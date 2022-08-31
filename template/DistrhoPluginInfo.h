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

{% block HeaderPrologue %}
{% if not (lv2uri is defined) %}
{{fail("`lv2uri` is undefined.")}}
{% endif %}
{% endblock %}

#pragma once

#define DISTRHO_PLUGIN_NAME {{cstr(name)}}
#define DISTRHO_PLUGIN_URI  {{cstr(lv2uri)}}

#define DISTRHO_PLUGIN_HAS_UI          {% if uitype is defined %}1{% else %}0{% endif %}
#define DISTRHO_PLUGIN_IS_RT_SAFE      1
#define DISTRHO_PLUGIN_NUM_INPUTS      {{inputs}}
#define DISTRHO_PLUGIN_NUM_OUTPUTS     {{outputs}}

enum Parameters {
    // inputs
    {% for p in active %}kParameter_{{p.meta.symbol|default("" ~ loop.index)}},
    {% endfor %}
    // outputs
    {% for p in passive %}kParameter_{{p.meta.symbol|default("" ~ (active|length+loop.index))}},
    {% endfor %}
    // terminator
    kParameterCount
};

enum Programs {
    kProgramCount
};

enum States {
    kStateCount
};

static constexpr const char* kParameterNames[{{active|length+passive|length}}] = {
    // inputs
    {% for p in active %}{{cstr(p.label)}},
    {% endfor %}
    // ouputs
    {% for p in passive %}{{cstr(p.label)}},
    {% endfor %}
};

static constexpr const struct { float def, min, max; } kParameterRanges[{{active|length+passive|length}}] = {
    // inputs
    {% for p in active %}{ {{p.init}}, {{p.min}}, {{p.max}} },
    {% endfor %}
    // ouputs
    {% for p in passive %}{ {{p.init}}, {{p.min}}, {{p.max}} },
    {% endfor %}
};

static constexpr const char* kParameterSymbols[{{active|length+passive|length}}] = {
    // inputs
    {% for p in active %}{{cstr(cid(p.meta.symbol|default("lv2_port_" ~ (inputs+outputs+loop.index0))))}},
    {% endfor %}
    // ouputs
    {% for p in passive %}{{cstr(cid(p.meta.symbol|default("lv2_port_" ~ (inputs+outputs+active|length+loop.index0))))}},
    {% endfor %}
};

static constexpr const char* kParameterUnits[{{active|length+passive|length}}] = {
    // inputs
    {% for p in active %}{{cstr(p.unit)}},
    {% endfor %}
    // ouputs
    {% for p in passive %}{{cstr(p.unit)}},
    {% endfor %}
};

// #if __has_include("ExtraProperties.h")
#include "ExtraProperties.h"
// #endif

{% block HeaderEpilogue %}
{% endblock %}
