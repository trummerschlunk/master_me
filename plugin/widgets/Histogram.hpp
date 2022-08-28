/*
 * Histogram widget for DPF
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

#include "TopLevelWidget.hpp"
#include "implot/implot.h"
#include "src/DistrhoDefines.h"

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

class Histogram : public ImGuiSubWidget
{
    ImPlotContext* const context;

    uint bufferSize = 0;
    double sampleRate = 0.0;
    int numPointsInDataBuffer = 0;

    struct Data {
        int head = 0;
        int written = 0; // up to numPointsInDataBuffer
        float* buffer = nullptr;
    } dataLufsIn, dataLufsOut;

    static constexpr const uint numSecsInHistogram = 30;

public:
    explicit Histogram(TopLevelWidget* const parent)
        : ImGuiSubWidget(parent),
          context(ImPlot::CreateContext())
    {
        setName("Histogram");

        ImGuiStyle& style(ImGui::GetStyle());
        style.WindowPadding = ImVec2();
        style.WindowRounding = style.WindowBorderSize = 0.f;
        style.Colors[ImGuiCol_FrameBg] = ImVec4();
    }

    ~Histogram() override
    {
        ImPlot::DestroyContext(context);
        delete[] dataLufsIn.buffer;
        delete[] dataLufsOut.buffer;
    }

    void setup(const uint bufSize, const double srate)
    {
        DISTRHO_SAFE_ASSERT_RETURN(bufSize != 0,);

        delete[] dataLufsIn.buffer;
        delete[] dataLufsOut.buffer;

        bufferSize = bufSize;
        sampleRate = srate;
        numPointsInDataBuffer = (sampleRate / bufSize) * numSecsInHistogram;
        dataLufsIn.buffer = new float[numPointsInDataBuffer];
        dataLufsOut.buffer = new float[numPointsInDataBuffer];
        dataLufsIn.head = dataLufsIn.written = dataLufsOut.head = dataLufsOut.written = 0;

        std::memset(dataLufsIn.buffer, 0, sizeof(float)*numPointsInDataBuffer);
        std::memset(dataLufsOut.buffer, 0, sizeof(float)*numPointsInDataBuffer);
    }

    void setSampleRate(const double srate)
    {
        setup(bufferSize, srate);
    }

    void tick(const bool output, const float value)
    {
        if (numPointsInDataBuffer == 0)
            return;

        Data& d(output ? dataLufsOut : dataLufsIn);

        d.buffer[d.head++] = value;

        if (d.head == numPointsInDataBuffer)
            d.head = 0;

        if (d.written != numPointsInDataBuffer)
            ++d.written;
    }

protected:
    void onImGuiDisplay() override
    {
        DISTRHO_SAFE_ASSERT_UINT2(dataLufsIn.written == dataLufsOut.written, dataLufsIn.written, dataLufsOut.written);

        ImPlot::SetCurrentContext(context);

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(getWidth(), getHeight()));

        constexpr const ImGuiWindowFlags windowFlags = 0
            |ImGuiWindowFlags_NoDecoration
            |ImGuiWindowFlags_NoMove
            |ImGuiWindowFlags_NoScrollWithMouse
            |ImGuiWindowFlags_AlwaysAutoResize
            |ImGuiWindowFlags_NoBackground;

        ImGui::Begin("Histogram", nullptr, windowFlags);

        constexpr const ImPlotFlags plotFlags = 0
            |ImPlotFlags_NoTitle
            |ImPlotFlags_NoMouseText
            |ImPlotFlags_NoMenus
            |ImPlotFlags_NoBoxSelect
            |ImPlotFlags_NoFrame
            |ImPlotFlags_Crosshairs;

        if (ImPlot::BeginPlot("##histogram", ImVec2(getWidth(), getHeight()), plotFlags))
        {
            constexpr const ImPlotAxisFlags axisFlags = 0
                |ImPlotAxisFlags_NoMenus
                |ImPlotAxisFlags_NoSideSwitch
                |ImPlotAxisFlags_NoHighlight
                |ImPlotAxisFlags_Lock;
            constexpr const ImPlotLegendFlags legendFlags = 0
                |ImPlotLegendFlags_NoMenus
                |ImPlotLegendFlags_Horizontal;
            ImPlot::SetupAxis(ImAxis_X1, "Time (s)", axisFlags | ImPlotAxisFlags_NoLabel);
            ImPlot::SetupAxis(ImAxis_Y1, "dB", axisFlags | ImPlotAxisFlags_Opposite);
            ImPlot::SetupAxisLimits(ImAxis_X1, 0, numSecsInHistogram, ImGuiCond_Always);
            ImPlot::SetupAxisLimits(ImAxis_Y1, -70, 0, ImGuiCond_Always);
            ImPlot::SetupLegend(ImPlotLocation_NorthWest, legendFlags);
            ImPlot::SetupFinish();

            // ImPlot::PlotShadedG("lufs in+out", imPlotIn, this, imPlotOut, this, 0); // std::min(dataLufsIn.written, dataLufsOut.written));
            ImPlot::PlotLineG("lufs in", imPlotIn, this, dataLufsIn.written);
            ImPlot::PlotLineG("lufs out", imPlotOut, this, dataLufsOut.written);

            ImPlot::EndPlot();
        }

        ImGui::End();
    }

private:
    static ImPlotPoint imPlotIn(const int idx, void* const arg)
    {
        Histogram* const self = static_cast<Histogram*>(arg);
        Data& d(self->dataLufsIn);

        const uint bufPos = d.written != self->numPointsInDataBuffer ? idx : (idx + d.head) % self->numPointsInDataBuffer;
        const double time = static_cast<double>(idx) / self->numPointsInDataBuffer * numSecsInHistogram;
        return { time, d.buffer[bufPos] };
    }

    static ImPlotPoint imPlotOut(const int idx, void* const arg)
    {
        Histogram* const self = static_cast<Histogram*>(arg);
        Data& d(self->dataLufsOut);

        const uint bufPos = d.written != self->numPointsInDataBuffer ? idx : (idx + d.head) % self->numPointsInDataBuffer;
        const double time = static_cast<double>(idx) / self->numPointsInDataBuffer * numSecsInHistogram;
        return { time, d.buffer[bufPos] };
    }
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL
