#!/usr/bin/make -f

# define project version
VERSION_MAJOR = 0
VERSION_MINOR = 0
VERSION_MICRO = 1

# include dpf base makefile definitions
include dpf/Makefile.base.mk

# default build target
all: master_me

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
# dgl target, building the dpf little graphics library

dgl:
	$(MAKE) -C dpf/dgl opengl NVG_FONT_TEXTURE_FLAGS=NVG_IMAGE_NEAREST

# ---------------------------------------------------------------------------------------------------------------------
# list of plugin source code files to generate, converted from faust dsp files

PLUGIN_TEMPLATE_FILES   = $(subst template/,,$(wildcard template/*.*))
PLUGIN_GENERATED_FILES  = $(foreach f,$(PLUGIN_TEMPLATE_FILES),build/master_me/$(f))
PLUGIN_GENERATED_FILES += bin/master_me.lv2/manifest.ttl
PLUGIN_GENERATED_FILES += bin/master_me.lv2/plugin.ttl
PLUGIN_GENERATED_FILES += bin/master_me.lv2/ui.ttl
PLUGIN_GENERATED_FILES += build/BuildInfo.hpp
PLUGIN_GENERATED_FILES += build/Logo.hpp

gen: $(PLUGIN_GENERATED_FILES)

# ---------------------------------------------------------------------------------------------------------------------
# master_me target, for actual building the plugin after its source code has been generated

master_me: $(PLUGIN_GENERATED_FILES) dgl
	$(MAKE) -C plugin

# ---------------------------------------------------------------------------------------------------------------------
# rules for faust dsp to plugin code conversion

FAUSTPP_ARGS = \
	-Dbinary_name="master_me" \
	-Dbrand="4ohm" \
	-Dhomepage="https://4ohm.de/" \
	-Dlabel="master_me" \
	-Dlicense="GPLv3+" \
	-Dlicenseurl="http://spdx.org/licenses/GPL-3.0-or-later.html" \
	-Dlibext="$(LIB_EXT)" \
	-Dlv2uri="https://github.com/trummerschlunk/master_me" \
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

bin/master_me.lv2/%: soundsgood.dsp template/LV2/% faustpp
	mkdir -p bin/master_me.lv2
	$(FAUSTPP_EXEC) $(FAUSTPP_ARGS) -a template/LV2/$* $< -o $@

build/master_me/%: soundsgood.dsp template/% faustpp
	mkdir -p build/master_me
	$(FAUSTPP_EXEC) $(FAUSTPP_ARGS) -a template/$* $< -o $@

# regenerated on every possible change
build/BuildInfo.hpp: soundsgood.dsp plugin/* template/* template/LV2/*
	mkdir -p build
	echo 'constexpr const char* const kBuildInfoString = ""' > $@
	echo '"\t4ohm.de | master_me\t\\n"' >> $@
	echo '"A plugin by Klaus Scheuermann.\\n"' >> $@
	echo '"With contributions from falkTX, magnetophon, x42 and others.\\n\\n"' >> $@
	echo '"Using `$(shell git branch --show-current)` branch, with commit:\\n"' >> $@
	echo '"$(shell git log -n 1 --decorate=no --pretty=oneline --abbrev-commit)\\n"' >> $@
	echo ';' >> $@

build/Logo.hpp: img/logo/master_me_white@2x.png
	mkdir -p build
	./dpf/utils/res2c.py Logo img/logo/ build/

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
