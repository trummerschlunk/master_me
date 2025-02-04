// Copyright 2022-2024 Filipe Coelho <falktx@falktx.com>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "DistrhoPlugin.hpp"
#include "extra/ScopedDenormalDisable.hpp"

// faustpp generated plugin template
#include "DistrhoPluginInfo.h"
#include "Plugin.cpp"

// leaving for last, includes windows.h
#if MASTER_ME_SHARED_MEMORY
#include "utils/SharedMemory.hpp"
#endif

// checks to ensure things are still as we expect them to be from faust dsp side
static_assert(DISTRHO_PLUGIN_NUM_INPUTS == 2, "has 2 audio inputs");
static_assert(DISTRHO_PLUGIN_NUM_OUTPUTS == 2, "has 2 audio outputs");

START_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

class MasterMePlugin : public FaustGeneratedPlugin
{
    // current mode
    String mode;

    // histogram related stuff
    uint bufferSizeForHistogram;
    uint numFramesSoFar = 0;
    float highestLufsInValue = -70.f;
    float highestLufsOutValue = -70.f;
   #ifndef __MOD_DEVICES__
    bool histogramActive = false;
   #endif
   #if MASTER_ME_SHARED_MEMORY
    MasterMeFifoControl lufsInFifo;
    MasterMeFifoControl lufsOutFifo;
    SharedMemory<MasterMeHistogramFifos> histogramSharedData;
   #else
    float histogramValueIn = -70.f;
    float histogramValueOut = -70.f;
    bool histogramValueFlipFlop = true;
   #endif

public:
    MasterMePlugin()
        : FaustGeneratedPlugin(kExtraParameterCount, kExtraProgramCount, kExtraStateCount)
    {
        bufferSizeForHistogram = std::max(kMinimumHistogramBufferSize, getBufferSize());
    }

protected:
   /* -----------------------------------------------------------------------------------------------------------------
    * Information */

