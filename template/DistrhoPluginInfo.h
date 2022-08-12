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
#define DISTRHO_UI_USE_NANOVG          1

enum Parameters {
    {% for p in active + passive %}kParameter{{p.meta.symbol|default("" ~ loop.index)}},
    {% endfor %}kParameterCount
};

enum Programs {
    kProgramCount
};

enum States {
    kStateCount
};

static const struct { float def, min, max; } kParameterRanges[{{active|length}}] = {
    {% for p in active %}{ {{p.init}}, {{p.min}}, {{p.max}} },
    {% endfor %}
};

static const char* kParameterNames[{{active|length}}] = {
    {% for p in active %}{{cstr(p.label)}},
    {% endfor %}
};

// #if has_include("ExtraProperties.h")
#include "ExtraProperties.h"
// #endif

{% block HeaderEpilogue %}
{% endblock %}
