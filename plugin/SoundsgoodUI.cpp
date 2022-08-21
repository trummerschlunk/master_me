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

    QuantumLevelMeter meterLufs;
    QuantumMixerSlider slider;
    QuantumLevelMeter meterGain;

    explicit InputMeterGroup(TopLevelWidget* const parent, const QuantumTheme& t)
        : QuantumFrame(parent, t),
          theme(t),
          meterLufs(parent, t),
          slider(parent, t),
          meterGain(parent, t) {}

    void adjustSize(const SoundsGoodMetrics& metrics, const uint height)
    {
        meterLufs.setSize(metrics.valueMeterVertical.getWidth(), height);
        slider.setSize(metrics.valueMeterVertical.getWidth(), height); // TODO mixer slider metric
        meterGain.setSize(metrics.valueMeterVertical.getWidth(), height);
        setSize(meterLufs.getWidth() + slider.getWidth() + meterGain.getWidth() + theme.borderSize * 2 + theme.padding * 5,
                height + theme.borderSize * 2 + theme.padding * 5);
    }

    void setAbsolutePos(const int x, const int y)
    {
        QuantumFrame::setAbsolutePos(x, y);
        meterLufs.setAbsolutePos(x + theme.borderSize + theme.padding, y + theme.borderSize + theme.padding);
        slider.setAbsolutePos(meterLufs.getAbsoluteX() + meterLufs.getWidth() + theme.padding, y + theme.borderSize + theme.padding);
        meterGain.setAbsolutePos(slider.getAbsoluteX() + slider.getWidth() + theme.padding, y + theme.borderSize + theme.padding);
    }
};

// custom layout for output levels (single widget for now)
struct OutputMeterGroup : QuantumFrame
{
    const QuantumTheme& theme;

    QuantumLevelMeter meter;

    explicit OutputMeterGroup(TopLevelWidget* const parent, const QuantumTheme& t)
        : QuantumFrame(parent, t),
          theme(t),
          meter(parent, t) {}

    void adjustSize(const SoundsGoodMetrics& metrics, const uint height)
    {
        meter.setSize(metrics.valueMeterVertical.getWidth(), height);
        setSize(meter.getWidth() + theme.borderSize * 2 + theme.padding * 2,
                height + theme.borderSize * 2 + theme.padding * 5);
    }

    void setAbsolutePos(const int x, const int y)
    {
        QuantumFrame::setAbsolutePos(x, y);
        meter.setAbsolutePos(x + theme.borderSize + theme.padding, y + theme.borderSize + theme.padding);
    }
};

// -----------------------------------------------------------------------------------------------------------

