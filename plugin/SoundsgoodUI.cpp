/*
 */

#include "DistrhoPluginInfo.h"
#include "DistrhoUI.hpp"

#include "Quantum.hpp"
#include "SoundsgoodWidgetGroups.hpp"
#include "extra/ScopedPointer.hpp"
#include "widgets/InspectorWindow.hpp"

#include "BuildInfo.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

// our custom metrics, making vertical sliders have less height
struct SoundsGoodMetrics : QuantumMetrics
{
    SoundsGoodMetrics(const QuantumTheme& theme) noexcept
        : QuantumMetrics(theme)
    {
        valueMeterVertical.setHeight(valueMeterVertical.getHeight() * 2 / 3);
    }
};

// custom layout for input levels and mixer slider
struct InputMeterGroup : QuantumFrame
{
    const QuantumTheme& theme;

    QuantumStereoLevelMeterWithLUFS meter;
    QuantumMixerSlider slider;

    explicit InputMeterGroup(TopLevelWidget* const parent, KnobEventHandler::Callback* const cb, const QuantumTheme& t)
        : QuantumFrame(parent, t),
          theme(t),
          meter(this, t),
          slider(this, t)
    {
        setName("Inputs");

        meter.setName(" + Meter");
        meter.setRange(kParameterRanges[kParameter_peakmeter_in_l].min, kParameterRanges[kParameter_peakmeter_in_l].max);
        meter.setValues(kParameterRanges[kParameter_peakmeter_in_l].min,
                        kParameterRanges[kParameter_peakmeter_in_r].min, 
                        kParameterRanges[kParameter_lufs_in].min);

        slider.setCallback(cb);
        slider.setId(kParameter_target);
        slider.setName("Target");
        // NOTE this slider widget assumes -50 to 0 dB range
        // slider.setRange(kParameterRanges[kParameter_target].min, kParameterRanges[kParameter_target].max);
        slider.setValue(kParameterRanges[kParameter_target].def, false);
    }

    void adjustSize(const SoundsGoodMetrics& metrics, const uint height)
    {
        const uint usableHeight = height - theme.borderSize * 2 - theme.padding * 2;
        meter.setSize(metrics.stereoLevelMeterWithLufs.getWidth(), usableHeight);
        slider.setSize(metrics.mixerSlider.getWidth(), usableHeight);
        setSize(meter.getWidth() + slider.getWidth() + theme.borderSize * 2 + theme.padding * 3, height);
    }

    void setAbsolutePos(const int x, const int y)
    {
        QuantumFrame::setAbsolutePos(x, y);
        meter.setAbsolutePos(x + theme.borderSize + theme.padding, y + theme.borderSize + theme.padding);
        slider.setAbsolutePos(meter.getAbsoluteX() + meter.getWidth() + theme.padding, meter.getAbsoluteY());
    }
};

// custom layout for output levels (single widget for now)
struct OutputMeterGroup : QuantumFrame
{
    const QuantumTheme& theme;

    QuantumStereoLevelMeterWithLUFS meter;

    explicit OutputMeterGroup(TopLevelWidget* const parent, const QuantumTheme& t)
        : QuantumFrame(parent, t),
          theme(t),
          meter(this, t)
    {
        setName("Outputs");

        meter.setName(" + Meter");
        meter.setRange(kParameterRanges[kParameter_peakmeter_out_l].min, kParameterRanges[kParameter_peakmeter_out_l].max);
        meter.setValues(kParameterRanges[kParameter_peakmeter_out_l].min,
                        kParameterRanges[kParameter_peakmeter_out_r].min, 
                        kParameterRanges[kParameter_lufs_out].min);
    }

    void adjustSize(const SoundsGoodMetrics& metrics, const uint height)
    {
        const uint usableHeight = height - theme.borderSize * 2 - theme.padding * 2;
        meter.setSize(metrics.stereoLevelMeterWithLufs.getWidth(), usableHeight);
        setSize(meter.getWidth() + theme.borderSize * 2 + theme.padding * 2, height);
    }

    void setAbsolutePos(const int x, const int y)
    {
        QuantumFrame::setAbsolutePos(x, y);
        meter.setAbsolutePos(x + theme.borderSize + theme.padding, y + theme.borderSize + theme.padding);
    }
};

// custom layout for top centered content (global enable and leveler gain)
struct TopCenteredGroup : QuantumFrame
{
    const QuantumTheme& theme;

    QuantumSwitch globalEnableSwitch;
    QuantumVerticalSeparatorLine separator;
    QuantumLabelWithValueMeter levelerGain;

    uint innerWidth = 0;

    explicit TopCenteredGroup(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, const QuantumTheme& t)
        : QuantumFrame(parent, t),
          theme(t),
          globalEnableSwitch(this, t),
          separator(this, t),
          levelerGain(this, t)
    {
        setName("Top Center");

        globalEnableSwitch.setCallback(bcb);
        globalEnableSwitch.setCheckable(true);
        globalEnableSwitch.setChecked(kParameterRanges[kParameter_global_bypass].def, false);
        globalEnableSwitch.setId(kParameter_global_bypass);
        globalEnableSwitch.setLabel("Enable");
        globalEnableSwitch.setName("Global Enable Button");

        separator.setName("+ separator");

        levelerGain.meter.setId(kParameter_leveler_gain);
        levelerGain.meter.setName(kParameterNames[kParameter_leveler_gain]);
        levelerGain.meter.setOrientation(QuantumValueMeter::CenterToSides);
        levelerGain.meter.setRange(kParameterRanges[kParameter_leveler_gain].min, kParameterRanges[kParameter_leveler_gain].max);
        levelerGain.meter.setUnitLabel(kParameterUnits[kParameter_leveler_gain]);
        levelerGain.meter.setValue(kParameterRanges[kParameter_leveler_gain].def);
        levelerGain.label.setLabel("Leveler Gain:");
        levelerGain.label.setName(kParameterNames[kParameter_leveler_gain]);
    }

    void adjustSize(const SoundsGoodMetrics& metrics, const uint width, const uint height, const uint widgetsHeight)
    {
        globalEnableSwitch.adjustSize();
        globalEnableSwitch.setHeight(widgetsHeight);
        separator.setSize(metrics.separatorVertical);
        separator.setHeight(widgetsHeight);
        levelerGain.adjustSize(metrics);
        levelerGain.label.setHeight(widgetsHeight);
        levelerGain.meter.setSize(levelerGain.meter.getWidth() * 2, widgetsHeight); // double the normal meter size
        innerWidth = globalEnableSwitch.getWidth() + separator.getWidth() + levelerGain.meter.getWidth() + levelerGain.label.getWidth() + theme.padding * 9;
        setSize(width, height);
    }

    void setAbsolutePos(int x, const int y)
    {
        QuantumFrame::setAbsolutePos(0, 0);
        x += (getWidth() - innerWidth) / 2;
        globalEnableSwitch.setAbsolutePos(x, y);
        separator.setAbsolutePos(globalEnableSwitch.getAbsoluteX() + globalEnableSwitch.getWidth() + theme.padding * 4, y);
        levelerGain.setAbsolutePos(separator.getAbsoluteX() + separator.getWidth() + theme.padding * 4, y, theme.padding);
    }

