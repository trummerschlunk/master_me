/*
 */

#include "DistrhoPlugin.hpp"
#include "DistrhoPluginInfo.h"
#include "Plugin.cpp"
#include "ExtraProperties.h"

// checks to ensure things are still as we expect them to be from faust dsp side
static_assert(DISTRHO_PLUGIN_NUM_INPUTS == 2, "has 2 audio inputs");
static_assert(DISTRHO_PLUGIN_NUM_OUTPUTS == 2, "has 2 audio outputs");
static_assert(kParameter_87 + 1 - kParameter_70 == 18, "has 18 knee+multiband compressor passive controls");

START_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

class SoundsgoodPlugin : public FaustGeneratedPlugin
{
    // bool isBypassed = false;

public:
    SoundsgoodPlugin()
        : FaustGeneratedPlugin(kExtraParameterCount, kExtraProgramCount, kExtraStateCount)
    {
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
        switch (index)
        {
        case kParameter_global_bypass:
            param.initDesignation(kParameterDesignationBypass);
            break;
        default:
            FaustGeneratedPlugin::initParameter(index, param);
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

#if 0
    float getParameterValue(const uint32_t index) const override
    {
        if (index < kParameterCount)
            return FaustGeneratedPlugin::getParameterValue(index);

        switch (index - kParameterCount)
        {
        case kExtraParameterBypass:
            return isBypassed ? 1.f : 0.f;
        default:
            return 0.0f;
        }
    }

    void setParameterValue(const uint32_t index, const float value) override
    {
        if (index < kParameterCount)
            return FaustGeneratedPlugin::setParameterValue(index, value);
        
        switch (index - kParameterCount)
        {
        case kExtraParameterBypass:
            isBypassed = value > 0.5f;
            break;
        }
    }
#endif

    void setState(const char*, const char*) override
    {
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Audio/MIDI Processing */

#if 0
    void run(const float** const inputs, float** const outputs, const uint32_t frames) override
    {
        // TODO custom bypass
        dsp->compute(frames, const_cast<float**>(inputs), outputs);
    }
#endif

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
