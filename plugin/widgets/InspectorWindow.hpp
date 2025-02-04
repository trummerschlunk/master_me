/*
 * Inspector Window for DPF
 * Copyright (C) 2022 Filipe Coelho <falktx@falktx.com>
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
#include "Quantum.hpp"

#include "Application.hpp"
#include "extra/String.hpp"

#include <list>

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

class InspectorWindow : public ImGuiTopLevelWidget
{
    std::list<SubWidget*> subwidgets;

    QuantumTheme& theme;
    QuantumThemeCallback* const themeChangeCallback;

public:
    bool isOpen = true;
    double userScaling = 1;

    explicit InspectorWindow(TopLevelWidget* const tlw, QuantumTheme& t, QuantumThemeCallback* const cb)
        : ImGuiTopLevelWidget(tlw->getWindow()),
          subwidgets(tlw->getChildren()),
          theme(t),
          themeChangeCallback(cb)
    {
        ResizeEvent ev;
        ev.size = tlw->getSize();
        onResize(ev);
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

        if (ImGui::SmallButton("150% Zoom"))
        {
            changedScale = true;
            userScaling = 1.5;
        }

        ImGui::SameLine();

        if (ImGui::SmallButton("200% Zoom"))
        {
            changedScale = true;
            userScaling = 2;
        }

        ImGui::SameLine();

        if (ImGui::SmallButton("300% Zoom"))
        {
            changedScale = true;
            userScaling = 3;
        }

        ImGui::SameLine();
        ImGui::TextUnformatted("(zoom changes reset colors)");

        if (changedScale)
        {
            changedSize = true;
            changedColors = true;
            scaleFactor = getScaleFactor() * userScaling;
            theme = QuantumTheme();
            theme.borderSize *= scaleFactor;
            theme.padding *= scaleFactor;
            theme.fontSize *= scaleFactor;
            theme.textHeight *= scaleFactor;
            theme.widgetLineSize *= scaleFactor;
            theme.windowPadding *= scaleFactor;
            theme.textPixelRatioWidthCompensation = static_cast<uint>(scaleFactor - 1.0 + 0.25);
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

        if (changedSize || changedColors)
        {
            theme.windowPadding = theme.borderSize + theme.padding * 3;
            themeChangeCallback->quantumThemeChanged(changedSize, changedColors);
        }
    }

private:
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