    void onNanoDisplay() override
    {
        const Color color2(Color(theme.widgetBackgroundColor, theme.windowBackgroundColor, 0.5f).withAlpha(0.5f));
        const Color color1(color2.withAlpha(0.f));
        const uint gradientWidth = (getWidth() - innerWidth) / 2;
        const uint height = getHeight();

        beginPath();
        rect(0, 0, gradientWidth, height);
        fillPaint(linearGradient(0, 0, gradientWidth, 0, color2, color1));
        fill();

        beginPath();
        rect(getWidth() - gradientWidth, 0, gradientWidth, height);
        fillPaint(linearGradient(getWidth() - gradientWidth, 0, getWidth(), 0, color1, color2));
        fill();

        beginPath();
        rect(gradientWidth - 1, 0, innerWidth + 2, height);
        fillColor(color1);
        fill();
    }
};

// custom widget for drawing build info within frame
struct ContentGroup : QuantumFrame
{
    const QuantumTheme& theme;
    QuantumButton& expertButton;

public:
    explicit ContentGroup(TopLevelWidget* const parent, const QuantumTheme& t, QuantumButton& eb)
        : QuantumFrame(parent, t),
          theme(t),
          expertButton(eb)
    {
        loadSharedResources();
        setName("Name");
    }

    void onNanoDisplay() override
    {
        QuantumFrame::onNanoDisplay();

        if (expertButton.isChecked())
            return;

        fillColor(theme.textMidColor);
        fontSize(theme.fontSize);
        textAlign(ALIGN_BOTTOM|ALIGN_RIGHT);
        textBox(0, getHeight() - theme.fontSize * 5 - theme.borderSize,
                getWidth() - theme.borderSize - theme.padding,
                kBuildInfoString, nullptr);
    }
};

// custom widget for drawing plugin name (so it appears on top of other widgets if needed)
class SoundsgoodNameWidget : public NanoSubWidget
{
    const QuantumTheme& theme;

    static constexpr const char* const kText = "soundsgood";

public:
    explicit SoundsgoodNameWidget(TopLevelWidget* const parent, const QuantumTheme& t)
        : NanoSubWidget(parent),
          theme(t)
    {
        loadSharedResources();
        setName("Name");
    }

    // based on QuantumLabel::adjustSize()
    void adjustSize()
    {
        Rectangle<float> bounds;
        fontSize(theme.fontSize * 2);

        textBounds(0, 0, kText, nullptr, bounds);
        const uint width = std::max(static_cast<uint>(bounds.getWidth() + 0.5f), theme.padding) + theme.textPixelRatioWidthCompensation;
        const uint height = std::max(static_cast<uint>(bounds.getHeight() + 0.5f), theme.fontSize * 2);

        setSize(width, height);
    }

protected:
    void onNanoDisplay() override
    {
        fillColor(theme.textLightColor);
        fontSize(theme.fontSize * 2);
        textAlign(ALIGN_CENTER|ALIGN_MIDDLE);
        text(getWidth() / 2, getHeight() / 2, kText, nullptr);
    }
};

// -----------------------------------------------------------------------------------------------------------