class SoundsGoodUI : public UI,
                     public ButtonEventHandler::Callback,
                     public KnobEventHandler::Callback
{
  static const uint kInitialWidth = 1201;
  static const uint kInitialHeight = 760;

  ScopedPointer<InspectorWindow> inspectorWindow;

  QuantumTheme theme;

  // easy vs expert mode switch buttons
  QuantumButton easyModeButton;
  QuantumButton expertModeButton;

  // group of widgets
  InputMeterGroup inputGroup;
  QuantumFrame contentGroup;
  OutputMeterGroup outputGroup;
  QuantumFrame presetGroup;

  // easy mode labels
  QuantumValueMeter17 easyMetering;
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
          inputGain.slider.setSize(metrics.valueSlider);
          mono.switch_.adjustSize();
          phaseL.switch_.adjustSize();
          phaseR.switch_.adjustSize();
          dcBlocker.switch_.adjustSize();
          stereoCorrect.switch_.adjustSize();
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
          threshold.slider.setSize(metrics.valueSlider);
          attack.slider.setSize(metrics.valueSlider);
          hold.slider.setSize(metrics.valueSlider);
          release.slider.setSize(metrics.valueSlider);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
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
          speed.slider.setSize(metrics.valueSlider);
          threshold.slider.setSize(metrics.valueSlider);
          max_plus.slider.setSize(metrics.valueSlider);
          max_minus.slider.setSize(metrics.valueSlider);
          separator.label.adjustSize();
          gate.meter.setSize(metrics.valueMeterHorizontal);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
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
          highpass.slider.setSize(metrics.valueSlider);
          tilt.label.adjustSize();
          tilt_gain.slider.setSize(metrics.valueSlider);
          side.label.adjustSize();
          side_gain.slider.setSize(metrics.valueSlider);
          side_freq.slider.setSize(metrics.valueSlider);
          side_bandwidth.slider.setSize(metrics.valueSlider);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
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
      // TODO meters here??

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
          strength.slider.setSize(metrics.valueSlider);
          threshold.slider.setSize(metrics.valueSlider);
          attack.slider.setSize(metrics.valueSlider);
          release.slider.setSize(metrics.valueSlider);
          knee.slider.setSize(metrics.valueSlider);
          link.slider.setSize(metrics.valueSlider);
          fffb.slider.setSize(metrics.valueSlider);
          makeup.slider.setSize(metrics.valueSlider);
          drywet.slider.setSize(metrics.valueSlider);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
      }
  } kneeComp;

  struct MultiBandCompressor : SoundsgoodParameterGroupWithBypassSwitch {
      QuantumDualLabelWithCenterSpacer labelsTop;
      QuantumDualValueSliderWithCenterLabel crossover;
      QuantumDualValueSliderWithCenterLabel strength;
      QuantumDualValueSliderWithCenterLabel threshold;
      QuantumDualValueSliderWithCenterLabel attack;
      QuantumDualValueSliderWithCenterLabel release;
      QuantumDualValueSliderWithCenterLabel knee;
      QuantumDualValueSliderWithCenterLabel link;
      MultiBandCompressorLabels labelsMid;
      MultiBandCompressorValueMeters metersM;
      MultiBandCompressorValueMeters metersS;
      MultiBandCompressorOutputGainGroup outputGain;

      explicit MultiBandCompressor(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : SoundsgoodParameterGroupWithBypassSwitch(parent, theme),
            labelsTop(&frame, theme),
            crossover(&frame, theme),
            strength(&frame, theme),
            threshold(&frame, theme),
            attack(&frame, theme),
            release(&frame, theme),
            knee(&frame, theme),
            link(&frame, theme),
            labelsMid(&frame, theme),
            metersM(&frame, theme),
            metersS(&frame, theme),
            outputGain(&frame, theme)
      {
          frame.setName("MultiBand Compressor");
          frame.mainWidget.setCallback(bcb);
          frame.mainWidget.setId(kParameter_mscomp_bypass);
          frame.mainWidget.setLabel("MultiBand Compressor");

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

          setupDualSlider(crossover, cb, kParameter_mscomp_low_crossover, idOffset, 4);
          setupDualSlider(strength, cb, kParameter_mscomp_low_strength, idOffset, 4);
          setupDualSlider(threshold, cb, kParameter_mscomp_low_threshold, idOffset, 4);
          setupDualSlider(attack, cb, kParameter_mscomp_low_attack, idOffset, 4);
          setupDualSlider(release, cb, kParameter_mscomp_low_release, idOffset, 4);
          setupDualSlider(knee, cb, kParameter_mscomp_low_knee, idOffset, 4);
          setupDualSlider(link, cb, kParameter_mscomp_low_link, idOffset, 4);

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
          crossover.sliderL.setSize(metrics.valueSlider);
          crossover.sliderR.setSize(metrics.valueSlider);
          strength.sliderL.setSize(metrics.valueSlider);
          strength.sliderR.setSize(metrics.valueSlider);
          threshold.sliderL.setSize(metrics.valueSlider);
          threshold.sliderR.setSize(metrics.valueSlider);
          attack.sliderL.setSize(metrics.valueSlider);
          attack.sliderR.setSize(metrics.valueSlider);
          release.sliderL.setSize(metrics.valueSlider);
          release.sliderR.setSize(metrics.valueSlider);
          knee.sliderL.setSize(metrics.valueSlider);
          knee.sliderR.setSize(metrics.valueSlider);
          link.sliderL.setSize(metrics.valueSlider);
          link.sliderR.setSize(metrics.valueSlider);
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
          metersM.label.adjustSize();
          metersS.label.adjustSize();
          metersM.m1.setSize(metrics.valueMeterVertical);
          metersM.m2.setSize(metrics.valueMeterVertical);
          metersM.m3.setSize(metrics.valueMeterVertical);
          metersM.m4.setSize(metrics.valueMeterVertical);
          metersM.m5.setSize(metrics.valueMeterVertical);
          metersM.m6.setSize(metrics.valueMeterVertical);
          metersM.m7.setSize(metrics.valueMeterVertical);
          metersM.m8.setSize(metrics.valueMeterVertical);
          metersM.m9.setSize(metrics.valueMeterVertical);
          metersS.m1.setSize(metrics.valueMeterVertical);
          metersS.m2.setSize(metrics.valueMeterVertical);
          metersS.m3.setSize(metrics.valueMeterVertical);
          metersS.m4.setSize(metrics.valueMeterVertical);
          metersS.m5.setSize(metrics.valueMeterVertical);
          metersS.m6.setSize(metrics.valueMeterVertical);
          metersS.m7.setSize(metrics.valueMeterVertical);
          metersS.m8.setSize(metrics.valueMeterVertical);
          metersS.m9.setSize(metrics.valueMeterVertical);
          outputGain.fixedSpace.setSize(metrics.valueSlider);
          outputGain.slider.setSize(metrics.valueSlider);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
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
  } mbCompressor;

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
          strength.slider.setSize(metrics.valueSlider);
          threshold.slider.setSize(metrics.valueSlider);
          attack.slider.setSize(metrics.valueSlider);
          release.slider.setSize(metrics.valueSlider);
          fffb.slider.setSize(metrics.valueSlider);
          knee.slider.setSize(metrics.valueSlider);
          makeup.slider.setSize(metrics.valueSlider);
          separator.label.adjustSize();
          gainReduction.meter.setSize(metrics.valueMeterHorizontal);
          SoundsgoodParameterGroupWithBypassSwitch::adjustSize(metrics);
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
          ceiling.slider.setSize(metrics.valueSlider);
          release.slider.setSize(metrics.valueSlider);
          limit.meter.setSize(metrics.valueMeterHorizontal);
          SoundsgoodParameterGroupWithoutBypassSwitch::adjustSize(metrics);
      }
  } brickwall;

  NanoSubWidget* parameterGroups[8] = {
      &preProcessing.frame,
      &gate.frame,
      &leveler.frame,
      &eq.frame,
      &kneeComp.frame,
      &mbCompressor.frame,
      &limiter.frame,
      &brickwall.frame,
  };

  // preset buttons
  std::vector<QuantumButton*> presetButtons;

