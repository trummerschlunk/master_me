/*
 */

#include "DistrhoPluginInfo.h"
#include "DistrhoUI.hpp"

#include "NanoVG.hpp"
#include "extra/ScopedPointer.hpp"
#include "widgets/InspectorWindow.hpp"

#include "SoundsgoodWidgetGroups.hpp"

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

    QuantumLevelMeter meterL;
    QuantumLevelMeter meterR;
    QuantumSpacer spacer;
    QuantumLevelMeter meterLufs;
    QuantumMixerSlider slider;
    QuantumLevelMeter meterGain;

    explicit InputMeterGroup(TopLevelWidget* const parent, KnobEventHandler::Callback* const cb, const QuantumTheme& t)
        : QuantumFrame(parent, t),
          theme(t),
          meterL(this, t),
          meterR(this, t),
          spacer(this),
          meterLufs(this, t),
          slider(this, t),
          meterGain(this, t)
    {
        setName("Inputs");

        meterL.setId(kParameter_peakmeter_in_l);
        meterL.setName("In L");
        meterL.setRange(kParameterRanges[kParameter_peakmeter_in_l].min, kParameterRanges[kParameter_peakmeter_in_l].max);
        meterL.setValue(kParameterRanges[kParameter_peakmeter_in_l].def);

        meterR.setId(kParameter_peakmeter_in_r);
        meterR.setName("In R");
        meterR.setRange(kParameterRanges[kParameter_peakmeter_in_r].min, kParameterRanges[kParameter_peakmeter_in_r].max);
        meterR.setValue(kParameterRanges[kParameter_peakmeter_in_r].def);

        spacer.setName("Spacer");

        meterLufs.setBackgroundColor(theme.levelMeterAlternativeColor);
        meterLufs.setId(kParameter_lufs_in);
        meterLufs.setName("Lufs");
        meterLufs.setRange(kParameterRanges[kParameter_lufs_in].min, kParameterRanges[kParameter_lufs_in].max);
        meterLufs.setValue(kParameterRanges[kParameter_lufs_in].def);

        slider.setCallback(cb);
        slider.setId(kParameter_target);
        slider.setName("Target");
        slider.setRange(kParameterRanges[kParameter_target].min, kParameterRanges[kParameter_target].max);
        slider.setValue(kParameterRanges[kParameter_target].def, false);

        meterGain.setId(kParameter_leveler_gain);
        meterGain.setName("Leveler gain");
        meterGain.setRange(kParameterRanges[kParameter_leveler_gain].min, kParameterRanges[kParameter_leveler_gain].max);
        meterGain.setValue(kParameterRanges[kParameter_leveler_gain].def);
    }

    void adjustSize(const SoundsGoodMetrics& metrics, const uint height)
    {
        const uint usableHeight = height - theme.borderSize * 2 - theme.padding * 2;
        meterL.setSize(metrics.valueMeterVertical.getWidth(), usableHeight);
        meterR.setSize(metrics.valueMeterVertical.getWidth(), usableHeight);
        spacer.setSize(theme.borderSize + theme.padding * 2, usableHeight);
        meterLufs.setSize(metrics.valueMeterVertical.getWidth()/2, usableHeight);
        slider.setSize(metrics.valueMeterVertical.getWidth(), usableHeight); // TODO mixer slider metric
        meterGain.setSize(metrics.valueMeterVertical.getWidth(), usableHeight);
        setSize(meterL.getWidth() + meterR.getWidth() + meterLufs.getWidth() + spacer.getWidth() + slider.getWidth() + meterGain.getWidth() + theme.borderSize * 3 + theme.padding * 7,
                height);
    }

    void setAbsolutePos(const int x, const int y)
    {
        QuantumFrame::setAbsolutePos(x, y);
        meterL.setAbsolutePos(x + theme.borderSize + theme.padding, y + theme.borderSize + theme.padding);
        meterR.setAbsolutePos(meterL.getAbsoluteX() + meterL.getWidth() + theme.padding, meterL.getAbsoluteY());
        spacer.setAbsolutePos(meterR.getAbsoluteX() + meterR.getWidth() + theme.padding, meterL.getAbsoluteY());
        meterLufs.setAbsolutePos(spacer.getAbsoluteX() + spacer.getWidth() + theme.padding, meterL.getAbsoluteY());
        slider.setAbsolutePos(meterLufs.getAbsoluteX() + meterLufs.getWidth() + theme.padding, meterL.getAbsoluteY());
        meterGain.setAbsolutePos(slider.getAbsoluteX() + slider.getWidth() + theme.padding, meterL.getAbsoluteY());
    }
};

// custom layout for output levels (single widget for now)
struct OutputMeterGroup : QuantumFrame
{
    const QuantumTheme& theme;