class SoundsGoodUI : public UI,
                     public ButtonEventHandler::Callback,
                     public KnobEventHandler::Callback
{
  static const uint kInitialWidth = 1010;
  static const uint kInitialHeight = 600;

  ScopedPointer<InspectorWindow> inspectorWindow;

  QuantumTheme theme;

  // easy vs expert mode switch buttons
  QuantumButton easyModeButton;
  QuantumButton expertModeButton;

  // group of widgets
  TopCenteredGroup topCenteredGroup;
  InputMeterGroup inputGroup;
  ContentGroup contentGroup;
  OutputMeterGroup outputGroup;

  // easy mode labels
  QuantumValueMeter18 easyMetering;
  QuantumLabel welcomeLabel;

  // plugin name
  SoundsgoodNameWidget name;

  struct PreProcessing : SoundsgoodParameterGroupWithoutBypassSwitch {
      QuantumValueSliderWithLabel inputGain;
      QuantumSingleSwitch mono;
      QuantumSingleSwitch phaseL;
      QuantumSingleSwitch phaseR;
      QuantumSingleSwitch dcBlocker;
      QuantumSingleSwitch stereoCorrect;

      explicit PreProcessing(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithoutBypassSwitch(parent, theme),
            inputGain(&frame, theme),
            mono(&frame, theme),
            phaseL(&frame, theme),
            phaseR(&frame, theme),
            dcBlocker(&frame, theme),
            stereoCorrect(&frame, theme)
      {
          frame.setName("Pre-Processing");
          frame.mainWidget.setLabel("Pre-Processing");

          setupSlider(inputGain, cb, kParameter_in_gain, 0);
          setupSwitch(mono, bcb, kParameter_mono, 0);
          setupSwitch(phaseL, bcb, kParameter_phase_l, 0);
          setupSwitch(phaseR, bcb, kParameter_phase_r, 0);
          setupSwitch(dcBlocker, bcb, kParameter_dc_blocker, 0);
          setupSwitch(stereoCorrect, bcb, kParameter_stereo_correct, 0);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          inputGain.adjustSize(metrics);
          mono.adjustSize();
          phaseL.adjustSize();
          phaseR.adjustSize();
          dcBlocker.adjustSize();
          stereoCorrect.adjustSize();
          SoundsgoodParameterGroupWithoutBypassSwitch::adjustSize(metrics);
      }
  } preProcessing;

  struct Gate : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel threshold;
      QuantumValueSliderWithLabel attack;
      QuantumValueSliderWithLabel hold;
      QuantumValueSliderWithLabel release;

      explicit Gate(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            threshold(&frame, theme),
            attack(&frame, theme),
            hold(&frame, theme),
            release(&frame, theme)
      {
          frame.setName("Gate");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_gate_bypass);
          frame.mainWidget.setLabel("Gate");

          setupSlider(threshold, cb, kParameter_gate_threshold, 5);
          setupSlider(attack, cb, kParameter_gate_attack, 5);
          setupSlider(hold, cb, kParameter_gate_hold, 5);
          setupSlider(release, cb, kParameter_gate_release, 5);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          threshold.adjustSize(metrics);
          attack.adjustSize(metrics);
          hold.adjustSize(metrics);
          release.adjustSize(metrics);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }

      void setEnabledColor(const bool enabled)
      {
          const Color color = enabled ? theme.textLightColor : theme.textDarkColor;
          threshold.label.setLabelColor(color);
          threshold.slider.setTextColor(color);
          attack.label.setLabelColor(color);
          attack.slider.setTextColor(color);
          hold.label.setLabelColor(color);
          hold.slider.setTextColor(color);
          release.label.setLabelColor(color);
          release.slider.setTextColor(color);
      }
  } gate;

  struct Leveler : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel speed;
      QuantumValueSliderWithLabel threshold;
      QuantumValueSliderWithLabel max_plus;
      QuantumValueSliderWithLabel max_minus;
      QuantumLabelWithSeparatorLine separator;
      QuantumValueMeterWithLabel gate;

      explicit Leveler(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            speed(&frame, theme),
            threshold(&frame, theme),
            max_plus(&frame, theme),
            max_minus(&frame, theme),
            separator(&frame, theme),
            gate(&frame, theme)
      {
          frame.setName("Leveler");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_leveler_bypass);
          frame.mainWidget.setLabel("Leveler");

          setupSlider(speed, cb, kParameter_leveler_speed, 8);
          setupSlider(threshold, cb, kParameter_leveler_gate_threshold, 8);
          setupSlider(max_plus, cb, kParameter_leveler_max_plus, 8);
          setupSlider(max_minus, cb, kParameter_leveler_max_minus, 8);
          setupSeparatorLine(separator, "Outputs:");
          setupMeter(gate, kParameter_leveler_gate, 8);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          speed.adjustSize(metrics);
          threshold.adjustSize(metrics);
          max_plus.adjustSize(metrics);
          max_minus.adjustSize(metrics);
          separator.adjustSize(metrics);
          gate.adjustSize(metrics);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }

      void setEnabledColor(const bool enabled)
      {
          const Color color = enabled ? theme.textLightColor : theme.textDarkColor;
          speed.label.setLabelColor(color);
          speed.slider.setTextColor(color);
          threshold.label.setLabelColor(color);
          threshold.slider.setTextColor(color);
          max_plus.label.setLabelColor(color);
          max_plus.slider.setTextColor(color);
          max_minus.label.setLabelColor(color);
          max_minus.slider.setTextColor(color);
          separator.label.setLabelColor(color);
          gate.label.setLabelColor(color);
          gate.meter.setTextColor(color);
      }
  } leveler;

  struct Eq : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel highpass;
      QuantumLabelWithSeparatorLine tilt;
      QuantumValueSliderWithLabel tilt_gain;
      QuantumLabelWithSeparatorLine side;
      QuantumValueSliderWithLabel side_gain;
      QuantumValueSliderWithLabel side_freq;
      QuantumValueSliderWithLabel side_bandwidth;

      explicit Eq(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            highpass(&frame, theme),
            tilt(&frame, theme),
            tilt_gain(&frame, theme),
            side(&frame, theme),
            side_gain(&frame, theme),
            side_freq(&frame, theme),
            side_bandwidth(&frame, theme)
      {
          frame.setName("EQ");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_eq_bypass);
          frame.mainWidget.setLabel("EQ");

          setupSlider(highpass, cb, kParameter_eq_highpass_freq, 3);
          setupSeparatorLine(tilt, "Tilt:");
          setupSlider(tilt_gain, cb, kParameter_eq_tilt_gain, 8);
          setupSeparatorLine(side, "Side:");
          setupSlider(side_gain, cb, kParameter_eq_side_gain, 8);
          setupSlider(side_freq, cb, kParameter_eq_side_freq, 8);
          setupSlider(side_bandwidth, cb, kParameter_eq_side_bandwidth, 8);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          highpass.adjustSize(metrics);
          tilt.adjustSize(metrics);
          tilt_gain.adjustSize(metrics);
          side.adjustSize(metrics);
          side_gain.adjustSize(metrics);
          side_freq.adjustSize(metrics);
          side_bandwidth.adjustSize(metrics);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }

      void setEnabledColor(const bool enabled)
      {
          const Color color = enabled ? theme.textLightColor : theme.textDarkColor;
          highpass.label.setLabelColor(color);
          highpass.slider.setTextColor(color);
          tilt.label.setLabelColor(color);
          tilt_gain.label.setLabelColor(color);
          tilt_gain.slider.setTextColor(color);
          side.label.setLabelColor(color);
          side_gain.label.setLabelColor(color);
          side_gain.slider.setTextColor(color);
          side_freq.label.setLabelColor(color);
          side_freq.slider.setTextColor(color);
          side_bandwidth.label.setLabelColor(color);
          side_bandwidth.slider.setTextColor(color);
      }
  } eq;

  struct KneeCompressor : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel strength;
      QuantumValueSliderWithLabel threshold;
      QuantumValueSliderWithLabel attack;
      QuantumValueSliderWithLabel release;
      QuantumValueSliderWithLabel knee;
      QuantumValueSliderWithLabel link;
      QuantumValueSliderWithLabel fffb;
      QuantumValueSliderWithLabel makeup;
      QuantumValueSliderWithLabel drywet;
      QuantumLabelWithSeparatorLine separator;
      QuantumValueMeterWithLabel m1; // FIXME name this
      QuantumValueMeterWithLabel m2; // FIXME name this

      explicit KneeCompressor(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            strength(&frame, theme),
            threshold(&frame, theme),
            attack(&frame, theme),
            release(&frame, theme),
            knee(&frame, theme),
            link(&frame, theme),
            fffb(&frame, theme),
            makeup(&frame, theme),
            drywet(&frame, theme),
            separator(&frame, theme),
            m1(&frame, theme),
            m2(&frame, theme)
      {
          frame.setName("Knee Compressor");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_kneecomp_bypass);
          frame.mainWidget.setLabel("Knee Compressor");

          setupSlider(strength, cb, kParameter_kneecomp_strength, 9);
          setupSlider(threshold, cb, kParameter_kneecomp_threshold, 9);
          setupSlider(attack, cb, kParameter_kneecomp_attack, 9);
          setupSlider(release, cb, kParameter_kneecomp_release, 9);
          setupSlider(knee, cb, kParameter_kneecomp_knee, 9);
          setupSlider(link, cb, kParameter_kneecomp_link, 9);
          setupSlider(fffb, cb, kParameter_kneecomp_fffb, 9);
          setupSlider(makeup, cb, kParameter_kneecomp_makeup, 9);
          setupSlider(drywet, cb, kParameter_kneecomp_drywet, 9);
          setupSeparatorLine(separator, "Outputs:");
          setupMeter(m1, kParameter_70, 0);
          setupMeter(m2, kParameter_71, 0);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          strength.adjustSize(metrics);
          threshold.adjustSize(metrics);
          attack.adjustSize(metrics);
          release.adjustSize(metrics);
          knee.adjustSize(metrics);
          link.adjustSize(metrics);
          fffb.adjustSize(metrics);
          makeup.adjustSize(metrics);
          separator.adjustSize(metrics);
          m1.adjustSize(metrics);
          m2.adjustSize(metrics);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }

      void setEnabledColor(const bool enabled)
      {
          const Color color = enabled ? theme.textLightColor : theme.textDarkColor;
          strength.label.setLabelColor(color);
          strength.slider.setTextColor(color);
          threshold.label.setLabelColor(color);
          threshold.slider.setTextColor(color);
          attack.label.setLabelColor(color);
          attack.slider.setTextColor(color);
          release.label.setLabelColor(color);
          release.slider.setTextColor(color);
          knee.label.setLabelColor(color);
          knee.slider.setTextColor(color);
          link.label.setLabelColor(color);
          link.slider.setTextColor(color);
          fffb.label.setLabelColor(color);
          fffb.slider.setTextColor(color);
          makeup.label.setLabelColor(color);
          makeup.slider.setTextColor(color);
          drywet.label.setLabelColor(color);
          drywet.slider.setTextColor(color);
          separator.label.setLabelColor(color);
          m1.label.setLabelColor(color);
          m1.meter.setTextColor(color);
          m2.label.setLabelColor(color);
          m2.meter.setTextColor(color);
      }
  } kneeComp;

  struct MidSideCompressor : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumDualLabelWithCenterSpacer labelsTop;
      QuantumDualValueSliderWithCenterLabel strength;
      QuantumDualValueSliderWithCenterLabel threshold;
      QuantumDualValueSliderWithCenterLabel attack;
      QuantumDualValueSliderWithCenterLabel release;
      QuantumDualValueSliderWithCenterLabel knee;
      QuantumDualValueSliderWithCenterLabel link;
      QuantumDualValueSliderWithCenterLabel crossover;
      MultiBandCompressorLabels labelsMid;
      MultiBandCompressorValueMeters metersM;
      MultiBandCompressorValueMeters metersS;
      MultiBandCompressorOutputGainGroup outputGain;

      explicit MidSideCompressor(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            labelsTop(&frame, theme),
            strength(&frame, theme),
            threshold(&frame, theme),
            attack(&frame, theme),
            release(&frame, theme),
            knee(&frame, theme),
            link(&frame, theme),
            crossover(&frame, theme),
            labelsMid(&frame, theme),
            metersM(&frame, theme),
            metersS(&frame, theme),
            outputGain(&frame, theme)
      {
          frame.setName("MidSide Compressor");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_mscomp_bypass);
          frame.mainWidget.setLabel("MidSide Compressor");

          constexpr const uint idOffset = kParameter_mscomp_high_crossover - kParameter_mscomp_low_crossover;
          static_assert(kParameter_mscomp_high_strength - kParameter_mscomp_low_strength == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_threshold - kParameter_mscomp_low_threshold == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_attack - kParameter_mscomp_low_attack == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_release - kParameter_mscomp_low_release == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_knee - kParameter_mscomp_low_knee == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_link - kParameter_mscomp_low_link == idOffset, "mscomp param id offset mismatch");

          labelsTop.labelL.setLabel("Low");
          labelsTop.labelR.setLabel("High");
          items.push_back(&labelsTop);

          setupDualSlider(strength, cb, kParameter_mscomp_low_strength, idOffset, 4);
          setupDualSlider(threshold, cb, kParameter_mscomp_low_threshold, idOffset, 4);
          setupDualSlider(attack, cb, kParameter_mscomp_low_attack, idOffset, 4);
          setupDualSlider(release, cb, kParameter_mscomp_low_release, idOffset, 4);
          setupDualSlider(knee, cb, kParameter_mscomp_low_knee, idOffset, 4);
          setupDualSlider(link, cb, kParameter_mscomp_low_link, idOffset, 4);
          setupDualSlider(crossover, cb, kParameter_mscomp_low_crossover, idOffset, 4);

          labelsMid.label1.setLabel("1");
          labelsMid.label2.setLabel("2");
          labelsMid.label3.setLabel("3");
          labelsMid.label4.setLabel("4");
          labelsMid.label5.setLabel("5");
          labelsMid.label6.setLabel("6");
          labelsMid.label7.setLabel("7");
          labelsMid.label8.setLabel("8");
          items.push_back(&labelsMid);

          setupMeters(metersM, "  m  ", kParameter_72);
          setupMeters(metersS, "  s  ", kParameter_80);

          outputGain.slider.setCallback(cb);
          outputGain.slider.setId(kParameter_mscomp_output_gain);
          outputGain.slider.setName(kParameterNames[kParameter_mscomp_output_gain]);
          outputGain.slider.setRange(kParameterRanges[kParameter_mscomp_output_gain].min, kParameterRanges[kParameter_mscomp_output_gain].max);
          outputGain.slider.setUnitLabel(kParameterUnits[kParameter_mscomp_output_gain]);
          outputGain.slider.setValue(kParameterRanges[kParameter_mscomp_output_gain].def, false);
          outputGain.label.setLabel(kParameterNames[kParameter_mscomp_output_gain]);
          outputGain.label.setName(String(kParameterNames[kParameter_mscomp_output_gain]) + " [label]");
          items.push_back(&outputGain);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          const Size<uint> labelsTopSize(metrics.valueSlider.getWidth(), theme.textHeight);
          labelsTop.labelL.setSize(labelsTopSize);
          labelsTop.labelR.setSize(labelsTopSize);
          strength.adjustSize(metrics);
          threshold.adjustSize(metrics);
          attack.adjustSize(metrics);
          release.adjustSize(metrics);
          knee.adjustSize(metrics);
          link.adjustSize(metrics);
          crossover.adjustSize(metrics);
          const Size<uint> labelsMidSize(metrics.valueMeterVertical.getWidth(), theme.textHeight);
          labelsMid.label1.setSize(labelsMidSize);
          labelsMid.label2.setSize(labelsMidSize);
          labelsMid.label3.setSize(labelsMidSize);
          labelsMid.label4.setSize(labelsMidSize);
          labelsMid.label5.setSize(labelsMidSize);
          labelsMid.label6.setSize(labelsMidSize);
          labelsMid.label7.setSize(labelsMidSize);
          labelsMid.label8.setSize(labelsMidSize);
          metersM.adjustSize(metrics);
          metersS.adjustSize(metrics);
          outputGain.adjustSize(metrics);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }

      void setEnabledColor(const bool enabled)
      {
          const Color color = enabled ? theme.textLightColor : theme.textDarkColor;
          labelsTop.labelL.setLabelColor(color);
          labelsTop.labelR.setLabelColor(color);
          crossover.label.setLabelColor(color);
          crossover.sliderL.setTextColor(color);
          crossover.sliderR.setTextColor(color);
          strength.label.setLabelColor(color);
          strength.sliderL.setTextColor(color);
          strength.sliderR.setTextColor(color);
          threshold.label.setLabelColor(color);
          threshold.sliderL.setTextColor(color);
          threshold.sliderR.setTextColor(color);
          attack.label.setLabelColor(color);
          attack.sliderL.setTextColor(color);
          attack.sliderR.setTextColor(color);
          release.label.setLabelColor(color);
          release.sliderL.setTextColor(color);
          release.sliderR.setTextColor(color);
          knee.label.setLabelColor(color);
          knee.sliderL.setTextColor(color);
          knee.sliderR.setTextColor(color);
          link.label.setLabelColor(color);
          link.sliderL.setTextColor(color);
          link.sliderR.setTextColor(color);
          labelsMid.label1.setLabelColor(color);
          labelsMid.label2.setLabelColor(color);
          labelsMid.label3.setLabelColor(color);
          labelsMid.label4.setLabelColor(color);
          labelsMid.label5.setLabelColor(color);
          labelsMid.label6.setLabelColor(color);
          labelsMid.label7.setLabelColor(color);
          labelsMid.label8.setLabelColor(color);
          metersM.label.setLabelColor(color);
          metersS.label.setLabelColor(color);
          outputGain.label.setLabelColor(color);
          outputGain.slider.setTextColor(color);
      }

      inline void setupMeters(MultiBandCompressorValueMeters& w, const char* const label, const int idStart)
      {
          w.m1.setId(idStart + 0);
          w.m2.setId(idStart + 1);
          w.m3.setId(idStart + 2);
          w.m4.setId(idStart + 3);
          w.m5.setId(idStart + 4);
          w.m6.setId(idStart + 5);
          w.m7.setId(idStart + 6);
          w.m8.setId(idStart + 7);

          w.m1.setName(kParameterNames[idStart + 0]);
          w.m2.setName(kParameterNames[idStart + 1]);
          w.m3.setName(kParameterNames[idStart + 2]);
          w.m4.setName(kParameterNames[idStart + 3]);
          w.m5.setName(kParameterNames[idStart + 4]);
          w.m6.setName(kParameterNames[idStart + 5]);
          w.m7.setName(kParameterNames[idStart + 6]);
          w.m8.setName(kParameterNames[idStart + 7]);

          w.m1.setRange(kParameterRanges[idStart + 0].min,
                        kParameterRanges[idStart + 0].max);
          w.m2.setRange(kParameterRanges[idStart + 1].min,
                        kParameterRanges[idStart + 1].max);
          w.m3.setRange(kParameterRanges[idStart + 2].min,
                        kParameterRanges[idStart + 2].max);
          w.m4.setRange(kParameterRanges[idStart + 3].min,
                        kParameterRanges[idStart + 3].max);
          w.m5.setRange(kParameterRanges[idStart + 4].min,
                        kParameterRanges[idStart + 4].max);
          w.m6.setRange(kParameterRanges[idStart + 5].min,
                        kParameterRanges[idStart + 5].max);
          w.m7.setRange(kParameterRanges[idStart + 6].min,
                        kParameterRanges[idStart + 6].max);
          w.m8.setRange(kParameterRanges[idStart + 7].min,
                        kParameterRanges[idStart + 7].max);

          w.m1.setUnitLabel(kParameterUnits[idStart + 0]);
          w.m2.setUnitLabel(kParameterUnits[idStart + 1]);
          w.m3.setUnitLabel(kParameterUnits[idStart + 2]);
          w.m4.setUnitLabel(kParameterUnits[idStart + 3]);
          w.m5.setUnitLabel(kParameterUnits[idStart + 4]);
          w.m6.setUnitLabel(kParameterUnits[idStart + 5]);
          w.m7.setUnitLabel(kParameterUnits[idStart + 6]);
          w.m8.setUnitLabel(kParameterUnits[idStart + 7]);

          w.m1.setValue(kParameterRanges[idStart + 0].def);
          w.m2.setValue(kParameterRanges[idStart + 1].def);
          w.m3.setValue(kParameterRanges[idStart + 2].def);
          w.m4.setValue(kParameterRanges[idStart + 3].def);
          w.m5.setValue(kParameterRanges[idStart + 4].def);
          w.m6.setValue(kParameterRanges[idStart + 5].def);
          w.m7.setValue(kParameterRanges[idStart + 6].def);
          w.m8.setValue(kParameterRanges[idStart + 7].def);

          w.label.setLabel(label);
          w.label.setName(label);
          items.push_back(&w);
      }
  } msCompressor;

  struct Limiter : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel strength;
      QuantumValueSliderWithLabel threshold;
      QuantumValueSliderWithLabel attack;
      QuantumValueSliderWithLabel release;
      QuantumValueSliderWithLabel fffb;
      QuantumValueSliderWithLabel knee;
      QuantumValueSliderWithLabel makeup;
      QuantumLabelWithSeparatorLine separator;
      QuantumValueMeterWithLabel gainReduction;

      explicit Limiter(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            strength(&frame, theme),
            threshold(&frame, theme),
            attack(&frame, theme),
            release(&frame, theme),
            fffb(&frame, theme),
            knee(&frame, theme),
            makeup(&frame, theme),
            separator(&frame, theme),
            gainReduction(&frame, theme)
      {
          frame.setName("Limiter");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_limiter_bypass);
          frame.mainWidget.setLabel("Limiter");

          setupSlider(strength, cb, kParameter_limiter_strength, 8);
          setupSlider(threshold, cb, kParameter_limiter_threshold, 8);
          setupSlider(attack, cb, kParameter_limiter_attack, 8);
          setupSlider(release, cb, kParameter_limiter_release, 8);
          setupSlider(fffb, cb, kParameter_limiter_fffb, 8);
          setupSlider(knee, cb, kParameter_limiter_knee, 8);
          setupSlider(makeup, cb, kParameter_limiter_makeup, 8);
          setupSeparatorLine(separator, "Outputs:");
          setupMeter(gainReduction, kParameter_limiter_gain_reduction, 8);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          strength.adjustSize(metrics);
          threshold.adjustSize(metrics);
          attack.adjustSize(metrics);
          release.adjustSize(metrics);
          fffb.adjustSize(metrics);
          knee.adjustSize(metrics);
          makeup.adjustSize(metrics);
          separator.adjustSize(metrics);
          gainReduction.adjustSize(metrics);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }

      void setEnabledColor(const bool enabled)
      {
          const Color color = enabled ? theme.textLightColor : theme.textDarkColor;
          strength.label.setLabelColor(color);
          strength.slider.setTextColor(color);
          threshold.label.setLabelColor(color);
          threshold.slider.setTextColor(color);
          attack.label.setLabelColor(color);
          attack.slider.setTextColor(color);
          release.label.setLabelColor(color);
          release.slider.setTextColor(color);
          fffb.label.setLabelColor(color);
          fffb.slider.setTextColor(color);
          knee.label.setLabelColor(color);
          knee.slider.setTextColor(color);
          makeup.label.setLabelColor(color);
          makeup.slider.setTextColor(color);
          separator.label.setLabelColor(color);
          gainReduction.label.setLabelColor(color);
          gainReduction.meter.setTextColor(color);
      }
  } limiter;

  struct Brickwall : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel ceiling;
      QuantumValueSliderWithLabel release;
      QuantumValueMeterWithLabel limit;

      explicit Brickwall(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            ceiling(&frame, theme),
            release(&frame, theme),
            limit(&frame, theme)
      {
          frame.setName("Brickwall");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_brickwall_bypass);
          frame.mainWidget.setLabel("Brickwall");

          setupSlider(ceiling, cb, kParameter_brickwall_ceiling, 10);
          setupSlider(release, cb, kParameter_brickwall_release, 10);
          setupMeter(limit, kParameter_brickwall_limit, 0);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          ceiling.adjustSize(metrics);
          release.adjustSize(metrics);
          limit.adjustSize(metrics);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }

      void setEnabledColor(const bool enabled)
      {
          const Color color = enabled ? theme.textLightColor : theme.textDarkColor;
          ceiling.label.setLabelColor(color);
          ceiling.slider.setTextColor(color);
          release.label.setLabelColor(color);
          release.slider.setTextColor(color);
          limit.label.setLabelColor(color);
          limit.meter.setTextColor(color);
      }
  } brickwall;

  NanoSubWidget* parameterGroups[8] = {
      &preProcessing.frame,
      &gate.frame,
      &leveler.frame,
      &eq.frame,
      &kneeComp.frame,
      &msCompressor.frame,
      &limiter.frame,
      &brickwall.frame,
  };

  struct PresetButtons : SoundsgoodPresetGroup {
      QuantumButtonWithDescription b1, b2, b3, b4, b5;
      std::vector<QuantumButton*> buttonList = {
          &b1.button,
          &b2.button,
          &b3.button,
          &b4.button,
          &b5.button,
      };

      PresetButtons(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, const QuantumTheme& theme)
          : SoundsgoodPresetGroup(parent, theme),
            b1(&frame, theme),
            b2(&frame, theme),
            b3(&frame, theme),
            b4(&frame, theme),
            b5(&frame, theme)
      {
          frame.setName("Easy Presets");
          frame.mainWidget.setLabel("Easy Presets");
          setupButton(b1, bcb, "Speech Mild", "Use this for regular speech");
          setupButton(b2, bcb, "Speech Medium", "Use this for regular speech");
          setupButton(b3, bcb, "Speech Heavy", "Use this for loud speech");
          setupButton(b4, bcb, "Music Mild", "For regular music");
          setupButton(b5, bcb, "Music Heavy", "For heavy, loud music");
      }

      void adjustSize(const QuantumMetrics& metrics)
      {
          b1.button.adjustSize();
          b1.label.adjustSize();
          b2.button.adjustSize();
          b2.label.adjustSize();
          b3.button.adjustSize();
          b3.label.adjustSize();
          b4.button.adjustSize();
          b4.label.adjustSize();
          b5.button.adjustSize();
          b5.label.adjustSize();
          const uint normalWidth = std::max(b1.button.getWidth(), std::max(b2.button.getWidth(), std::max(b3.button.getWidth(), std::max(b4.button.getWidth(), b5.button.getWidth()))));
          b1.button.setWidth(normalWidth);
          b2.button.setWidth(normalWidth);
          b3.button.setWidth(normalWidth);
          b4.button.setWidth(normalWidth);
          b5.button.setWidth(normalWidth);
          SoundsgoodPresetGroup::adjustSize(metrics);
      }

      inline void setupButton(QuantumButtonWithDescription& b, ButtonEventHandler::Callback* const bcb, const char* const label, const char* const description)
      {
          b.button.setCallback(bcb);
          b.button.setCheckable(true);
          b.button.setId(10003);
          b.button.setLabel(label);
          b.button.setName(label);
          b.label.setLabel(description);
          b.label.setName(String(label) + " [description]");
          items.push_back(&b);
      }
  } presetButtons;

