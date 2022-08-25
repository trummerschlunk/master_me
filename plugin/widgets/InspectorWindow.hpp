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
#include "DearImGui/imgui.h"
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

        const double initialSize = 1200 * getScaleFactor();

        ImGui::SetNextWindowPos(ImVec2(initialSize / 4, initialSize / 16), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(initialSize / 2, initialSize / 3), ImGuiCond_Once);

        ImGui::Begin("Theme", &isOpen, ImGuiWindowFlags_NoCollapse);

        int val;
        bool changed = false;

        if (ImGui::Button("Reset"))
        {
            changed = true;
            theme = QuantumTheme();
        }

        val = theme.borderSize;
        if (ImGui::SliderInt("Border Size", &val, 1, 20))
        {
            changed = true;
            theme.borderSize = val;
        }

        val = theme.padding;
        if (ImGui::SliderInt("Padding", &val, 0, 20))
        {
            changed = true;
            theme.padding = val;
        }

        val = theme.fontSize;
        if (ImGui::SliderInt("Font Size", &val, 8, 50))
        {
            changed = true;
            theme.fontSize = val;
        }

        val = theme.textHeight;
        if (ImGui::SliderInt("Text Height", &val, theme.fontSize, 60))
        {
            changed = true;
            theme.textHeight = val;
        }

        val = theme.widgetLineSize;
        if (ImGui::SliderInt("Widget Line Size", &val, 1, 10))
        {
            changed = true;
            theme.widgetLineSize = val;
        }

        ImGui::ColorEdit4("Level Meter", theme.levelMeterColor.rgba);
        ImGui::ColorEdit4("Level Meter Alternative", theme.levelMeterAlternativeColor.rgba);
        ImGui::ColorEdit4("Widget Background", theme.widgetBackgroundColor.rgba);
        ImGui::ColorEdit4("Widget Default Active", theme.widgetDefaultActiveColor.rgba);
        ImGui::ColorEdit4("Widget Default Alternative", theme.widgetDefaultAlternativeColor.rgba);
        ImGui::ColorEdit4("Widget Foreground", theme.widgetForegroundColor.rgba);
        ImGui::ColorEdit4("Window Background", theme.windowBackgroundColor.rgba);
        ImGui::ColorEdit4("Text Light", theme.textLightColor.rgba);
        ImGui::ColorEdit4("Text Mid", theme.textMidColor.rgba);
        ImGui::ColorEdit4("Text Dark", theme.textDarkColor.rgba);

        ImGui::End();

        if (changed)
        {
            theme.windowPadding = theme.borderSize + theme.padding * 3;
            themeChangeCallback->quantumThemeChanged();
        }

        /*
        ImGui::Begin("Widgets", &isOpen);
        displaySubWidget(subwidgets);
        ImGui::End();
        */
    }

    /*
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
    */
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
