{% block HeaderDescription %}
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: {{file_name}}
// Name: {{name}}
// Description: {{description}}
// Author: {{author}}
// Copyright: {{copyright}}
// License: {{license}}
// Version: {{version}}
//------------------------------------------------------------------------------
{% endblock %}

#include "DistrhoPlugin.hpp"
#include "extra/ScopedPointer.hpp"

// --------------------------------------------------------------------------------------------------------------------

// inline code when possible
#define FAUSTPP_VIRTUAL inline

// make everything available directly
#define FAUSTPP_PRIVATE public
#define FAUSTPP_PROTECTED public

// match distrho namespace
#define FAUSTPP_BEGIN_NAMESPACE START_NAMESPACE_DISTRHO
#define FAUSTPP_END_NAMESPACE END_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

START_NAMESPACE_DISTRHO

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class dsp {
public:
    virtual ~dsp() {}
};

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void openTabBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

END_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

{% block ImplementationFaustCode %}
{{class_code}}
{% endblock %}

// --------------------------------------------------------------------------------------------------------------------

START_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

class FaustGeneratedPlugin : public Plugin
{
protected:
    ScopedPointer<mydsp> dsp;

public:
    FaustGeneratedPlugin(const uint32_t extraParameters = 0,
                         const uint32_t extraPrograms = 0,
                         const uint32_t extraStates = 0)
        : Plugin(kParameterCount + extraParameters, kProgramCount + extraPrograms, kStateCount + extraStates)
    {
        dsp = new mydsp;
        dsp->init(getSampleRate());
    }

protected:
   /* -----------------------------------------------------------------------------------------------------------------
    * Information */

    const char* getLabel() const override
    {
        return {{cstr(label)}};
    }

    const char* getDescription() const override
    {
        return {{cstr(meta.description)}};
    }

    const char* getMaker() const override
    {
        return {{cstr(brand)}};
    }

    const char* getHomePage() const override
    {
        return {{cstr(homepage)}};
    }

    const char* getLicense() const override
    {
        return {{cstr(license)}};
    }

    uint32_t getVersion() const override
    {
        return d_version({{version_major}}, {{version_minor}}, {{version_micro}});
    }

    int64_t getUniqueId() const override
    {
        // FIXME provide a way to set this in meta data
        return d_cconst('F', 'I', 'X', 'M');
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Init */

    void initAudioPort(const bool input, const uint32_t index, AudioPort& port) override
    {
        /* make assumptions related to IO.
         * 1 audio port means mono, 2 means stereo.
         */
        {% if inputs == outputs %}
            {% if inputs == 1 %}
        port.groupId = kPortGroupMono;
            {% endif %}
            {% if inputs == 2 %}
        port.groupId = kPortGroupStereo;
            {% endif %}
        {% else %}
            {% if inputs == 1 %}
        if (input) port.groupId = kPortGroupMono;
            {% endif %}
            {% if inputs == 2 %}
        if (input) port.groupId = kPortGroupStereo;
            {% endif %}
            {% if outputs == 1 %}
        if (!input) port.groupId = kPortGroupMono;
            {% endif %}
            {% if outputs == 2 %}
        if (!input) port.groupId = kPortGroupStereo;
            {% endif %}
        {% endif %}

        // everything else is as default
        Plugin::initAudioPort(input, index, port);
    }

    void initParameter(const uint32_t index, Parameter& param) override
    {
        switch (index)
        {
        {% for p in active %}case kParameter_{{p.meta.symbol|default("" ~ loop.index)}}:
            param.hints = kParameterIsAutomatable
            {% if p.type in ["button"] or p.meta.trigger is defined %}
                |kParameterIsTrigger
            {% endif %}
            {% if p.type in ["button", "checkbox"] or p.meta.boolean is defined %}
                |kParameterIsBoolean
            {% endif %}
            {% if p.type in ["button", "checkbox"] or p.meta.boolean is defined or p.meta.integer is defined %}
                |kParameterIsInteger
            {% endif %}
            {% if p.scale == "log" %}
                |kParameterIsLogarithmic
            {% endif %}
            ;
            param.name = kParameterNames[{{loop.index0}}];
            param.unit = kParameterUnits[{{loop.index0}}];
            param.symbol = {{cstr(cid(p.meta.symbol|default("lv2_port_" ~ (inputs+outputs+loop.index0))))}};
            param.shortName = {{cstr(p.meta.abbrev|default(""))}};
            param.ranges.def = {{p.init}};
            param.ranges.min = {{p.min}};
            param.ranges.max = {{p.max}};
            break;
        {% endfor %}
        {% for p in passive %}case kParameter_{{p.meta.symbol|default("" ~ (active|length+loop.index))}}:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            {% if p.type in ["button", "checkbox"] or p.meta.boolean is defined %}
                |kParameterIsBoolean
            {% endif %}
            {% if p.type in ["button", "checkbox"] or p.meta.boolean is defined or p.meta.integer is defined %}
                |kParameterIsInteger
            {% endif %}
            {% if p.scale == "log" %}
                |kParameterIsLogarithmic
            {% endif %}
            ;
            param.name = kParameterNames[{{active|length+loop.index0}}];
            param.unit = kParameterUnits[{{active|length+loop.index0}}];
            param.symbol = {{cstr(cid(p.meta.symbol|default("lv2_port_" ~ (inputs+outputs+active|length+loop.index0))))}};
            param.shortName = {{cstr(p.meta.abbrev|default(""))}};
            param.ranges.def = {{p.init}};
            param.ranges.min = {{p.min}};
            param.ranges.max = {{p.max}};
            break;
        {% endfor %}
        }
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Internal data */

    float getParameterValue(const uint32_t index) const override
    {
        switch (index)
        {
        {% for p in active + passive %}case kParameter_{{p.meta.symbol|default("" ~ loop.index)}}:
            return dsp->{{p.var}};
        {% endfor %}
        default:
            return 0.0f;
        }
    }

    void setParameterValue(const uint32_t index, const float value) override
    {
        switch (index)
        {
        {% for p in active %}case kParameter_{{p.meta.symbol|default("" ~ loop.index)}}:
            dsp->{{p.var}} = value;
            break;
        {% endfor %}
        }
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Audio/MIDI Processing */

    void run(const float** const inputs, float** const outputs, const uint32_t frames) override
    {
        dsp->compute(frames, const_cast<float**>(inputs), outputs);
    }

    // ----------------------------------------------------------------------------------------------------------------

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FaustGeneratedPlugin)
};

// --------------------------------------------------------------------------------------------------------------------

#if 0
{% if not skip_dpf_create_plugin %}

Plugin* createPlugin()
{
    return new FaustGeneratedPlugin();
}

{% endif %}
#endif

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
