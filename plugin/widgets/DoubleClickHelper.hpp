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
#include "Quantum.hpp"

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

constexpr inline ImVec4 ImVec4Color(const Color& c)
{
    return ImVec4(c.red, c.green, c.blue, c.alpha);
}

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

    explicit DoubleClickHelper(TopLevelWidget* const tlw,
                               Callback* const cb,
                               SubWidget* const w,
                               const char* const text,
                               const Rectangle<int>& area,
                               const QuantumTheme& theme)
        : ImGuiTopLevelWidget(tlw->getWindow(), theme.fontSize),
          callback(cb),
          widget(w)
    {
        pos = ImVec2(area.getX(), area.getY());
        size = ImVec2(area.getWidth(), area.getHeight());

        std::strncpy(textBuf, text, sizeof(textBuf)-1);

        ImGuiStyle& style(ImGui::GetStyle());
        style.WindowPadding = ImVec2();
        style.WindowRounding = style.WindowBorderSize = 0.f;
        style.ChildRounding = style.ChildBorderSize = 0.f;
        style.PopupRounding = style.PopupBorderSize = 0.f;
        style.FrameRounding = style.FrameBorderSize = 0.f;
        style.Colors[ImGuiCol_FrameBg] = ImVec4();
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4();
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4();
        style.Colors[ImGuiCol_NavHighlight] = ImVec4();
        style.Colors[ImGuiCol_Text] = ImVec4Color(theme.textLightColor);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4Color(theme.textMidColor);
        style.Colors[ImGuiCol_TextSelectedBg] = ImVec4Color(theme.widgetActiveColor);
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
        ImGui::SetNextWindowContentSize(size);
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
            |ImGuiInputTextFlags_AutoSelectAll
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
