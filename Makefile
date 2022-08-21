#!/usr/bin/make -f

# define project version
VERSION_MAJOR = 0
VERSION_MINOR = 0
VERSION_MICRO = 1

# include dpf base makefile definitions
include dpf/Makefile.base.mk

# default build target
all: soundsgood

# ---------------------------------------------------------------------------------------------------------------------
# clean target, removes any build artifacts

clean:
	rm -rf bin build
	rm -rf dpf/build
	rm -f dpf-widgets/opengl/*.d
	rm -f dpf-widgets/opengl/*.o

# ---------------------------------------------------------------------------------------------------------------------
# faustpp target, building it ourselves if not available from the system

ifeq ($(shell command -v faustpp 1>/dev/null && echo true),true)
FAUSTPP_TARGET =
FAUSTPP_EXEC = faustpp
else
FAUSTPP_TARGET = build/faustpp/faustpp$(APP_EXT)
FAUSTPP_EXEC = $(CURDIR)/$(FAUSTPP_TARGET)
endif

# never rebuild faustpp
ifeq ($(wildcard build/faustpp/faustpp$(APP_EXT)),)
faustpp: $(FAUSTPP_TARGET)
.PHONY: faustpp
else
faustpp:
endif

# ---------------------------------------------------------------------------------------------------------------------
# list of plugin source code files to generate, converted from faust dsp files

PLUGIN_TEMPLATE_FILES   = $(subst template/,,$(wildcard template/*.*))
PLUGIN_GENERATED_FILES  = $(foreach f,$(PLUGIN_TEMPLATE_FILES),build/soundsgood/$(f))
PLUGIN_GENERATED_FILES += bin/soundsgood.lv2/manifest.ttl
PLUGIN_GENERATED_FILES += bin/soundsgood.lv2/plugin.ttl
PLUGIN_GENERATED_FILES += bin/soundsgood.lv2/ui.ttl

gen: $(PLUGIN_GENERATED_FILES)

# ---------------------------------------------------------------------------------------------------------------------
# soundsgood target, for actual building the plugin after its source code has been generated

soundsgood: $(PLUGIN_GENERATED_FILES)
	$(MAKE) -C plugin

# ---------------------------------------------------------------------------------------------------------------------
# rules for faust dsp to plugin code conversion

FAUSTPP_ARGS = \
	-Dbinary_name="soundsgood" \
	-Dbrand="4ohm" \
	-Dhomepage="https://4ohm.de/" \
	-Dlabel="soundsgood" \
	-Dlicense="GPLv3+" \
	-Dlicenseurl="http://spdx.org/licenses/GPL-3.0-or-later.html" \
	-Dlibext="$(LIB_EXT)" \
	-Dlv2uri="https://github.com/trummerschlunk/soundsgood" \
	-Dversion_major=$(VERSION_MAJOR) \
	-Dversion_minor=$(VERSION_MINOR) \
	-Dversion_micro=$(VERSION_MICRO)

ifeq ($(MACOS),true)
FAUSTPP_ARGS += -Duitype=Cocoa
else ifeq ($(WINDOWS),true)
FAUSTPP_ARGS += -Duitype=HWND
else ifeq ($(HAVE_DGL),true)
FAUSTPP_ARGS += -Duitype=X11
endif

bin/soundsgood.lv2/%: soundsgood.dsp template/LV2/% faustpp
	mkdir -p bin/soundsgood.lv2
	$(FAUSTPP_EXEC) $(FAUSTPP_ARGS) -a template/LV2/$* $< -o $@

build/soundsgood/%: soundsgood.dsp template/% faustpp
	mkdir -p build/soundsgood
	$(FAUSTPP_EXEC) $(FAUSTPP_ARGS) -a template/$* $< -o $@

# ---------------------------------------------------------------------------------------------------------------------
# rules for custom faustpp build

CMAKE_ARGS  = -G 'Unix Makefiles'
ifeq ($(DEBUG),true)
CMAKE_ARGS += -DCMAKE_BUILD_TYPE=Debug
else
CMAKE_ARGS += -DCMAKE_BUILD_TYPE=Release
endif
ifeq ($(WINDOWS),true)
CMAKE_ARGS += -DCMAKE_SYSTEM_NAME=Windows
endif

faustpp/CMakeLists.txt:
	git clone --recursive https://github.com/falkTX/faustpp.git --depth=1 -b use-internal=boost

build/faustpp/Makefile: faustpp/CMakeLists.txt
	cmake -Bbuild/faustpp -Sfaustpp -DFAUSTPP_USE_INTERNAL_BOOST=ON $(CMAKE_ARGS)

build/faustpp/faustpp$(APP_EXT): build/faustpp/Makefile
	$(MAKE) -C build/faustpp

# ---------------------------------------------------------------------------------------------------------------------