public:
  SoundsGoodUI()
      : UI(kInitialWidth, kInitialHeight),
        easyModeButton(this, theme),
        expertModeButton(this, theme),
        topCenteredGroup(this, this, theme),
        inputGroup(this, this, theme),
        contentGroup(this, theme, expertModeButton),
        outputGroup(this, theme),
        easyMetering(this, theme),
        welcomeLabel(this, theme),
        name(this, theme),
        preProcessing(this, this, this, theme),
        gate(this, this, this, theme),
        leveler(this, this, this, theme),
        eq(this, this, this, theme),
        kneeComp(this, this, this, theme),
        msCompressor(this, this, this, theme),
        limiter(this, this, this, theme),
        brickwall(this, this, this, theme),
        presetButtons(this, this, theme)
  {
    loadSharedResources();

    const double scaleFactor = getScaleFactor();

    if (d_isNotEqual(scaleFactor, 1.0))
    {
        setSize(kInitialWidth * scaleFactor, kInitialHeight * scaleFactor);
        setGeometryConstraints(kInitialWidth * scaleFactor / 2, kInitialHeight * scaleFactor / 2, false);

        theme.borderSize *= scaleFactor;
        theme.padding *= scaleFactor;
        theme.fontSize *= scaleFactor;
        theme.textHeight *= scaleFactor;
        theme.widgetLineSize *= scaleFactor;
        theme.windowPadding *= scaleFactor;
        theme.textPixelRatioWidthCompensation = static_cast<uint>(scaleFactor - 1.0 + 0.25);
    }
    else
    {
        setGeometryConstraints(kInitialWidth / 2, kInitialHeight / 2, false);
    }

    // setup widget properties
    easyModeButton.setCallback(this);
    easyModeButton.setCheckable(true);
    easyModeButton.setId(10001);
    easyModeButton.setLabel("Easy");
    easyModeButton.setName("Easy Mode Button");

    expertModeButton.setCallback(this);
    expertModeButton.setCheckable(true);
    expertModeButton.setId(10002);
    expertModeButton.setLabel("Expert");
    expertModeButton.setName("Expert Mode Button");

    easyMetering.setName("Easy metering for testing");

    static const char* const welcomeMessage = ""
        "Hi there,\n"
        "\n"
        "soundsgood is an automatic mastering plugin for live-streamers,\n"
        "podcasters and alike.\n"
        "\n"
        "You are currently in \"easy\" mode.\n"
        "Select a preset, set your desired target loudness and you're good to go.\n"
        "\n"
        "Hit \"expert\" above to see and tweak what is under the hood.\n"
        "\n"
        "Happy streaming!\n";
    welcomeLabel.setLabel(welcomeMessage);
    welcomeLabel.setName("Welcome Label");
    welcomeLabel.setAlignment(NanoVG::ALIGN_TOP|NanoVG::ALIGN_LEFT);

    contentGroup.setName("Content");

    // bottom of the drawing stack
    topCenteredGroup.toBottom();

    // initial resize and reposition
    resizeWidgets(scaleFactor, getWidth(), getHeight());

    // load initial state, easy mode is default
    easyModeButton.setChecked(true, false);

    for (NanoSubWidget* w : parameterGroups)
        w->hide();
  }

  ~SoundsGoodUI() override
  {
      if (inspectorWindow != nullptr)
      {
          inspectorWindow->close();
          inspectorWindow = nullptr;
      }
  }

  void repositionWidgets()
  {
      const SoundsGoodMetrics metrics(theme);

      const uint width = getWidth();
      const uint borderSize = theme.borderSize;
      const uint padding = theme.padding;
      const uint windowPadding = theme.windowPadding;
      const uint startY = windowPadding * 2 + metrics.button.getHeight();

      topCenteredGroup.setAbsolutePos(windowPadding, windowPadding);
      inputGroup.setAbsolutePos(windowPadding, startY);
      contentGroup.setAbsolutePos(windowPadding + inputGroup.getWidth() + padding * 2, startY);
      outputGroup.setAbsolutePos(width - windowPadding - outputGroup.getWidth(), startY);

      name.setAbsolutePos(outputGroup.getAbsoluteX() - (name.getWidth() - padding) / 2,
                          outputGroup.getAbsoluteY() - padding - name.getHeight());

      presetButtons.setAbsolutePos(contentGroup.getAbsoluteX() + contentGroup.getWidth() - presetButtons.frame.getWidth() - borderSize - padding,
                                   contentGroup.getAbsoluteY() + borderSize + padding);

      const uint inputAreaCenter = inputGroup.getWidth() / 2;
      const uint easyModeButtonOffset = inputAreaCenter - easyModeButton.getWidth() / 2;
      easyModeButton.setAbsolutePos(windowPadding + easyModeButtonOffset, windowPadding);
      expertModeButton.setAbsolutePos(contentGroup.getAbsoluteX() + easyModeButtonOffset, windowPadding);

      welcomeLabel.setAbsolutePos(contentGroup.getAbsoluteX() + borderSize + padding, startY + borderSize + padding);
      easyMetering.setAbsolutePos(contentGroup.getAbsoluteX() + borderSize + padding,
                                  startY + contentGroup.getHeight() - easyMetering.getHeight() - padding);

      // 1st row
      const uint row1y = contentGroup.getAbsoluteY() + borderSize + padding;
      preProcessing.setAbsolutePos(contentGroup.getAbsoluteX() + borderSize + padding, row1y);
      gate.setAbsolutePos(preProcessing.frame.getAbsoluteX() + preProcessing.frame.getWidth() + padding, row1y);
      leveler.setAbsolutePos(gate.frame.getAbsoluteX() + gate.frame.getWidth() + padding, row1y);
      eq.setAbsolutePos(leveler.frame.getAbsoluteX() + leveler.frame.getWidth() + padding, row1y);

      // 2nd row
      const uint highestOf1stRow = std::max(preProcessing.frame.getHeight(), std::max(gate.frame.getHeight(), std::max(leveler.frame.getHeight(), eq.frame.getHeight())));
      const uint row2y = contentGroup.getAbsoluteY() + borderSize + padding * 3 + highestOf1stRow;
      kneeComp.setAbsolutePos(preProcessing.frame.getAbsoluteX(), row2y);
      msCompressor.setAbsolutePos(kneeComp.frame.getAbsoluteX() + kneeComp.frame.getWidth() + padding, row2y);
      limiter.setAbsolutePos(msCompressor.frame.getAbsoluteX() + msCompressor.frame.getWidth() + padding, row2y);
      brickwall.setAbsolutePos(limiter.frame.getAbsoluteX() + limiter.frame.getWidth() + padding, row2y);
  }

  void resizeWidgets(const double scaleFactor, const uint width, const uint height)
  {
      const SoundsGoodMetrics metrics(theme);

      const uint padding = theme.padding * scaleFactor;
      const uint borderSize = theme.borderSize * scaleFactor;
      const uint windowPadding = theme.windowPadding * scaleFactor;
      const uint startY = windowPadding * 2 + metrics.button.getHeight();
      const uint contentHeight = height - startY - windowPadding;

      easyModeButton.adjustSize();
      expertModeButton.adjustSize();
      name.adjustSize();

      inputGroup.adjustSize(metrics, contentHeight);
      outputGroup.adjustSize(metrics, contentHeight);
      contentGroup.setSize(width - windowPadding * 2 - padding * 4 - inputGroup.getWidth() - outputGroup.getWidth(), contentHeight);
      topCenteredGroup.adjustSize(metrics, getWidth(), getHeight(), easyModeButton.getHeight());

      welcomeLabel.setSize(contentGroup.getWidth() - borderSize * 2 - padding * 2, contentHeight - borderSize * 2 - padding * 2);
      easyMetering.setSize(300 * scaleFactor, contentGroup.getHeight() / 2 - padding);

      presetButtons.adjustSize(metrics);

      preProcessing.adjustSize(metrics);
      gate.adjustSize(metrics);
      leveler.adjustSize(metrics);
      eq.adjustSize(metrics);
      kneeComp.adjustSize(metrics);
      msCompressor.adjustSize(metrics);
      limiter.adjustSize(metrics);
      brickwall.adjustSize(metrics);

      repositionWidgets();
  }