    QuantumLevelMeter meterLufs;
    QuantumSpacer spacer;
    QuantumLevelMeter meterL;
    QuantumLevelMeter meterR;

    explicit OutputMeterGroup(TopLevelWidget* const parent, const QuantumTheme& t)
        : QuantumFrame(parent, t),
          theme(t),
          meterLufs(this, t),
          spacer(this),
          meterL(this, t),
          meterR(this, t)
    {
        setName("Outputs");

        meterLufs.setBackgroundColor(theme.levelMeterAlternativeColor);
        meterLufs.setId(kParameter_lufs_out);
        meterLufs.setName("Lufs");
        meterLufs.setRange(kParameterRanges[kParameter_lufs_out].min, kParameterRanges[kParameter_lufs_out].max);
        meterLufs.setValue(kParameterRanges[kParameter_lufs_out].def);

        meterL.setId(kParameter_peakmeter_out_l);
        meterL.setName("Out L");
        meterL.setRange(kParameterRanges[kParameter_peakmeter_out_l].min, kParameterRanges[kParameter_peakmeter_out_l].max);
        meterL.setValue(kParameterRanges[kParameter_peakmeter_out_l].def);

        meterR.setId(kParameter_peakmeter_out_r);
        meterR.setName("Out R");
        meterR.setRange(kParameterRanges[kParameter_peakmeter_out_r].min, kParameterRanges[kParameter_peakmeter_out_r].max);
        meterR.setValue(kParameterRanges[kParameter_peakmeter_out_r].def);
    }

    void adjustSize(const SoundsGoodMetrics& metrics, const uint height)
    {
        const uint usableHeight = height - theme.borderSize * 2 - theme.padding * 2;
        meterLufs.setSize(metrics.valueMeterVertical.getWidth()/2, usableHeight);
        spacer.setSize(theme.borderSize + theme.padding * 2, usableHeight);
        meterL.setSize(metrics.valueMeterVertical.getWidth(), usableHeight);
        meterR.setSize(metrics.valueMeterVertical.getWidth(), usableHeight);
        setSize(meterLufs.getWidth() + meterL.getWidth() + meterR.getWidth() + theme.borderSize * 3 + theme.padding * 7, height);
    }

    void setAbsolutePos(const int x, const int y)
    {
        QuantumFrame::setAbsolutePos(x, y);
        meterLufs.setAbsolutePos(x + theme.borderSize + theme.padding, y + theme.borderSize + theme.padding);
        spacer.setAbsolutePos(meterLufs.getAbsoluteX() + meterLufs.getWidth() + theme.padding, meterL.getAbsoluteY());
        meterL.setAbsolutePos(spacer.getAbsoluteX() + spacer.getWidth() + theme.padding, meterLufs.getAbsoluteY());
        meterR.setAbsolutePos(meterL.getAbsoluteX() + meterL.getWidth() + theme.padding, meterLufs.getAbsoluteY());
    }
};

// -----------------------------------------------------------------------------------------------------------

