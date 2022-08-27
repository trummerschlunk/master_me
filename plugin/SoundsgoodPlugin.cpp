/*
 */

#include "DistrhoPlugin.hpp"

// faustpp generated plugin template
#include "DistrhoPluginInfo.h"
#include "Plugin.cpp"

// leaving for last, includes windows.h
#include "src/DistrhoDefines.h"
#include "utils/SharedMemory.hpp"

// checks to ensure things are still as we expect them to be from faust dsp side
static_assert(DISTRHO_PLUGIN_NUM_INPUTS == 2, "has 2 audio inputs");
static_assert(DISTRHO_PLUGIN_NUM_OUTPUTS == 2, "has 2 audio outputs");

START_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

class SoundsgoodPlugin : public FaustGeneratedPlugin
{
    uint bufferSizeForHistogram;
    uint numFramesSoFar = 0;

    MasterMeFifoControl lufsInFifo;
    MasterMeFifoControl lufsOutFifo;
    SharedMemory<MasterMeHistogramFifos> histogramSharedData;
    bool histogramActive = false;

    static constexpr const uint kMinimumHistogramBufferSize = 4096;

public:
    SoundsgoodPlugin()
        : FaustGeneratedPlugin(kExtraParameterCount, kExtraProgramCount, kExtraStateCount)
    {
        bufferSizeForHistogram = std::max(kMinimumHistogramBufferSize, getBufferSize());
    }

protected:
   /* -----------------------------------------------------------------------------------------------------------------
    * Information */

    int64_t getUniqueId() const override
    {
        return d_cconst('S', 'n', 'd', 'G');
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
            switch (index)
            {
            case kParameter_global_bypass:
                param.initDesignation(kParameterDesignationBypass);
                break;
            default:
                FaustGeneratedPlugin::initParameter(index, param);
                break;
            }
            return;
        }

        switch (index - kParameterCount)
        {
        case kExtraParameterHistogramBufferSize:
            param.hints = kParameterIsAutomatable|kParameterIsOutput|kParameterIsInteger;
            param.name = "Histogram Buffer Size";
            param.unit = "frames";
            param.symbol = "histo_buffer_size";
            param.shortName = "HistBufSize";
            param.ranges.def = kMinimumHistogramBufferSize;
            param.ranges.min = kMinimumHistogramBufferSize;
            param.ranges.max = 16384;
            break;
        }
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
        default:
            return 0.0f;
        }
    }

    void setState(const char* const key, const char* const value) override
    {
        if (std::strcmp(key, "histogram") == 0)
        {
            if (histogramSharedData.isCreatedOrConnected())
            {
                DISTRHO_SAFE_ASSERT(! histogramActive);
                lufsInFifo.setFloatFifo(nullptr);
                lufsOutFifo.setFloatFifo(nullptr);
                histogramSharedData.close();
            }

            if (MasterMeHistogramFifos* const fifos = histogramSharedData.connect(value))
            {
                lufsInFifo.setFloatFifo(&fifos->lufsIn);
                lufsOutFifo.setFloatFifo(&fifos->lufsOut);
                histogramActive = true;
            }
        }
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Audio/MIDI Processing */

    void activate() override
    {
        numFramesSoFar = 0;
    }

    void run(const float** const inputs, float** const outputs, const uint32_t frames) override
    {
        dsp->compute(frames, const_cast<float**>(inputs), outputs);

        numFramesSoFar += frames;

        if (numFramesSoFar >= bufferSizeForHistogram)
        {
            numFramesSoFar -= bufferSizeForHistogram;

            if (histogramActive)
            {
                MasterMeHistogramFifos* const data = histogramSharedData.getDataPointer();
                DISTRHO_SAFE_ASSERT_RETURN(data != nullptr,);

                if (data->closed)
                {
                    histogramActive = false;
                }
                else
                {
                    lufsInFifo.write(FaustGeneratedPlugin::getParameterValue(kParameter_lufs_in));
                    lufsOutFifo.write(FaustGeneratedPlugin::getParameterValue(kParameter_lufs_out));
                }
            }
        }
    }

    void bufferSizeChanged(const uint newBufferSize) override
    {
        bufferSizeForHistogram = std::max(kMinimumHistogramBufferSize, newBufferSize);
    }

    // ----------------------------------------------------------------------------------------------------------------

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundsgoodPlugin)
};

// --------------------------------------------------------------------------------------------------------------------

Plugin* createPlugin()
{
    return new SoundsgoodPlugin();
}

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