protected:
  /* --------------------------------------------------------------------------------------------------------
   * DSP/Plugin Callbacks */

  void parameterChanged(const uint32_t index, const float value) override
  {
    switch (static_cast<Parameters>(index))
    {
    // inputs
    case kParameter_global_bypass:
      topCenteredGroup.globalEnableSwitch.setChecked(value < 0.5f, false);
      break;
    case kParameter_target:
      inputGroup.slider.setValue(value, false);
      break;
    case kParameter_in_gain:
      preProcessing.inputGain.slider.setValue(value, false);
      break;
    case kParameter_mono:
      preProcessing.mono.smallSwitch.setChecked(value > 0.5f, false);
      break;
    case kParameter_phase_l:
      preProcessing.phaseL.smallSwitch.setChecked(value > 0.5f, false);
      break;
    case kParameter_phase_r:
      preProcessing.phaseR.smallSwitch.setChecked(value > 0.5f, false);
      break;
    case kParameter_dc_blocker:
      preProcessing.dcBlocker.smallSwitch.setChecked(value > 0.5f, false);
      break;
    case kParameter_stereo_correct:
      preProcessing.stereoCorrect.smallSwitch.setChecked(value > 0.5f, false);
      break;
    case kParameter_gate_bypass:
      gate.frame.mainWidget.setChecked(value < 0.5f, false);
      gate.setEnabledColor(value < 0.5f);
      break;
    case kParameter_gate_threshold:
      gate.threshold.slider.setValue(value, false);
      break;
    case kParameter_gate_attack:
      gate.attack.slider.setValue(value, false);
      break;
    case kParameter_gate_hold:
      gate.hold.slider.setValue(value, false);
      break;
    case kParameter_gate_release:
      gate.release.slider.setValue(value, false);
      break;
    case kParameter_leveler_bypass:
      leveler.frame.mainWidget.setChecked(value < 0.5f, false);
      leveler.setEnabledColor(value < 0.5f);
      break;
    case kParameter_leveler_speed:
      leveler.speed.slider.setValue(value, false);
      break;
    case kParameter_leveler_gate_threshold:
      leveler.threshold.slider.setValue(value, false);
      break;
    case kParameter_leveler_max_plus:
      leveler.max_plus.slider.setValue(value, false);
      break;
    case kParameter_leveler_max_minus:
      leveler.max_minus.slider.setValue(value, false);
      break;
    case kParameter_eq_bypass:
      eq.frame.mainWidget.setChecked(value < 0.5f, false);
      eq.setEnabledColor(value < 0.5f);
      break;
    case kParameter_eq_highpass_freq:
      eq.highpass.slider.setValue(value, false);
      break;
    case kParameter_eq_tilt_gain:
      eq.tilt_gain.slider.setValue(value, false);
      break;
    case kParameter_eq_side_gain:
      eq.side_gain.slider.setValue(value, false);
      break;
    case kParameter_eq_side_freq:
      eq.side_freq.slider.setValue(value, false);
      break;
    case kParameter_eq_side_bandwidth:
      eq.side_bandwidth.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_bypass:
      kneeComp.frame.mainWidget.setChecked(value < 0.5f, false);
      kneeComp.setEnabledColor(value < 0.5f);
      break;
    case kParameter_kneecomp_strength:
      kneeComp.strength.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_threshold:
      kneeComp.threshold.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_attack:
      kneeComp.attack.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_release:
      kneeComp.release.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_knee:
      kneeComp.knee.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_link:
      kneeComp.link.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_fffb:
      kneeComp.fffb.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_makeup:
      kneeComp.makeup.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_drywet:
      kneeComp.drywet.slider.setValue(value, false);
      break;
    case kParameter_mscomp_bypass:
      msCompressor.frame.mainWidget.setChecked(value < 0.5f, false);
      msCompressor.setEnabledColor(value < 0.5f);
      break;
    case kParameter_mscomp_low_crossover:
      msCompressor.crossover.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_strength:
      msCompressor.strength.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_threshold:
      msCompressor.threshold.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_attack:
      msCompressor.attack.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_release:
      msCompressor.release.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_knee:
      msCompressor.knee.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_link:
      msCompressor.link.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_high_crossover:
      msCompressor.crossover.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_strength:
      msCompressor.strength.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_threshold:
      msCompressor.threshold.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_attack:
      msCompressor.attack.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_release:
      msCompressor.release.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_knee:
      msCompressor.knee.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_link:
      msCompressor.link.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_output_gain:
      msCompressor.outputGain.slider.setValue(value, false);
      break;
    case kParameter_limiter_bypass:
      limiter.frame.mainWidget.setChecked(value < 0.5f, false);
      limiter.setEnabledColor(value < 0.5f);
      break;
    case kParameter_limiter_strength:
      limiter.strength.slider.setValue(value, false);
      break;
    case kParameter_limiter_threshold:
      limiter.threshold.slider.setValue(value, false);
      break;
    case kParameter_limiter_attack:
      limiter.attack.slider.setValue(value, false);
      break;
    case kParameter_limiter_release:
      limiter.release.slider.setValue(value, false);
      break;
    case kParameter_limiter_fffb:
      limiter.fffb.slider.setValue(value, false);
      break;
    case kParameter_limiter_knee:
      limiter.knee.slider.setValue(value, false);
      break;
    case kParameter_limiter_makeup:
      limiter.makeup.slider.setValue(value, false);
      break;
    case kParameter_brickwall_bypass:
      brickwall.frame.mainWidget.setChecked(value < 0.5f, false);
      brickwall.setEnabledColor(value < 0.5f);
      break;
    case kParameter_brickwall_ceiling:
      brickwall.ceiling.slider.setValue(value, false);
      break;
    case kParameter_brickwall_release:
      brickwall.release.slider.setValue(value, false);
      break;
    // outputs
    case kParameter_peakmeter_in_l:
      inputGroup.meter.setValueL(value);
      break;
    case kParameter_peakmeter_in_r:
      inputGroup.meter.setValueR(value);
      break;
    case kParameter_lufs_in:
      inputGroup.meter.setValueLufs(value);
      break;
    case kParameter_leveler_gain:
      topCenteredGroup.levelerGain.meter.setValue(value);
      break;
    case kParameter_lufs_out:
      outputGroup.meter.setValueLufs(value);
      break;
    case kParameter_peakmeter_out_l:
      outputGroup.meter.setValueL(value);
      break;
    case kParameter_peakmeter_out_r:
      outputGroup.meter.setValueR(value);
      break;
    case kParameter_leveler_gate:
      leveler.gate.meter.setValue(value);
      break;
    case kParameter_70:
      kneeComp.m1.meter.setValue(value);
      break;
    case kParameter_71:
      kneeComp.m2.meter.setValue(value);
      break;
    case kParameter_72:
      msCompressor.metersM.m1.setValue(value);
      break;
    case kParameter_73:
      msCompressor.metersS.m1.setValue(value);
      break;
    case kParameter_74:
      msCompressor.metersM.m2.setValue(value);
      break;
    case kParameter_75:
      msCompressor.metersS.m2.setValue(value);
      break;
    case kParameter_76:
      msCompressor.metersM.m3.setValue(value);
      break;
    case kParameter_77:
      msCompressor.metersS.m3.setValue(value);
      break;
    case kParameter_78:
      msCompressor.metersM.m4.setValue(value);
      break;
    case kParameter_79:
      msCompressor.metersS.m4.setValue(value);
      break;
    case kParameter_80:
      msCompressor.metersM.m5.setValue(value);
      break;
    case kParameter_81:
      msCompressor.metersS.m5.setValue(value);
      break;
    case kParameter_82:
      msCompressor.metersM.m6.setValue(value);
      break;
    case kParameter_83:
      msCompressor.metersS.m6.setValue(value);
      break;
    case kParameter_84:
      msCompressor.metersM.m7.setValue(value);
      break;
    case kParameter_85:
      msCompressor.metersS.m7.setValue(value);
      break;
    case kParameter_86:
      msCompressor.metersM.m8.setValue(value);
      break;
    case kParameter_87:
      msCompressor.metersS.m8.setValue(value);
      break;
    case kParameter_limiter_gain_reduction:
      limiter.gainReduction.meter.setValue(value);
      break;
    case kParameter_brickwall_limit:
      brickwall.limit.meter.setValue(value);
      break;
    // terminator
    case kParameterCount:
      break;
    }

    // easy meters
    if (index >= kParameter_70 && index <= kParameter_87)
      easyMetering.setValue(index - kParameter_70, value);
  }

    void stateChanged(const char* key, const char* value) override
    {
        if (std::strcmp(key, "mode") == 0)
        {
            const bool expert = std::strcmp(value, "expert") == 0;
            buttonClicked(expert ? &expertModeButton : &easyModeButton, 0);
        }
    }

  /* --------------------------------------------------------------------------------------------------------
   * DSP/Plugin Callbacks (optional) */

  void sampleRateChanged(double newSampleRate) override {}

  /* --------------------------------------------------------------------------------------------------------
   * Widget Callbacks */

  void onNanoDisplay() override
  {
      beginPath();
      rect(0, 0, getWidth(), getHeight());
      fillColor(theme.windowBackgroundColor);
      fill();
  }

  bool onMouse(const MouseEvent &ev) override {
    if (UI::onMouse(ev))
      return true;

    if (ev.button == 1 && ev.press) {
      if (inspectorWindow == nullptr)
        inspectorWindow = new InspectorWindow(this);
      inspectorWindow->show();
    }

    return false;
  }

  void onResize(const ResizeEvent& ev) override
  {
      resizeWidgets(getScaleFactor(), ev.size.getWidth(), ev.size.getHeight());
      UI::onResize(ev);
  }

