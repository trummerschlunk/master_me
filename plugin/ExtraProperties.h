/*
 */

#pragma once

#define DISTRHO_PLUGIN_WANT_STATE 1
#define DISTRHO_PLUGIN_HAS_UI     1
#define DISTRHO_UI_USE_NANOVG     1
#define DISTRHO_UI_USER_RESIZABLE 0

enum ExtraParameters {
    kExtraParameterCount
};

enum ExtraPrograms {
    kExtraProgramCount
};

enum ExtraStates {
    kExtraStateMode = 0,
    kExtraStateCount
};
