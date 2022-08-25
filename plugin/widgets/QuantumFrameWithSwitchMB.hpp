/*
 */

#pragma once

#include "Quantum.hpp"

START_NAMESPACE_DGL

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

        fillColor(theme.textLightColor);
        fontSize(theme.fontSize);

        textAlign(ALIGN_LEFT|ALIGN_TOP);
        text(xOffset, topMeterTick, "3dB", nullptr);

        textAlign(ALIGN_LEFT|ALIGN_MIDDLE);
        text(xOffset, topMeterTick + (bottomMeterTick - topMeterTick) * 0.5f, "0dB", nullptr);

        textAlign(ALIGN_LEFT|ALIGN_BOTTOM);
        text(xOffset, bottomMeterTick, "3dB", nullptr);
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
