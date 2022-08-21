/*
 */

#pragma once

#include "NanoVG.hpp"
#include "Quantum.hpp"
#include "Widget.hpp"

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------
// fixed meter, expanding label

struct QuantumValueMeterWithLabel : HorizontalLayout
{
    QuantumValueMeter meter;
    QuantumLabel label;

    explicit QuantumValueMeterWithLabel(NanoSubWidget* const parent, const QuantumTheme& theme)
        : meter(parent, theme),
          label(parent, theme)
    {
        widgets.push_back({ &meter, Fixed });
        widgets.push_back({ &label, Expanding });
    }
};

// --------------------------------------------------------------------------------------------------------------------
// fixed slider, expanding label

struct QuantumValueSliderWithLabel : HorizontalLayout
{
    QuantumValueSlider slider;
    QuantumLabel label;

    explicit QuantumValueSliderWithLabel(NanoSubWidget* const parent, const QuantumTheme& theme)
        : slider(parent, theme),
          label(parent, theme)
    {
        widgets.push_back({ &slider, Fixed });
        widgets.push_back({ &label, Expanding });
    }
};

// --------------------------------------------------------------------------------------------------------------------
// sliders on both sides, center expanding label

struct QuantumDualValueSliderWithCenterLabel : HorizontalLayout
{
    QuantumValueSlider sliderL;
    QuantumLabel label;
    QuantumValueSlider sliderR;

    explicit QuantumDualValueSliderWithCenterLabel(NanoSubWidget* const parent, const QuantumTheme& theme)
        : sliderL(parent, theme),
          label(parent, theme),
          sliderR(parent, theme)
    {
        label.setAlignment(NanoVG::ALIGN_MIDDLE|NanoVG::ALIGN_CENTER);

        widgets.push_back({ &sliderL, Fixed });
        widgets.push_back({ &label, Expanding });
        widgets.push_back({ &sliderR, Fixed });
    }
};

// --------------------------------------------------------------------------------------------------------------------
// single expanding switch

struct QuantumSingleSwitch : HorizontalLayout
{
    QuantumSwitch switch_;

    explicit QuantumSingleSwitch(NanoSubWidget* const parent, const QuantumTheme& theme)
        : switch_(parent, theme)
    {
        widgets.push_back({ &switch_, Expanding });
    }
};

// --------------------------------------------------------------------------------------------------------------------
// frame with label on top

// struct QuantumFrameWithLabel : VerticalLayout
// {
//     QuantumLabel label;
//     QuantumFrame frame;

//     explicit QuantumFrameWithLabel(TopLevelWidget* const parent, const QuantumTheme& theme)
//         : label(parent, theme),
//           frame(parent, theme)
//     {
//         widgets.push_back({ &label, Fixed });
//         widgets.push_back({ &frame, Expanding });
//     }

//     void adjustSize(const QuantumTheme& theme, const QuantumMetrics& metrics, const Size<uint>& frameSize)
//     {
//         // adjust width ourselves
//         label.adjustSize();
//         frame.setWidth(frameSize.getWidth());

//         // set fixed elements height (prefer to use switch widget height, to keep switch vs label height consistent)
//         label.setHeight(metrics.switch_.getHeight());

//         // now let the layout code do the rest
//         setSize(metrics.switch_.getHeight() + theme.padding + frameSize.getHeight(), theme.padding);
//     }
// };

// --------------------------------------------------------------------------------------------------------------------
// frame with switch on top

// struct QuantumFrameWithSwitch : VerticalLayout
// {
//     QuantumSwitch switch_;
//     QuantumFrame frame;

//     explicit QuantumFrameWithSwitch(TopLevelWidget* const parent, const QuantumTheme& theme)
//         : switch_(parent, theme),
//           frame(parent, theme)
//     {
//         widgets.push_back({ &switch_, Fixed });
//         widgets.push_back({ &frame, Expanding });
//     }

