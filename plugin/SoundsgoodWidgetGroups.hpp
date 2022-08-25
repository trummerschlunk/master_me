/*
 */

#pragma once

#include "Layout.hpp"
#include "NanoVG.hpp"
#include "SoundsgoodWidgetLayouts.hpp"
#include "widgets/QuantumFrameWithSwitchMB.hpp"
#include "extra/String.hpp"

#include "DistrhoPluginInfo.h"

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

template<class tFrameWidget>
struct SoundsgoodParameterGroup : VerticallyStackedHorizontalLayout
{
    const QuantumTheme& theme;
    tFrameWidget frame;

    explicit SoundsgoodParameterGroup(TopLevelWidget* const parent, const QuantumTheme& t)
        : theme(t),
          frame(parent, t) {}

    virtual void adjustSize(const QuantumMetrics& metrics)
    {
        // adjust size of frame contents
        Size<uint> frameSize = VerticallyStackedHorizontalLayout::adjustSize(theme.padding);
        frameSize += metrics.frame;

        // adjust frame extra widget
        frame.adjustMainWidgetSize();

        // adjust size now
        frame.setSize(frameSize.getWidth(), frameSize.getHeight() + frame.getOffset() + theme.padding);
    }

    virtual void setAbsolutePos(const int x, const int y)
    {
        // move frame
        frame.setAbsolutePos(x, y);
        // move children
        VerticallyStackedHorizontalLayout::setAbsolutePos(frame.getAbsoluteX() + theme.borderSize + theme.padding,
                                                          frame.getAbsoluteY() + frame.getOffset() + theme.borderSize + theme.padding,
                                                          theme.padding);
    }

    inline void setupSeparatorLine(QuantumLabelWithSeparatorLine& w, const char* const label)
    {
        w.label.setName(label);
        w.label.setLabel(label);
        w.separator1.setName(String(label) + " [separator L]");
        w.separator2.setName(String(label) + " [separator R]");
        items.push_back(&w);
    }

    inline void setupSeparatorLine(QuantumSingleSeparatorLine& w)
    {
        w.separator.setName("+ separator");
        items.push_back(&w);
    }

    inline void setupSlider(QuantumValueSliderWithLabel& w, KnobEventHandler::Callback* const cb, const int id, const uint nameOffset)
    {
        w.slider.setCallback(cb);
        w.slider.setId(id);
        w.slider.setName(kParameterNames[id]);
        w.slider.setDefault(kParameterRanges[id].def);
        w.slider.setRange(kParameterRanges[id].min, kParameterRanges[id].max);
        w.slider.setUnitLabel(kParameterUnits[id]);
        w.slider.setValue(kParameterRanges[id].def, false);
        w.label.setLabel(kParameterNames[id] + nameOffset);
        w.label.setName(String(kParameterNames[id]) + " [label]");
        items.push_back(&w);

        // FIXME find the proper way faust exports this
        if (kParameterUnits[id][0] == '%')
            w.slider.setStep(1.f);
    }

    inline void setupDualSlider(QuantumDualValueSliderWithCenterLabel&w, KnobEventHandler::Callback* const cb, const int id, const uint idOffset, const uint nameOffset)
    {
        w.sliderL.setCallback(cb);
        w.sliderR.setCallback(cb);
        w.sliderL.setId(id);
        w.sliderR.setId(id + idOffset);
        w.sliderL.setName(kParameterNames[id]);
        w.sliderR.setName(kParameterNames[id + idOffset]);
        w.sliderL.setDefault(kParameterRanges[id].def);
        w.sliderR.setDefault(kParameterRanges[id + idOffset].def);
        w.sliderL.setRange(kParameterRanges[id].min, kParameterRanges[id].max);
        w.sliderR.setRange(kParameterRanges[id + idOffset].min, kParameterRanges[id + idOffset].max);
        w.sliderL.setUnitLabel(kParameterUnits[id]);
        w.sliderR.setUnitLabel(kParameterUnits[id + idOffset]);
        w.sliderL.setValue(kParameterRanges[id].def, false);
        w.sliderR.setValue(kParameterRanges[id + idOffset].def, false);
        w.label.setLabel(kParameterNames[id] + nameOffset);
        w.label.setName(String(kParameterNames[id]) + " [label]");
        items.push_back(&w);

        // FIXME find the proper way faust exports this
        if (kParameterUnits[id][0] == '%')
            w.sliderL.setStep(1.f);
        // FIXME find the proper way faust exports this
        if (kParameterUnits[id + idOffset][0] == '%')
            w.sliderR.setStep(1.f);
    }

    inline void setupMeter(QuantumValueMeterWithLabel& w, const int id, const uint nameOffset)
    {
        w.meter.setId(id);
        w.meter.setName(kParameterNames[id]);
        w.meter.setOrientation(QuantumValueMeter::RightToLeft);
        w.meter.setRange(kParameterRanges[id].min, kParameterRanges[id].max);
        w.meter.setUnitLabel(kParameterUnits[id]);
        w.meter.setValue(kParameterRanges[id].def);
        w.label.setLabel(kParameterNames[id] + nameOffset);
        w.label.setName(String(kParameterNames[id]) + " [label]");
        items.push_back(&w);
    }

    inline void setupSwitch(QuantumSingleSwitch& w, ButtonEventHandler::Callback* const bcb, const int id, const uint nameOffset)
    {
        w.smallSwitch.setCallback(bcb);
        w.smallSwitch.setId(id);
        w.smallSwitch.setChecked(kParameterRanges[id].def > 0.5f, false);
        w.smallSwitch.setLabel(kParameterNames[id] + nameOffset);
        w.smallSwitch.setName(kParameterNames[id]);
        items.push_back(&w);
    }
};

typedef SoundsgoodParameterGroup<QuantumFrameWithLabel> SoundsgoodParameterGroupWithoutBypassSwitch;
typedef SoundsgoodParameterGroup<QuantumFrameWithSwitch> SoundsgoodParameterGroupWithBypassSwitch;
typedef SoundsgoodParameterGroup<QuantumFrameWithSwitchMB> SoundsgoodParameterGroupWithBypassSwitchMB;

// --------------------------------------------------------------------------------------------------------------------

struct SoundsgoodPresetGroup : HorizontalLayout
{
    const QuantumTheme& theme;
    QuantumFrameWithLabel frame;

    explicit SoundsgoodPresetGroup(TopLevelWidget* const parent, const QuantumTheme& t)
        : theme(t),
          frame(parent, t) {}

    void adjustSize(const uint buttonSize, const QuantumMetrics& metrics)
    {
        // adjust size of frame contents
        Size<uint> frameSize = Size<uint>(buttonSize * widgets.size() + theme.padding * (widgets.size() - 1), buttonSize / 2);
        frameSize += metrics.frame;

        HorizontalLayout::setSize(buttonSize / 2, theme.padding);

        // adjust frame extra widget
        frame.adjustMainWidgetSize();

        // adjust size now
        frame.setSize(frameSize.getWidth(), frameSize.getHeight() + frame.getOffset());
    }

    void setAbsolutePos(const int x, const int y)
    {
        // move frame
        frame.setAbsolutePos(x, y);
        // move children
        HorizontalLayout::setAbsolutePos(frame.getAbsoluteX() + theme.borderSize + theme.padding,
                                         frame.getAbsoluteY() + frame.getOffset() + theme.borderSize + theme.padding,
                                         theme.padding);
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