class SoundsGoodUI : public UI,
                     public ButtonEventHandler::Callback,
                     public KnobEventHandler::Callback
{
  static const uint kInitialWidth = 1000;
  static const uint kInitialHeight = 600;

  ScopedPointer<InspectorWindow> inspectorWindow;

  QuantumTheme theme;

  // easy vs expert mode switch buttons
  QuantumButton easyModeButton;
  QuantumButton expertModeButton;

  // global bypass
  QuantumButton globalEnableButton;

  // group of widgets
  InputMeterGroup inputGroup;
  QuantumFrame contentGroup;
  OutputMeterGroup outputGroup;

  // easy mode labels
  QuantumValueMeter18 easyMetering;
  QuantumLabel welcomeLabel;

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
      // NOTE kParameter_leveler_gain is setup separately

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
            drywet(&frame, theme)
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
          drywet.adjustSize(metrics);
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
          labelsMid.label9.setLabel("9");
          items.push_back(&labelsMid);

          setupMeters(metersM, "  m  ", kParameter_69);
          setupMeters(metersS, "  s  ", kParameter_78);

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
          labelsMid.label9.setSize(labelsMidSize);
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
          labelsMid.label9.setLabelColor(color);
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
          w.m9.setId(idStart + 8);

          w.m1.setName(kParameterNames[idStart + 0]);
          w.m2.setName(kParameterNames[idStart + 1]);
          w.m3.setName(kParameterNames[idStart + 2]);
          w.m4.setName(kParameterNames[idStart + 3]);
          w.m5.setName(kParameterNames[idStart + 4]);
          w.m6.setName(kParameterNames[idStart + 5]);
          w.m7.setName(kParameterNames[idStart + 6]);
          w.m8.setName(kParameterNames[idStart + 7]);
          w.m9.setName(kParameterNames[idStart + 8]);

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
          w.m9.setRange(kParameterRanges[idStart + 8].min,
                        kParameterRanges[idStart + 8].max);

          w.m1.setUnitLabel(kParameterUnits[idStart + 0]);
          w.m2.setUnitLabel(kParameterUnits[idStart + 1]);
          w.m3.setUnitLabel(kParameterUnits[idStart + 2]);
          w.m4.setUnitLabel(kParameterUnits[idStart + 3]);
          w.m5.setUnitLabel(kParameterUnits[idStart + 4]);
          w.m6.setUnitLabel(kParameterUnits[idStart + 5]);
          w.m7.setUnitLabel(kParameterUnits[idStart + 6]);
          w.m8.setUnitLabel(kParameterUnits[idStart + 7]);
          w.m9.setUnitLabel(kParameterUnits[idStart + 8]);

          w.m1.setValue(kParameterRanges[idStart + 0].def);
          w.m2.setValue(kParameterRanges[idStart + 1].def);
          w.m3.setValue(kParameterRanges[idStart + 2].def);
          w.m4.setValue(kParameterRanges[idStart + 3].def);
          w.m5.setValue(kParameterRanges[idStart + 4].def);
          w.m6.setValue(kParameterRanges[idStart + 5].def);
          w.m7.setValue(kParameterRanges[idStart + 6].def);
          w.m8.setValue(kParameterRanges[idStart + 7].def);
          w.m9.setValue(kParameterRanges[idStart + 8].def);

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

  struct Brickwall : SoundsgoodParameterGroupWithoutBypassSwitch {
      QuantumValueSliderWithLabel ceiling;
      QuantumValueSliderWithLabel release;
      QuantumValueMeterWithLabel limit;

      explicit Brickwall(TopLevelWidget* const parent, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithoutBypassSwitch(parent, theme),
            ceiling(&frame, theme),
            release(&frame, theme),
            limit(&frame, theme)
      {
          frame.setName("Brickwall");
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
          SoundsgoodParameterGroupWithoutBypassSwitch::adjustSize(metrics);
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
        globalEnableButton(this, theme),
        inputGroup(this, this, theme),
        contentGroup(this, theme),
        outputGroup(this, theme),
        easyMetering(this, theme),
        welcomeLabel(this, theme),
        preProcessing(this, this, this, theme),
        gate(this, this, this, theme),
        leveler(this, this, this, theme),
        eq(this, this, this, theme),
        kneeComp(this, this, this, theme),
        msCompressor(this, this, this, theme),
        limiter(this, this, this, theme),
        brickwall(this, this, theme),
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

    globalEnableButton.setCallback(this);
    globalEnableButton.setCheckable(true);
    globalEnableButton.setChecked(kParameterRanges[kParameter_global_bypass].def, false);
    globalEnableButton.setId(kParameter_global_bypass);
    globalEnableButton.setLabel("Enable");
    globalEnableButton.setName("Global Enable Button");

    inputGroup.setName("Input Group");
    contentGroup.setName("Content Group");
    outputGroup.setName("Output Group");

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

    // initial resize and reposition
    resizeWidgets(scaleFactor, getWidth(), getHeight());

    // load initial state, easy mode is default
    easyModeButton.setChecked(true, false);

    for (NanoSubWidget* w : parameterGroups)
        w->hide();
  }

  ~SoundsGoodUI() override
  {
  }

  void repositionWidgets(const double scaleFactor)
  {
      const SoundsGoodMetrics metrics(theme);

      const uint width = getWidth();
      const uint borderSize = theme.borderSize * scaleFactor;
      const uint padding = theme.padding * scaleFactor;
      const uint windowPadding = theme.windowPadding * scaleFactor;
      const uint startY = windowPadding * 2 + metrics.button.getHeight();

      inputGroup.setAbsolutePos(windowPadding, startY);
      contentGroup.setAbsolutePos(windowPadding + inputGroup.getWidth() + padding * 2, startY);
      outputGroup.setAbsolutePos(width - windowPadding - outputGroup.getWidth(), startY);

      presetButtons.setAbsolutePos(contentGroup.getAbsoluteX() + contentGroup.getWidth() - presetButtons.frame.getWidth() - borderSize - padding,
                                   contentGroup.getAbsoluteY() + borderSize + padding);

      const uint inputAreaCenter = inputGroup.getWidth() / 2;
      const uint easyModeButtonOffset = inputAreaCenter - easyModeButton.getWidth() / 2;
      easyModeButton.setAbsolutePos(windowPadding + easyModeButtonOffset, windowPadding);
      expertModeButton.setAbsolutePos(contentGroup.getAbsoluteX() + easyModeButtonOffset, windowPadding);
      globalEnableButton.setAbsolutePos(outputGroup.getAbsoluteX() - globalEnableButton.getWidth() * 2 - padding - easyModeButtonOffset, windowPadding);

      welcomeLabel.setAbsolutePos(contentGroup.getAbsoluteX() + borderSize + padding, startY + borderSize + padding);
      easyMetering.setAbsolutePos(contentGroup.getAbsoluteX() + contentGroup.getWidth() - easyMetering.getWidth() - padding,
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
      globalEnableButton.adjustSize();

      inputGroup.adjustSize(metrics, contentHeight);
      outputGroup.adjustSize(metrics, contentHeight);
      contentGroup.setSize(width - windowPadding * 2 - padding * 4 - inputGroup.getWidth() - outputGroup.getWidth(), contentHeight);

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

      repositionWidgets(scaleFactor);
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
      globalEnableButton.setChecked(value < 0.5f, false);
      break;
    case kParameter_target:
      inputGroup.slider.setValue(value, false);
      break;
    case kParameter_in_gain:
      preProcessing.inputGain.slider.setValue(value, false);
      break;
    case kParameter_mono:
      preProcessing.mono.switch_.setChecked(value > 0.5f, false);
      break;
    case kParameter_phase_l:
      preProcessing.phaseL.switch_.setChecked(value > 0.5f, false);
      break;
    case kParameter_phase_r:
      preProcessing.phaseR.switch_.setChecked(value > 0.5f, false);
      break;
    case kParameter_dc_blocker:
      preProcessing.dcBlocker.switch_.setChecked(value > 0.5f, false);
      break;
    case kParameter_stereo_correct:
      preProcessing.stereoCorrect.switch_.setChecked(value > 0.5f, false);
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
    case kParameter_brickwall_ceiling:
      brickwall.ceiling.slider.setValue(value, false);
      break;
    case kParameter_brickwall_release:
      brickwall.release.slider.setValue(value, false);
      break;
    // outputs
    case kParameter_peakmeter_in_l:
      inputGroup.meterL.setValue(value);
      break;
    case kParameter_peakmeter_in_r:
      inputGroup.meterR.setValue(value);
      break;
    case kParameter_lufs_in:
      inputGroup.meterLufs.setValue(value);
      break;
    case kParameter_leveler_gain:
      inputGroup.meterGain.setValue(value);
      break;
    case kParameter_lufs_out:
      outputGroup.meterLufs.setValue(value);
      break;
    case kParameter_peakmeter_out_l:
      outputGroup.meterL.setValue(value);
      break;
    case kParameter_peakmeter_out_r:
      outputGroup.meterR.setValue(value);
      break;
    case kParameter_leveler_gate:
      leveler.gate.meter.setValue(value);
      break;
    case kParameter_69:
      msCompressor.metersM.m1.setValue(value);
      break;
    case kParameter_70:
      msCompressor.metersS.m1.setValue(value);
      break;
    case kParameter_71:
      msCompressor.metersM.m2.setValue(value);
      break;
    case kParameter_72:
      msCompressor.metersS.m2.setValue(value);
      break;
    case kParameter_73:
      msCompressor.metersM.m3.setValue(value);
      break;
    case kParameter_74:
      msCompressor.metersS.m3.setValue(value);
      break;
    case kParameter_75:
      msCompressor.metersM.m4.setValue(value);
      break;
    case kParameter_76:
      msCompressor.metersS.m4.setValue(value);
      break;
    case kParameter_77:
      msCompressor.metersM.m5.setValue(value);
      break;
    case kParameter_78:
      msCompressor.metersS.m5.setValue(value);
      break;
    case kParameter_79:
      msCompressor.metersM.m6.setValue(value);
      break;
    case kParameter_80:
      msCompressor.metersS.m6.setValue(value);
      break;
    case kParameter_81:
      msCompressor.metersM.m7.setValue(value);
      break;
    case kParameter_82:
      msCompressor.metersS.m7.setValue(value);
      break;
    case kParameter_83:
      msCompressor.metersM.m8.setValue(value);
      break;
    case kParameter_84:
      msCompressor.metersS.m8.setValue(value);
      break;
    case kParameter_85:
      msCompressor.metersM.m9.setValue(value);
      break;
    case kParameter_86:
      msCompressor.metersS.m9.setValue(value);
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
    if (index >= kParameter_69 && index <= kParameter_86)
      easyMetering.setValue(index - kParameter_69, value);
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
      const uint windowPadding = theme.windowPadding;

      beginPath();
      rect(0, 0, getWidth(), getHeight());
      fillColor(theme.windowBackgroundColor);
      fill();

      fillColor(theme.textLightColor);
      fontSize(theme.fontSize * 2);
      textAlign(ALIGN_RIGHT|ALIGN_MIDDLE);
      text(getWidth() - windowPadding - theme.padding,
           globalEnableButton.getAbsoluteY() + globalEnableButton.getHeight() / 2,
           "soundsgood", nullptr);
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
      // regular switches, normal operation
      case kParameter_mono:
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