public:
  SoundsGoodUI()
      : UI(kInitialWidth, kInitialHeight),
        easyModeButton(this, theme),
        expertModeButton(this, theme),
        inputGroup(this, theme),
        contentGroup(this, theme),
        outputGroup(this, theme),
        presetGroup(this, theme),
        easyMetering(this, theme),
        welcomeLabel(this, theme),
        preProcessing(this, this, this, theme),
        gate(this, this, this, theme),
        leveler(this, this, this, theme),
        eq(this, this, this, theme),
        kneeComp(this, this, this, theme),
        mbCompressor(this, this, this, theme),
        limiter(this, this, this, theme),
        brickwall(this, this, theme)
  {
    loadSharedResources();

    const double scaleFactor = getScaleFactor();

    if (d_isNotEqual(scaleFactor, 1.0))
    {
        setSize(kInitialWidth * scaleFactor, kInitialHeight * scaleFactor);
        setGeometryConstraints(kInitialWidth * scaleFactor / 2, kInitialHeight * scaleFactor / 2, false);
    }
    else
    {
        setGeometryConstraints(kInitialWidth / 2, kInitialHeight / 2, false);
    }

    // setup widget properties
    easyModeButton.setCallback(this);
    easyModeButton.setCheckable(true);
    easyModeButton.setLabel("Easy");
    easyModeButton.setName("Easy Mode Button");

    expertModeButton.setCallback(this);
    expertModeButton.setCheckable(true);
    expertModeButton.setLabel("Expert");
    expertModeButton.setName("Expert Mode Button");

    inputGroup.setName("Input Group");
    contentGroup.setName("Content Group");
    outputGroup.setName("Output Group");
    presetGroup.setName("Preset Group");

    easyMetering.setName("Easy metering for testing");

    static const char* const welcomeMessage = ""
        "Hi there,\n"
        "\n"
        "soundsgood is an automatic mastering plugin for live-streamers, podcasters and alike.\n"
        "\n"
        "You are currently in \"easy\" mode.\n"
        "Select a preset below, set your desired target loudness and you're good to go.\n"
        "\n"
        "Hit \"expert\" above to see and tweak what is under the hood.\n"
        "\n"
        "Happy streaming!\n";
    welcomeLabel.setLabel(welcomeMessage);
    welcomeLabel.setName("Welcome Label");

    inputGroup.setName("Input Group");
    inputGroup.slider.setCallback(this);
    inputGroup.slider.setId(kParameter_target);
    inputGroup.slider.setName("Input Group slider");
    inputGroup.slider.setRange(kParameterRanges[kParameter_target].min, kParameterRanges[kParameter_target].max);
    inputGroup.slider.setValue(kParameterRanges[kParameter_target].def, false);

    inputGroup.meterLufs.setId(kParameter_lufs_in);
    inputGroup.meterLufs.setName("Input Group lufs meter");
    inputGroup.meterLufs.setRange(kParameterRanges[kParameter_lufs_in].min, kParameterRanges[kParameter_lufs_in].max);
    inputGroup.meterLufs.setValue(kParameterRanges[kParameter_lufs_in].def);

    inputGroup.meterGain.setId(kParameter_leveler_gain);
    inputGroup.meterGain.setName("Input Group gain meter");
    inputGroup.meterGain.setRange(kParameterRanges[kParameter_leveler_gain].min, kParameterRanges[kParameter_leveler_gain].max);
    inputGroup.meterGain.setValue(kParameterRanges[kParameter_leveler_gain].def);

    outputGroup.setName("Output Group");
    outputGroup.meter.setId(kParameter_lufs_out);
    outputGroup.meter.setName("Output Meter");
    outputGroup.meter.setRange(kParameterRanges[kParameter_lufs_out].min, kParameterRanges[kParameter_lufs_out].max);
    outputGroup.meter.setValue(kParameterRanges[kParameter_lufs_out].def);

    static const struct {
        const char* const label;
        const int presetId;
    } presetButtonsInfo[] = {
        { "Speech Mild", 0 },
        { "Speech Medium", 1 },
        { "Speech Heavy", 2 },
        { "Music Mild", 3 },
        { "Music Heavy", 4 },
    };

    for (auto presetInfo : presetButtonsInfo)
    {
        QuantumButton* const button = new QuantumButton(this, theme);
        button->setCallback(this);
        button->setCheckable(true);
        button->setLabel(presetInfo.label);
        button->setName(presetInfo.label);
        presetButtons.push_back(button);
    }

    // initial resize and reposition
    resizeWidgets(scaleFactor, getWidth(), getHeight());

    // load initial state
    easyModeButton.setChecked(true, false);

    for (NanoSubWidget* w : parameterGroups)
        w->hide();
  }

  ~SoundsGoodUI() override
  {
      for (QuantumButton* button : presetButtons)
          delete button;
  }

  void repositionWidgets(const double scaleFactor)
  {
      const SoundsGoodMetrics metrics(theme);

      const uint width = getWidth();
      const uint height = getHeight();
      const uint borderSize = theme.borderSize * scaleFactor;
      const uint padding = theme.padding * scaleFactor;
      const uint windowPadding = theme.windowPadding * scaleFactor;
      const uint startY = windowPadding * 2 + metrics.button.getHeight();

      inputGroup.setAbsolutePos(windowPadding, startY);
      contentGroup.setAbsolutePos(windowPadding + inputGroup.getWidth() + padding * 2, startY);
      outputGroup.setAbsolutePos(width - windowPadding - outputGroup.getWidth(), startY);
      presetGroup.setAbsolutePos(windowPadding, height - windowPadding - presetGroup.getHeight());

      const uint inputAreaCenter = inputGroup.getWidth() / 2;
      const uint easyModeButtonOffset = inputAreaCenter - easyModeButton.getWidth() / 2;
      easyModeButton.setAbsolutePos(windowPadding + easyModeButtonOffset, windowPadding);
      expertModeButton.setAbsolutePos(contentGroup.getAbsoluteX() + easyModeButtonOffset, windowPadding);

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
      mbCompressor.setAbsolutePos(kneeComp.frame.getAbsoluteX() + kneeComp.frame.getWidth() + padding, row2y);
      limiter.setAbsolutePos(mbCompressor.frame.getAbsoluteX() + mbCompressor.frame.getWidth() + padding, row2y);
      brickwall.setAbsolutePos(limiter.frame.getAbsoluteX() + limiter.frame.getWidth() + padding, row2y);

      uint buttonIndex = 0;
      for (QuantumButton* button : presetButtons)
      {
          button->setAbsolutePos(presetGroup.getAbsoluteX() + padding * 2 + (button->getWidth() + padding) * buttonIndex,
                                 presetGroup.getAbsoluteY() + padding * 2);
          ++buttonIndex;
      }
  }

  void resizeWidgets(const double scaleFactor, const uint width, const uint height)
  {
      const SoundsGoodMetrics metrics(theme);

      const uint padding = theme.padding * scaleFactor;
      const uint buttonHeight = (theme.textHeight + theme.padding * 2) * scaleFactor;
      const uint borderSize = theme.borderSize * scaleFactor;
      const uint windowPadding = theme.windowPadding * scaleFactor;
      const uint contentY = windowPadding * 2 + buttonHeight;
      const uint presetGroupHeight = (buttonHeight + theme.padding * 4) * scaleFactor;
      const uint contentHeight = height - windowPadding - contentY - presetGroupHeight - padding * 2;
      // const uint switchesHeight = (theme.textHeight / 2 + theme.borderSize * 2) * scaleFactor;
      // const uint slidersHeight = (theme.textHeight + theme.padding * 2) * scaleFactor;

      // TODO easy / expert buttons
      // TODO preset buttons

      inputGroup.adjustSize(metrics, contentHeight);
      outputGroup.adjustSize(metrics, contentHeight);
      contentGroup.setSize(width - windowPadding * 2 - padding * 4 - inputGroup.getWidth() - outputGroup.getWidth(), contentHeight);
      presetGroup.setSize(width - windowPadding * 2, presetGroupHeight);

      welcomeLabel.setSize(contentGroup.getWidth() - borderSize * 2 - padding * 2, contentHeight - borderSize * 2 - padding * 2);
      easyMetering.setSize(300 * scaleFactor, contentGroup.getHeight() / 2 - padding);

      preProcessing.adjustSize(metrics);
      gate.adjustSize(metrics);
      leveler.adjustSize(metrics);
      eq.adjustSize(metrics);
      kneeComp.adjustSize(metrics);
      mbCompressor.adjustSize(metrics);
      limiter.adjustSize(metrics);
      brickwall.adjustSize(metrics);

      const uint presetButtonWidth = std::floor(double(presetGroup.getWidth() - padding * (2 + presetButtons.size())) / presetButtons.size());

      for (QuantumButton* button : presetButtons)
          button->setSize(presetButtonWidth, buttonHeight);

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
      // TODO
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
      gate.frame.mainWidget.setChecked(value < 0.5f, false);
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
      mbCompressor.frame.mainWidget.setChecked(value < 0.5f, false);
      break;
    case kParameter_mscomp_low_crossover:
      mbCompressor.crossover.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_strength:
      mbCompressor.strength.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_threshold:
      mbCompressor.threshold.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_attack:
      mbCompressor.attack.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_release:
      mbCompressor.release.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_knee:
      mbCompressor.knee.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_low_link:
      mbCompressor.link.sliderL.setValue(value, false);
      break;
    case kParameter_mscomp_high_crossover:
      mbCompressor.crossover.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_strength:
      mbCompressor.strength.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_threshold:
      mbCompressor.threshold.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_attack:
      mbCompressor.attack.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_release:
      mbCompressor.release.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_knee:
      mbCompressor.knee.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_high_link:
      mbCompressor.link.sliderR.setValue(value, false);
      break;
    case kParameter_mscomp_output_gain:
      mbCompressor.outputGain.slider.setValue(value, false);
      break;
    case kParameter_limiter_bypass:
      limiter.frame.mainWidget.setChecked(value < 0.5f, false);
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
    case kParameter_lufs_in:
      inputGroup.meterLufs.setValue(value);
      break;
    case kParameter_leveler_gain:
      inputGroup.meterGain.setValue(value);
      break;
    case kParameter_lufs_out:
      outputGroup.meter.setValue(value);
      break;
    case kParameter_leveler_gate:
      leveler.gate.meter.setValue(value);
      break;
    case kParameter_69:
      mbCompressor.metersM.m1.setValue(value);
      break;
    case kParameter_70:
      mbCompressor.metersS.m1.setValue(value);
      break;
    case kParameter_71:
      mbCompressor.metersM.m2.setValue(value);
      break;
    case kParameter_72:
      mbCompressor.metersS.m2.setValue(value);
      break;
    case kParameter_73:
      mbCompressor.metersM.m3.setValue(value);
      break;
    case kParameter_74:
      mbCompressor.metersS.m3.setValue(value);
      break;
    case kParameter_75:
      mbCompressor.metersM.m4.setValue(value);
      break;
    case kParameter_76:
      mbCompressor.metersS.m4.setValue(value);
      break;
    case kParameter_77:
      mbCompressor.metersM.m5.setValue(value);
      break;
    case kParameter_78:
      mbCompressor.metersS.m5.setValue(value);
      break;
    case kParameter_79:
      mbCompressor.metersM.m6.setValue(value);
      break;
    case kParameter_80:
      mbCompressor.metersS.m6.setValue(value);
      break;
    case kParameter_81:
      mbCompressor.metersM.m7.setValue(value);
      break;
    case kParameter_82:
      mbCompressor.metersS.m7.setValue(value);
      break;
    case kParameter_83:
      mbCompressor.metersM.m8.setValue(value);
      break;
    case kParameter_84:
      mbCompressor.metersS.m8.setValue(value);
      break;
    case kParameter_85:
      mbCompressor.metersM.m9.setValue(value);
      break;
    case kParameter_86:
      mbCompressor.metersS.m9.setValue(value);
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
      const double scaleFactor = getScaleFactor();
      const uint windowPadding = theme.windowPadding * scaleFactor;

      beginPath();
      rect(0, 0, getWidth(), getHeight());
      fillColor(theme.windowBackgroundColor);
      fill();

      fillColor(theme.textLightColor);
      fontSize(theme.fontSize * 2 * scaleFactor);
      textAlign(ALIGN_RIGHT|ALIGN_TOP);
      text(getWidth() - windowPadding - theme.padding * scaleFactor, windowPadding, "soundsgood", nullptr);
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

  void buttonClicked(SubWidget* const widget, int) override
  {
      if (const uint id = widget->getId())
      {
          QuantumSwitch* const qswitch = reinterpret_cast<QuantumSwitch*>(widget);
          DISTRHO_SAFE_ASSERT_RETURN(qswitch != nullptr,);

          switch (id)
          {
          // bypass switches, inverted operation
          case kParameter_gate_bypass:
          case kParameter_stereo_correct:
          case kParameter_leveler_bypass:
          case kParameter_eq_bypass:
          case kParameter_mscomp_bypass:
          case kParameter_kneecomp_bypass:
          case kParameter_limiter_bypass:
              editParameter(id, true);
              setParameterValue(id, qswitch->isChecked() ? 0.f : 1.f);
              editParameter(id, false);
              break;
          // regular switches, normal operation
          case kParameter_mono:
              editParameter(id, true);
              setParameterValue(id, qswitch->isChecked() ? 1.f : 0.f);
              editParameter(id, false);
              break;
          }

          return;
      }

      if (widget == &easyModeButton)
      {
          easyModeButton.setChecked(true, false);
          expertModeButton.setChecked(false, false);

          easyMetering.show();
          welcomeLabel.show();

          for (NanoSubWidget* w : parameterGroups)
              w->hide();
      }
      else if (widget == &expertModeButton)
      {
          easyModeButton.setChecked(false, false);
          expertModeButton.setChecked(true, false);

          easyMetering.hide();
          welcomeLabel.hide();

          for (NanoSubWidget* w : parameterGroups)
              w->show();
      }
      else if (std::find(presetButtons.begin(), presetButtons.end(), widget) != presetButtons.end())
      {
          for (QuantumButton* button : presetButtons)
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