#if 0 // FOR TESTING
  static float randomMeterValue()
  {
      const double r = static_cast<double>(std::rand()) / RAND_MAX;
      return r * -70.0;
  }

  void uiIdle() override
  {
      static int doit = 0;
      if (++doit != 20)
          return;
      doit = 0;
      inputGroup.meter.setValues(randomMeterValue(), randomMeterValue(), randomMeterValue());
      outputGroup.meter.setValues(randomMeterValue(), randomMeterValue(), randomMeterValue());
      topCenteredGroup.levelerGain.meter.setValue(30.f);
  }
#endif

  /* --------------------------------------------------------------------------------------------------------
   * Custom Widget Callbacks */

  void reportGroupBypassChanged(const uint id, const bool enabled)
  {
      editParameter(id, true);
      setParameterValue(id, enabled ? 0.f : 1.f);
      editParameter(id, false);
  }

  void buttonClicked(SubWidget* const widget, int) override
  {
      const uint id = widget->getId();

      QuantumSwitch* const qswitch = reinterpret_cast<QuantumSwitch*>(widget);
      DISTRHO_SAFE_ASSERT_RETURN(qswitch != nullptr,);

      const bool enabled = qswitch->isChecked();

      switch (id)
      {
      // bypass switches, inverted operation
      case kParameter_global_bypass:
          reportGroupBypassChanged(id, enabled);
          break;
      case kParameter_gate_bypass:
          gate.setEnabledColor(enabled);
          reportGroupBypassChanged(id, enabled);
          break;
      case kParameter_leveler_bypass:
          leveler.setEnabledColor(enabled);
          topCenteredGroup.levelerGain.label.setLabelColor(enabled ? theme.textLightColor : theme.textDarkColor);
          topCenteredGroup.levelerGain.meter.setTextColor(enabled ? theme.textLightColor : theme.textDarkColor);
          reportGroupBypassChanged(id, enabled);
          break;
      case kParameter_eq_bypass:
          eq.setEnabledColor(enabled);
          reportGroupBypassChanged(id, enabled);
          break;
      case kParameter_kneecomp_bypass:
          kneeComp.setEnabledColor(enabled);
          reportGroupBypassChanged(id, enabled);
          break;
      case kParameter_mscomp_bypass:
          msCompressor.setEnabledColor(enabled);
          reportGroupBypassChanged(id, enabled);
          break;
      case kParameter_limiter_bypass:
          limiter.setEnabledColor(enabled);
          reportGroupBypassChanged(id, enabled);
          break;
      case kParameter_brickwall_bypass:
          brickwall.setEnabledColor(enabled);
          reportGroupBypassChanged(id, enabled);
          break;
      // regular switches, normal operation
      case kParameter_mono:
      case kParameter_phase_l:
      case kParameter_phase_r:
      case kParameter_dc_blocker:
      case kParameter_stereo_correct:
          editParameter(id, true);
          setParameterValue(id, qswitch->isChecked() ? 1.f : 0.f);
          editParameter(id, false);
          break;
      }

      if (widget == &easyModeButton)
      {
          easyModeButton.setChecked(true, false);
          expertModeButton.setChecked(false, false);

          easyMetering.show();
          welcomeLabel.show();
          presetButtons.frame.show();

          for (NanoSubWidget* w : parameterGroups)
              w->hide();
      }
      else if (widget == &expertModeButton)
      {
          easyModeButton.setChecked(false, false);
          expertModeButton.setChecked(true, false);

          easyMetering.hide();
          welcomeLabel.hide();
          presetButtons.frame.hide();

          for (NanoSubWidget* w : parameterGroups)
              w->show();
      }
      else if (std::find(presetButtons.buttonList.begin(), presetButtons.buttonList.end(), widget) != presetButtons.buttonList.end())
      {
          for (QuantumButton* button : presetButtons.buttonList)
              button->setChecked(button == widget, false);
      }
  }

  void knobDragStarted(SubWidget *const widget) override
  {
    editParameter(widget->getId(), true);
  }

  void knobDragFinished(SubWidget *const widget) override
  {
    editParameter(widget->getId(), false);
  }

  void knobValueChanged(SubWidget *const widget, const float value) override
  {
    setParameterValue(widget->getId(), value);
  }

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundsGoodUI)
};

// -----------------------------------------------------------------------------------------------------------

UI* createUI()
{
    return new SoundsGoodUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
