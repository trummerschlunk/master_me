#!/usr/bin/make -f

# include dpf base makefile definitions
include dpf/Makefile.base.mk

# include version details
include VERSION.mk
VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_MICRO)

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
# bench target, for testing

BENCH_CMD = ./bench/faustbench -notrace -best $(CURDIR)/master_me.dsp

BENCH_FLAGS  = $(BUILD_CXX_FLAGS)
BENCH_FLAGS += -Wno-overloaded-virtual -Wno-unused-function -Wno-unused-parameter
BENCH_FLAGS += -I$(shell faust --includedir) -Ibench -Ibench/master_me -DBEST_TESTS
BENCH_FLAGS += -flto
BENCH_FLAGS += $(LINK_FLAGS)

BENCH_TARGETS = all normal prefetch tree-vec unroll prefetch+tree prefetch+unroll tree+unroll

bench: $(BENCH_TARGETS:%=bench/master_me/bench.%$(APP_EXT))

bench/master_me/bench.all$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) -fomit-frame-pointer -fprefetch-loop-arrays -ftree-vectorize -funroll-loops $< -o $@

bench/master_me/bench.normal$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) $< -o $@

bench/master_me/bench.prefetch$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) -fprefetch-loop-arrays $< -o $@

bench/master_me/bench.tree-vec$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) -ftree-vectorize $< -o $@

bench/master_me/bench.unroll$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) -funroll-loops $< -o $@

bench/master_me/bench.prefetch+trees$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) -fprefetch-loop-arrays -ftree-vectorize $< -o $@

bench/master_me/bench.prefetch+unroll$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) -fprefetch-loop-arrays -funroll-loops $< -o $@

bench/master_me/bench.tree+unrolls$(APP_EXT): bench/master_me/faustbench.cpp
	$(CXX) $(BENCH_FLAGS) -ftree-vectorize -funroll-loops $< -o $@

bench/master_me/faustbench.cpp:
	$(BENCH_CMD) -source

.PHONY: bench

# ---------------------------------------------------------------------------------------------------------------------
# dgl target, building the dpf little graphics library

DPF_EXTRA_ARGS  = DGL_NAMESPACE=MasterMeDGL
DPF_EXTRA_ARGS += FILE_BROWSER_DISABLED=true
DPF_EXTRA_ARGS += NVG_FONT_TEXTURE_FLAGS=NVG_IMAGE_NEAREST
DPF_EXTRA_ARGS += SKIP_NATIVE_AUDIO_FALLBACK=true

dgl:
	$(MAKE) -C dpf/dgl opengl $(DPF_EXTRA_ARGS)

# ---------------------------------------------------------------------------------------------------------------------
# list of plugin source code files to generate, converted from faust dsp files

