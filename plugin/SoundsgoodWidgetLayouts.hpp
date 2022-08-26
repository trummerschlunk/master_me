/*
 */

#pragma once

#include "Quantum.hpp"

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------
// fixed button, expanding label below it for description

struct QuantumButtonWithDescription : HorizontalLayout
{
    QuantumButton button;
    QuantumLabel label;

    explicit QuantumButtonWithDescription(NanoSubWidget* const parent, const QuantumTheme& theme)
        : button(parent, theme),
          label(parent, theme)
    {
        widgets.push_back({ &button, Fixed });
        widgets.push_back({ &label, Expanding });
    }

    void adjustSize()
    {
        button.adjustSize();
        label.adjustSize();
    }
};

// --------------------------------------------------------------------------------------------------------------------
// fixed label, expanding separator line

struct QuantumLabelWithSeparatorLine : HorizontalLayout
{
    QuantumHorizontalSeparatorLine separator1;
    QuantumLabel label;
    QuantumHorizontalSeparatorLine separator2;

    explicit QuantumLabelWithSeparatorLine(NanoSubWidget* const parent, const QuantumTheme& theme)
        : separator1(parent, theme),
          label(parent, theme),
          separator2(parent, theme)
    {
        widgets.push_back({ &separator1, Expanding });
        widgets.push_back({ &label, Fixed });
        widgets.push_back({ &separator2, Expanding });
    }

    void adjustSize(const QuantumMetrics& metrics)
    {
        separator1.setSize(metrics.separatorHorizontal);
        label.adjustSize();
    }
};

// --------------------------------------------------------------------------------------------------------------------
// fixed meter, expanding label (both directions)

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

    void adjustSize(const QuantumMetrics& metrics)
    {
        meter.setSize(metrics.valueMeterHorizontal);
        label.adjustSize();
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

    void adjustSize(const QuantumMetrics& metrics)
    {
        slider.setSize(metrics.valueSlider);
        label.adjustSize();
    }
};

// --------------------------------------------------------------------------------------------------------------------
// label on both sides, center expanding spacer

struct QuantumDualLabelWithCenterSpacer : HorizontalLayout
{
    QuantumLabel labelL;
    QuantumSpacer spacer;
    QuantumLabel labelR;

    explicit QuantumDualLabelWithCenterSpacer(NanoSubWidget* const parent, const QuantumTheme& theme)
        : labelL(parent, theme),
          spacer(parent),
          labelR(parent, theme)
    {
        labelL.setAlignment(NanoVG::ALIGN_MIDDLE|NanoVG::ALIGN_CENTER);
        labelR.setAlignment(NanoVG::ALIGN_MIDDLE|NanoVG::ALIGN_CENTER);

        widgets.push_back({ &labelL, Fixed });
        widgets.push_back({ &spacer, Expanding });
        widgets.push_back({ &labelR, Fixed });
    }

    void adjustSize()
    {
        labelL.adjustSize();
        spacer.setSize(Size<uint>());
        labelR.adjustSize();
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

    void adjustSize(const QuantumMetrics& metrics)
    {
        sliderL.setSize(metrics.valueSlider);
        label.adjustSize();
        sliderR.setSize(metrics.valueSlider);
    }
};

// --------------------------------------------------------------------------------------------------------------------
// single separator line

struct QuantumSingleSeparatorLine : HorizontalLayout
{
    QuantumHorizontalSeparatorLine separator;

    explicit QuantumSingleSeparatorLine(NanoSubWidget* const parent, const QuantumTheme& theme)
        : separator(parent, theme)
    {
        widgets.push_back({ &separator, Expanding });
    }

    void adjustSize(const QuantumMetrics& metrics)
    {
        separator.setSize(metrics.separatorHorizontal);
    }
};

// --------------------------------------------------------------------------------------------------------------------
// single spacer

struct QuantumSingleSpacer : HorizontalLayout
{
    QuantumSpacer spacer;

    explicit QuantumSingleSpacer(NanoSubWidget* const parent)
        : spacer(parent)
    {
        widgets.push_back({ &spacer, Fixed });
    }
};

// --------------------------------------------------------------------------------------------------------------------
// single expanding label

struct QuantumSingleLabel : HorizontalLayout
{
    QuantumLabel label;

    explicit QuantumSingleLabel(NanoSubWidget* const parent, const QuantumTheme& theme)
        : label(parent, theme)
    {
        widgets.push_back({ &label, Expanding });
    }

    void adjustSize()
    {
        label.adjustSize();
    }
};

// --------------------------------------------------------------------------------------------------------------------
// single expanding value meter

struct QuantumSingleValueMeter : HorizontalLayout
{
    QuantumValueMeter meter;

    explicit QuantumSingleValueMeter(NanoSubWidget* const parent, const QuantumTheme& theme)
        : meter(parent, theme)
    {
        widgets.push_back({ &meter, Expanding });
    }

