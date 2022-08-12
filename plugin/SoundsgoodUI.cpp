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
  QuantumValueMeter16 easyMetering;
  QuantumLabel welcomeLabel;

  // expert mode groups (TODO convert to same as below)
  QuantumGroupWithVerticallyStackedLayout groupMBCompressor;
  QuantumGroupWithVerticallyStackedLayout groupLimiter;
  QuantumGroupWithVerticallyStackedLayout groupBrickwall;

  // parameters
  struct ParameterGroup {
      QuantumGroupWithVerticallyStackedLayout group;

      explicit ParameterGroup(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, const QuantumTheme& theme)
          : group(parent, theme)
      {
          group.mainSwitch.setCallback(bcb);
      }

      inline void setupSlider(QuantumValueSliderWithLabel& w, KnobEventHandler::Callback* const cb, const int id, const uint nameOffset)
      {
          w.slider.setCallback(cb);
          w.slider.setId(id);
          w.slider.setName(kParameterNames[id]);
          w.slider.setRange(kParameterRanges[id].min, kParameterRanges[id].max);
          w.slider.setValue(kParameterRanges[id].def);
          w.label.setLabel(kParameterNames[id] + nameOffset);
          w.label.setName(String(kParameterNames[id]) + " [label]");
          group.layout.items.push_back(&w);
      }
  };

  struct Gate : ParameterGroup {
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
          group.mainSwitch.setId(kParametergate_bypass);
          group.mainSwitch.setLabel("Gate");
          group.mainSwitch.setName("Gate Switch");

          setupSlider(threshold, cb, kParametergate_threshold, 5);
          setupSlider(attack, cb, kParametergate_attack, 5);
          setupSlider(hold, cb, kParametergate_hold, 5);
          setupSlider(release, cb, kParametergate_release, 5);
      }
  } gate;

  struct StereoControl : ParameterGroup {
      // TODO
      explicit StereoControl(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme)
      {
          group.setName("Stereo Control Group");
          group.mainSwitch.setId(kParametercorrelation_bypass);
          group.mainSwitch.setLabel("Stereo Control");
          group.mainSwitch.setName("Stereo Control Switch");
      }
  } stereoControl;

  struct Leveler : ParameterGroup {
      QuantumValueSliderWithLabel speed;
      QuantumValueSliderWithLabel max_plus;
      QuantumValueSliderWithLabel max_minus;
      QuantumValueSliderWithLabel threshold;
      // TODO gate output
      // TODO gain output
      explicit Leveler(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            speed(parent, theme),
            max_plus(parent, theme),
            max_minus(parent, theme),
            threshold(parent, theme)
      {
          group.setName("Leveler Group");
          group.mainSwitch.setId(kParameterleveler_bypass);
          group.mainSwitch.setLabel("Leveler");
          group.mainSwitch.setName("Leveler Switch");

          setupSlider(speed, cb, kParameterleveler_speed, 8);
          setupSlider(max_plus, cb, kParameterleveler_max_plus, 8);
          setupSlider(max_minus, cb, kParameterleveler_max_minus, 8);
          setupSlider(threshold, cb, kParameterleveler_gate_threshold, 8);
      }
  } leveler;

  struct Eq : ParameterGroup {
      QuantumValueSliderWithLabel highpass;
      QuantumValueSliderWithLabel tilt_gain;
      QuantumValueSliderWithLabel tilt_freq;
      QuantumValueSliderWithLabel side_gain;
      QuantumValueSliderWithLabel side_freq;
      QuantumValueSliderWithLabel side_bandwidth;
      explicit Eq(TopLevelWidget* const parent, ButtonEventHandler::Callback* const bcb, KnobEventHandler::Callback* const cb, const QuantumTheme& theme)
          : ParameterGroup(parent, bcb, theme),
            highpass(parent, theme),
            tilt_gain(parent, theme),
            tilt_freq(parent, theme),
            side_gain(parent, theme),
            side_freq(parent, theme),
            side_bandwidth(parent, theme)
      {
          group.setName("EQ Group");
          group.mainSwitch.setId(kParametereq_bypass);
          group.mainSwitch.setLabel("EQ");
          group.mainSwitch.setName("EQ Switch");

          setupSlider(highpass, cb, kParametereq_highpass_freq, 3);
          setupSlider(tilt_gain, cb, kParametereq_tilt_gain, 3);
          setupSlider(tilt_freq, cb, kParametereq_tilt_freq, 3);
          setupSlider(side_gain, cb, kParametereq_side_gain, 3);
          setupSlider(side_freq, cb, kParametereq_side_freq, 3);
          setupSlider(side_bandwidth, cb, kParametereq_side_bandwidth, 3);
      }
  } eq;

  struct KneeCompressor : ParameterGroup {
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
          group.mainSwitch.setId(kParameterkneecomp_bypass);
          group.mainSwitch.setLabel("Compressor");
          group.mainSwitch.setName("Compressor Switch");

          setupSlider(strength, cb, kParameterkneecomp_strength, 9);
          setupSlider(attack, cb, kParameterkneecomp_attack, 9);
          setupSlider(release, cb, kParameterkneecomp_release, 9);
          setupSlider(knee, cb, kParameterkneecomp_knee, 9);
          setupSlider(link, cb, kParameterkneecomp_link, 9);
          setupSlider(makeup, cb, kParameterkneecomp_makeup, 9);
          setupSlider(threshold, cb, kParametergate_threshold, 9);
      }
  } kneeComp;

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
        groupMBCompressor(this, theme),
        groupLimiter(this, theme),
        groupBrickwall(this, theme),
        gate(this, this, this, theme),
        stereoControl(this, this, this, theme),
        leveler(this, this, this, theme),
        eq(this, this, this, theme),
        kneeComp(this, this, this, theme),
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

    groupMBCompressor.setName("Multi-Band Compressor Group");
    groupMBCompressor.mainSwitch.setLabel("Multi-Band Compressor");
    groupMBCompressor.mainSwitch.setName("Multi-Band Compressor Switch");

    groupLimiter.setName("Limiter Group");
    groupLimiter.mainSwitch.setLabel("Limiter");
    groupLimiter.mainSwitch.setName("Limiter Switch");

    groupBrickwall.setName("Brickwall Group");
    groupBrickwall.mainSwitch.setLabel("Brickwall");
    groupBrickwall.mainSwitch.setName("Brickwall Switch");

    inputMeterSlider.setName("Input Meter with slider");
    inputMeterSlider.slider.setCallback(this);
    inputMeterSlider.slider.setId(kParametertarget);
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
    groupMBCompressor.hideAll();
    groupLimiter.hideAll();
    groupBrickwall.hideAll();
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
      groupMBCompressor.setAbsolutePos(kneeComp.group.getAbsoluteX() + kneeComp.group.getWidth() + padding, kneeComp.group.getAbsoluteY());
      groupLimiter.setAbsolutePos(groupMBCompressor.getAbsoluteX() + groupMBCompressor.getWidth() + padding, kneeComp.group.getAbsoluteY());
      groupBrickwall.setAbsolutePos(groupLimiter.getAbsoluteX() + groupLimiter.getWidth() + padding, kneeComp.group.getAbsoluteY());

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

      // adjust size of individual widgets first
      kneeComp.strength.slider.setSize(metrics.valueSlider);
      kneeComp.attack.slider.setSize(metrics.valueSlider);
      kneeComp.release.slider.setSize(metrics.valueSlider);
      kneeComp.knee.slider.setSize(metrics.valueSlider);
      kneeComp.link.slider.setSize(metrics.valueSlider);
      kneeComp.makeup.slider.setSize(metrics.valueSlider);
      kneeComp.threshold.slider.setSize(metrics.valueSlider);
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

      gate.group.adjustSize();
      stereoControl.group.adjustSize();
      leveler.group.adjustSize();
      eq.group.adjustSize();
      kneeComp.group.adjustSize();
      groupMBCompressor.adjustSize();
      groupLimiter.adjustSize();
      groupBrickwall.adjustSize();

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
    switch (index) {
    case kParametergate_bypass:
      gate.group.mainSwitch.setChecked(value < 0.5f, false);
      break;
    case kParametergate_threshold:
      gate.threshold.slider.setValue(value, false);
      break;
    case kParametergate_attack:
      gate.attack.slider.setValue(value, false);
      break;
    case kParametergate_hold:
      gate.hold.slider.setValue(value, false);
      break;
    case kParametergate_release:
      gate.release.slider.setValue(value, false);
      break;
    case kParametercorrelation_bypass:
      stereoControl.group.mainSwitch.setChecked(value < 0.5f, false);
      break;
    case kParameterleveler_bypass:
      leveler.group.mainSwitch.setChecked(value < 0.5f, false);
      break;
    case kParameterleveler_speed:
      leveler.speed.slider.setValue(value, false);
      break;
    case kParameterleveler_gate_threshold:
      leveler.threshold.slider.setValue(value, false);
      break;
    case kParameterleveler_max_plus:
      leveler.max_plus.slider.setValue(value, false);
      break;
    case kParameterleveler_max_minus:
      leveler.max_minus.slider.setValue(value, false);
      break;
    case kParametereq_bypass:
      eq.group.mainSwitch.setChecked(value < 0.5f, false);
      break;
    case kParametereq_highpass_freq:
      eq.highpass.slider.setValue(value, false);
      break;
    case kParametereq_tilt_gain:
      eq.tilt_gain.slider.setValue(value, false);
      break;
    case kParametereq_tilt_freq:
      eq.tilt_freq.slider.setValue(value, false);
      break;
    case kParametereq_side_gain:
      eq.side_gain.slider.setValue(value, false);
      break;
    case kParametereq_side_freq:
      eq.side_freq.slider.setValue(value, false);
      break;
    case kParametereq_side_bandwidth:
      eq.side_bandwidth.slider.setValue(value, false);
      break;
    case kParameterkneecomp_bypass:
      gate.group.mainSwitch.setChecked(value < 0.5f, false);
      break;
    case kParameterkneecomp_strength:
      kneeComp.strength.slider.setValue(value, false);
      break;
    case kParameterkneecomp_attack:
      kneeComp.attack.slider.setValue(value, false);
      break;
    case kParameterkneecomp_release:
      kneeComp.release.slider.setValue(value, false);
      break;
    case kParameterkneecomp_knee:
      kneeComp.knee.slider.setValue(value, false);
      break;
    case kParameterkneecomp_link:
      kneeComp.link.slider.setValue(value, false);
      break;
    case kParameterkneecomp_makeup:
      kneeComp.makeup.slider.setValue(value, false);
      break;
    case kParameterkneecomp_threshold:
      kneeComp.threshold.slider.setValue(value, false);
      break;
    case kParameterlufs_in:
      if (inputMeterSlider.meter.setNormalizedValue(value))
        inputMeterSlider.repaint();
      break;
    case kParametertarget:
      if (inputMeterSlider.slider.setValue(value, false))
        inputMeterSlider.repaint();
      break;
    case kParameterleveler_gain:
      gainMeter.setNormalizedValue(value);
      break;
    case kParameterlufs_out:
      outputMeter.setNormalizedValue(value);
      break;
    case kParameter52:
    case kParameter53:
    case kParameter54:
    case kParameter55:
    case kParameter56:
    case kParameter57:
    case kParameter58:
    case kParameter59:
    case kParameter60:
    case kParameter61:
    case kParameter62:
    case kParameter63:
    case kParameter64:
    case kParameter65:
    case kParameter66:
    case kParameter67:
    case kParameter68:
    case kParameter69:
      easyMetering.setValue(index - kParameter52, value);
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
          case kParametergate_bypass:
          case kParametercorrelation_bypass:
          case kParameterleveler_bypass:
          case kParametereq_bypass:
          case kParametermscomp_bypass:
          case kParameterkneecomp_bypass:
          case kParameterlimiter_bypass:
          case kParameterbrickwall_bypass:
              editParameter(id, true);
              setParameterValue(id, qswitch->isChecked() ? 0.f : 1.f);
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
          groupMBCompressor.hideAll();
          groupLimiter.hideAll();
          groupBrickwall.hideAll();
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
          groupMBCompressor.showAll();
          groupLimiter.showAll();
          groupBrickwall.showAll();
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

UI *createUI() { return new SoundsGoodUI(); }

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
