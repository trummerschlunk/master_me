/*
 * Double Click helper widget for DPF
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

#include "extra/String.hpp"

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

class DoubleClickHelper : public ImGuiTopLevelWidget
{
    bool closeOnNextIdle = false;
    bool firstOpen = true;
    char textBuf[64] = {};
    ImVec2 pos, size;

public:
    struct Callback {
        virtual ~Callback() {}
        virtual void doubleClickHelperDone(SubWidget* widget, const char* text) = 0;
    };
    Callback* const callback;
    SubWidget* const widget;

    explicit DoubleClickHelper(TopLevelWidget* const tlw, Callback* const cb, SubWidget* const w, const Rectangle<int>& area)
        : ImGuiTopLevelWidget(tlw->getWindow()),
          callback(cb),
          widget(w)
    {
        ResizeEvent ev;
        ev.size = tlw->getSize();
        onResize(ev);

        pos = ImVec2(area.getX(), area.getY());
        size = ImVec2(area.getWidth(), area.getHeight());

        ImGuiStyle& style(ImGui::GetStyle());
        style.WindowPadding = ImVec2();
        style.WindowRounding = style.WindowBorderSize = 0.f;
        style.Colors[ImGuiCol_FrameBg] = ImVec4();
    }
    
    void setText(const char* const text)
    {
        std::strncpy(textBuf, text, sizeof(textBuf)-1);
    }

protected:
    void idleCallback() override
    {
        ImGuiTopLevelWidget::idleCallback();
        
        if (closeOnNextIdle)
        {
            closeOnNextIdle = false;
            callback->doubleClickHelperDone(widget, textBuf);
            return;
        }
    }

    void onImGuiDisplay() override
    {
        ImGui::SetNextWindowPos(pos);
        ImGui::SetNextWindowSize(size);
        ImGui::SetNextWindowFocus();

        constexpr const ImGuiWindowFlags windowFlags = 0
            |ImGuiWindowFlags_NoDecoration
            |ImGuiWindowFlags_NoMove
            |ImGuiWindowFlags_NoScrollWithMouse
            |ImGuiWindowFlags_AlwaysAutoResize;
        
        constexpr const ImGuiInputTextFlags textFlags = 0
            |ImGuiInputTextFlags_CharsDecimal
            |ImGuiInputTextFlags_CharsScientific
            |ImGuiInputTextFlags_CharsNoBlank
            |ImGuiInputTextFlags_EnterReturnsTrue;
        
        const bool wasFirstOpen = firstOpen;

        ImGui::Begin("Double Click Helper", nullptr, windowFlags);

        if (wasFirstOpen)
        {
            firstOpen = false;
            ImGui::SetKeyboardFocusHere();
        }

        closeOnNextIdle |= ImGui::InputText("Value", textBuf, sizeof(textBuf), textFlags);

        if (!wasFirstOpen && !ImGui::IsItemActive())
            closeOnNextIdle = true;

        ImGui::End();
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