//     void adjustSize(const QuantumTheme& theme, const QuantumMetrics& metrics, const Size<uint>& frameSize)
//     {
//         // adjust width ourselves
//         switch_.adjustSize();
//         frame.setWidth(frameSize.getWidth());

//         // set fixed elements height
//         switch_.setHeight(metrics.switch_.getHeight());

//         // now let the layout code do the rest
//         setSize(metrics.switch_.getHeight() + theme.padding + frameSize.getHeight(), theme.padding);
//     }
// };

// --------------------------------------------------------------------------------------------------------------------
// custom layout for multiband compressor labels

struct MultiBandCompressorLabels : HorizontalLayout
{
    QuantumSpacer spacer1;
    QuantumLabel label1, label2, label3, label4, label5, label6, label7, label8, label9;
    QuantumSpacer spacer2;

    explicit MultiBandCompressorLabels(NanoSubWidget* const parent, const QuantumTheme& theme)
        : spacer1(parent),
          label1(parent, theme),
          label2(parent, theme),
          label3(parent, theme),
          label4(parent, theme),
          label5(parent, theme),
          label6(parent, theme),
          label7(parent, theme),
          label8(parent, theme),
          label9(parent, theme),
          spacer2(parent)
    {
        label1.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label2.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label3.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label4.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label5.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label6.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label7.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label8.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);
        label9.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_BOTTOM);

        widgets.push_back({ &spacer1, Expanding });
        widgets.push_back({ &label1, Fixed });
        widgets.push_back({ &label2, Fixed });
        widgets.push_back({ &label3, Fixed });
        widgets.push_back({ &label4, Fixed });
        widgets.push_back({ &label5, Fixed });
        widgets.push_back({ &label6, Fixed });
        widgets.push_back({ &label7, Fixed });
        widgets.push_back({ &label8, Fixed });
        widgets.push_back({ &label9, Fixed });
        widgets.push_back({ &spacer2, Expanding });
    }
};

// --------------------------------------------------------------------------------------------------------------------
// custom layout for multiband compressor meters

struct MultiBandCompressorValueMeters : HorizontalLayout
{
    QuantumLabel label;
    QuantumValueMeter m1, m2, m3, m4, m5, m6, m7, m8, m9;
    QuantumSpacer spacer;

    explicit MultiBandCompressorValueMeters(NanoSubWidget* const parent, const QuantumTheme& theme)
        : label(parent, theme),
          m1(parent, theme),
          m2(parent, theme),
          m3(parent, theme),
          m4(parent, theme),
          m5(parent, theme),
          m6(parent, theme),
          m7(parent, theme),
          m8(parent, theme),
          m9(parent, theme),
          spacer(parent)
    {
        label.setAlignment(NanoVG::ALIGN_RIGHT|NanoVG::ALIGN_MIDDLE);

        m1.setOrientation(QuantumValueMeter::TopToBottom);
        m2.setOrientation(QuantumValueMeter::TopToBottom);
        m3.setOrientation(QuantumValueMeter::TopToBottom);
        m4.setOrientation(QuantumValueMeter::TopToBottom);
        m5.setOrientation(QuantumValueMeter::TopToBottom);
        m6.setOrientation(QuantumValueMeter::TopToBottom);
        m7.setOrientation(QuantumValueMeter::TopToBottom);
        m8.setOrientation(QuantumValueMeter::TopToBottom);
        m9.setOrientation(QuantumValueMeter::TopToBottom);

        widgets.push_back({ &label, Expanding });
        widgets.push_back({ &m1, Fixed });
        widgets.push_back({ &m2, Fixed });
        widgets.push_back({ &m3, Fixed });
        widgets.push_back({ &m4, Fixed });
        widgets.push_back({ &m5, Fixed });
        widgets.push_back({ &m6, Fixed });
        widgets.push_back({ &m7, Fixed });
        widgets.push_back({ &m8, Fixed });
        widgets.push_back({ &m9, Fixed });
        widgets.push_back({ &spacer, Expanding });
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