    void adjustSize(const QuantumMetrics& metrics)
    {
        meter.setSize(metrics.valueMeterHorizontal);
    }
};

// --------------------------------------------------------------------------------------------------------------------
// single expanding switch

struct QuantumSingleSwitch : HorizontalLayout
{
    QuantumSmallSwitch smallSwitch;

    explicit QuantumSingleSwitch(NanoSubWidget* const parent, const QuantumTheme& theme)
        : smallSwitch(parent, theme)
    {
        widgets.push_back({ &smallSwitch, Expanding });
    }

    void adjustSize()
    {
        smallSwitch.adjustSize();
    }
};

// --------------------------------------------------------------------------------------------------------------------
// label on both sides, center expanding spacer

struct MultiBandCompressorOutputGainGroup : HorizontalLayout
{
    QuantumSpacer fixedSpace;
    QuantumLabel label;
    QuantumValueSlider slider;

    explicit MultiBandCompressorOutputGainGroup(NanoSubWidget* const parent, const QuantumTheme& theme)
        : fixedSpace(parent),
          label(parent, theme),
          slider(parent, theme)
    {
        label.setAlignment(NanoVG::ALIGN_MIDDLE|NanoVG::ALIGN_CENTER);

        widgets.push_back({ &fixedSpace, Fixed });
        widgets.push_back({ &label, Expanding });
        widgets.push_back({ &slider, Fixed });
    }

    void adjustSize(const QuantumMetrics& metrics)
    {
        fixedSpace.setSize(metrics.valueSlider);
        label.adjustSize();
        slider.setSize(metrics.valueSlider);
    }
};

// --------------------------------------------------------------------------------------------------------------------
// custom layout for multiband compressor labels

struct MultiBandCompressorLabels : HorizontalLayout
{
    QuantumSpacer spacer1;
    QuantumLabel label1, label2, label3, label4, label5, label6, label7, label8;
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

        widgets.push_back({ &spacer1, Expanding });
        widgets.push_back({ &label1, Fixed });
        widgets.push_back({ &label2, Fixed });
        widgets.push_back({ &label3, Fixed });
        widgets.push_back({ &label4, Fixed });
        widgets.push_back({ &label5, Fixed });
        widgets.push_back({ &label6, Fixed });
        widgets.push_back({ &label7, Fixed });
        widgets.push_back({ &label8, Fixed });
        widgets.push_back({ &spacer2, Expanding });
    }

    void adjustSize()
    {
        label1.adjustSize();
        label2.adjustSize();
        label3.adjustSize();
        label4.adjustSize();
        label5.adjustSize();
        label6.adjustSize();
        label7.adjustSize();
        label8.adjustSize();
    }
};

// --------------------------------------------------------------------------------------------------------------------
// custom layout for multiband compressor meters

struct MultiBandCompressorValueMeters : HorizontalLayout
{
    QuantumLabel label;
    QuantumValueMeter m1, m2, m3, m4, m5, m6, m7, m8;
    QuantumSpacer spacer;

    explicit MultiBandCompressorValueMeters(NanoSubWidget* const parent, const QuantumTheme& theme, const QuantumValueMeter::Orientation orientation)
        : label(parent, theme),
          m1(parent, theme),
          m2(parent, theme),
          m3(parent, theme),
          m4(parent, theme),
          m5(parent, theme),
          m6(parent, theme),
          m7(parent, theme),
          m8(parent, theme),
          spacer(parent)
    {
        label.setAlignment(NanoVG::ALIGN_CENTER|NanoVG::ALIGN_MIDDLE);

        m1.setOrientation(orientation);
        m2.setOrientation(orientation);
        m3.setOrientation(orientation);
        m4.setOrientation(orientation);
        m5.setOrientation(orientation);
        m6.setOrientation(orientation);
        m7.setOrientation(orientation);
        m8.setOrientation(orientation);

        widgets.push_back({ &label, Expanding });
        widgets.push_back({ &m1, Fixed });
        widgets.push_back({ &m2, Fixed });
        widgets.push_back({ &m3, Fixed });
        widgets.push_back({ &m4, Fixed });
        widgets.push_back({ &m5, Fixed });
        widgets.push_back({ &m6, Fixed });
        widgets.push_back({ &m7, Fixed });
        widgets.push_back({ &m8, Fixed });
        widgets.push_back({ &spacer, Expanding });
    }

    void adjustSize(const QuantumMetrics& metrics)
    {
        label.adjustSize();
        m1.setSize(metrics.valueMeterVertical);
        m2.setSize(metrics.valueMeterVertical);
        m3.setSize(metrics.valueMeterVertical);
        m4.setSize(metrics.valueMeterVertical);
        m5.setSize(metrics.valueMeterVertical);
        m6.setSize(metrics.valueMeterVertical);
        m7.setSize(metrics.valueMeterVertical);
        m8.setSize(metrics.valueMeterVertical);
        spacer.setSize(label.getSize());
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
