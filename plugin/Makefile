#!/usr/bin/make -f

NAME = soundsgood
FILES_DSP = SoundsgoodPlugin.cpp
FILES_UI = SoundsgoodUI.cpp
FILES_UI += ../dpf-widgets/opengl/DearImGui.cpp
FILES_UI += ../dpf-widgets/opengl/Quantum.cpp

DPF_TARGET_DIR = ../bin
DPF_BUILD_DIR = ../build
DPF_PATH = ../dpf

# force pixel-perfect font positioning
export NVG_FONT_TEXTURE_FLAGS = NVG_IMAGE_NEAREST

include $(DPF_PATH)/Makefile.plugins.mk

BUILD_CXX_FLAGS += -I../build
BUILD_CXX_FLAGS += -I../build/soundsgood
BUILD_CXX_FLAGS += -I../dpf-widgets/opengl

PLUGIN_TARGETS  = jack ladspa lv2_sep vst2 vst3

all: $(PLUGIN_TARGETS)
