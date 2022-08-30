#!/usr/bin/make -f

NAME = master_me
FILES_DSP = SoundsgoodPlugin.cpp
FILES_UI = SoundsgoodUI.cpp
FILES_UI += widgets/implot/implot.cpp
FILES_UI += widgets/implot/implot_items.cpp
FILES_UI += ../build/Logo.cpp
FILES_UI += ../dpf-widgets/opengl/DearImGui.cpp
FILES_UI += ../dpf-widgets/opengl/Quantum.cpp

DPF_TARGET_DIR = ../bin
DPF_BUILD_DIR = ../build
DPF_PATH = ../dpf

# tweak DPF build
export DGL_NAMESPACE = MasterMeDGL
export FILE_BROWSER_DISABLED = true
export NVG_FONT_TEXTURE_FLAGS = NVG_IMAGE_NEAREST

include $(DPF_PATH)/Makefile.plugins.mk

BUILD_CXX_FLAGS += -I../build
BUILD_CXX_FLAGS += -I../build/master_me
BUILD_CXX_FLAGS += -I../dpf-widgets/opengl
BUILD_CXX_FLAGS += -funroll-loops
# ifeq ($(GCC),true)
# BUILD_CXX_FLAGS += -fprefetch-loop-arrays -fsingle-precision-constant
# endif
LINK_FLAGS      += $(SHARED_MEMORY_LIBS)

PLUGIN_TARGETS = jack lv2_sep vst2 vst3

all: $(PLUGIN_TARGETS)
