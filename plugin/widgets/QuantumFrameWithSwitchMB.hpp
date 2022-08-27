/*
 */

#pragma once

#include "Quantum.hpp"

#include "DistrhoPluginInfo.h"

START_NAMESPACE_DGL

// -----------------------------------------------------------------------------------------------------------

// make sure our expectations match
static_assert(kParameterRanges[kParameter_msredux11].min == -3.f, "mscomp meters -3 dB min");
static_assert(kParameterRanges[kParameter_msredux11].max == 0.f, "mscomp meters 0 dB max");

// --------------------------------------------------------------------------------------------------------------------

class QuantumFrameWithSwitchMB : public QuantumFrameWithSwitch
{
    const QuantumTheme& theme;

    int xOffset = 0;
    int topMeterTick = 0;
    int bottomMeterTick = 0;

public:
    QuantumFrameWithSwitchMB(TopLevelWidget* const parent, const QuantumTheme& t)
        : QuantumFrameWithSwitch(parent, t),
          theme(t)
    {
        loadSharedResources();
    }

    void setTickPos(const int x, const int top, const int bottom)
    {
        xOffset = x;
        topMeterTick = top;
        bottomMeterTick = bottom;
        repaint();
    }

protected:
    void onNanoDisplay() override
    {
        QuantumFrameWithSwitch::onNanoDisplay();

        const float midTick = topMeterTick + (bottomMeterTick - topMeterTick) * 0.5f;
        const float textCenterX = xOffset + (getWidth() - theme.borderSize - theme.padding - xOffset) * 0.5f;

        fillColor(theme.textLightColor);
        fontSize(theme.fontSize);
        textAlign(ALIGN_CENTER|ALIGN_MIDDLE);

        strokeColor(theme.widgetBackgroundColor);
        strokeWidth(theme.widgetLineSize);

        beginPath();
        moveTo(xOffset - theme.fontSize * 0.25f, topMeterTick + static_cast<int>(theme.widgetLineSize * 0.5f));
        lineTo(xOffset + theme.fontSize * 0.25f, topMeterTick + static_cast<int>(theme.widgetLineSize * 0.5f));
        stroke();

        beginPath();
        moveTo(xOffset - theme.fontSize * 0.25f, midTick);
        lineTo(xOffset + theme.fontSize * 0.25f, midTick);
        stroke();

        beginPath();
        moveTo(xOffset - theme.fontSize * 0.25f, bottomMeterTick - static_cast<int>(theme.widgetLineSize * 0.5f));
        lineTo(xOffset + theme.fontSize * 0.25f, bottomMeterTick - static_cast<int>(theme.widgetLineSize * 0.5f));
        stroke();

        text(textCenterX, topMeterTick, "-3dB", nullptr);
        text(textCenterX, midTick, "0dB", nullptr);
        text(textCenterX, bottomMeterTick, "-3dB", nullptr);
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