PLUGIN_TEMPLATE_FILES   = $(subst template/,,$(wildcard template/*.*))
PLUGIN_GENERATED_FILES  = $(foreach f,$(PLUGIN_TEMPLATE_FILES),pregen/$(f))
PLUGIN_GENERATED_FILES += bin/master_me.lv2/manifest.ttl
PLUGIN_GENERATED_FILES += bin/master_me.lv2/plugin.ttl
PLUGIN_GENERATED_FILES += bin/master_me.lv2/ui.ttl
PLUGIN_GENERATED_FILES += bin/master_me-easy-presets.lv2/manifest.ttl
PLUGIN_GENERATED_FILES += bin/master_me-easy-presets.lv2/presets.ttl
PLUGIN_GENERATED_FILES += build/BuildInfo1.hpp
PLUGIN_GENERATED_FILES += build/BuildInfo2.hpp
PLUGIN_GENERATED_FILES += build/Logo.hpp

gen: $(PLUGIN_GENERATED_FILES)

# ---------------------------------------------------------------------------------------------------------------------
# master_me target, for actual building the plugin after its source code has been generated

master_me: $(PLUGIN_GENERATED_FILES) dgl
	$(MAKE) -C plugin

# ---------------------------------------------------------------------------------------------------------------------
# install target, does what you think it does

PREFIX  ?= /usr/local
DESTDIR ?=

install: master_me
	install -d $(DESTDIR)$(PREFIX)/bin
	install -d $(DESTDIR)$(PREFIX)/lib/lv2/master_me.lv2
	install -d $(DESTDIR)$(PREFIX)/lib/lv2/master_me-easy-presets.lv2
	install -d $(DESTDIR)$(PREFIX)/lib/vst
	install -d $(DESTDIR)$(PREFIX)/lib/vst3/master_me.vst3/Contents

	install -m 755 bin/master_me                    $(DESTDIR)$(PREFIX)/bin/
	install -m 644 bin/master_me.lv2/*              $(DESTDIR)$(PREFIX)/lib/lv2/master_me.lv2/
	install -m 644 bin/master_me-easy-presets.lv2/* $(DESTDIR)$(PREFIX)/lib/lv2/master_me-easy-presets.lv2/
	install -m 644 bin/master_me-vst.*              $(DESTDIR)$(PREFIX)/lib/vst/
	cp -rL bin/master_me.vst3/Contents/*-*          $(DESTDIR)$(PREFIX)/lib/vst3/master_me.vst3/Contents/

# ---------------------------------------------------------------------------------------------------------------------
# rules for faust dsp to plugin code conversion

FAUSTPP_ARGS = \
	-Dbinary_name="master_me" \
	-Dbrand="Klaus Scheuermann" \
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

# FAUSTPP_OPTS = -X-scal
FAUSTPP_OPTS = -X-vec -X-lv -X1 -X-vs -X8
# -X-fm -Xfastmath.cpp

bin/master_me.lv2/%: master_me.dsp template/LV2/% faustpp
	mkdir -p bin/master_me.lv2
	$(FAUSTPP_EXEC) $(FAUSTPP_ARGS) -a template/LV2/$* $< -o $@

bin/master_me-easy-presets.lv2/%: plugin/master_me-easy-presets.lv2/%
	mkdir -p bin/master_me-easy-presets.lv2
	cp $< $@

# FIXME have files in repo with proper dependency tracking
# pregen/%: master_me.dsp template/% faustpp
# 	mkdir -p build/master_me
# 	$(FAUSTPP_EXEC) $(FAUSTPP_ARGS) $(FAUSTPP_OPTS) -a template/$* $< -o $@

# only generated once
build/BuildInfo1.hpp:
	mkdir -p build
	echo 'constexpr const char kBuildInfoString1[] = ""' > $@
	echo '"A plugin by Klaus Scheuermann, made with Faust and DPF\\n"' >> $@
	echo '"DSP: Klaus Scheuermann, magnetophon, x42, jkbd\\n"' >> $@
	echo '"GUI, Plugin: falkTX\\n"' >> $@
	echo '"Supported by the Prototype Fund / German Federal Ministry of Education and Research"' >> $@
	echo ';' >> $@

# regenerated on every possible change
build/BuildInfo2.hpp: master_me.dsp plugin/* template/* template/LV2/* VERSION.mk
	mkdir -p build
	echo 'constexpr const char kBuildInfoString2[] = ""' > $@
ifneq ($(wildcard .git/HEAD),)
	echo '"Built using `$(shell git branch --show-current | tr -d "'")` branch with commit:\\n$(shell git log -n 1 --decorate=no --pretty=oneline --abbrev-commit | tr -d "'")"' >> $@
else
	echo '"v$(VERSION)"' >> $@
endif
	echo ';' >> $@

build/Logo.hpp: img/logo/master_me_white.png img/logo/master_me_white@2x.png
	mkdir -p build
	./dpf/utils/res2c.py Logo img/logo/ build/

# ---------------------------------------------------------------------------------------------------------------------
# tarball target, generating release source-code tarballs ready for packaging

TAR_ARGS = \
	--exclude=".appveyor*" \
	--exclude=".ci*" \
	--exclude=".clang*" \
	--exclude=".drone*" \
	--exclude=".editor*" \
	--exclude=".git*" \
	--exclude="*.kdev*" \
	--exclude=".travis*" \
	--exclude=".vscode*" \
	--exclude="*.d" \
	--exclude="*.o" \
	--exclude=bin \
	--exclude=build \
	--exclude=dpf/build \
	--exclude=dpf/cmake \
	--exclude=dpf/examples \
	--exclude=dpf/lac \
	--exclude=dpf/tests \
	--exclude=dpf-widgets/generic \
	--exclude=dpf-widgets/opengl/Blendish* \
	--exclude=dpf-widgets/opengl/DearImGuiColorTextEditor* \
	--exclude=dpf-widgets/tests \
	--transform='s,^\.\.,-.-.,' \
	--transform='s,^\.,master_me-$(VERSION),' \
	--transform='s,^-\.-\.,..,' \

tarball:
	rm -f ../master_me-$(VERSION).tar.xz
	tar -c --lzma $(TAR_ARGS) -f ../master_me-$(VERSION).tar.xz .

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
