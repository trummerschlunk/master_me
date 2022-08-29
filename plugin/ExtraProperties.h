/*
 */

#pragma once

#define DISTRHO_PLUGIN_WANT_STATE 1
#define DISTRHO_PLUGIN_HAS_UI     1
#define DISTRHO_UI_FILE_BROWSER   0
#define DISTRHO_UI_USE_NANOVG     1
#define DISTRHO_UI_USER_RESIZABLE 0

#define DISTRHO_UI_DEFAULT_WIDTH 1030
#define DISTRHO_UI_DEFAULT_HEIGHT 597

enum ExtraParameters {
    kExtraParameterHistogramBufferSize,
    kExtraParameterCount
};

enum ExtraPrograms {
    kExtraProgramCount
};

enum ExtraStates {
    kExtraStateMode = 0,
    kExtraStateCount
};

#include "utils/FloatFifo.hpp"

typedef FloatFifo<128> MasterMeFloatFifo;
typedef FloatFifoControl<128> MasterMeFifoControl;

struct MasterMeHistogramFifos {
    MasterMeFloatFifo lufsIn;
    MasterMeFloatFifo lufsOut;
    bool closed;
};

static constexpr const uint kMinimumHistogramBufferSize = 4096;