    const char* getDescription() const override
    {
        return "Automatic audio mastering plugin for live-streaming, podcasting and internet radio stations";
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Init */

    void initAudioPort(const bool input, const uint32_t index, AudioPort& port) override
    {
        // always stereo
        port.groupId = kPortGroupStereo;

        // everything else is as default
        Plugin::initAudioPort(input, index, port);
    }

    void initParameter(const uint32_t index, Parameter& param) override
    {
        if (index < kParameterCount)
        {
            if (index == kParameter_global_bypass)
            {
                param.initDesignation(kParameterDesignationBypass);
                return;
            }

            FaustGeneratedPlugin::initParameter(index, param);

            switch (index)
            {
            case kParameter_target:
                param.hints |= kParameterIsInteger;
                break;
            }
            return;
        }

        switch (index - kParameterCount)
        {
        case kExtraParameterHistogramBufferSize:
            param.hints = kParameterIsOutput|kParameterIsInteger;
            param.name = "Histogram Buffer Size";
            param.unit = "frames";
            param.symbol = "histogram_buffer_size";
            param.shortName = "HistBufSize";
            param.ranges.def = kMinimumHistogramBufferSize;
            param.ranges.min = kMinimumHistogramBufferSize;
            param.ranges.max = 16384;
            break;
       #if ! MASTER_ME_SHARED_MEMORY
        case kExtraParameterHistogramValueIn:
            param.hints = kParameterIsOutput;
            param.name = "Histogram Value In";
            param.unit = "dB";
            param.symbol = "histogram_value_in";
            param.shortName = "HistValIn";
            param.ranges.def = -70;
            param.ranges.min = -70;
            param.ranges.max = 0;
            break;
        case kExtraParameterHistogramValueOut:
            param.hints = kParameterIsOutput;
            param.name = "Histogram Value Out";
            param.unit = "dB";
            param.symbol = "histogram_value_out";
            param.shortName = "HistValOut";
            param.ranges.def = -70;
            param.ranges.min = -70;
            param.ranges.max = 0;
            break;
       #endif
        }
    }

    void initProgramName(const uint32_t index, String& programName) override
    {
        programName = kEasyPresets[index].name;
    }

    void initState(const uint32_t index, State& state) override
    {
        if (index < kStateCount)
            return; // FaustGeneratedPlugin::initState(index, state);

        switch (index - kStateCount)
        {
        case kExtraStateMode:
            state.hints = kStateIsHostReadable | kStateIsOnlyForUI;
            state.key = "mode";
            state.defaultValue = "simple";
            state.label = "Mode";
            state.description = "Simple vs Advanced mode switch";
            break;
        }
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Internal data */

    float getParameterValue(const uint32_t index) const override
    {
        if (index < kParameterCount)
            return FaustGeneratedPlugin::getParameterValue(index);

        switch (index - kParameterCount)
        {
        case kExtraParameterHistogramBufferSize:
            return bufferSizeForHistogram;
       #if ! MASTER_ME_SHARED_MEMORY
        case kExtraParameterHistogramValueIn:
            return histogramValueIn;
        case kExtraParameterHistogramValueOut:
            return histogramValueOut;
       #endif
        default:
            return 0.0f;
        }
    }

    void loadProgram(const uint32_t index) override
    {
        const EasyPreset& preset(kEasyPresets[index]);

        for (uint i=1; i<ARRAY_SIZE(preset.values); ++i)
            setParameterValue(i, preset.values[i]);
    }

    String getState(const char* const key) const override
    {
        if (std::strcmp(key, "mode") == 0)
            return mode;

        return String();
    }

    void setState(const char* const key, const char* const value) override
    {
        if (std::strcmp(key, "mode") == 0)
        {
            mode = value;
        }
       #ifndef __MOD_DEVICES__
        else if (std::strcmp(key, "histogram") == 0)
        {
           #if MASTER_ME_SHARED_MEMORY
            if (histogramSharedData.isCreatedOrConnected())
            {
                DISTRHO_SAFE_ASSERT(! histogramActive);
                lufsInFifo.setFloatFifo(nullptr);
                lufsOutFifo.setFloatFifo(nullptr);
                histogramSharedData.close();
            }

            MasterMeHistogramFifos* const fifos = histogramSharedData.connect(value);
            DISTRHO_SAFE_ASSERT_RETURN(fifos != nullptr,);

            lufsInFifo.setFloatFifo(&fifos->lufsIn);
            lufsOutFifo.setFloatFifo(&fifos->lufsOut);
           #endif
            histogramActive = true;
        }
       #endif
        /*
        else if (std::strcmp(key, "export") == 0)
        {
            printCurrentValues();
        }
        */
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Audio/MIDI Processing */

    void activate() override
    {
        numFramesSoFar = 0;
    }

    void run(const float** const inputs, float** const outputs, const uint32_t frames) override
    {
        // optimize for non-denormal usage
        const ScopedDenormalDisable sdd;
        for (uint32_t i = 0; i < frames; ++i)
        {
            if (!std::isfinite(inputs[0][i]))
                __builtin_unreachable();
            if (!std::isfinite(inputs[1][i]))
                __builtin_unreachable();
            if (!std::isfinite(outputs[0][i]))
                __builtin_unreachable();
            if (!std::isfinite(outputs[1][i]))
                __builtin_unreachable();
        }

        dsp->compute(frames, const_cast<float**>(inputs), outputs);

        highestLufsInValue = std::max(highestLufsInValue, FaustGeneratedPlugin::getParameterValue(kParameter_lufs_in));
        highestLufsOutValue = std::max(highestLufsOutValue, FaustGeneratedPlugin::getParameterValue(kParameter_lufs_out));

        numFramesSoFar += frames;

        if (numFramesSoFar >= bufferSizeForHistogram)
        {
            numFramesSoFar -= bufferSizeForHistogram;

           #ifndef __MOD_DEVICES__
            if (histogramActive)
           #endif
            {
               #if MASTER_ME_SHARED_MEMORY
                MasterMeHistogramFifos* const data = histogramSharedData.getDataPointer();
                DISTRHO_SAFE_ASSERT_RETURN(data != nullptr,);

                if (data->closed)
                {
                    histogramActive = false;
                }
                else
                {
                    lufsInFifo.write(highestLufsInValue);
                    lufsOutFifo.write(highestLufsOutValue);
                }
               #else
                const float uniqueValue = (histogramValueFlipFlop = !histogramValueFlipFlop) ? 0.0001f : -0.0001f;

                if (d_isNotEqual(histogramValueIn, highestLufsInValue))
                    histogramValueIn = highestLufsInValue;
                else
                    histogramValueIn += uniqueValue;

                if (d_isNotEqual(histogramValueOut, highestLufsOutValue))
                    histogramValueOut = highestLufsOutValue;
                else
                    histogramValueOut += uniqueValue;
               #endif
            }

            highestLufsInValue = highestLufsOutValue = -70.f;
        }
    }

    void bufferSizeChanged(const uint newBufferSize) override
    {
        bufferSizeForHistogram = std::max(kMinimumHistogramBufferSize, newBufferSize);
    }

    // ----------------------------------------------------------------------------------------------------------------

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MasterMePlugin)
};

// --------------------------------------------------------------------------------------------------------------------

Plugin* createPlugin()
{
    return new MasterMePlugin();
}

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
