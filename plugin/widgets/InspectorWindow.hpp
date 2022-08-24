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
#include "Application.hpp"
#include "DearImGui/imgui.h"
#include "extra/String.hpp"

#include <list>

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

class InspectorWindow : public ImGuiTopLevelWidget
{
    std::list<SubWidget*> subwidgets;

public:
    bool isOpen = true;

    explicit InspectorWindow(TopLevelWidget* const tlw)
        : ImGuiTopLevelWidget(tlw->getWindow()),
          subwidgets(tlw->getChildren())
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

        const double initialSize = 600 * getScaleFactor();

        ImGui::SetNextWindowPos(ImVec2(initialSize / 4, initialSize / 4), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(initialSize, initialSize / 2), ImGuiCond_Once);

        ImGui::Begin("Widgets", &isOpen);

        displaySubWidget(subwidgets);

        ImGui::End();
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
