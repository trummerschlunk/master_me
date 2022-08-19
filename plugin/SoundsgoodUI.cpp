/*
 */

#include "DistrhoUI.hpp"

#include "extra/ScopedPointer.hpp"
#include "widgets/InspectorWindow.hpp"

#include "Quantum.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class SoundsGoodUI : public UI,
                     public ButtonEventHandler::Callback,
                     public KnobEventHandler::Callback
{
  static const uint kInitialWidth = 1201;
  static const uint kInitialHeight = 600;

  ScopedPointer<InspectorWindow> inspectorWindow;

  QuantumTheme theme;

  // easy vs expert mode switch buttons
  QuantumButton easyModeButton;
  QuantumButton expertModeButton;

  // group of widgets
  QuantumFrameGroup inputGroup;
  QuantumFrameGroup contentGroup;
  QuantumFrameGroup outputGroup;
  QuantumFrameGroup presetGroup;

  // easy mode labels
  QuantumValueMeter17 easyMetering;
  QuantumLabel welcomeLabel;

  // parameters
  template<class tMainWidget>
  struct ParameterGroup {
      QuantumGroupWithVerticallyStackedLayout<tMainWidget> group;

      // constructor with label as main widget
      explicit ParameterGroup(TopLevelWidget* const parent, const QuantumTheme& theme)
          : group(parent, theme) {}

      // constructor with switch as main widget
      explicit ParameterGroup(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, const QuantumTheme& theme)
          : group(parent, theme)
      {
          group.mainWidget.setCallback(bcb);
      }

      virtual void adjustSize(const QuantumMetrics&)
      {
          group.adjustSize();
      }

      inline void setupSlider(QuantumValueSliderWithLabel& w, KnobEventHandler::Callback* const cb, const int id, const uint nameOffset)
      {
          w.slider.setCallback(cb);
          w.slider.setId(id);
          w.slider.setName(kParameterNames[id]);
          w.slider.setRange(kParameterRanges[id].min, kParameterRanges[id].max);
          w.slider.setValue(kParameterRanges[id].def, false);
          w.label.setLabel(kParameterNames[id] + nameOffset);
          w.label.setName(String(kParameterNames[id]) + " [label]");
          group.layout.items.push_back(&w);
      }

      inline void setupDualSlider(QuantumDualValueSliderWithCenterLabel&w, KnobEventHandler::Callback* const cb, const int id, const uint idOffset, const uint nameOffset)
      {
          w.sliderL.setCallback(cb);
          w.sliderR.setCallback(cb);
          w.sliderL.setId(id);
          w.sliderR.setId(id + idOffset);
          w.sliderL.setName(kParameterNames[id]);
          w.sliderR.setName(kParameterNames[id + idOffset]);
          w.sliderL.setRange(kParameterRanges[id].min, kParameterRanges[id].max);
          w.sliderL.setRange(kParameterRanges[id + idOffset].min, kParameterRanges[id + idOffset].max);
          w.sliderL.setValue(kParameterRanges[id].def, false);
          w.sliderR.setValue(kParameterRanges[id + idOffset].def, false);
          w.label.setLabel(kParameterNames[id] + nameOffset);
          w.label.setName(String(kParameterNames[id]) + " [label]");
          group.layout.items.push_back(&w);
      }

      inline void setupSwitch(QuantumSwitchWithLayout& w, ButtonEventHandler::Callback* const bcb, const int id, const uint nameOffset)
      {
          w.switch_.setCallback(bcb);
          w.switch_.setId(id);
          w.switch_.setChecked(kParameterRanges[id].def > 0.5f, false);
          w.switch_.setLabel(kParameterNames[id] + nameOffset);
          w.switch_.setName(kParameterNames[id]);
          group.layout.items.push_back(&w);
      }
  };

  typedef ParameterGroup<QuantumSwitch> ParameterGroupWithBypassSwitch;
  typedef ParameterGroup<QuantumLabel> ParameterGroupWithoutBypassSwitch;

  struct Gate : ParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel threshold;
      QuantumValueSliderWithLabel attack;
      QuantumValueSliderWithLabel hold;
      QuantumValueSliderWithLabel release;
      // TODO add gain reduction widget

      explicit Gate(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            threshold(parent, theme),
            attack(parent, theme),
            hold(parent, theme),
            release(parent, theme)
      {
          group.setName("Gate Group");
          group.mainWidget.setId(kParameter_gate_bypass);
          group.mainWidget.setLabel("Gate");
          group.mainWidget.setName("Gate Switch");

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
          ParameterGroup::adjustSize(metrics);
      }
  } gate;

  struct StereoControl : ParameterGroupWithBypassSwitch {
      QuantumSwitchWithLayout mono;

      explicit StereoControl(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback*, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            mono(parent, theme)
      {
          group.setName("Stereo Control Group");
          group.mainWidget.setId(kParameter_correlation_bypass);
          group.mainWidget.setLabel("Stereo Control");
          group.mainWidget.setName("Stereo Control Switch");

          setupSwitch(mono, bcb, kParameter_mono, 0);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          // TODO
          // mono.switch_.setSize(metrics.label);xxx
          ParameterGroup::adjustSize(metrics);
      }
  } stereoControl;

  struct Leveler : ParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel speed;
      QuantumValueSliderWithLabel max_plus;
      QuantumValueSliderWithLabel max_minus;
      QuantumValueSliderWithLabel threshold;
      // TODO kParameter_leveler_gain
      // TODO kParameter_leveler_gate

      explicit Leveler(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            speed(parent, theme),
            max_plus(parent, theme),
            max_minus(parent, theme),
            threshold(parent, theme)
      {
          group.setName("Leveler Group");
          group.mainWidget.setId(kParameter_leveler_bypass);
          group.mainWidget.setLabel("Leveler");
          group.mainWidget.setName("Leveler Switch");

          setupSlider(speed, cb, kParameter_leveler_speed, 8);
          setupSlider(max_plus, cb, kParameter_leveler_max_plus, 8);
          setupSlider(max_minus, cb, kParameter_leveler_max_minus, 8);
          setupSlider(threshold, cb, kParameter_leveler_gate_threshold, 8);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          speed.slider.setSize(metrics.valueSlider);
          max_plus.slider.setSize(metrics.valueSlider);
          max_minus.slider.setSize(metrics.valueSlider);
          threshold.slider.setSize(metrics.valueSlider);
          ParameterGroup::adjustSize(metrics);
      }
  } leveler;

  struct Eq : ParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel highpass;
      QuantumValueSliderWithLabel tilt_gain;
      QuantumValueSliderWithLabel side_gain;
      QuantumValueSliderWithLabel side_freq;
      QuantumValueSliderWithLabel side_bandwidth;

      explicit Eq(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            highpass(parent, theme),
            tilt_gain(parent, theme),
            side_gain(parent, theme),
            side_freq(parent, theme),
            side_bandwidth(parent, theme)
      {
          group.setName("EQ Group");
          group.mainWidget.setId(kParameter_eq_bypass);
          group.mainWidget.setLabel("EQ");
          group.mainWidget.setName("EQ Switch");

          setupSlider(highpass, cb, kParameter_eq_highpass_freq, 3);
          setupSlider(tilt_gain, cb, kParameter_eq_tilt_gain, 3);
          setupSlider(side_gain, cb, kParameter_eq_side_gain, 3);
          setupSlider(side_freq, cb, kParameter_eq_side_freq, 3);
          setupSlider(side_bandwidth, cb, kParameter_eq_side_bandwidth, 3);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          highpass.slider.setSize(metrics.valueSlider);
          tilt_gain.slider.setSize(metrics.valueSlider);
          side_gain.slider.setSize(metrics.valueSlider);
          side_freq.slider.setSize(metrics.valueSlider);
          side_bandwidth.slider.setSize(metrics.valueSlider);
          ParameterGroup::adjustSize(metrics);
      }
  } eq;

  struct KneeCompressor : ParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel strength;
      QuantumValueSliderWithLabel attack;
      QuantumValueSliderWithLabel release;
      QuantumValueSliderWithLabel knee;
      QuantumValueSliderWithLabel link;
      QuantumValueSliderWithLabel makeup;
      QuantumValueSliderWithLabel threshold;

      explicit KneeCompressor(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            strength(parent, theme),
            attack(parent, theme),
            release(parent, theme),
            knee(parent, theme),
            link(parent, theme),
            makeup(parent, theme),
            threshold(parent, theme)
      {
          group.setName("Knee Compressor Group");
          group.mainWidget.setId(kParameter_kneecomp_bypass);
          group.mainWidget.setLabel("Compressor");
          group.mainWidget.setName("Compressor Switch");

          setupSlider(strength, cb, kParameter_kneecomp_strength, 9);
          setupSlider(attack, cb, kParameter_kneecomp_attack, 9);
          setupSlider(release, cb, kParameter_kneecomp_release, 9);
          setupSlider(knee, cb, kParameter_kneecomp_knee, 9);
          setupSlider(link, cb, kParameter_kneecomp_link, 9);
          setupSlider(makeup, cb, kParameter_kneecomp_makeup, 9);
          setupSlider(threshold, cb, kParameter_kneecomp_threshold, 9);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          strength.slider.setSize(metrics.valueSlider);
          attack.slider.setSize(metrics.valueSlider);
          release.slider.setSize(metrics.valueSlider);
          knee.slider.setSize(metrics.valueSlider);
          link.slider.setSize(metrics.valueSlider);
          makeup.slider.setSize(metrics.valueSlider);
          threshold.slider.setSize(metrics.valueSlider);
          ParameterGroup::adjustSize(metrics);
      }
  } kneeComp;

  struct MultiBandCompressor : ParameterGroupWithBypassSwitch {
      QuantumDualValueSliderWithCenterLabel crossover;
      QuantumDualValueSliderWithCenterLabel strength;
      QuantumDualValueSliderWithCenterLabel threshold;
      QuantumDualValueSliderWithCenterLabel attack;
      QuantumDualValueSliderWithCenterLabel release;
      QuantumDualValueSliderWithCenterLabel knee;
      QuantumDualValueSliderWithCenterLabel link;
      QuantumValueSliderWithLabel output_gain;
      // TODO kParameter_52 ... kParameter_69

      explicit MultiBandCompressor(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            crossover(parent, theme),
            strength(parent, theme),
            threshold(parent, theme),
            attack(parent, theme),
            release(parent, theme),
            knee(parent, theme),
            link(parent, theme),
            output_gain(parent, theme)
      {
          group.setName("MultiBand Compressor Group");
          group.mainWidget.setId(kParameter_mscomp_bypass);
          group.mainWidget.setLabel("MultiBand Compressor");
          group.mainWidget.setName("MultiBand Compressor Switch");

          constexpr const uint idOffset = kParameter_mscomp_high_crossover - kParameter_mscomp_low_crossover;
          static_assert(kParameter_mscomp_high_strength - kParameter_mscomp_low_strength == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_threshold - kParameter_mscomp_low_threshold == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_attack - kParameter_mscomp_low_attack == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_release - kParameter_mscomp_low_release == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_knee - kParameter_mscomp_low_knee == idOffset, "mscomp param id offset mismatch");
          static_assert(kParameter_mscomp_high_link - kParameter_mscomp_low_link == idOffset, "mscomp param id offset mismatch");

          setupDualSlider(crossover, cb, kParameter_mscomp_low_crossover, idOffset, 4);
          setupDualSlider(strength, cb, kParameter_mscomp_low_strength, idOffset, 4);
          setupDualSlider(threshold, cb, kParameter_mscomp_low_threshold, idOffset, 4);
          setupDualSlider(attack, cb, kParameter_mscomp_low_attack, idOffset, 4);
          setupDualSlider(release, cb, kParameter_mscomp_low_release, idOffset, 4);
          setupDualSlider(knee, cb, kParameter_mscomp_low_knee, idOffset, 4);
          setupDualSlider(link, cb, kParameter_mscomp_low_link, idOffset, 4);
          setupSlider(output_gain, cb, kParameter_mscomp_output_gain, 0);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
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
          output_gain.slider.setSize(metrics.valueSlider);
          ParameterGroup::adjustSize(metrics);
      }
  } mbCompressor;

  struct Limiter : ParameterGroupWithBypassSwitch {
      QuantumValueSliderWithLabel makeup;
      // TODO kParameter_limiter_gain_reduction

      explicit Limiter(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            makeup(parent, theme)
      {
          group.setName("Limiter Group");
          group.mainWidget.setId(kParameter_limiter_bypass);
          group.mainWidget.setLabel("Limiter");
          group.mainWidget.setName("Limiter Switch");

          setupSlider(makeup, cb, kParameter_limiter_makeup, 8);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          makeup.slider.setSize(metrics.valueSlider);
          ParameterGroup::adjustSize(metrics);
      }
  } limiter;

  struct Brickwall : ParameterGroupWithoutBypassSwitch {
      QuantumValueSliderWithLabel ceiling;
      QuantumValueSliderWithLabel release;
      // TODO kParameter_brickwall_limit

      explicit Brickwall(TopLevelWidget* const parent, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, theme),
            ceiling(parent, theme),
            release(parent, theme)
      {
          group.setName("Brickwall Group");
          group.mainWidget.setLabel("Brickwall");
          group.mainWidget.setName("Brickwall Label");

          setupSlider(ceiling, cb, kParameter_brickwall_ceiling, 10);
          setupSlider(release, cb, kParameter_brickwall_release, 10);
      }

      void adjustSize(const QuantumMetrics& metrics) override
      {
          ceiling.slider.setSize(metrics.valueSlider);
          release.slider.setSize(metrics.valueSlider);
          ParameterGroup::adjustSize(metrics);
      }
  } brickwall;

  // meters
  QuantumMixerSliderWithLevelMeter inputMeterSlider;
  QuantumLevelMeter gainMeter;
  QuantumLevelMeter outputMeter;

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
        gate(this, this, this, theme),
        stereoControl(this, this, this, theme),
        leveler(this, this, this, theme),
        eq(this, this, this, theme),
        kneeComp(this, this, this, theme),
        mbCompressor(this, this, this, theme),
        limiter(this, this, this, theme),
        brickwall(this, this, theme),
        inputMeterSlider(this, theme),
        gainMeter(this, theme),
        outputMeter(this, theme)
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

    inputMeterSlider.setName("Input Meter with slider");
    inputMeterSlider.slider.setCallback(this);
    inputMeterSlider.slider.setId(kParameter_target);
    inputMeterSlider.slider.setRange(-50, 0);
    inputMeterSlider.slider.setValue(0, false);

    gainMeter.setName("Gain Meter");

    outputMeter.setName("Output Meter");

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
    gate.group.hideAll();
    stereoControl.group.hideAll();
    leveler.group.hideAll();
    eq.group.hideAll();
    kneeComp.group.hideAll();
    mbCompressor.group.hideAll();
    limiter.group.hideAll();
    brickwall.group.hideAll();
  }

  ~SoundsGoodUI() override
  {
      for (QuantumButton* button : presetButtons)
          delete button;
  }

  void repositionWidgets(const double scaleFactor)
  {
      const uint width = getWidth();
      const uint height = getHeight();
      const uint borderSize = theme.borderSize * scaleFactor;
      const uint padding = theme.padding * scaleFactor;
      const uint buttonHeight = (theme.textHeight + theme.padding * 2) * scaleFactor;
      const uint windowPadding = theme.windowPadding * scaleFactor;
      const uint contentY = windowPadding * 2 + buttonHeight;

      inputGroup.setAbsolutePos(windowPadding, contentY);
      contentGroup.setAbsolutePos(windowPadding + inputGroup.getWidth() + padding * 2, contentY);
      outputGroup.setAbsolutePos(width - windowPadding - outputGroup.getWidth(), contentY);
      presetGroup.setAbsolutePos(windowPadding, height - windowPadding - presetGroup.getHeight());

      inputMeterSlider.setAbsolutePos(inputGroup.getAbsoluteX() + padding, inputGroup.getAbsoluteY() + padding);
      inputMeterSlider.meter.setAbsolutePos(inputMeterSlider.getAbsoluteX() + padding, inputMeterSlider.getAbsoluteY() + padding);
      inputMeterSlider.slider.setAbsolutePos(inputMeterSlider.meter.getAbsoluteX() + inputMeterSlider.meter.getWidth() + padding, inputMeterSlider.getAbsoluteY() + padding);
      gainMeter.setAbsolutePos(inputMeterSlider.getAbsoluteX() + inputMeterSlider.getWidth() + padding * 3, inputGroup.getAbsoluteY() + padding * 2);
      outputMeter.setAbsolutePos(outputGroup.getAbsoluteX() + padding * 2, outputGroup.getAbsoluteY() + padding * 2);

      const uint inputAreaCenter = inputGroup.getWidth() / 2;
      const uint easyModeButtonOffset = inputAreaCenter - easyModeButton.getWidth() / 2;
      easyModeButton.setAbsolutePos(windowPadding + easyModeButtonOffset, windowPadding);
      expertModeButton.setAbsolutePos(contentGroup.getAbsoluteX() + easyModeButtonOffset, windowPadding);

      welcomeLabel.setAbsolutePos(contentGroup.getAbsoluteX() + padding, contentY - contentGroup.getHeight() / 4); // FIXME
      easyMetering.setAbsolutePos(contentGroup.getAbsoluteX() + contentGroup.getWidth() - easyMetering.getWidth() - padding,
                                  contentY + contentGroup.getHeight() - easyMetering.getHeight() - padding);

      // 1st row
      gate.group.setAbsolutePos(contentGroup.getAbsoluteX() + borderSize + padding, contentGroup.getAbsoluteY() + borderSize + padding);
      stereoControl.group.setAbsolutePos(gate.group.getAbsoluteX() + gate.group.getWidth() + padding, gate.group.getAbsoluteY());
      leveler.group.setAbsolutePos(stereoControl.group.getAbsoluteX() + stereoControl.group.getWidth() + padding, gate.group.getAbsoluteY());
      eq.group.setAbsolutePos(leveler.group.getAbsoluteX() + leveler.group.getWidth() + padding, gate.group.getAbsoluteY());

      // 2nd row
      const uint highestOf1stRow = std::max(gate.group.getHeight(), std::max(stereoControl.group.getHeight(), std::max(leveler.group.getHeight(), eq.group.getHeight())));
      kneeComp.group.setAbsolutePos(gate.group.getAbsoluteX(), contentGroup.getAbsoluteY() + borderSize + padding * 3 + highestOf1stRow);
      mbCompressor.group.setAbsolutePos(kneeComp.group.getAbsoluteX() + kneeComp.group.getWidth() + padding, kneeComp.group.getAbsoluteY());
      limiter.group.setAbsolutePos(mbCompressor.group.getAbsoluteX() + mbCompressor.group.getWidth() + padding, kneeComp.group.getAbsoluteY());
      brickwall.group.setAbsolutePos(limiter.group.getAbsoluteX() + limiter.group.getWidth() + padding, kneeComp.group.getAbsoluteY());

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
      const uint padding = theme.padding * scaleFactor;
      const uint buttonHeight = (theme.textHeight + theme.padding * 2) * scaleFactor;
      const uint windowPadding = theme.windowPadding * scaleFactor;
      const uint contentY = windowPadding * 2 + buttonHeight;
      const uint presetGroupHeight = (buttonHeight + theme.padding * 4) * scaleFactor;
      const uint contentHeight = height - windowPadding - contentY - presetGroupHeight - padding * 2;
      // const uint switchesHeight = (theme.textHeight / 2 + theme.borderSize * 2) * scaleFactor;
      // const uint slidersHeight = (theme.textHeight + theme.padding * 2) * scaleFactor;

      const QuantumMetrics metrics(theme);

      // TODO easy / expert buttons
      // TODO preset buttons

      inputGroup.setSize(130, contentHeight); // FIXME
      outputGroup.setSize(50, contentHeight); // FIXME
      contentGroup.setSize(width - windowPadding * 2 - padding * 4 - inputGroup.getWidth() - outputGroup.getWidth(), contentHeight);
      presetGroup.setSize(width - windowPadding * 2, presetGroupHeight);

      inputMeterSlider.setSize(inputGroup.getWidth() * 2 / 3 - padding * 4, inputGroup.getHeight() - padding * 2);
      inputMeterSlider.meter.setSize(inputMeterSlider.getWidth() * 2 / 3, inputMeterSlider.getHeight() - padding * 2);
      inputMeterSlider.slider.setSize(inputMeterSlider.getWidth() / 3, inputMeterSlider.getHeight() - padding * 2);
      gainMeter.setSize(inputGroup.getWidth() / 3 - padding * 2, inputMeterSlider.getHeight() - padding * 2);
      outputMeter.setSize(outputGroup.getWidth() - padding * 4, outputGroup.getHeight() - padding * 4);

      welcomeLabel.setSize(contentGroup.getWidth() - padding * 2, contentHeight - padding * 2);
      easyMetering.setSize(300 * scaleFactor, contentGroup.getHeight() / 2 - padding);

      gate.adjustSize(metrics);
      stereoControl.adjustSize(metrics);
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
    case kParameter_target:
      if (inputMeterSlider.slider.setValue(value, false))
        inputMeterSlider.repaint();
      break;
    case kParameter_gate_bypass:
      gate.group.mainWidget.setChecked(value < 0.5f, false);
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
    case kParameter_correlation_bypass:
      stereoControl.group.mainWidget.setChecked(value < 0.5f, false);
      break;
    case kParameter_mono:
      stereoControl.mono.switch_.setChecked(value > 0.5f, false);
      break;
    case kParameter_leveler_bypass:
      leveler.group.mainWidget.setChecked(value < 0.5f, false);
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
      eq.group.mainWidget.setChecked(value < 0.5f, false);
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
      gate.group.mainWidget.setChecked(value < 0.5f, false);
      break;
    case kParameter_kneecomp_strength:
      kneeComp.strength.slider.setValue(value, false);
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
    case kParameter_kneecomp_makeup:
      kneeComp.makeup.slider.setValue(value, false);
      break;
    case kParameter_kneecomp_threshold:
      kneeComp.threshold.slider.setValue(value, false);
      break;
    case kParameter_mscomp_bypass:
      mbCompressor.group.mainWidget.setChecked(value < 0.5f, false);
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
      mbCompressor.output_gain.slider.setValue(value, false);
      break;
    case kParameter_limiter_bypass:
      limiter.group.mainWidget.setChecked(value < 0.5f, false);
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
    case kParameter_lufs_in:
      if (inputMeterSlider.meter.setNormalizedValue(value))
        inputMeterSlider.repaint();
      break;
    case kParameter_leveler_gain:
      gainMeter.setNormalizedValue(value);
      break;
    case kParameter_lufs_out:
      outputMeter.setNormalizedValue(value);
      break;
    case kParameter_leveler_gate:
      // TODO
      break;
    case kParameter_52:
    case kParameter_53:
    case kParameter_54:
    case kParameter_55:
    case kParameter_56:
    case kParameter_57:
    case kParameter_58:
    case kParameter_59:
    case kParameter_60:
    case kParameter_61:
    case kParameter_62:
    case kParameter_63:
    case kParameter_64:
    case kParameter_65:
    case kParameter_66:
    case kParameter_67:
    case kParameter_68:
    case kParameter_69:
      easyMetering.setValue(index - kParameter_52, value);
      break;
    case kParameter_limiter_gain_reduction:
    case kParameter_brickwall_limit:
      // TODO
      break;
    case kParameterCount:
      break;
    }
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
          case kParameter_correlation_bypass:
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

          gate.group.hideAll();
          stereoControl.group.hideAll();
          leveler.group.hideAll();
          eq.group.hideAll();
          kneeComp.group.hideAll();
          mbCompressor.group.hideAll();
          limiter.group.hideAll();
          brickwall.group.hideAll();
      }
      else if (widget == &expertModeButton)
      {
          easyModeButton.setChecked(false, false);
          expertModeButton.setChecked(true, false);

          easyMetering.hide();
          welcomeLabel.hide();

          gate.group.showAll();
          stereoControl.group.showAll();
          leveler.group.showAll();
          eq.group.showAll();
          kneeComp.group.showAll();
          mbCompressor.group.showAll();
          limiter.group.showAll();
          brickwall.group.showAll();
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
