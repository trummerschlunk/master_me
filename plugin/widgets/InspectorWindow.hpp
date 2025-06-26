/*
 * Inspector Window for DPF
 * Copyright (C) 2022-2025 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#include "DearImGui.hpp"
#include "DistrhoPluginUtils.hpp"
#include "Quantum.hpp"

#include "Application.hpp"
#include "extra/Filesystem.hpp"

#include "json.hpp"

#include <fstream>
#include <list>

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

static std::string ColorToString(const Color& color)
{
    char str[10];
    std::snprintf(str,
                  sizeof(str),
                  "#%02x%02x%02x",
                  d_roundToIntPositive(color.red * 255),
                  d_roundToIntPositive(color.green * 255),
                  d_roundToIntPositive(color.blue * 255));
    return str;
}

// --------------------------------------------------------------------------------------------------------------------

struct MasterMeTheme : QuantumTheme
{
    MasterMeTheme(const double scaleFactor, const bool loadThemeNow = true) noexcept
    {
        if (loadThemeNow)
        {
            String filename(getSpecialDir(kSpecialDirConfig));
            filename += "MasterMeTheme.json";
            loadTheme(filename);
        }

        scaleAll(scaleFactor);
    }

    void loadTheme(const char* const filename)
    {
        std::ifstream f(filename);
        if (! f.good())
            return;

        nlohmann::json j;

        try {
            j = nlohmann::json::parse(f);

            #define LOAD_UINT(var) if (j.contains(#var)) var = j[#var].get<uint>();
            LOAD_UINT(borderSize)
            LOAD_UINT(padding)
            LOAD_UINT(fontSize)
            LOAD_UINT(textHeight)
            // LOAD_UINT(knobIndicatorSize)
            LOAD_UINT(widgetLineSize)
            #undef LOAD_UINT

            #define LOAD_COLOR(var) if (j.contains(#var)) var = Color::fromHTML(j[#var].get<std::string>().c_str());
            LOAD_COLOR(levelMeterColor)
            LOAD_COLOR(levelMeterAlternativeColor)
            // LOAD_COLOR(knobRingColor)
            // LOAD_COLOR(knobAlternativeRingColor)
            LOAD_COLOR(widgetBackgroundColor)
            LOAD_COLOR(widgetActiveColor)
            LOAD_COLOR(widgetAlternativeColor)
            LOAD_COLOR(widgetForegroundColor)
            LOAD_COLOR(windowBackgroundColor)
            LOAD_COLOR(textLightColor)
            LOAD_COLOR(textMidColor)
            LOAD_COLOR(textDarkColor)
            #undef LOAD_COLOR

        } catch (const std::exception& e) {
            d_stderr("failed to parse MasterMeTheme: %s", e.what());
            return;
        } catch (...) {
            d_stderr("failed to parse MasterMeTheme: unknown exception");
            return;
        }
    }

    void scaleAll(const double scaleFactor)
    {
        if (d_isNotEqual(scaleFactor, 1.0))
        {
            borderSize *= scaleFactor;
            padding *= scaleFactor;
            fontSize *= scaleFactor;
            // knobIndicatorSize *= scaleFactor;
            textHeight *= scaleFactor;
            widgetLineSize *= scaleFactor;
        }

        windowPadding = borderSize + padding * 3;
        textPixelRatioWidthCompensation = static_cast<uint>(scaleFactor - 1.0 + 0.25);
    }
};

using MasterMeThemeCallback = QuantumThemeCallback;

// --------------------------------------------------------------------------------------------------------------------

class InspectorWindow : public ImGuiTopLevelWidget
{
    std::list<SubWidget*> subwidgets;

    MasterMeTheme& theme;
    MasterMeThemeCallback* const themeChangeCallback;

    // for file export/import callbacks
    bool isSaving = true;

public:
    bool isOpen = true;
    double userScaling = 1;

    explicit InspectorWindow(TopLevelWidget* const tlw, MasterMeTheme& t, MasterMeThemeCallback* const cb)
        : ImGuiTopLevelWidget(tlw->getWindow()),
          subwidgets(tlw->getChildren()),
          theme(t),
          themeChangeCallback(cb) {}

    void uiFileBrowserSelected(const char* const filename)
    {
        if (isSaving)
        {
            String sfilename(filename);
            if (! sfilename.contains('.'))
                sfilename += ".json";

            saveTheme(sfilename);
        }
        else
        {
            loadTheme(filename);
        }
    }

protected:
    void onImGuiDisplay() override
    {
        if (!isOpen)
            return;

        double scaleFactor = getScaleFactor() * userScaling;
        const double initialSize = 1200 * scaleFactor;

        ImGui::SetNextWindowPos(ImVec2(initialSize / 4, initialSize / 16), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(initialSize / 2, initialSize / 3), ImGuiCond_Once);

        ImGui::Begin("Theme", &isOpen, ImGuiWindowFlags_NoCollapse);

        int val;
        bool changedSize = false;
        bool changedColors = false;
        bool changedScale = false;

        if (ImGui::Button("Reset"))
        {
            changedScale = true;
            userScaling = 1;
        }

        ImGui::SameLine();

        if (ImGui::Button("Save"))
        {
            String filename(getSpecialDir(kSpecialDirConfig));
            filename += "MasterMeTheme.json";
            saveTheme(filename);
        }

        ImGui::SameLine();

        if (ImGui::Button("150% Zoom"))
        {
            changedScale = true;
            userScaling = 1.5;
        }

        ImGui::SameLine();

        if (ImGui::Button("200% Zoom"))
        {
            changedScale = true;
            userScaling = 2;
        }

        ImGui::SameLine();

        if (ImGui::Button("300% Zoom"))
        {
            changedScale = true;
            userScaling = 3;
        }

        ImGui::SameLine();
        ImGui::TextUnformatted("(zoom resets colors)");

        ImGui::SameLine();

        if (ImGui::Button("Export..."))
        {
            FileBrowserOptions opts;
            opts.saving = isSaving = true;
            opts.defaultName = "MasterMeTheme.json";
            opts.title = "Export MasterMeTheme Theme";
            getWindow().openFileBrowser(opts);
        }

        ImGui::SameLine();

        if (ImGui::Button("Import..."))
        {
            FileBrowserOptions opts;
            opts.saving = isSaving = false;
            opts.title = "Import MasterMeTheme Theme";
            getWindow().openFileBrowser(opts);
        }

        val = static_cast<int>(theme.borderSize / scaleFactor + 0.5f);
        if (ImGui::SliderInt("Border Size", &val, 1, 10))
        {
            changedSize = true;
            theme.borderSize = val * scaleFactor;
        }

        val = static_cast<int>(theme.padding / scaleFactor + 0.5f);
        if (ImGui::SliderInt("Padding", &val, 0, 20))
        {
            changedSize = true;
            theme.padding = val * scaleFactor;
        }

        val = static_cast<int>(theme.fontSize / scaleFactor + 0.5f);
        if (ImGui::SliderInt("Font Size", &val, 8, 50))
        {
            changedSize = true;
            theme.fontSize = val * scaleFactor;
            if (theme.fontSize > theme.textHeight)
                theme.textHeight = theme.fontSize;
        }

        val = static_cast<int>(theme.textHeight / scaleFactor + 0.5f);
        if (ImGui::SliderInt("Text Height", &val, theme.fontSize / scaleFactor, 60))
        {
            changedSize = true;
            theme.textHeight = val * scaleFactor;
        }

        val = static_cast<int>(theme.widgetLineSize / scaleFactor + 0.5f);
        if (ImGui::SliderInt("Widget Line Size", &val, 1, 10))
        {
            changedSize = true;
            theme.widgetLineSize = val * scaleFactor;
        }

        changedColors |= ImGui::ColorEdit4("Level Meter", theme.levelMeterColor.rgba);
        changedColors |= ImGui::ColorEdit4("Level Meter Alternative", theme.levelMeterAlternativeColor.rgba);
        changedColors |= ImGui::ColorEdit4("Widget Background", theme.widgetBackgroundColor.rgba);
        changedColors |= ImGui::ColorEdit4("Widget Active", theme.widgetActiveColor.rgba);
        changedColors |= ImGui::ColorEdit4("Widget Alternative", theme.widgetAlternativeColor.rgba);
        changedColors |= ImGui::ColorEdit4("Widget Foreground", theme.widgetForegroundColor.rgba);
        changedColors |= ImGui::ColorEdit4("Window Background", theme.windowBackgroundColor.rgba);
        changedColors |= ImGui::ColorEdit4("Text Light", theme.textLightColor.rgba);
        changedColors |= ImGui::ColorEdit4("Text Mid", theme.textMidColor.rgba);
        changedColors |= ImGui::ColorEdit4("Text Dark", theme.textDarkColor.rgba);

        ImGui::Separator();
        ImGui::TextUnformatted("Widgets");
        displaySubWidget(subwidgets);

        ImGui::End();

        if (changedScale)
        {
            changedSize = true;
            changedColors = true;
            scaleFactor = getScaleFactor() * userScaling;
            theme = MasterMeTheme(scaleFactor, false);
        }

        if (changedSize || changedColors)
        {
            theme.windowPadding = theme.borderSize + theme.padding * 3;
            themeChangeCallback->quantumThemeChanged(changedSize, changedColors);
        }
    }

private:
    void loadTheme(const char* const filename)
    {
        theme.loadTheme(filename);
        theme.scaleAll(getScaleFactor());
        themeChangeCallback->quantumThemeChanged(true, true);
    }

    void saveTheme(const char* const filename)
    {
        const double scaleFactor = getScaleFactor();

        const SafeFileWriter file(filename);
        if (file.ok())
        {
            nlohmann::json j;
            j["borderSize"] = d_roundToIntPositive(theme.borderSize / scaleFactor);
            j["padding"] = d_roundToIntPositive(theme.padding / scaleFactor);
            j["fontSize"] = d_roundToIntPositive(theme.fontSize / scaleFactor);
            j["textHeight"] = d_roundToIntPositive(theme.textHeight / scaleFactor);
            // j["knobIndicatorSize"] = d_roundToIntPositive(theme.knobIndicatorSize / scaleFactor);
            j["widgetLineSize"] = d_roundToIntPositive(theme.widgetLineSize / scaleFactor);
            // j["sidelabelsFontSize"] = d_roundToIntPositive(theme.sidelabelsFontSize / scaleFactor);
            j["levelMeterColor"] = ColorToString(theme.levelMeterColor);
            j["levelMeterAlternativeColor"] = ColorToString(theme.levelMeterAlternativeColor);
            // j["inputLevelBracket1"] = ColorToString(theme.inputLevelBracket1);
            // j["inputLevelBracket2"] = ColorToString(theme.inputLevelBracket2);
            // j["knobRingColor"] = ColorToString(theme.knobRingColor);
            // j["knobAlternativeRingColor"] = ColorToString(theme.knobAlternativeRingColor);
            j["widgetBackgroundColor"] = ColorToString(theme.widgetBackgroundColor);
            j["widgetActiveColor"] = ColorToString(theme.widgetActiveColor);
            j["widgetAlternativeColor"] = ColorToString(theme.widgetAlternativeColor);
            j["widgetForegroundColor"] = ColorToString(theme.widgetForegroundColor);
            j["windowBackgroundColor"] = ColorToString(theme.windowBackgroundColor);
            j["textLightColor"] = ColorToString(theme.textLightColor);
            j["textMidColor"] = ColorToString(theme.textMidColor);
            j["textDarkColor"] = ColorToString(theme.textDarkColor);

            const std::string jsonstr = j.dump(2, ' ', false, nlohmann::detail::error_handler_t::replace);

            file.write(jsonstr.c_str(), jsonstr.length());
        }
    }

    static void displaySubWidget(const std::list<SubWidget*>& subwidgets)
    {
        for (SubWidget* w : subwidgets)
        {
            if (ImGui::TreeNode(w->getName()))
            {
                float val;

                if (ImGui::Button("Bring To Front"))
                    w->toFront();

                ImGui::SameLine();

                if (w->isVisible())
                {
                    if (ImGui::Button("Hide"))
                        w->hide();
                }
                else
                {
                    if (ImGui::Button("Show"))
                        w->show();
                }

                val = w->getAbsoluteX();
                if (ImGui::DragFloat("Absolute X", &val))
                    w->setAbsoluteX(val);

                val = w->getAbsoluteY();
                if (ImGui::DragFloat("Absolute Y", &val))
                    w->setAbsoluteY(val);

                val = w->getWidth();
                if (ImGui::DragFloat("Width", &val))
                    w->setWidth(std::max(0.f, val));

                val = w->getHeight();
                if (ImGui::DragFloat("Height", &val))
                    w->setHeight(std::max(0.f, val));

                displaySubWidget(w->getChildren());

                ImGui::TreePop();
            }
        }
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
