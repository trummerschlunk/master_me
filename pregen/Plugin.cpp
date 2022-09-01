
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: master_me.dsp
// Name: master_me
// Description: 
// Author: Klaus Scheuermann
// Copyright: 
// License: GPLv3+
// Version: 1.0
//------------------------------------------------------------------------------


#include "DistrhoPlugin.hpp"
#include "extra/ScopedPointer.hpp"

// --------------------------------------------------------------------------------------------------------------------

// inline code when possible
#define FAUSTPP_VIRTUAL inline

// make everything available directly
#define FAUSTPP_PRIVATE public
#define FAUSTPP_PROTECTED public

// match distrho namespace
#define FAUSTPP_BEGIN_NAMESPACE START_NAMESPACE_DISTRHO
#define FAUSTPP_END_NAMESPACE END_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

START_NAMESPACE_DISTRHO

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class dsp {
public:
    virtual ~dsp() {}
};

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void openTabBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

END_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float mydsp_faustpower6_f(float value) {
	return value * value * value * value * value * value;
}
static float mydsp_faustpower7_f(float value) {
	return value * value * value * value * value * value * value;
}
static float mydsp_faustpower5_f(float value) {
	return value * value * value * value * value;
}
static float mydsp_faustpower4_f(float value) {
	return value * value * value * value;
}
static float mydsp_faustpower3_f(float value) {
	return value * value * value;
}

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fCheckbox0;
	float fConst2;
	float fRec0_perm[4];
	FAUSTFLOAT fCheckbox1;
	float fRec7_perm[4];
	FAUSTFLOAT fCheckbox2;
	float fRec8_perm[4];
	FAUSTFLOAT fCheckbox3;
	float fRec12_perm[4];
	FAUSTFLOAT fCheckbox4;
	float fRec13_perm[4];
	FAUSTFLOAT fCheckbox5;
	float fRec14_perm[4];
	FAUSTFLOAT fCheckbox6;
	float fRec15_perm[4];
	FAUSTFLOAT fVslider0;
	float fRec16_perm[4];
	float fConst3;
	float fRec17_perm[4];
	FAUSTFLOAT fCheckbox7;
	float fRec18_perm[4];
	float fConst5;
	FAUSTFLOAT fVbargraph0;
	float fYec0_perm[4];
	float fConst6;
	float fRec19_perm[4];
	float fRec21_perm[4];
	float fConst8;
	float fConst9;
	float fConst10;
	float fYec1_perm[4];
	float fConst11;
	float fConst13;
	float fConst14;
	float fRec25_perm[4];
	float fRec24_perm[4];
	float fConst18;
	float fConst19;
	float fConst20;
	float fYec2_perm[4];
	float fConst21;
	float fRec23_perm[4];
	float fRec22_perm[4];
	FAUSTFLOAT fVbargraph1;
	float fYec3_perm[4];
	float fYec4_perm[4];
	float fRec29_perm[4];
	float fRec28_perm[4];
	float fYec5_perm[4];
	float fRec27_perm[4];
	float fRec26_perm[4];
	float fConst23;
	int iConst24;
	float fYec6_perm[4];
	float fYec7_perm[4];
	float fYec8_perm[8];
	float fYec9_perm[16];
	float fYec10[64];
	int fYec10_idx;
	int fYec10_idx_save;
	float fYec11[128];
	int fYec11_idx;
	int fYec11_idx_save;
	float fYec12[256];
	int fYec12_idx;
	int fYec12_idx_save;
	float fYec13[512];
	int fYec13_idx;
	int fYec13_idx_save;
	float fYec14[1024];
	int fYec14_idx;
	int fYec14_idx_save;
	float fYec15[2048];
	int fYec15_idx;
	int fYec15_idx_save;
	float fYec16[4096];
	int fYec16_idx;
	int fYec16_idx_save;
	float fYec17[8192];
	int fYec17_idx;
	int fYec17_idx_save;
	float fYec18[16384];
	int fYec18_idx;
	int fYec18_idx_save;
	float fYec19[32768];
	int fYec19_idx;
	int fYec19_idx_save;
	float fYec20[65536];
	int fYec20_idx;
	int fYec20_idx_save;
	float fYec21[131072];
	int fYec21_idx;
	int fYec21_idx_save;
	float fYec22[262144];
	int fYec22_idx;
	int fYec22_idx_save;
	float fYec23[524288];
	int fYec23_idx;
	int fYec23_idx_save;
	float fYec24[1048576];
	int fYec24_idx;
	int fYec24_idx_save;
	float fYec25[2097152];
	int fYec25_idx;
	int fYec25_idx_save;
	int iConst61;
	int iConst62;
	int iConst63;
	int iConst64;
	int iConst65;
	int iConst66;
	int iConst67;
	int iConst68;
	int iConst69;
	int iConst70;
	int iConst71;
	int iConst72;
	int iConst73;
	int iConst74;
	int iConst75;
	int iConst76;
	int iConst77;
	int iConst78;
	int iConst79;
	int iConst80;
	int iConst81;
	int iConst82;
	int iConst83;
	int iConst84;
	int iConst85;
	int iConst86;
	int iConst87;
	int iConst88;
	int iConst89;
	int iConst90;
	int iConst91;
	int iConst92;
	int iConst93;
	int iConst94;
	int iConst95;
	int iConst96;
	int iConst97;
	float fYec26_perm[4];
	float fYec27_perm[4];
	float fYec28_perm[8];
	float fYec29_perm[16];
	float fYec30[64];
	int fYec30_idx;
	int fYec30_idx_save;
	float fYec31[128];
	int fYec31_idx;
	int fYec31_idx_save;
	float fYec32[256];
	int fYec32_idx;
	int fYec32_idx_save;
	float fYec33[512];
	int fYec33_idx;
	int fYec33_idx_save;
	float fYec34[1024];
	int fYec34_idx;
	int fYec34_idx_save;
	float fYec35[2048];
	int fYec35_idx;
	int fYec35_idx_save;
	float fYec36[4096];
	int fYec36_idx;
	int fYec36_idx_save;
	float fYec37[8192];
	int fYec37_idx;
	int fYec37_idx_save;
	float fYec38[16384];
	int fYec38_idx;
	int fYec38_idx_save;
	float fYec39[32768];
	int fYec39_idx;
	int fYec39_idx_save;
	float fYec40[65536];
	int fYec40_idx;
	int fYec40_idx_save;
	float fYec41[131072];
	int fYec41_idx;
	int fYec41_idx_save;
	float fYec42[262144];
	int fYec42_idx;
	int fYec42_idx_save;
	float fYec43[524288];
	int fYec43_idx;
	int fYec43_idx_save;
	float fYec44[1048576];
	int fYec44_idx;
	int fYec44_idx_save;
	float fYec45[2097152];
	int fYec45_idx;
	int fYec45_idx_save;
	FAUSTFLOAT fVbargraph2;
	float fYec46_perm[4];
	float fRec20_perm[4];
	float fConst98;
	float fConst99;
	FAUSTFLOAT fCheckbox8;
	FAUSTFLOAT fCheckbox9;
	float fRec33_perm[4];
	float fRec34_perm[4];
	float fRec32_perm[4];
	float fRec35_perm[4];
	float fRec36_perm[4];
	float fRec31_perm[4];
	float fConst100;
	float fConst101;
	float fRec30_perm[4];
	float fRec38_perm[4];
	float fRec37_perm[4];
	float fRec40_perm[4];
	float fRec39_perm[4];
	float fRec42_perm[4];
	float fRec41_perm[4];
	float fRec44_perm[4];
	float fRec43_perm[4];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	float fConst102;
	float fRec48_perm[4];
	float fConst103;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	int iYec47_perm[4];
	int iRec49_perm[4];
	float fRec47_perm[4];
	FAUSTFLOAT fVbargraph3;
	float fRec46_perm[4];
	int iYec48_perm[4];
	int iRec50_perm[4];
	float fRec45_perm[4];
	float fConst104;
	FAUSTFLOAT fVslider5;
	float fYec49_perm[4];
	float fRec53_perm[4];
	float fConst106;
	float fConst108;
	float fConst109;
	float fConst110;
	float fRec52_perm[4];
	float fRec54_perm[4];
	FAUSTFLOAT fVslider6;
	float fRec55_perm[4];
	float fYec50_perm[4];
	float fRec51_perm[4];
	float fRec56_perm[4];
	float fYec51_perm[4];
	float fRec59_perm[4];
	float fRec58_perm[4];
	float fRec60_perm[4];
	float fYec52_perm[4];
	float fRec57_perm[4];
	float fRec61_perm[4];
	FAUSTFLOAT fVslider7;
	float fRec70_perm[4];
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fVslider9;
	float fRec66_perm[4];
	float fRec67_perm[4];
	float fRec62_perm[4];
	float fRec63_perm[4];
	int iConst112;
	float fYec53_perm[4];
	int iConst114;
	float fYec54_perm[4];
	int iConst116;
	float fYec55_perm[8];
	int iConst118;
	int iConst120;
	float fYec56_perm[16];
	int iConst122;
	int iConst124;
	float fYec57[64];
	int fYec57_idx;
	int fYec57_idx_save;
	int iConst126;
	int iConst128;
	float fYec58[128];
	int fYec58_idx;
	int fYec58_idx_save;
	int iConst130;
	int iConst132;
	float fYec59[256];
	int fYec59_idx;
	int fYec59_idx_save;
	int iConst134;
	int iConst136;
	float fYec60[512];
	int fYec60_idx;
	int fYec60_idx_save;
	int iConst138;
	int iConst140;
	float fYec61[1024];
	int fYec61_idx;
	int fYec61_idx_save;
	int iConst142;
	int iConst144;
	float fYec62[2048];
	int fYec62_idx;
	int fYec62_idx_save;
	int iConst146;
	int iConst148;
	float fYec63[4096];
	int fYec63_idx;
	int fYec63_idx_save;
	int iConst150;
	int iConst152;
	float fYec64[8192];
	int fYec64_idx;
	int fYec64_idx_save;
	int iConst154;
	int iConst156;
	float fYec65[16384];
	int fYec65_idx;
	int fYec65_idx_save;
	int iConst158;
	int iConst160;
	float fYec66[32768];
	int fYec66_idx;
	int fYec66_idx_save;
	int iConst162;
	int iConst163;
	float fYec67[65536];
	int fYec67_idx;
	int fYec67_idx_save;
	int iConst164;
	FAUSTFLOAT fVslider10;
	float fConst165;
	float fConst166;
	float fRec11_perm[4];
	float fYec68_perm[4];
	float fRec74_perm[4];
	float fRec73_perm[4];
	float fYec69_perm[4];
	float fRec72_perm[4];
	float fRec71_perm[4];
	float fYec70_perm[4];
	float fRec78_perm[4];
	float fRec77_perm[4];
	float fYec71_perm[4];
	float fRec76_perm[4];
	float fRec75_perm[4];
	FAUSTFLOAT fVslider11;
	FAUSTFLOAT fVbargraph4;
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	FAUSTFLOAT fVslider14;
	float fConst168;
	int iConst169;
	float fYec72_perm[4];
	float fYec73_perm[4];
	float fYec74_perm[8];
	float fYec75_perm[16];
	float fYec76[64];
	int fYec76_idx;
	int fYec76_idx_save;
	float fYec77[128];
	int fYec77_idx;
	int fYec77_idx_save;
	float fYec78[256];
	int fYec78_idx;
	int fYec78_idx_save;
	float fYec79[512];
	int fYec79_idx;
	int fYec79_idx_save;
	float fYec80[1024];
	int fYec80_idx;
	int fYec80_idx_save;
	float fYec81[2048];
	int fYec81_idx;
	int fYec81_idx_save;
	float fYec82[4096];
	int fYec82_idx;
	int fYec82_idx_save;
	float fYec83[8192];
	int fYec83_idx;
	int fYec83_idx_save;
	float fYec84[16384];
	int fYec84_idx;
	int fYec84_idx_save;
	float fYec85[32768];
	int fYec85_idx;
	int fYec85_idx_save;
	float fYec86[65536];
	int fYec86_idx;
	int fYec86_idx_save;
	float fYec87[131072];
	int fYec87_idx;
	int fYec87_idx_save;
	float fYec88[262144];
	int fYec88_idx;
	int fYec88_idx_save;
	int iConst200;
	int iConst201;
	int iConst202;
	int iConst203;
	int iConst204;
	int iConst205;
	int iConst206;
	int iConst207;
	int iConst208;
	int iConst209;
	int iConst210;
	int iConst211;
	int iConst212;
	int iConst213;
	int iConst214;
	int iConst215;
	int iConst216;
	int iConst217;
	int iConst218;
	int iConst219;
	int iConst220;
	int iConst221;
	int iConst222;
	int iConst223;
	int iConst224;
	int iConst225;
	int iConst226;
	int iConst227;
	int iConst228;
	int iConst229;
	int iConst230;
	float fYec89_perm[4];
	float fYec90_perm[4];
	float fYec91_perm[8];
	float fYec92_perm[16];
	float fYec93[64];
	int fYec93_idx;
	int fYec93_idx_save;
	float fYec94[128];
	int fYec94_idx;
	int fYec94_idx_save;
	float fYec95[256];
	int fYec95_idx;
	int fYec95_idx_save;
	float fYec96[512];
	int fYec96_idx;
	int fYec96_idx_save;
	float fYec97[1024];
	int fYec97_idx;
	int fYec97_idx_save;
	float fYec98[2048];
	int fYec98_idx;
	int fYec98_idx_save;
	float fYec99[4096];
	int fYec99_idx;
	int fYec99_idx_save;
	float fYec100[8192];
	int fYec100_idx;
	int fYec100_idx_save;
	float fYec101[16384];
	int fYec101_idx;
	int fYec101_idx_save;
	float fYec102[32768];
	int fYec102_idx;
	int fYec102_idx_save;
	float fYec103[65536];
	int fYec103_idx;
	int fYec103_idx_save;
	float fYec104[131072];
	int fYec104_idx;
	int fYec104_idx_save;
	float fYec105[262144];
	int fYec105_idx;
	int fYec105_idx_save;
	float fRec10_perm[4];
	FAUSTFLOAT fVbargraph5;
	float fRec9_perm[4];
	float fConst231;
	FAUSTFLOAT fVslider15;
	float fRec79_perm[4];
	FAUSTFLOAT fCheckbox10;
	float fRec80_perm[4];
	FAUSTFLOAT fVslider16;
	float fRec81_perm[4];
	FAUSTFLOAT fVslider17;
	float fRec83[262144];
	int fRec83_idx;
	int fRec83_idx_save;
	FAUSTFLOAT fVslider18;
	FAUSTFLOAT fVslider19;
	float fRec82_perm[4];
	float fRec85[262144];
	int fRec85_idx;
	int fRec85_idx_save;
	float fRec84_perm[4];
	FAUSTFLOAT fVslider20;
	float fRec86_perm[4];
	FAUSTFLOAT fVslider21;
	FAUSTFLOAT fVslider22;
	FAUSTFLOAT fVslider23;
	FAUSTFLOAT fVslider24;
	FAUSTFLOAT fVbargraph6;
	FAUSTFLOAT fVbargraph7;
	FAUSTFLOAT fVslider25;
	FAUSTFLOAT fVslider26;
	float fRec90_perm[4];
	float fRec89_perm[4];
	float fRec88_perm[4];
	FAUSTFLOAT fVslider27;
	FAUSTFLOAT fVslider28;
	FAUSTFLOAT fVslider29;
	FAUSTFLOAT fVslider30;
	FAUSTFLOAT fVslider31;
	FAUSTFLOAT fVslider32;
	FAUSTFLOAT fVslider33;
	FAUSTFLOAT fVslider34;
	float fRec87_perm[4];
	float fRec94_perm[4];
	float fRec93_perm[4];
	float fRec92_perm[4];
	float fRec91_perm[4];
	float fRec325_perm[4];
	float fRec324_perm[4];
	float fRec323_perm[4];
	float fRec322_perm[4];
	float fRec321_perm[4];
	float fRec320_perm[4];
	float fRec319_perm[4];
	float fRec318_perm[4];
	float fRec317_perm[4];
	float fRec316_perm[4];
	float fRec315_perm[4];
	float fRec314_perm[4];
	float fRec313_perm[4];
	float fRec312_perm[4];
	float fRec311_perm[4];
	float fRec310_perm[4];
	float fRec309_perm[4];
	float fRec308_perm[4];
	float fRec307_perm[4];
	float fRec306_perm[4];
	FAUSTFLOAT fVslider35;
	FAUSTFLOAT fVslider36;
	float fRec305_perm[4];
	float fRec346_perm[4];
	float fRec345_perm[4];
	float fRec344_perm[4];
	float fRec343_perm[4];
	float fRec342_perm[4];
	float fRec341_perm[4];
	float fRec340_perm[4];
	float fRec339_perm[4];
	float fRec338_perm[4];
	float fRec337_perm[4];
	float fRec336_perm[4];
	float fRec335_perm[4];
	float fRec334_perm[4];
	float fRec333_perm[4];
	float fRec332_perm[4];
	float fRec331_perm[4];
	float fRec330_perm[4];
	float fRec329_perm[4];
	float fRec328_perm[4];
	float fRec327_perm[4];
	float fRec326_perm[4];
	FAUSTFLOAT fVslider37;
	FAUSTFLOAT fVbargraph8;
	float fRec300_perm[4];
	float fRec301_perm[4];
	float fRec295_perm[4];
	float fRec296_perm[4];
	float fRec290_perm[4];
	float fRec291_perm[4];
	float fRec349_perm[4];
	float fRec348_perm[4];
	float fRec347_perm[4];
	float fRec352_perm[4];
	float fRec351_perm[4];
	float fRec350_perm[4];
	FAUSTFLOAT fVslider38;
	FAUSTFLOAT fVbargraph9;
	float fRec285_perm[4];
	float fRec286_perm[4];
	float fRec280_perm[4];
	float fRec281_perm[4];
	float fRec275_perm[4];
	float fRec276_perm[4];
	float fRec270_perm[4];
	float fRec271_perm[4];
	float fRec265_perm[4];
	float fRec266_perm[4];
	float fRec260_perm[4];
	float fRec261_perm[4];
	float fRec355_perm[4];
	float fRec354_perm[4];
	float fRec353_perm[4];
	float fRec358_perm[4];
	float fRec357_perm[4];
	float fRec356_perm[4];
	FAUSTFLOAT fVbargraph10;
	float fRec255_perm[4];
	float fRec256_perm[4];
	float fRec250_perm[4];
	float fRec251_perm[4];
	float fRec245_perm[4];
	float fRec246_perm[4];
	float fRec240_perm[4];
	float fRec241_perm[4];
	float fRec235_perm[4];
	float fRec236_perm[4];
	float fRec230_perm[4];
	float fRec231_perm[4];
	float fRec361_perm[4];
	float fRec360_perm[4];
	float fRec359_perm[4];
	float fRec364_perm[4];
	float fRec363_perm[4];
	float fRec362_perm[4];
	FAUSTFLOAT fVbargraph11;
	float fRec225_perm[4];
	float fRec226_perm[4];
	float fRec220_perm[4];
	float fRec221_perm[4];
	float fRec215_perm[4];
	float fRec216_perm[4];
	float fRec210_perm[4];
	float fRec211_perm[4];
	float fRec205_perm[4];
	float fRec206_perm[4];
	float fRec200_perm[4];
	float fRec201_perm[4];
	float fRec367_perm[4];
	float fRec366_perm[4];
	float fRec365_perm[4];
	float fRec370_perm[4];
	float fRec369_perm[4];
	float fRec368_perm[4];
	FAUSTFLOAT fVbargraph12;
	float fRec195_perm[4];
	float fRec196_perm[4];
	float fRec190_perm[4];
	float fRec191_perm[4];
	float fRec185_perm[4];
	float fRec186_perm[4];
	float fRec180_perm[4];
	float fRec181_perm[4];
	float fRec175_perm[4];
	float fRec176_perm[4];
	float fRec170_perm[4];
	float fRec171_perm[4];
	float fRec373_perm[4];
	float fRec372_perm[4];
	float fRec371_perm[4];
	float fRec376_perm[4];
	float fRec375_perm[4];
	float fRec374_perm[4];
	FAUSTFLOAT fVbargraph13;
	float fRec165_perm[4];
	float fRec166_perm[4];
	float fRec160_perm[4];
	float fRec161_perm[4];
	float fRec155_perm[4];
	float fRec156_perm[4];
	float fRec150_perm[4];
	float fRec151_perm[4];
	float fRec145_perm[4];
	float fRec146_perm[4];
	float fRec140_perm[4];
	float fRec141_perm[4];
	float fRec379_perm[4];
	float fRec378_perm[4];
	float fRec377_perm[4];
	float fRec382_perm[4];
	float fRec381_perm[4];
	float fRec380_perm[4];
	FAUSTFLOAT fVbargraph14;
	float fRec135_perm[4];
	float fRec136_perm[4];
	float fRec130_perm[4];
	float fRec131_perm[4];
	float fRec125_perm[4];
	float fRec126_perm[4];
	float fRec120_perm[4];
	float fRec121_perm[4];
	float fRec115_perm[4];
	float fRec116_perm[4];
	float fRec110_perm[4];
	float fRec111_perm[4];
	FAUSTFLOAT fVbargraph15;
	float fRec105_perm[4];
	float fRec106_perm[4];
	float fRec100_perm[4];
	float fRec101_perm[4];
	float fRec95_perm[4];
	float fRec96_perm[4];
	FAUSTFLOAT fVbargraph16;
	float fRec588_perm[4];
	float fRec589_perm[4];
	float fRec583_perm[4];
	float fRec584_perm[4];
	float fRec578_perm[4];
	float fRec579_perm[4];
	FAUSTFLOAT fVbargraph17;
	float fRec573_perm[4];
	float fRec574_perm[4];
	float fRec568_perm[4];
	float fRec569_perm[4];
	float fRec563_perm[4];
	float fRec564_perm[4];
	float fRec558_perm[4];
	float fRec559_perm[4];
	float fRec553_perm[4];
	float fRec554_perm[4];
	float fRec548_perm[4];
	float fRec549_perm[4];
	FAUSTFLOAT fVbargraph18;
	float fRec543_perm[4];
	float fRec544_perm[4];
	float fRec538_perm[4];
	float fRec539_perm[4];
	float fRec533_perm[4];
	float fRec534_perm[4];
	float fRec528_perm[4];
	float fRec529_perm[4];
	float fRec523_perm[4];
	float fRec524_perm[4];
	float fRec518_perm[4];
	float fRec519_perm[4];
	FAUSTFLOAT fVbargraph19;
	float fRec513_perm[4];
	float fRec514_perm[4];
	float fRec508_perm[4];
	float fRec509_perm[4];
	float fRec503_perm[4];
	float fRec504_perm[4];
	float fRec498_perm[4];
	float fRec499_perm[4];
	float fRec493_perm[4];
	float fRec494_perm[4];
	float fRec488_perm[4];
	float fRec489_perm[4];
	FAUSTFLOAT fVbargraph20;
	float fRec483_perm[4];
	float fRec484_perm[4];
	float fRec478_perm[4];
	float fRec479_perm[4];
	float fRec473_perm[4];
	float fRec474_perm[4];
	float fRec468_perm[4];
	float fRec469_perm[4];
	float fRec463_perm[4];
	float fRec464_perm[4];
	float fRec458_perm[4];
	float fRec459_perm[4];
	FAUSTFLOAT fVbargraph21;
	float fRec453_perm[4];
	float fRec454_perm[4];
	float fRec448_perm[4];
	float fRec449_perm[4];
	float fRec443_perm[4];
	float fRec444_perm[4];
	float fRec438_perm[4];
	float fRec439_perm[4];
	float fRec433_perm[4];
	float fRec434_perm[4];
	float fRec428_perm[4];
	float fRec429_perm[4];
	FAUSTFLOAT fVbargraph22;
	float fRec423_perm[4];
	float fRec424_perm[4];
	float fRec418_perm[4];
	float fRec419_perm[4];
	float fRec413_perm[4];
	float fRec414_perm[4];
	float fRec408_perm[4];
	float fRec409_perm[4];
	float fRec403_perm[4];
	float fRec404_perm[4];
	float fRec398_perm[4];
	float fRec399_perm[4];
	FAUSTFLOAT fVbargraph23;
	float fRec393_perm[4];
	float fRec394_perm[4];
	float fRec388_perm[4];
	float fRec389_perm[4];
	float fRec383_perm[4];
	float fRec384_perm[4];
	FAUSTFLOAT fVslider39;
	float fRec594[131072];
	int fRec594_idx;
	int fRec594_idx_save;
	FAUSTFLOAT fVslider40;
	FAUSTFLOAT fVslider41;
	float fRec593_perm[4];
	float fRec596[131072];
	int fRec596_idx;
	int fRec596_idx_save;
	float fRec595_perm[4];
	FAUSTFLOAT fVslider42;
	FAUSTFLOAT fVslider43;
	FAUSTFLOAT fVslider44;
	FAUSTFLOAT fVbargraph24;
	float fRec5_perm[4];
	float fRec6_perm[4];
	FAUSTFLOAT fVslider45;
	float fRec597_perm[4];
	FAUSTFLOAT fCheckbox11;
	float fRec598_perm[4];
	FAUSTFLOAT fCheckbox12;
	float fRec599_perm[4];
	FAUSTFLOAT fVslider46;
	float fRec600_perm[4];
	float fRec601_perm[4];
	FAUSTFLOAT fVslider47;
	FAUSTFLOAT fVbargraph25;
	float fRec3_perm[4];
	float fRec4_perm[4];
	float fRec1_perm[4];
	float fRec2_perm[4];
	float fYec106_perm[4];
	float fRec602_perm[4];
	FAUSTFLOAT fVbargraph26;
	float fYec107_perm[4];
	float fRec606_perm[4];
	float fRec605_perm[4];
	float fYec108_perm[4];
	float fRec604_perm[4];
	float fRec603_perm[4];
	float fYec109_perm[4];
	float fYec110_perm[4];
	float fRec610_perm[4];
	float fRec609_perm[4];
	float fYec111_perm[4];
	float fRec608_perm[4];
	float fRec607_perm[4];
	float fYec112_perm[4];
	float fYec113_perm[4];
	float fYec114_perm[8];
	float fYec115_perm[16];
	float fYec116[64];
	int fYec116_idx;
	int fYec116_idx_save;
	float fYec117[128];
	int fYec117_idx;
	int fYec117_idx_save;
	float fYec118[256];
	int fYec118_idx;
	int fYec118_idx_save;
	float fYec119[512];
	int fYec119_idx;
	int fYec119_idx_save;
	float fYec120[1024];
	int fYec120_idx;
	int fYec120_idx_save;
	float fYec121[2048];
	int fYec121_idx;
	int fYec121_idx_save;
	float fYec122[4096];
	int fYec122_idx;
	int fYec122_idx_save;
	float fYec123[8192];
	int fYec123_idx;
	int fYec123_idx_save;
	float fYec124[16384];
	int fYec124_idx;
	int fYec124_idx_save;
	float fYec125[32768];
	int fYec125_idx;
	int fYec125_idx_save;
	float fYec126[65536];
	int fYec126_idx;
	int fYec126_idx_save;
	float fYec127[131072];
	int fYec127_idx;
	int fYec127_idx_save;
	float fYec128[262144];
	int fYec128_idx;
	int fYec128_idx_save;
	float fYec129[524288];
	int fYec129_idx;
	int fYec129_idx_save;
	float fYec130[1048576];
	int fYec130_idx;
	int fYec130_idx_save;
	float fYec131[2097152];
	int fYec131_idx;
	int fYec131_idx_save;
	float fYec132_perm[4];
	float fYec133_perm[4];
	float fYec134_perm[8];
	float fYec135_perm[16];
	float fYec136[64];
	int fYec136_idx;
	int fYec136_idx_save;
	float fYec137[128];
	int fYec137_idx;
	int fYec137_idx_save;
	float fYec138[256];
	int fYec138_idx;
	int fYec138_idx_save;
	float fYec139[512];
	int fYec139_idx;
	int fYec139_idx_save;
	float fYec140[1024];
	int fYec140_idx;
	int fYec140_idx_save;
	float fYec141[2048];
	int fYec141_idx;
	int fYec141_idx_save;
	float fYec142[4096];
	int fYec142_idx;
	int fYec142_idx_save;
	float fYec143[8192];
	int fYec143_idx;
	int fYec143_idx_save;
	float fYec144[16384];
	int fYec144_idx;
	int fYec144_idx_save;
	float fYec145[32768];
	int fYec145_idx;
	int fYec145_idx_save;
	float fYec146[65536];
	int fYec146_idx;
	int fYec146_idx_save;
	float fYec147[131072];
	int fYec147_idx;
	int fYec147_idx_save;
	float fYec148[262144];
	int fYec148_idx;
	int fYec148_idx_save;
	float fYec149[524288];
	int fYec149_idx;
	int fYec149_idx_save;
	float fYec150[1048576];
	int fYec150_idx;
	int fYec150_idx_save;
	float fYec151[2097152];
	int fYec151_idx;
	int fYec151_idx_save;
	FAUSTFLOAT fVbargraph27;
	float fRec611_perm[4];
	FAUSTFLOAT fVbargraph28;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.2");
		m->declare("author", "Klaus Scheuermann");
		m->declare("basics.lib/bypass1:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/parallelMin:author", "Bart Brouns");
		m->declare("basics.lib/parallelMin:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelMin:licence", "GPL-3.0");
		m->declare("basics.lib/parallelOp:author", "Bart Brouns");
		m->declare("basics.lib/parallelOp:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelOp:licence", "GPL-3.0");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-a /home/falktx/.cache/faustpp/3033603-md.cpp -lang cpp -es 1 -mcd 16 -single -ftz 0 -vec -lv 1 -vs 8");
		m->declare("compressors.lib/FFcompressor_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/FFcompressor_N_chan:license", "GPLv3");
		m->declare("compressors.lib/RMS_FBFFcompressor_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_FBFFcompressor_N_chan:license", "GPLv3");
		m->declare("compressors.lib/RMS_compression_gain_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_compression_gain_N_chan:license", "GPLv3");
		m->declare("compressors.lib/RMS_compression_gain_mono:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_compression_gain_mono:license", "GPLv3");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/peak_compression_gain_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/peak_compression_gain_N_chan:license", "GPLv3");
		m->declare("compressors.lib/peak_compression_gain_mono:author", "Bart Brouns");
		m->declare("compressors.lib/peak_compression_gain_mono:license", "GPLv3");
		m->declare("compressors.lib/version", "0.2");
		m->declare("expanders.lib/author", "Bart Brouns");
		m->declare("expanders.lib/license", "GPLv3");
		m->declare("expanders.lib/name", "expanders");
		m->declare("expanders.lib/version", "0.1");
		m->declare("filename", "master_me.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/integrator:author", "Julius O. Smith III");
		m->declare("filters.lib/integrator:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/integrator:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/lowshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowshelf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/svf:author", "Oleg Nesterov");
		m->declare("filters.lib/svf:copyright", "Copyright (C) 2020 Oleg Nesterov <oleg@redhat.com>");
		m->declare("filters.lib/svf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf22t:author", "Julius O. Smith III");
		m->declare("filters.lib/tf22t:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf22t:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("interpolators.lib/interpolate_linear:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_linear:licence", "MIT");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/version", "0.3");
		m->declare("lib/ebur128.dsp/author", "Jakob Dübel");
		m->declare("lib/ebur128.dsp/license", "ISC");
		m->declare("lib/ebur128.dsp/name", "ITU-R BS.1770-4 prefilter");
		m->declare("lib/ebur128.dsp/version", "1.0");
		m->declare("license", "GPLv3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "master_me");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "0.3");
		m->declare("version", "1.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.0999985f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 80.0f / fConst0;
		float fConst4 = 31.415926f / fConst0;
		fConst5 = 1.0f / (fConst4 + 1.0f);
		fConst6 = 1.0f - fConst4;
		float fConst7 = std::tan(5283.41504f / fConst0);
		fConst8 = 1.0f / (fConst7 * (fConst7 + 1.41421354f) + 1.0f);
		fConst9 = fConst7 * (fConst7 + -1.41421354f) + 1.0f;
		fConst10 = fConst7 * (fConst7 + -1.78036666f) + 1.5848527f;
		fConst11 = fConst7 * (fConst7 + 1.78036666f) + 1.5848527f;
		float fConst12 = mydsp_faustpower2_f(fConst7);
		fConst13 = fConst12 + -1.0f;
		fConst14 = fConst12 + -1.5848527f;
		float fConst15 = std::tan(119.806114f / fConst0);
		float fConst16 = 0.500327051f * fConst15;
		float fConst17 = fConst15 * (fConst16 + 1.0f) + 0.500327051f;
		fConst18 = 0.0f - 1.0006541f / fConst17;
		fConst19 = 1.0f / fConst17;
		fConst20 = fConst15 * (fConst16 + -1.0f) + 0.500327051f;
		fConst21 = 1.0006541f * (mydsp_faustpower2_f(fConst15) + -1.0f);
		float fConst22 = std::rint(3.0f * fConst0);
		fConst23 = 1.0f / std::max<float>(fConst22, 1.1920929e-07f);
		iConst24 = int(std::floor(1.90734863e-06f * fConst22)) % 2;
		int iConst25 = int(std::floor(fConst22)) % 2;
		int iConst26 = int(std::floor(0.5f * fConst22)) % 2;
		int iConst27 = iConst25 + 2 * iConst26;
		int iConst28 = int(std::floor(0.25f * fConst22)) % 2;
		int iConst29 = iConst27 + 4 * iConst28;
		int iConst30 = int(std::floor(0.125f * fConst22)) % 2;
		int iConst31 = iConst29 + 8 * iConst30;
		int iConst32 = int(std::floor(0.0625f * fConst22)) % 2;
		int iConst33 = iConst31 + 16 * iConst32;
		int iConst34 = int(std::floor(0.03125f * fConst22)) % 2;
		int iConst35 = iConst33 + 32 * iConst34;
		int iConst36 = int(std::floor(0.015625f * fConst22)) % 2;
		int iConst37 = iConst35 + 64 * iConst36;
		int iConst38 = int(std::floor(0.0078125f * fConst22)) % 2;
		int iConst39 = iConst37 + 128 * iConst38;
		int iConst40 = int(std::floor(0.00390625f * fConst22)) % 2;
		int iConst41 = iConst39 + 256 * iConst40;
		int iConst42 = int(std::floor(0.001953125f * fConst22)) % 2;
		int iConst43 = iConst41 + 512 * iConst42;
		int iConst44 = int(std::floor(0.0009765625f * fConst22)) % 2;
		int iConst45 = iConst43 + 1024 * iConst44;
		int iConst46 = int(std::floor(0.00048828125f * fConst22)) % 2;
		int iConst47 = iConst45 + 2048 * iConst46;
		int iConst48 = int(std::floor(0.000244140625f * fConst22)) % 2;
		int iConst49 = iConst47 + 4096 * iConst48;
		int iConst50 = int(std::floor(0.000122070312f * fConst22)) % 2;
		int iConst51 = iConst49 + 8192 * iConst50;
		int iConst52 = int(std::floor(6.10351562e-05f * fConst22)) % 2;
		int iConst53 = iConst51 + 16384 * iConst52;
		int iConst54 = int(std::floor(3.05175781e-05f * fConst22)) % 2;
		int iConst55 = iConst53 + 32768 * iConst54;
		int iConst56 = int(std::floor(1.52587891e-05f * fConst22)) % 2;
		int iConst57 = iConst55 + 65536 * iConst56;
		int iConst58 = int(std::floor(7.62939453e-06f * fConst22)) % 2;
		int iConst59 = iConst57 + 131072 * iConst58;
		int iConst60 = int(std::floor(3.81469727e-06f * fConst22)) % 2;
		iConst61 = iConst59 + 262144 * iConst60;
		iConst62 = iConst60;
		iConst63 = iConst59;
		iConst64 = iConst58;
		iConst65 = iConst57;
		iConst66 = iConst56;
		iConst67 = iConst55;
		iConst68 = iConst54;
		iConst69 = iConst53;
		iConst70 = iConst52;
		iConst71 = iConst51;
		iConst72 = iConst50;
		iConst73 = iConst49;
		iConst74 = iConst48;
		iConst75 = iConst47;
		iConst76 = iConst46;
		iConst77 = iConst45;
		iConst78 = iConst44;
		iConst79 = iConst43;
		iConst80 = iConst42;
		iConst81 = iConst41;
		iConst82 = iConst40;
		iConst83 = iConst39;
		iConst84 = iConst38;
		iConst85 = iConst37;
		iConst86 = iConst36;
		iConst87 = iConst35;
		iConst88 = iConst34;
		iConst89 = iConst33;
		iConst90 = iConst32;
		iConst91 = iConst31;
		iConst92 = iConst30;
		iConst93 = iConst29;
		iConst94 = iConst28;
		iConst95 = iConst27;
		iConst96 = iConst25;
		iConst97 = iConst26;
		fConst98 = std::exp(0.0f - fConst4);
		fConst99 = 1.0f - fConst98;
		fConst100 = std::exp(0.0f - 12.566371f / fConst0);
		fConst101 = 1.0f - fConst100;
		fConst102 = 1.0f / fConst0;
		fConst103 = 0.00100000005f * fConst0;
		fConst104 = 3.14159274f / fConst0;
		float fConst105 = std::tan(1979.20337f / fConst0);
		fConst106 = 1.0f / fConst105;
		float fConst107 = fConst106 + 1.0f;
		fConst108 = 0.0f - 1.0f / (fConst105 * fConst107);
		fConst109 = 1.0f / fConst107;
		fConst110 = 1.0f - fConst106;
		int iConst111 = int(std::floor(0.100000001f * fConst0)) % 2;
		iConst112 = iConst111;
		int iConst113 = int(std::floor(0.0500000007f * fConst0)) % 2;
		iConst114 = iConst113;
		int iConst115 = int(std::floor(0.0250000004f * fConst0)) % 2;
		iConst116 = iConst115;
		int iConst117 = iConst111 + 2 * iConst113;
		iConst118 = iConst117;
		int iConst119 = int(std::floor(0.0125000002f * fConst0)) % 2;
		iConst120 = iConst119;
		int iConst121 = iConst117 + 4 * iConst115;
		iConst122 = iConst121;
		int iConst123 = int(std::floor(0.00625000009f * fConst0)) % 2;
		iConst124 = iConst123;
		int iConst125 = iConst121 + 8 * iConst119;
		iConst126 = iConst125;
		int iConst127 = int(std::floor(0.00312500005f * fConst0)) % 2;
		iConst128 = iConst127;
		int iConst129 = iConst125 + 16 * iConst123;
		iConst130 = iConst129;
		int iConst131 = int(std::floor(0.00156250002f * fConst0)) % 2;
		iConst132 = iConst131;
		int iConst133 = iConst129 + 32 * iConst127;
		iConst134 = iConst133;
		int iConst135 = int(std::floor(0.000781250012f * fConst0)) % 2;
		iConst136 = iConst135;
		int iConst137 = iConst133 + 64 * iConst131;
		iConst138 = iConst137;
		int iConst139 = int(std::floor(0.000390625006f * fConst0)) % 2;
		iConst140 = iConst139;
		int iConst141 = iConst137 + 128 * iConst135;
		iConst142 = iConst141;
		int iConst143 = int(std::floor(0.000195312503f * fConst0)) % 2;
		iConst144 = iConst143;
		int iConst145 = iConst141 + 256 * iConst139;
		iConst146 = iConst145;
		int iConst147 = int(std::floor(9.76562515e-05f * fConst0)) % 2;
		iConst148 = iConst147;
		int iConst149 = iConst145 + 512 * iConst143;
		iConst150 = iConst149;
		int iConst151 = int(std::floor(4.88281257e-05f * fConst0)) % 2;
		iConst152 = iConst151;
		int iConst153 = iConst149 + 1024 * iConst147;
		iConst154 = iConst153;
		int iConst155 = int(std::floor(2.44140629e-05f * fConst0)) % 2;
		iConst156 = iConst155;
		int iConst157 = iConst153 + 2048 * iConst151;
		iConst158 = iConst157;
		int iConst159 = int(std::floor(1.22070314e-05f * fConst0)) % 2;
		iConst160 = iConst159;
		int iConst161 = iConst157 + 4096 * iConst155;
		iConst162 = iConst161;
		iConst163 = int(std::floor(6.10351572e-06f * fConst0)) % 2;
		iConst164 = iConst161 + 8192 * iConst159;
		fConst165 = std::exp(0.0f - 3.33333325f / fConst0);
		fConst166 = std::exp(0.0f - 20.0f / fConst0);
		float fConst167 = std::rint(0.400000006f * fConst0);
		fConst168 = 1.0f / std::max<float>(fConst167, 1.1920929e-07f);
		iConst169 = int(std::floor(1.52587891e-05f * fConst167)) % 2;
		int iConst170 = int(std::floor(fConst167)) % 2;
		int iConst171 = int(std::floor(0.5f * fConst167)) % 2;
		int iConst172 = iConst170 + 2 * iConst171;
		int iConst173 = int(std::floor(0.25f * fConst167)) % 2;
		int iConst174 = iConst172 + 4 * iConst173;
		int iConst175 = int(std::floor(0.125f * fConst167)) % 2;
		int iConst176 = iConst174 + 8 * iConst175;
		int iConst177 = int(std::floor(0.0625f * fConst167)) % 2;
		int iConst178 = iConst176 + 16 * iConst177;
		int iConst179 = int(std::floor(0.03125f * fConst167)) % 2;
		int iConst180 = iConst178 + 32 * iConst179;
		int iConst181 = int(std::floor(0.015625f * fConst167)) % 2;
		int iConst182 = iConst180 + 64 * iConst181;
		int iConst183 = int(std::floor(0.0078125f * fConst167)) % 2;
		int iConst184 = iConst182 + 128 * iConst183;
		int iConst185 = int(std::floor(0.00390625f * fConst167)) % 2;
		int iConst186 = iConst184 + 256 * iConst185;
		int iConst187 = int(std::floor(0.001953125f * fConst167)) % 2;
		int iConst188 = iConst186 + 512 * iConst187;
		int iConst189 = int(std::floor(0.0009765625f * fConst167)) % 2;
		int iConst190 = iConst188 + 1024 * iConst189;
		int iConst191 = int(std::floor(0.00048828125f * fConst167)) % 2;
		int iConst192 = iConst190 + 2048 * iConst191;
		int iConst193 = int(std::floor(0.000244140625f * fConst167)) % 2;
		int iConst194 = iConst192 + 4096 * iConst193;
		int iConst195 = int(std::floor(0.000122070312f * fConst167)) % 2;
		int iConst196 = iConst194 + 8192 * iConst195;
		int iConst197 = int(std::floor(6.10351562e-05f * fConst167)) % 2;
		int iConst198 = iConst196 + 16384 * iConst197;
		int iConst199 = int(std::floor(3.05175781e-05f * fConst167)) % 2;
		iConst200 = iConst198 + 32768 * iConst199;
		iConst201 = iConst199;
		iConst202 = iConst198;
		iConst203 = iConst197;
		iConst204 = iConst196;
		iConst205 = iConst195;
		iConst206 = iConst194;
		iConst207 = iConst193;
		iConst208 = iConst192;
		iConst209 = iConst191;
		iConst210 = iConst190;
		iConst211 = iConst189;
		iConst212 = iConst188;
		iConst213 = iConst187;
		iConst214 = iConst186;
		iConst215 = iConst185;
		iConst216 = iConst184;
		iConst217 = iConst183;
		iConst218 = iConst182;
		iConst219 = iConst181;
		iConst220 = iConst180;
		iConst221 = iConst179;
		iConst222 = iConst178;
		iConst223 = iConst177;
		iConst224 = iConst176;
		iConst225 = iConst175;
		iConst226 = iConst174;
		iConst227 = iConst173;
		iConst228 = iConst172;
		iConst229 = iConst170;
		iConst230 = iConst171;
		fConst231 = 0.441000015f / fConst0;
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fCheckbox6 = FAUSTFLOAT(0.0f);
		fVslider0 = FAUSTFLOAT(0.0f);
		fCheckbox7 = FAUSTFLOAT(0.0f);
		fCheckbox8 = FAUSTFLOAT(0.0f);
		fCheckbox9 = FAUSTFLOAT(0.0f);
		fVslider1 = FAUSTFLOAT(0.0f);
		fVslider2 = FAUSTFLOAT(500.0f);
		fVslider3 = FAUSTFLOAT(50.0f);
		fVslider4 = FAUSTFLOAT(-90.0f);
		fVslider5 = FAUSTFLOAT(5.0f);
		fVslider6 = FAUSTFLOAT(0.0f);
		fVslider7 = FAUSTFLOAT(0.0f);
		fVslider8 = FAUSTFLOAT(600.0f);
		fVslider9 = FAUSTFLOAT(1.0f);
		fVslider10 = FAUSTFLOAT(-14.0f);
		fVslider11 = FAUSTFLOAT(20.0f);
		fVslider12 = FAUSTFLOAT(20.0f);
		fVslider13 = FAUSTFLOAT(20.0f);
		fVslider14 = FAUSTFLOAT(-18.0f);
		fVslider15 = FAUSTFLOAT(100.0f);
		fCheckbox10 = FAUSTFLOAT(0.0f);
		fVslider16 = FAUSTFLOAT(0.0f);
		fVslider17 = FAUSTFLOAT(50.0f);
		fVslider18 = FAUSTFLOAT(200.0f);
		fVslider19 = FAUSTFLOAT(20.0f);
		fVslider20 = FAUSTFLOAT(1.0f);
		fVslider21 = FAUSTFLOAT(20.0f);
		fVslider22 = FAUSTFLOAT(-6.0f);
		fVslider23 = FAUSTFLOAT(6.0f);
		fVslider24 = FAUSTFLOAT(60.0f);
		fVslider25 = FAUSTFLOAT(60.0f);
		fVslider26 = FAUSTFLOAT(8000.0f);
		fVslider27 = FAUSTFLOAT(10.0f);
		fVslider28 = FAUSTFLOAT(10.0f);
		fVslider29 = FAUSTFLOAT(-12.0f);
		fVslider30 = FAUSTFLOAT(12.0f);
		fVslider31 = FAUSTFLOAT(15.0f);
		fVslider32 = FAUSTFLOAT(3.0f);
		fVslider33 = FAUSTFLOAT(150.0f);
		fVslider34 = FAUSTFLOAT(30.0f);
		fVslider35 = FAUSTFLOAT(-6.0f);
		fVslider36 = FAUSTFLOAT(12.0f);
		fVslider37 = FAUSTFLOAT(60.0f);
		fVslider38 = FAUSTFLOAT(30.0f);
		fVslider39 = FAUSTFLOAT(50.0f);
		fVslider40 = FAUSTFLOAT(40.0f);
		fVslider41 = FAUSTFLOAT(1.0f);
		fVslider42 = FAUSTFLOAT(80.0f);
		fVslider43 = FAUSTFLOAT(6.0f);
		fVslider44 = FAUSTFLOAT(8.0f);
		fVslider45 = FAUSTFLOAT(0.0f);
		fCheckbox11 = FAUSTFLOAT(0.0f);
		fCheckbox12 = FAUSTFLOAT(0.0f);
		fVslider46 = FAUSTFLOAT(75.0f);
		fVslider47 = FAUSTFLOAT(-1.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; l0 < 4; l0 = l0 + 1) {
			fRec0_perm[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 4; l1 = l1 + 1) {
			fRec7_perm[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 4; l2 = l2 + 1) {
			fRec8_perm[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 4; l3 = l3 + 1) {
			fRec12_perm[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 4; l4 = l4 + 1) {
			fRec13_perm[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 4; l5 = l5 + 1) {
			fRec14_perm[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 4; l6 = l6 + 1) {
			fRec15_perm[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 4; l7 = l7 + 1) {
			fRec16_perm[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4; l8 = l8 + 1) {
			fRec17_perm[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 4; l9 = l9 + 1) {
			fRec18_perm[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 4; l10 = l10 + 1) {
			fYec0_perm[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 4; l11 = l11 + 1) {
			fRec19_perm[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 4; l12 = l12 + 1) {
			fRec21_perm[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 4; l13 = l13 + 1) {
			fYec1_perm[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4; l14 = l14 + 1) {
			fRec25_perm[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 4; l15 = l15 + 1) {
			fRec24_perm[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 4; l16 = l16 + 1) {
			fYec2_perm[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 4; l17 = l17 + 1) {
			fRec23_perm[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 4; l18 = l18 + 1) {
			fRec22_perm[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 4; l19 = l19 + 1) {
			fYec3_perm[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 4; l20 = l20 + 1) {
			fYec4_perm[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 4; l21 = l21 + 1) {
			fRec29_perm[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 4; l22 = l22 + 1) {
			fRec28_perm[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 4; l23 = l23 + 1) {
			fYec5_perm[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 4; l24 = l24 + 1) {
			fRec27_perm[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 4; l25 = l25 + 1) {
			fRec26_perm[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 4; l26 = l26 + 1) {
			fYec6_perm[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 4; l27 = l27 + 1) {
			fYec7_perm[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 8; l28 = l28 + 1) {
			fYec8_perm[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 16; l29 = l29 + 1) {
			fYec9_perm[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 64; l30 = l30 + 1) {
			fYec10[l30] = 0.0f;
		}
		fYec10_idx = 0;
		fYec10_idx_save = 0;
		for (int l31 = 0; l31 < 128; l31 = l31 + 1) {
			fYec11[l31] = 0.0f;
		}
		fYec11_idx = 0;
		fYec11_idx_save = 0;
		for (int l32 = 0; l32 < 256; l32 = l32 + 1) {
			fYec12[l32] = 0.0f;
		}
		fYec12_idx = 0;
		fYec12_idx_save = 0;
		for (int l33 = 0; l33 < 512; l33 = l33 + 1) {
			fYec13[l33] = 0.0f;
		}
		fYec13_idx = 0;
		fYec13_idx_save = 0;
		for (int l34 = 0; l34 < 1024; l34 = l34 + 1) {
			fYec14[l34] = 0.0f;
		}
		fYec14_idx = 0;
		fYec14_idx_save = 0;
		for (int l35 = 0; l35 < 2048; l35 = l35 + 1) {
			fYec15[l35] = 0.0f;
		}
		fYec15_idx = 0;
		fYec15_idx_save = 0;
		for (int l36 = 0; l36 < 4096; l36 = l36 + 1) {
			fYec16[l36] = 0.0f;
		}
		fYec16_idx = 0;
		fYec16_idx_save = 0;
		for (int l37 = 0; l37 < 8192; l37 = l37 + 1) {
			fYec17[l37] = 0.0f;
		}
		fYec17_idx = 0;
		fYec17_idx_save = 0;
		for (int l38 = 0; l38 < 16384; l38 = l38 + 1) {
			fYec18[l38] = 0.0f;
		}
		fYec18_idx = 0;
		fYec18_idx_save = 0;
		for (int l39 = 0; l39 < 32768; l39 = l39 + 1) {
			fYec19[l39] = 0.0f;
		}
		fYec19_idx = 0;
		fYec19_idx_save = 0;
		for (int l40 = 0; l40 < 65536; l40 = l40 + 1) {
			fYec20[l40] = 0.0f;
		}
		fYec20_idx = 0;
		fYec20_idx_save = 0;
		for (int l41 = 0; l41 < 131072; l41 = l41 + 1) {
			fYec21[l41] = 0.0f;
		}
		fYec21_idx = 0;
		fYec21_idx_save = 0;
		for (int l42 = 0; l42 < 262144; l42 = l42 + 1) {
			fYec22[l42] = 0.0f;
		}
		fYec22_idx = 0;
		fYec22_idx_save = 0;
		for (int l43 = 0; l43 < 524288; l43 = l43 + 1) {
			fYec23[l43] = 0.0f;
		}
		fYec23_idx = 0;
		fYec23_idx_save = 0;
		for (int l44 = 0; l44 < 1048576; l44 = l44 + 1) {
			fYec24[l44] = 0.0f;
		}
		fYec24_idx = 0;
		fYec24_idx_save = 0;
		for (int l45 = 0; l45 < 2097152; l45 = l45 + 1) {
			fYec25[l45] = 0.0f;
		}
		fYec25_idx = 0;
		fYec25_idx_save = 0;
		for (int l46 = 0; l46 < 4; l46 = l46 + 1) {
			fYec26_perm[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 4; l47 = l47 + 1) {
			fYec27_perm[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 8; l48 = l48 + 1) {
			fYec28_perm[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 16; l49 = l49 + 1) {
			fYec29_perm[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 64; l50 = l50 + 1) {
			fYec30[l50] = 0.0f;
		}
		fYec30_idx = 0;
		fYec30_idx_save = 0;
		for (int l51 = 0; l51 < 128; l51 = l51 + 1) {
			fYec31[l51] = 0.0f;
		}
		fYec31_idx = 0;
		fYec31_idx_save = 0;
		for (int l52 = 0; l52 < 256; l52 = l52 + 1) {
			fYec32[l52] = 0.0f;
		}
		fYec32_idx = 0;
		fYec32_idx_save = 0;
		for (int l53 = 0; l53 < 512; l53 = l53 + 1) {
			fYec33[l53] = 0.0f;
		}
		fYec33_idx = 0;
		fYec33_idx_save = 0;
		for (int l54 = 0; l54 < 1024; l54 = l54 + 1) {
			fYec34[l54] = 0.0f;
		}
		fYec34_idx = 0;
		fYec34_idx_save = 0;
		for (int l55 = 0; l55 < 2048; l55 = l55 + 1) {
			fYec35[l55] = 0.0f;
		}
		fYec35_idx = 0;
		fYec35_idx_save = 0;
		for (int l56 = 0; l56 < 4096; l56 = l56 + 1) {
			fYec36[l56] = 0.0f;
		}
		fYec36_idx = 0;
		fYec36_idx_save = 0;
		for (int l57 = 0; l57 < 8192; l57 = l57 + 1) {
			fYec37[l57] = 0.0f;
		}
		fYec37_idx = 0;
		fYec37_idx_save = 0;
		for (int l58 = 0; l58 < 16384; l58 = l58 + 1) {
			fYec38[l58] = 0.0f;
		}
		fYec38_idx = 0;
		fYec38_idx_save = 0;
		for (int l59 = 0; l59 < 32768; l59 = l59 + 1) {
			fYec39[l59] = 0.0f;
		}
		fYec39_idx = 0;
		fYec39_idx_save = 0;
		for (int l60 = 0; l60 < 65536; l60 = l60 + 1) {
			fYec40[l60] = 0.0f;
		}
		fYec40_idx = 0;
		fYec40_idx_save = 0;
		for (int l61 = 0; l61 < 131072; l61 = l61 + 1) {
			fYec41[l61] = 0.0f;
		}
		fYec41_idx = 0;
		fYec41_idx_save = 0;
		for (int l62 = 0; l62 < 262144; l62 = l62 + 1) {
			fYec42[l62] = 0.0f;
		}
		fYec42_idx = 0;
		fYec42_idx_save = 0;
		for (int l63 = 0; l63 < 524288; l63 = l63 + 1) {
			fYec43[l63] = 0.0f;
		}
		fYec43_idx = 0;
		fYec43_idx_save = 0;
		for (int l64 = 0; l64 < 1048576; l64 = l64 + 1) {
			fYec44[l64] = 0.0f;
		}
		fYec44_idx = 0;
		fYec44_idx_save = 0;
		for (int l65 = 0; l65 < 2097152; l65 = l65 + 1) {
			fYec45[l65] = 0.0f;
		}
		fYec45_idx = 0;
		fYec45_idx_save = 0;
		for (int l66 = 0; l66 < 4; l66 = l66 + 1) {
			fYec46_perm[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 4; l67 = l67 + 1) {
			fRec20_perm[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 4; l68 = l68 + 1) {
			fRec33_perm[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 4; l69 = l69 + 1) {
			fRec34_perm[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 4; l70 = l70 + 1) {
			fRec32_perm[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 4; l71 = l71 + 1) {
			fRec35_perm[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 4; l72 = l72 + 1) {
			fRec36_perm[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 4; l73 = l73 + 1) {
			fRec31_perm[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 4; l74 = l74 + 1) {
			fRec30_perm[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 4; l75 = l75 + 1) {
			fRec38_perm[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 4; l76 = l76 + 1) {
			fRec37_perm[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 4; l77 = l77 + 1) {
			fRec40_perm[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 4; l78 = l78 + 1) {
			fRec39_perm[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 4; l79 = l79 + 1) {
			fRec42_perm[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 4; l80 = l80 + 1) {
			fRec41_perm[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 4; l81 = l81 + 1) {
			fRec44_perm[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 4; l82 = l82 + 1) {
			fRec43_perm[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 4; l83 = l83 + 1) {
			fRec48_perm[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 4; l84 = l84 + 1) {
			iYec47_perm[l84] = 0;
		}
		for (int l85 = 0; l85 < 4; l85 = l85 + 1) {
			iRec49_perm[l85] = 0;
		}
		for (int l86 = 0; l86 < 4; l86 = l86 + 1) {
			fRec47_perm[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 4; l87 = l87 + 1) {
			fRec46_perm[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 4; l88 = l88 + 1) {
			iYec48_perm[l88] = 0;
		}
		for (int l89 = 0; l89 < 4; l89 = l89 + 1) {
			iRec50_perm[l89] = 0;
		}
		for (int l90 = 0; l90 < 4; l90 = l90 + 1) {
			fRec45_perm[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 4; l91 = l91 + 1) {
			fYec49_perm[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 4; l92 = l92 + 1) {
			fRec53_perm[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 4; l93 = l93 + 1) {
			fRec52_perm[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 4; l94 = l94 + 1) {
			fRec54_perm[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 4; l95 = l95 + 1) {
			fRec55_perm[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 4; l96 = l96 + 1) {
			fYec50_perm[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 4; l97 = l97 + 1) {
			fRec51_perm[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 4; l98 = l98 + 1) {
			fRec56_perm[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 4; l99 = l99 + 1) {
			fYec51_perm[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 4; l100 = l100 + 1) {
			fRec59_perm[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 4; l101 = l101 + 1) {
			fRec58_perm[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 4; l102 = l102 + 1) {
			fRec60_perm[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 4; l103 = l103 + 1) {
			fYec52_perm[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 4; l104 = l104 + 1) {
			fRec57_perm[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 4; l105 = l105 + 1) {
			fRec61_perm[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 4; l106 = l106 + 1) {
			fRec70_perm[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 4; l107 = l107 + 1) {
			fRec66_perm[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 4; l108 = l108 + 1) {
			fRec67_perm[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 4; l109 = l109 + 1) {
			fRec62_perm[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 4; l110 = l110 + 1) {
			fRec63_perm[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 4; l111 = l111 + 1) {
			fYec53_perm[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 4; l112 = l112 + 1) {
			fYec54_perm[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 8; l113 = l113 + 1) {
			fYec55_perm[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 16; l114 = l114 + 1) {
			fYec56_perm[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 64; l115 = l115 + 1) {
			fYec57[l115] = 0.0f;
		}
		fYec57_idx = 0;
		fYec57_idx_save = 0;
		for (int l116 = 0; l116 < 128; l116 = l116 + 1) {
			fYec58[l116] = 0.0f;
		}
		fYec58_idx = 0;
		fYec58_idx_save = 0;
		for (int l117 = 0; l117 < 256; l117 = l117 + 1) {
			fYec59[l117] = 0.0f;
		}
		fYec59_idx = 0;
		fYec59_idx_save = 0;
		for (int l118 = 0; l118 < 512; l118 = l118 + 1) {
			fYec60[l118] = 0.0f;
		}
		fYec60_idx = 0;
		fYec60_idx_save = 0;
		for (int l119 = 0; l119 < 1024; l119 = l119 + 1) {
			fYec61[l119] = 0.0f;
		}
		fYec61_idx = 0;
		fYec61_idx_save = 0;
		for (int l120 = 0; l120 < 2048; l120 = l120 + 1) {
			fYec62[l120] = 0.0f;
		}
		fYec62_idx = 0;
		fYec62_idx_save = 0;
		for (int l121 = 0; l121 < 4096; l121 = l121 + 1) {
			fYec63[l121] = 0.0f;
		}
		fYec63_idx = 0;
		fYec63_idx_save = 0;
		for (int l122 = 0; l122 < 8192; l122 = l122 + 1) {
			fYec64[l122] = 0.0f;
		}
		fYec64_idx = 0;
		fYec64_idx_save = 0;
		for (int l123 = 0; l123 < 16384; l123 = l123 + 1) {
			fYec65[l123] = 0.0f;
		}
		fYec65_idx = 0;
		fYec65_idx_save = 0;
		for (int l124 = 0; l124 < 32768; l124 = l124 + 1) {
			fYec66[l124] = 0.0f;
		}
		fYec66_idx = 0;
		fYec66_idx_save = 0;
		for (int l125 = 0; l125 < 65536; l125 = l125 + 1) {
			fYec67[l125] = 0.0f;
		}
		fYec67_idx = 0;
		fYec67_idx_save = 0;
		for (int l126 = 0; l126 < 4; l126 = l126 + 1) {
			fRec11_perm[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 4; l127 = l127 + 1) {
			fYec68_perm[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 4; l128 = l128 + 1) {
			fRec74_perm[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 4; l129 = l129 + 1) {
			fRec73_perm[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 4; l130 = l130 + 1) {
			fYec69_perm[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 4; l131 = l131 + 1) {
			fRec72_perm[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 4; l132 = l132 + 1) {
			fRec71_perm[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 4; l133 = l133 + 1) {
			fYec70_perm[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 4; l134 = l134 + 1) {
			fRec78_perm[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 4; l135 = l135 + 1) {
			fRec77_perm[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 4; l136 = l136 + 1) {
			fYec71_perm[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 4; l137 = l137 + 1) {
			fRec76_perm[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 4; l138 = l138 + 1) {
			fRec75_perm[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 4; l139 = l139 + 1) {
			fYec72_perm[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 4; l140 = l140 + 1) {
			fYec73_perm[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 8; l141 = l141 + 1) {
			fYec74_perm[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 16; l142 = l142 + 1) {
			fYec75_perm[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 64; l143 = l143 + 1) {
			fYec76[l143] = 0.0f;
		}
		fYec76_idx = 0;
		fYec76_idx_save = 0;
		for (int l144 = 0; l144 < 128; l144 = l144 + 1) {
			fYec77[l144] = 0.0f;
		}
		fYec77_idx = 0;
		fYec77_idx_save = 0;
		for (int l145 = 0; l145 < 256; l145 = l145 + 1) {
			fYec78[l145] = 0.0f;
		}
		fYec78_idx = 0;
		fYec78_idx_save = 0;
		for (int l146 = 0; l146 < 512; l146 = l146 + 1) {
			fYec79[l146] = 0.0f;
		}
		fYec79_idx = 0;
		fYec79_idx_save = 0;
		for (int l147 = 0; l147 < 1024; l147 = l147 + 1) {
			fYec80[l147] = 0.0f;
		}
		fYec80_idx = 0;
		fYec80_idx_save = 0;
		for (int l148 = 0; l148 < 2048; l148 = l148 + 1) {
			fYec81[l148] = 0.0f;
		}
		fYec81_idx = 0;
		fYec81_idx_save = 0;
		for (int l149 = 0; l149 < 4096; l149 = l149 + 1) {
			fYec82[l149] = 0.0f;
		}
		fYec82_idx = 0;
		fYec82_idx_save = 0;
		for (int l150 = 0; l150 < 8192; l150 = l150 + 1) {
			fYec83[l150] = 0.0f;
		}
		fYec83_idx = 0;
		fYec83_idx_save = 0;
		for (int l151 = 0; l151 < 16384; l151 = l151 + 1) {
			fYec84[l151] = 0.0f;
		}
		fYec84_idx = 0;
		fYec84_idx_save = 0;
		for (int l152 = 0; l152 < 32768; l152 = l152 + 1) {
			fYec85[l152] = 0.0f;
		}
		fYec85_idx = 0;
		fYec85_idx_save = 0;
		for (int l153 = 0; l153 < 65536; l153 = l153 + 1) {
			fYec86[l153] = 0.0f;
		}
		fYec86_idx = 0;
		fYec86_idx_save = 0;
		for (int l154 = 0; l154 < 131072; l154 = l154 + 1) {
			fYec87[l154] = 0.0f;
		}
		fYec87_idx = 0;
		fYec87_idx_save = 0;
		for (int l155 = 0; l155 < 262144; l155 = l155 + 1) {
			fYec88[l155] = 0.0f;
		}
		fYec88_idx = 0;
		fYec88_idx_save = 0;
		for (int l156 = 0; l156 < 4; l156 = l156 + 1) {
			fYec89_perm[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 4; l157 = l157 + 1) {
			fYec90_perm[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 8; l158 = l158 + 1) {
			fYec91_perm[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 16; l159 = l159 + 1) {
			fYec92_perm[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 64; l160 = l160 + 1) {
			fYec93[l160] = 0.0f;
		}
		fYec93_idx = 0;
		fYec93_idx_save = 0;
		for (int l161 = 0; l161 < 128; l161 = l161 + 1) {
			fYec94[l161] = 0.0f;
		}
		fYec94_idx = 0;
		fYec94_idx_save = 0;
		for (int l162 = 0; l162 < 256; l162 = l162 + 1) {
			fYec95[l162] = 0.0f;
		}
		fYec95_idx = 0;
		fYec95_idx_save = 0;
		for (int l163 = 0; l163 < 512; l163 = l163 + 1) {
			fYec96[l163] = 0.0f;
		}
		fYec96_idx = 0;
		fYec96_idx_save = 0;
		for (int l164 = 0; l164 < 1024; l164 = l164 + 1) {
			fYec97[l164] = 0.0f;
		}
		fYec97_idx = 0;
		fYec97_idx_save = 0;
		for (int l165 = 0; l165 < 2048; l165 = l165 + 1) {
			fYec98[l165] = 0.0f;
		}
		fYec98_idx = 0;
		fYec98_idx_save = 0;
		for (int l166 = 0; l166 < 4096; l166 = l166 + 1) {
			fYec99[l166] = 0.0f;
		}
		fYec99_idx = 0;
		fYec99_idx_save = 0;
		for (int l167 = 0; l167 < 8192; l167 = l167 + 1) {
			fYec100[l167] = 0.0f;
		}
		fYec100_idx = 0;
		fYec100_idx_save = 0;
		for (int l168 = 0; l168 < 16384; l168 = l168 + 1) {
			fYec101[l168] = 0.0f;
		}
		fYec101_idx = 0;
		fYec101_idx_save = 0;
		for (int l169 = 0; l169 < 32768; l169 = l169 + 1) {
			fYec102[l169] = 0.0f;
		}
		fYec102_idx = 0;
		fYec102_idx_save = 0;
		for (int l170 = 0; l170 < 65536; l170 = l170 + 1) {
			fYec103[l170] = 0.0f;
		}
		fYec103_idx = 0;
		fYec103_idx_save = 0;
		for (int l171 = 0; l171 < 131072; l171 = l171 + 1) {
			fYec104[l171] = 0.0f;
		}
		fYec104_idx = 0;
		fYec104_idx_save = 0;
		for (int l172 = 0; l172 < 262144; l172 = l172 + 1) {
			fYec105[l172] = 0.0f;
		}
		fYec105_idx = 0;
		fYec105_idx_save = 0;
		for (int l173 = 0; l173 < 4; l173 = l173 + 1) {
			fRec10_perm[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 4; l174 = l174 + 1) {
			fRec9_perm[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 4; l175 = l175 + 1) {
			fRec79_perm[l175] = 0.0f;
		}
		for (int l176 = 0; l176 < 4; l176 = l176 + 1) {
			fRec80_perm[l176] = 0.0f;
		}
		for (int l177 = 0; l177 < 4; l177 = l177 + 1) {
			fRec81_perm[l177] = 0.0f;
		}
		for (int l178 = 0; l178 < 262144; l178 = l178 + 1) {
			fRec83[l178] = 0.0f;
		}
		fRec83_idx = 0;
		fRec83_idx_save = 0;
		for (int l179 = 0; l179 < 4; l179 = l179 + 1) {
			fRec82_perm[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 262144; l180 = l180 + 1) {
			fRec85[l180] = 0.0f;
		}
		fRec85_idx = 0;
		fRec85_idx_save = 0;
		for (int l181 = 0; l181 < 4; l181 = l181 + 1) {
			fRec84_perm[l181] = 0.0f;
		}
		for (int l182 = 0; l182 < 4; l182 = l182 + 1) {
			fRec86_perm[l182] = 0.0f;
		}
		for (int l183 = 0; l183 < 4; l183 = l183 + 1) {
			fRec90_perm[l183] = 0.0f;
		}
		for (int l184 = 0; l184 < 4; l184 = l184 + 1) {
			fRec89_perm[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 4; l185 = l185 + 1) {
			fRec88_perm[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 4; l186 = l186 + 1) {
			fRec87_perm[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 4; l187 = l187 + 1) {
			fRec94_perm[l187] = 0.0f;
		}
		for (int l188 = 0; l188 < 4; l188 = l188 + 1) {
			fRec93_perm[l188] = 0.0f;
		}
		for (int l189 = 0; l189 < 4; l189 = l189 + 1) {
			fRec92_perm[l189] = 0.0f;
		}
		for (int l190 = 0; l190 < 4; l190 = l190 + 1) {
			fRec91_perm[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 4; l191 = l191 + 1) {
			fRec325_perm[l191] = 0.0f;
		}
		for (int l192 = 0; l192 < 4; l192 = l192 + 1) {
			fRec324_perm[l192] = 0.0f;
		}
		for (int l193 = 0; l193 < 4; l193 = l193 + 1) {
			fRec323_perm[l193] = 0.0f;
		}
		for (int l194 = 0; l194 < 4; l194 = l194 + 1) {
			fRec322_perm[l194] = 0.0f;
		}
		for (int l195 = 0; l195 < 4; l195 = l195 + 1) {
			fRec321_perm[l195] = 0.0f;
		}
		for (int l196 = 0; l196 < 4; l196 = l196 + 1) {
			fRec320_perm[l196] = 0.0f;
		}
		for (int l197 = 0; l197 < 4; l197 = l197 + 1) {
			fRec319_perm[l197] = 0.0f;
		}
		for (int l198 = 0; l198 < 4; l198 = l198 + 1) {
			fRec318_perm[l198] = 0.0f;
		}
		for (int l199 = 0; l199 < 4; l199 = l199 + 1) {
			fRec317_perm[l199] = 0.0f;
		}
		for (int l200 = 0; l200 < 4; l200 = l200 + 1) {
			fRec316_perm[l200] = 0.0f;
		}
		for (int l201 = 0; l201 < 4; l201 = l201 + 1) {
			fRec315_perm[l201] = 0.0f;
		}
		for (int l202 = 0; l202 < 4; l202 = l202 + 1) {
			fRec314_perm[l202] = 0.0f;
		}
		for (int l203 = 0; l203 < 4; l203 = l203 + 1) {
			fRec313_perm[l203] = 0.0f;
		}
		for (int l204 = 0; l204 < 4; l204 = l204 + 1) {
			fRec312_perm[l204] = 0.0f;
		}
		for (int l205 = 0; l205 < 4; l205 = l205 + 1) {
			fRec311_perm[l205] = 0.0f;
		}
		for (int l206 = 0; l206 < 4; l206 = l206 + 1) {
			fRec310_perm[l206] = 0.0f;
		}
		for (int l207 = 0; l207 < 4; l207 = l207 + 1) {
			fRec309_perm[l207] = 0.0f;
		}
		for (int l208 = 0; l208 < 4; l208 = l208 + 1) {
			fRec308_perm[l208] = 0.0f;
		}
		for (int l209 = 0; l209 < 4; l209 = l209 + 1) {
			fRec307_perm[l209] = 0.0f;
		}
		for (int l210 = 0; l210 < 4; l210 = l210 + 1) {
			fRec306_perm[l210] = 0.0f;
		}
		for (int l211 = 0; l211 < 4; l211 = l211 + 1) {
			fRec305_perm[l211] = 0.0f;
		}
		for (int l212 = 0; l212 < 4; l212 = l212 + 1) {
			fRec346_perm[l212] = 0.0f;
		}
		for (int l213 = 0; l213 < 4; l213 = l213 + 1) {
			fRec345_perm[l213] = 0.0f;
		}
		for (int l214 = 0; l214 < 4; l214 = l214 + 1) {
			fRec344_perm[l214] = 0.0f;
		}
		for (int l215 = 0; l215 < 4; l215 = l215 + 1) {
			fRec343_perm[l215] = 0.0f;
		}
		for (int l216 = 0; l216 < 4; l216 = l216 + 1) {
			fRec342_perm[l216] = 0.0f;
		}
		for (int l217 = 0; l217 < 4; l217 = l217 + 1) {
			fRec341_perm[l217] = 0.0f;
		}
		for (int l218 = 0; l218 < 4; l218 = l218 + 1) {
			fRec340_perm[l218] = 0.0f;
		}
		for (int l219 = 0; l219 < 4; l219 = l219 + 1) {
			fRec339_perm[l219] = 0.0f;
		}
		for (int l220 = 0; l220 < 4; l220 = l220 + 1) {
			fRec338_perm[l220] = 0.0f;
		}
		for (int l221 = 0; l221 < 4; l221 = l221 + 1) {
			fRec337_perm[l221] = 0.0f;
		}
		for (int l222 = 0; l222 < 4; l222 = l222 + 1) {
			fRec336_perm[l222] = 0.0f;
		}
		for (int l223 = 0; l223 < 4; l223 = l223 + 1) {
			fRec335_perm[l223] = 0.0f;
		}
		for (int l224 = 0; l224 < 4; l224 = l224 + 1) {
			fRec334_perm[l224] = 0.0f;
		}
		for (int l225 = 0; l225 < 4; l225 = l225 + 1) {
			fRec333_perm[l225] = 0.0f;
		}
		for (int l226 = 0; l226 < 4; l226 = l226 + 1) {
			fRec332_perm[l226] = 0.0f;
		}
		for (int l227 = 0; l227 < 4; l227 = l227 + 1) {
			fRec331_perm[l227] = 0.0f;
		}
		for (int l228 = 0; l228 < 4; l228 = l228 + 1) {
			fRec330_perm[l228] = 0.0f;
		}
		for (int l229 = 0; l229 < 4; l229 = l229 + 1) {
			fRec329_perm[l229] = 0.0f;
		}
		for (int l230 = 0; l230 < 4; l230 = l230 + 1) {
			fRec328_perm[l230] = 0.0f;
		}
		for (int l231 = 0; l231 < 4; l231 = l231 + 1) {
			fRec327_perm[l231] = 0.0f;
		}
		for (int l232 = 0; l232 < 4; l232 = l232 + 1) {
			fRec326_perm[l232] = 0.0f;
		}
		for (int l233 = 0; l233 < 4; l233 = l233 + 1) {
			fRec300_perm[l233] = 0.0f;
		}
		for (int l234 = 0; l234 < 4; l234 = l234 + 1) {
			fRec301_perm[l234] = 0.0f;
		}
		for (int l235 = 0; l235 < 4; l235 = l235 + 1) {
			fRec295_perm[l235] = 0.0f;
		}
		for (int l236 = 0; l236 < 4; l236 = l236 + 1) {
			fRec296_perm[l236] = 0.0f;
		}
		for (int l237 = 0; l237 < 4; l237 = l237 + 1) {
			fRec290_perm[l237] = 0.0f;
		}
		for (int l238 = 0; l238 < 4; l238 = l238 + 1) {
			fRec291_perm[l238] = 0.0f;
		}
		for (int l239 = 0; l239 < 4; l239 = l239 + 1) {
			fRec349_perm[l239] = 0.0f;
		}
		for (int l240 = 0; l240 < 4; l240 = l240 + 1) {
			fRec348_perm[l240] = 0.0f;
		}
		for (int l241 = 0; l241 < 4; l241 = l241 + 1) {
			fRec347_perm[l241] = 0.0f;
		}
		for (int l242 = 0; l242 < 4; l242 = l242 + 1) {
			fRec352_perm[l242] = 0.0f;
		}
		for (int l243 = 0; l243 < 4; l243 = l243 + 1) {
			fRec351_perm[l243] = 0.0f;
		}
		for (int l244 = 0; l244 < 4; l244 = l244 + 1) {
			fRec350_perm[l244] = 0.0f;
		}
		for (int l245 = 0; l245 < 4; l245 = l245 + 1) {
			fRec285_perm[l245] = 0.0f;
		}
		for (int l246 = 0; l246 < 4; l246 = l246 + 1) {
			fRec286_perm[l246] = 0.0f;
		}
		for (int l247 = 0; l247 < 4; l247 = l247 + 1) {
			fRec280_perm[l247] = 0.0f;
		}
		for (int l248 = 0; l248 < 4; l248 = l248 + 1) {
			fRec281_perm[l248] = 0.0f;
		}
		for (int l249 = 0; l249 < 4; l249 = l249 + 1) {
			fRec275_perm[l249] = 0.0f;
		}
		for (int l250 = 0; l250 < 4; l250 = l250 + 1) {
			fRec276_perm[l250] = 0.0f;
		}
		for (int l251 = 0; l251 < 4; l251 = l251 + 1) {
			fRec270_perm[l251] = 0.0f;
		}
		for (int l252 = 0; l252 < 4; l252 = l252 + 1) {
			fRec271_perm[l252] = 0.0f;
		}
		for (int l253 = 0; l253 < 4; l253 = l253 + 1) {
			fRec265_perm[l253] = 0.0f;
		}
		for (int l254 = 0; l254 < 4; l254 = l254 + 1) {
			fRec266_perm[l254] = 0.0f;
		}
		for (int l255 = 0; l255 < 4; l255 = l255 + 1) {
			fRec260_perm[l255] = 0.0f;
		}
		for (int l256 = 0; l256 < 4; l256 = l256 + 1) {
			fRec261_perm[l256] = 0.0f;
		}
		for (int l257 = 0; l257 < 4; l257 = l257 + 1) {
			fRec355_perm[l257] = 0.0f;
		}
		for (int l258 = 0; l258 < 4; l258 = l258 + 1) {
			fRec354_perm[l258] = 0.0f;
		}
		for (int l259 = 0; l259 < 4; l259 = l259 + 1) {
			fRec353_perm[l259] = 0.0f;
		}
		for (int l260 = 0; l260 < 4; l260 = l260 + 1) {
			fRec358_perm[l260] = 0.0f;
		}
		for (int l261 = 0; l261 < 4; l261 = l261 + 1) {
			fRec357_perm[l261] = 0.0f;
		}
		for (int l262 = 0; l262 < 4; l262 = l262 + 1) {
			fRec356_perm[l262] = 0.0f;
		}
		for (int l263 = 0; l263 < 4; l263 = l263 + 1) {
			fRec255_perm[l263] = 0.0f;
		}
		for (int l264 = 0; l264 < 4; l264 = l264 + 1) {
			fRec256_perm[l264] = 0.0f;
		}
		for (int l265 = 0; l265 < 4; l265 = l265 + 1) {
			fRec250_perm[l265] = 0.0f;
		}
		for (int l266 = 0; l266 < 4; l266 = l266 + 1) {
			fRec251_perm[l266] = 0.0f;
		}
		for (int l267 = 0; l267 < 4; l267 = l267 + 1) {
			fRec245_perm[l267] = 0.0f;
		}
		for (int l268 = 0; l268 < 4; l268 = l268 + 1) {
			fRec246_perm[l268] = 0.0f;
		}
		for (int l269 = 0; l269 < 4; l269 = l269 + 1) {
			fRec240_perm[l269] = 0.0f;
		}
		for (int l270 = 0; l270 < 4; l270 = l270 + 1) {
			fRec241_perm[l270] = 0.0f;
		}
		for (int l271 = 0; l271 < 4; l271 = l271 + 1) {
			fRec235_perm[l271] = 0.0f;
		}
		for (int l272 = 0; l272 < 4; l272 = l272 + 1) {
			fRec236_perm[l272] = 0.0f;
		}
		for (int l273 = 0; l273 < 4; l273 = l273 + 1) {
			fRec230_perm[l273] = 0.0f;
		}
		for (int l274 = 0; l274 < 4; l274 = l274 + 1) {
			fRec231_perm[l274] = 0.0f;
		}
		for (int l275 = 0; l275 < 4; l275 = l275 + 1) {
			fRec361_perm[l275] = 0.0f;
		}
		for (int l276 = 0; l276 < 4; l276 = l276 + 1) {
			fRec360_perm[l276] = 0.0f;
		}
		for (int l277 = 0; l277 < 4; l277 = l277 + 1) {
			fRec359_perm[l277] = 0.0f;
		}
		for (int l278 = 0; l278 < 4; l278 = l278 + 1) {
			fRec364_perm[l278] = 0.0f;
		}
		for (int l279 = 0; l279 < 4; l279 = l279 + 1) {
			fRec363_perm[l279] = 0.0f;
		}
		for (int l280 = 0; l280 < 4; l280 = l280 + 1) {
			fRec362_perm[l280] = 0.0f;
		}
		for (int l281 = 0; l281 < 4; l281 = l281 + 1) {
			fRec225_perm[l281] = 0.0f;
		}
		for (int l282 = 0; l282 < 4; l282 = l282 + 1) {
			fRec226_perm[l282] = 0.0f;
		}
		for (int l283 = 0; l283 < 4; l283 = l283 + 1) {
			fRec220_perm[l283] = 0.0f;
		}
		for (int l284 = 0; l284 < 4; l284 = l284 + 1) {
			fRec221_perm[l284] = 0.0f;
		}
		for (int l285 = 0; l285 < 4; l285 = l285 + 1) {
			fRec215_perm[l285] = 0.0f;
		}
		for (int l286 = 0; l286 < 4; l286 = l286 + 1) {
			fRec216_perm[l286] = 0.0f;
		}
		for (int l287 = 0; l287 < 4; l287 = l287 + 1) {
			fRec210_perm[l287] = 0.0f;
		}
		for (int l288 = 0; l288 < 4; l288 = l288 + 1) {
			fRec211_perm[l288] = 0.0f;
		}
		for (int l289 = 0; l289 < 4; l289 = l289 + 1) {
			fRec205_perm[l289] = 0.0f;
		}
		for (int l290 = 0; l290 < 4; l290 = l290 + 1) {
			fRec206_perm[l290] = 0.0f;
		}
		for (int l291 = 0; l291 < 4; l291 = l291 + 1) {
			fRec200_perm[l291] = 0.0f;
		}
		for (int l292 = 0; l292 < 4; l292 = l292 + 1) {
			fRec201_perm[l292] = 0.0f;
		}
		for (int l293 = 0; l293 < 4; l293 = l293 + 1) {
			fRec367_perm[l293] = 0.0f;
		}
		for (int l294 = 0; l294 < 4; l294 = l294 + 1) {
			fRec366_perm[l294] = 0.0f;
		}
		for (int l295 = 0; l295 < 4; l295 = l295 + 1) {
			fRec365_perm[l295] = 0.0f;
		}
		for (int l296 = 0; l296 < 4; l296 = l296 + 1) {
			fRec370_perm[l296] = 0.0f;
		}
		for (int l297 = 0; l297 < 4; l297 = l297 + 1) {
			fRec369_perm[l297] = 0.0f;
		}
		for (int l298 = 0; l298 < 4; l298 = l298 + 1) {
			fRec368_perm[l298] = 0.0f;
		}
		for (int l299 = 0; l299 < 4; l299 = l299 + 1) {
			fRec195_perm[l299] = 0.0f;
		}
		for (int l300 = 0; l300 < 4; l300 = l300 + 1) {
			fRec196_perm[l300] = 0.0f;
		}
		for (int l301 = 0; l301 < 4; l301 = l301 + 1) {
			fRec190_perm[l301] = 0.0f;
		}
		for (int l302 = 0; l302 < 4; l302 = l302 + 1) {
			fRec191_perm[l302] = 0.0f;
		}
		for (int l303 = 0; l303 < 4; l303 = l303 + 1) {
			fRec185_perm[l303] = 0.0f;
		}
		for (int l304 = 0; l304 < 4; l304 = l304 + 1) {
			fRec186_perm[l304] = 0.0f;
		}
		for (int l305 = 0; l305 < 4; l305 = l305 + 1) {
			fRec180_perm[l305] = 0.0f;
		}
		for (int l306 = 0; l306 < 4; l306 = l306 + 1) {
			fRec181_perm[l306] = 0.0f;
		}
		for (int l307 = 0; l307 < 4; l307 = l307 + 1) {
			fRec175_perm[l307] = 0.0f;
		}
		for (int l308 = 0; l308 < 4; l308 = l308 + 1) {
			fRec176_perm[l308] = 0.0f;
		}
		for (int l309 = 0; l309 < 4; l309 = l309 + 1) {
			fRec170_perm[l309] = 0.0f;
		}
		for (int l310 = 0; l310 < 4; l310 = l310 + 1) {
			fRec171_perm[l310] = 0.0f;
		}
		for (int l311 = 0; l311 < 4; l311 = l311 + 1) {
			fRec373_perm[l311] = 0.0f;
		}
		for (int l312 = 0; l312 < 4; l312 = l312 + 1) {
			fRec372_perm[l312] = 0.0f;
		}
		for (int l313 = 0; l313 < 4; l313 = l313 + 1) {
			fRec371_perm[l313] = 0.0f;
		}
		for (int l314 = 0; l314 < 4; l314 = l314 + 1) {
			fRec376_perm[l314] = 0.0f;
		}
		for (int l315 = 0; l315 < 4; l315 = l315 + 1) {
			fRec375_perm[l315] = 0.0f;
		}
		for (int l316 = 0; l316 < 4; l316 = l316 + 1) {
			fRec374_perm[l316] = 0.0f;
		}
		for (int l317 = 0; l317 < 4; l317 = l317 + 1) {
			fRec165_perm[l317] = 0.0f;
		}
		for (int l318 = 0; l318 < 4; l318 = l318 + 1) {
			fRec166_perm[l318] = 0.0f;
		}
		for (int l319 = 0; l319 < 4; l319 = l319 + 1) {
			fRec160_perm[l319] = 0.0f;
		}
		for (int l320 = 0; l320 < 4; l320 = l320 + 1) {
			fRec161_perm[l320] = 0.0f;
		}
		for (int l321 = 0; l321 < 4; l321 = l321 + 1) {
			fRec155_perm[l321] = 0.0f;
		}
		for (int l322 = 0; l322 < 4; l322 = l322 + 1) {
			fRec156_perm[l322] = 0.0f;
		}
		for (int l323 = 0; l323 < 4; l323 = l323 + 1) {
			fRec150_perm[l323] = 0.0f;
		}
		for (int l324 = 0; l324 < 4; l324 = l324 + 1) {
			fRec151_perm[l324] = 0.0f;
		}
		for (int l325 = 0; l325 < 4; l325 = l325 + 1) {
			fRec145_perm[l325] = 0.0f;
		}
		for (int l326 = 0; l326 < 4; l326 = l326 + 1) {
			fRec146_perm[l326] = 0.0f;
		}
		for (int l327 = 0; l327 < 4; l327 = l327 + 1) {
			fRec140_perm[l327] = 0.0f;
		}
		for (int l328 = 0; l328 < 4; l328 = l328 + 1) {
			fRec141_perm[l328] = 0.0f;
		}
		for (int l329 = 0; l329 < 4; l329 = l329 + 1) {
			fRec379_perm[l329] = 0.0f;
		}
		for (int l330 = 0; l330 < 4; l330 = l330 + 1) {
			fRec378_perm[l330] = 0.0f;
		}
		for (int l331 = 0; l331 < 4; l331 = l331 + 1) {
			fRec377_perm[l331] = 0.0f;
		}
		for (int l332 = 0; l332 < 4; l332 = l332 + 1) {
			fRec382_perm[l332] = 0.0f;
		}
		for (int l333 = 0; l333 < 4; l333 = l333 + 1) {
			fRec381_perm[l333] = 0.0f;
		}
		for (int l334 = 0; l334 < 4; l334 = l334 + 1) {
			fRec380_perm[l334] = 0.0f;
		}
		for (int l335 = 0; l335 < 4; l335 = l335 + 1) {
			fRec135_perm[l335] = 0.0f;
		}
		for (int l336 = 0; l336 < 4; l336 = l336 + 1) {
			fRec136_perm[l336] = 0.0f;
		}
		for (int l337 = 0; l337 < 4; l337 = l337 + 1) {
			fRec130_perm[l337] = 0.0f;
		}
		for (int l338 = 0; l338 < 4; l338 = l338 + 1) {
			fRec131_perm[l338] = 0.0f;
		}
		for (int l339 = 0; l339 < 4; l339 = l339 + 1) {
			fRec125_perm[l339] = 0.0f;
		}
		for (int l340 = 0; l340 < 4; l340 = l340 + 1) {
			fRec126_perm[l340] = 0.0f;
		}
		for (int l341 = 0; l341 < 4; l341 = l341 + 1) {
			fRec120_perm[l341] = 0.0f;
		}
		for (int l342 = 0; l342 < 4; l342 = l342 + 1) {
			fRec121_perm[l342] = 0.0f;
		}
		for (int l343 = 0; l343 < 4; l343 = l343 + 1) {
			fRec115_perm[l343] = 0.0f;
		}
		for (int l344 = 0; l344 < 4; l344 = l344 + 1) {
			fRec116_perm[l344] = 0.0f;
		}
		for (int l345 = 0; l345 < 4; l345 = l345 + 1) {
			fRec110_perm[l345] = 0.0f;
		}
		for (int l346 = 0; l346 < 4; l346 = l346 + 1) {
			fRec111_perm[l346] = 0.0f;
		}
		for (int l347 = 0; l347 < 4; l347 = l347 + 1) {
			fRec105_perm[l347] = 0.0f;
		}
		for (int l348 = 0; l348 < 4; l348 = l348 + 1) {
			fRec106_perm[l348] = 0.0f;
		}
		for (int l349 = 0; l349 < 4; l349 = l349 + 1) {
			fRec100_perm[l349] = 0.0f;
		}
		for (int l350 = 0; l350 < 4; l350 = l350 + 1) {
			fRec101_perm[l350] = 0.0f;
		}
		for (int l351 = 0; l351 < 4; l351 = l351 + 1) {
			fRec95_perm[l351] = 0.0f;
		}
		for (int l352 = 0; l352 < 4; l352 = l352 + 1) {
			fRec96_perm[l352] = 0.0f;
		}
		for (int l353 = 0; l353 < 4; l353 = l353 + 1) {
			fRec588_perm[l353] = 0.0f;
		}
		for (int l354 = 0; l354 < 4; l354 = l354 + 1) {
			fRec589_perm[l354] = 0.0f;
		}
		for (int l355 = 0; l355 < 4; l355 = l355 + 1) {
			fRec583_perm[l355] = 0.0f;
		}
		for (int l356 = 0; l356 < 4; l356 = l356 + 1) {
			fRec584_perm[l356] = 0.0f;
		}
		for (int l357 = 0; l357 < 4; l357 = l357 + 1) {
			fRec578_perm[l357] = 0.0f;
		}
		for (int l358 = 0; l358 < 4; l358 = l358 + 1) {
			fRec579_perm[l358] = 0.0f;
		}
		for (int l359 = 0; l359 < 4; l359 = l359 + 1) {
			fRec573_perm[l359] = 0.0f;
		}
		for (int l360 = 0; l360 < 4; l360 = l360 + 1) {
			fRec574_perm[l360] = 0.0f;
		}
		for (int l361 = 0; l361 < 4; l361 = l361 + 1) {
			fRec568_perm[l361] = 0.0f;
		}
		for (int l362 = 0; l362 < 4; l362 = l362 + 1) {
			fRec569_perm[l362] = 0.0f;
		}
		for (int l363 = 0; l363 < 4; l363 = l363 + 1) {
			fRec563_perm[l363] = 0.0f;
		}
		for (int l364 = 0; l364 < 4; l364 = l364 + 1) {
			fRec564_perm[l364] = 0.0f;
		}
		for (int l365 = 0; l365 < 4; l365 = l365 + 1) {
			fRec558_perm[l365] = 0.0f;
		}
		for (int l366 = 0; l366 < 4; l366 = l366 + 1) {
			fRec559_perm[l366] = 0.0f;
		}
		for (int l367 = 0; l367 < 4; l367 = l367 + 1) {
			fRec553_perm[l367] = 0.0f;
		}
		for (int l368 = 0; l368 < 4; l368 = l368 + 1) {
			fRec554_perm[l368] = 0.0f;
		}
		for (int l369 = 0; l369 < 4; l369 = l369 + 1) {
			fRec548_perm[l369] = 0.0f;
		}
		for (int l370 = 0; l370 < 4; l370 = l370 + 1) {
			fRec549_perm[l370] = 0.0f;
		}
		for (int l371 = 0; l371 < 4; l371 = l371 + 1) {
			fRec543_perm[l371] = 0.0f;
		}
		for (int l372 = 0; l372 < 4; l372 = l372 + 1) {
			fRec544_perm[l372] = 0.0f;
		}
		for (int l373 = 0; l373 < 4; l373 = l373 + 1) {
			fRec538_perm[l373] = 0.0f;
		}
		for (int l374 = 0; l374 < 4; l374 = l374 + 1) {
			fRec539_perm[l374] = 0.0f;
		}
		for (int l375 = 0; l375 < 4; l375 = l375 + 1) {
			fRec533_perm[l375] = 0.0f;
		}
		for (int l376 = 0; l376 < 4; l376 = l376 + 1) {
			fRec534_perm[l376] = 0.0f;
		}
		for (int l377 = 0; l377 < 4; l377 = l377 + 1) {
			fRec528_perm[l377] = 0.0f;
		}
		for (int l378 = 0; l378 < 4; l378 = l378 + 1) {
			fRec529_perm[l378] = 0.0f;
		}
		for (int l379 = 0; l379 < 4; l379 = l379 + 1) {
			fRec523_perm[l379] = 0.0f;
		}
		for (int l380 = 0; l380 < 4; l380 = l380 + 1) {
			fRec524_perm[l380] = 0.0f;
		}
		for (int l381 = 0; l381 < 4; l381 = l381 + 1) {
			fRec518_perm[l381] = 0.0f;
		}
		for (int l382 = 0; l382 < 4; l382 = l382 + 1) {
			fRec519_perm[l382] = 0.0f;
		}
		for (int l383 = 0; l383 < 4; l383 = l383 + 1) {
			fRec513_perm[l383] = 0.0f;
		}
		for (int l384 = 0; l384 < 4; l384 = l384 + 1) {
			fRec514_perm[l384] = 0.0f;
		}
		for (int l385 = 0; l385 < 4; l385 = l385 + 1) {
			fRec508_perm[l385] = 0.0f;
		}
		for (int l386 = 0; l386 < 4; l386 = l386 + 1) {
			fRec509_perm[l386] = 0.0f;
		}
		for (int l387 = 0; l387 < 4; l387 = l387 + 1) {
			fRec503_perm[l387] = 0.0f;
		}
		for (int l388 = 0; l388 < 4; l388 = l388 + 1) {
			fRec504_perm[l388] = 0.0f;
		}
		for (int l389 = 0; l389 < 4; l389 = l389 + 1) {
			fRec498_perm[l389] = 0.0f;
		}
		for (int l390 = 0; l390 < 4; l390 = l390 + 1) {
			fRec499_perm[l390] = 0.0f;
		}
		for (int l391 = 0; l391 < 4; l391 = l391 + 1) {
			fRec493_perm[l391] = 0.0f;
		}
		for (int l392 = 0; l392 < 4; l392 = l392 + 1) {
			fRec494_perm[l392] = 0.0f;
		}
		for (int l393 = 0; l393 < 4; l393 = l393 + 1) {
			fRec488_perm[l393] = 0.0f;
		}
		for (int l394 = 0; l394 < 4; l394 = l394 + 1) {
			fRec489_perm[l394] = 0.0f;
		}
		for (int l395 = 0; l395 < 4; l395 = l395 + 1) {
			fRec483_perm[l395] = 0.0f;
		}
		for (int l396 = 0; l396 < 4; l396 = l396 + 1) {
			fRec484_perm[l396] = 0.0f;
		}
		for (int l397 = 0; l397 < 4; l397 = l397 + 1) {
			fRec478_perm[l397] = 0.0f;
		}
		for (int l398 = 0; l398 < 4; l398 = l398 + 1) {
			fRec479_perm[l398] = 0.0f;
		}
		for (int l399 = 0; l399 < 4; l399 = l399 + 1) {
			fRec473_perm[l399] = 0.0f;
		}
		for (int l400 = 0; l400 < 4; l400 = l400 + 1) {
			fRec474_perm[l400] = 0.0f;
		}
		for (int l401 = 0; l401 < 4; l401 = l401 + 1) {
			fRec468_perm[l401] = 0.0f;
		}
		for (int l402 = 0; l402 < 4; l402 = l402 + 1) {
			fRec469_perm[l402] = 0.0f;
		}
		for (int l403 = 0; l403 < 4; l403 = l403 + 1) {
			fRec463_perm[l403] = 0.0f;
		}
		for (int l404 = 0; l404 < 4; l404 = l404 + 1) {
			fRec464_perm[l404] = 0.0f;
		}
		for (int l405 = 0; l405 < 4; l405 = l405 + 1) {
			fRec458_perm[l405] = 0.0f;
		}
		for (int l406 = 0; l406 < 4; l406 = l406 + 1) {
			fRec459_perm[l406] = 0.0f;
		}
		for (int l407 = 0; l407 < 4; l407 = l407 + 1) {
			fRec453_perm[l407] = 0.0f;
		}
		for (int l408 = 0; l408 < 4; l408 = l408 + 1) {
			fRec454_perm[l408] = 0.0f;
		}
		for (int l409 = 0; l409 < 4; l409 = l409 + 1) {
			fRec448_perm[l409] = 0.0f;
		}
		for (int l410 = 0; l410 < 4; l410 = l410 + 1) {
			fRec449_perm[l410] = 0.0f;
		}
		for (int l411 = 0; l411 < 4; l411 = l411 + 1) {
			fRec443_perm[l411] = 0.0f;
		}
		for (int l412 = 0; l412 < 4; l412 = l412 + 1) {
			fRec444_perm[l412] = 0.0f;
		}
		for (int l413 = 0; l413 < 4; l413 = l413 + 1) {
			fRec438_perm[l413] = 0.0f;
		}
		for (int l414 = 0; l414 < 4; l414 = l414 + 1) {
			fRec439_perm[l414] = 0.0f;
		}
		for (int l415 = 0; l415 < 4; l415 = l415 + 1) {
			fRec433_perm[l415] = 0.0f;
		}
		for (int l416 = 0; l416 < 4; l416 = l416 + 1) {
			fRec434_perm[l416] = 0.0f;
		}
		for (int l417 = 0; l417 < 4; l417 = l417 + 1) {
			fRec428_perm[l417] = 0.0f;
		}
		for (int l418 = 0; l418 < 4; l418 = l418 + 1) {
			fRec429_perm[l418] = 0.0f;
		}
		for (int l419 = 0; l419 < 4; l419 = l419 + 1) {
			fRec423_perm[l419] = 0.0f;
		}
		for (int l420 = 0; l420 < 4; l420 = l420 + 1) {
			fRec424_perm[l420] = 0.0f;
		}
		for (int l421 = 0; l421 < 4; l421 = l421 + 1) {
			fRec418_perm[l421] = 0.0f;
		}
		for (int l422 = 0; l422 < 4; l422 = l422 + 1) {
			fRec419_perm[l422] = 0.0f;
		}
		for (int l423 = 0; l423 < 4; l423 = l423 + 1) {
			fRec413_perm[l423] = 0.0f;
		}
		for (int l424 = 0; l424 < 4; l424 = l424 + 1) {
			fRec414_perm[l424] = 0.0f;
		}
		for (int l425 = 0; l425 < 4; l425 = l425 + 1) {
			fRec408_perm[l425] = 0.0f;
		}
		for (int l426 = 0; l426 < 4; l426 = l426 + 1) {
			fRec409_perm[l426] = 0.0f;
		}
		for (int l427 = 0; l427 < 4; l427 = l427 + 1) {
			fRec403_perm[l427] = 0.0f;
		}
		for (int l428 = 0; l428 < 4; l428 = l428 + 1) {
			fRec404_perm[l428] = 0.0f;
		}
		for (int l429 = 0; l429 < 4; l429 = l429 + 1) {
			fRec398_perm[l429] = 0.0f;
		}
		for (int l430 = 0; l430 < 4; l430 = l430 + 1) {
			fRec399_perm[l430] = 0.0f;
		}
		for (int l431 = 0; l431 < 4; l431 = l431 + 1) {
			fRec393_perm[l431] = 0.0f;
		}
		for (int l432 = 0; l432 < 4; l432 = l432 + 1) {
			fRec394_perm[l432] = 0.0f;
		}
		for (int l433 = 0; l433 < 4; l433 = l433 + 1) {
			fRec388_perm[l433] = 0.0f;
		}
		for (int l434 = 0; l434 < 4; l434 = l434 + 1) {
			fRec389_perm[l434] = 0.0f;
		}
		for (int l435 = 0; l435 < 4; l435 = l435 + 1) {
			fRec383_perm[l435] = 0.0f;
		}
		for (int l436 = 0; l436 < 4; l436 = l436 + 1) {
			fRec384_perm[l436] = 0.0f;
		}
		for (int l437 = 0; l437 < 131072; l437 = l437 + 1) {
			fRec594[l437] = 0.0f;
		}
		fRec594_idx = 0;
		fRec594_idx_save = 0;
		for (int l438 = 0; l438 < 4; l438 = l438 + 1) {
			fRec593_perm[l438] = 0.0f;
		}
		for (int l439 = 0; l439 < 131072; l439 = l439 + 1) {
			fRec596[l439] = 0.0f;
		}
		fRec596_idx = 0;
		fRec596_idx_save = 0;
		for (int l440 = 0; l440 < 4; l440 = l440 + 1) {
			fRec595_perm[l440] = 0.0f;
		}
		for (int l441 = 0; l441 < 4; l441 = l441 + 1) {
			fRec5_perm[l441] = 0.0f;
		}
		for (int l442 = 0; l442 < 4; l442 = l442 + 1) {
			fRec6_perm[l442] = 0.0f;
		}
		for (int l443 = 0; l443 < 4; l443 = l443 + 1) {
			fRec597_perm[l443] = 0.0f;
		}
		for (int l444 = 0; l444 < 4; l444 = l444 + 1) {
			fRec598_perm[l444] = 0.0f;
		}
		for (int l445 = 0; l445 < 4; l445 = l445 + 1) {
			fRec599_perm[l445] = 0.0f;
		}
		for (int l446 = 0; l446 < 4; l446 = l446 + 1) {
			fRec600_perm[l446] = 0.0f;
		}
		for (int l447 = 0; l447 < 4; l447 = l447 + 1) {
			fRec601_perm[l447] = 0.0f;
		}
		for (int l448 = 0; l448 < 4; l448 = l448 + 1) {
			fRec3_perm[l448] = 0.0f;
		}
		for (int l449 = 0; l449 < 4; l449 = l449 + 1) {
			fRec4_perm[l449] = 0.0f;
		}
		for (int l450 = 0; l450 < 4; l450 = l450 + 1) {
			fRec1_perm[l450] = 0.0f;
		}
		for (int l451 = 0; l451 < 4; l451 = l451 + 1) {
			fRec2_perm[l451] = 0.0f;
		}
		for (int l452 = 0; l452 < 4; l452 = l452 + 1) {
			fYec106_perm[l452] = 0.0f;
		}
		for (int l453 = 0; l453 < 4; l453 = l453 + 1) {
			fRec602_perm[l453] = 0.0f;
		}
		for (int l454 = 0; l454 < 4; l454 = l454 + 1) {
			fYec107_perm[l454] = 0.0f;
		}
		for (int l455 = 0; l455 < 4; l455 = l455 + 1) {
			fRec606_perm[l455] = 0.0f;
		}
		for (int l456 = 0; l456 < 4; l456 = l456 + 1) {
			fRec605_perm[l456] = 0.0f;
		}
		for (int l457 = 0; l457 < 4; l457 = l457 + 1) {
			fYec108_perm[l457] = 0.0f;
		}
		for (int l458 = 0; l458 < 4; l458 = l458 + 1) {
			fRec604_perm[l458] = 0.0f;
		}
		for (int l459 = 0; l459 < 4; l459 = l459 + 1) {
			fRec603_perm[l459] = 0.0f;
		}
		for (int l460 = 0; l460 < 4; l460 = l460 + 1) {
			fYec109_perm[l460] = 0.0f;
		}
		for (int l461 = 0; l461 < 4; l461 = l461 + 1) {
			fYec110_perm[l461] = 0.0f;
		}
		for (int l462 = 0; l462 < 4; l462 = l462 + 1) {
			fRec610_perm[l462] = 0.0f;
		}
		for (int l463 = 0; l463 < 4; l463 = l463 + 1) {
			fRec609_perm[l463] = 0.0f;
		}
		for (int l464 = 0; l464 < 4; l464 = l464 + 1) {
			fYec111_perm[l464] = 0.0f;
		}
		for (int l465 = 0; l465 < 4; l465 = l465 + 1) {
			fRec608_perm[l465] = 0.0f;
		}
		for (int l466 = 0; l466 < 4; l466 = l466 + 1) {
			fRec607_perm[l466] = 0.0f;
		}
		for (int l467 = 0; l467 < 4; l467 = l467 + 1) {
			fYec112_perm[l467] = 0.0f;
		}
		for (int l468 = 0; l468 < 4; l468 = l468 + 1) {
			fYec113_perm[l468] = 0.0f;
		}
		for (int l469 = 0; l469 < 8; l469 = l469 + 1) {
			fYec114_perm[l469] = 0.0f;
		}
		for (int l470 = 0; l470 < 16; l470 = l470 + 1) {
			fYec115_perm[l470] = 0.0f;
		}
		for (int l471 = 0; l471 < 64; l471 = l471 + 1) {
			fYec116[l471] = 0.0f;
		}
		fYec116_idx = 0;
		fYec116_idx_save = 0;
		for (int l472 = 0; l472 < 128; l472 = l472 + 1) {
			fYec117[l472] = 0.0f;
		}
		fYec117_idx = 0;
		fYec117_idx_save = 0;
		for (int l473 = 0; l473 < 256; l473 = l473 + 1) {
			fYec118[l473] = 0.0f;
		}
		fYec118_idx = 0;
		fYec118_idx_save = 0;
		for (int l474 = 0; l474 < 512; l474 = l474 + 1) {
			fYec119[l474] = 0.0f;
		}
		fYec119_idx = 0;
		fYec119_idx_save = 0;
		for (int l475 = 0; l475 < 1024; l475 = l475 + 1) {
			fYec120[l475] = 0.0f;
		}
		fYec120_idx = 0;
		fYec120_idx_save = 0;
		for (int l476 = 0; l476 < 2048; l476 = l476 + 1) {
			fYec121[l476] = 0.0f;
		}
		fYec121_idx = 0;
		fYec121_idx_save = 0;
		for (int l477 = 0; l477 < 4096; l477 = l477 + 1) {
			fYec122[l477] = 0.0f;
		}
		fYec122_idx = 0;
		fYec122_idx_save = 0;
		for (int l478 = 0; l478 < 8192; l478 = l478 + 1) {
			fYec123[l478] = 0.0f;
		}
		fYec123_idx = 0;
		fYec123_idx_save = 0;
		for (int l479 = 0; l479 < 16384; l479 = l479 + 1) {
			fYec124[l479] = 0.0f;
		}
		fYec124_idx = 0;
		fYec124_idx_save = 0;
		for (int l480 = 0; l480 < 32768; l480 = l480 + 1) {
			fYec125[l480] = 0.0f;
		}
		fYec125_idx = 0;
		fYec125_idx_save = 0;
		for (int l481 = 0; l481 < 65536; l481 = l481 + 1) {
			fYec126[l481] = 0.0f;
		}
		fYec126_idx = 0;
		fYec126_idx_save = 0;
		for (int l482 = 0; l482 < 131072; l482 = l482 + 1) {
			fYec127[l482] = 0.0f;
		}
		fYec127_idx = 0;
		fYec127_idx_save = 0;
		for (int l483 = 0; l483 < 262144; l483 = l483 + 1) {
			fYec128[l483] = 0.0f;
		}
		fYec128_idx = 0;
		fYec128_idx_save = 0;
		for (int l484 = 0; l484 < 524288; l484 = l484 + 1) {
			fYec129[l484] = 0.0f;
		}
		fYec129_idx = 0;
		fYec129_idx_save = 0;
		for (int l485 = 0; l485 < 1048576; l485 = l485 + 1) {
			fYec130[l485] = 0.0f;
		}
		fYec130_idx = 0;
		fYec130_idx_save = 0;
		for (int l486 = 0; l486 < 2097152; l486 = l486 + 1) {
			fYec131[l486] = 0.0f;
		}
		fYec131_idx = 0;
		fYec131_idx_save = 0;
		for (int l487 = 0; l487 < 4; l487 = l487 + 1) {
			fYec132_perm[l487] = 0.0f;
		}
		for (int l488 = 0; l488 < 4; l488 = l488 + 1) {
			fYec133_perm[l488] = 0.0f;
		}
		for (int l489 = 0; l489 < 8; l489 = l489 + 1) {
			fYec134_perm[l489] = 0.0f;
		}
		for (int l490 = 0; l490 < 16; l490 = l490 + 1) {
			fYec135_perm[l490] = 0.0f;
		}
		for (int l491 = 0; l491 < 64; l491 = l491 + 1) {
			fYec136[l491] = 0.0f;
		}
		fYec136_idx = 0;
		fYec136_idx_save = 0;
		for (int l492 = 0; l492 < 128; l492 = l492 + 1) {
			fYec137[l492] = 0.0f;
		}
		fYec137_idx = 0;
		fYec137_idx_save = 0;
		for (int l493 = 0; l493 < 256; l493 = l493 + 1) {
			fYec138[l493] = 0.0f;
		}
		fYec138_idx = 0;
		fYec138_idx_save = 0;
		for (int l494 = 0; l494 < 512; l494 = l494 + 1) {
			fYec139[l494] = 0.0f;
		}
		fYec139_idx = 0;
		fYec139_idx_save = 0;
		for (int l495 = 0; l495 < 1024; l495 = l495 + 1) {
			fYec140[l495] = 0.0f;
		}
		fYec140_idx = 0;
		fYec140_idx_save = 0;
		for (int l496 = 0; l496 < 2048; l496 = l496 + 1) {
			fYec141[l496] = 0.0f;
		}
		fYec141_idx = 0;
		fYec141_idx_save = 0;
		for (int l497 = 0; l497 < 4096; l497 = l497 + 1) {
			fYec142[l497] = 0.0f;
		}
		fYec142_idx = 0;
		fYec142_idx_save = 0;
		for (int l498 = 0; l498 < 8192; l498 = l498 + 1) {
			fYec143[l498] = 0.0f;
		}
		fYec143_idx = 0;
		fYec143_idx_save = 0;
		for (int l499 = 0; l499 < 16384; l499 = l499 + 1) {
			fYec144[l499] = 0.0f;
		}
		fYec144_idx = 0;
		fYec144_idx_save = 0;
		for (int l500 = 0; l500 < 32768; l500 = l500 + 1) {
			fYec145[l500] = 0.0f;
		}
		fYec145_idx = 0;
		fYec145_idx_save = 0;
		for (int l501 = 0; l501 < 65536; l501 = l501 + 1) {
			fYec146[l501] = 0.0f;
		}
		fYec146_idx = 0;
		fYec146_idx_save = 0;
		for (int l502 = 0; l502 < 131072; l502 = l502 + 1) {
			fYec147[l502] = 0.0f;
		}
		fYec147_idx = 0;
		fYec147_idx_save = 0;
		for (int l503 = 0; l503 < 262144; l503 = l503 + 1) {
			fYec148[l503] = 0.0f;
		}
		fYec148_idx = 0;
		fYec148_idx_save = 0;
		for (int l504 = 0; l504 < 524288; l504 = l504 + 1) {
			fYec149[l504] = 0.0f;
		}
		fYec149_idx = 0;
		fYec149_idx_save = 0;
		for (int l505 = 0; l505 < 1048576; l505 = l505 + 1) {
			fYec150[l505] = 0.0f;
		}
		fYec150_idx = 0;
		fYec150_idx_save = 0;
		for (int l506 = 0; l506 < 2097152; l506 = l506 + 1) {
			fYec151[l506] = 0.0f;
		}
		fYec151_idx = 0;
		fYec151_idx_save = 0;
		for (int l507 = 0; l507 < 4; l507 = l507 + 1) {
			fRec611_perm[l507] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("master_me");
		ui_interface->declare(&fCheckbox0, "symbol", "global_bypass");
		ui_interface->addCheckButton("global bypass", &fCheckbox0);
		ui_interface->openVerticalBox("master_me");
		ui_interface->openHorizontalBox("easy");
		ui_interface->declare(&fVbargraph0, "0", "");
		ui_interface->declare(&fVbargraph0, "symbol", "peakmeter_in_l");
		ui_interface->declare(&fVbargraph0, "unit", "dB");
		ui_interface->addVerticalBargraph("in L", &fVbargraph0, FAUSTFLOAT(-70.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph1, "1", "");
		ui_interface->declare(&fVbargraph1, "symbol", "peakmeter_in_r");
		ui_interface->declare(&fVbargraph1, "unit", "dB");
		ui_interface->addVerticalBargraph("in R", &fVbargraph1, FAUSTFLOAT(-70.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph2, "2", "");
		ui_interface->declare(&fVbargraph2, "symbol", "lufs_in");
		ui_interface->declare(&fVbargraph2, "unit", "dB");
		ui_interface->addVerticalBargraph("in lufs-s", &fVbargraph2, FAUSTFLOAT(-70.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVslider14, "3", "");
		ui_interface->declare(&fVslider14, "integer", "");
		ui_interface->declare(&fVslider14, "symbol", "target");
		ui_interface->declare(&fVslider14, "unit", "dB");
		ui_interface->addVerticalSlider("Target", &fVslider14, FAUSTFLOAT(-18.0f), FAUSTFLOAT(-50.0f), FAUSTFLOAT(-2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph5, "4", "");
		ui_interface->declare(&fVbargraph5, "symbol", "leveler_gain");
		ui_interface->declare(&fVbargraph5, "unit", "dB");
		ui_interface->addVerticalBargraph("leveler gain", &fVbargraph5, FAUSTFLOAT(-50.0f), FAUSTFLOAT(50.0f));
		ui_interface->declare(&fVbargraph27, "7", "");
		ui_interface->declare(&fVbargraph27, "symbol", "lufs_out");
		ui_interface->declare(&fVbargraph27, "unit", "dB");
		ui_interface->addVerticalBargraph("out lufs-s", &fVbargraph27, FAUSTFLOAT(-70.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph26, "8", "");
		ui_interface->declare(&fVbargraph26, "symbol", "peakmeter_out_l");
		ui_interface->declare(&fVbargraph26, "unit", "dB");
		ui_interface->addVerticalBargraph("out L", &fVbargraph26, FAUSTFLOAT(-70.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph28, "9", "");
		ui_interface->declare(&fVbargraph28, "symbol", "peakmeter_out_r");
		ui_interface->declare(&fVbargraph28, "unit", "dB");
		ui_interface->addVerticalBargraph("out R", &fVbargraph28, FAUSTFLOAT(-70.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->openTabBox("expert");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("pre-processing");
		ui_interface->declare(&fVslider0, "1", "");
		ui_interface->declare(&fVslider0, "symbol", "in_gain");
		ui_interface->declare(&fVslider0, "unit", "dB");
		ui_interface->addVerticalSlider("input gain", &fVslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-100.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fCheckbox8, "2", "");
		ui_interface->declare(&fCheckbox8, "symbol", "phase_l");
		ui_interface->addCheckButton("phase L", &fCheckbox8);
		ui_interface->declare(&fCheckbox9, "3", "");
		ui_interface->declare(&fCheckbox9, "symbol", "phase_r");
		ui_interface->addCheckButton("phase R", &fCheckbox9);
		ui_interface->declare(&fCheckbox6, "4", "");
		ui_interface->declare(&fCheckbox6, "symbol", "mono");
		ui_interface->addCheckButton("mono", &fCheckbox6);
		ui_interface->declare(&fCheckbox7, "5", "");
		ui_interface->declare(&fCheckbox7, "symbol", "dc_blocker");
		ui_interface->addCheckButton("dc blocker", &fCheckbox7);
		ui_interface->declare(&fCheckbox5, "6", "");
		ui_interface->declare(&fCheckbox5, "symbol", "stereo_correct");
		ui_interface->addCheckButton("stereo correct", &fCheckbox5);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("gate");
		ui_interface->declare(&fCheckbox4, "1", "");
		ui_interface->declare(&fCheckbox4, "symbol", "gate_bypass");
		ui_interface->addCheckButton("gate bypass", &fCheckbox4);
		ui_interface->declare(&fVslider4, "2", "");
		ui_interface->declare(&fVslider4, "symbol", "gate_threshold");
		ui_interface->declare(&fVslider4, "unit", "dB");
		ui_interface->addVerticalSlider("gate threshold", &fVslider4, FAUSTFLOAT(-90.0f), FAUSTFLOAT(-90.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider1, "3", "");
		ui_interface->declare(&fVslider1, "symbol", "gate_attack");
		ui_interface->declare(&fVslider1, "unit", "ms");
		ui_interface->addVerticalSlider("gate attack", &fVslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider3, "4", "");
		ui_interface->declare(&fVslider3, "symbol", "gate_hold");
		ui_interface->declare(&fVslider3, "unit", "ms");
		ui_interface->addVerticalSlider("gate hold", &fVslider3, FAUSTFLOAT(50.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider2, "5", "");
		ui_interface->declare(&fVslider2, "symbol", "gate_release");
		ui_interface->declare(&fVslider2, "unit", "ms");
		ui_interface->addVerticalSlider("gate release", &fVslider2, FAUSTFLOAT(500.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph3, "6", "");
		ui_interface->declare(&fVbargraph3, "symbol", "gate_meter");
		ui_interface->declare(&fVbargraph3, "unit", "dB");
		ui_interface->addVerticalBargraph("gate meter", &fVbargraph3, FAUSTFLOAT(-70.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("eq");
		ui_interface->declare(&fCheckbox3, "1", "");
		ui_interface->declare(&fCheckbox3, "symbol", "eq_bypass");
		ui_interface->addCheckButton("eq bypass", &fCheckbox3);
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("highpass");
		ui_interface->declare(&fVslider5, "1", "");
		ui_interface->declare(&fVslider5, "scale", "log");
		ui_interface->declare(&fVslider5, "symbol", "eq_highpass_freq");
		ui_interface->declare(&fVslider5, "unit", "Hz");
		ui_interface->addVerticalSlider("eq highpass freq", &fVslider5, FAUSTFLOAT(5.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("tilt eq");
		ui_interface->declare(&fVslider6, "1", "");
		ui_interface->declare(&fVslider6, "symbol", "eq_tilt_gain");
		ui_interface->declare(&fVslider6, "unit", "dB");
		ui_interface->addVerticalSlider("eq tilt gain", &fVslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.5f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("side eq");
		ui_interface->declare(&fVslider7, "1", "");
		ui_interface->declare(&fVslider7, "symbol", "eq_side_gain");
		ui_interface->declare(&fVslider7, "unit", "dB");
		ui_interface->addVerticalSlider("eq side gain", &fVslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider8, "2", "");
		ui_interface->declare(&fVslider8, "scale", "log");
		ui_interface->declare(&fVslider8, "symbol", "eq_side_freq");
		ui_interface->declare(&fVslider8, "unit", "Hz");
		ui_interface->addVerticalSlider("eq side freq", &fVslider8, FAUSTFLOAT(600.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider9, "3", "");
		ui_interface->declare(&fVslider9, "symbol", "eq_side_bandwidth");
		ui_interface->addVerticalSlider("eq side bandwidth", &fVslider9, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.5f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("leveler");
		ui_interface->declare(&fCheckbox2, "1", "");
		ui_interface->declare(&fCheckbox2, "symbol", "leveler_bypass");
		ui_interface->addCheckButton("leveler bypass", &fCheckbox2);
		ui_interface->declare(&fVslider11, "4", "");
		ui_interface->declare(&fVslider11, "integer", "");
		ui_interface->declare(&fVslider11, "symbol", "leveler_speed");
		ui_interface->declare(&fVslider11, "unit", "%");
		ui_interface->addVerticalSlider("leveler speed", &fVslider11, FAUSTFLOAT(20.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider10, "5", "");
		ui_interface->declare(&fVslider10, "symbol", "leveler_brake_threshold");
		ui_interface->declare(&fVslider10, "unit", "dB");
		ui_interface->addVerticalSlider("leveler brake threshold", &fVslider10, FAUSTFLOAT(-14.0f), FAUSTFLOAT(-90.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph4, "6", "");
		ui_interface->declare(&fVbargraph4, "integer", "");
		ui_interface->declare(&fVbargraph4, "symbol", "leveler_brake");
		ui_interface->declare(&fVbargraph4, "unit", "%");
		ui_interface->addVerticalBargraph("leveler brake", &fVbargraph4, FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f));
		ui_interface->declare(&fVslider13, "7", "");
		ui_interface->declare(&fVslider13, "symbol", "leveler_max_plus");
		ui_interface->declare(&fVslider13, "unit", "dB");
		ui_interface->addVerticalSlider("leveler max +", &fVslider13, FAUSTFLOAT(20.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(60.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider12, "8", "");
		ui_interface->declare(&fVslider12, "symbol", "leveler_max_minus");
		ui_interface->declare(&fVslider12, "unit", "dB");
		ui_interface->addVerticalSlider("leveler max -", &fVslider12, FAUSTFLOAT(20.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(60.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("kneecomp");
		ui_interface->declare(&fCheckbox10, "0", "");
		ui_interface->declare(&fCheckbox10, "symbol", "kneecomp_bypass");
		ui_interface->addCheckButton("kneecomp bypass", &fCheckbox10);
		ui_interface->declare(&fVslider21, "1", "");
		ui_interface->declare(&fVslider21, "integer", "");
		ui_interface->declare(&fVslider21, "symbol", "kneecomp_strength");
		ui_interface->declare(&fVslider21, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp strength", &fVslider21, FAUSTFLOAT(20.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider22, "2", "");
		ui_interface->declare(&fVslider22, "symbol", "kneecomp_threshold");
		ui_interface->declare(&fVslider22, "unit", "dB");
		ui_interface->addVerticalSlider("kneecomp tar-thresh", &fVslider22, FAUSTFLOAT(-6.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider19, "3", "");
		ui_interface->declare(&fVslider19, "symbol", "kneecomp_attack");
		ui_interface->declare(&fVslider19, "unit", "ms");
		ui_interface->addVerticalSlider("kneecomp attack", &fVslider19, FAUSTFLOAT(20.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider18, "4", "");
		ui_interface->declare(&fVslider18, "symbol", "kneecomp_release");
		ui_interface->declare(&fVslider18, "unit", "ms");
		ui_interface->addVerticalSlider("kneecomp release", &fVslider18, FAUSTFLOAT(200.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider23, "5", "");
		ui_interface->declare(&fVslider23, "symbol", "kneecomp_knee");
		ui_interface->declare(&fVslider23, "unit", "dB");
		ui_interface->addVerticalSlider("kneecomp knee", &fVslider23, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(30.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider24, "6", "");
		ui_interface->declare(&fVslider24, "integer", "");
		ui_interface->declare(&fVslider24, "symbol", "kneecomp_link");
		ui_interface->declare(&fVslider24, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp link", &fVslider24, FAUSTFLOAT(60.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider17, "7", "");
		ui_interface->declare(&fVslider17, "integer", "");
		ui_interface->declare(&fVslider17, "symbol", "kneecomp_fffb");
		ui_interface->declare(&fVslider17, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp ff-fb", &fVslider17, FAUSTFLOAT(50.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider16, "8", "");
		ui_interface->declare(&fVslider16, "symbol", "kneecomp_makeup");
		ui_interface->declare(&fVslider16, "unit", "dB");
		ui_interface->addVerticalSlider("kneecomp makeup", &fVslider16, FAUSTFLOAT(0.0f), FAUSTFLOAT(-10.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider15, "9", "");
		ui_interface->declare(&fVslider15, "integer", "");
		ui_interface->declare(&fVslider15, "symbol", "kneecomp_drywet");
		ui_interface->declare(&fVslider15, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp dry/wet", &fVslider15, FAUSTFLOAT(100.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph6, "symbol", "kneecomp_meter_0");
		ui_interface->declare(&fVbargraph6, "unit", "dB");
		ui_interface->addVerticalBargraph("kneecomp meter 0", &fVbargraph6, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph7, "symbol", "kneecomp_meter_1");
		ui_interface->declare(&fVbargraph7, "unit", "dB");
		ui_interface->addVerticalBargraph("kneecomp meter 1", &fVbargraph7, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("mscomp");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("bypass");
		ui_interface->declare(&fCheckbox1, "0", "");
		ui_interface->declare(&fCheckbox1, "symbol", "mscomp_bypass");
		ui_interface->addCheckButton("mscomp bypass", &fCheckbox1);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("low band");
		ui_interface->declare(&fVslider27, "1", "");
		ui_interface->declare(&fVslider27, "integer", "");
		ui_interface->declare(&fVslider27, "symbol", "mscomp_low_strength");
		ui_interface->declare(&fVslider27, "unit", "%");
		ui_interface->addVerticalSlider("low strength", &fVslider27, FAUSTFLOAT(10.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider35, "2", "");
		ui_interface->declare(&fVslider35, "symbol", "mscomp_low_threshold");
		ui_interface->declare(&fVslider35, "unit", "dB");
		ui_interface->addVerticalSlider("low tar-thresh", &fVslider35, FAUSTFLOAT(-6.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider31, "3", "");
		ui_interface->declare(&fVslider31, "symbol", "mscomp_low_attack");
		ui_interface->declare(&fVslider31, "unit", "ms");
		ui_interface->addVerticalSlider("low attack", &fVslider31, FAUSTFLOAT(15.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fVslider33, "4", "");
		ui_interface->declare(&fVslider33, "symbol", "mscomp_low_release");
		ui_interface->declare(&fVslider33, "unit", "ms");
		ui_interface->addVerticalSlider("low release", &fVslider33, FAUSTFLOAT(150.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider36, "5", "");
		ui_interface->declare(&fVslider36, "symbol", "mscomp_low_knee");
		ui_interface->declare(&fVslider36, "unit", "dB");
		ui_interface->addVerticalSlider("low knee", &fVslider36, FAUSTFLOAT(12.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(30.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fVslider37, "6", "");
		ui_interface->declare(&fVslider37, "integer", "");
		ui_interface->declare(&fVslider37, "symbol", "mscomp_low_link");
		ui_interface->declare(&fVslider37, "unit", "%");
		ui_interface->addVerticalSlider("low link", &fVslider37, FAUSTFLOAT(60.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider25, "7", "");
		ui_interface->declare(&fVslider25, "scale", "log");
		ui_interface->declare(&fVslider25, "symbol", "mscomp_low_crossover");
		ui_interface->declare(&fVslider25, "unit", "Hz");
		ui_interface->addVerticalSlider("low crossover", &fVslider25, FAUSTFLOAT(60.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(4000.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("high band");
		ui_interface->declare(&fVslider28, "1", "");
		ui_interface->declare(&fVslider28, "integer", "");
		ui_interface->declare(&fVslider28, "symbol", "mscomp_high_strength");
		ui_interface->declare(&fVslider28, "unit", "%");
		ui_interface->addVerticalSlider("high strength", &fVslider28, FAUSTFLOAT(10.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider29, "2", "");
		ui_interface->declare(&fVslider29, "symbol", "mscomp_high_threshold");
		ui_interface->declare(&fVslider29, "unit", "dB");
		ui_interface->addVerticalSlider("high tar-thresh", &fVslider29, FAUSTFLOAT(-12.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider32, "3", "");
		ui_interface->declare(&fVslider32, "symbol", "mscomp_high_attack");
		ui_interface->declare(&fVslider32, "unit", "ms");
		ui_interface->addVerticalSlider("high attack", &fVslider32, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fVslider34, "4", "");
		ui_interface->declare(&fVslider34, "symbol", "mscomp_high_release");
		ui_interface->declare(&fVslider34, "unit", "ms");
		ui_interface->addVerticalSlider("high release", &fVslider34, FAUSTFLOAT(30.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider30, "5", "");
		ui_interface->declare(&fVslider30, "symbol", "mscomp_high_knee");
		ui_interface->declare(&fVslider30, "unit", "dB");
		ui_interface->addVerticalSlider("high knee", &fVslider30, FAUSTFLOAT(12.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(30.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fVslider38, "6", "");
		ui_interface->declare(&fVslider38, "integer", "");
		ui_interface->declare(&fVslider38, "symbol", "mscomp_high_link");
		ui_interface->declare(&fVslider38, "unit", "%");
		ui_interface->addVerticalSlider("high link", &fVslider38, FAUSTFLOAT(30.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider26, "7", "");
		ui_interface->declare(&fVslider26, "scale", "log");
		ui_interface->declare(&fVslider26, "symbol", "mscomp_high_crossover");
		ui_interface->declare(&fVslider26, "unit", "Hz");
		ui_interface->addVerticalSlider("high crossover", &fVslider26, FAUSTFLOAT(8000.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("out");
		ui_interface->declare(&fVslider20, "3", "");
		ui_interface->declare(&fVslider20, "symbol", "mscomp_output_gain");
		ui_interface->declare(&fVslider20, "unit", "dB");
		ui_interface->addVerticalSlider("makeup", &fVslider20, FAUSTFLOAT(1.0f), FAUSTFLOAT(-6.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.5f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "6", "");
		ui_interface->openHorizontalBox("mscomp_meter");
		ui_interface->declare(&fVbargraph8, "1.1", "");
		ui_interface->declare(&fVbargraph8, "symbol", "msredux11");
		ui_interface->declare(&fVbargraph8, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph8, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec0320cfa0", &fVbargraph8, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph16, "1.2", "");
		ui_interface->declare(&fVbargraph16, "symbol", "msredux12");
		ui_interface->declare(&fVbargraph16, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph16, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec036c4c70", &fVbargraph16, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph9, "2.1", "");
		ui_interface->declare(&fVbargraph9, "symbol", "msredux21");
		ui_interface->declare(&fVbargraph9, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph9, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec0327a240", &fVbargraph9, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph17, "2.2", "");
		ui_interface->declare(&fVbargraph17, "symbol", "msredux22");
		ui_interface->declare(&fVbargraph17, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph17, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec036f7a10", &fVbargraph17, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph10, "3.1", "");
		ui_interface->declare(&fVbargraph10, "symbol", "msredux31");
		ui_interface->declare(&fVbargraph10, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph10, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec033183d0", &fVbargraph10, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph18, "3.2", "");
		ui_interface->declare(&fVbargraph18, "symbol", "msredux32");
		ui_interface->declare(&fVbargraph18, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph18, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec03757420", &fVbargraph18, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph11, "4.1", "");
		ui_interface->declare(&fVbargraph11, "symbol", "msredux41");
		ui_interface->declare(&fVbargraph11, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph11, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec033bc7e0", &fVbargraph11, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph19, "4.2", "");
		ui_interface->declare(&fVbargraph19, "symbol", "msredux42");
		ui_interface->declare(&fVbargraph19, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph19, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec037bac90", &fVbargraph19, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph12, "5.1", "");
		ui_interface->declare(&fVbargraph12, "symbol", "msredux51");
		ui_interface->declare(&fVbargraph12, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph12, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec03464f60", &fVbargraph12, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph20, "5.2", "");
		ui_interface->declare(&fVbargraph20, "symbol", "msredux52");
		ui_interface->declare(&fVbargraph20, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph20, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec03824e70", &fVbargraph20, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph13, "6.1", "");
		ui_interface->declare(&fVbargraph13, "symbol", "msredux61");
		ui_interface->declare(&fVbargraph13, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph13, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec03515040", &fVbargraph13, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph21, "6.2", "");
		ui_interface->declare(&fVbargraph21, "symbol", "msredux62");
		ui_interface->declare(&fVbargraph21, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph21, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec03892140", &fVbargraph21, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph14, "7.1", "");
		ui_interface->declare(&fVbargraph14, "symbol", "msredux71");
		ui_interface->declare(&fVbargraph14, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph14, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec035ca410", &fVbargraph14, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph22, "7.2", "");
		ui_interface->declare(&fVbargraph22, "symbol", "msredux72");
		ui_interface->declare(&fVbargraph22, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph22, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec038ff160", &fVbargraph22, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph15, "8.1", "");
		ui_interface->declare(&fVbargraph15, "symbol", "msredux81");
		ui_interface->declare(&fVbargraph15, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph15, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec03650950", &fVbargraph15, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph23, "8.2", "");
		ui_interface->declare(&fVbargraph23, "symbol", "msredux82");
		ui_interface->declare(&fVbargraph23, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph23, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55ec03975a50", &fVbargraph23, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "7", "");
		ui_interface->openHorizontalBox("limiter");
		ui_interface->declare(&fCheckbox11, "0", "");
		ui_interface->declare(&fCheckbox11, "symbol", "limiter_bypass");
		ui_interface->addCheckButton("limiter bypass", &fCheckbox11);
		ui_interface->declare(&fVslider42, "1", "");
		ui_interface->declare(&fVslider42, "integer", "");
		ui_interface->declare(&fVslider42, "symbol", "limiter_strength");
		ui_interface->declare(&fVslider42, "unit", "%");
		ui_interface->addVerticalSlider("limiter strength", &fVslider42, FAUSTFLOAT(80.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider43, "2", "");
		ui_interface->declare(&fVslider43, "symbol", "limiter_threshold");
		ui_interface->declare(&fVslider43, "unit", "dB");
		ui_interface->addVerticalSlider("limiter tar-thresh", &fVslider43, FAUSTFLOAT(6.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider41, "3", "");
		ui_interface->declare(&fVslider41, "symbol", "limiter_attack");
		ui_interface->declare(&fVslider41, "unit", "ms");
		ui_interface->addVerticalSlider("limiter attack", &fVslider41, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider40, "4", "");
		ui_interface->declare(&fVslider40, "symbol", "limiter_release");
		ui_interface->declare(&fVslider40, "unit", "ms");
		ui_interface->addVerticalSlider("limiter release", &fVslider40, FAUSTFLOAT(40.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider44, "5", "");
		ui_interface->declare(&fVslider44, "symbol", "limiter_knee");
		ui_interface->declare(&fVslider44, "unit", "dB");
		ui_interface->addVerticalSlider("limiter knee", &fVslider44, FAUSTFLOAT(8.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider39, "6", "");
		ui_interface->declare(&fVslider39, "integer", "");
		ui_interface->declare(&fVslider39, "symbol", "limiter_fffb");
		ui_interface->declare(&fVslider39, "unit", "%");
		ui_interface->addVerticalSlider("limiter ff-fb", &fVslider39, FAUSTFLOAT(50.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider45, "8", "");
		ui_interface->declare(&fVslider45, "symbol", "limiter_makeup");
		ui_interface->declare(&fVslider45, "unit", "dB");
		ui_interface->addVerticalSlider("limiter makeup", &fVslider45, FAUSTFLOAT(0.0f), FAUSTFLOAT(-10.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVbargraph24, "9", "");
		ui_interface->declare(&fVbargraph24, "symbol", "limiter_gain_reduction");
		ui_interface->declare(&fVbargraph24, "unit", "dB");
		ui_interface->addVerticalBargraph("limiter gain reduction", &fVbargraph24, FAUSTFLOAT(-12.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "8", "");
		ui_interface->openHorizontalBox("brickwall");
		ui_interface->declare(&fCheckbox12, "1", "");
		ui_interface->declare(&fCheckbox12, "symbol", "brickwall_bypass");
		ui_interface->addCheckButton("brickwall bypass", &fCheckbox12);
		ui_interface->declare(&fVslider47, "3", "");
		ui_interface->declare(&fVslider47, "symbol", "brickwall_ceiling");
		ui_interface->declare(&fVslider47, "unit", "dB");
		ui_interface->addVerticalSlider("brickwall ceiling", &fVslider47, FAUSTFLOAT(-1.0f), FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fVslider46, "4", "");
		ui_interface->declare(&fVslider46, "symbol", "brickwall_release");
		ui_interface->declare(&fVslider46, "unit", "ms");
		ui_interface->addVerticalSlider("brickwall release", &fVslider46, FAUSTFLOAT(75.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph25, "symbol", "brickwall_limit");
		ui_interface->declare(&fVbargraph25, "unit", "dB");
		ui_interface->addVerticalBargraph("lim", &fVbargraph25, FAUSTFLOAT(-20.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* input1_ptr = inputs[1];
		FAUSTFLOAT* output0_ptr = outputs[0];
		FAUSTFLOAT* output1_ptr = outputs[1];
		float fSlow0 = fConst1 * float(fCheckbox0);
		float fRec0_tmp[12];
		float* fRec0 = &fRec0_tmp[4];
		float fSlow1 = fConst1 * float(fCheckbox1);
		float fRec7_tmp[12];
		float* fRec7 = &fRec7_tmp[4];
		float fSlow2 = fConst1 * float(fCheckbox2);
		float fRec8_tmp[12];
		float* fRec8 = &fRec8_tmp[4];
		float fSlow3 = fConst1 * float(fCheckbox3);
		float fRec12_tmp[12];
		float* fRec12 = &fRec12_tmp[4];
		float fSlow4 = fConst1 * float(fCheckbox4);
		float fRec13_tmp[12];
		float* fRec13 = &fRec13_tmp[4];
		float fSlow5 = fConst1 * (1.0f - float(fCheckbox5));
		float fRec14_tmp[12];
		float* fRec14 = &fRec14_tmp[4];
		float fSlow6 = fConst1 * (1.0f - float(fCheckbox6));
		float fRec15_tmp[12];
		float* fRec15 = &fRec15_tmp[4];
		float fSlow7 = fConst1 * std::pow(10.0f, 0.0500000007f * float(fVslider0));
		float fRec16_tmp[12];
		float* fRec16 = &fRec16_tmp[4];
		float fZec0[8];
		float fRec17_tmp[12];
		float* fRec17 = &fRec17_tmp[4];
		float fSlow8 = fConst1 * (1.0f - float(fCheckbox7));
		float fRec18_tmp[12];
		float* fRec18 = &fRec18_tmp[4];
		float fYec0_tmp[12];
		float* fYec0 = &fYec0_tmp[4];
		float fRec19_tmp[12];
		float* fRec19 = &fRec19_tmp[4];
		float fZec1[8];
		float fRec21_tmp[12];
		float* fRec21 = &fRec21_tmp[4];
		float fYec1_tmp[12];
		float* fYec1 = &fYec1_tmp[4];
		float fRec25_tmp[12];
		float* fRec25 = &fRec25_tmp[4];
		float fRec24_tmp[12];
		float* fRec24 = &fRec24_tmp[4];
		float fYec2_tmp[12];
		float* fYec2 = &fYec2_tmp[4];
		float fRec23_tmp[12];
		float* fRec23 = &fRec23_tmp[4];
		float fRec22_tmp[12];
		float* fRec22 = &fRec22_tmp[4];
		float fYec3_tmp[12];
		float* fYec3 = &fYec3_tmp[4];
		float fYec4_tmp[12];
		float* fYec4 = &fYec4_tmp[4];
		float fRec29_tmp[12];
		float* fRec29 = &fRec29_tmp[4];
		float fRec28_tmp[12];
		float* fRec28 = &fRec28_tmp[4];
		float fYec5_tmp[12];
		float* fYec5 = &fYec5_tmp[4];
		float fRec27_tmp[12];
		float* fRec27 = &fRec27_tmp[4];
		float fRec26_tmp[12];
		float* fRec26 = &fRec26_tmp[4];
		float fYec6_tmp[12];
		float* fYec6 = &fYec6_tmp[4];
		float fYec7_tmp[12];
		float* fYec7 = &fYec7_tmp[4];
		float fYec8_tmp[16];
		float* fYec8 = &fYec8_tmp[8];
		float fYec9_tmp[24];
		float* fYec9 = &fYec9_tmp[16];
		float fYec26_tmp[12];
		float* fYec26 = &fYec26_tmp[4];
		float fYec27_tmp[12];
		float* fYec27 = &fYec27_tmp[4];
		float fYec28_tmp[16];
		float* fYec28 = &fYec28_tmp[8];
		float fYec29_tmp[24];
		float* fYec29 = &fYec29_tmp[16];
		float fYec46_tmp[12];
		float* fYec46 = &fYec46_tmp[4];
		float fRec20_tmp[12];
		float* fRec20 = &fRec20_tmp[4];
		float fSlow9 = float(fCheckbox8);
		float fZec2[8];
		float fZec3[8];
		float fSlow10 = 1.0f - fSlow9;
		float fZec4[8];
		float fSlow11 = float(fCheckbox9);
		float fZec5[8];
		float fSlow12 = 1.0f - fSlow11;
		float fZec6[8];
		float fZec7[8];
		float fZec8[8];
		float fRec33_tmp[12];
		float* fRec33 = &fRec33_tmp[4];
		float fZec9[8];
		float fRec34_tmp[12];
		float* fRec34 = &fRec34_tmp[4];
		float fZec10[8];
		float fZec11[8];
		float fRec32_tmp[12];
		float* fRec32 = &fRec32_tmp[4];
		float fRec35_tmp[12];
		float* fRec35 = &fRec35_tmp[4];
		float fRec36_tmp[12];
		float* fRec36 = &fRec36_tmp[4];
		float fZec12[8];
		float fRec31_tmp[12];
		float* fRec31 = &fRec31_tmp[4];
		float fRec30_tmp[12];
		float* fRec30 = &fRec30_tmp[4];
		float fRec38_tmp[12];
		float* fRec38 = &fRec38_tmp[4];
		float fRec37_tmp[12];
		float* fRec37 = &fRec37_tmp[4];
		float fRec40_tmp[12];
		float* fRec40 = &fRec40_tmp[4];
		float fRec39_tmp[12];
		float* fRec39 = &fRec39_tmp[4];
		float fRec42_tmp[12];
		float* fRec42 = &fRec42_tmp[4];
		float fRec41_tmp[12];
		float* fRec41 = &fRec41_tmp[4];
		float fRec44_tmp[12];
		float* fRec44 = &fRec44_tmp[4];
		float fRec43_tmp[12];
		float* fRec43 = &fRec43_tmp[4];
		float fZec13[8];
		float fZec14[8];
		float fZec15[8];
		float fZec16[8];
		float fZec17[8];
		float fZec18[8];
		float fZec19[8];
		float fSlow13 = 0.00100000005f * float(fVslider1);
		float fSlow14 = 0.00100000005f * float(fVslider2);
		float fSlow15 = std::min<float>(fSlow13, fSlow14);
		int iSlow16 = std::fabs(fSlow15) < 1.1920929e-07f;
		float fThen41 = std::exp(0.0f - fConst102 / ((iSlow16) ? 1.0f : fSlow15));
		float fSlow17 = ((iSlow16) ? 0.0f : fThen41);
		float fSlow18 = 1.0f - fSlow17;
		float fRec48_tmp[12];
		float* fRec48 = &fRec48_tmp[4];
		int iSlow19 = int(fConst103 * float(fVslider3));
		float fSlow20 = std::pow(10.0f, 0.0500000007f * float(fVslider4));
		int iYec47_tmp[12];
		int* iYec47 = &iYec47_tmp[4];
		int iRec49_tmp[12];
		int* iRec49 = &iRec49_tmp[4];
		float fZec20[8];
		int iSlow21 = std::fabs(fSlow14) < 1.1920929e-07f;
		float fThen43 = std::exp(0.0f - fConst102 / ((iSlow21) ? 1.0f : fSlow14));
		float fSlow22 = ((iSlow21) ? 0.0f : fThen43);
		int iSlow23 = std::fabs(fSlow13) < 1.1920929e-07f;
		float fThen45 = std::exp(0.0f - fConst102 / ((iSlow23) ? 1.0f : fSlow13));
		float fSlow24 = ((iSlow23) ? 0.0f : fThen45);
		float fZec21[8];
		float fRec47_tmp[12];
		float* fRec47 = &fRec47_tmp[4];
		float fZec22[8];
		float fRec46_tmp[12];
		float* fRec46 = &fRec46_tmp[4];
		int iYec48_tmp[12];
		int* iYec48 = &iYec48_tmp[4];
		int iRec50_tmp[12];
		int* iRec50 = &iRec50_tmp[4];
		float fZec23[8];
		float fZec24[8];
		float fRec45_tmp[12];
		float* fRec45 = &fRec45_tmp[4];
		float fSlow25 = std::tan(fConst104 * float(fVslider5));
		float fSlow26 = 1.0f / fSlow25;
		float fSlow27 = fSlow26 + 1.0f;
		float fSlow28 = 0.0f - 1.0f / (fSlow25 * fSlow27);
		float fZec25[8];
		float fYec49_tmp[12];
		float* fYec49 = &fYec49_tmp[4];
		float fSlow29 = 1.0f / fSlow27;
		float fSlow30 = 1.0f - fSlow26;
		float fRec53_tmp[12];
		float* fRec53 = &fRec53_tmp[4];
		float fRec52_tmp[12];
		float* fRec52 = &fRec52_tmp[4];
		float fRec54_tmp[12];
		float* fRec54 = &fRec54_tmp[4];
		float fSlow31 = fConst1 * float(fVslider6);
		float fRec55_tmp[12];
		float* fRec55 = &fRec55_tmp[4];
		float fZec26[8];
		float fZec27[8];
		float fYec50_tmp[12];
		float* fYec50 = &fYec50_tmp[4];
		float fRec51_tmp[12];
		float* fRec51 = &fRec51_tmp[4];
		float fRec56_tmp[12];
		float* fRec56 = &fRec56_tmp[4];
		float fZec28[8];
		float fYec51_tmp[12];
		float* fYec51 = &fYec51_tmp[4];
		float fRec59_tmp[12];
		float* fRec59 = &fRec59_tmp[4];
		float fRec58_tmp[12];
		float* fRec58 = &fRec58_tmp[4];
		float fRec60_tmp[12];
		float* fRec60 = &fRec60_tmp[4];
		float fYec52_tmp[12];
		float* fYec52 = &fYec52_tmp[4];
		float fRec57_tmp[12];
		float* fRec57 = &fRec57_tmp[4];
		float fRec61_tmp[12];
		float* fRec61 = &fRec61_tmp[4];
		float fSlow32 = fConst1 * float(fVslider7);
		float fRec70_tmp[12];
		float* fRec70 = &fRec70_tmp[4];
		float fSlow33 = float(fVslider8);
		float fSlow34 = float(fVslider9);
		float fSlow35 = std::tan(fConst104 * std::max<float>(50.0f, fSlow33 * (1.0f - fSlow34)));
		float fZec29[8];
		float fZec30[8];
		float fZec31[8];
		float fZec32[8];
		float fZec33[8];
		float fZec34[8];
		float fZec35[8];
		float fZec36[8];
		float fZec37[8];
		float fZec38[8];
		float fZec39[8];
		float fRec66_tmp[12];
		float* fRec66 = &fRec66_tmp[4];
		float fZec40[8];
		float fRec67_tmp[12];
		float* fRec67 = &fRec67_tmp[4];
		float fRec68[8];
		float fRec69[8];
		float fSlow36 = std::tan(fConst104 * std::min<float>(8000.0f, fSlow33 * (fSlow34 + 1.0f)));
		float fZec41[8];
		float fZec42[8];
		float fZec43[8];
		float fZec44[8];
		float fZec45[8];
		float fZec46[8];
		float fZec47[8];
		float fZec48[8];
		float fRec62_tmp[12];
		float* fRec62 = &fRec62_tmp[4];
		float fZec49[8];
		float fRec63_tmp[12];
		float* fRec63 = &fRec63_tmp[4];
		float fRec64[8];
		float fRec65[8];
		float fZec50[8];
		float fZec51[8];
		float fZec52[8];
		float fZec53[8];
		float fZec54[8];
		float fYec53_tmp[12];
		float* fYec53 = &fYec53_tmp[4];
		float fYec54_tmp[12];
		float* fYec54 = &fYec54_tmp[4];
		float fYec55_tmp[16];
		float* fYec55 = &fYec55_tmp[8];
		float fYec56_tmp[24];
		float* fYec56 = &fYec56_tmp[16];
		float fZec55[8];
		float fSlow37 = float(fVslider10);
		float fSlow38 = fSlow37 + -6.0f;
		float fSlow39 = fSlow37 + 6.0f;
		int iZec56[8];
		float fZec57[8];
		float fZec58[8];
		float fRec11_tmp[12];
		float* fRec11 = &fRec11_tmp[4];
		float fYec68_tmp[12];
		float* fYec68 = &fYec68_tmp[4];
		float fRec74_tmp[12];
		float* fRec74 = &fRec74_tmp[4];
		float fRec73_tmp[12];
		float* fRec73 = &fRec73_tmp[4];
		float fYec69_tmp[12];
		float* fYec69 = &fYec69_tmp[4];
		float fRec72_tmp[12];
		float* fRec72 = &fRec72_tmp[4];
		float fRec71_tmp[12];
		float* fRec71 = &fRec71_tmp[4];
		float fYec70_tmp[12];
		float* fYec70 = &fYec70_tmp[4];
		float fRec78_tmp[12];
		float* fRec78 = &fRec78_tmp[4];
		float fRec77_tmp[12];
		float* fRec77 = &fRec77_tmp[4];
		float fYec71_tmp[12];
		float* fYec71 = &fYec71_tmp[4];
		float fRec76_tmp[12];
		float* fRec76 = &fRec76_tmp[4];
		float fRec75_tmp[12];
		float* fRec75 = &fRec75_tmp[4];
		float fSlow40 = 106.103294f / float(fVslider11);
		float fZec59[8];
		float fZec60[8];
		int iZec61[8];
		float fZec62[8];
		float fSlow41 = -1.0f * float(fVslider12);
		float fSlow42 = float(fVslider13);
		float fSlow43 = float(fVslider14);
		float fYec72_tmp[12];
		float* fYec72 = &fYec72_tmp[4];
		float fYec73_tmp[12];
		float* fYec73 = &fYec73_tmp[4];
		float fYec74_tmp[16];
		float* fYec74 = &fYec74_tmp[8];
		float fYec75_tmp[24];
		float* fYec75 = &fYec75_tmp[16];
		float fYec89_tmp[12];
		float* fYec89 = &fYec89_tmp[4];
		float fYec90_tmp[12];
		float* fYec90 = &fYec90_tmp[4];
		float fYec91_tmp[16];
		float* fYec91 = &fYec91_tmp[8];
		float fYec92_tmp[24];
		float* fYec92 = &fYec92_tmp[16];
		float fRec10_tmp[12];
		float* fRec10 = &fRec10_tmp[4];
		float fRec9_tmp[12];
		float* fRec9 = &fRec9_tmp[4];
		float fSlow44 = fConst231 * float(fVslider15);
		float fRec79_tmp[12];
		float* fRec79 = &fRec79_tmp[4];
		float fSlow45 = fConst1 * float(fCheckbox10);
		float fRec80_tmp[12];
		float* fRec80 = &fRec80_tmp[4];
		float fSlow46 = fConst1 * float(fVslider16);
		float fRec81_tmp[12];
		float* fRec81 = &fRec81_tmp[4];
		float fSlow47 = 0.00999999978f * float(fVslider17);
		float fSlow48 = 1.0f - fSlow47;
		float fZec63[8];
		float fZec64[8];
		float fZec65[8];
		int iSlow49 = std::max<int>(1, int(fConst103 * float(fVslider18)));
		float fSlow50 = 1.0f / float(iSlow49);
		int iSlow51 = std::max<int>(0, iSlow49);
		float fZec66[8];
		float fSlow52 = 0.00100000005f * float(fVslider19);
		int iSlow53 = std::fabs(fSlow52) < 1.1920929e-07f;
		float fThen103 = std::exp(0.0f - fConst102 / ((iSlow53) ? 1.0f : fSlow52));
		float fSlow54 = ((iSlow53) ? 0.0f : fThen103);
		float fZec67[8];
		float fRec82_tmp[12];
		float* fRec82 = &fRec82_tmp[4];
		float fZec68[8];
		float fZec69[8];
		float fRec84_tmp[12];
		float* fRec84 = &fRec84_tmp[4];
		float fSlow55 = fConst1 * std::pow(10.0f, 0.0500000007f * float(fVslider20));
		float fRec86_tmp[12];
		float* fRec86 = &fRec86_tmp[4];
		float fZec70[8];
		float fSlow56 = float(fVslider21);
		float fZec71[8];
		float fSlow57 = float(fVslider22);
		float fSlow58 = fSlow43 + fSlow57;
		float fSlow59 = float(fVslider23);
		float fSlow60 = 0.5f * fSlow59;
		float fSlow61 = fSlow58 - fSlow60;
		float fSlow62 = fSlow43 + fSlow57 + fSlow60;
		int iZec72[8];
		float fZec73[8];
		float fSlow63 = 0.5f / std::max<float>(1.1920929e-07f, fSlow59);
		float fZec74[8];
		float fSlow64 = float(fVslider24);
		float fSlow65 = 0.00999999978f * fSlow56;
		float fZec75[8];
		float fZec76[8];
		int iZec77[8];
		float fZec78[8];
		float fZec79[8];
		float fZec80[8];
		float fZec81[8];
		float fZec82[8];
		float fZec83[8];
		float fZec84[8];
		float fZec85[8];
		float fZec86[8];
		float fZec87[8];
		float fZec88[8];
		float fSlow66 = std::max<float>(1.1920929e-07f, float(fVslider25));
		float fSlow67 = std::pow(std::max<float>(1.1920929e-07f, float(fVslider26)) / fSlow66, 0.166666672f);
		float fSlow68 = std::tan(fConst104 * fSlow66 * mydsp_faustpower6_f(fSlow67));
		float fSlow69 = 1.0f / fSlow68;
		float fSlow70 = 1.0f / ((fSlow69 + 1.93185163f) / fSlow68 + 1.0f);
		float fSlow71 = (fSlow69 + -1.93185163f) / fSlow68 + 1.0f;
		float fSlow72 = mydsp_faustpower2_f(fSlow68);
		float fSlow73 = 1.0f / fSlow72;
		float fSlow74 = 2.0f * (1.0f - fSlow73);
		float fRec90_tmp[12];
		float* fRec90 = &fRec90_tmp[4];
		float fSlow75 = 0.0f - 2.0f / fSlow72;
		float fSlow76 = 1.0f / ((fSlow69 + 1.41421354f) / fSlow68 + 1.0f);
		float fSlow77 = (fSlow69 + -1.41421354f) / fSlow68 + 1.0f;
		float fRec89_tmp[12];
		float* fRec89 = &fRec89_tmp[4];
		float fSlow78 = 1.0f / ((fSlow69 + 0.517638087f) / fSlow68 + 1.0f);
		float fSlow79 = (fSlow69 + -0.517638087f) / fSlow68 + 1.0f;
		float fRec88_tmp[12];
		float* fRec88 = &fRec88_tmp[4];
		float fSlow80 = float(fVslider27);
		float fSlow81 = float(fVslider28) - fSlow80;
		float fSlow82 = 0.00999999978f * (fSlow80 + fSlow81);
		float fZec89[8];
		float fSlow83 = float(fVslider29);
		float fSlow84 = fSlow43 + fSlow83;
		float fSlow85 = float(fVslider30);
		float fSlow86 = 0.5f * fSlow85;
		float fSlow87 = fSlow84 - fSlow86;
		float fSlow88 = fSlow43 + fSlow83 + fSlow86;
		int iZec90[8];
		float fZec91[8];
		float fSlow89 = 0.5f / std::max<float>(1.1920929e-07f, fSlow85);
		float fZec92[8];
		float fSlow90 = std::max<float>(1.1920929e-07f, 0.00100000005f * float(fVslider31));
		float fSlow91 = std::pow(std::max<float>(1.1920929e-07f, 0.00100000005f * float(fVslider32)) / fSlow90, 0.142857149f);
		float fSlow92 = fSlow90 * mydsp_faustpower7_f(fSlow91);
		int iSlow93 = std::fabs(fSlow92) < 1.1920929e-07f;
		float fThen113 = std::exp(0.0f - fConst102 / ((iSlow93) ? 1.0f : fSlow92));
		float fSlow94 = ((iSlow93) ? 0.0f : fThen113);
		float fSlow95 = std::max<float>(1.1920929e-07f, 0.00100000005f * float(fVslider33));
		float fSlow96 = std::pow(std::max<float>(1.1920929e-07f, 0.00100000005f * float(fVslider34)) / fSlow95, 0.142857149f);
		float fSlow97 = fSlow95 * mydsp_faustpower7_f(fSlow96);
		int iSlow98 = std::fabs(fSlow97) < 1.1920929e-07f;
		float fThen115 = std::exp(0.0f - fConst102 / ((iSlow98) ? 1.0f : fSlow97));
		float fSlow99 = ((iSlow98) ? 0.0f : fThen115);
		float fZec93[8];
		float fRec87_tmp[12];
		float* fRec87 = &fRec87_tmp[4];
		float fZec94[8];
		float fRec94_tmp[12];
		float* fRec94 = &fRec94_tmp[4];
		float fRec93_tmp[12];
		float* fRec93 = &fRec93_tmp[4];
		float fRec92_tmp[12];
		float* fRec92 = &fRec92_tmp[4];
		float fZec95[8];
		int iZec96[8];
		float fZec97[8];
		float fZec98[8];
		float fZec99[8];
		float fRec91_tmp[12];
		float* fRec91 = &fRec91_tmp[4];
		float fRec325_tmp[12];
		float* fRec325 = &fRec325_tmp[4];
		float fRec324_tmp[12];
		float* fRec324 = &fRec324_tmp[4];
		float fSlow100 = std::tan(fConst104 * fSlow66 * mydsp_faustpower5_f(fSlow67));
		float fSlow101 = 1.0f / fSlow100;
		float fSlow102 = 1.0f / ((fSlow101 + 1.93185163f) / fSlow100 + 1.0f);
		float fSlow103 = (fSlow101 + -1.93185163f) / fSlow100 + 1.0f;
		float fSlow104 = mydsp_faustpower2_f(fSlow100);
		float fSlow105 = 1.0f / fSlow104;
		float fSlow106 = 2.0f * (1.0f - fSlow105);
		float fRec323_tmp[12];
		float* fRec323 = &fRec323_tmp[4];
		float fSlow107 = 1.0f / ((fSlow101 + 1.41421354f) / fSlow100 + 1.0f);
		float fSlow108 = (fSlow101 + -1.41421354f) / fSlow100 + 1.0f;
		float fRec322_tmp[12];
		float* fRec322 = &fRec322_tmp[4];
		float fSlow109 = 1.0f / ((fSlow101 + 0.517638087f) / fSlow100 + 1.0f);
		float fSlow110 = (fSlow101 + -0.517638087f) / fSlow100 + 1.0f;
		float fRec321_tmp[12];
		float* fRec321 = &fRec321_tmp[4];
		float fSlow111 = std::tan(fConst104 * fSlow66 * mydsp_faustpower4_f(fSlow67));
		float fSlow112 = 1.0f / fSlow111;
		float fSlow113 = 1.0f / ((fSlow112 + 1.93185163f) / fSlow111 + 1.0f);
		float fSlow114 = (fSlow112 + -1.93185163f) / fSlow111 + 1.0f;
		float fSlow115 = mydsp_faustpower2_f(fSlow111);
		float fSlow116 = 1.0f / fSlow115;
		float fSlow117 = 2.0f * (1.0f - fSlow116);
		float fRec320_tmp[12];
		float* fRec320 = &fRec320_tmp[4];
		float fSlow118 = 1.0f / ((fSlow112 + 1.41421354f) / fSlow111 + 1.0f);
		float fSlow119 = (fSlow112 + -1.41421354f) / fSlow111 + 1.0f;
		float fRec319_tmp[12];
		float* fRec319 = &fRec319_tmp[4];
		float fSlow120 = 1.0f / ((fSlow112 + 0.517638087f) / fSlow111 + 1.0f);
		float fSlow121 = (fSlow112 + -0.517638087f) / fSlow111 + 1.0f;
		float fRec318_tmp[12];
		float* fRec318 = &fRec318_tmp[4];
		float fSlow122 = std::tan(fConst104 * fSlow66 * mydsp_faustpower3_f(fSlow67));
		float fSlow123 = 1.0f / fSlow122;
		float fSlow124 = 1.0f / ((fSlow123 + 1.93185163f) / fSlow122 + 1.0f);
		float fSlow125 = (fSlow123 + -1.93185163f) / fSlow122 + 1.0f;
		float fSlow126 = mydsp_faustpower2_f(fSlow122);
		float fSlow127 = 1.0f / fSlow126;
		float fSlow128 = 2.0f * (1.0f - fSlow127);
		float fRec317_tmp[12];
		float* fRec317 = &fRec317_tmp[4];
		float fSlow129 = 1.0f / ((fSlow123 + 1.41421354f) / fSlow122 + 1.0f);
		float fSlow130 = (fSlow123 + -1.41421354f) / fSlow122 + 1.0f;
		float fRec316_tmp[12];
		float* fRec316 = &fRec316_tmp[4];
		float fSlow131 = 1.0f / ((fSlow123 + 0.517638087f) / fSlow122 + 1.0f);
		float fSlow132 = (fSlow123 + -0.517638087f) / fSlow122 + 1.0f;
		float fRec315_tmp[12];
		float* fRec315 = &fRec315_tmp[4];
		float fSlow133 = std::tan(fConst104 * fSlow66 * mydsp_faustpower2_f(fSlow67));
		float fSlow134 = 1.0f / fSlow133;
		float fSlow135 = 1.0f / ((fSlow134 + 1.93185163f) / fSlow133 + 1.0f);
		float fSlow136 = (fSlow134 + -1.93185163f) / fSlow133 + 1.0f;
		float fSlow137 = mydsp_faustpower2_f(fSlow133);
		float fSlow138 = 1.0f / fSlow137;
		float fSlow139 = 2.0f * (1.0f - fSlow138);
		float fRec314_tmp[12];
		float* fRec314 = &fRec314_tmp[4];
		float fSlow140 = 1.0f / ((fSlow134 + 1.41421354f) / fSlow133 + 1.0f);
		float fSlow141 = (fSlow134 + -1.41421354f) / fSlow133 + 1.0f;
		float fRec313_tmp[12];
		float* fRec313 = &fRec313_tmp[4];
		float fSlow142 = 1.0f / ((fSlow134 + 0.517638087f) / fSlow133 + 1.0f);
		float fSlow143 = (fSlow134 + -0.517638087f) / fSlow133 + 1.0f;
		float fRec312_tmp[12];
		float* fRec312 = &fRec312_tmp[4];
		float fSlow144 = std::tan(fConst104 * fSlow66 * fSlow67);
		float fSlow145 = 1.0f / fSlow144;
		float fSlow146 = 1.0f / ((fSlow145 + 1.93185163f) / fSlow144 + 1.0f);
		float fSlow147 = (fSlow145 + -1.93185163f) / fSlow144 + 1.0f;
		float fSlow148 = mydsp_faustpower2_f(fSlow144);
		float fSlow149 = 1.0f / fSlow148;
		float fSlow150 = 2.0f * (1.0f - fSlow149);
		float fRec311_tmp[12];
		float* fRec311 = &fRec311_tmp[4];
		float fSlow151 = 1.0f / ((fSlow145 + 1.41421354f) / fSlow144 + 1.0f);
		float fSlow152 = (fSlow145 + -1.41421354f) / fSlow144 + 1.0f;
		float fRec310_tmp[12];
		float* fRec310 = &fRec310_tmp[4];
		float fSlow153 = 1.0f / ((fSlow145 + 0.517638087f) / fSlow144 + 1.0f);
		float fSlow154 = (fSlow145 + -0.517638087f) / fSlow144 + 1.0f;
		float fRec309_tmp[12];
		float* fRec309 = &fRec309_tmp[4];
		float fSlow155 = std::tan(fConst104 * fSlow66);
		float fSlow156 = 1.0f / fSlow155;
		float fSlow157 = 1.0f / ((fSlow156 + 1.93185163f) / fSlow155 + 1.0f);
		float fSlow158 = (fSlow156 + -1.93185163f) / fSlow155 + 1.0f;
		float fSlow159 = mydsp_faustpower2_f(fSlow155);
		float fSlow160 = 1.0f / fSlow159;
		float fSlow161 = 2.0f * (1.0f - fSlow160);
		float fRec308_tmp[12];
		float* fRec308 = &fRec308_tmp[4];
		float fSlow162 = 1.0f / ((fSlow156 + 1.41421354f) / fSlow155 + 1.0f);
		float fSlow163 = (fSlow156 + -1.41421354f) / fSlow155 + 1.0f;
		float fRec307_tmp[12];
		float* fRec307 = &fRec307_tmp[4];
		float fSlow164 = 1.0f / ((fSlow156 + 0.517638087f) / fSlow155 + 1.0f);
		float fSlow165 = (fSlow156 + -0.517638087f) / fSlow155 + 1.0f;
		float fRec306_tmp[12];
		float* fRec306 = &fRec306_tmp[4];
		float fSlow166 = 0.00999999978f * fSlow80;
		float fZec100[8];
		float fSlow167 = float(fVslider35);
		float fSlow168 = fSlow43 + fSlow167;
		float fSlow169 = float(fVslider36);
		float fSlow170 = 0.5f * fSlow169;
		float fSlow171 = fSlow168 - fSlow170;
		float fSlow172 = fSlow43 + fSlow167 + fSlow170;
		int iZec101[8];
		float fZec102[8];
		float fSlow173 = 0.5f / std::max<float>(1.1920929e-07f, fSlow169);
		float fZec103[8];
		int iSlow174 = std::fabs(fSlow90) < 1.1920929e-07f;
		float fThen123 = std::exp(0.0f - fConst102 / ((iSlow174) ? 1.0f : fSlow90));
		float fSlow175 = ((iSlow174) ? 0.0f : fThen123);
		int iSlow176 = std::fabs(fSlow95) < 1.1920929e-07f;
		float fThen125 = std::exp(0.0f - fConst102 / ((iSlow176) ? 1.0f : fSlow95));
		float fSlow177 = ((iSlow176) ? 0.0f : fThen125);
		float fZec104[8];
		float fRec305_tmp[12];
		float* fRec305 = &fRec305_tmp[4];
		float fRec346_tmp[12];
		float* fRec346 = &fRec346_tmp[4];
		float fRec345_tmp[12];
		float* fRec345 = &fRec345_tmp[4];
		float fRec344_tmp[12];
		float* fRec344 = &fRec344_tmp[4];
		float fRec343_tmp[12];
		float* fRec343 = &fRec343_tmp[4];
		float fRec342_tmp[12];
		float* fRec342 = &fRec342_tmp[4];
		float fRec341_tmp[12];
		float* fRec341 = &fRec341_tmp[4];
		float fRec340_tmp[12];
		float* fRec340 = &fRec340_tmp[4];
		float fRec339_tmp[12];
		float* fRec339 = &fRec339_tmp[4];
		float fRec338_tmp[12];
		float* fRec338 = &fRec338_tmp[4];
		float fRec337_tmp[12];
		float* fRec337 = &fRec337_tmp[4];
		float fRec336_tmp[12];
		float* fRec336 = &fRec336_tmp[4];
		float fRec335_tmp[12];
		float* fRec335 = &fRec335_tmp[4];
		float fRec334_tmp[12];
		float* fRec334 = &fRec334_tmp[4];
		float fRec333_tmp[12];
		float* fRec333 = &fRec333_tmp[4];
		float fRec332_tmp[12];
		float* fRec332 = &fRec332_tmp[4];
		float fRec331_tmp[12];
		float* fRec331 = &fRec331_tmp[4];
		float fRec330_tmp[12];
		float* fRec330 = &fRec330_tmp[4];
		float fRec329_tmp[12];
		float* fRec329 = &fRec329_tmp[4];
		float fRec328_tmp[12];
		float* fRec328 = &fRec328_tmp[4];
		float fRec327_tmp[12];
		float* fRec327 = &fRec327_tmp[4];
		float fZec105[8];
		int iZec106[8];
		float fZec107[8];
		float fZec108[8];
		float fZec109[8];
		float fRec326_tmp[12];
		float* fRec326 = &fRec326_tmp[4];
		float fSlow178 = float(fVslider37);
		float fSlow179 = 0.00999999978f * fSlow178;
		float fZec110[8];
		float fZec111[8];
		float fZec112[8];
		float fZec113[8];
		float fZec114[8];
		float fZec115[8];
		float fZec116[8];
		float fZec117[8];
		float fRec300_tmp[12];
		float* fRec300 = &fRec300_tmp[4];
		float fZec118[8];
		float fRec301_tmp[12];
		float* fRec301 = &fRec301_tmp[4];
		float fRec302[8];
		float fRec303[8];
		float fRec304[8];
		float fZec119[8];
		float fZec120[8];
		float fZec121[8];
		float fZec122[8];
		float fZec123[8];
		float fZec124[8];
		float fRec295_tmp[12];
		float* fRec295 = &fRec295_tmp[4];
		float fZec125[8];
		float fRec296_tmp[12];
		float* fRec296 = &fRec296_tmp[4];
		float fRec297[8];
		float fRec298[8];
		float fRec299[8];
		float fZec126[8];
		float fZec127[8];
		float fZec128[8];
		float fZec129[8];
		float fRec290_tmp[12];
		float* fRec290 = &fRec290_tmp[4];
		float fZec130[8];
		float fRec291_tmp[12];
		float* fRec291 = &fRec291_tmp[4];
		float fRec292[8];
		float fRec293[8];
		float fRec294[8];
		float fSlow180 = 0.0f - 2.0f / fSlow159;
		float fRec349_tmp[12];
		float* fRec349 = &fRec349_tmp[4];
		float fRec348_tmp[12];
		float* fRec348 = &fRec348_tmp[4];
		float fSlow181 = fSlow166 + 0.00142857141f * fSlow81;
		float fZec131[8];
		float fSlow182 = fSlow83 - fSlow167;
		float fSlow183 = 0.142857149f * fSlow182;
		float fSlow184 = fSlow43 + fSlow167 + fSlow183;
		float fSlow185 = fSlow85 - fSlow169;
		float fSlow186 = fSlow169 + 0.142857149f * fSlow185;
		float fSlow187 = 0.5f * fSlow186;
		float fSlow188 = fSlow184 - fSlow187;
		float fSlow189 = fSlow43 + fSlow167 + fSlow183 + fSlow187;
		int iZec132[8];
		float fZec133[8];
		float fSlow190 = 0.5f / std::max<float>(1.1920929e-07f, fSlow186);
		float fZec134[8];
		float fSlow191 = fSlow90 * fSlow91;
		int iSlow192 = std::fabs(fSlow191) < 1.1920929e-07f;
		float fThen133 = std::exp(0.0f - fConst102 / ((iSlow192) ? 1.0f : fSlow191));
		float fSlow193 = ((iSlow192) ? 0.0f : fThen133);
		float fSlow194 = fSlow95 * fSlow96;
		int iSlow195 = std::fabs(fSlow194) < 1.1920929e-07f;
		float fThen135 = std::exp(0.0f - fConst102 / ((iSlow195) ? 1.0f : fSlow194));
		float fSlow196 = ((iSlow195) ? 0.0f : fThen135);
		float fZec135[8];
		float fRec347_tmp[12];
		float* fRec347 = &fRec347_tmp[4];
		float fRec352_tmp[12];
		float* fRec352 = &fRec352_tmp[4];
		float fRec351_tmp[12];
		float* fRec351 = &fRec351_tmp[4];
		float fZec136[8];
		int iZec137[8];
		float fZec138[8];
		float fZec139[8];
		float fZec140[8];
		float fRec350_tmp[12];
		float* fRec350 = &fRec350_tmp[4];
		float fZec141[8];
		float fSlow197 = float(fVslider38) - fSlow178;
		float fSlow198 = fSlow179 + 0.00142857141f * fSlow197;
		float fZec142[8];
		float fZec143[8];
		float fZec144[8];
		float fZec145[8];
		float fZec146[8];
		float fZec147[8];
		float fZec148[8];
		float fZec149[8];
		float fZec150[8];
		float fRec285_tmp[12];
		float* fRec285 = &fRec285_tmp[4];
		float fZec151[8];
		float fRec286_tmp[12];
		float* fRec286 = &fRec286_tmp[4];
		float fRec287[8];
		float fRec288[8];
		float fRec289[8];
		float fZec152[8];
		float fZec153[8];
		float fZec154[8];
		float fZec155[8];
		float fZec156[8];
		float fZec157[8];
		float fRec280_tmp[12];
		float* fRec280 = &fRec280_tmp[4];
		float fZec158[8];
		float fRec281_tmp[12];
		float* fRec281 = &fRec281_tmp[4];
		float fRec282[8];
		float fRec283[8];
		float fRec284[8];
		float fZec159[8];
		float fZec160[8];
		float fZec161[8];
		float fZec162[8];
		float fRec275_tmp[12];
		float* fRec275 = &fRec275_tmp[4];
		float fZec163[8];
		float fRec276_tmp[12];
		float* fRec276 = &fRec276_tmp[4];
		float fRec277[8];
		float fRec278[8];
		float fRec279[8];
		float fZec164[8];
		float fZec165[8];
		float fZec166[8];
		float fZec167[8];
		float fZec168[8];
		float fZec169[8];
		float fZec170[8];
		float fRec270_tmp[12];
		float* fRec270 = &fRec270_tmp[4];
		float fZec171[8];
		float fRec271_tmp[12];
		float* fRec271 = &fRec271_tmp[4];
		float fRec272[8];
		float fRec273[8];
		float fRec274[8];
		float fZec172[8];
		float fZec173[8];
		float fZec174[8];
		float fZec175[8];
		float fZec176[8];
		float fZec177[8];
		float fRec265_tmp[12];
		float* fRec265 = &fRec265_tmp[4];
		float fZec178[8];
		float fRec266_tmp[12];
		float* fRec266 = &fRec266_tmp[4];
		float fRec267[8];
		float fRec268[8];
		float fRec269[8];
		float fZec179[8];
		float fZec180[8];
		float fZec181[8];
		float fZec182[8];
		float fRec260_tmp[12];
		float* fRec260 = &fRec260_tmp[4];
		float fZec183[8];
		float fRec261_tmp[12];
		float* fRec261 = &fRec261_tmp[4];
		float fRec262[8];
		float fRec263[8];
		float fRec264[8];
		float fSlow199 = 0.0f - 2.0f / fSlow148;
		float fRec355_tmp[12];
		float* fRec355 = &fRec355_tmp[4];
		float fRec354_tmp[12];
		float* fRec354 = &fRec354_tmp[4];
		float fSlow200 = fSlow166 + 0.00285714283f * fSlow81;
		float fZec184[8];
		float fSlow201 = 0.285714298f * fSlow182;
		float fSlow202 = fSlow43 + fSlow167 + fSlow201;
		float fSlow203 = fSlow169 + 0.285714298f * fSlow185;
		float fSlow204 = 0.5f * fSlow203;
		float fSlow205 = fSlow202 - fSlow204;
		float fSlow206 = fSlow43 + fSlow167 + fSlow201 + fSlow204;
		int iZec185[8];
		float fZec186[8];
		float fSlow207 = 0.5f / std::max<float>(1.1920929e-07f, fSlow203);
		float fZec187[8];
		float fSlow208 = fSlow90 * mydsp_faustpower2_f(fSlow91);
		int iSlow209 = std::fabs(fSlow208) < 1.1920929e-07f;
		float fThen143 = std::exp(0.0f - fConst102 / ((iSlow209) ? 1.0f : fSlow208));
		float fSlow210 = ((iSlow209) ? 0.0f : fThen143);
		float fSlow211 = fSlow95 * mydsp_faustpower2_f(fSlow96);
		int iSlow212 = std::fabs(fSlow211) < 1.1920929e-07f;
		float fThen145 = std::exp(0.0f - fConst102 / ((iSlow212) ? 1.0f : fSlow211));
		float fSlow213 = ((iSlow212) ? 0.0f : fThen145);
		float fZec188[8];
		float fRec353_tmp[12];
		float* fRec353 = &fRec353_tmp[4];
		float fRec358_tmp[12];
		float* fRec358 = &fRec358_tmp[4];
		float fRec357_tmp[12];
		float* fRec357 = &fRec357_tmp[4];
		float fZec189[8];
		int iZec190[8];
		float fZec191[8];
		float fZec192[8];
		float fZec193[8];
		float fRec356_tmp[12];
		float* fRec356 = &fRec356_tmp[4];
		float fZec194[8];
		float fSlow214 = fSlow179 + 0.00285714283f * fSlow197;
		float fZec195[8];
		float fZec196[8];
		float fZec197[8];
		float fZec198[8];
		float fZec199[8];
		float fZec200[8];
		float fZec201[8];
		float fZec202[8];
		float fZec203[8];
		float fRec255_tmp[12];
		float* fRec255 = &fRec255_tmp[4];
		float fZec204[8];
		float fRec256_tmp[12];
		float* fRec256 = &fRec256_tmp[4];
		float fRec257[8];
		float fRec258[8];
		float fRec259[8];
		float fZec205[8];
		float fZec206[8];
		float fZec207[8];
		float fZec208[8];
		float fZec209[8];
		float fZec210[8];
		float fRec250_tmp[12];
		float* fRec250 = &fRec250_tmp[4];
		float fZec211[8];
		float fRec251_tmp[12];
		float* fRec251 = &fRec251_tmp[4];
		float fRec252[8];
		float fRec253[8];
		float fRec254[8];
		float fZec212[8];
		float fZec213[8];
		float fZec214[8];
		float fZec215[8];
		float fRec245_tmp[12];
		float* fRec245 = &fRec245_tmp[4];
		float fZec216[8];
		float fRec246_tmp[12];
		float* fRec246 = &fRec246_tmp[4];
		float fRec247[8];
		float fRec248[8];
		float fRec249[8];
		float fZec217[8];
		float fZec218[8];
		float fZec219[8];
		float fZec220[8];
		float fZec221[8];
		float fZec222[8];
		float fZec223[8];
		float fRec240_tmp[12];
		float* fRec240 = &fRec240_tmp[4];
		float fZec224[8];
		float fRec241_tmp[12];
		float* fRec241 = &fRec241_tmp[4];
		float fRec242[8];
		float fRec243[8];
		float fRec244[8];
		float fZec225[8];
		float fZec226[8];
		float fZec227[8];
		float fZec228[8];
		float fZec229[8];
		float fZec230[8];
		float fRec235_tmp[12];
		float* fRec235 = &fRec235_tmp[4];
		float fZec231[8];
		float fRec236_tmp[12];
		float* fRec236 = &fRec236_tmp[4];
		float fRec237[8];
		float fRec238[8];
		float fRec239[8];
		float fZec232[8];
		float fZec233[8];
		float fZec234[8];
		float fZec235[8];
		float fRec230_tmp[12];
		float* fRec230 = &fRec230_tmp[4];
		float fZec236[8];
		float fRec231_tmp[12];
		float* fRec231 = &fRec231_tmp[4];
		float fRec232[8];
		float fRec233[8];
		float fRec234[8];
		float fSlow215 = 0.0f - 2.0f / fSlow137;
		float fRec361_tmp[12];
		float* fRec361 = &fRec361_tmp[4];
		float fRec360_tmp[12];
		float* fRec360 = &fRec360_tmp[4];
		float fSlow216 = fSlow166 + 0.00428571412f * fSlow81;
		float fZec237[8];
		float fSlow217 = 0.428571433f * fSlow182;
		float fSlow218 = fSlow43 + fSlow167 + fSlow217;
		float fSlow219 = fSlow169 + 0.428571433f * fSlow185;
		float fSlow220 = 0.5f * fSlow219;
		float fSlow221 = fSlow218 - fSlow220;
		float fSlow222 = fSlow43 + fSlow167 + fSlow217 + fSlow220;
		int iZec238[8];
		float fZec239[8];
		float fSlow223 = 0.5f / std::max<float>(1.1920929e-07f, fSlow219);
		float fZec240[8];
		float fSlow224 = fSlow90 * mydsp_faustpower3_f(fSlow91);
		int iSlow225 = std::fabs(fSlow224) < 1.1920929e-07f;
		float fThen153 = std::exp(0.0f - fConst102 / ((iSlow225) ? 1.0f : fSlow224));
		float fSlow226 = ((iSlow225) ? 0.0f : fThen153);
		float fSlow227 = fSlow95 * mydsp_faustpower3_f(fSlow96);
		int iSlow228 = std::fabs(fSlow227) < 1.1920929e-07f;
		float fThen155 = std::exp(0.0f - fConst102 / ((iSlow228) ? 1.0f : fSlow227));
		float fSlow229 = ((iSlow228) ? 0.0f : fThen155);
		float fZec241[8];
		float fRec359_tmp[12];
		float* fRec359 = &fRec359_tmp[4];
		float fRec364_tmp[12];
		float* fRec364 = &fRec364_tmp[4];
		float fRec363_tmp[12];
		float* fRec363 = &fRec363_tmp[4];
		float fZec242[8];
		int iZec243[8];
		float fZec244[8];
		float fZec245[8];
		float fZec246[8];
		float fRec362_tmp[12];
		float* fRec362 = &fRec362_tmp[4];
		float fZec247[8];
		float fSlow230 = fSlow179 + 0.00428571412f * fSlow197;
		float fZec248[8];
		float fZec249[8];
		float fZec250[8];
		float fZec251[8];
		float fZec252[8];
		float fZec253[8];
		float fZec254[8];
		float fZec255[8];
		float fZec256[8];
		float fRec225_tmp[12];
		float* fRec225 = &fRec225_tmp[4];
		float fZec257[8];
		float fRec226_tmp[12];
		float* fRec226 = &fRec226_tmp[4];
		float fRec227[8];
		float fRec228[8];
		float fRec229[8];
		float fZec258[8];
		float fZec259[8];
		float fZec260[8];
		float fZec261[8];
		float fZec262[8];
		float fZec263[8];
		float fRec220_tmp[12];
		float* fRec220 = &fRec220_tmp[4];
		float fZec264[8];
		float fRec221_tmp[12];
		float* fRec221 = &fRec221_tmp[4];
		float fRec222[8];
		float fRec223[8];
		float fRec224[8];
		float fZec265[8];
		float fZec266[8];
		float fZec267[8];
		float fZec268[8];
		float fRec215_tmp[12];
		float* fRec215 = &fRec215_tmp[4];
		float fZec269[8];
		float fRec216_tmp[12];
		float* fRec216 = &fRec216_tmp[4];
		float fRec217[8];
		float fRec218[8];
		float fRec219[8];
		float fZec270[8];
		float fZec271[8];
		float fZec272[8];
		float fZec273[8];
		float fZec274[8];
		float fZec275[8];
		float fZec276[8];
		float fRec210_tmp[12];
		float* fRec210 = &fRec210_tmp[4];
		float fZec277[8];
		float fRec211_tmp[12];
		float* fRec211 = &fRec211_tmp[4];
		float fRec212[8];
		float fRec213[8];
		float fRec214[8];
		float fZec278[8];
		float fZec279[8];
		float fZec280[8];
		float fZec281[8];
		float fZec282[8];
		float fZec283[8];
		float fRec205_tmp[12];
		float* fRec205 = &fRec205_tmp[4];
		float fZec284[8];
		float fRec206_tmp[12];
		float* fRec206 = &fRec206_tmp[4];
		float fRec207[8];
		float fRec208[8];
		float fRec209[8];
		float fZec285[8];
		float fZec286[8];
		float fZec287[8];
		float fZec288[8];
		float fRec200_tmp[12];
		float* fRec200 = &fRec200_tmp[4];
		float fZec289[8];
		float fRec201_tmp[12];
		float* fRec201 = &fRec201_tmp[4];
		float fRec202[8];
		float fRec203[8];
		float fRec204[8];
		float fSlow231 = 0.0f - 2.0f / fSlow126;
		float fRec367_tmp[12];
		float* fRec367 = &fRec367_tmp[4];
		float fRec366_tmp[12];
		float* fRec366 = &fRec366_tmp[4];
		float fSlow232 = fSlow166 + 0.00571428565f * fSlow81;
		float fZec290[8];
		float fSlow233 = 0.571428597f * fSlow182;
		float fSlow234 = fSlow43 + fSlow167 + fSlow233;
		float fSlow235 = fSlow169 + 0.571428597f * fSlow185;
		float fSlow236 = 0.5f * fSlow235;
		float fSlow237 = fSlow234 - fSlow236;
		float fSlow238 = fSlow43 + fSlow167 + fSlow233 + fSlow236;
		int iZec291[8];
		float fZec292[8];
		float fSlow239 = 0.5f / std::max<float>(1.1920929e-07f, fSlow235);
		float fZec293[8];
		float fSlow240 = fSlow90 * mydsp_faustpower4_f(fSlow91);
		int iSlow241 = std::fabs(fSlow240) < 1.1920929e-07f;
		float fThen163 = std::exp(0.0f - fConst102 / ((iSlow241) ? 1.0f : fSlow240));
		float fSlow242 = ((iSlow241) ? 0.0f : fThen163);
		float fSlow243 = fSlow95 * mydsp_faustpower4_f(fSlow96);
		int iSlow244 = std::fabs(fSlow243) < 1.1920929e-07f;
		float fThen165 = std::exp(0.0f - fConst102 / ((iSlow244) ? 1.0f : fSlow243));
		float fSlow245 = ((iSlow244) ? 0.0f : fThen165);
		float fZec294[8];
		float fRec365_tmp[12];
		float* fRec365 = &fRec365_tmp[4];
		float fRec370_tmp[12];
		float* fRec370 = &fRec370_tmp[4];
		float fRec369_tmp[12];
		float* fRec369 = &fRec369_tmp[4];
		float fZec295[8];
		int iZec296[8];
		float fZec297[8];
		float fZec298[8];
		float fZec299[8];
		float fRec368_tmp[12];
		float* fRec368 = &fRec368_tmp[4];
		float fZec300[8];
		float fSlow246 = fSlow179 + 0.00571428565f * fSlow197;
		float fZec301[8];
		float fZec302[8];
		float fZec303[8];
		float fZec304[8];
		float fZec305[8];
		float fZec306[8];
		float fZec307[8];
		float fZec308[8];
		float fZec309[8];
		float fRec195_tmp[12];
		float* fRec195 = &fRec195_tmp[4];
		float fZec310[8];
		float fRec196_tmp[12];
		float* fRec196 = &fRec196_tmp[4];
		float fRec197[8];
		float fRec198[8];
		float fRec199[8];
		float fZec311[8];
		float fZec312[8];
		float fZec313[8];
		float fZec314[8];
		float fZec315[8];
		float fZec316[8];
		float fRec190_tmp[12];
		float* fRec190 = &fRec190_tmp[4];
		float fZec317[8];
		float fRec191_tmp[12];
		float* fRec191 = &fRec191_tmp[4];
		float fRec192[8];
		float fRec193[8];
		float fRec194[8];
		float fZec318[8];
		float fZec319[8];
		float fZec320[8];
		float fZec321[8];
		float fRec185_tmp[12];
		float* fRec185 = &fRec185_tmp[4];
		float fZec322[8];
		float fRec186_tmp[12];
		float* fRec186 = &fRec186_tmp[4];
		float fRec187[8];
		float fRec188[8];
		float fRec189[8];
		float fZec323[8];
		float fZec324[8];
		float fZec325[8];
		float fZec326[8];
		float fZec327[8];
		float fZec328[8];
		float fZec329[8];
		float fRec180_tmp[12];
		float* fRec180 = &fRec180_tmp[4];
		float fZec330[8];
		float fRec181_tmp[12];
		float* fRec181 = &fRec181_tmp[4];
		float fRec182[8];
		float fRec183[8];
		float fRec184[8];
		float fZec331[8];
		float fZec332[8];
		float fZec333[8];
		float fZec334[8];
		float fZec335[8];
		float fZec336[8];
		float fRec175_tmp[12];
		float* fRec175 = &fRec175_tmp[4];
		float fZec337[8];
		float fRec176_tmp[12];
		float* fRec176 = &fRec176_tmp[4];
		float fRec177[8];
		float fRec178[8];
		float fRec179[8];
		float fZec338[8];
		float fZec339[8];
		float fZec340[8];
		float fZec341[8];
		float fRec170_tmp[12];
		float* fRec170 = &fRec170_tmp[4];
		float fZec342[8];
		float fRec171_tmp[12];
		float* fRec171 = &fRec171_tmp[4];
		float fRec172[8];
		float fRec173[8];
		float fRec174[8];
		float fSlow247 = 0.0f - 2.0f / fSlow115;
		float fRec373_tmp[12];
		float* fRec373 = &fRec373_tmp[4];
		float fRec372_tmp[12];
		float* fRec372 = &fRec372_tmp[4];
		float fSlow248 = fSlow166 + 0.00714285718f * fSlow81;
		float fZec343[8];
		float fSlow249 = 0.714285731f * fSlow182;
		float fSlow250 = fSlow43 + fSlow167 + fSlow249;
		float fSlow251 = fSlow169 + 0.714285731f * fSlow185;
		float fSlow252 = 0.5f * fSlow251;
		float fSlow253 = fSlow250 - fSlow252;
		float fSlow254 = fSlow43 + fSlow167 + fSlow249 + fSlow252;
		int iZec344[8];
		float fZec345[8];
		float fSlow255 = 0.5f / std::max<float>(1.1920929e-07f, fSlow251);
		float fZec346[8];
		float fSlow256 = fSlow90 * mydsp_faustpower5_f(fSlow91);
		int iSlow257 = std::fabs(fSlow256) < 1.1920929e-07f;
		float fThen173 = std::exp(0.0f - fConst102 / ((iSlow257) ? 1.0f : fSlow256));
		float fSlow258 = ((iSlow257) ? 0.0f : fThen173);
		float fSlow259 = fSlow95 * mydsp_faustpower5_f(fSlow96);
		int iSlow260 = std::fabs(fSlow259) < 1.1920929e-07f;
		float fThen175 = std::exp(0.0f - fConst102 / ((iSlow260) ? 1.0f : fSlow259));
		float fSlow261 = ((iSlow260) ? 0.0f : fThen175);
		float fZec347[8];
		float fRec371_tmp[12];
		float* fRec371 = &fRec371_tmp[4];
		float fRec376_tmp[12];
		float* fRec376 = &fRec376_tmp[4];
		float fRec375_tmp[12];
		float* fRec375 = &fRec375_tmp[4];
		float fZec348[8];
		int iZec349[8];
		float fZec350[8];
		float fZec351[8];
		float fZec352[8];
		float fRec374_tmp[12];
		float* fRec374 = &fRec374_tmp[4];
		float fZec353[8];
		float fSlow262 = fSlow179 + 0.00714285718f * fSlow197;
		float fZec354[8];
		float fZec355[8];
		float fZec356[8];
		float fZec357[8];
		float fZec358[8];
		float fZec359[8];
		float fZec360[8];
		float fZec361[8];
		float fZec362[8];
		float fRec165_tmp[12];
		float* fRec165 = &fRec165_tmp[4];
		float fZec363[8];
		float fRec166_tmp[12];
		float* fRec166 = &fRec166_tmp[4];
		float fRec167[8];
		float fRec168[8];
		float fRec169[8];
		float fZec364[8];
		float fZec365[8];
		float fZec366[8];
		float fZec367[8];
		float fZec368[8];
		float fZec369[8];
		float fRec160_tmp[12];
		float* fRec160 = &fRec160_tmp[4];
		float fZec370[8];
		float fRec161_tmp[12];
		float* fRec161 = &fRec161_tmp[4];
		float fRec162[8];
		float fRec163[8];
		float fRec164[8];
		float fZec371[8];
		float fZec372[8];
		float fZec373[8];
		float fZec374[8];
		float fRec155_tmp[12];
		float* fRec155 = &fRec155_tmp[4];
		float fZec375[8];
		float fRec156_tmp[12];
		float* fRec156 = &fRec156_tmp[4];
		float fRec157[8];
		float fRec158[8];
		float fRec159[8];
		float fZec376[8];
		float fZec377[8];
		float fZec378[8];
		float fZec379[8];
		float fZec380[8];
		float fZec381[8];
		float fZec382[8];
		float fRec150_tmp[12];
		float* fRec150 = &fRec150_tmp[4];
		float fZec383[8];
		float fRec151_tmp[12];
		float* fRec151 = &fRec151_tmp[4];
		float fRec152[8];
		float fRec153[8];
		float fRec154[8];
		float fZec384[8];
		float fZec385[8];
		float fZec386[8];
		float fZec387[8];
		float fZec388[8];
		float fZec389[8];
		float fRec145_tmp[12];
		float* fRec145 = &fRec145_tmp[4];
		float fZec390[8];
		float fRec146_tmp[12];
		float* fRec146 = &fRec146_tmp[4];
		float fRec147[8];
		float fRec148[8];
		float fRec149[8];
		float fZec391[8];
		float fZec392[8];
		float fZec393[8];
		float fZec394[8];
		float fRec140_tmp[12];
		float* fRec140 = &fRec140_tmp[4];
		float fZec395[8];
		float fRec141_tmp[12];
		float* fRec141 = &fRec141_tmp[4];
		float fRec142[8];
		float fRec143[8];
		float fRec144[8];
		float fSlow263 = 0.0f - 2.0f / fSlow104;
		float fRec379_tmp[12];
		float* fRec379 = &fRec379_tmp[4];
		float fRec378_tmp[12];
		float* fRec378 = &fRec378_tmp[4];
		float fSlow264 = fSlow166 + 0.00857142825f * fSlow81;
		float fZec396[8];
		float fSlow265 = 0.857142866f * fSlow182;
		float fSlow266 = fSlow43 + fSlow167 + fSlow265;
		float fSlow267 = fSlow169 + 0.857142866f * fSlow185;
		float fSlow268 = 0.5f * fSlow267;
		float fSlow269 = fSlow266 - fSlow268;
		float fSlow270 = fSlow43 + fSlow167 + fSlow265 + fSlow268;
		int iZec397[8];
		float fZec398[8];
		float fSlow271 = 0.5f / std::max<float>(1.1920929e-07f, fSlow267);
		float fZec399[8];
		float fSlow272 = fSlow90 * mydsp_faustpower6_f(fSlow91);
		int iSlow273 = std::fabs(fSlow272) < 1.1920929e-07f;
		float fThen183 = std::exp(0.0f - fConst102 / ((iSlow273) ? 1.0f : fSlow272));
		float fSlow274 = ((iSlow273) ? 0.0f : fThen183);
		float fSlow275 = fSlow95 * mydsp_faustpower6_f(fSlow96);
		int iSlow276 = std::fabs(fSlow275) < 1.1920929e-07f;
		float fThen185 = std::exp(0.0f - fConst102 / ((iSlow276) ? 1.0f : fSlow275));
		float fSlow277 = ((iSlow276) ? 0.0f : fThen185);
		float fZec400[8];
		float fRec377_tmp[12];
		float* fRec377 = &fRec377_tmp[4];
		float fRec382_tmp[12];
		float* fRec382 = &fRec382_tmp[4];
		float fRec381_tmp[12];
		float* fRec381 = &fRec381_tmp[4];
		float fZec401[8];
		int iZec402[8];
		float fZec403[8];
		float fZec404[8];
		float fZec405[8];
		float fRec380_tmp[12];
		float* fRec380 = &fRec380_tmp[4];
		float fZec406[8];
		float fSlow278 = fSlow179 + 0.00857142825f * fSlow197;
		float fZec407[8];
		float fZec408[8];
		float fZec409[8];
		float fZec410[8];
		float fZec411[8];
		float fZec412[8];
		float fZec413[8];
		float fZec414[8];
		float fZec415[8];
		float fRec135_tmp[12];
		float* fRec135 = &fRec135_tmp[4];
		float fZec416[8];
		float fRec136_tmp[12];
		float* fRec136 = &fRec136_tmp[4];
		float fRec137[8];
		float fRec138[8];
		float fRec139[8];
		float fZec417[8];
		float fZec418[8];
		float fZec419[8];
		float fZec420[8];
		float fZec421[8];
		float fZec422[8];
		float fRec130_tmp[12];
		float* fRec130 = &fRec130_tmp[4];
		float fZec423[8];
		float fRec131_tmp[12];
		float* fRec131 = &fRec131_tmp[4];
		float fRec132[8];
		float fRec133[8];
		float fRec134[8];
		float fZec424[8];
		float fZec425[8];
		float fZec426[8];
		float fZec427[8];
		float fRec125_tmp[12];
		float* fRec125 = &fRec125_tmp[4];
		float fZec428[8];
		float fRec126_tmp[12];
		float* fRec126 = &fRec126_tmp[4];
		float fRec127[8];
		float fRec128[8];
		float fRec129[8];
		float fZec429[8];
		float fZec430[8];
		float fZec431[8];
		float fZec432[8];
		float fZec433[8];
		float fZec434[8];
		float fZec435[8];
		float fRec120_tmp[12];
		float* fRec120 = &fRec120_tmp[4];
		float fZec436[8];
		float fRec121_tmp[12];
		float* fRec121 = &fRec121_tmp[4];
		float fRec122[8];
		float fRec123[8];
		float fRec124[8];
		float fZec437[8];
		float fZec438[8];
		float fZec439[8];
		float fZec440[8];
		float fZec441[8];
		float fZec442[8];
		float fRec115_tmp[12];
		float* fRec115 = &fRec115_tmp[4];
		float fZec443[8];
		float fRec116_tmp[12];
		float* fRec116 = &fRec116_tmp[4];
		float fRec117[8];
		float fRec118[8];
		float fRec119[8];
		float fZec444[8];
		float fZec445[8];
		float fZec446[8];
		float fZec447[8];
		float fRec110_tmp[12];
		float* fRec110 = &fRec110_tmp[4];
		float fZec448[8];
		float fRec111_tmp[12];
		float* fRec111 = &fRec111_tmp[4];
		float fRec112[8];
		float fRec113[8];
		float fRec114[8];
		float fSlow279 = 0.00999999978f * (fSlow178 + fSlow197);
		float fZec449[8];
		float fZec450[8];
		float fZec451[8];
		float fZec452[8];
		float fZec453[8];
		float fZec454[8];
		float fZec455[8];
		float fZec456[8];
		float fZec457[8];
		float fRec105_tmp[12];
		float* fRec105 = &fRec105_tmp[4];
		float fZec458[8];
		float fRec106_tmp[12];
		float* fRec106 = &fRec106_tmp[4];
		float fRec107[8];
		float fRec108[8];
		float fRec109[8];
		float fZec459[8];
		float fZec460[8];
		float fZec461[8];
		float fZec462[8];
		float fZec463[8];
		float fZec464[8];
		float fRec100_tmp[12];
		float* fRec100 = &fRec100_tmp[4];
		float fZec465[8];
		float fRec101_tmp[12];
		float* fRec101 = &fRec101_tmp[4];
		float fRec102[8];
		float fRec103[8];
		float fRec104[8];
		float fZec466[8];
		float fZec467[8];
		float fZec468[8];
		float fZec469[8];
		float fRec95_tmp[12];
		float* fRec95 = &fRec95_tmp[4];
		float fZec470[8];
		float fRec96_tmp[12];
		float* fRec96 = &fRec96_tmp[4];
		float fRec97[8];
		float fRec98[8];
		float fRec99[8];
		float fZec471[8];
		float fZec472[8];
		float fZec473[8];
		float fZec474[8];
		float fZec475[8];
		float fZec476[8];
		float fZec477[8];
		float fRec588_tmp[12];
		float* fRec588 = &fRec588_tmp[4];
		float fZec478[8];
		float fRec589_tmp[12];
		float* fRec589 = &fRec589_tmp[4];
		float fRec590[8];
		float fRec591[8];
		float fRec592[8];
		float fZec479[8];
		float fZec480[8];
		float fZec481[8];
		float fZec482[8];
		float fZec483[8];
		float fZec484[8];
		float fRec583_tmp[12];
		float* fRec583 = &fRec583_tmp[4];
		float fZec485[8];
		float fRec584_tmp[12];
		float* fRec584 = &fRec584_tmp[4];
		float fRec585[8];
		float fRec586[8];
		float fRec587[8];
		float fZec486[8];
		float fZec487[8];
		float fZec488[8];
		float fZec489[8];
		float fRec578_tmp[12];
		float* fRec578 = &fRec578_tmp[4];
		float fZec490[8];
		float fRec579_tmp[12];
		float* fRec579 = &fRec579_tmp[4];
		float fRec580[8];
		float fRec581[8];
		float fRec582[8];
		float fZec491[8];
		float fZec492[8];
		float fZec493[8];
		float fZec494[8];
		float fZec495[8];
		float fZec496[8];
		float fZec497[8];
		float fZec498[8];
		float fZec499[8];
		float fRec573_tmp[12];
		float* fRec573 = &fRec573_tmp[4];
		float fZec500[8];
		float fRec574_tmp[12];
		float* fRec574 = &fRec574_tmp[4];
		float fRec575[8];
		float fRec576[8];
		float fRec577[8];
		float fZec501[8];
		float fZec502[8];
		float fZec503[8];
		float fZec504[8];
		float fZec505[8];
		float fZec506[8];
		float fRec568_tmp[12];
		float* fRec568 = &fRec568_tmp[4];
		float fZec507[8];
		float fRec569_tmp[12];
		float* fRec569 = &fRec569_tmp[4];
		float fRec570[8];
		float fRec571[8];
		float fRec572[8];
		float fZec508[8];
		float fZec509[8];
		float fZec510[8];
		float fZec511[8];
		float fRec563_tmp[12];
		float* fRec563 = &fRec563_tmp[4];
		float fZec512[8];
		float fRec564_tmp[12];
		float* fRec564 = &fRec564_tmp[4];
		float fRec565[8];
		float fRec566[8];
		float fRec567[8];
		float fZec513[8];
		float fZec514[8];
		float fZec515[8];
		float fZec516[8];
		float fZec517[8];
		float fZec518[8];
		float fZec519[8];
		float fRec558_tmp[12];
		float* fRec558 = &fRec558_tmp[4];
		float fZec520[8];
		float fRec559_tmp[12];
		float* fRec559 = &fRec559_tmp[4];
		float fRec560[8];
		float fRec561[8];
		float fRec562[8];
		float fZec521[8];
		float fZec522[8];
		float fZec523[8];
		float fZec524[8];
		float fZec525[8];
		float fZec526[8];
		float fRec553_tmp[12];
		float* fRec553 = &fRec553_tmp[4];
		float fZec527[8];
		float fRec554_tmp[12];
		float* fRec554 = &fRec554_tmp[4];
		float fRec555[8];
		float fRec556[8];
		float fRec557[8];
		float fZec528[8];
		float fZec529[8];
		float fZec530[8];
		float fZec531[8];
		float fRec548_tmp[12];
		float* fRec548 = &fRec548_tmp[4];
		float fZec532[8];
		float fRec549_tmp[12];
		float* fRec549 = &fRec549_tmp[4];
		float fRec550[8];
		float fRec551[8];
		float fRec552[8];
		float fZec533[8];
		float fZec534[8];
		float fZec535[8];
		float fZec536[8];
		float fZec537[8];
		float fZec538[8];
		float fZec539[8];
		float fZec540[8];
		float fZec541[8];
		float fRec543_tmp[12];
		float* fRec543 = &fRec543_tmp[4];
		float fZec542[8];
		float fRec544_tmp[12];
		float* fRec544 = &fRec544_tmp[4];
		float fRec545[8];
		float fRec546[8];
		float fRec547[8];
		float fZec543[8];
		float fZec544[8];
		float fZec545[8];
		float fZec546[8];
		float fZec547[8];
		float fZec548[8];
		float fRec538_tmp[12];
		float* fRec538 = &fRec538_tmp[4];
		float fZec549[8];
		float fRec539_tmp[12];
		float* fRec539 = &fRec539_tmp[4];
		float fRec540[8];
		float fRec541[8];
		float fRec542[8];
		float fZec550[8];
		float fZec551[8];
		float fZec552[8];
		float fZec553[8];
		float fRec533_tmp[12];
		float* fRec533 = &fRec533_tmp[4];
		float fZec554[8];
		float fRec534_tmp[12];
		float* fRec534 = &fRec534_tmp[4];
		float fRec535[8];
		float fRec536[8];
		float fRec537[8];
		float fZec555[8];
		float fZec556[8];
		float fZec557[8];
		float fZec558[8];
		float fZec559[8];
		float fZec560[8];
		float fZec561[8];
		float fRec528_tmp[12];
		float* fRec528 = &fRec528_tmp[4];
		float fZec562[8];
		float fRec529_tmp[12];
		float* fRec529 = &fRec529_tmp[4];
		float fRec530[8];
		float fRec531[8];
		float fRec532[8];
		float fZec563[8];
		float fZec564[8];
		float fZec565[8];
		float fZec566[8];
		float fZec567[8];
		float fZec568[8];
		float fRec523_tmp[12];
		float* fRec523 = &fRec523_tmp[4];
		float fZec569[8];
		float fRec524_tmp[12];
		float* fRec524 = &fRec524_tmp[4];
		float fRec525[8];
		float fRec526[8];
		float fRec527[8];
		float fZec570[8];
		float fZec571[8];
		float fZec572[8];
		float fZec573[8];
		float fRec518_tmp[12];
		float* fRec518 = &fRec518_tmp[4];
		float fZec574[8];
		float fRec519_tmp[12];
		float* fRec519 = &fRec519_tmp[4];
		float fRec520[8];
		float fRec521[8];
		float fRec522[8];
		float fZec575[8];
		float fZec576[8];
		float fZec577[8];
		float fZec578[8];
		float fZec579[8];
		float fZec580[8];
		float fZec581[8];
		float fZec582[8];
		float fZec583[8];
		float fRec513_tmp[12];
		float* fRec513 = &fRec513_tmp[4];
		float fZec584[8];
		float fRec514_tmp[12];
		float* fRec514 = &fRec514_tmp[4];
		float fRec515[8];
		float fRec516[8];
		float fRec517[8];
		float fZec585[8];
		float fZec586[8];
		float fZec587[8];
		float fZec588[8];
		float fZec589[8];
		float fZec590[8];
		float fRec508_tmp[12];
		float* fRec508 = &fRec508_tmp[4];
		float fZec591[8];
		float fRec509_tmp[12];
		float* fRec509 = &fRec509_tmp[4];
		float fRec510[8];
		float fRec511[8];
		float fRec512[8];
		float fZec592[8];
		float fZec593[8];
		float fZec594[8];
		float fZec595[8];
		float fRec503_tmp[12];
		float* fRec503 = &fRec503_tmp[4];
		float fZec596[8];
		float fRec504_tmp[12];
		float* fRec504 = &fRec504_tmp[4];
		float fRec505[8];
		float fRec506[8];
		float fRec507[8];
		float fZec597[8];
		float fZec598[8];
		float fZec599[8];
		float fZec600[8];
		float fZec601[8];
		float fZec602[8];
		float fZec603[8];
		float fRec498_tmp[12];
		float* fRec498 = &fRec498_tmp[4];
		float fZec604[8];
		float fRec499_tmp[12];
		float* fRec499 = &fRec499_tmp[4];
		float fRec500[8];
		float fRec501[8];
		float fRec502[8];
		float fZec605[8];
		float fZec606[8];
		float fZec607[8];
		float fZec608[8];
		float fZec609[8];
		float fZec610[8];
		float fRec493_tmp[12];
		float* fRec493 = &fRec493_tmp[4];
		float fZec611[8];
		float fRec494_tmp[12];
		float* fRec494 = &fRec494_tmp[4];
		float fRec495[8];
		float fRec496[8];
		float fRec497[8];
		float fZec612[8];
		float fZec613[8];
		float fZec614[8];
		float fZec615[8];
		float fRec488_tmp[12];
		float* fRec488 = &fRec488_tmp[4];
		float fZec616[8];
		float fRec489_tmp[12];
		float* fRec489 = &fRec489_tmp[4];
		float fRec490[8];
		float fRec491[8];
		float fRec492[8];
		float fZec617[8];
		float fZec618[8];
		float fZec619[8];
		float fZec620[8];
		float fZec621[8];
		float fZec622[8];
		float fZec623[8];
		float fZec624[8];
		float fZec625[8];
		float fRec483_tmp[12];
		float* fRec483 = &fRec483_tmp[4];
		float fZec626[8];
		float fRec484_tmp[12];
		float* fRec484 = &fRec484_tmp[4];
		float fRec485[8];
		float fRec486[8];
		float fRec487[8];
		float fZec627[8];
		float fZec628[8];
		float fZec629[8];
		float fZec630[8];
		float fZec631[8];
		float fZec632[8];
		float fRec478_tmp[12];
		float* fRec478 = &fRec478_tmp[4];
		float fZec633[8];
		float fRec479_tmp[12];
		float* fRec479 = &fRec479_tmp[4];
		float fRec480[8];
		float fRec481[8];
		float fRec482[8];
		float fZec634[8];
		float fZec635[8];
		float fZec636[8];
		float fZec637[8];
		float fRec473_tmp[12];
		float* fRec473 = &fRec473_tmp[4];
		float fZec638[8];
		float fRec474_tmp[12];
		float* fRec474 = &fRec474_tmp[4];
		float fRec475[8];
		float fRec476[8];
		float fRec477[8];
		float fZec639[8];
		float fZec640[8];
		float fZec641[8];
		float fZec642[8];
		float fZec643[8];
		float fZec644[8];
		float fZec645[8];
		float fRec468_tmp[12];
		float* fRec468 = &fRec468_tmp[4];
		float fZec646[8];
		float fRec469_tmp[12];
		float* fRec469 = &fRec469_tmp[4];
		float fRec470[8];
		float fRec471[8];
		float fRec472[8];
		float fZec647[8];
		float fZec648[8];
		float fZec649[8];
		float fZec650[8];
		float fZec651[8];
		float fZec652[8];
		float fRec463_tmp[12];
		float* fRec463 = &fRec463_tmp[4];
		float fZec653[8];
		float fRec464_tmp[12];
		float* fRec464 = &fRec464_tmp[4];
		float fRec465[8];
		float fRec466[8];
		float fRec467[8];
		float fZec654[8];
		float fZec655[8];
		float fZec656[8];
		float fZec657[8];
		float fRec458_tmp[12];
		float* fRec458 = &fRec458_tmp[4];
		float fZec658[8];
		float fRec459_tmp[12];
		float* fRec459 = &fRec459_tmp[4];
		float fRec460[8];
		float fRec461[8];
		float fRec462[8];
		float fZec659[8];
		float fZec660[8];
		float fZec661[8];
		float fZec662[8];
		float fZec663[8];
		float fZec664[8];
		float fZec665[8];
		float fZec666[8];
		float fZec667[8];
		float fRec453_tmp[12];
		float* fRec453 = &fRec453_tmp[4];
		float fZec668[8];
		float fRec454_tmp[12];
		float* fRec454 = &fRec454_tmp[4];
		float fRec455[8];
		float fRec456[8];
		float fRec457[8];
		float fZec669[8];
		float fZec670[8];
		float fZec671[8];
		float fZec672[8];
		float fZec673[8];
		float fZec674[8];
		float fRec448_tmp[12];
		float* fRec448 = &fRec448_tmp[4];
		float fZec675[8];
		float fRec449_tmp[12];
		float* fRec449 = &fRec449_tmp[4];
		float fRec450[8];
		float fRec451[8];
		float fRec452[8];
		float fZec676[8];
		float fZec677[8];
		float fZec678[8];
		float fZec679[8];
		float fRec443_tmp[12];
		float* fRec443 = &fRec443_tmp[4];
		float fZec680[8];
		float fRec444_tmp[12];
		float* fRec444 = &fRec444_tmp[4];
		float fRec445[8];
		float fRec446[8];
		float fRec447[8];
		float fZec681[8];
		float fZec682[8];
		float fZec683[8];
		float fZec684[8];
		float fZec685[8];
		float fZec686[8];
		float fZec687[8];
		float fRec438_tmp[12];
		float* fRec438 = &fRec438_tmp[4];
		float fZec688[8];
		float fRec439_tmp[12];
		float* fRec439 = &fRec439_tmp[4];
		float fRec440[8];
		float fRec441[8];
		float fRec442[8];
		float fZec689[8];
		float fZec690[8];
		float fZec691[8];
		float fZec692[8];
		float fZec693[8];
		float fZec694[8];
		float fRec433_tmp[12];
		float* fRec433 = &fRec433_tmp[4];
		float fZec695[8];
		float fRec434_tmp[12];
		float* fRec434 = &fRec434_tmp[4];
		float fRec435[8];
		float fRec436[8];
		float fRec437[8];
		float fZec696[8];
		float fZec697[8];
		float fZec698[8];
		float fZec699[8];
		float fRec428_tmp[12];
		float* fRec428 = &fRec428_tmp[4];
		float fZec700[8];
		float fRec429_tmp[12];
		float* fRec429 = &fRec429_tmp[4];
		float fRec430[8];
		float fRec431[8];
		float fRec432[8];
		float fZec701[8];
		float fZec702[8];
		float fZec703[8];
		float fZec704[8];
		float fZec705[8];
		float fZec706[8];
		float fZec707[8];
		float fZec708[8];
		float fZec709[8];
		float fRec423_tmp[12];
		float* fRec423 = &fRec423_tmp[4];
		float fZec710[8];
		float fRec424_tmp[12];
		float* fRec424 = &fRec424_tmp[4];
		float fRec425[8];
		float fRec426[8];
		float fRec427[8];
		float fZec711[8];
		float fZec712[8];
		float fZec713[8];
		float fZec714[8];
		float fZec715[8];
		float fZec716[8];
		float fRec418_tmp[12];
		float* fRec418 = &fRec418_tmp[4];
		float fZec717[8];
		float fRec419_tmp[12];
		float* fRec419 = &fRec419_tmp[4];
		float fRec420[8];
		float fRec421[8];
		float fRec422[8];
		float fZec718[8];
		float fZec719[8];
		float fZec720[8];
		float fZec721[8];
		float fRec413_tmp[12];
		float* fRec413 = &fRec413_tmp[4];
		float fZec722[8];
		float fRec414_tmp[12];
		float* fRec414 = &fRec414_tmp[4];
		float fRec415[8];
		float fRec416[8];
		float fRec417[8];
		float fZec723[8];
		float fZec724[8];
		float fZec725[8];
		float fZec726[8];
		float fZec727[8];
		float fZec728[8];
		float fZec729[8];
		float fRec408_tmp[12];
		float* fRec408 = &fRec408_tmp[4];
		float fZec730[8];
		float fRec409_tmp[12];
		float* fRec409 = &fRec409_tmp[4];
		float fRec410[8];
		float fRec411[8];
		float fRec412[8];
		float fZec731[8];
		float fZec732[8];
		float fZec733[8];
		float fZec734[8];
		float fZec735[8];
		float fZec736[8];
		float fRec403_tmp[12];
		float* fRec403 = &fRec403_tmp[4];
		float fZec737[8];
		float fRec404_tmp[12];
		float* fRec404 = &fRec404_tmp[4];
		float fRec405[8];
		float fRec406[8];
		float fRec407[8];
		float fZec738[8];
		float fZec739[8];
		float fZec740[8];
		float fZec741[8];
		float fRec398_tmp[12];
		float* fRec398 = &fRec398_tmp[4];
		float fZec742[8];
		float fRec399_tmp[12];
		float* fRec399 = &fRec399_tmp[4];
		float fRec400[8];
		float fRec401[8];
		float fRec402[8];
		float fZec743[8];
		float fZec744[8];
		float fZec745[8];
		float fZec746[8];
		float fZec747[8];
		float fZec748[8];
		float fZec749[8];
		float fZec750[8];
		float fRec393_tmp[12];
		float* fRec393 = &fRec393_tmp[4];
		float fZec751[8];
		float fRec394_tmp[12];
		float* fRec394 = &fRec394_tmp[4];
		float fRec395[8];
		float fRec396[8];
		float fRec397[8];
		float fZec752[8];
		float fZec753[8];
		float fZec754[8];
		float fZec755[8];
		float fZec756[8];
		float fZec757[8];
		float fRec388_tmp[12];
		float* fRec388 = &fRec388_tmp[4];
		float fZec758[8];
		float fRec389_tmp[12];
		float* fRec389 = &fRec389_tmp[4];
		float fRec390[8];
		float fRec391[8];
		float fRec392[8];
		float fZec759[8];
		float fZec760[8];
		float fZec761[8];
		float fZec762[8];
		float fRec383_tmp[12];
		float* fRec383 = &fRec383_tmp[4];
		float fZec763[8];
		float fRec384_tmp[12];
		float* fRec384 = &fRec384_tmp[4];
		float fRec385[8];
		float fRec386[8];
		float fRec387[8];
		float fZec764[8];
		float fSlow280 = 0.00999999978f * float(fVslider39);
		float fZec765[8];
		float fZec766[8];
		float fZec767[8];
		float fZec768[8];
		float fZec769[8];
		int iSlow281 = std::max<int>(1, int(fConst103 * float(fVslider40)));
		float fSlow282 = 1.0f / float(iSlow281);
		int iSlow283 = std::max<int>(0, iSlow281);
		float fZec770[8];
		float fSlow284 = 0.00100000005f * float(fVslider41);
		int iSlow285 = std::fabs(fSlow284) < 1.1920929e-07f;
		float fThen191 = std::exp(0.0f - fConst102 / ((iSlow285) ? 1.0f : fSlow284));
		float fSlow286 = ((iSlow285) ? 0.0f : fThen191);
		float fZec771[8];
		float fRec593_tmp[12];
		float* fRec593 = &fRec593_tmp[4];
		float fZec772[8];
		float fZec773[8];
		float fZec774[8];
		float fZec775[8];
		float fRec595_tmp[12];
		float* fRec595 = &fRec595_tmp[4];
		float fSlow287 = 0.00999999978f * float(fVslider42) * (2.0f - fSlow280);
		float fZec776[8];
		float fSlow288 = float(fVslider43);
		float fSlow289 = fSlow43 + fSlow288;
		float fSlow290 = float(fVslider44);
		float fSlow291 = 0.5f * fSlow290;
		float fSlow292 = fSlow289 - fSlow291;
		float fSlow293 = fSlow43 + fSlow288 + fSlow291;
		int iZec777[8];
		float fZec778[8];
		float fSlow294 = 0.5f / std::max<float>(1.1920929e-07f, fSlow290);
		float fZec779[8];
		int iZec780[8];
		float fZec781[8];
		float fZec782[8];
		float fZec783[8];
		float fRec5_tmp[12];
		float* fRec5 = &fRec5_tmp[4];
		float fRec6_tmp[12];
		float* fRec6 = &fRec6_tmp[4];
		float fSlow295 = fConst1 * std::pow(10.0f, 0.0500000007f * float(fVslider45));
		float fRec597_tmp[12];
		float* fRec597 = &fRec597_tmp[4];
		float fSlow296 = fConst1 * float(fCheckbox11);
		float fRec598_tmp[12];
		float* fRec598 = &fRec598_tmp[4];
		float fSlow297 = fConst1 * float(fCheckbox12);
		float fRec599_tmp[12];
		float* fRec599 = &fRec599_tmp[4];
		float fZec784[8];
		float fZec785[8];
		float fZec786[8];
		float fSlow298 = 0.00100000005f * float(fVslider46);
		int iSlow299 = std::fabs(fSlow298) < 1.1920929e-07f;
		float fThen199 = std::exp(0.0f - fConst102 / ((iSlow299) ? 1.0f : fSlow298));
		float fSlow300 = ((iSlow299) ? 0.0f : fThen199);
		float fZec787[8];
		float fRec600_tmp[12];
		float* fRec600 = &fRec600_tmp[4];
		float fZec788[8];
		float fZec789[8];
		float fZec790[8];
		float fRec601_tmp[12];
		float* fRec601 = &fRec601_tmp[4];
		float fZec791[8];
		float fSlow301 = float(fVslider47);
		int iZec792[8];
		float fZec793[8];
		float fZec794[8];
		int iZec795[8];
		float fZec796[8];
		float fZec797[8];
		float fZec798[8];
		float fRec3_tmp[12];
		float* fRec3 = &fRec3_tmp[4];
		float fRec4_tmp[12];
		float* fRec4 = &fRec4_tmp[4];
		float fRec1_tmp[12];
		float* fRec1 = &fRec1_tmp[4];
		float fRec2_tmp[12];
		float* fRec2 = &fRec2_tmp[4];
		float fZec799[8];
		float fYec106_tmp[12];
		float* fYec106 = &fYec106_tmp[4];
		float fRec602_tmp[12];
		float* fRec602 = &fRec602_tmp[4];
		float fYec107_tmp[12];
		float* fYec107 = &fYec107_tmp[4];
		float fRec606_tmp[12];
		float* fRec606 = &fRec606_tmp[4];
		float fRec605_tmp[12];
		float* fRec605 = &fRec605_tmp[4];
		float fYec108_tmp[12];
		float* fYec108 = &fYec108_tmp[4];
		float fRec604_tmp[12];
		float* fRec604 = &fRec604_tmp[4];
		float fRec603_tmp[12];
		float* fRec603 = &fRec603_tmp[4];
		float fYec109_tmp[12];
		float* fYec109 = &fYec109_tmp[4];
		float fYec110_tmp[12];
		float* fYec110 = &fYec110_tmp[4];
		float fRec610_tmp[12];
		float* fRec610 = &fRec610_tmp[4];
		float fRec609_tmp[12];
		float* fRec609 = &fRec609_tmp[4];
		float fYec111_tmp[12];
		float* fYec111 = &fYec111_tmp[4];
		float fRec608_tmp[12];
		float* fRec608 = &fRec608_tmp[4];
		float fRec607_tmp[12];
		float* fRec607 = &fRec607_tmp[4];
		float fYec112_tmp[12];
		float* fYec112 = &fYec112_tmp[4];
		float fYec113_tmp[12];
		float* fYec113 = &fYec113_tmp[4];
		float fYec114_tmp[16];
		float* fYec114 = &fYec114_tmp[8];
		float fYec115_tmp[24];
		float* fYec115 = &fYec115_tmp[16];
		float fYec132_tmp[12];
		float* fYec132 = &fYec132_tmp[4];
		float fYec133_tmp[12];
		float* fYec133 = &fYec133_tmp[4];
		float fYec134_tmp[16];
		float* fYec134 = &fYec134_tmp[8];
		float fYec135_tmp[24];
		float* fYec135 = &fYec135_tmp[16];
		float fZec800[8];
		float fRec611_tmp[12];
		float* fRec611 = &fRec611_tmp[4];
		for (int vindex = 0; vindex < count; vindex = vindex + 8) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* input1 = &input1_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			FAUSTFLOAT* output1 = &output1_ptr[vindex];
			int vsize = std::min<int>(8, count - vindex);
			/* Recursive loop 0 */
			/* Pre code */
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				fRec16_tmp[j14] = fRec16_perm[j14];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec16[i] = fSlow7 + fConst2 * fRec16[i - 1];
			}
			/* Post code */
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				fRec16_perm[j15] = fRec16_tmp[vsize + j15];
			}
			/* Vectorizable loop 1 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = float(input0[i]) * fRec16[i];
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec1[i] = float(input1[i]) * fRec16[i];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				fRec17_tmp[j16] = fRec17_perm[j16];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec17[i] = std::max<float>(fRec17[i - 1] - fConst3, std::min<float>(10.0f, 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::max<float>(0.000316227757f, std::fabs(fZec0[i]))))));
			}
			/* Post code */
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				fRec17_perm[j17] = fRec17_tmp[vsize + j17];
			}
			/* Recursive loop 4 */
			/* Pre code */
			for (int j24 = 0; j24 < 4; j24 = j24 + 1) {
				fRec21_tmp[j24] = fRec21_perm[j24];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec21[i] = std::max<float>(fRec21[i - 1] - fConst3, std::min<float>(10.0f, 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::max<float>(0.000316227757f, std::fabs(fZec1[i]))))));
			}
			/* Post code */
			for (int j25 = 0; j25 < 4; j25 = j25 + 1) {
				fRec21_perm[j25] = fRec21_tmp[vsize + j25];
			}
			/* Vectorizable loop 5 */
			/* Pre code */
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fYec0_tmp[j20] = fYec0_perm[j20];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph0 = FAUSTFLOAT(fRec17[i]);
				fYec0[i] = fZec0[i];
			}
			/* Post code */
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fYec0_perm[j21] = fYec0_tmp[vsize + j21];
			}
			/* Vectorizable loop 6 */
			/* Pre code */
			for (int j38 = 0; j38 < 4; j38 = j38 + 1) {
				fYec3_tmp[j38] = fYec3_perm[j38];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph1 = FAUSTFLOAT(fRec21[i]);
				fYec3[i] = fZec1[i];
			}
			/* Post code */
			for (int j39 = 0; j39 < 4; j39 = j39 + 1) {
				fYec3_perm[j39] = fYec3_tmp[vsize + j39];
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j26 = 0; j26 < 4; j26 = j26 + 1) {
				fYec1_tmp[j26] = fYec1_perm[j26];
			}
			for (int j28 = 0; j28 < 4; j28 = j28 + 1) {
				fRec25_tmp[j28] = fRec25_perm[j28];
			}
			for (int j30 = 0; j30 < 4; j30 = j30 + 1) {
				fRec24_tmp[j30] = fRec24_perm[j30];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec1[i] = 0.0f - fConst8 * (fConst9 * fRec24[i - 1] - fConst10 * fYec0[i - 1]);
				fRec25[i] = fYec1[i - 1] + fConst8 * (fConst11 * fYec0[i] - 2.0f * (fConst13 * fRec25[i - 1] - fConst14 * fYec0[i - 1]));
				fRec24[i] = fRec25[i];
			}
			/* Post code */
			for (int j27 = 0; j27 < 4; j27 = j27 + 1) {
				fYec1_perm[j27] = fYec1_tmp[vsize + j27];
			}
			for (int j29 = 0; j29 < 4; j29 = j29 + 1) {
				fRec25_perm[j29] = fRec25_tmp[vsize + j29];
			}
			for (int j31 = 0; j31 < 4; j31 = j31 + 1) {
				fRec24_perm[j31] = fRec24_tmp[vsize + j31];
			}
			/* Recursive loop 8 */
			/* Pre code */
			for (int j40 = 0; j40 < 4; j40 = j40 + 1) {
				fYec4_tmp[j40] = fYec4_perm[j40];
			}
			for (int j42 = 0; j42 < 4; j42 = j42 + 1) {
				fRec29_tmp[j42] = fRec29_perm[j42];
			}
			for (int j44 = 0; j44 < 4; j44 = j44 + 1) {
				fRec28_tmp[j44] = fRec28_perm[j44];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec4[i] = 0.0f - fConst8 * (fConst9 * fRec28[i - 1] - fConst10 * fYec3[i - 1]);
				fRec29[i] = fYec4[i - 1] + fConst8 * (fConst11 * fYec3[i] - 2.0f * (fConst13 * fRec29[i - 1] - fConst14 * fYec3[i - 1]));
				fRec28[i] = fRec29[i];
			}
			/* Post code */
			for (int j41 = 0; j41 < 4; j41 = j41 + 1) {
				fYec4_perm[j41] = fYec4_tmp[vsize + j41];
			}
			for (int j43 = 0; j43 < 4; j43 = j43 + 1) {
				fRec29_perm[j43] = fRec29_tmp[vsize + j43];
			}
			for (int j45 = 0; j45 < 4; j45 = j45 + 1) {
				fRec28_perm[j45] = fRec28_tmp[vsize + j45];
			}
			/* Recursive loop 9 */
			/* Pre code */
			for (int j32 = 0; j32 < 4; j32 = j32 + 1) {
				fYec2_tmp[j32] = fYec2_perm[j32];
			}
			for (int j34 = 0; j34 < 4; j34 = j34 + 1) {
				fRec23_tmp[j34] = fRec23_perm[j34];
			}
			for (int j36 = 0; j36 < 4; j36 = j36 + 1) {
				fRec22_tmp[j36] = fRec22_perm[j36];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec2[i] = 0.500327051f * fRec24[i - 1] - fConst20 * fRec22[i - 1];
				fRec23[i] = fConst18 * fRec24[i - 1] + fConst19 * (fYec2[i - 1] - fConst21 * fRec23[i - 1] + 0.500327051f * fRec24[i]);
				fRec22[i] = fRec23[i];
			}
			/* Post code */
			for (int j33 = 0; j33 < 4; j33 = j33 + 1) {
				fYec2_perm[j33] = fYec2_tmp[vsize + j33];
			}
			for (int j35 = 0; j35 < 4; j35 = j35 + 1) {
				fRec23_perm[j35] = fRec23_tmp[vsize + j35];
			}
			for (int j37 = 0; j37 < 4; j37 = j37 + 1) {
				fRec22_perm[j37] = fRec22_tmp[vsize + j37];
			}
			/* Recursive loop 10 */
			/* Pre code */
			for (int j46 = 0; j46 < 4; j46 = j46 + 1) {
				fYec5_tmp[j46] = fYec5_perm[j46];
			}
			for (int j48 = 0; j48 < 4; j48 = j48 + 1) {
				fRec27_tmp[j48] = fRec27_perm[j48];
			}
			for (int j50 = 0; j50 < 4; j50 = j50 + 1) {
				fRec26_tmp[j50] = fRec26_perm[j50];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec5[i] = 0.500327051f * fRec28[i - 1] - fConst20 * fRec26[i - 1];
				fRec27[i] = fConst18 * fRec28[i - 1] + fConst19 * (fYec5[i - 1] - fConst21 * fRec27[i - 1] + 0.500327051f * fRec28[i]);
				fRec26[i] = fRec27[i];
			}
			/* Post code */
			for (int j47 = 0; j47 < 4; j47 = j47 + 1) {
				fYec5_perm[j47] = fYec5_tmp[vsize + j47];
			}
			for (int j49 = 0; j49 < 4; j49 = j49 + 1) {
				fRec27_perm[j49] = fRec27_tmp[vsize + j49];
			}
			for (int j51 = 0; j51 < 4; j51 = j51 + 1) {
				fRec26_perm[j51] = fRec26_tmp[vsize + j51];
			}
			/* Vectorizable loop 11 */
			/* Pre code */
			for (int j52 = 0; j52 < 4; j52 = j52 + 1) {
				fYec6_tmp[j52] = fYec6_perm[j52];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec6[i] = mydsp_faustpower2_f(fRec22[i]);
			}
			/* Post code */
			for (int j53 = 0; j53 < 4; j53 = j53 + 1) {
				fYec6_perm[j53] = fYec6_tmp[vsize + j53];
			}
			/* Vectorizable loop 12 */
			/* Pre code */
			for (int j60 = 0; j60 < 4; j60 = j60 + 1) {
				fYec26_tmp[j60] = fYec26_perm[j60];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec26[i] = mydsp_faustpower2_f(fRec26[i]);
			}
			/* Post code */
			for (int j61 = 0; j61 < 4; j61 = j61 + 1) {
				fYec26_perm[j61] = fYec26_tmp[vsize + j61];
			}
			/* Vectorizable loop 13 */
			/* Pre code */
			for (int j54 = 0; j54 < 4; j54 = j54 + 1) {
				fYec7_tmp[j54] = fYec7_perm[j54];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec7[i] = fYec6[i] + fYec6[i - 1];
			}
			/* Post code */
			for (int j55 = 0; j55 < 4; j55 = j55 + 1) {
				fYec7_perm[j55] = fYec7_tmp[vsize + j55];
			}
			/* Vectorizable loop 14 */
			/* Pre code */
			for (int j62 = 0; j62 < 4; j62 = j62 + 1) {
				fYec27_tmp[j62] = fYec27_perm[j62];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec27[i] = fYec26[i] + fYec26[i - 1];
			}
			/* Post code */
			for (int j63 = 0; j63 < 4; j63 = j63 + 1) {
				fYec27_perm[j63] = fYec27_tmp[vsize + j63];
			}
			/* Vectorizable loop 15 */
			/* Pre code */
			for (int j56 = 0; j56 < 8; j56 = j56 + 1) {
				fYec8_tmp[j56] = fYec8_perm[j56];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec8[i] = fYec7[i] + fYec7[i - 2];
			}
			/* Post code */
			for (int j57 = 0; j57 < 8; j57 = j57 + 1) {
				fYec8_perm[j57] = fYec8_tmp[vsize + j57];
			}
			/* Vectorizable loop 16 */
			/* Pre code */
			for (int j64 = 0; j64 < 8; j64 = j64 + 1) {
				fYec28_tmp[j64] = fYec28_perm[j64];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec28[i] = fYec27[i] + fYec27[i - 2];
			}
			/* Post code */
			for (int j65 = 0; j65 < 8; j65 = j65 + 1) {
				fYec28_perm[j65] = fYec28_tmp[vsize + j65];
			}
			/* Vectorizable loop 17 */
			/* Pre code */
			for (int j58 = 0; j58 < 16; j58 = j58 + 1) {
				fYec9_tmp[j58] = fYec9_perm[j58];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec9[i] = fYec8[i] + fYec8[i - 4];
			}
			/* Post code */
			for (int j59 = 0; j59 < 16; j59 = j59 + 1) {
				fYec9_perm[j59] = fYec9_tmp[vsize + j59];
			}
			/* Vectorizable loop 18 */
			/* Pre code */
			for (int j66 = 0; j66 < 16; j66 = j66 + 1) {
				fYec29_tmp[j66] = fYec29_perm[j66];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec29[i] = fYec28[i] + fYec28[i - 4];
			}
			/* Post code */
			for (int j67 = 0; j67 < 16; j67 = j67 + 1) {
				fYec29_perm[j67] = fYec29_tmp[vsize + j67];
			}
			/* Vectorizable loop 19 */
			/* Pre code */
			fYec10_idx = (fYec10_idx + fYec10_idx_save) & 63;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec10[(i + fYec10_idx) & 63] = fYec9[i] + fYec9[i - 8];
			}
			/* Post code */
			fYec10_idx_save = vsize;
			/* Vectorizable loop 20 */
			/* Pre code */
			fYec30_idx = (fYec30_idx + fYec30_idx_save) & 63;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec30[(i + fYec30_idx) & 63] = fYec29[i] + fYec29[i - 8];
			}
			/* Post code */
			fYec30_idx_save = vsize;
			/* Vectorizable loop 21 */
			/* Pre code */
			fYec11_idx = (fYec11_idx + fYec11_idx_save) & 127;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec11[(i + fYec11_idx) & 127] = fYec10[(i + fYec10_idx) & 63] + fYec10[((i + fYec10_idx) - 16) & 63];
			}
			/* Post code */
			fYec11_idx_save = vsize;
			/* Vectorizable loop 22 */
			/* Pre code */
			fYec31_idx = (fYec31_idx + fYec31_idx_save) & 127;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec31[(i + fYec31_idx) & 127] = fYec30[(i + fYec30_idx) & 63] + fYec30[((i + fYec30_idx) - 16) & 63];
			}
			/* Post code */
			fYec31_idx_save = vsize;
			/* Vectorizable loop 23 */
			/* Pre code */
			fYec12_idx = (fYec12_idx + fYec12_idx_save) & 255;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec12[(i + fYec12_idx) & 255] = fYec11[(i + fYec11_idx) & 127] + fYec11[((i + fYec11_idx) - 32) & 127];
			}
			/* Post code */
			fYec12_idx_save = vsize;
			/* Vectorizable loop 24 */
			/* Pre code */
			fYec32_idx = (fYec32_idx + fYec32_idx_save) & 255;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec32[(i + fYec32_idx) & 255] = fYec31[(i + fYec31_idx) & 127] + fYec31[((i + fYec31_idx) - 32) & 127];
			}
			/* Post code */
			fYec32_idx_save = vsize;
			/* Vectorizable loop 25 */
			/* Pre code */
			fYec13_idx = (fYec13_idx + fYec13_idx_save) & 511;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec13[(i + fYec13_idx) & 511] = fYec12[(i + fYec12_idx) & 255] + fYec12[((i + fYec12_idx) - 64) & 255];
			}
			/* Post code */
			fYec13_idx_save = vsize;
			/* Vectorizable loop 26 */
			/* Pre code */
			fYec33_idx = (fYec33_idx + fYec33_idx_save) & 511;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec33[(i + fYec33_idx) & 511] = fYec32[(i + fYec32_idx) & 255] + fYec32[((i + fYec32_idx) - 64) & 255];
			}
			/* Post code */
			fYec33_idx_save = vsize;
			/* Vectorizable loop 27 */
			/* Pre code */
			fYec14_idx = (fYec14_idx + fYec14_idx_save) & 1023;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec14[(i + fYec14_idx) & 1023] = fYec13[(i + fYec13_idx) & 511] + fYec13[((i + fYec13_idx) - 128) & 511];
			}
			/* Post code */
			fYec14_idx_save = vsize;
			/* Vectorizable loop 28 */
			/* Pre code */
			fYec34_idx = (fYec34_idx + fYec34_idx_save) & 1023;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec34[(i + fYec34_idx) & 1023] = fYec33[(i + fYec33_idx) & 511] + fYec33[((i + fYec33_idx) - 128) & 511];
			}
			/* Post code */
			fYec34_idx_save = vsize;
			/* Vectorizable loop 29 */
			/* Pre code */
			fYec15_idx = (fYec15_idx + fYec15_idx_save) & 2047;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec15[(i + fYec15_idx) & 2047] = fYec14[(i + fYec14_idx) & 1023] + fYec14[((i + fYec14_idx) - 256) & 1023];
			}
			/* Post code */
			fYec15_idx_save = vsize;
			/* Vectorizable loop 30 */
			/* Pre code */
			fYec35_idx = (fYec35_idx + fYec35_idx_save) & 2047;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec35[(i + fYec35_idx) & 2047] = fYec34[(i + fYec34_idx) & 1023] + fYec34[((i + fYec34_idx) - 256) & 1023];
			}
			/* Post code */
			fYec35_idx_save = vsize;
			/* Vectorizable loop 31 */
			/* Pre code */
			fYec16_idx = (fYec16_idx + fYec16_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec16[(i + fYec16_idx) & 4095] = fYec15[(i + fYec15_idx) & 2047] + fYec15[((i + fYec15_idx) - 512) & 2047];
			}
			/* Post code */
			fYec16_idx_save = vsize;
			/* Vectorizable loop 32 */
			/* Pre code */
			fYec36_idx = (fYec36_idx + fYec36_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec36[(i + fYec36_idx) & 4095] = fYec35[(i + fYec35_idx) & 2047] + fYec35[((i + fYec35_idx) - 512) & 2047];
			}
			/* Post code */
			fYec36_idx_save = vsize;
			/* Vectorizable loop 33 */
			/* Pre code */
			fYec17_idx = (fYec17_idx + fYec17_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec17[(i + fYec17_idx) & 8191] = fYec16[(i + fYec16_idx) & 4095] + fYec16[((i + fYec16_idx) - 1024) & 4095];
			}
			/* Post code */
			fYec17_idx_save = vsize;
			/* Vectorizable loop 34 */
			/* Pre code */
			fYec37_idx = (fYec37_idx + fYec37_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec37[(i + fYec37_idx) & 8191] = fYec36[(i + fYec36_idx) & 4095] + fYec36[((i + fYec36_idx) - 1024) & 4095];
			}
			/* Post code */
			fYec37_idx_save = vsize;
			/* Vectorizable loop 35 */
			/* Pre code */
			fYec18_idx = (fYec18_idx + fYec18_idx_save) & 16383;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec18[(i + fYec18_idx) & 16383] = fYec17[(i + fYec17_idx) & 8191] + fYec17[((i + fYec17_idx) - 2048) & 8191];
			}
			/* Post code */
			fYec18_idx_save = vsize;
			/* Vectorizable loop 36 */
			/* Pre code */
			fYec38_idx = (fYec38_idx + fYec38_idx_save) & 16383;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec38[(i + fYec38_idx) & 16383] = fYec37[(i + fYec37_idx) & 8191] + fYec37[((i + fYec37_idx) - 2048) & 8191];
			}
			/* Post code */
			fYec38_idx_save = vsize;
			/* Vectorizable loop 37 */
			/* Pre code */
			fYec19_idx = (fYec19_idx + fYec19_idx_save) & 32767;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec19[(i + fYec19_idx) & 32767] = fYec18[(i + fYec18_idx) & 16383] + fYec18[((i + fYec18_idx) - 4096) & 16383];
			}
			/* Post code */
			fYec19_idx_save = vsize;
			/* Vectorizable loop 38 */
			/* Pre code */
			fYec39_idx = (fYec39_idx + fYec39_idx_save) & 32767;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec39[(i + fYec39_idx) & 32767] = fYec38[(i + fYec38_idx) & 16383] + fYec38[((i + fYec38_idx) - 4096) & 16383];
			}
			/* Post code */
			fYec39_idx_save = vsize;
			/* Vectorizable loop 39 */
			/* Pre code */
			fYec20_idx = (fYec20_idx + fYec20_idx_save) & 65535;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec20[(i + fYec20_idx) & 65535] = fYec19[(i + fYec19_idx) & 32767] + fYec19[((i + fYec19_idx) - 8192) & 32767];
			}
			/* Post code */
			fYec20_idx_save = vsize;
			/* Vectorizable loop 40 */
			/* Pre code */
			fYec40_idx = (fYec40_idx + fYec40_idx_save) & 65535;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec40[(i + fYec40_idx) & 65535] = fYec39[(i + fYec39_idx) & 32767] + fYec39[((i + fYec39_idx) - 8192) & 32767];
			}
			/* Post code */
			fYec40_idx_save = vsize;
			/* Vectorizable loop 41 */
			/* Pre code */
			fYec21_idx = (fYec21_idx + fYec21_idx_save) & 131071;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec21[(i + fYec21_idx) & 131071] = fYec20[(i + fYec20_idx) & 65535] + fYec20[((i + fYec20_idx) - 16384) & 65535];
			}
			/* Post code */
			fYec21_idx_save = vsize;
			/* Vectorizable loop 42 */
			/* Pre code */
			fYec41_idx = (fYec41_idx + fYec41_idx_save) & 131071;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec41[(i + fYec41_idx) & 131071] = fYec40[(i + fYec40_idx) & 65535] + fYec40[((i + fYec40_idx) - 16384) & 65535];
			}
			/* Post code */
			fYec41_idx_save = vsize;
			/* Vectorizable loop 43 */
			/* Pre code */
			fYec22_idx = (fYec22_idx + fYec22_idx_save) & 262143;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec22[(i + fYec22_idx) & 262143] = fYec21[(i + fYec21_idx) & 131071] + fYec21[((i + fYec21_idx) - 32768) & 131071];
			}
			/* Post code */
			fYec22_idx_save = vsize;
			/* Vectorizable loop 44 */
			/* Pre code */
			fYec42_idx = (fYec42_idx + fYec42_idx_save) & 262143;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec42[(i + fYec42_idx) & 262143] = fYec41[(i + fYec41_idx) & 131071] + fYec41[((i + fYec41_idx) - 32768) & 131071];
			}
			/* Post code */
			fYec42_idx_save = vsize;
			/* Vectorizable loop 45 */
			/* Pre code */
			fYec23_idx = (fYec23_idx + fYec23_idx_save) & 524287;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec23[(i + fYec23_idx) & 524287] = fYec22[(i + fYec22_idx) & 262143] + fYec22[((i + fYec22_idx) - 65536) & 262143];
			}
			/* Post code */
			fYec23_idx_save = vsize;
			/* Vectorizable loop 46 */
			/* Pre code */
			fYec43_idx = (fYec43_idx + fYec43_idx_save) & 524287;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec43[(i + fYec43_idx) & 524287] = fYec42[(i + fYec42_idx) & 262143] + fYec42[((i + fYec42_idx) - 65536) & 262143];
			}
			/* Post code */
			fYec43_idx_save = vsize;
			/* Vectorizable loop 47 */
			/* Pre code */
			fYec24_idx = (fYec24_idx + fYec24_idx_save) & 1048575;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec24[(i + fYec24_idx) & 1048575] = fYec23[(i + fYec23_idx) & 524287] + fYec23[((i + fYec23_idx) - 131072) & 524287];
			}
			/* Post code */
			fYec24_idx_save = vsize;
			/* Vectorizable loop 48 */
			/* Pre code */
			fYec44_idx = (fYec44_idx + fYec44_idx_save) & 1048575;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec44[(i + fYec44_idx) & 1048575] = fYec43[(i + fYec43_idx) & 524287] + fYec43[((i + fYec43_idx) - 131072) & 524287];
			}
			/* Post code */
			fYec44_idx_save = vsize;
			/* Vectorizable loop 49 */
			/* Pre code */
			fYec25_idx = (fYec25_idx + fYec25_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec25[(i + fYec25_idx) & 2097151] = fYec24[(i + fYec24_idx) & 1048575] + fYec24[((i + fYec24_idx) - 262144) & 1048575];
			}
			/* Post code */
			fYec25_idx_save = vsize;
			/* Vectorizable loop 50 */
			/* Pre code */
			fYec45_idx = (fYec45_idx + fYec45_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec45[(i + fYec45_idx) & 2097151] = fYec44[(i + fYec44_idx) & 1048575] + fYec44[((i + fYec44_idx) - 262144) & 1048575];
			}
			/* Post code */
			fYec45_idx_save = vsize;
			/* Recursive loop 51 */
			/* Pre code */
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec18_tmp[j18] = fRec18_perm[j18];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec18[i] = fSlow8 + fConst2 * fRec18[i - 1];
			}
			/* Post code */
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec18_perm[j19] = fRec18_tmp[vsize + j19];
			}
			/* Vectorizable loop 52 */
			/* Pre code */
			for (int j68 = 0; j68 < 4; j68 = j68 + 1) {
				fYec46_tmp[j68] = fYec46_perm[j68];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				float fElse0 = fYec25[((i + fYec25_idx) - iConst61) & 2097151];
				float fElse1 = fYec24[((i + fYec24_idx) - iConst63) & 1048575];
				float fElse2 = fYec23[((i + fYec23_idx) - iConst65) & 524287];
				float fElse3 = fYec22[((i + fYec22_idx) - iConst67) & 262143];
				float fElse4 = fYec21[((i + fYec21_idx) - iConst69) & 131071];
				float fElse5 = fYec20[((i + fYec20_idx) - iConst71) & 65535];
				float fElse6 = fYec19[((i + fYec19_idx) - iConst73) & 32767];
				float fElse7 = fYec18[((i + fYec18_idx) - iConst75) & 16383];
				float fElse8 = fYec17[((i + fYec17_idx) - iConst77) & 8191];
				float fElse9 = fYec16[((i + fYec16_idx) - iConst79) & 4095];
				float fElse10 = fYec15[((i + fYec15_idx) - iConst81) & 2047];
				float fElse11 = fYec14[((i + fYec14_idx) - iConst83) & 1023];
				float fElse12 = fYec13[((i + fYec13_idx) - iConst85) & 511];
				float fElse13 = fYec12[((i + fYec12_idx) - iConst87) & 255];
				float fElse14 = fYec11[((i + fYec11_idx) - iConst89) & 127];
				float fElse15 = fYec10[((i + fYec10_idx) - iConst91) & 63];
				float fElse16 = fYec9[i - iConst93];
				float fElse17 = fYec8[i - iConst95];
				float fElse18 = fYec6[i];
				float fElse19 = fYec7[i - iConst96];
				float fElse20 = fYec45[((i + fYec45_idx) - iConst61) & 2097151];
				float fElse21 = fYec44[((i + fYec44_idx) - iConst63) & 1048575];
				float fElse22 = fYec43[((i + fYec43_idx) - iConst65) & 524287];
				float fElse23 = fYec42[((i + fYec42_idx) - iConst67) & 262143];
				float fElse24 = fYec41[((i + fYec41_idx) - iConst69) & 131071];
				float fElse25 = fYec40[((i + fYec40_idx) - iConst71) & 65535];
				float fElse26 = fYec39[((i + fYec39_idx) - iConst73) & 32767];
				float fElse27 = fYec38[((i + fYec38_idx) - iConst75) & 16383];
				float fElse28 = fYec37[((i + fYec37_idx) - iConst77) & 8191];
				float fElse29 = fYec36[((i + fYec36_idx) - iConst79) & 4095];
				float fElse30 = fYec35[((i + fYec35_idx) - iConst81) & 2047];
				float fElse31 = fYec34[((i + fYec34_idx) - iConst83) & 1023];
				float fElse32 = fYec33[((i + fYec33_idx) - iConst85) & 511];
				float fElse33 = fYec32[((i + fYec32_idx) - iConst87) & 255];
				float fElse34 = fYec31[((i + fYec31_idx) - iConst89) & 127];
				float fElse35 = fYec30[((i + fYec30_idx) - iConst91) & 63];
				float fElse36 = fYec29[i - iConst93];
				float fElse37 = fYec28[i - iConst95];
				float fElse38 = fYec26[i];
				float fElse39 = fYec27[i - iConst96];
				fVbargraph2 = FAUSTFLOAT(4.34294462f * std::log(std::max<float>(9.99999996e-13f, fConst23 * (((iConst24) ? fElse0 : 0.0f) + ((iConst62) ? fElse1 : 0.0f) + ((iConst64) ? fElse2 : 0.0f) + ((iConst66) ? fElse3 : 0.0f) + ((iConst68) ? fElse4 : 0.0f) + ((iConst70) ? fElse5 : 0.0f) + ((iConst72) ? fElse6 : 0.0f) + ((iConst74) ? fElse7 : 0.0f) + ((iConst76) ? fElse8 : 0.0f) + ((iConst78) ? fElse9 : 0.0f) + ((iConst80) ? fElse10 : 0.0f) + ((iConst82) ? fElse11 : 0.0f) + ((iConst84) ? fElse12 : 0.0f) + ((iConst86) ? fElse13 : 0.0f) + ((iConst88) ? fElse14 : 0.0f) + ((iConst90) ? fElse15 : 0.0f) + ((iConst92) ? fElse16 : 0.0f) + ((iConst94) ? fElse17 : 0.0f) + ((iConst96) ? fElse18 : 0.0f) + ((iConst97) ? fElse19 : 0.0f) + ((iConst24) ? fElse20 : 0.0f) + ((iConst62) ? fElse21 : 0.0f) + ((iConst64) ? fElse22 : 0.0f) + ((iConst66) ? fElse23 : 0.0f) + ((iConst68) ? fElse24 : 0.0f) + ((iConst70) ? fElse25 : 0.0f) + ((iConst72) ? fElse26 : 0.0f) + ((iConst74) ? fElse27 : 0.0f) + ((iConst76) ? fElse28 : 0.0f) + ((iConst78) ? fElse29 : 0.0f) + ((iConst80) ? fElse30 : 0.0f) + ((iConst82) ? fElse31 : 0.0f) + ((iConst84) ? fElse32 : 0.0f) + ((iConst86) ? fElse33 : 0.0f) + ((iConst88) ? fElse34 : 0.0f) + ((iConst90) ? fElse35 : 0.0f) + ((iConst92) ? fElse36 : 0.0f) + ((iConst94) ? fElse37 : 0.0f) + ((iConst96) ? fElse38 : 0.0f) + ((iConst97) ? fElse39 : 0.0f)))) + -0.690999985f);
				fYec46[i] = fYec3[i];
			}
			/* Post code */
			for (int j69 = 0; j69 < 4; j69 = j69 + 1) {
				fYec46_perm[j69] = fYec46_tmp[vsize + j69];
			}
			/* Recursive loop 53 */
			/* Pre code */
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec19_tmp[j22] = fRec19_perm[j22];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec19[i] = fConst5 * (fYec0[i] - fYec0[i - 1] + fConst6 * fRec19[i - 1]);
			}
			/* Post code */
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec19_perm[j23] = fRec19_tmp[vsize + j23];
			}
			/* Recursive loop 54 */
			/* Pre code */
			for (int j70 = 0; j70 < 4; j70 = j70 + 1) {
				fRec20_tmp[j70] = fRec20_perm[j70];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec20[i] = fConst5 * (fYec46[i] - fYec46[i - 1] + fConst6 * fRec20[i - 1]);
			}
			/* Post code */
			for (int j71 = 0; j71 < 4; j71 = j71 + 1) {
				fRec20_perm[j71] = fRec20_tmp[vsize + j71];
			}
			/* Vectorizable loop 55 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec2[i] = 1.0f - fRec18[i];
			}
			/* Vectorizable loop 56 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec3[i] = fYec0[i] * fRec18[i] + fRec19[i] * fZec2[i];
			}
			/* Vectorizable loop 57 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec5[i] = fRec20[i] * fZec2[i] + fRec18[i] * fYec46[i];
			}
			/* Recursive loop 58 */
			/* Pre code */
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				fRec15_tmp[j12] = fRec15_perm[j12];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec15[i] = fSlow6 + fConst2 * fRec15[i - 1];
			}
			/* Post code */
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				fRec15_perm[j13] = fRec15_tmp[vsize + j13];
			}
			/* Vectorizable loop 59 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec4[i] = fSlow9 * (0.0f - fZec3[i]) + fSlow10 * fZec3[i];
			}
			/* Vectorizable loop 60 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec6[i] = fSlow11 * (0.0f - fZec5[i]) + fSlow12 * fZec5[i];
			}
			/* Vectorizable loop 61 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec7[i] = 0.5f * (1.0f - fRec15[i]) * (fZec4[i] + fZec6[i]);
			}
			/* Vectorizable loop 62 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec8[i] = fRec15[i] * fZec4[i] + fZec7[i];
			}
			/* Vectorizable loop 63 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec9[i] = fZec7[i] + fRec15[i] * fZec6[i];
			}
			/* Recursive loop 64 */
			/* Pre code */
			for (int j72 = 0; j72 < 4; j72 = j72 + 1) {
				fRec33_tmp[j72] = fRec33_perm[j72];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec33[i] = fConst98 * fRec33[i - 1] + fConst99 * fZec8[i];
			}
			/* Post code */
			for (int j73 = 0; j73 < 4; j73 = j73 + 1) {
				fRec33_perm[j73] = fRec33_tmp[vsize + j73];
			}
			/* Recursive loop 65 */
			/* Pre code */
			for (int j74 = 0; j74 < 4; j74 = j74 + 1) {
				fRec34_tmp[j74] = fRec34_perm[j74];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec34[i] = fConst98 * fRec34[i - 1] + fConst99 * fZec9[i];
			}
			/* Post code */
			for (int j75 = 0; j75 < 4; j75 = j75 + 1) {
				fRec34_perm[j75] = fRec34_tmp[vsize + j75];
			}
			/* Vectorizable loop 66 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec10[i] = fZec8[i] - fRec33[i];
			}
			/* Vectorizable loop 67 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec11[i] = fZec9[i] - fRec34[i];
			}
			/* Recursive loop 68 */
			/* Pre code */
			for (int j76 = 0; j76 < 4; j76 = j76 + 1) {
				fRec32_tmp[j76] = fRec32_perm[j76];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec32[i] = fConst98 * fRec32[i - 1] + fConst99 * fZec10[i] * fZec11[i];
			}
			/* Post code */
			for (int j77 = 0; j77 < 4; j77 = j77 + 1) {
				fRec32_perm[j77] = fRec32_tmp[vsize + j77];
			}
			/* Recursive loop 69 */
			/* Pre code */
			for (int j78 = 0; j78 < 4; j78 = j78 + 1) {
				fRec35_tmp[j78] = fRec35_perm[j78];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec35[i] = fConst98 * fRec35[i - 1] + fConst99 * mydsp_faustpower2_f(fZec10[i]);
			}
			/* Post code */
			for (int j79 = 0; j79 < 4; j79 = j79 + 1) {
				fRec35_perm[j79] = fRec35_tmp[vsize + j79];
			}
			/* Recursive loop 70 */
			/* Pre code */
			for (int j80 = 0; j80 < 4; j80 = j80 + 1) {
				fRec36_tmp[j80] = fRec36_perm[j80];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec36[i] = fConst98 * fRec36[i - 1] + fConst99 * mydsp_faustpower2_f(fZec11[i]);
			}
			/* Post code */
			for (int j81 = 0; j81 < 4; j81 = j81 + 1) {
				fRec36_perm[j81] = fRec36_tmp[vsize + j81];
			}
			/* Vectorizable loop 71 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec12[i] = fRec32[i] / std::max<float>(1.1920929e-07f, std::sqrt(fRec35[i]) * std::sqrt(fRec36[i]));
			}
			/* Recursive loop 72 */
			/* Pre code */
			for (int j82 = 0; j82 < 4; j82 = j82 + 1) {
				fRec31_tmp[j82] = fRec31_perm[j82];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec31[i] = fConst98 * fRec31[i - 1] + fConst99 * float(fZec12[i] > 0.999899983f);
			}
			/* Post code */
			for (int j83 = 0; j83 < 4; j83 = j83 + 1) {
				fRec31_perm[j83] = fRec31_tmp[vsize + j83];
			}
			/* Recursive loop 73 */
			/* Pre code */
			for (int j86 = 0; j86 < 4; j86 = j86 + 1) {
				fRec38_tmp[j86] = fRec38_perm[j86];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec38[i] = fConst98 * fRec38[i - 1] + fConst99 * float(fZec12[i] < -0.999899983f);
			}
			/* Post code */
			for (int j87 = 0; j87 < 4; j87 = j87 + 1) {
				fRec38_perm[j87] = fRec38_tmp[vsize + j87];
			}
			/* Recursive loop 74 */
			/* Pre code */
			for (int j90 = 0; j90 < 4; j90 = j90 + 1) {
				fRec40_tmp[j90] = fRec40_perm[j90];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec40[i] = fConst98 * fRec40[i - 1] + fConst99 * float((fZec12[i] < 9.99999975e-05f) & (fZec12[i] > -9.99999975e-05f));
			}
			/* Post code */
			for (int j91 = 0; j91 < 4; j91 = j91 + 1) {
				fRec40_perm[j91] = fRec40_tmp[vsize + j91];
			}
			/* Recursive loop 75 */
			/* Pre code */
			for (int j94 = 0; j94 < 4; j94 = j94 + 1) {
				fRec42_tmp[j94] = fRec42_perm[j94];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec42[i] = fConst98 * fRec42[i - 1] + fConst99 * float((fZec12[i] > 9.99999975e-05f) & (fZec12[i] < 0.999899983f));
			}
			/* Post code */
			for (int j95 = 0; j95 < 4; j95 = j95 + 1) {
				fRec42_perm[j95] = fRec42_tmp[vsize + j95];
			}
			/* Recursive loop 76 */
			/* Pre code */
			for (int j98 = 0; j98 < 4; j98 = j98 + 1) {
				fRec44_tmp[j98] = fRec44_perm[j98];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec44[i] = fConst98 * fRec44[i - 1] + fConst99 * float((fZec12[i] > -0.999899983f) & (fZec12[i] < -9.99999975e-05f));
			}
			/* Post code */
			for (int j99 = 0; j99 < 4; j99 = j99 + 1) {
				fRec44_perm[j99] = fRec44_tmp[vsize + j99];
			}
			/* Recursive loop 77 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec14_tmp[j10] = fRec14_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec14[i] = fSlow5 + fConst2 * fRec14[i - 1];
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec14_perm[j11] = fRec14_tmp[vsize + j11];
			}
			/* Recursive loop 78 */
			/* Pre code */
			for (int j84 = 0; j84 < 4; j84 = j84 + 1) {
				fRec30_tmp[j84] = fRec30_perm[j84];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec30[i] = fConst101 * fRec31[i] + fConst100 * fRec30[i - 1];
			}
			/* Post code */
			for (int j85 = 0; j85 < 4; j85 = j85 + 1) {
				fRec30_perm[j85] = fRec30_tmp[vsize + j85];
			}
			/* Recursive loop 79 */
			/* Pre code */
			for (int j88 = 0; j88 < 4; j88 = j88 + 1) {
				fRec37_tmp[j88] = fRec37_perm[j88];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec37[i] = fConst101 * fRec38[i] + fConst100 * fRec37[i - 1];
			}
			/* Post code */
			for (int j89 = 0; j89 < 4; j89 = j89 + 1) {
				fRec37_perm[j89] = fRec37_tmp[vsize + j89];
			}
			/* Recursive loop 80 */
			/* Pre code */
			for (int j92 = 0; j92 < 4; j92 = j92 + 1) {
				fRec39_tmp[j92] = fRec39_perm[j92];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec39[i] = fConst101 * fRec40[i] + fConst100 * fRec39[i - 1];
			}
			/* Post code */
			for (int j93 = 0; j93 < 4; j93 = j93 + 1) {
				fRec39_perm[j93] = fRec39_tmp[vsize + j93];
			}
			/* Recursive loop 81 */
			/* Pre code */
			for (int j96 = 0; j96 < 4; j96 = j96 + 1) {
				fRec41_tmp[j96] = fRec41_perm[j96];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec41[i] = fConst101 * fRec42[i] + fConst100 * fRec41[i - 1];
			}
			/* Post code */
			for (int j97 = 0; j97 < 4; j97 = j97 + 1) {
				fRec41_perm[j97] = fRec41_tmp[vsize + j97];
			}
			/* Recursive loop 82 */
			/* Pre code */
			for (int j100 = 0; j100 < 4; j100 = j100 + 1) {
				fRec43_tmp[j100] = fRec43_perm[j100];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec43[i] = fConst101 * fRec44[i] + fConst100 * fRec43[i - 1];
			}
			/* Post code */
			for (int j101 = 0; j101 < 4; j101 = j101 + 1) {
				fRec43_perm[j101] = fRec43_tmp[vsize + j101];
			}
			/* Vectorizable loop 83 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = fZec8[i] + fZec9[i];
			}
			/* Vectorizable loop 84 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = 1.0f - fRec14[i];
			}
			/* Vectorizable loop 85 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec15[i] = 0.5f * (fRec30[i] * fZec14[i] + fRec37[i] * (fZec8[i] - fZec9[i])) + fRec39[i] * fZec14[i];
			}
			/* Vectorizable loop 86 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec16[i] = fRec41[i] + fRec43[i];
			}
			/* Vectorizable loop 87 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec18[i] = fRec14[i] * fZec9[i] + fZec13[i] * (fZec15[i] + fZec9[i] * fZec16[i]);
			}
			/* Vectorizable loop 88 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec17[i] = fRec14[i] * fZec8[i] + fZec13[i] * (fZec15[i] + fZec8[i] * fZec16[i]);
			}
			/* Vectorizable loop 89 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec19[i] = std::fabs(fZec18[i]);
			}
			/* Recursive loop 90 */
			/* Pre code */
			for (int j102 = 0; j102 < 4; j102 = j102 + 1) {
				fRec48_tmp[j102] = fRec48_perm[j102];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec48[i] = std::fabs(std::fabs(fZec17[i]) + fZec19[i]) * fSlow18 + fRec48[i - 1] * fSlow17;
			}
			/* Post code */
			for (int j103 = 0; j103 < 4; j103 = j103 + 1) {
				fRec48_perm[j103] = fRec48_tmp[vsize + j103];
			}
			/* Vectorizable loop 91 */
			/* Pre code */
			for (int j104 = 0; j104 < 4; j104 = j104 + 1) {
				iYec47_tmp[j104] = iYec47_perm[j104];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iYec47[i] = fRec48[i] > fSlow20;
			}
			/* Post code */
			for (int j105 = 0; j105 < 4; j105 = j105 + 1) {
				iYec47_perm[j105] = iYec47_tmp[vsize + j105];
			}
			/* Recursive loop 92 */
			/* Pre code */
			for (int j106 = 0; j106 < 4; j106 = j106 + 1) {
				iRec49_tmp[j106] = iRec49_perm[j106];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec49[i] = std::max<int>(int(iSlow19 * (iYec47[i] < iYec47[i - 1])), int(iRec49[i - 1] + -1));
			}
			/* Post code */
			for (int j107 = 0; j107 < 4; j107 = j107 + 1) {
				iRec49_perm[j107] = iRec49_tmp[vsize + j107];
			}
			/* Vectorizable loop 93 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec20[i] = std::fabs(std::max<float>(float(iYec47[i]), float(iRec49[i] > 0)));
			}
			/* Recursive loop 94 */
			/* Pre code */
			for (int j108 = 0; j108 < 4; j108 = j108 + 1) {
				fRec47_tmp[j108] = fRec47_perm[j108];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec21[i] = ((fZec20[i] > fRec47[i - 1]) ? fSlow24 : fSlow22);
				fRec47[i] = fZec20[i] * (1.0f - fZec21[i]) + fRec47[i - 1] * fZec21[i];
			}
			/* Post code */
			for (int j109 = 0; j109 < 4; j109 = j109 + 1) {
				fRec47_perm[j109] = fRec47_tmp[vsize + j109];
			}
			/* Vectorizable loop 95 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph3 = FAUSTFLOAT(std::max<float>(-70.0f, 20.0f * std::log10(std::max<float>(1.17549435e-38f, fRec47[i]))));
				fZec22[i] = fZec17[i];
			}
			/* Recursive loop 96 */
			/* Pre code */
			for (int j110 = 0; j110 < 4; j110 = j110 + 1) {
				fRec46_tmp[j110] = fRec46_perm[j110];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec46[i] = fSlow18 * std::fabs(fZec19[i] + std::fabs(fZec22[i])) + fSlow17 * fRec46[i - 1];
			}
			/* Post code */
			for (int j111 = 0; j111 < 4; j111 = j111 + 1) {
				fRec46_perm[j111] = fRec46_tmp[vsize + j111];
			}
			/* Vectorizable loop 97 */
			/* Pre code */
			for (int j112 = 0; j112 < 4; j112 = j112 + 1) {
				iYec48_tmp[j112] = iYec48_perm[j112];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iYec48[i] = fRec46[i] > fSlow20;
			}
			/* Post code */
			for (int j113 = 0; j113 < 4; j113 = j113 + 1) {
				iYec48_perm[j113] = iYec48_tmp[vsize + j113];
			}
			/* Recursive loop 98 */
			/* Pre code */
			for (int j114 = 0; j114 < 4; j114 = j114 + 1) {
				iRec50_tmp[j114] = iRec50_perm[j114];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec50[i] = std::max<int>(int(iSlow19 * (iYec48[i] < iYec48[i - 1])), int(iRec50[i - 1] + -1));
			}
			/* Post code */
			for (int j115 = 0; j115 < 4; j115 = j115 + 1) {
				iRec50_perm[j115] = iRec50_tmp[vsize + j115];
			}
			/* Vectorizable loop 99 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec23[i] = std::fabs(std::max<float>(float(iYec48[i]), float(iRec50[i] > 0)));
			}
			/* Recursive loop 100 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec13_tmp[j8] = fRec13_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec13[i] = fSlow4 + fConst2 * fRec13[i - 1];
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec13_perm[j9] = fRec13_tmp[vsize + j9];
			}
			/* Recursive loop 101 */
			/* Pre code */
			for (int j116 = 0; j116 < 4; j116 = j116 + 1) {
				fRec45_tmp[j116] = fRec45_perm[j116];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec24[i] = ((fZec23[i] > fRec45[i - 1]) ? fSlow24 : fSlow22);
				fRec45[i] = fZec23[i] * (1.0f - fZec24[i]) + fRec45[i - 1] * fZec24[i];
			}
			/* Post code */
			for (int j117 = 0; j117 < 4; j117 = j117 + 1) {
				fRec45_perm[j117] = fRec45_tmp[vsize + j117];
			}
			/* Vectorizable loop 102 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec25[i] = fRec45[i] * (1.0f - fRec13[i]);
			}
			/* Vectorizable loop 103 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec28[i] = fRec13[i] + fZec25[i];
			}
			/* Vectorizable loop 104 */
			/* Pre code */
			for (int j118 = 0; j118 < 4; j118 = j118 + 1) {
				fYec49_tmp[j118] = fYec49_perm[j118];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec49[i] = fRec13[i] * fZec17[i] + fZec25[i] * fZec22[i];
			}
			/* Post code */
			for (int j119 = 0; j119 < 4; j119 = j119 + 1) {
				fYec49_perm[j119] = fYec49_tmp[vsize + j119];
			}
			/* Recursive loop 105 */
			/* Pre code */
			for (int j126 = 0; j126 < 4; j126 = j126 + 1) {
				fRec55_tmp[j126] = fRec55_perm[j126];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec55[i] = fSlow31 + fConst2 * fRec55[i - 1];
			}
			/* Post code */
			for (int j127 = 0; j127 < 4; j127 = j127 + 1) {
				fRec55_perm[j127] = fRec55_tmp[vsize + j127];
			}
			/* Vectorizable loop 106 */
			/* Pre code */
			for (int j134 = 0; j134 < 4; j134 = j134 + 1) {
				fYec51_tmp[j134] = fYec51_perm[j134];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec51[i] = fZec18[i] * fZec28[i];
			}
			/* Post code */
			for (int j135 = 0; j135 < 4; j135 = j135 + 1) {
				fYec51_perm[j135] = fYec51_tmp[vsize + j135];
			}
			/* Recursive loop 107 */
			/* Pre code */
			for (int j120 = 0; j120 < 4; j120 = j120 + 1) {
				fRec53_tmp[j120] = fRec53_perm[j120];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec53[i] = fSlow28 * fYec49[i - 1] - fSlow29 * (fSlow30 * fRec53[i - 1] - fSlow26 * fYec49[i]);
			}
			/* Post code */
			for (int j121 = 0; j121 < 4; j121 = j121 + 1) {
				fRec53_perm[j121] = fRec53_tmp[vsize + j121];
			}
			/* Vectorizable loop 108 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec26[i] = 0.0500000007f * fRec55[i];
			}
			/* Recursive loop 109 */
			/* Pre code */
			for (int j136 = 0; j136 < 4; j136 = j136 + 1) {
				fRec59_tmp[j136] = fRec59_perm[j136];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec59[i] = fSlow28 * fYec51[i - 1] - fSlow29 * (fSlow30 * fRec59[i - 1] - fSlow26 * fYec51[i]);
			}
			/* Post code */
			for (int j137 = 0; j137 < 4; j137 = j137 + 1) {
				fRec59_perm[j137] = fRec59_tmp[vsize + j137];
			}
			/* Recursive loop 110 */
			/* Pre code */
			for (int j122 = 0; j122 < 4; j122 = j122 + 1) {
				fRec52_tmp[j122] = fRec52_perm[j122];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec52[i] = fConst108 * fRec53[i - 1] - fConst109 * (fConst110 * fRec52[i - 1] - fConst106 * fRec53[i]);
			}
			/* Post code */
			for (int j123 = 0; j123 < 4; j123 = j123 + 1) {
				fRec52_perm[j123] = fRec52_tmp[vsize + j123];
			}
			/* Recursive loop 111 */
			/* Pre code */
			for (int j124 = 0; j124 < 4; j124 = j124 + 1) {
				fRec54_tmp[j124] = fRec54_perm[j124];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec54[i] = 0.0f - fConst109 * (fConst110 * fRec54[i - 1] - (fRec53[i] + fRec53[i - 1]));
			}
			/* Post code */
			for (int j125 = 0; j125 < 4; j125 = j125 + 1) {
				fRec54_perm[j125] = fRec54_tmp[vsize + j125];
			}
			/* Vectorizable loop 112 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec27[i] = std::pow(10.0f, 0.0f - fZec26[i]);
			}
			/* Recursive loop 113 */
			/* Pre code */
			for (int j138 = 0; j138 < 4; j138 = j138 + 1) {
				fRec58_tmp[j138] = fRec58_perm[j138];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec58[i] = fConst108 * fRec59[i - 1] - fConst109 * (fConst110 * fRec58[i - 1] - fConst106 * fRec59[i]);
			}
			/* Post code */
			for (int j139 = 0; j139 < 4; j139 = j139 + 1) {
				fRec58_perm[j139] = fRec58_tmp[vsize + j139];
			}
			/* Recursive loop 114 */
			/* Pre code */
			for (int j140 = 0; j140 < 4; j140 = j140 + 1) {
				fRec60_tmp[j140] = fRec60_perm[j140];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec60[i] = 0.0f - fConst109 * (fConst110 * fRec60[i - 1] - (fRec59[i] + fRec59[i - 1]));
			}
			/* Post code */
			for (int j141 = 0; j141 < 4; j141 = j141 + 1) {
				fRec60_perm[j141] = fRec60_tmp[vsize + j141];
			}
			/* Vectorizable loop 115 */
			/* Pre code */
			for (int j128 = 0; j128 < 4; j128 = j128 + 1) {
				fYec50_tmp[j128] = fYec50_perm[j128];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec50[i] = fRec52[i] + fRec54[i] * fZec27[i];
			}
			/* Post code */
			for (int j129 = 0; j129 < 4; j129 = j129 + 1) {
				fYec50_perm[j129] = fYec50_tmp[vsize + j129];
			}
			/* Vectorizable loop 116 */
			/* Pre code */
			for (int j142 = 0; j142 < 4; j142 = j142 + 1) {
				fYec52_tmp[j142] = fYec52_perm[j142];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec52[i] = fRec58[i] + fRec60[i] * fZec27[i];
			}
			/* Post code */
			for (int j143 = 0; j143 < 4; j143 = j143 + 1) {
				fYec52_perm[j143] = fYec52_tmp[vsize + j143];
			}
			/* Recursive loop 117 */
			/* Pre code */
			for (int j148 = 0; j148 < 4; j148 = j148 + 1) {
				fRec70_tmp[j148] = fRec70_perm[j148];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec70[i] = fSlow32 + fConst2 * fRec70[i - 1];
			}
			/* Post code */
			for (int j149 = 0; j149 < 4; j149 = j149 + 1) {
				fRec70_perm[j149] = fRec70_tmp[vsize + j149];
			}
			/* Recursive loop 118 */
			/* Pre code */
			for (int j130 = 0; j130 < 4; j130 = j130 + 1) {
				fRec51_tmp[j130] = fRec51_perm[j130];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec51[i] = 0.0f - fConst109 * (fConst110 * fRec51[i - 1] - (fYec50[i] + fYec50[i - 1]));
			}
			/* Post code */
			for (int j131 = 0; j131 < 4; j131 = j131 + 1) {
				fRec51_perm[j131] = fRec51_tmp[vsize + j131];
			}
			/* Recursive loop 119 */
			/* Pre code */
			for (int j132 = 0; j132 < 4; j132 = j132 + 1) {
				fRec56_tmp[j132] = fRec56_perm[j132];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec56[i] = fConst108 * fYec50[i - 1] - fConst109 * (fConst110 * fRec56[i - 1] - fConst106 * fYec50[i]);
			}
			/* Post code */
			for (int j133 = 0; j133 < 4; j133 = j133 + 1) {
				fRec56_perm[j133] = fRec56_tmp[vsize + j133];
			}
			/* Recursive loop 120 */
			/* Pre code */
			for (int j144 = 0; j144 < 4; j144 = j144 + 1) {
				fRec57_tmp[j144] = fRec57_perm[j144];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec57[i] = 0.0f - fConst109 * (fConst110 * fRec57[i - 1] - (fYec52[i] + fYec52[i - 1]));
			}
			/* Post code */
			for (int j145 = 0; j145 < 4; j145 = j145 + 1) {
				fRec57_perm[j145] = fRec57_tmp[vsize + j145];
			}
			/* Recursive loop 121 */
			/* Pre code */
			for (int j146 = 0; j146 < 4; j146 = j146 + 1) {
				fRec61_tmp[j146] = fRec61_perm[j146];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec61[i] = fConst108 * fYec52[i - 1] - fConst109 * (fConst110 * fRec61[i - 1] - fConst106 * fYec52[i]);
			}
			/* Post code */
			for (int j147 = 0; j147 < 4; j147 = j147 + 1) {
				fRec61_perm[j147] = fRec61_tmp[vsize + j147];
			}
			/* Vectorizable loop 122 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec29[i] = std::pow(10.0f, fZec26[i]);
			}
			/* Vectorizable loop 123 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec34[i] = 0.0250000004f * fRec70[i];
			}
			/* Vectorizable loop 124 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec30[i] = fRec51[i] + fRec56[i] * fZec29[i];
			}
			/* Vectorizable loop 125 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec31[i] = fRec57[i] + fRec61[i] * fZec29[i];
			}
			/* Vectorizable loop 126 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec35[i] = std::pow(10.0f, 0.0f - fZec34[i]);
			}
			/* Vectorizable loop 127 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec32[i] = fZec30[i] - fZec31[i];
			}
			/* Vectorizable loop 128 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec36[i] = std::sqrt(fZec35[i]);
			}
			/* Vectorizable loop 129 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec33[i] = 0.5f * fZec32[i];
			}
			/* Vectorizable loop 130 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec38[i] = fSlow35 * (fSlow35 / fZec36[i] + 1.42857146f) / fZec36[i] + 1.0f;
			}
			/* Recursive loop 131 */
			/* Pre code */
			for (int j150 = 0; j150 < 4; j150 = j150 + 1) {
				fRec66_tmp[j150] = fRec66_perm[j150];
			}
			for (int j152 = 0; j152 < 4; j152 = j152 + 1) {
				fRec67_tmp[j152] = fRec67_perm[j152];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec37[i] = fRec66[i - 1] + fSlow35 * (fZec33[i] - fRec67[i - 1]) / fZec36[i];
				fZec39[i] = fZec37[i] / fZec38[i];
				fRec66[i] = 2.0f * fZec39[i] - fRec66[i - 1];
				fZec40[i] = fRec67[i - 1] + fSlow35 * fZec37[i] / (fZec36[i] * fZec38[i]);
				fRec67[i] = 2.0f * fZec40[i] - fRec67[i - 1];
				fRec68[i] = fZec39[i];
				fRec69[i] = fZec40[i];
			}
			/* Post code */
			for (int j151 = 0; j151 < 4; j151 = j151 + 1) {
				fRec66_perm[j151] = fRec66_tmp[vsize + j151];
			}
			for (int j153 = 0; j153 < 4; j153 = j153 + 1) {
				fRec67_perm[j153] = fRec67_tmp[vsize + j153];
			}
			/* Vectorizable loop 132 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec44[i] = std::pow(10.0f, fZec34[i]);
			}
			/* Vectorizable loop 133 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec41[i] = fRec68[i] * (fZec35[i] + -1.0f);
			}
			/* Vectorizable loop 134 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec42[i] = fRec69[i] * (mydsp_faustpower2_f(fZec35[i]) + -1.0f);
			}
			/* Vectorizable loop 135 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec45[i] = std::sqrt(fZec44[i]);
			}
			/* Vectorizable loop 136 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec43[i] = fZec33[i] + 1.42857146f * fZec41[i] + fZec42[i];
			}
			/* Vectorizable loop 137 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec47[i] = fSlow36 * (fSlow36 / fZec45[i] + 1.42857146f) / fZec45[i] + 1.0f;
			}
			/* Recursive loop 138 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				fRec12_tmp[j6] = fRec12_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec12[i] = fSlow3 + fConst2 * fRec12[i - 1];
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				fRec12_perm[j7] = fRec12_tmp[vsize + j7];
			}
			/* Recursive loop 139 */
			/* Pre code */
			for (int j154 = 0; j154 < 4; j154 = j154 + 1) {
				fRec62_tmp[j154] = fRec62_perm[j154];
			}
			for (int j156 = 0; j156 < 4; j156 = j156 + 1) {
				fRec63_tmp[j156] = fRec63_perm[j156];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec46[i] = fRec62[i - 1] + fSlow36 * (fZec43[i] - fRec63[i - 1]) / fZec45[i];
				fZec48[i] = fZec46[i] / fZec47[i];
				fRec62[i] = 2.0f * fZec48[i] - fRec62[i - 1];
				fZec49[i] = fRec63[i - 1] + fSlow36 * fZec46[i] / (fZec45[i] * fZec47[i]);
				fRec63[i] = 2.0f * fZec49[i] - fRec63[i - 1];
				fRec64[i] = fZec48[i];
				fRec65[i] = fZec49[i];
			}
			/* Post code */
			for (int j155 = 0; j155 < 4; j155 = j155 + 1) {
				fRec62_perm[j155] = fRec62_tmp[vsize + j155];
			}
			for (int j157 = 0; j157 < 4; j157 = j157 + 1) {
				fRec63_perm[j157] = fRec63_tmp[vsize + j157];
			}
			/* Vectorizable loop 140 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec50[i] = 1.0f - fRec12[i];
			}
			/* Vectorizable loop 141 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec51[i] = fZec30[i] + fZec31[i];
			}
			/* Vectorizable loop 142 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec52[i] = fRec65[i] * (mydsp_faustpower2_f(fZec44[i]) + -1.0f) + fZec42[i] + 1.42857146f * (fZec41[i] + fRec64[i] * (fZec44[i] + -1.0f));
			}
			/* Vectorizable loop 143 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec53[i] = fRec12[i] * fYec49[i] + fZec50[i] * (0.5f * (fZec51[i] + fZec32[i]) + fZec52[i]);
			}
			/* Vectorizable loop 144 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec54[i] = fRec12[i] * fZec18[i] * fZec28[i] + fZec50[i] * (0.5f * (fZec51[i] - fZec32[i]) - fZec52[i]);
			}
			/* Vectorizable loop 145 */
			/* Pre code */
			for (int j158 = 0; j158 < 4; j158 = j158 + 1) {
				fYec53_tmp[j158] = fYec53_perm[j158];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec53[i] = std::fabs(std::fabs(fZec53[i]) + std::fabs(fZec54[i]));
			}
			/* Post code */
			for (int j159 = 0; j159 < 4; j159 = j159 + 1) {
				fYec53_perm[j159] = fYec53_tmp[vsize + j159];
			}
			/* Vectorizable loop 146 */
			/* Pre code */
			for (int j160 = 0; j160 < 4; j160 = j160 + 1) {
				fYec54_tmp[j160] = fYec54_perm[j160];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec54[i] = std::max<float>(fYec53[i], fYec53[i - 1]);
			}
			/* Post code */
			for (int j161 = 0; j161 < 4; j161 = j161 + 1) {
				fYec54_perm[j161] = fYec54_tmp[vsize + j161];
			}
			/* Vectorizable loop 147 */
			/* Pre code */
			for (int j162 = 0; j162 < 8; j162 = j162 + 1) {
				fYec55_tmp[j162] = fYec55_perm[j162];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec55[i] = std::max<float>(fYec54[i], fYec54[i - 2]);
			}
			/* Post code */
			for (int j163 = 0; j163 < 8; j163 = j163 + 1) {
				fYec55_perm[j163] = fYec55_tmp[vsize + j163];
			}
			/* Vectorizable loop 148 */
			/* Pre code */
			for (int j164 = 0; j164 < 16; j164 = j164 + 1) {
				fYec56_tmp[j164] = fYec56_perm[j164];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec56[i] = std::max<float>(fYec55[i], fYec55[i - 4]);
			}
			/* Post code */
			for (int j165 = 0; j165 < 16; j165 = j165 + 1) {
				fYec56_perm[j165] = fYec56_tmp[vsize + j165];
			}
			/* Vectorizable loop 149 */
			/* Pre code */
			fYec57_idx = (fYec57_idx + fYec57_idx_save) & 63;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec57[(i + fYec57_idx) & 63] = std::max<float>(fYec56[i], fYec56[i - 8]);
			}
			/* Post code */
			fYec57_idx_save = vsize;
			/* Vectorizable loop 150 */
			/* Pre code */
			fYec58_idx = (fYec58_idx + fYec58_idx_save) & 127;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec58[(i + fYec58_idx) & 127] = std::max<float>(fYec57[(i + fYec57_idx) & 63], fYec57[((i + fYec57_idx) - 16) & 63]);
			}
			/* Post code */
			fYec58_idx_save = vsize;
			/* Vectorizable loop 151 */
			/* Pre code */
			fYec59_idx = (fYec59_idx + fYec59_idx_save) & 255;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec59[(i + fYec59_idx) & 255] = std::max<float>(fYec58[(i + fYec58_idx) & 127], fYec58[((i + fYec58_idx) - 32) & 127]);
			}
			/* Post code */
			fYec59_idx_save = vsize;
			/* Vectorizable loop 152 */
			/* Pre code */
			fYec60_idx = (fYec60_idx + fYec60_idx_save) & 511;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec60[(i + fYec60_idx) & 511] = std::max<float>(fYec59[(i + fYec59_idx) & 255], fYec59[((i + fYec59_idx) - 64) & 255]);
			}
			/* Post code */
			fYec60_idx_save = vsize;
			/* Vectorizable loop 153 */
			/* Pre code */
			fYec61_idx = (fYec61_idx + fYec61_idx_save) & 1023;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec61[(i + fYec61_idx) & 1023] = std::max<float>(fYec60[(i + fYec60_idx) & 511], fYec60[((i + fYec60_idx) - 128) & 511]);
			}
			/* Post code */
			fYec61_idx_save = vsize;
			/* Vectorizable loop 154 */
			/* Pre code */
			fYec62_idx = (fYec62_idx + fYec62_idx_save) & 2047;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec62[(i + fYec62_idx) & 2047] = std::max<float>(fYec61[(i + fYec61_idx) & 1023], fYec61[((i + fYec61_idx) - 256) & 1023]);
			}
			/* Post code */
			fYec62_idx_save = vsize;
			/* Vectorizable loop 155 */
			/* Pre code */
			fYec63_idx = (fYec63_idx + fYec63_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec63[(i + fYec63_idx) & 4095] = std::max<float>(fYec62[(i + fYec62_idx) & 2047], fYec62[((i + fYec62_idx) - 512) & 2047]);
			}
			/* Post code */
			fYec63_idx_save = vsize;
			/* Vectorizable loop 156 */
			/* Pre code */
			fYec64_idx = (fYec64_idx + fYec64_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec64[(i + fYec64_idx) & 8191] = std::max<float>(fYec63[(i + fYec63_idx) & 4095], fYec63[((i + fYec63_idx) - 1024) & 4095]);
			}
			/* Post code */
			fYec64_idx_save = vsize;
			/* Vectorizable loop 157 */
			/* Pre code */
			fYec65_idx = (fYec65_idx + fYec65_idx_save) & 16383;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec65[(i + fYec65_idx) & 16383] = std::max<float>(fYec64[(i + fYec64_idx) & 8191], fYec64[((i + fYec64_idx) - 2048) & 8191]);
			}
			/* Post code */
			fYec65_idx_save = vsize;
			/* Vectorizable loop 158 */
			/* Pre code */
			fYec66_idx = (fYec66_idx + fYec66_idx_save) & 32767;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec66[(i + fYec66_idx) & 32767] = std::max<float>(fYec65[(i + fYec65_idx) & 16383], fYec65[((i + fYec65_idx) - 4096) & 16383]);
			}
			/* Post code */
			fYec66_idx_save = vsize;
			/* Vectorizable loop 159 */
			/* Pre code */
			fYec67_idx = (fYec67_idx + fYec67_idx_save) & 65535;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec67[(i + fYec67_idx) & 65535] = std::max<float>(fYec66[(i + fYec66_idx) & 32767], fYec66[((i + fYec66_idx) - 8192) & 32767]);
			}
			/* Post code */
			fYec67_idx_save = vsize;
			/* Vectorizable loop 160 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				float fElse48 = fYec53[i];
				float fElse49 = fYec54[i - iConst112];
				float fElse50 = fYec55[i - iConst118];
				float fElse51 = fYec56[i - iConst122];
				float fElse52 = fYec57[((i + fYec57_idx) - iConst126) & 63];
				float fElse53 = fYec58[((i + fYec58_idx) - iConst130) & 127];
				float fElse54 = fYec59[((i + fYec59_idx) - iConst134) & 255];
				float fElse55 = fYec60[((i + fYec60_idx) - iConst138) & 511];
				float fElse56 = fYec61[((i + fYec61_idx) - iConst142) & 1023];
				float fElse57 = fYec62[((i + fYec62_idx) - iConst146) & 2047];
				float fElse58 = fYec63[((i + fYec63_idx) - iConst150) & 4095];
				float fElse59 = fYec64[((i + fYec64_idx) - iConst154) & 8191];
				float fElse60 = fYec65[((i + fYec65_idx) - iConst158) & 16383];
				float fElse61 = fYec66[((i + fYec66_idx) - iConst162) & 32767];
				float fElse62 = fYec67[((i + fYec67_idx) - iConst164) & 65535];
				fZec55[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(((iConst112) ? fElse48 : -3.40282347e+38f), ((iConst114) ? fElse49 : -3.40282347e+38f)), ((iConst116) ? fElse50 : -3.40282347e+38f)), ((iConst120) ? fElse51 : -3.40282347e+38f)), ((iConst124) ? fElse52 : -3.40282347e+38f)), ((iConst128) ? fElse53 : -3.40282347e+38f)), ((iConst132) ? fElse54 : -3.40282347e+38f)), ((iConst136) ? fElse55 : -3.40282347e+38f)), ((iConst140) ? fElse56 : -3.40282347e+38f)), ((iConst144) ? fElse57 : -3.40282347e+38f)), ((iConst148) ? fElse58 : -3.40282347e+38f)), ((iConst152) ? fElse59 : -3.40282347e+38f)), ((iConst156) ? fElse60 : -3.40282347e+38f)), ((iConst160) ? fElse61 : -3.40282347e+38f)), ((iConst163) ? fElse62 : -3.40282347e+38f))));
			}
			/* Vectorizable loop 161 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec56[i] = (fZec55[i] > fSlow38) + (fZec55[i] > fSlow39);
			}
			/* Vectorizable loop 162 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				float fElse63 = 0.0f - 0.0416666679f * mydsp_faustpower2_f((fZec55[i] + -6.0f) - fSlow37);
				float fThen64 = ((iZec56[i] == 1) ? fElse63 : 0.0f);
				float fElse64 = fZec55[i] - fSlow37;
				fZec57[i] = std::max<float>(-120.0f, 2.0f * ((iZec56[i] == 0) ? fElse64 : fThen64));
			}
			/* Recursive loop 163 */
			/* Pre code */
			for (int j166 = 0; j166 < 4; j166 = j166 + 1) {
				fRec11_tmp[j166] = fRec11_perm[j166];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec58[i] = ((fZec57[i] > fRec11[i - 1]) ? fConst166 : fConst165);
				fRec11[i] = fZec57[i] * (1.0f - fZec58[i]) + fRec11[i - 1] * fZec58[i];
			}
			/* Post code */
			for (int j167 = 0; j167 < 4; j167 = j167 + 1) {
				fRec11_perm[j167] = fRec11_tmp[vsize + j167];
			}
			/* Vectorizable loop 164 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec59[i] = std::min<float>(1.0f, std::max<float>(0.0f, std::pow(10.0f, 0.0500000007f * fRec11[i])));
			}
			/* Vectorizable loop 165 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph4 = FAUSTFLOAT(100.0f * (1.0f - fZec59[i]));
				fZec60[i] = fSlow40 / fZec59[i];
			}
			/* Recursive loop 166 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec7_tmp[j2] = fRec7_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec7[i] = fSlow1 + fConst2 * fRec7[i - 1];
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec7_perm[j3] = fRec7_tmp[vsize + j3];
			}
			/* Vectorizable loop 167 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec61[i] = std::fabs(fZec60[i]) < 1.1920929e-07f;
			}
			/* Recursive loop 168 */
			/* Pre code */
			for (int j214 = 0; j214 < 4; j214 = j214 + 1) {
				fRec80_tmp[j214] = fRec80_perm[j214];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec80[i] = fSlow45 + fConst2 * fRec80[i - 1];
			}
			/* Post code */
			for (int j215 = 0; j215 < 4; j215 = j215 + 1) {
				fRec80_perm[j215] = fRec80_tmp[vsize + j215];
			}
			/* Recursive loop 169 */
			/* Pre code */
			for (int j222 = 0; j222 < 4; j222 = j222 + 1) {
				fRec86_tmp[j222] = fRec86_perm[j222];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec86[i] = fSlow55 + fConst2 * fRec86[i - 1];
			}
			/* Post code */
			for (int j223 = 0; j223 < 4; j223 = j223 + 1) {
				fRec86_perm[j223] = fRec86_tmp[vsize + j223];
			}
			/* Recursive loop 170 */
			/* Pre code */
			for (int j742 = 0; j742 < 4; j742 = j742 + 1) {
				fRec598_tmp[j742] = fRec598_perm[j742];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec598[i] = fSlow296 + fConst2 * fRec598[i - 1];
			}
			/* Post code */
			for (int j743 = 0; j743 < 4; j743 = j743 + 1) {
				fRec598_perm[j743] = fRec598_tmp[vsize + j743];
			}
			/* Recursive loop 171 */
			/* Pre code */
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				fRec0_tmp[j0] = fRec0_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[i] = fSlow0 + fConst2 * fRec0[i - 1];
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				fRec0_perm[j1] = fRec0_tmp[vsize + j1];
			}
			/* Recursive loop 172 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec8_tmp[j4] = fRec8_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec8[i] = fSlow2 + fConst2 * fRec8[i - 1];
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec8_perm[j5] = fRec8_tmp[vsize + j5];
			}
			/* Vectorizable loop 173 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				float fThen66 = fZec60[i];
				float fThen67 = std::exp(0.0f - fConst102 / ((iZec61[i]) ? 1.0f : fThen66));
				fZec62[i] = ((iZec61[i]) ? 0.0f : fThen67);
			}
			/* Recursive loop 174 */
			/* Pre code */
			for (int j212 = 0; j212 < 4; j212 = j212 + 1) {
				fRec79_tmp[j212] = fRec79_perm[j212];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec79[i] = fSlow44 + fConst2 * fRec79[i - 1];
			}
			/* Post code */
			for (int j213 = 0; j213 < 4; j213 = j213 + 1) {
				fRec79_perm[j213] = fRec79_tmp[vsize + j213];
			}
			/* Recursive loop 175 */
			/* Pre code */
			for (int j216 = 0; j216 < 4; j216 = j216 + 1) {
				fRec81_tmp[j216] = fRec81_perm[j216];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec81[i] = fSlow46 + fConst2 * fRec81[i - 1];
			}
			/* Post code */
			for (int j217 = 0; j217 < 4; j217 = j217 + 1) {
				fRec81_perm[j217] = fRec81_tmp[vsize + j217];
			}
			/* Vectorizable loop 176 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec70[i] = 1.0f - fRec80[i];
			}
			/* Vectorizable loop 177 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec784[i] = 1.0f - fRec598[i];
			}
			/* Recursive loop 178 */
			/* Pre code */
			for (int j744 = 0; j744 < 4; j744 = j744 + 1) {
				fRec599_tmp[j744] = fRec599_perm[j744];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec599[i] = fSlow297 + fConst2 * fRec599[i - 1];
			}
			/* Post code */
			for (int j745 = 0; j745 < 4; j745 = j745 + 1) {
				fRec599_perm[j745] = fRec599_tmp[vsize + j745];
			}
			/* Vectorizable loop 179 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec766[i] = fRec86[i] * (1.0f - fRec7[i]);
			}
			/* Recursive loop 180 */
			/* Pre code */
			for (int j740 = 0; j740 < 4; j740 = j740 + 1) {
				fRec597_tmp[j740] = fRec597_perm[j740];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec597[i] = fSlow295 + fConst2 * fRec597[i - 1];
			}
			/* Post code */
			for (int j741 = 0; j741 < 4; j741 = j741 + 1) {
				fRec597_perm[j741] = fRec597_tmp[vsize + j741];
			}
			/* Recursive loop 181 */
			/* Pre code */
			for (int j168 = 0; j168 < 4; j168 = j168 + 1) {
				fYec68_tmp[j168] = fYec68_perm[j168];
			}
			for (int j170 = 0; j170 < 4; j170 = j170 + 1) {
				fRec74_tmp[j170] = fRec74_perm[j170];
			}
			for (int j172 = 0; j172 < 4; j172 = j172 + 1) {
				fRec73_tmp[j172] = fRec73_perm[j172];
			}
			for (int j174 = 0; j174 < 4; j174 = j174 + 1) {
				fYec69_tmp[j174] = fYec69_perm[j174];
			}
			for (int j176 = 0; j176 < 4; j176 = j176 + 1) {
				fRec72_tmp[j176] = fRec72_perm[j176];
			}
			for (int j178 = 0; j178 < 4; j178 = j178 + 1) {
				fRec71_tmp[j178] = fRec71_perm[j178];
			}
			for (int j180 = 0; j180 < 4; j180 = j180 + 1) {
				fYec70_tmp[j180] = fYec70_perm[j180];
			}
			for (int j182 = 0; j182 < 4; j182 = j182 + 1) {
				fRec78_tmp[j182] = fRec78_perm[j182];
			}
			for (int j184 = 0; j184 < 4; j184 = j184 + 1) {
				fRec77_tmp[j184] = fRec77_perm[j184];
			}
			for (int j186 = 0; j186 < 4; j186 = j186 + 1) {
				fYec71_tmp[j186] = fYec71_perm[j186];
			}
			for (int j188 = 0; j188 < 4; j188 = j188 + 1) {
				fRec76_tmp[j188] = fRec76_perm[j188];
			}
			for (int j190 = 0; j190 < 4; j190 = j190 + 1) {
				fRec75_tmp[j190] = fRec75_perm[j190];
			}
			for (int j192 = 0; j192 < 4; j192 = j192 + 1) {
				fYec72_tmp[j192] = fYec72_perm[j192];
			}
			for (int j194 = 0; j194 < 4; j194 = j194 + 1) {
				fYec73_tmp[j194] = fYec73_perm[j194];
			}
			for (int j196 = 0; j196 < 8; j196 = j196 + 1) {
				fYec74_tmp[j196] = fYec74_perm[j196];
			}
			for (int j198 = 0; j198 < 16; j198 = j198 + 1) {
				fYec75_tmp[j198] = fYec75_perm[j198];
			}
			fYec76_idx = (fYec76_idx + fYec76_idx_save) & 63;
			fYec77_idx = (fYec77_idx + fYec77_idx_save) & 127;
			fYec78_idx = (fYec78_idx + fYec78_idx_save) & 255;
			fYec79_idx = (fYec79_idx + fYec79_idx_save) & 511;
			fYec80_idx = (fYec80_idx + fYec80_idx_save) & 1023;
			fYec81_idx = (fYec81_idx + fYec81_idx_save) & 2047;
			fYec82_idx = (fYec82_idx + fYec82_idx_save) & 4095;
			fYec83_idx = (fYec83_idx + fYec83_idx_save) & 8191;
			fYec84_idx = (fYec84_idx + fYec84_idx_save) & 16383;
			fYec85_idx = (fYec85_idx + fYec85_idx_save) & 32767;
			fYec86_idx = (fYec86_idx + fYec86_idx_save) & 65535;
			fYec87_idx = (fYec87_idx + fYec87_idx_save) & 131071;
			fYec88_idx = (fYec88_idx + fYec88_idx_save) & 262143;
			for (int j200 = 0; j200 < 4; j200 = j200 + 1) {
				fYec89_tmp[j200] = fYec89_perm[j200];
			}
			for (int j202 = 0; j202 < 4; j202 = j202 + 1) {
				fYec90_tmp[j202] = fYec90_perm[j202];
			}
			for (int j204 = 0; j204 < 8; j204 = j204 + 1) {
				fYec91_tmp[j204] = fYec91_perm[j204];
			}
			for (int j206 = 0; j206 < 16; j206 = j206 + 1) {
				fYec92_tmp[j206] = fYec92_perm[j206];
			}
			fYec93_idx = (fYec93_idx + fYec93_idx_save) & 63;
			fYec94_idx = (fYec94_idx + fYec94_idx_save) & 127;
			fYec95_idx = (fYec95_idx + fYec95_idx_save) & 255;
			fYec96_idx = (fYec96_idx + fYec96_idx_save) & 511;
			fYec97_idx = (fYec97_idx + fYec97_idx_save) & 1023;
			fYec98_idx = (fYec98_idx + fYec98_idx_save) & 2047;
			fYec99_idx = (fYec99_idx + fYec99_idx_save) & 4095;
			fYec100_idx = (fYec100_idx + fYec100_idx_save) & 8191;
			fYec101_idx = (fYec101_idx + fYec101_idx_save) & 16383;
			fYec102_idx = (fYec102_idx + fYec102_idx_save) & 32767;
			fYec103_idx = (fYec103_idx + fYec103_idx_save) & 65535;
			fYec104_idx = (fYec104_idx + fYec104_idx_save) & 131071;
			fYec105_idx = (fYec105_idx + fYec105_idx_save) & 262143;
			for (int j208 = 0; j208 < 4; j208 = j208 + 1) {
				fRec10_tmp[j208] = fRec10_perm[j208];
			}
			for (int j210 = 0; j210 < 4; j210 = j210 + 1) {
				fRec9_tmp[j210] = fRec9_perm[j210];
			}
			fRec83_idx = (fRec83_idx + fRec83_idx_save) & 262143;
			for (int j218 = 0; j218 < 4; j218 = j218 + 1) {
				fRec82_tmp[j218] = fRec82_perm[j218];
			}
			fRec85_idx = (fRec85_idx + fRec85_idx_save) & 262143;
			for (int j220 = 0; j220 < 4; j220 = j220 + 1) {
				fRec84_tmp[j220] = fRec84_perm[j220];
			}
			for (int j224 = 0; j224 < 4; j224 = j224 + 1) {
				fRec90_tmp[j224] = fRec90_perm[j224];
			}
			for (int j226 = 0; j226 < 4; j226 = j226 + 1) {
				fRec89_tmp[j226] = fRec89_perm[j226];
			}
			for (int j228 = 0; j228 < 4; j228 = j228 + 1) {
				fRec88_tmp[j228] = fRec88_perm[j228];
			}
			for (int j230 = 0; j230 < 4; j230 = j230 + 1) {
				fRec87_tmp[j230] = fRec87_perm[j230];
			}
			for (int j232 = 0; j232 < 4; j232 = j232 + 1) {
				fRec94_tmp[j232] = fRec94_perm[j232];
			}
			for (int j234 = 0; j234 < 4; j234 = j234 + 1) {
				fRec93_tmp[j234] = fRec93_perm[j234];
			}
			for (int j236 = 0; j236 < 4; j236 = j236 + 1) {
				fRec92_tmp[j236] = fRec92_perm[j236];
			}
			for (int j238 = 0; j238 < 4; j238 = j238 + 1) {
				fRec91_tmp[j238] = fRec91_perm[j238];
			}
			for (int j240 = 0; j240 < 4; j240 = j240 + 1) {
				fRec325_tmp[j240] = fRec325_perm[j240];
			}
			for (int j242 = 0; j242 < 4; j242 = j242 + 1) {
				fRec324_tmp[j242] = fRec324_perm[j242];
			}
			for (int j244 = 0; j244 < 4; j244 = j244 + 1) {
				fRec323_tmp[j244] = fRec323_perm[j244];
			}
			for (int j246 = 0; j246 < 4; j246 = j246 + 1) {
				fRec322_tmp[j246] = fRec322_perm[j246];
			}
			for (int j248 = 0; j248 < 4; j248 = j248 + 1) {
				fRec321_tmp[j248] = fRec321_perm[j248];
			}
			for (int j250 = 0; j250 < 4; j250 = j250 + 1) {
				fRec320_tmp[j250] = fRec320_perm[j250];
			}
			for (int j252 = 0; j252 < 4; j252 = j252 + 1) {
				fRec319_tmp[j252] = fRec319_perm[j252];
			}
			for (int j254 = 0; j254 < 4; j254 = j254 + 1) {
				fRec318_tmp[j254] = fRec318_perm[j254];
			}
			for (int j256 = 0; j256 < 4; j256 = j256 + 1) {
				fRec317_tmp[j256] = fRec317_perm[j256];
			}
			for (int j258 = 0; j258 < 4; j258 = j258 + 1) {
				fRec316_tmp[j258] = fRec316_perm[j258];
			}
			for (int j260 = 0; j260 < 4; j260 = j260 + 1) {
				fRec315_tmp[j260] = fRec315_perm[j260];
			}
			for (int j262 = 0; j262 < 4; j262 = j262 + 1) {
				fRec314_tmp[j262] = fRec314_perm[j262];
			}
			for (int j264 = 0; j264 < 4; j264 = j264 + 1) {
				fRec313_tmp[j264] = fRec313_perm[j264];
			}
			for (int j266 = 0; j266 < 4; j266 = j266 + 1) {
				fRec312_tmp[j266] = fRec312_perm[j266];
			}
			for (int j268 = 0; j268 < 4; j268 = j268 + 1) {
				fRec311_tmp[j268] = fRec311_perm[j268];
			}
			for (int j270 = 0; j270 < 4; j270 = j270 + 1) {
				fRec310_tmp[j270] = fRec310_perm[j270];
			}
			for (int j272 = 0; j272 < 4; j272 = j272 + 1) {
				fRec309_tmp[j272] = fRec309_perm[j272];
			}
			for (int j274 = 0; j274 < 4; j274 = j274 + 1) {
				fRec308_tmp[j274] = fRec308_perm[j274];
			}
			for (int j276 = 0; j276 < 4; j276 = j276 + 1) {
				fRec307_tmp[j276] = fRec307_perm[j276];
			}
			for (int j278 = 0; j278 < 4; j278 = j278 + 1) {
				fRec306_tmp[j278] = fRec306_perm[j278];
			}
			for (int j280 = 0; j280 < 4; j280 = j280 + 1) {
				fRec305_tmp[j280] = fRec305_perm[j280];
			}
			for (int j282 = 0; j282 < 4; j282 = j282 + 1) {
				fRec346_tmp[j282] = fRec346_perm[j282];
			}
			for (int j284 = 0; j284 < 4; j284 = j284 + 1) {
				fRec345_tmp[j284] = fRec345_perm[j284];
			}
			for (int j286 = 0; j286 < 4; j286 = j286 + 1) {
				fRec344_tmp[j286] = fRec344_perm[j286];
			}
			for (int j288 = 0; j288 < 4; j288 = j288 + 1) {
				fRec343_tmp[j288] = fRec343_perm[j288];
			}
			for (int j290 = 0; j290 < 4; j290 = j290 + 1) {
				fRec342_tmp[j290] = fRec342_perm[j290];
			}
			for (int j292 = 0; j292 < 4; j292 = j292 + 1) {
				fRec341_tmp[j292] = fRec341_perm[j292];
			}
			for (int j294 = 0; j294 < 4; j294 = j294 + 1) {
				fRec340_tmp[j294] = fRec340_perm[j294];
			}
			for (int j296 = 0; j296 < 4; j296 = j296 + 1) {
				fRec339_tmp[j296] = fRec339_perm[j296];
			}
			for (int j298 = 0; j298 < 4; j298 = j298 + 1) {
				fRec338_tmp[j298] = fRec338_perm[j298];
			}
			for (int j300 = 0; j300 < 4; j300 = j300 + 1) {
				fRec337_tmp[j300] = fRec337_perm[j300];
			}
			for (int j302 = 0; j302 < 4; j302 = j302 + 1) {
				fRec336_tmp[j302] = fRec336_perm[j302];
			}
			for (int j304 = 0; j304 < 4; j304 = j304 + 1) {
				fRec335_tmp[j304] = fRec335_perm[j304];
			}
			for (int j306 = 0; j306 < 4; j306 = j306 + 1) {
				fRec334_tmp[j306] = fRec334_perm[j306];
			}
			for (int j308 = 0; j308 < 4; j308 = j308 + 1) {
				fRec333_tmp[j308] = fRec333_perm[j308];
			}
			for (int j310 = 0; j310 < 4; j310 = j310 + 1) {
				fRec332_tmp[j310] = fRec332_perm[j310];
			}
			for (int j312 = 0; j312 < 4; j312 = j312 + 1) {
				fRec331_tmp[j312] = fRec331_perm[j312];
			}
			for (int j314 = 0; j314 < 4; j314 = j314 + 1) {
				fRec330_tmp[j314] = fRec330_perm[j314];
			}
			for (int j316 = 0; j316 < 4; j316 = j316 + 1) {
				fRec329_tmp[j316] = fRec329_perm[j316];
			}
			for (int j318 = 0; j318 < 4; j318 = j318 + 1) {
				fRec328_tmp[j318] = fRec328_perm[j318];
			}
			for (int j320 = 0; j320 < 4; j320 = j320 + 1) {
				fRec327_tmp[j320] = fRec327_perm[j320];
			}
			for (int j322 = 0; j322 < 4; j322 = j322 + 1) {
				fRec326_tmp[j322] = fRec326_perm[j322];
			}
			for (int j324 = 0; j324 < 4; j324 = j324 + 1) {
				fRec300_tmp[j324] = fRec300_perm[j324];
			}
			for (int j326 = 0; j326 < 4; j326 = j326 + 1) {
				fRec301_tmp[j326] = fRec301_perm[j326];
			}
			for (int j328 = 0; j328 < 4; j328 = j328 + 1) {
				fRec295_tmp[j328] = fRec295_perm[j328];
			}
			for (int j330 = 0; j330 < 4; j330 = j330 + 1) {
				fRec296_tmp[j330] = fRec296_perm[j330];
			}
			for (int j332 = 0; j332 < 4; j332 = j332 + 1) {
				fRec290_tmp[j332] = fRec290_perm[j332];
			}
			for (int j334 = 0; j334 < 4; j334 = j334 + 1) {
				fRec291_tmp[j334] = fRec291_perm[j334];
			}
			for (int j336 = 0; j336 < 4; j336 = j336 + 1) {
				fRec349_tmp[j336] = fRec349_perm[j336];
			}
			for (int j338 = 0; j338 < 4; j338 = j338 + 1) {
				fRec348_tmp[j338] = fRec348_perm[j338];
			}
			for (int j340 = 0; j340 < 4; j340 = j340 + 1) {
				fRec347_tmp[j340] = fRec347_perm[j340];
			}
			for (int j342 = 0; j342 < 4; j342 = j342 + 1) {
				fRec352_tmp[j342] = fRec352_perm[j342];
			}
			for (int j344 = 0; j344 < 4; j344 = j344 + 1) {
				fRec351_tmp[j344] = fRec351_perm[j344];
			}
			for (int j346 = 0; j346 < 4; j346 = j346 + 1) {
				fRec350_tmp[j346] = fRec350_perm[j346];
			}
			for (int j348 = 0; j348 < 4; j348 = j348 + 1) {
				fRec285_tmp[j348] = fRec285_perm[j348];
			}
			for (int j350 = 0; j350 < 4; j350 = j350 + 1) {
				fRec286_tmp[j350] = fRec286_perm[j350];
			}
			for (int j352 = 0; j352 < 4; j352 = j352 + 1) {
				fRec280_tmp[j352] = fRec280_perm[j352];
			}
			for (int j354 = 0; j354 < 4; j354 = j354 + 1) {
				fRec281_tmp[j354] = fRec281_perm[j354];
			}
			for (int j356 = 0; j356 < 4; j356 = j356 + 1) {
				fRec275_tmp[j356] = fRec275_perm[j356];
			}
			for (int j358 = 0; j358 < 4; j358 = j358 + 1) {
				fRec276_tmp[j358] = fRec276_perm[j358];
			}
			for (int j360 = 0; j360 < 4; j360 = j360 + 1) {
				fRec270_tmp[j360] = fRec270_perm[j360];
			}
			for (int j362 = 0; j362 < 4; j362 = j362 + 1) {
				fRec271_tmp[j362] = fRec271_perm[j362];
			}
			for (int j364 = 0; j364 < 4; j364 = j364 + 1) {
				fRec265_tmp[j364] = fRec265_perm[j364];
			}
			for (int j366 = 0; j366 < 4; j366 = j366 + 1) {
				fRec266_tmp[j366] = fRec266_perm[j366];
			}
			for (int j368 = 0; j368 < 4; j368 = j368 + 1) {
				fRec260_tmp[j368] = fRec260_perm[j368];
			}
			for (int j370 = 0; j370 < 4; j370 = j370 + 1) {
				fRec261_tmp[j370] = fRec261_perm[j370];
			}
			for (int j372 = 0; j372 < 4; j372 = j372 + 1) {
				fRec355_tmp[j372] = fRec355_perm[j372];
			}
			for (int j374 = 0; j374 < 4; j374 = j374 + 1) {
				fRec354_tmp[j374] = fRec354_perm[j374];
			}
			for (int j376 = 0; j376 < 4; j376 = j376 + 1) {
				fRec353_tmp[j376] = fRec353_perm[j376];
			}
			for (int j378 = 0; j378 < 4; j378 = j378 + 1) {
				fRec358_tmp[j378] = fRec358_perm[j378];
			}
			for (int j380 = 0; j380 < 4; j380 = j380 + 1) {
				fRec357_tmp[j380] = fRec357_perm[j380];
			}
			for (int j382 = 0; j382 < 4; j382 = j382 + 1) {
				fRec356_tmp[j382] = fRec356_perm[j382];
			}
			for (int j384 = 0; j384 < 4; j384 = j384 + 1) {
				fRec255_tmp[j384] = fRec255_perm[j384];
			}
			for (int j386 = 0; j386 < 4; j386 = j386 + 1) {
				fRec256_tmp[j386] = fRec256_perm[j386];
			}
			for (int j388 = 0; j388 < 4; j388 = j388 + 1) {
				fRec250_tmp[j388] = fRec250_perm[j388];
			}
			for (int j390 = 0; j390 < 4; j390 = j390 + 1) {
				fRec251_tmp[j390] = fRec251_perm[j390];
			}
			for (int j392 = 0; j392 < 4; j392 = j392 + 1) {
				fRec245_tmp[j392] = fRec245_perm[j392];
			}
			for (int j394 = 0; j394 < 4; j394 = j394 + 1) {
				fRec246_tmp[j394] = fRec246_perm[j394];
			}
			for (int j396 = 0; j396 < 4; j396 = j396 + 1) {
				fRec240_tmp[j396] = fRec240_perm[j396];
			}
			for (int j398 = 0; j398 < 4; j398 = j398 + 1) {
				fRec241_tmp[j398] = fRec241_perm[j398];
			}
			for (int j400 = 0; j400 < 4; j400 = j400 + 1) {
				fRec235_tmp[j400] = fRec235_perm[j400];
			}
			for (int j402 = 0; j402 < 4; j402 = j402 + 1) {
				fRec236_tmp[j402] = fRec236_perm[j402];
			}
			for (int j404 = 0; j404 < 4; j404 = j404 + 1) {
				fRec230_tmp[j404] = fRec230_perm[j404];
			}
			for (int j406 = 0; j406 < 4; j406 = j406 + 1) {
				fRec231_tmp[j406] = fRec231_perm[j406];
			}
			for (int j408 = 0; j408 < 4; j408 = j408 + 1) {
				fRec361_tmp[j408] = fRec361_perm[j408];
			}
			for (int j410 = 0; j410 < 4; j410 = j410 + 1) {
				fRec360_tmp[j410] = fRec360_perm[j410];
			}
			for (int j412 = 0; j412 < 4; j412 = j412 + 1) {
				fRec359_tmp[j412] = fRec359_perm[j412];
			}
			for (int j414 = 0; j414 < 4; j414 = j414 + 1) {
				fRec364_tmp[j414] = fRec364_perm[j414];
			}
			for (int j416 = 0; j416 < 4; j416 = j416 + 1) {
				fRec363_tmp[j416] = fRec363_perm[j416];
			}
			for (int j418 = 0; j418 < 4; j418 = j418 + 1) {
				fRec362_tmp[j418] = fRec362_perm[j418];
			}
			for (int j420 = 0; j420 < 4; j420 = j420 + 1) {
				fRec225_tmp[j420] = fRec225_perm[j420];
			}
			for (int j422 = 0; j422 < 4; j422 = j422 + 1) {
				fRec226_tmp[j422] = fRec226_perm[j422];
			}
			for (int j424 = 0; j424 < 4; j424 = j424 + 1) {
				fRec220_tmp[j424] = fRec220_perm[j424];
			}
			for (int j426 = 0; j426 < 4; j426 = j426 + 1) {
				fRec221_tmp[j426] = fRec221_perm[j426];
			}
			for (int j428 = 0; j428 < 4; j428 = j428 + 1) {
				fRec215_tmp[j428] = fRec215_perm[j428];
			}
			for (int j430 = 0; j430 < 4; j430 = j430 + 1) {
				fRec216_tmp[j430] = fRec216_perm[j430];
			}
			for (int j432 = 0; j432 < 4; j432 = j432 + 1) {
				fRec210_tmp[j432] = fRec210_perm[j432];
			}
			for (int j434 = 0; j434 < 4; j434 = j434 + 1) {
				fRec211_tmp[j434] = fRec211_perm[j434];
			}
			for (int j436 = 0; j436 < 4; j436 = j436 + 1) {
				fRec205_tmp[j436] = fRec205_perm[j436];
			}
			for (int j438 = 0; j438 < 4; j438 = j438 + 1) {
				fRec206_tmp[j438] = fRec206_perm[j438];
			}
			for (int j440 = 0; j440 < 4; j440 = j440 + 1) {
				fRec200_tmp[j440] = fRec200_perm[j440];
			}
			for (int j442 = 0; j442 < 4; j442 = j442 + 1) {
				fRec201_tmp[j442] = fRec201_perm[j442];
			}
			for (int j444 = 0; j444 < 4; j444 = j444 + 1) {
				fRec367_tmp[j444] = fRec367_perm[j444];
			}
			for (int j446 = 0; j446 < 4; j446 = j446 + 1) {
				fRec366_tmp[j446] = fRec366_perm[j446];
			}
			for (int j448 = 0; j448 < 4; j448 = j448 + 1) {
				fRec365_tmp[j448] = fRec365_perm[j448];
			}
			for (int j450 = 0; j450 < 4; j450 = j450 + 1) {
				fRec370_tmp[j450] = fRec370_perm[j450];
			}
			for (int j452 = 0; j452 < 4; j452 = j452 + 1) {
				fRec369_tmp[j452] = fRec369_perm[j452];
			}
			for (int j454 = 0; j454 < 4; j454 = j454 + 1) {
				fRec368_tmp[j454] = fRec368_perm[j454];
			}
			for (int j456 = 0; j456 < 4; j456 = j456 + 1) {
				fRec195_tmp[j456] = fRec195_perm[j456];
			}
			for (int j458 = 0; j458 < 4; j458 = j458 + 1) {
				fRec196_tmp[j458] = fRec196_perm[j458];
			}
			for (int j460 = 0; j460 < 4; j460 = j460 + 1) {
				fRec190_tmp[j460] = fRec190_perm[j460];
			}
			for (int j462 = 0; j462 < 4; j462 = j462 + 1) {
				fRec191_tmp[j462] = fRec191_perm[j462];
			}
			for (int j464 = 0; j464 < 4; j464 = j464 + 1) {
				fRec185_tmp[j464] = fRec185_perm[j464];
			}
			for (int j466 = 0; j466 < 4; j466 = j466 + 1) {
				fRec186_tmp[j466] = fRec186_perm[j466];
			}
			for (int j468 = 0; j468 < 4; j468 = j468 + 1) {
				fRec180_tmp[j468] = fRec180_perm[j468];
			}
			for (int j470 = 0; j470 < 4; j470 = j470 + 1) {
				fRec181_tmp[j470] = fRec181_perm[j470];
			}
			for (int j472 = 0; j472 < 4; j472 = j472 + 1) {
				fRec175_tmp[j472] = fRec175_perm[j472];
			}
			for (int j474 = 0; j474 < 4; j474 = j474 + 1) {
				fRec176_tmp[j474] = fRec176_perm[j474];
			}
			for (int j476 = 0; j476 < 4; j476 = j476 + 1) {
				fRec170_tmp[j476] = fRec170_perm[j476];
			}
			for (int j478 = 0; j478 < 4; j478 = j478 + 1) {
				fRec171_tmp[j478] = fRec171_perm[j478];
			}
			for (int j480 = 0; j480 < 4; j480 = j480 + 1) {
				fRec373_tmp[j480] = fRec373_perm[j480];
			}
			for (int j482 = 0; j482 < 4; j482 = j482 + 1) {
				fRec372_tmp[j482] = fRec372_perm[j482];
			}
			for (int j484 = 0; j484 < 4; j484 = j484 + 1) {
				fRec371_tmp[j484] = fRec371_perm[j484];
			}
			for (int j486 = 0; j486 < 4; j486 = j486 + 1) {
				fRec376_tmp[j486] = fRec376_perm[j486];
			}
			for (int j488 = 0; j488 < 4; j488 = j488 + 1) {
				fRec375_tmp[j488] = fRec375_perm[j488];
			}
			for (int j490 = 0; j490 < 4; j490 = j490 + 1) {
				fRec374_tmp[j490] = fRec374_perm[j490];
			}
			for (int j492 = 0; j492 < 4; j492 = j492 + 1) {
				fRec165_tmp[j492] = fRec165_perm[j492];
			}
			for (int j494 = 0; j494 < 4; j494 = j494 + 1) {
				fRec166_tmp[j494] = fRec166_perm[j494];
			}
			for (int j496 = 0; j496 < 4; j496 = j496 + 1) {
				fRec160_tmp[j496] = fRec160_perm[j496];
			}
			for (int j498 = 0; j498 < 4; j498 = j498 + 1) {
				fRec161_tmp[j498] = fRec161_perm[j498];
			}
			for (int j500 = 0; j500 < 4; j500 = j500 + 1) {
				fRec155_tmp[j500] = fRec155_perm[j500];
			}
			for (int j502 = 0; j502 < 4; j502 = j502 + 1) {
				fRec156_tmp[j502] = fRec156_perm[j502];
			}
			for (int j504 = 0; j504 < 4; j504 = j504 + 1) {
				fRec150_tmp[j504] = fRec150_perm[j504];
			}
			for (int j506 = 0; j506 < 4; j506 = j506 + 1) {
				fRec151_tmp[j506] = fRec151_perm[j506];
			}
			for (int j508 = 0; j508 < 4; j508 = j508 + 1) {
				fRec145_tmp[j508] = fRec145_perm[j508];
			}
			for (int j510 = 0; j510 < 4; j510 = j510 + 1) {
				fRec146_tmp[j510] = fRec146_perm[j510];
			}
			for (int j512 = 0; j512 < 4; j512 = j512 + 1) {
				fRec140_tmp[j512] = fRec140_perm[j512];
			}
			for (int j514 = 0; j514 < 4; j514 = j514 + 1) {
				fRec141_tmp[j514] = fRec141_perm[j514];
			}
			for (int j516 = 0; j516 < 4; j516 = j516 + 1) {
				fRec379_tmp[j516] = fRec379_perm[j516];
			}
			for (int j518 = 0; j518 < 4; j518 = j518 + 1) {
				fRec378_tmp[j518] = fRec378_perm[j518];
			}
			for (int j520 = 0; j520 < 4; j520 = j520 + 1) {
				fRec377_tmp[j520] = fRec377_perm[j520];
			}
			for (int j522 = 0; j522 < 4; j522 = j522 + 1) {
				fRec382_tmp[j522] = fRec382_perm[j522];
			}
			for (int j524 = 0; j524 < 4; j524 = j524 + 1) {
				fRec381_tmp[j524] = fRec381_perm[j524];
			}
			for (int j526 = 0; j526 < 4; j526 = j526 + 1) {
				fRec380_tmp[j526] = fRec380_perm[j526];
			}
			for (int j528 = 0; j528 < 4; j528 = j528 + 1) {
				fRec135_tmp[j528] = fRec135_perm[j528];
			}
			for (int j530 = 0; j530 < 4; j530 = j530 + 1) {
				fRec136_tmp[j530] = fRec136_perm[j530];
			}
			for (int j532 = 0; j532 < 4; j532 = j532 + 1) {
				fRec130_tmp[j532] = fRec130_perm[j532];
			}
			for (int j534 = 0; j534 < 4; j534 = j534 + 1) {
				fRec131_tmp[j534] = fRec131_perm[j534];
			}
			for (int j536 = 0; j536 < 4; j536 = j536 + 1) {
				fRec125_tmp[j536] = fRec125_perm[j536];
			}
			for (int j538 = 0; j538 < 4; j538 = j538 + 1) {
				fRec126_tmp[j538] = fRec126_perm[j538];
			}
			for (int j540 = 0; j540 < 4; j540 = j540 + 1) {
				fRec120_tmp[j540] = fRec120_perm[j540];
			}
			for (int j542 = 0; j542 < 4; j542 = j542 + 1) {
				fRec121_tmp[j542] = fRec121_perm[j542];
			}
			for (int j544 = 0; j544 < 4; j544 = j544 + 1) {
				fRec115_tmp[j544] = fRec115_perm[j544];
			}
			for (int j546 = 0; j546 < 4; j546 = j546 + 1) {
				fRec116_tmp[j546] = fRec116_perm[j546];
			}
			for (int j548 = 0; j548 < 4; j548 = j548 + 1) {
				fRec110_tmp[j548] = fRec110_perm[j548];
			}
			for (int j550 = 0; j550 < 4; j550 = j550 + 1) {
				fRec111_tmp[j550] = fRec111_perm[j550];
			}
			for (int j552 = 0; j552 < 4; j552 = j552 + 1) {
				fRec105_tmp[j552] = fRec105_perm[j552];
			}
			for (int j554 = 0; j554 < 4; j554 = j554 + 1) {
				fRec106_tmp[j554] = fRec106_perm[j554];
			}
			for (int j556 = 0; j556 < 4; j556 = j556 + 1) {
				fRec100_tmp[j556] = fRec100_perm[j556];
			}
			for (int j558 = 0; j558 < 4; j558 = j558 + 1) {
				fRec101_tmp[j558] = fRec101_perm[j558];
			}
			for (int j560 = 0; j560 < 4; j560 = j560 + 1) {
				fRec95_tmp[j560] = fRec95_perm[j560];
			}
			for (int j562 = 0; j562 < 4; j562 = j562 + 1) {
				fRec96_tmp[j562] = fRec96_perm[j562];
			}
			for (int j564 = 0; j564 < 4; j564 = j564 + 1) {
				fRec588_tmp[j564] = fRec588_perm[j564];
			}
			for (int j566 = 0; j566 < 4; j566 = j566 + 1) {
				fRec589_tmp[j566] = fRec589_perm[j566];
			}
			for (int j568 = 0; j568 < 4; j568 = j568 + 1) {
				fRec583_tmp[j568] = fRec583_perm[j568];
			}
			for (int j570 = 0; j570 < 4; j570 = j570 + 1) {
				fRec584_tmp[j570] = fRec584_perm[j570];
			}
			for (int j572 = 0; j572 < 4; j572 = j572 + 1) {
				fRec578_tmp[j572] = fRec578_perm[j572];
			}
			for (int j574 = 0; j574 < 4; j574 = j574 + 1) {
				fRec579_tmp[j574] = fRec579_perm[j574];
			}
			for (int j576 = 0; j576 < 4; j576 = j576 + 1) {
				fRec573_tmp[j576] = fRec573_perm[j576];
			}
			for (int j578 = 0; j578 < 4; j578 = j578 + 1) {
				fRec574_tmp[j578] = fRec574_perm[j578];
			}
			for (int j580 = 0; j580 < 4; j580 = j580 + 1) {
				fRec568_tmp[j580] = fRec568_perm[j580];
			}
			for (int j582 = 0; j582 < 4; j582 = j582 + 1) {
				fRec569_tmp[j582] = fRec569_perm[j582];
			}
			for (int j584 = 0; j584 < 4; j584 = j584 + 1) {
				fRec563_tmp[j584] = fRec563_perm[j584];
			}
			for (int j586 = 0; j586 < 4; j586 = j586 + 1) {
				fRec564_tmp[j586] = fRec564_perm[j586];
			}
			for (int j588 = 0; j588 < 4; j588 = j588 + 1) {
				fRec558_tmp[j588] = fRec558_perm[j588];
			}
			for (int j590 = 0; j590 < 4; j590 = j590 + 1) {
				fRec559_tmp[j590] = fRec559_perm[j590];
			}
			for (int j592 = 0; j592 < 4; j592 = j592 + 1) {
				fRec553_tmp[j592] = fRec553_perm[j592];
			}
			for (int j594 = 0; j594 < 4; j594 = j594 + 1) {
				fRec554_tmp[j594] = fRec554_perm[j594];
			}
			for (int j596 = 0; j596 < 4; j596 = j596 + 1) {
				fRec548_tmp[j596] = fRec548_perm[j596];
			}
			for (int j598 = 0; j598 < 4; j598 = j598 + 1) {
				fRec549_tmp[j598] = fRec549_perm[j598];
			}
			for (int j600 = 0; j600 < 4; j600 = j600 + 1) {
				fRec543_tmp[j600] = fRec543_perm[j600];
			}
			for (int j602 = 0; j602 < 4; j602 = j602 + 1) {
				fRec544_tmp[j602] = fRec544_perm[j602];
			}
			for (int j604 = 0; j604 < 4; j604 = j604 + 1) {
				fRec538_tmp[j604] = fRec538_perm[j604];
			}
			for (int j606 = 0; j606 < 4; j606 = j606 + 1) {
				fRec539_tmp[j606] = fRec539_perm[j606];
			}
			for (int j608 = 0; j608 < 4; j608 = j608 + 1) {
				fRec533_tmp[j608] = fRec533_perm[j608];
			}
			for (int j610 = 0; j610 < 4; j610 = j610 + 1) {
				fRec534_tmp[j610] = fRec534_perm[j610];
			}
			for (int j612 = 0; j612 < 4; j612 = j612 + 1) {
				fRec528_tmp[j612] = fRec528_perm[j612];
			}
			for (int j614 = 0; j614 < 4; j614 = j614 + 1) {
				fRec529_tmp[j614] = fRec529_perm[j614];
			}
			for (int j616 = 0; j616 < 4; j616 = j616 + 1) {
				fRec523_tmp[j616] = fRec523_perm[j616];
			}
			for (int j618 = 0; j618 < 4; j618 = j618 + 1) {
				fRec524_tmp[j618] = fRec524_perm[j618];
			}
			for (int j620 = 0; j620 < 4; j620 = j620 + 1) {
				fRec518_tmp[j620] = fRec518_perm[j620];
			}
			for (int j622 = 0; j622 < 4; j622 = j622 + 1) {
				fRec519_tmp[j622] = fRec519_perm[j622];
			}
			for (int j624 = 0; j624 < 4; j624 = j624 + 1) {
				fRec513_tmp[j624] = fRec513_perm[j624];
			}
			for (int j626 = 0; j626 < 4; j626 = j626 + 1) {
				fRec514_tmp[j626] = fRec514_perm[j626];
			}
			for (int j628 = 0; j628 < 4; j628 = j628 + 1) {
				fRec508_tmp[j628] = fRec508_perm[j628];
			}
			for (int j630 = 0; j630 < 4; j630 = j630 + 1) {
				fRec509_tmp[j630] = fRec509_perm[j630];
			}
			for (int j632 = 0; j632 < 4; j632 = j632 + 1) {
				fRec503_tmp[j632] = fRec503_perm[j632];
			}
			for (int j634 = 0; j634 < 4; j634 = j634 + 1) {
				fRec504_tmp[j634] = fRec504_perm[j634];
			}
			for (int j636 = 0; j636 < 4; j636 = j636 + 1) {
				fRec498_tmp[j636] = fRec498_perm[j636];
			}
			for (int j638 = 0; j638 < 4; j638 = j638 + 1) {
				fRec499_tmp[j638] = fRec499_perm[j638];
			}
			for (int j640 = 0; j640 < 4; j640 = j640 + 1) {
				fRec493_tmp[j640] = fRec493_perm[j640];
			}
			for (int j642 = 0; j642 < 4; j642 = j642 + 1) {
				fRec494_tmp[j642] = fRec494_perm[j642];
			}
			for (int j644 = 0; j644 < 4; j644 = j644 + 1) {
				fRec488_tmp[j644] = fRec488_perm[j644];
			}
			for (int j646 = 0; j646 < 4; j646 = j646 + 1) {
				fRec489_tmp[j646] = fRec489_perm[j646];
			}
			for (int j648 = 0; j648 < 4; j648 = j648 + 1) {
				fRec483_tmp[j648] = fRec483_perm[j648];
			}
			for (int j650 = 0; j650 < 4; j650 = j650 + 1) {
				fRec484_tmp[j650] = fRec484_perm[j650];
			}
			for (int j652 = 0; j652 < 4; j652 = j652 + 1) {
				fRec478_tmp[j652] = fRec478_perm[j652];
			}
			for (int j654 = 0; j654 < 4; j654 = j654 + 1) {
				fRec479_tmp[j654] = fRec479_perm[j654];
			}
			for (int j656 = 0; j656 < 4; j656 = j656 + 1) {
				fRec473_tmp[j656] = fRec473_perm[j656];
			}
			for (int j658 = 0; j658 < 4; j658 = j658 + 1) {
				fRec474_tmp[j658] = fRec474_perm[j658];
			}
			for (int j660 = 0; j660 < 4; j660 = j660 + 1) {
				fRec468_tmp[j660] = fRec468_perm[j660];
			}
			for (int j662 = 0; j662 < 4; j662 = j662 + 1) {
				fRec469_tmp[j662] = fRec469_perm[j662];
			}
			for (int j664 = 0; j664 < 4; j664 = j664 + 1) {
				fRec463_tmp[j664] = fRec463_perm[j664];
			}
			for (int j666 = 0; j666 < 4; j666 = j666 + 1) {
				fRec464_tmp[j666] = fRec464_perm[j666];
			}
			for (int j668 = 0; j668 < 4; j668 = j668 + 1) {
				fRec458_tmp[j668] = fRec458_perm[j668];
			}
			for (int j670 = 0; j670 < 4; j670 = j670 + 1) {
				fRec459_tmp[j670] = fRec459_perm[j670];
			}
			for (int j672 = 0; j672 < 4; j672 = j672 + 1) {
				fRec453_tmp[j672] = fRec453_perm[j672];
			}
			for (int j674 = 0; j674 < 4; j674 = j674 + 1) {
				fRec454_tmp[j674] = fRec454_perm[j674];
			}
			for (int j676 = 0; j676 < 4; j676 = j676 + 1) {
				fRec448_tmp[j676] = fRec448_perm[j676];
			}
			for (int j678 = 0; j678 < 4; j678 = j678 + 1) {
				fRec449_tmp[j678] = fRec449_perm[j678];
			}
			for (int j680 = 0; j680 < 4; j680 = j680 + 1) {
				fRec443_tmp[j680] = fRec443_perm[j680];
			}
			for (int j682 = 0; j682 < 4; j682 = j682 + 1) {
				fRec444_tmp[j682] = fRec444_perm[j682];
			}
			for (int j684 = 0; j684 < 4; j684 = j684 + 1) {
				fRec438_tmp[j684] = fRec438_perm[j684];
			}
			for (int j686 = 0; j686 < 4; j686 = j686 + 1) {
				fRec439_tmp[j686] = fRec439_perm[j686];
			}
			for (int j688 = 0; j688 < 4; j688 = j688 + 1) {
				fRec433_tmp[j688] = fRec433_perm[j688];
			}
			for (int j690 = 0; j690 < 4; j690 = j690 + 1) {
				fRec434_tmp[j690] = fRec434_perm[j690];
			}
			for (int j692 = 0; j692 < 4; j692 = j692 + 1) {
				fRec428_tmp[j692] = fRec428_perm[j692];
			}
			for (int j694 = 0; j694 < 4; j694 = j694 + 1) {
				fRec429_tmp[j694] = fRec429_perm[j694];
			}
			for (int j696 = 0; j696 < 4; j696 = j696 + 1) {
				fRec423_tmp[j696] = fRec423_perm[j696];
			}
			for (int j698 = 0; j698 < 4; j698 = j698 + 1) {
				fRec424_tmp[j698] = fRec424_perm[j698];
			}
			for (int j700 = 0; j700 < 4; j700 = j700 + 1) {
				fRec418_tmp[j700] = fRec418_perm[j700];
			}
			for (int j702 = 0; j702 < 4; j702 = j702 + 1) {
				fRec419_tmp[j702] = fRec419_perm[j702];
			}
			for (int j704 = 0; j704 < 4; j704 = j704 + 1) {
				fRec413_tmp[j704] = fRec413_perm[j704];
			}
			for (int j706 = 0; j706 < 4; j706 = j706 + 1) {
				fRec414_tmp[j706] = fRec414_perm[j706];
			}
			for (int j708 = 0; j708 < 4; j708 = j708 + 1) {
				fRec408_tmp[j708] = fRec408_perm[j708];
			}
			for (int j710 = 0; j710 < 4; j710 = j710 + 1) {
				fRec409_tmp[j710] = fRec409_perm[j710];
			}
			for (int j712 = 0; j712 < 4; j712 = j712 + 1) {
				fRec403_tmp[j712] = fRec403_perm[j712];
			}
			for (int j714 = 0; j714 < 4; j714 = j714 + 1) {
				fRec404_tmp[j714] = fRec404_perm[j714];
			}
			for (int j716 = 0; j716 < 4; j716 = j716 + 1) {
				fRec398_tmp[j716] = fRec398_perm[j716];
			}
			for (int j718 = 0; j718 < 4; j718 = j718 + 1) {
				fRec399_tmp[j718] = fRec399_perm[j718];
			}
			for (int j720 = 0; j720 < 4; j720 = j720 + 1) {
				fRec393_tmp[j720] = fRec393_perm[j720];
			}
			for (int j722 = 0; j722 < 4; j722 = j722 + 1) {
				fRec394_tmp[j722] = fRec394_perm[j722];
			}
			for (int j724 = 0; j724 < 4; j724 = j724 + 1) {
				fRec388_tmp[j724] = fRec388_perm[j724];
			}
			for (int j726 = 0; j726 < 4; j726 = j726 + 1) {
				fRec389_tmp[j726] = fRec389_perm[j726];
			}
			for (int j728 = 0; j728 < 4; j728 = j728 + 1) {
				fRec383_tmp[j728] = fRec383_perm[j728];
			}
			for (int j730 = 0; j730 < 4; j730 = j730 + 1) {
				fRec384_tmp[j730] = fRec384_perm[j730];
			}
			fRec594_idx = (fRec594_idx + fRec594_idx_save) & 131071;
			for (int j732 = 0; j732 < 4; j732 = j732 + 1) {
				fRec593_tmp[j732] = fRec593_perm[j732];
			}
			fRec596_idx = (fRec596_idx + fRec596_idx_save) & 131071;
			for (int j734 = 0; j734 < 4; j734 = j734 + 1) {
				fRec595_tmp[j734] = fRec595_perm[j734];
			}
			for (int j736 = 0; j736 < 4; j736 = j736 + 1) {
				fRec5_tmp[j736] = fRec5_perm[j736];
			}
			for (int j738 = 0; j738 < 4; j738 = j738 + 1) {
				fRec6_tmp[j738] = fRec6_perm[j738];
			}
			for (int j746 = 0; j746 < 4; j746 = j746 + 1) {
				fRec600_tmp[j746] = fRec600_perm[j746];
			}
			for (int j748 = 0; j748 < 4; j748 = j748 + 1) {
				fRec601_tmp[j748] = fRec601_perm[j748];
			}
			for (int j750 = 0; j750 < 4; j750 = j750 + 1) {
				fRec3_tmp[j750] = fRec3_perm[j750];
			}
			for (int j752 = 0; j752 < 4; j752 = j752 + 1) {
				fRec4_tmp[j752] = fRec4_perm[j752];
			}
			for (int j754 = 0; j754 < 4; j754 = j754 + 1) {
				fRec1_tmp[j754] = fRec1_perm[j754];
			}
			for (int j756 = 0; j756 < 4; j756 = j756 + 1) {
				fRec2_tmp[j756] = fRec2_perm[j756];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec68[i] = 0.0f - fConst8 * (fConst9 * fRec73[i - 1] - fConst10 * fRec1[i - 2]);
				fRec74[i] = fYec68[i - 1] + fConst8 * (fConst11 * fRec1[i - 1] - 2.0f * (fConst13 * fRec74[i - 1] - fConst14 * fRec1[i - 2]));
				fRec73[i] = fRec74[i];
				fYec69[i] = 0.500327051f * fRec73[i - 1] - fConst20 * fRec71[i - 1];
				fRec72[i] = fConst18 * fRec73[i - 1] + fConst19 * (fYec69[i - 1] - fConst21 * fRec72[i - 1] + 0.500327051f * fRec73[i]);
				fRec71[i] = fRec72[i];
				fYec70[i] = 0.0f - fConst8 * (fConst9 * fRec77[i - 1] - fConst10 * fRec2[i - 2]);
				fRec78[i] = fYec70[i - 1] + fConst8 * (fConst11 * fRec2[i - 1] - 2.0f * (fConst13 * fRec78[i - 1] - fConst14 * fRec2[i - 2]));
				fRec77[i] = fRec78[i];
				fYec71[i] = 0.500327051f * fRec77[i - 1] - fConst20 * fRec75[i - 1];
				fRec76[i] = fConst18 * fRec77[i - 1] + fConst19 * (fYec71[i - 1] - fConst21 * fRec76[i - 1] + 0.500327051f * fRec77[i]);
				fRec75[i] = fRec76[i];
				fYec72[i] = mydsp_faustpower2_f(fRec71[i]);
				fYec73[i] = fYec72[i] + fYec72[i - 1];
				fYec74[i] = fYec73[i] + fYec73[i - 2];
				fYec75[i] = fYec74[i] + fYec74[i - 4];
				fYec76[(i + fYec76_idx) & 63] = fYec75[i] + fYec75[i - 8];
				fYec77[(i + fYec77_idx) & 127] = fYec76[(i + fYec76_idx) & 63] + fYec76[((i + fYec76_idx) - 16) & 63];
				fYec78[(i + fYec78_idx) & 255] = fYec77[(i + fYec77_idx) & 127] + fYec77[((i + fYec77_idx) - 32) & 127];
				fYec79[(i + fYec79_idx) & 511] = fYec78[(i + fYec78_idx) & 255] + fYec78[((i + fYec78_idx) - 64) & 255];
				fYec80[(i + fYec80_idx) & 1023] = fYec79[(i + fYec79_idx) & 511] + fYec79[((i + fYec79_idx) - 128) & 511];
				fYec81[(i + fYec81_idx) & 2047] = fYec80[(i + fYec80_idx) & 1023] + fYec80[((i + fYec80_idx) - 256) & 1023];
				fYec82[(i + fYec82_idx) & 4095] = fYec81[(i + fYec81_idx) & 2047] + fYec81[((i + fYec81_idx) - 512) & 2047];
				fYec83[(i + fYec83_idx) & 8191] = fYec82[(i + fYec82_idx) & 4095] + fYec82[((i + fYec82_idx) - 1024) & 4095];
				fYec84[(i + fYec84_idx) & 16383] = fYec83[(i + fYec83_idx) & 8191] + fYec83[((i + fYec83_idx) - 2048) & 8191];
				fYec85[(i + fYec85_idx) & 32767] = fYec84[(i + fYec84_idx) & 16383] + fYec84[((i + fYec84_idx) - 4096) & 16383];
				fYec86[(i + fYec86_idx) & 65535] = fYec85[(i + fYec85_idx) & 32767] + fYec85[((i + fYec85_idx) - 8192) & 32767];
				fYec87[(i + fYec87_idx) & 131071] = fYec86[(i + fYec86_idx) & 65535] + fYec86[((i + fYec86_idx) - 16384) & 65535];
				fYec88[(i + fYec88_idx) & 262143] = fYec87[(i + fYec87_idx) & 131071] + fYec87[((i + fYec87_idx) - 32768) & 131071];
				float fElse68 = fYec88[((i + fYec88_idx) - iConst200) & 262143];
				float fElse69 = fYec87[((i + fYec87_idx) - iConst202) & 131071];
				float fElse70 = fYec86[((i + fYec86_idx) - iConst204) & 65535];
				float fElse71 = fYec85[((i + fYec85_idx) - iConst206) & 32767];
				float fElse72 = fYec84[((i + fYec84_idx) - iConst208) & 16383];
				float fElse73 = fYec83[((i + fYec83_idx) - iConst210) & 8191];
				float fElse74 = fYec82[((i + fYec82_idx) - iConst212) & 4095];
				float fElse75 = fYec81[((i + fYec81_idx) - iConst214) & 2047];
				float fElse76 = fYec80[((i + fYec80_idx) - iConst216) & 1023];
				float fElse77 = fYec79[((i + fYec79_idx) - iConst218) & 511];
				float fElse78 = fYec78[((i + fYec78_idx) - iConst220) & 255];
				float fElse79 = fYec77[((i + fYec77_idx) - iConst222) & 127];
				float fElse80 = fYec76[((i + fYec76_idx) - iConst224) & 63];
				float fElse81 = fYec75[i - iConst226];
				float fElse82 = fYec74[i - iConst228];
				float fElse83 = fYec72[i];
				float fElse84 = fYec73[i - iConst229];
				fYec89[i] = mydsp_faustpower2_f(fRec75[i]);
				fYec90[i] = fYec89[i] + fYec89[i - 1];
				fYec91[i] = fYec90[i] + fYec90[i - 2];
				fYec92[i] = fYec91[i] + fYec91[i - 4];
				fYec93[(i + fYec93_idx) & 63] = fYec92[i] + fYec92[i - 8];
				fYec94[(i + fYec94_idx) & 127] = fYec93[(i + fYec93_idx) & 63] + fYec93[((i + fYec93_idx) - 16) & 63];
				fYec95[(i + fYec95_idx) & 255] = fYec94[(i + fYec94_idx) & 127] + fYec94[((i + fYec94_idx) - 32) & 127];
				fYec96[(i + fYec96_idx) & 511] = fYec95[(i + fYec95_idx) & 255] + fYec95[((i + fYec95_idx) - 64) & 255];
				fYec97[(i + fYec97_idx) & 1023] = fYec96[(i + fYec96_idx) & 511] + fYec96[((i + fYec96_idx) - 128) & 511];
				fYec98[(i + fYec98_idx) & 2047] = fYec97[(i + fYec97_idx) & 1023] + fYec97[((i + fYec97_idx) - 256) & 1023];
				fYec99[(i + fYec99_idx) & 4095] = fYec98[(i + fYec98_idx) & 2047] + fYec98[((i + fYec98_idx) - 512) & 2047];
				fYec100[(i + fYec100_idx) & 8191] = fYec99[(i + fYec99_idx) & 4095] + fYec99[((i + fYec99_idx) - 1024) & 4095];
				fYec101[(i + fYec101_idx) & 16383] = fYec100[(i + fYec100_idx) & 8191] + fYec100[((i + fYec100_idx) - 2048) & 8191];
				fYec102[(i + fYec102_idx) & 32767] = fYec101[(i + fYec101_idx) & 16383] + fYec101[((i + fYec101_idx) - 4096) & 16383];
				fYec103[(i + fYec103_idx) & 65535] = fYec102[(i + fYec102_idx) & 32767] + fYec102[((i + fYec102_idx) - 8192) & 32767];
				fYec104[(i + fYec104_idx) & 131071] = fYec103[(i + fYec103_idx) & 65535] + fYec103[((i + fYec103_idx) - 16384) & 65535];
				fYec105[(i + fYec105_idx) & 262143] = fYec104[(i + fYec104_idx) & 131071] + fYec104[((i + fYec104_idx) - 32768) & 131071];
				float fElse85 = fYec105[((i + fYec105_idx) - iConst200) & 262143];
				float fElse86 = fYec104[((i + fYec104_idx) - iConst202) & 131071];
				float fElse87 = fYec103[((i + fYec103_idx) - iConst204) & 65535];
				float fElse88 = fYec102[((i + fYec102_idx) - iConst206) & 32767];
				float fElse89 = fYec101[((i + fYec101_idx) - iConst208) & 16383];
				float fElse90 = fYec100[((i + fYec100_idx) - iConst210) & 8191];
				float fElse91 = fYec99[((i + fYec99_idx) - iConst212) & 4095];
				float fElse92 = fYec98[((i + fYec98_idx) - iConst214) & 2047];
				float fElse93 = fYec97[((i + fYec97_idx) - iConst216) & 1023];
				float fElse94 = fYec96[((i + fYec96_idx) - iConst218) & 511];
				float fElse95 = fYec95[((i + fYec95_idx) - iConst220) & 255];
				float fElse96 = fYec94[((i + fYec94_idx) - iConst222) & 127];
				float fElse97 = fYec93[((i + fYec93_idx) - iConst224) & 63];
				float fElse98 = fYec92[i - iConst226];
				float fElse99 = fYec91[i - iConst228];
				float fElse100 = fYec89[i];
				float fElse101 = fYec90[i - iConst229];
				fRec10[i] = (1.0f - fZec62[i]) * std::max<float>(fSlow41, std::min<float>(fSlow42, fSlow43 + fRec9[i - 1] + 0.690999985f - 4.34294462f * std::log(std::max<float>(9.99999996e-13f, fConst168 * (((iConst169) ? fElse68 : 0.0f) + ((iConst201) ? fElse69 : 0.0f) + ((iConst203) ? fElse70 : 0.0f) + ((iConst205) ? fElse71 : 0.0f) + ((iConst207) ? fElse72 : 0.0f) + ((iConst209) ? fElse73 : 0.0f) + ((iConst211) ? fElse74 : 0.0f) + ((iConst213) ? fElse75 : 0.0f) + ((iConst215) ? fElse76 : 0.0f) + ((iConst217) ? fElse77 : 0.0f) + ((iConst219) ? fElse78 : 0.0f) + ((iConst221) ? fElse79 : 0.0f) + ((iConst223) ? fElse80 : 0.0f) + ((iConst225) ? fElse81 : 0.0f) + ((iConst227) ? fElse82 : 0.0f) + ((iConst229) ? fElse83 : 0.0f) + ((iConst230) ? fElse84 : 0.0f) + ((iConst169) ? fElse85 : 0.0f) + ((iConst201) ? fElse86 : 0.0f) + ((iConst203) ? fElse87 : 0.0f) + ((iConst205) ? fElse88 : 0.0f) + ((iConst207) ? fElse89 : 0.0f) + ((iConst209) ? fElse90 : 0.0f) + ((iConst211) ? fElse91 : 0.0f) + ((iConst213) ? fElse92 : 0.0f) + ((iConst215) ? fElse93 : 0.0f) + ((iConst217) ? fElse94 : 0.0f) + ((iConst219) ? fElse95 : 0.0f) + ((iConst221) ? fElse96 : 0.0f) + ((iConst223) ? fElse97 : 0.0f) + ((iConst225) ? fElse98 : 0.0f) + ((iConst227) ? fElse99 : 0.0f) + ((iConst229) ? fElse100 : 0.0f) + ((iConst230) ? fElse101 : 0.0f)))))) + fZec62[i] * fRec10[i - 1];
				fVbargraph5 = FAUSTFLOAT(fRec10[i]);
				fRec9[i] = fVbargraph5;
				fZec63[i] = fRec8[i] + (1.0f - fRec8[i]) * std::pow(10.0f, 0.0500000007f * fRec9[i]);
				fZec64[i] = fSlow47 * fRec3[i - 1] + fSlow48 * fZec53[i] * fZec63[i];
				fZec65[i] = fSlow47 * fRec4[i - 1] + fSlow48 * fZec54[i] * fZec63[i];
				fRec83[(i + fRec83_idx) & 262143] = fRec83[((i + fRec83_idx) - 1) & 262143] + mydsp_faustpower2_f(0.5f * (fZec64[i] + fZec65[i]));
				fZec66[i] = std::sqrt(fSlow50 * (fRec83[(i + fRec83_idx) & 262143] - fRec83[((i + fRec83_idx) - iSlow51) & 262143]));
				fZec67[i] = ((fZec66[i] > fRec82[i - 1]) ? fSlow54 : 0.0f);
				fRec82[i] = fZec66[i] * (1.0f - fZec67[i]) + fRec82[i - 1] * fZec67[i];
				fRec85[(i + fRec85_idx) & 262143] = fRec85[((i + fRec85_idx) - 1) & 262143] + mydsp_faustpower2_f(0.5f * (fZec64[i] - fZec65[i]));
				fZec68[i] = std::sqrt(fSlow50 * (fRec85[(i + fRec85_idx) & 262143] - fRec85[((i + fRec85_idx) - iSlow51) & 262143]));
				fZec69[i] = ((fZec68[i] > fRec84[i - 1]) ? fSlow54 : 0.0f);
				fRec84[i] = fZec68[i] * (1.0f - fZec69[i]) + fRec84[i - 1] * fZec69[i];
				fZec71[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, fRec82[i]));
				iZec72[i] = (fZec71[i] > fSlow61) + (fZec71[i] > fSlow62);
				fZec73[i] = fZec71[i] - fSlow58;
				float fThen106 = fZec73[i];
				float fElse106 = fSlow63 * mydsp_faustpower2_f(fSlow60 + fZec73[i]);
				float fThen107 = ((iZec72[i] == 1) ? fElse106 : fThen106);
				fZec74[i] = std::max<float>(0.0f, ((iZec72[i] == 0) ? 0.0f : fThen107));
				fZec75[i] = fSlow65 * fZec74[i];
				fZec76[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, fRec84[i]));
				iZec77[i] = (fZec76[i] > fSlow61) + (fZec76[i] > fSlow62);
				fZec78[i] = fZec76[i] - fSlow58;
				float fThen108 = fZec78[i];
				float fElse108 = fSlow63 * mydsp_faustpower2_f(fSlow60 + fZec78[i]);
				float fThen109 = ((iZec77[i] == 1) ? fElse108 : fThen108);
				fZec79[i] = std::max<float>(0.0f, ((iZec77[i] == 0) ? 0.0f : fThen109));
				fZec80[i] = fSlow65 * fZec79[i];
				fZec81[i] = std::min<float>(0.0f - fZec75[i], 0.0f - fZec80[i]);
				fZec82[i] = 0.0f - 0.00999999978f * (fSlow56 * fZec74[i] - fSlow64 * (fZec75[i] + fZec81[i]));
				fVbargraph6 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec82[i])));
				fZec83[i] = (fRec80[i] + fZec70[i] * std::pow(10.0f, 0.0500000007f * (fRec81[i] + fZec82[i]))) * (fZec53[i] + fZec54[i]);
				fZec84[i] = 0.0f - 0.00999999978f * (fSlow56 * fZec79[i] - fSlow64 * (fZec80[i] + fZec81[i]));
				fVbargraph7 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec84[i])));
				fZec85[i] = (fRec80[i] + fZec70[i] * std::pow(10.0f, 0.0500000007f * (fRec81[i] + fZec84[i]))) * (fZec53[i] - fZec54[i]);
				fZec86[i] = fZec53[i] + fRec79[i] * (0.5f * (fZec83[i] + fZec85[i]) - fZec53[i]);
				fZec87[i] = fZec54[i] + fRec79[i] * (0.5f * (fZec83[i] - fZec85[i]) - fZec54[i]);
				fZec88[i] = 0.5f * fZec63[i] * (fZec86[i] + fZec87[i]);
				fRec90[i] = fZec88[i] - fSlow70 * (fSlow71 * fRec90[i - 2] + fSlow74 * fRec90[i - 1]);
				fRec89[i] = fSlow70 * (fSlow73 * fRec90[i] + fSlow75 * fRec90[i - 1] + fSlow73 * fRec90[i - 2]) - fSlow76 * (fSlow77 * fRec89[i - 2] + fSlow74 * fRec89[i - 1]);
				fRec88[i] = fSlow76 * (fSlow73 * fRec89[i] + fSlow75 * fRec89[i - 1] + fSlow73 * fRec89[i - 2]) - fSlow78 * (fSlow79 * fRec88[i - 2] + fSlow74 * fRec88[i - 1]);
				fZec89[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow78 * (fSlow73 * fRec88[i] + fSlow75 * fRec88[i - 1] + fSlow73 * fRec88[i - 2]))));
				iZec90[i] = (fZec89[i] > fSlow87) + (fZec89[i] > fSlow88);
				fZec91[i] = fZec89[i] - fSlow84;
				float fThen110 = fZec91[i];
				float fElse110 = fSlow89 * mydsp_faustpower2_f(fSlow86 + fZec91[i]);
				float fThen111 = ((iZec90[i] == 1) ? fElse110 : fThen110);
				fZec92[i] = 0.0f - fSlow82 * std::max<float>(0.0f, ((iZec90[i] == 0) ? 0.0f : fThen111));
				fZec93[i] = ((fZec92[i] > fRec87[i - 1]) ? fSlow99 : fSlow94);
				fRec87[i] = fZec92[i] * (1.0f - fZec93[i]) + fRec87[i - 1] * fZec93[i];
				fZec94[i] = 0.5f * fZec63[i] * (fZec86[i] - fZec87[i]);
				fRec94[i] = fZec94[i] - fSlow70 * (fSlow71 * fRec94[i - 2] + fSlow74 * fRec94[i - 1]);
				fRec93[i] = fSlow70 * (fSlow73 * fRec94[i] + fSlow75 * fRec94[i - 1] + fSlow73 * fRec94[i - 2]) - fSlow76 * (fSlow77 * fRec93[i - 2] + fSlow74 * fRec93[i - 1]);
				fRec92[i] = fSlow76 * (fSlow73 * fRec93[i] + fSlow75 * fRec93[i - 1] + fSlow73 * fRec93[i - 2]) - fSlow78 * (fSlow79 * fRec92[i - 2] + fSlow74 * fRec92[i - 1]);
				fZec95[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow78 * (fSlow73 * fRec92[i] + fSlow75 * fRec92[i - 1] + fSlow73 * fRec92[i - 2]))));
				iZec96[i] = (fZec95[i] > fSlow87) + (fZec95[i] > fSlow88);
				fZec97[i] = fZec95[i] - fSlow84;
				float fThen117 = fZec97[i];
				float fElse117 = fSlow89 * mydsp_faustpower2_f(fSlow86 + fZec97[i]);
				float fThen118 = ((iZec96[i] == 1) ? fElse117 : fThen117);
				fZec98[i] = 0.0f - fSlow82 * std::max<float>(0.0f, ((iZec96[i] == 0) ? 0.0f : fThen118));
				fZec99[i] = ((fZec98[i] > fRec91[i - 1]) ? fSlow99 : fSlow94);
				fRec91[i] = fZec98[i] * (1.0f - fZec99[i]) + fRec91[i - 1] * fZec99[i];
				fRec325[i] = fSlow70 * (fRec90[i - 2] + fRec90[i] + 2.0f * fRec90[i - 1]) - fSlow76 * (fSlow77 * fRec325[i - 2] + fSlow74 * fRec325[i - 1]);
				fRec324[i] = fSlow76 * (fRec325[i - 2] + fRec325[i] + 2.0f * fRec325[i - 1]) - fSlow78 * (fSlow79 * fRec324[i - 2] + fSlow74 * fRec324[i - 1]);
				fRec323[i] = fSlow78 * (fRec324[i - 2] + fRec324[i] + 2.0f * fRec324[i - 1]) - fSlow102 * (fSlow103 * fRec323[i - 2] + fSlow106 * fRec323[i - 1]);
				fRec322[i] = fSlow102 * (fRec323[i - 2] + fRec323[i] + 2.0f * fRec323[i - 1]) - fSlow107 * (fSlow108 * fRec322[i - 2] + fSlow106 * fRec322[i - 1]);
				fRec321[i] = fSlow107 * (fRec322[i - 2] + fRec322[i] + 2.0f * fRec322[i - 1]) - fSlow109 * (fSlow110 * fRec321[i - 2] + fSlow106 * fRec321[i - 1]);
				fRec320[i] = fSlow109 * (fRec321[i - 2] + fRec321[i] + 2.0f * fRec321[i - 1]) - fSlow113 * (fSlow114 * fRec320[i - 2] + fSlow117 * fRec320[i - 1]);
				fRec319[i] = fSlow113 * (fRec320[i - 2] + fRec320[i] + 2.0f * fRec320[i - 1]) - fSlow118 * (fSlow119 * fRec319[i - 2] + fSlow117 * fRec319[i - 1]);
				fRec318[i] = fSlow118 * (fRec319[i - 2] + fRec319[i] + 2.0f * fRec319[i - 1]) - fSlow120 * (fSlow121 * fRec318[i - 2] + fSlow117 * fRec318[i - 1]);
				fRec317[i] = fSlow120 * (fRec318[i - 2] + fRec318[i] + 2.0f * fRec318[i - 1]) - fSlow124 * (fSlow125 * fRec317[i - 2] + fSlow128 * fRec317[i - 1]);
				fRec316[i] = fSlow124 * (fRec317[i - 2] + fRec317[i] + 2.0f * fRec317[i - 1]) - fSlow129 * (fSlow130 * fRec316[i - 2] + fSlow128 * fRec316[i - 1]);
				fRec315[i] = fSlow129 * (fRec316[i - 2] + fRec316[i] + 2.0f * fRec316[i - 1]) - fSlow131 * (fSlow132 * fRec315[i - 2] + fSlow128 * fRec315[i - 1]);
				fRec314[i] = fSlow131 * (fRec315[i - 2] + fRec315[i] + 2.0f * fRec315[i - 1]) - fSlow135 * (fSlow136 * fRec314[i - 2] + fSlow139 * fRec314[i - 1]);
				fRec313[i] = fSlow135 * (fRec314[i - 2] + fRec314[i] + 2.0f * fRec314[i - 1]) - fSlow140 * (fSlow141 * fRec313[i - 2] + fSlow139 * fRec313[i - 1]);
				fRec312[i] = fSlow140 * (fRec313[i - 2] + fRec313[i] + 2.0f * fRec313[i - 1]) - fSlow142 * (fSlow143 * fRec312[i - 2] + fSlow139 * fRec312[i - 1]);
				fRec311[i] = fSlow142 * (fRec312[i - 2] + fRec312[i] + 2.0f * fRec312[i - 1]) - fSlow146 * (fSlow147 * fRec311[i - 2] + fSlow150 * fRec311[i - 1]);
				fRec310[i] = fSlow146 * (fRec311[i - 2] + fRec311[i] + 2.0f * fRec311[i - 1]) - fSlow151 * (fSlow152 * fRec310[i - 2] + fSlow150 * fRec310[i - 1]);
				fRec309[i] = fSlow151 * (fRec310[i - 2] + fRec310[i] + 2.0f * fRec310[i - 1]) - fSlow153 * (fSlow154 * fRec309[i - 2] + fSlow150 * fRec309[i - 1]);
				fRec308[i] = fSlow153 * (fRec309[i - 2] + fRec309[i] + 2.0f * fRec309[i - 1]) - fSlow157 * (fSlow158 * fRec308[i - 2] + fSlow161 * fRec308[i - 1]);
				fRec307[i] = fSlow157 * (fRec308[i - 2] + fRec308[i] + 2.0f * fRec308[i - 1]) - fSlow162 * (fSlow163 * fRec307[i - 2] + fSlow161 * fRec307[i - 1]);
				fRec306[i] = fSlow162 * (fRec307[i - 2] + fRec307[i] + 2.0f * fRec307[i - 1]) - fSlow164 * (fSlow165 * fRec306[i - 2] + fSlow161 * fRec306[i - 1]);
				fZec100[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow164 * (fRec306[i - 2] + fRec306[i] + 2.0f * fRec306[i - 1]))));
				iZec101[i] = (fZec100[i] > fSlow171) + (fZec100[i] > fSlow172);
				fZec102[i] = fZec100[i] - fSlow168;
				float fThen120 = fZec102[i];
				float fElse120 = fSlow173 * mydsp_faustpower2_f(fSlow170 + fZec102[i]);
				float fThen121 = ((iZec101[i] == 1) ? fElse120 : fThen120);
				fZec103[i] = 0.0f - fSlow166 * std::max<float>(0.0f, ((iZec101[i] == 0) ? 0.0f : fThen121));
				fZec104[i] = ((fZec103[i] > fRec305[i - 1]) ? fSlow177 : fSlow175);
				fRec305[i] = fZec103[i] * (1.0f - fZec104[i]) + fRec305[i - 1] * fZec104[i];
				fRec346[i] = fSlow70 * (fRec94[i - 2] + fRec94[i] + 2.0f * fRec94[i - 1]) - fSlow76 * (fSlow77 * fRec346[i - 2] + fSlow74 * fRec346[i - 1]);
				fRec345[i] = fSlow76 * (fRec346[i - 2] + fRec346[i] + 2.0f * fRec346[i - 1]) - fSlow78 * (fSlow79 * fRec345[i - 2] + fSlow74 * fRec345[i - 1]);
				fRec344[i] = fSlow78 * (fRec345[i - 2] + fRec345[i] + 2.0f * fRec345[i - 1]) - fSlow102 * (fSlow103 * fRec344[i - 2] + fSlow106 * fRec344[i - 1]);
				fRec343[i] = fSlow102 * (fRec344[i - 2] + fRec344[i] + 2.0f * fRec344[i - 1]) - fSlow107 * (fSlow108 * fRec343[i - 2] + fSlow106 * fRec343[i - 1]);
				fRec342[i] = fSlow107 * (fRec343[i - 2] + fRec343[i] + 2.0f * fRec343[i - 1]) - fSlow109 * (fSlow110 * fRec342[i - 2] + fSlow106 * fRec342[i - 1]);
				fRec341[i] = fSlow109 * (fRec342[i - 2] + fRec342[i] + 2.0f * fRec342[i - 1]) - fSlow113 * (fSlow114 * fRec341[i - 2] + fSlow117 * fRec341[i - 1]);
				fRec340[i] = fSlow113 * (fRec341[i - 2] + fRec341[i] + 2.0f * fRec341[i - 1]) - fSlow118 * (fSlow119 * fRec340[i - 2] + fSlow117 * fRec340[i - 1]);
				fRec339[i] = fSlow118 * (fRec340[i - 2] + fRec340[i] + 2.0f * fRec340[i - 1]) - fSlow120 * (fSlow121 * fRec339[i - 2] + fSlow117 * fRec339[i - 1]);
				fRec338[i] = fSlow120 * (fRec339[i - 2] + fRec339[i] + 2.0f * fRec339[i - 1]) - fSlow124 * (fSlow125 * fRec338[i - 2] + fSlow128 * fRec338[i - 1]);
				fRec337[i] = fSlow124 * (fRec338[i - 2] + fRec338[i] + 2.0f * fRec338[i - 1]) - fSlow129 * (fSlow130 * fRec337[i - 2] + fSlow128 * fRec337[i - 1]);
				fRec336[i] = fSlow129 * (fRec337[i - 2] + fRec337[i] + 2.0f * fRec337[i - 1]) - fSlow131 * (fSlow132 * fRec336[i - 2] + fSlow128 * fRec336[i - 1]);
				fRec335[i] = fSlow131 * (fRec336[i - 2] + fRec336[i] + 2.0f * fRec336[i - 1]) - fSlow135 * (fSlow136 * fRec335[i - 2] + fSlow139 * fRec335[i - 1]);
				fRec334[i] = fSlow135 * (fRec335[i - 2] + fRec335[i] + 2.0f * fRec335[i - 1]) - fSlow140 * (fSlow141 * fRec334[i - 2] + fSlow139 * fRec334[i - 1]);
				fRec333[i] = fSlow140 * (fRec334[i - 2] + fRec334[i] + 2.0f * fRec334[i - 1]) - fSlow142 * (fSlow143 * fRec333[i - 2] + fSlow139 * fRec333[i - 1]);
				fRec332[i] = fSlow142 * (fRec333[i - 2] + fRec333[i] + 2.0f * fRec333[i - 1]) - fSlow146 * (fSlow147 * fRec332[i - 2] + fSlow150 * fRec332[i - 1]);
				fRec331[i] = fSlow146 * (fRec332[i - 2] + fRec332[i] + 2.0f * fRec332[i - 1]) - fSlow151 * (fSlow152 * fRec331[i - 2] + fSlow150 * fRec331[i - 1]);
				fRec330[i] = fSlow151 * (fRec331[i - 2] + fRec331[i] + 2.0f * fRec331[i - 1]) - fSlow153 * (fSlow154 * fRec330[i - 2] + fSlow150 * fRec330[i - 1]);
				fRec329[i] = fSlow153 * (fRec330[i - 2] + fRec330[i] + 2.0f * fRec330[i - 1]) - fSlow157 * (fSlow158 * fRec329[i - 2] + fSlow161 * fRec329[i - 1]);
				fRec328[i] = fSlow157 * (fRec329[i - 2] + fRec329[i] + 2.0f * fRec329[i - 1]) - fSlow162 * (fSlow163 * fRec328[i - 2] + fSlow161 * fRec328[i - 1]);
				fRec327[i] = fSlow162 * (fRec328[i - 2] + fRec328[i] + 2.0f * fRec328[i - 1]) - fSlow164 * (fSlow165 * fRec327[i - 2] + fSlow161 * fRec327[i - 1]);
				fZec105[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow164 * (fRec327[i - 2] + fRec327[i] + 2.0f * fRec327[i - 1]))));
				iZec106[i] = (fZec105[i] > fSlow171) + (fZec105[i] > fSlow172);
				fZec107[i] = fZec105[i] - fSlow168;
				float fThen127 = fZec107[i];
				float fElse127 = fSlow173 * mydsp_faustpower2_f(fSlow170 + fZec107[i]);
				float fThen128 = ((iZec106[i] == 1) ? fElse127 : fThen127);
				fZec108[i] = 0.0f - fSlow166 * std::max<float>(0.0f, ((iZec106[i] == 0) ? 0.0f : fThen128));
				fZec109[i] = ((fZec108[i] > fRec326[i - 1]) ? fSlow177 : fSlow175);
				fRec326[i] = fZec108[i] * (1.0f - fZec109[i]) + fRec326[i - 1] * fZec109[i];
				fZec110[i] = std::min<float>(fRec305[i], fRec326[i]);
				fZec111[i] = fRec305[i] + fSlow179 * (fZec110[i] - fRec305[i]);
				fVbargraph8 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec111[i])));
				fZec112[i] = std::pow(10.0f, 0.00833333377f * fZec111[i]);
				fZec113[i] = std::sqrt(fZec112[i]);
				fZec114[i] = fRec300[i - 1] + fSlow155 * (fZec88[i] - fRec301[i - 1]) / fZec113[i];
				fZec115[i] = fSlow155 / fZec113[i];
				fZec116[i] = fSlow155 * (fZec115[i] + 2.0f) / fZec113[i] + 1.0f;
				fZec117[i] = fZec114[i] / fZec116[i];
				fRec300[i] = 2.0f * fZec117[i] - fRec300[i - 1];
				fZec118[i] = fRec301[i - 1] + fSlow155 * fZec114[i] / (fZec113[i] * fZec116[i]);
				fRec301[i] = 2.0f * fZec118[i] - fRec301[i - 1];
				fRec302[i] = fZec88[i];
				fRec303[i] = fZec117[i];
				fRec304[i] = fZec118[i];
				fZec119[i] = fZec112[i] + -1.0f;
				fZec120[i] = mydsp_faustpower2_f(fZec112[i]) + -1.0f;
				fZec121[i] = fRec302[i] + 2.0f * fRec303[i] * fZec119[i] + fRec304[i] * fZec120[i];
				fZec122[i] = fRec295[i - 1] + fSlow155 * (fZec121[i] - fRec296[i - 1]) / fZec113[i];
				fZec123[i] = fSlow155 * (fZec115[i] + 1.41442716f) / fZec113[i] + 1.0f;
				fZec124[i] = fZec122[i] / fZec123[i];
				fRec295[i] = 2.0f * fZec124[i] - fRec295[i - 1];
				fZec125[i] = fRec296[i - 1] + fSlow155 * fZec122[i] / (fZec113[i] * fZec123[i]);
				fRec296[i] = 2.0f * fZec125[i] - fRec296[i - 1];
				fRec297[i] = fZec121[i];
				fRec298[i] = fZec124[i];
				fRec299[i] = fZec125[i];
				fZec126[i] = fRec297[i] + 1.41442716f * fRec298[i] * fZec119[i] + fRec299[i] * fZec120[i];
				fZec127[i] = fRec290[i - 1] + fSlow155 * (fZec126[i] - fRec291[i - 1]) / fZec113[i];
				fZec128[i] = fSlow155 * (fZec115[i] + 0.5f) / fZec113[i] + 1.0f;
				fZec129[i] = fZec127[i] / fZec128[i];
				fRec290[i] = 2.0f * fZec129[i] - fRec290[i - 1];
				fZec130[i] = fRec291[i - 1] + fSlow155 * fZec127[i] / (fZec113[i] * fZec128[i]);
				fRec291[i] = 2.0f * fZec130[i] - fRec291[i - 1];
				fRec292[i] = fZec126[i];
				fRec293[i] = fZec129[i];
				fRec294[i] = fZec130[i];
				fRec349[i] = fSlow157 * (fSlow160 * fRec308[i] + fSlow180 * fRec308[i - 1] + fSlow160 * fRec308[i - 2]) - fSlow162 * (fSlow163 * fRec349[i - 2] + fSlow161 * fRec349[i - 1]);
				fRec348[i] = fSlow162 * (fSlow160 * fRec349[i] + fSlow180 * fRec349[i - 1] + fSlow160 * fRec349[i - 2]) - fSlow164 * (fSlow165 * fRec348[i - 2] + fSlow161 * fRec348[i - 1]);
				fZec131[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow164 * (fSlow160 * fRec348[i] + fSlow180 * fRec348[i - 1] + fSlow160 * fRec348[i - 2]))));
				iZec132[i] = (fZec131[i] > fSlow188) + (fZec131[i] > fSlow189);
				fZec133[i] = fZec131[i] - fSlow184;
				float fThen130 = fZec133[i];
				float fElse130 = fSlow190 * mydsp_faustpower2_f(fSlow187 + fZec133[i]);
				float fThen131 = ((iZec132[i] == 1) ? fElse130 : fThen130);
				fZec134[i] = 0.0f - fSlow181 * std::max<float>(0.0f, ((iZec132[i] == 0) ? 0.0f : fThen131));
				fZec135[i] = ((fZec134[i] > fRec347[i - 1]) ? fSlow196 : fSlow193);
				fRec347[i] = fZec134[i] * (1.0f - fZec135[i]) + fRec347[i - 1] * fZec135[i];
				fRec352[i] = fSlow157 * (fSlow160 * fRec329[i] + fSlow180 * fRec329[i - 1] + fSlow160 * fRec329[i - 2]) - fSlow162 * (fSlow163 * fRec352[i - 2] + fSlow161 * fRec352[i - 1]);
				fRec351[i] = fSlow162 * (fSlow160 * fRec352[i] + fSlow180 * fRec352[i - 1] + fSlow160 * fRec352[i - 2]) - fSlow164 * (fSlow165 * fRec351[i - 2] + fSlow161 * fRec351[i - 1]);
				fZec136[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow164 * (fSlow160 * fRec351[i] + fSlow180 * fRec351[i - 1] + fSlow160 * fRec351[i - 2]))));
				iZec137[i] = (fZec136[i] > fSlow188) + (fZec136[i] > fSlow189);
				fZec138[i] = fZec136[i] - fSlow184;
				float fThen137 = fZec138[i];
				float fElse137 = fSlow190 * mydsp_faustpower2_f(fSlow187 + fZec138[i]);
				float fThen138 = ((iZec137[i] == 1) ? fElse137 : fThen137);
				fZec139[i] = 0.0f - fSlow181 * std::max<float>(0.0f, ((iZec137[i] == 0) ? 0.0f : fThen138));
				fZec140[i] = ((fZec139[i] > fRec350[i - 1]) ? fSlow196 : fSlow193);
				fRec350[i] = fZec139[i] * (1.0f - fZec140[i]) + fRec350[i - 1] * fZec140[i];
				fZec141[i] = fRec292[i] + 0.5f * fRec293[i] * fZec119[i] + fRec294[i] * fZec120[i];
				fZec142[i] = std::min<float>(fRec347[i], fRec350[i]);
				fZec143[i] = fRec347[i] + fSlow198 * (fZec142[i] - fRec347[i]);
				fVbargraph9 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec143[i])));
				fZec144[i] = fZec143[i];
				fZec145[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec144[i]));
				fZec146[i] = std::sqrt(fZec145[i]);
				fZec147[i] = fRec285[i - 1] + fSlow155 * (fZec141[i] - fRec286[i - 1]) / fZec146[i];
				fZec148[i] = fSlow155 / fZec146[i];
				fZec149[i] = fSlow155 * (fZec148[i] + 2.0f) / fZec146[i] + 1.0f;
				fZec150[i] = fZec147[i] / fZec149[i];
				fRec285[i] = 2.0f * fZec150[i] - fRec285[i - 1];
				fZec151[i] = fRec286[i - 1] + fSlow155 * fZec147[i] / (fZec146[i] * fZec149[i]);
				fRec286[i] = 2.0f * fZec151[i] - fRec286[i - 1];
				fRec287[i] = fZec141[i];
				fRec288[i] = fZec150[i];
				fRec289[i] = fZec151[i];
				fZec152[i] = fZec145[i] + -1.0f;
				fZec153[i] = mydsp_faustpower2_f(fZec145[i]) + -1.0f;
				fZec154[i] = fRec287[i] + 2.0f * fRec288[i] * fZec152[i] + fRec289[i] * fZec153[i];
				fZec155[i] = fRec280[i - 1] + fSlow155 * (fZec154[i] - fRec281[i - 1]) / fZec146[i];
				fZec156[i] = fSlow155 * (fZec148[i] + 1.41442716f) / fZec146[i] + 1.0f;
				fZec157[i] = fZec155[i] / fZec156[i];
				fRec280[i] = 2.0f * fZec157[i] - fRec280[i - 1];
				fZec158[i] = fRec281[i - 1] + fSlow155 * fZec155[i] / (fZec146[i] * fZec156[i]);
				fRec281[i] = 2.0f * fZec158[i] - fRec281[i - 1];
				fRec282[i] = fZec154[i];
				fRec283[i] = fZec157[i];
				fRec284[i] = fZec158[i];
				fZec159[i] = fRec282[i] + 1.41442716f * fRec283[i] * fZec152[i] + fRec284[i] * fZec153[i];
				fZec160[i] = fRec275[i - 1] + fSlow155 * (fZec159[i] - fRec276[i - 1]) / fZec146[i];
				fZec161[i] = fSlow155 * (fZec148[i] + 0.5f) / fZec146[i] + 1.0f;
				fZec162[i] = fZec160[i] / fZec161[i];
				fRec275[i] = 2.0f * fZec162[i] - fRec275[i - 1];
				fZec163[i] = fRec276[i - 1] + fSlow155 * fZec160[i] / (fZec146[i] * fZec161[i]);
				fRec276[i] = 2.0f * fZec163[i] - fRec276[i - 1];
				fRec277[i] = fZec159[i];
				fRec278[i] = fZec162[i];
				fRec279[i] = fZec163[i];
				fZec164[i] = fRec277[i] + 0.5f * fRec278[i] * fZec152[i] + fRec279[i] * fZec153[i];
				fZec165[i] = std::pow(10.0f, 0.00833333377f * fZec144[i]);
				fZec166[i] = std::sqrt(fZec165[i]);
				fZec167[i] = fRec270[i - 1] + fSlow144 * (fZec164[i] - fRec271[i - 1]) / fZec166[i];
				fZec168[i] = fSlow144 / fZec166[i];
				fZec169[i] = fSlow144 * (fZec168[i] + 2.0f) / fZec166[i] + 1.0f;
				fZec170[i] = fZec167[i] / fZec169[i];
				fRec270[i] = 2.0f * fZec170[i] - fRec270[i - 1];
				fZec171[i] = fRec271[i - 1] + fSlow144 * fZec167[i] / (fZec166[i] * fZec169[i]);
				fRec271[i] = 2.0f * fZec171[i] - fRec271[i - 1];
				fRec272[i] = fZec164[i];
				fRec273[i] = fZec170[i];
				fRec274[i] = fZec171[i];
				fZec172[i] = fZec165[i] + -1.0f;
				fZec173[i] = mydsp_faustpower2_f(fZec165[i]) + -1.0f;
				fZec174[i] = fRec272[i] + 2.0f * fRec273[i] * fZec172[i] + fRec274[i] * fZec173[i];
				fZec175[i] = fRec265[i - 1] + fSlow144 * (fZec174[i] - fRec266[i - 1]) / fZec166[i];
				fZec176[i] = fSlow144 * (fZec168[i] + 1.41442716f) / fZec166[i] + 1.0f;
				fZec177[i] = fZec175[i] / fZec176[i];
				fRec265[i] = 2.0f * fZec177[i] - fRec265[i - 1];
				fZec178[i] = fRec266[i - 1] + fSlow144 * fZec175[i] / (fZec166[i] * fZec176[i]);
				fRec266[i] = 2.0f * fZec178[i] - fRec266[i - 1];
				fRec267[i] = fZec174[i];
				fRec268[i] = fZec177[i];
				fRec269[i] = fZec178[i];
				fZec179[i] = fRec267[i] + 1.41442716f * fRec268[i] * fZec172[i] + fRec269[i] * fZec173[i];
				fZec180[i] = fRec260[i - 1] + fSlow144 * (fZec179[i] - fRec261[i - 1]) / fZec166[i];
				fZec181[i] = fSlow144 * (fZec168[i] + 0.5f) / fZec166[i] + 1.0f;
				fZec182[i] = fZec180[i] / fZec181[i];
				fRec260[i] = 2.0f * fZec182[i] - fRec260[i - 1];
				fZec183[i] = fRec261[i - 1] + fSlow144 * fZec180[i] / (fZec166[i] * fZec181[i]);
				fRec261[i] = 2.0f * fZec183[i] - fRec261[i - 1];
				fRec262[i] = fZec179[i];
				fRec263[i] = fZec182[i];
				fRec264[i] = fZec183[i];
				fRec355[i] = fSlow146 * (fSlow149 * fRec311[i] + fSlow199 * fRec311[i - 1] + fSlow149 * fRec311[i - 2]) - fSlow151 * (fSlow152 * fRec355[i - 2] + fSlow150 * fRec355[i - 1]);
				fRec354[i] = fSlow151 * (fSlow149 * fRec355[i] + fSlow199 * fRec355[i - 1] + fSlow149 * fRec355[i - 2]) - fSlow153 * (fSlow154 * fRec354[i - 2] + fSlow150 * fRec354[i - 1]);
				fZec184[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow153 * (fSlow149 * fRec354[i] + fSlow199 * fRec354[i - 1] + fSlow149 * fRec354[i - 2]))));
				iZec185[i] = (fZec184[i] > fSlow205) + (fZec184[i] > fSlow206);
				fZec186[i] = fZec184[i] - fSlow202;
				float fThen140 = fZec186[i];
				float fElse140 = fSlow207 * mydsp_faustpower2_f(fSlow204 + fZec186[i]);
				float fThen141 = ((iZec185[i] == 1) ? fElse140 : fThen140);
				fZec187[i] = 0.0f - fSlow200 * std::max<float>(0.0f, ((iZec185[i] == 0) ? 0.0f : fThen141));
				fZec188[i] = ((fZec187[i] > fRec353[i - 1]) ? fSlow213 : fSlow210);
				fRec353[i] = fZec187[i] * (1.0f - fZec188[i]) + fRec353[i - 1] * fZec188[i];
				fRec358[i] = fSlow146 * (fSlow149 * fRec332[i] + fSlow199 * fRec332[i - 1] + fSlow149 * fRec332[i - 2]) - fSlow151 * (fSlow152 * fRec358[i - 2] + fSlow150 * fRec358[i - 1]);
				fRec357[i] = fSlow151 * (fSlow149 * fRec358[i] + fSlow199 * fRec358[i - 1] + fSlow149 * fRec358[i - 2]) - fSlow153 * (fSlow154 * fRec357[i - 2] + fSlow150 * fRec357[i - 1]);
				fZec189[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow153 * (fSlow149 * fRec357[i] + fSlow199 * fRec357[i - 1] + fSlow149 * fRec357[i - 2]))));
				iZec190[i] = (fZec189[i] > fSlow205) + (fZec189[i] > fSlow206);
				fZec191[i] = fZec189[i] - fSlow202;
				float fThen147 = fZec191[i];
				float fElse147 = fSlow207 * mydsp_faustpower2_f(fSlow204 + fZec191[i]);
				float fThen148 = ((iZec190[i] == 1) ? fElse147 : fThen147);
				fZec192[i] = 0.0f - fSlow200 * std::max<float>(0.0f, ((iZec190[i] == 0) ? 0.0f : fThen148));
				fZec193[i] = ((fZec192[i] > fRec356[i - 1]) ? fSlow213 : fSlow210);
				fRec356[i] = fZec192[i] * (1.0f - fZec193[i]) + fRec356[i - 1] * fZec193[i];
				fZec194[i] = fRec262[i] + 0.5f * fRec263[i] * fZec172[i] + fRec264[i] * fZec173[i];
				fZec195[i] = std::min<float>(fRec353[i], fRec356[i]);
				fZec196[i] = fRec353[i] + fSlow214 * (fZec195[i] - fRec353[i]);
				fVbargraph10 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec196[i])));
				fZec197[i] = fZec196[i];
				fZec198[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec197[i]));
				fZec199[i] = std::sqrt(fZec198[i]);
				fZec200[i] = fRec255[i - 1] + fSlow144 * (fZec194[i] - fRec256[i - 1]) / fZec199[i];
				fZec201[i] = fSlow144 / fZec199[i];
				fZec202[i] = fSlow144 * (fZec201[i] + 2.0f) / fZec199[i] + 1.0f;
				fZec203[i] = fZec200[i] / fZec202[i];
				fRec255[i] = 2.0f * fZec203[i] - fRec255[i - 1];
				fZec204[i] = fRec256[i - 1] + fSlow144 * fZec200[i] / (fZec199[i] * fZec202[i]);
				fRec256[i] = 2.0f * fZec204[i] - fRec256[i - 1];
				fRec257[i] = fZec194[i];
				fRec258[i] = fZec203[i];
				fRec259[i] = fZec204[i];
				fZec205[i] = fZec198[i] + -1.0f;
				fZec206[i] = mydsp_faustpower2_f(fZec198[i]) + -1.0f;
				fZec207[i] = fRec257[i] + 2.0f * fRec258[i] * fZec205[i] + fRec259[i] * fZec206[i];
				fZec208[i] = fRec250[i - 1] + fSlow144 * (fZec207[i] - fRec251[i - 1]) / fZec199[i];
				fZec209[i] = fSlow144 * (fZec201[i] + 1.41442716f) / fZec199[i] + 1.0f;
				fZec210[i] = fZec208[i] / fZec209[i];
				fRec250[i] = 2.0f * fZec210[i] - fRec250[i - 1];
				fZec211[i] = fRec251[i - 1] + fSlow144 * fZec208[i] / (fZec199[i] * fZec209[i]);
				fRec251[i] = 2.0f * fZec211[i] - fRec251[i - 1];
				fRec252[i] = fZec207[i];
				fRec253[i] = fZec210[i];
				fRec254[i] = fZec211[i];
				fZec212[i] = fRec252[i] + 1.41442716f * fRec253[i] * fZec205[i] + fRec254[i] * fZec206[i];
				fZec213[i] = fRec245[i - 1] + fSlow144 * (fZec212[i] - fRec246[i - 1]) / fZec199[i];
				fZec214[i] = fSlow144 * (fZec201[i] + 0.5f) / fZec199[i] + 1.0f;
				fZec215[i] = fZec213[i] / fZec214[i];
				fRec245[i] = 2.0f * fZec215[i] - fRec245[i - 1];
				fZec216[i] = fRec246[i - 1] + fSlow144 * fZec213[i] / (fZec199[i] * fZec214[i]);
				fRec246[i] = 2.0f * fZec216[i] - fRec246[i - 1];
				fRec247[i] = fZec212[i];
				fRec248[i] = fZec215[i];
				fRec249[i] = fZec216[i];
				fZec217[i] = fRec247[i] + 0.5f * fRec248[i] * fZec205[i] + fRec249[i] * fZec206[i];
				fZec218[i] = std::pow(10.0f, 0.00833333377f * fZec197[i]);
				fZec219[i] = std::sqrt(fZec218[i]);
				fZec220[i] = fRec240[i - 1] + fSlow133 * (fZec217[i] - fRec241[i - 1]) / fZec219[i];
				fZec221[i] = fSlow133 / fZec219[i];
				fZec222[i] = fSlow133 * (fZec221[i] + 2.0f) / fZec219[i] + 1.0f;
				fZec223[i] = fZec220[i] / fZec222[i];
				fRec240[i] = 2.0f * fZec223[i] - fRec240[i - 1];
				fZec224[i] = fRec241[i - 1] + fSlow133 * fZec220[i] / (fZec219[i] * fZec222[i]);
				fRec241[i] = 2.0f * fZec224[i] - fRec241[i - 1];
				fRec242[i] = fZec217[i];
				fRec243[i] = fZec223[i];
				fRec244[i] = fZec224[i];
				fZec225[i] = fZec218[i] + -1.0f;
				fZec226[i] = mydsp_faustpower2_f(fZec218[i]) + -1.0f;
				fZec227[i] = fRec242[i] + 2.0f * fRec243[i] * fZec225[i] + fRec244[i] * fZec226[i];
				fZec228[i] = fRec235[i - 1] + fSlow133 * (fZec227[i] - fRec236[i - 1]) / fZec219[i];
				fZec229[i] = fSlow133 * (fZec221[i] + 1.41442716f) / fZec219[i] + 1.0f;
				fZec230[i] = fZec228[i] / fZec229[i];
				fRec235[i] = 2.0f * fZec230[i] - fRec235[i - 1];
				fZec231[i] = fRec236[i - 1] + fSlow133 * fZec228[i] / (fZec219[i] * fZec229[i]);
				fRec236[i] = 2.0f * fZec231[i] - fRec236[i - 1];
				fRec237[i] = fZec227[i];
				fRec238[i] = fZec230[i];
				fRec239[i] = fZec231[i];
				fZec232[i] = fRec237[i] + 1.41442716f * fRec238[i] * fZec225[i] + fRec239[i] * fZec226[i];
				fZec233[i] = fRec230[i - 1] + fSlow133 * (fZec232[i] - fRec231[i - 1]) / fZec219[i];
				fZec234[i] = fSlow133 * (fZec221[i] + 0.5f) / fZec219[i] + 1.0f;
				fZec235[i] = fZec233[i] / fZec234[i];
				fRec230[i] = 2.0f * fZec235[i] - fRec230[i - 1];
				fZec236[i] = fRec231[i - 1] + fSlow133 * fZec233[i] / (fZec219[i] * fZec234[i]);
				fRec231[i] = 2.0f * fZec236[i] - fRec231[i - 1];
				fRec232[i] = fZec232[i];
				fRec233[i] = fZec235[i];
				fRec234[i] = fZec236[i];
				fRec361[i] = fSlow135 * (fSlow138 * fRec314[i] + fSlow215 * fRec314[i - 1] + fSlow138 * fRec314[i - 2]) - fSlow140 * (fSlow141 * fRec361[i - 2] + fSlow139 * fRec361[i - 1]);
				fRec360[i] = fSlow140 * (fSlow138 * fRec361[i] + fSlow215 * fRec361[i - 1] + fSlow138 * fRec361[i - 2]) - fSlow142 * (fSlow143 * fRec360[i - 2] + fSlow139 * fRec360[i - 1]);
				fZec237[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow142 * (fSlow138 * fRec360[i] + fSlow215 * fRec360[i - 1] + fSlow138 * fRec360[i - 2]))));
				iZec238[i] = (fZec237[i] > fSlow221) + (fZec237[i] > fSlow222);
				fZec239[i] = fZec237[i] - fSlow218;
				float fThen150 = fZec239[i];
				float fElse150 = fSlow223 * mydsp_faustpower2_f(fSlow220 + fZec239[i]);
				float fThen151 = ((iZec238[i] == 1) ? fElse150 : fThen150);
				fZec240[i] = 0.0f - fSlow216 * std::max<float>(0.0f, ((iZec238[i] == 0) ? 0.0f : fThen151));
				fZec241[i] = ((fZec240[i] > fRec359[i - 1]) ? fSlow229 : fSlow226);
				fRec359[i] = fZec240[i] * (1.0f - fZec241[i]) + fRec359[i - 1] * fZec241[i];
				fRec364[i] = fSlow135 * (fSlow138 * fRec335[i] + fSlow215 * fRec335[i - 1] + fSlow138 * fRec335[i - 2]) - fSlow140 * (fSlow141 * fRec364[i - 2] + fSlow139 * fRec364[i - 1]);
				fRec363[i] = fSlow140 * (fSlow138 * fRec364[i] + fSlow215 * fRec364[i - 1] + fSlow138 * fRec364[i - 2]) - fSlow142 * (fSlow143 * fRec363[i - 2] + fSlow139 * fRec363[i - 1]);
				fZec242[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow142 * (fSlow138 * fRec363[i] + fSlow215 * fRec363[i - 1] + fSlow138 * fRec363[i - 2]))));
				iZec243[i] = (fZec242[i] > fSlow221) + (fZec242[i] > fSlow222);
				fZec244[i] = fZec242[i] - fSlow218;
				float fThen157 = fZec244[i];
				float fElse157 = fSlow223 * mydsp_faustpower2_f(fSlow220 + fZec244[i]);
				float fThen158 = ((iZec243[i] == 1) ? fElse157 : fThen157);
				fZec245[i] = 0.0f - fSlow216 * std::max<float>(0.0f, ((iZec243[i] == 0) ? 0.0f : fThen158));
				fZec246[i] = ((fZec245[i] > fRec362[i - 1]) ? fSlow229 : fSlow226);
				fRec362[i] = fZec245[i] * (1.0f - fZec246[i]) + fRec362[i - 1] * fZec246[i];
				fZec247[i] = fRec232[i] + 0.5f * fRec233[i] * fZec225[i] + fRec234[i] * fZec226[i];
				fZec248[i] = std::min<float>(fRec359[i], fRec362[i]);
				fZec249[i] = fRec359[i] + fSlow230 * (fZec248[i] - fRec359[i]);
				fVbargraph11 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec249[i])));
				fZec250[i] = fZec249[i];
				fZec251[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec250[i]));
				fZec252[i] = std::sqrt(fZec251[i]);
				fZec253[i] = fRec225[i - 1] + fSlow133 * (fZec247[i] - fRec226[i - 1]) / fZec252[i];
				fZec254[i] = fSlow133 / fZec252[i];
				fZec255[i] = fSlow133 * (fZec254[i] + 2.0f) / fZec252[i] + 1.0f;
				fZec256[i] = fZec253[i] / fZec255[i];
				fRec225[i] = 2.0f * fZec256[i] - fRec225[i - 1];
				fZec257[i] = fRec226[i - 1] + fSlow133 * fZec253[i] / (fZec252[i] * fZec255[i]);
				fRec226[i] = 2.0f * fZec257[i] - fRec226[i - 1];
				fRec227[i] = fZec247[i];
				fRec228[i] = fZec256[i];
				fRec229[i] = fZec257[i];
				fZec258[i] = fZec251[i] + -1.0f;
				fZec259[i] = mydsp_faustpower2_f(fZec251[i]) + -1.0f;
				fZec260[i] = fRec227[i] + 2.0f * fRec228[i] * fZec258[i] + fRec229[i] * fZec259[i];
				fZec261[i] = fRec220[i - 1] + fSlow133 * (fZec260[i] - fRec221[i - 1]) / fZec252[i];
				fZec262[i] = fSlow133 * (fZec254[i] + 1.41442716f) / fZec252[i] + 1.0f;
				fZec263[i] = fZec261[i] / fZec262[i];
				fRec220[i] = 2.0f * fZec263[i] - fRec220[i - 1];
				fZec264[i] = fRec221[i - 1] + fSlow133 * fZec261[i] / (fZec252[i] * fZec262[i]);
				fRec221[i] = 2.0f * fZec264[i] - fRec221[i - 1];
				fRec222[i] = fZec260[i];
				fRec223[i] = fZec263[i];
				fRec224[i] = fZec264[i];
				fZec265[i] = fRec222[i] + 1.41442716f * fRec223[i] * fZec258[i] + fRec224[i] * fZec259[i];
				fZec266[i] = fRec215[i - 1] + fSlow133 * (fZec265[i] - fRec216[i - 1]) / fZec252[i];
				fZec267[i] = fSlow133 * (fZec254[i] + 0.5f) / fZec252[i] + 1.0f;
				fZec268[i] = fZec266[i] / fZec267[i];
				fRec215[i] = 2.0f * fZec268[i] - fRec215[i - 1];
				fZec269[i] = fRec216[i - 1] + fSlow133 * fZec266[i] / (fZec252[i] * fZec267[i]);
				fRec216[i] = 2.0f * fZec269[i] - fRec216[i - 1];
				fRec217[i] = fZec265[i];
				fRec218[i] = fZec268[i];
				fRec219[i] = fZec269[i];
				fZec270[i] = fRec217[i] + 0.5f * fRec218[i] * fZec258[i] + fRec219[i] * fZec259[i];
				fZec271[i] = std::pow(10.0f, 0.00833333377f * fZec250[i]);
				fZec272[i] = std::sqrt(fZec271[i]);
				fZec273[i] = fRec210[i - 1] + fSlow122 * (fZec270[i] - fRec211[i - 1]) / fZec272[i];
				fZec274[i] = fSlow122 / fZec272[i];
				fZec275[i] = fSlow122 * (fZec274[i] + 2.0f) / fZec272[i] + 1.0f;
				fZec276[i] = fZec273[i] / fZec275[i];
				fRec210[i] = 2.0f * fZec276[i] - fRec210[i - 1];
				fZec277[i] = fRec211[i - 1] + fSlow122 * fZec273[i] / (fZec272[i] * fZec275[i]);
				fRec211[i] = 2.0f * fZec277[i] - fRec211[i - 1];
				fRec212[i] = fZec270[i];
				fRec213[i] = fZec276[i];
				fRec214[i] = fZec277[i];
				fZec278[i] = fZec271[i] + -1.0f;
				fZec279[i] = mydsp_faustpower2_f(fZec271[i]) + -1.0f;
				fZec280[i] = fRec212[i] + 2.0f * fRec213[i] * fZec278[i] + fRec214[i] * fZec279[i];
				fZec281[i] = fRec205[i - 1] + fSlow122 * (fZec280[i] - fRec206[i - 1]) / fZec272[i];
				fZec282[i] = fSlow122 * (fZec274[i] + 1.41442716f) / fZec272[i] + 1.0f;
				fZec283[i] = fZec281[i] / fZec282[i];
				fRec205[i] = 2.0f * fZec283[i] - fRec205[i - 1];
				fZec284[i] = fRec206[i - 1] + fSlow122 * fZec281[i] / (fZec272[i] * fZec282[i]);
				fRec206[i] = 2.0f * fZec284[i] - fRec206[i - 1];
				fRec207[i] = fZec280[i];
				fRec208[i] = fZec283[i];
				fRec209[i] = fZec284[i];
				fZec285[i] = fRec207[i] + 1.41442716f * fRec208[i] * fZec278[i] + fRec209[i] * fZec279[i];
				fZec286[i] = fRec200[i - 1] + fSlow122 * (fZec285[i] - fRec201[i - 1]) / fZec272[i];
				fZec287[i] = fSlow122 * (fZec274[i] + 0.5f) / fZec272[i] + 1.0f;
				fZec288[i] = fZec286[i] / fZec287[i];
				fRec200[i] = 2.0f * fZec288[i] - fRec200[i - 1];
				fZec289[i] = fRec201[i - 1] + fSlow122 * fZec286[i] / (fZec272[i] * fZec287[i]);
				fRec201[i] = 2.0f * fZec289[i] - fRec201[i - 1];
				fRec202[i] = fZec285[i];
				fRec203[i] = fZec288[i];
				fRec204[i] = fZec289[i];
				fRec367[i] = fSlow124 * (fSlow127 * fRec317[i] + fSlow231 * fRec317[i - 1] + fSlow127 * fRec317[i - 2]) - fSlow129 * (fSlow130 * fRec367[i - 2] + fSlow128 * fRec367[i - 1]);
				fRec366[i] = fSlow129 * (fSlow127 * fRec367[i] + fSlow231 * fRec367[i - 1] + fSlow127 * fRec367[i - 2]) - fSlow131 * (fSlow132 * fRec366[i - 2] + fSlow128 * fRec366[i - 1]);
				fZec290[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow131 * (fSlow127 * fRec366[i] + fSlow231 * fRec366[i - 1] + fSlow127 * fRec366[i - 2]))));
				iZec291[i] = (fZec290[i] > fSlow237) + (fZec290[i] > fSlow238);
				fZec292[i] = fZec290[i] - fSlow234;
				float fThen160 = fZec292[i];
				float fElse160 = fSlow239 * mydsp_faustpower2_f(fSlow236 + fZec292[i]);
				float fThen161 = ((iZec291[i] == 1) ? fElse160 : fThen160);
				fZec293[i] = 0.0f - fSlow232 * std::max<float>(0.0f, ((iZec291[i] == 0) ? 0.0f : fThen161));
				fZec294[i] = ((fZec293[i] > fRec365[i - 1]) ? fSlow245 : fSlow242);
				fRec365[i] = fZec293[i] * (1.0f - fZec294[i]) + fRec365[i - 1] * fZec294[i];
				fRec370[i] = fSlow124 * (fSlow127 * fRec338[i] + fSlow231 * fRec338[i - 1] + fSlow127 * fRec338[i - 2]) - fSlow129 * (fSlow130 * fRec370[i - 2] + fSlow128 * fRec370[i - 1]);
				fRec369[i] = fSlow129 * (fSlow127 * fRec370[i] + fSlow231 * fRec370[i - 1] + fSlow127 * fRec370[i - 2]) - fSlow131 * (fSlow132 * fRec369[i - 2] + fSlow128 * fRec369[i - 1]);
				fZec295[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow131 * (fSlow127 * fRec369[i] + fSlow231 * fRec369[i - 1] + fSlow127 * fRec369[i - 2]))));
				iZec296[i] = (fZec295[i] > fSlow237) + (fZec295[i] > fSlow238);
				fZec297[i] = fZec295[i] - fSlow234;
				float fThen167 = fZec297[i];
				float fElse167 = fSlow239 * mydsp_faustpower2_f(fSlow236 + fZec297[i]);
				float fThen168 = ((iZec296[i] == 1) ? fElse167 : fThen167);
				fZec298[i] = 0.0f - fSlow232 * std::max<float>(0.0f, ((iZec296[i] == 0) ? 0.0f : fThen168));
				fZec299[i] = ((fZec298[i] > fRec368[i - 1]) ? fSlow245 : fSlow242);
				fRec368[i] = fZec298[i] * (1.0f - fZec299[i]) + fRec368[i - 1] * fZec299[i];
				fZec300[i] = fRec202[i] + 0.5f * fRec203[i] * fZec278[i] + fRec204[i] * fZec279[i];
				fZec301[i] = std::min<float>(fRec365[i], fRec368[i]);
				fZec302[i] = fRec365[i] + fSlow246 * (fZec301[i] - fRec365[i]);
				fVbargraph12 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec302[i])));
				fZec303[i] = fZec302[i];
				fZec304[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec303[i]));
				fZec305[i] = std::sqrt(fZec304[i]);
				fZec306[i] = fRec195[i - 1] + fSlow122 * (fZec300[i] - fRec196[i - 1]) / fZec305[i];
				fZec307[i] = fSlow122 / fZec305[i];
				fZec308[i] = fSlow122 * (fZec307[i] + 2.0f) / fZec305[i] + 1.0f;
				fZec309[i] = fZec306[i] / fZec308[i];
				fRec195[i] = 2.0f * fZec309[i] - fRec195[i - 1];
				fZec310[i] = fRec196[i - 1] + fSlow122 * fZec306[i] / (fZec305[i] * fZec308[i]);
				fRec196[i] = 2.0f * fZec310[i] - fRec196[i - 1];
				fRec197[i] = fZec300[i];
				fRec198[i] = fZec309[i];
				fRec199[i] = fZec310[i];
				fZec311[i] = fZec304[i] + -1.0f;
				fZec312[i] = mydsp_faustpower2_f(fZec304[i]) + -1.0f;
				fZec313[i] = fRec197[i] + 2.0f * fRec198[i] * fZec311[i] + fRec199[i] * fZec312[i];
				fZec314[i] = fRec190[i - 1] + fSlow122 * (fZec313[i] - fRec191[i - 1]) / fZec305[i];
				fZec315[i] = fSlow122 * (fZec307[i] + 1.41442716f) / fZec305[i] + 1.0f;
				fZec316[i] = fZec314[i] / fZec315[i];
				fRec190[i] = 2.0f * fZec316[i] - fRec190[i - 1];
				fZec317[i] = fRec191[i - 1] + fSlow122 * fZec314[i] / (fZec305[i] * fZec315[i]);
				fRec191[i] = 2.0f * fZec317[i] - fRec191[i - 1];
				fRec192[i] = fZec313[i];
				fRec193[i] = fZec316[i];
				fRec194[i] = fZec317[i];
				fZec318[i] = fRec192[i] + 1.41442716f * fRec193[i] * fZec311[i] + fRec194[i] * fZec312[i];
				fZec319[i] = fRec185[i - 1] + fSlow122 * (fZec318[i] - fRec186[i - 1]) / fZec305[i];
				fZec320[i] = fSlow122 * (fZec307[i] + 0.5f) / fZec305[i] + 1.0f;
				fZec321[i] = fZec319[i] / fZec320[i];
				fRec185[i] = 2.0f * fZec321[i] - fRec185[i - 1];
				fZec322[i] = fRec186[i - 1] + fSlow122 * fZec319[i] / (fZec305[i] * fZec320[i]);
				fRec186[i] = 2.0f * fZec322[i] - fRec186[i - 1];
				fRec187[i] = fZec318[i];
				fRec188[i] = fZec321[i];
				fRec189[i] = fZec322[i];
				fZec323[i] = fRec187[i] + 0.5f * fRec188[i] * fZec311[i] + fRec189[i] * fZec312[i];
				fZec324[i] = std::pow(10.0f, 0.00833333377f * fZec303[i]);
				fZec325[i] = std::sqrt(fZec324[i]);
				fZec326[i] = fRec180[i - 1] + fSlow111 * (fZec323[i] - fRec181[i - 1]) / fZec325[i];
				fZec327[i] = fSlow111 / fZec325[i];
				fZec328[i] = fSlow111 * (fZec327[i] + 2.0f) / fZec325[i] + 1.0f;
				fZec329[i] = fZec326[i] / fZec328[i];
				fRec180[i] = 2.0f * fZec329[i] - fRec180[i - 1];
				fZec330[i] = fRec181[i - 1] + fSlow111 * fZec326[i] / (fZec325[i] * fZec328[i]);
				fRec181[i] = 2.0f * fZec330[i] - fRec181[i - 1];
				fRec182[i] = fZec323[i];
				fRec183[i] = fZec329[i];
				fRec184[i] = fZec330[i];
				fZec331[i] = fZec324[i] + -1.0f;
				fZec332[i] = mydsp_faustpower2_f(fZec324[i]) + -1.0f;
				fZec333[i] = fRec182[i] + 2.0f * fRec183[i] * fZec331[i] + fRec184[i] * fZec332[i];
				fZec334[i] = fRec175[i - 1] + fSlow111 * (fZec333[i] - fRec176[i - 1]) / fZec325[i];
				fZec335[i] = fSlow111 * (fZec327[i] + 1.41442716f) / fZec325[i] + 1.0f;
				fZec336[i] = fZec334[i] / fZec335[i];
				fRec175[i] = 2.0f * fZec336[i] - fRec175[i - 1];
				fZec337[i] = fRec176[i - 1] + fSlow111 * fZec334[i] / (fZec325[i] * fZec335[i]);
				fRec176[i] = 2.0f * fZec337[i] - fRec176[i - 1];
				fRec177[i] = fZec333[i];
				fRec178[i] = fZec336[i];
				fRec179[i] = fZec337[i];
				fZec338[i] = fRec177[i] + 1.41442716f * fRec178[i] * fZec331[i] + fRec179[i] * fZec332[i];
				fZec339[i] = fRec170[i - 1] + fSlow111 * (fZec338[i] - fRec171[i - 1]) / fZec325[i];
				fZec340[i] = fSlow111 * (fZec327[i] + 0.5f) / fZec325[i] + 1.0f;
				fZec341[i] = fZec339[i] / fZec340[i];
				fRec170[i] = 2.0f * fZec341[i] - fRec170[i - 1];
				fZec342[i] = fRec171[i - 1] + fSlow111 * fZec339[i] / (fZec325[i] * fZec340[i]);
				fRec171[i] = 2.0f * fZec342[i] - fRec171[i - 1];
				fRec172[i] = fZec338[i];
				fRec173[i] = fZec341[i];
				fRec174[i] = fZec342[i];
				fRec373[i] = fSlow113 * (fSlow116 * fRec320[i] + fSlow247 * fRec320[i - 1] + fSlow116 * fRec320[i - 2]) - fSlow118 * (fSlow119 * fRec373[i - 2] + fSlow117 * fRec373[i - 1]);
				fRec372[i] = fSlow118 * (fSlow116 * fRec373[i] + fSlow247 * fRec373[i - 1] + fSlow116 * fRec373[i - 2]) - fSlow120 * (fSlow121 * fRec372[i - 2] + fSlow117 * fRec372[i - 1]);
				fZec343[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow120 * (fSlow116 * fRec372[i] + fSlow247 * fRec372[i - 1] + fSlow116 * fRec372[i - 2]))));
				iZec344[i] = (fZec343[i] > fSlow253) + (fZec343[i] > fSlow254);
				fZec345[i] = fZec343[i] - fSlow250;
				float fThen170 = fZec345[i];
				float fElse170 = fSlow255 * mydsp_faustpower2_f(fSlow252 + fZec345[i]);
				float fThen171 = ((iZec344[i] == 1) ? fElse170 : fThen170);
				fZec346[i] = 0.0f - fSlow248 * std::max<float>(0.0f, ((iZec344[i] == 0) ? 0.0f : fThen171));
				fZec347[i] = ((fZec346[i] > fRec371[i - 1]) ? fSlow261 : fSlow258);
				fRec371[i] = fZec346[i] * (1.0f - fZec347[i]) + fRec371[i - 1] * fZec347[i];
				fRec376[i] = fSlow113 * (fSlow116 * fRec341[i] + fSlow247 * fRec341[i - 1] + fSlow116 * fRec341[i - 2]) - fSlow118 * (fSlow119 * fRec376[i - 2] + fSlow117 * fRec376[i - 1]);
				fRec375[i] = fSlow118 * (fSlow116 * fRec376[i] + fSlow247 * fRec376[i - 1] + fSlow116 * fRec376[i - 2]) - fSlow120 * (fSlow121 * fRec375[i - 2] + fSlow117 * fRec375[i - 1]);
				fZec348[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow120 * (fSlow116 * fRec375[i] + fSlow247 * fRec375[i - 1] + fSlow116 * fRec375[i - 2]))));
				iZec349[i] = (fZec348[i] > fSlow253) + (fZec348[i] > fSlow254);
				fZec350[i] = fZec348[i] - fSlow250;
				float fThen177 = fZec350[i];
				float fElse177 = fSlow255 * mydsp_faustpower2_f(fSlow252 + fZec350[i]);
				float fThen178 = ((iZec349[i] == 1) ? fElse177 : fThen177);
				fZec351[i] = 0.0f - fSlow248 * std::max<float>(0.0f, ((iZec349[i] == 0) ? 0.0f : fThen178));
				fZec352[i] = ((fZec351[i] > fRec374[i - 1]) ? fSlow261 : fSlow258);
				fRec374[i] = fZec351[i] * (1.0f - fZec352[i]) + fRec374[i - 1] * fZec352[i];
				fZec353[i] = fRec172[i] + 0.5f * fRec173[i] * fZec331[i] + fRec174[i] * fZec332[i];
				fZec354[i] = std::min<float>(fRec371[i], fRec374[i]);
				fZec355[i] = fRec371[i] + fSlow262 * (fZec354[i] - fRec371[i]);
				fVbargraph13 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec355[i])));
				fZec356[i] = fZec355[i];
				fZec357[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec356[i]));
				fZec358[i] = std::sqrt(fZec357[i]);
				fZec359[i] = fRec165[i - 1] + fSlow111 * (fZec353[i] - fRec166[i - 1]) / fZec358[i];
				fZec360[i] = fSlow111 / fZec358[i];
				fZec361[i] = fSlow111 * (fZec360[i] + 2.0f) / fZec358[i] + 1.0f;
				fZec362[i] = fZec359[i] / fZec361[i];
				fRec165[i] = 2.0f * fZec362[i] - fRec165[i - 1];
				fZec363[i] = fRec166[i - 1] + fSlow111 * fZec359[i] / (fZec358[i] * fZec361[i]);
				fRec166[i] = 2.0f * fZec363[i] - fRec166[i - 1];
				fRec167[i] = fZec353[i];
				fRec168[i] = fZec362[i];
				fRec169[i] = fZec363[i];
				fZec364[i] = fZec357[i] + -1.0f;
				fZec365[i] = mydsp_faustpower2_f(fZec357[i]) + -1.0f;
				fZec366[i] = fRec167[i] + 2.0f * fRec168[i] * fZec364[i] + fRec169[i] * fZec365[i];
				fZec367[i] = fRec160[i - 1] + fSlow111 * (fZec366[i] - fRec161[i - 1]) / fZec358[i];
				fZec368[i] = fSlow111 * (fZec360[i] + 1.41442716f) / fZec358[i] + 1.0f;
				fZec369[i] = fZec367[i] / fZec368[i];
				fRec160[i] = 2.0f * fZec369[i] - fRec160[i - 1];
				fZec370[i] = fRec161[i - 1] + fSlow111 * fZec367[i] / (fZec358[i] * fZec368[i]);
				fRec161[i] = 2.0f * fZec370[i] - fRec161[i - 1];
				fRec162[i] = fZec366[i];
				fRec163[i] = fZec369[i];
				fRec164[i] = fZec370[i];
				fZec371[i] = fRec162[i] + 1.41442716f * fRec163[i] * fZec364[i] + fRec164[i] * fZec365[i];
				fZec372[i] = fRec155[i - 1] + fSlow111 * (fZec371[i] - fRec156[i - 1]) / fZec358[i];
				fZec373[i] = fSlow111 * (fZec360[i] + 0.5f) / fZec358[i] + 1.0f;
				fZec374[i] = fZec372[i] / fZec373[i];
				fRec155[i] = 2.0f * fZec374[i] - fRec155[i - 1];
				fZec375[i] = fRec156[i - 1] + fSlow111 * fZec372[i] / (fZec358[i] * fZec373[i]);
				fRec156[i] = 2.0f * fZec375[i] - fRec156[i - 1];
				fRec157[i] = fZec371[i];
				fRec158[i] = fZec374[i];
				fRec159[i] = fZec375[i];
				fZec376[i] = fRec157[i] + 0.5f * fRec158[i] * fZec364[i] + fRec159[i] * fZec365[i];
				fZec377[i] = std::pow(10.0f, 0.00833333377f * fZec356[i]);
				fZec378[i] = std::sqrt(fZec377[i]);
				fZec379[i] = fRec150[i - 1] + fSlow100 * (fZec376[i] - fRec151[i - 1]) / fZec378[i];
				fZec380[i] = fSlow100 / fZec378[i];
				fZec381[i] = fSlow100 * (fZec380[i] + 2.0f) / fZec378[i] + 1.0f;
				fZec382[i] = fZec379[i] / fZec381[i];
				fRec150[i] = 2.0f * fZec382[i] - fRec150[i - 1];
				fZec383[i] = fRec151[i - 1] + fSlow100 * fZec379[i] / (fZec378[i] * fZec381[i]);
				fRec151[i] = 2.0f * fZec383[i] - fRec151[i - 1];
				fRec152[i] = fZec376[i];
				fRec153[i] = fZec382[i];
				fRec154[i] = fZec383[i];
				fZec384[i] = fZec377[i] + -1.0f;
				fZec385[i] = mydsp_faustpower2_f(fZec377[i]) + -1.0f;
				fZec386[i] = fRec152[i] + 2.0f * fRec153[i] * fZec384[i] + fRec154[i] * fZec385[i];
				fZec387[i] = fRec145[i - 1] + fSlow100 * (fZec386[i] - fRec146[i - 1]) / fZec378[i];
				fZec388[i] = fSlow100 * (fZec380[i] + 1.41442716f) / fZec378[i] + 1.0f;
				fZec389[i] = fZec387[i] / fZec388[i];
				fRec145[i] = 2.0f * fZec389[i] - fRec145[i - 1];
				fZec390[i] = fRec146[i - 1] + fSlow100 * fZec387[i] / (fZec378[i] * fZec388[i]);
				fRec146[i] = 2.0f * fZec390[i] - fRec146[i - 1];
				fRec147[i] = fZec386[i];
				fRec148[i] = fZec389[i];
				fRec149[i] = fZec390[i];
				fZec391[i] = fRec147[i] + 1.41442716f * fRec148[i] * fZec384[i] + fRec149[i] * fZec385[i];
				fZec392[i] = fRec140[i - 1] + fSlow100 * (fZec391[i] - fRec141[i - 1]) / fZec378[i];
				fZec393[i] = fSlow100 * (fZec380[i] + 0.5f) / fZec378[i] + 1.0f;
				fZec394[i] = fZec392[i] / fZec393[i];
				fRec140[i] = 2.0f * fZec394[i] - fRec140[i - 1];
				fZec395[i] = fRec141[i - 1] + fSlow100 * fZec392[i] / (fZec378[i] * fZec393[i]);
				fRec141[i] = 2.0f * fZec395[i] - fRec141[i - 1];
				fRec142[i] = fZec391[i];
				fRec143[i] = fZec394[i];
				fRec144[i] = fZec395[i];
				fRec379[i] = fSlow102 * (fSlow105 * fRec323[i] + fSlow263 * fRec323[i - 1] + fSlow105 * fRec323[i - 2]) - fSlow107 * (fSlow108 * fRec379[i - 2] + fSlow106 * fRec379[i - 1]);
				fRec378[i] = fSlow107 * (fSlow105 * fRec379[i] + fSlow263 * fRec379[i - 1] + fSlow105 * fRec379[i - 2]) - fSlow109 * (fSlow110 * fRec378[i - 2] + fSlow106 * fRec378[i - 1]);
				fZec396[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow109 * (fSlow105 * fRec378[i] + fSlow263 * fRec378[i - 1] + fSlow105 * fRec378[i - 2]))));
				iZec397[i] = (fZec396[i] > fSlow269) + (fZec396[i] > fSlow270);
				fZec398[i] = fZec396[i] - fSlow266;
				float fThen180 = fZec398[i];
				float fElse180 = fSlow271 * mydsp_faustpower2_f(fSlow268 + fZec398[i]);
				float fThen181 = ((iZec397[i] == 1) ? fElse180 : fThen180);
				fZec399[i] = 0.0f - fSlow264 * std::max<float>(0.0f, ((iZec397[i] == 0) ? 0.0f : fThen181));
				fZec400[i] = ((fZec399[i] > fRec377[i - 1]) ? fSlow277 : fSlow274);
				fRec377[i] = fZec399[i] * (1.0f - fZec400[i]) + fRec377[i - 1] * fZec400[i];
				fRec382[i] = fSlow102 * (fSlow105 * fRec344[i] + fSlow263 * fRec344[i - 1] + fSlow105 * fRec344[i - 2]) - fSlow107 * (fSlow108 * fRec382[i - 2] + fSlow106 * fRec382[i - 1]);
				fRec381[i] = fSlow107 * (fSlow105 * fRec382[i] + fSlow263 * fRec382[i - 1] + fSlow105 * fRec382[i - 2]) - fSlow109 * (fSlow110 * fRec381[i - 2] + fSlow106 * fRec381[i - 1]);
				fZec401[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::fabs(fSlow109 * (fSlow105 * fRec381[i] + fSlow263 * fRec381[i - 1] + fSlow105 * fRec381[i - 2]))));
				iZec402[i] = (fZec401[i] > fSlow269) + (fZec401[i] > fSlow270);
				fZec403[i] = fZec401[i] - fSlow266;
				float fThen187 = fZec403[i];
				float fElse187 = fSlow271 * mydsp_faustpower2_f(fSlow268 + fZec403[i]);
				float fThen188 = ((iZec402[i] == 1) ? fElse187 : fThen187);
				fZec404[i] = 0.0f - fSlow264 * std::max<float>(0.0f, ((iZec402[i] == 0) ? 0.0f : fThen188));
				fZec405[i] = ((fZec404[i] > fRec380[i - 1]) ? fSlow277 : fSlow274);
				fRec380[i] = fZec404[i] * (1.0f - fZec405[i]) + fRec380[i - 1] * fZec405[i];
				fZec406[i] = fRec142[i] + 0.5f * fRec143[i] * fZec384[i] + fRec144[i] * fZec385[i];
				fZec407[i] = std::min<float>(fRec377[i], fRec380[i]);
				fZec408[i] = fRec377[i] + fSlow278 * (fZec407[i] - fRec377[i]);
				fVbargraph14 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec408[i])));
				fZec409[i] = fZec408[i];
				fZec410[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec409[i]));
				fZec411[i] = std::sqrt(fZec410[i]);
				fZec412[i] = fRec135[i - 1] + fSlow100 * (fZec406[i] - fRec136[i - 1]) / fZec411[i];
				fZec413[i] = fSlow100 / fZec411[i];
				fZec414[i] = fSlow100 * (fZec413[i] + 2.0f) / fZec411[i] + 1.0f;
				fZec415[i] = fZec412[i] / fZec414[i];
				fRec135[i] = 2.0f * fZec415[i] - fRec135[i - 1];
				fZec416[i] = fRec136[i - 1] + fSlow100 * fZec412[i] / (fZec411[i] * fZec414[i]);
				fRec136[i] = 2.0f * fZec416[i] - fRec136[i - 1];
				fRec137[i] = fZec406[i];
				fRec138[i] = fZec415[i];
				fRec139[i] = fZec416[i];
				fZec417[i] = fZec410[i] + -1.0f;
				fZec418[i] = mydsp_faustpower2_f(fZec410[i]) + -1.0f;
				fZec419[i] = fRec137[i] + 2.0f * fRec138[i] * fZec417[i] + fRec139[i] * fZec418[i];
				fZec420[i] = fRec130[i - 1] + fSlow100 * (fZec419[i] - fRec131[i - 1]) / fZec411[i];
				fZec421[i] = fSlow100 * (fZec413[i] + 1.41442716f) / fZec411[i] + 1.0f;
				fZec422[i] = fZec420[i] / fZec421[i];
				fRec130[i] = 2.0f * fZec422[i] - fRec130[i - 1];
				fZec423[i] = fRec131[i - 1] + fSlow100 * fZec420[i] / (fZec411[i] * fZec421[i]);
				fRec131[i] = 2.0f * fZec423[i] - fRec131[i - 1];
				fRec132[i] = fZec419[i];
				fRec133[i] = fZec422[i];
				fRec134[i] = fZec423[i];
				fZec424[i] = fRec132[i] + 1.41442716f * fRec133[i] * fZec417[i] + fRec134[i] * fZec418[i];
				fZec425[i] = fRec125[i - 1] + fSlow100 * (fZec424[i] - fRec126[i - 1]) / fZec411[i];
				fZec426[i] = fSlow100 * (fZec413[i] + 0.5f) / fZec411[i] + 1.0f;
				fZec427[i] = fZec425[i] / fZec426[i];
				fRec125[i] = 2.0f * fZec427[i] - fRec125[i - 1];
				fZec428[i] = fRec126[i - 1] + fSlow100 * fZec425[i] / (fZec411[i] * fZec426[i]);
				fRec126[i] = 2.0f * fZec428[i] - fRec126[i - 1];
				fRec127[i] = fZec424[i];
				fRec128[i] = fZec427[i];
				fRec129[i] = fZec428[i];
				fZec429[i] = fRec127[i] + 0.5f * fRec128[i] * fZec417[i] + fRec129[i] * fZec418[i];
				fZec430[i] = std::pow(10.0f, 0.00833333377f * fZec409[i]);
				fZec431[i] = std::sqrt(fZec430[i]);
				fZec432[i] = fRec120[i - 1] + fSlow68 * (fZec429[i] - fRec121[i - 1]) / fZec431[i];
				fZec433[i] = fSlow68 / fZec431[i];
				fZec434[i] = fSlow68 * (fZec433[i] + 2.0f) / fZec431[i] + 1.0f;
				fZec435[i] = fZec432[i] / fZec434[i];
				fRec120[i] = 2.0f * fZec435[i] - fRec120[i - 1];
				fZec436[i] = fRec121[i - 1] + fSlow68 * fZec432[i] / (fZec431[i] * fZec434[i]);
				fRec121[i] = 2.0f * fZec436[i] - fRec121[i - 1];
				fRec122[i] = fZec429[i];
				fRec123[i] = fZec435[i];
				fRec124[i] = fZec436[i];
				fZec437[i] = fZec430[i] + -1.0f;
				fZec438[i] = mydsp_faustpower2_f(fZec430[i]) + -1.0f;
				fZec439[i] = fRec122[i] + 2.0f * fRec123[i] * fZec437[i] + fRec124[i] * fZec438[i];
				fZec440[i] = fRec115[i - 1] + fSlow68 * (fZec439[i] - fRec116[i - 1]) / fZec431[i];
				fZec441[i] = fSlow68 * (fZec433[i] + 1.41442716f) / fZec431[i] + 1.0f;
				fZec442[i] = fZec440[i] / fZec441[i];
				fRec115[i] = 2.0f * fZec442[i] - fRec115[i - 1];
				fZec443[i] = fRec116[i - 1] + fSlow68 * fZec440[i] / (fZec431[i] * fZec441[i]);
				fRec116[i] = 2.0f * fZec443[i] - fRec116[i - 1];
				fRec117[i] = fZec439[i];
				fRec118[i] = fZec442[i];
				fRec119[i] = fZec443[i];
				fZec444[i] = fRec117[i] + 1.41442716f * fRec118[i] * fZec437[i] + fRec119[i] * fZec438[i];
				fZec445[i] = fRec110[i - 1] + fSlow68 * (fZec444[i] - fRec111[i - 1]) / fZec431[i];
				fZec446[i] = fSlow68 * (fZec433[i] + 0.5f) / fZec431[i] + 1.0f;
				fZec447[i] = fZec445[i] / fZec446[i];
				fRec110[i] = 2.0f * fZec447[i] - fRec110[i - 1];
				fZec448[i] = fRec111[i - 1] + fSlow68 * fZec445[i] / (fZec431[i] * fZec446[i]);
				fRec111[i] = 2.0f * fZec448[i] - fRec111[i - 1];
				fRec112[i] = fZec444[i];
				fRec113[i] = fZec447[i];
				fRec114[i] = fZec448[i];
				fZec449[i] = std::min<float>(fRec87[i], fRec91[i]);
				fZec450[i] = fRec87[i] + fSlow279 * (fZec449[i] - fRec87[i]);
				fVbargraph15 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec450[i])));
				fZec451[i] = std::pow(10.0f, 0.00833333377f * fZec450[i]);
				fZec452[i] = std::sqrt(fZec451[i]);
				fZec453[i] = fRec112[i] + 0.5f * fRec113[i] * fZec437[i] + fRec114[i] * fZec438[i];
				fZec454[i] = fRec105[i - 1] + fSlow68 * fZec452[i] * (fZec453[i] - fRec106[i - 1]);
				fZec455[i] = fSlow68 * fZec452[i];
				fZec456[i] = fSlow68 * fZec452[i] * (fZec455[i] + 2.0f) + 1.0f;
				fZec457[i] = fZec454[i] / fZec456[i];
				fRec105[i] = 2.0f * fZec457[i] - fRec105[i - 1];
				fZec458[i] = fRec106[i - 1] + fSlow68 * (fZec452[i] * fZec454[i]) / fZec456[i];
				fRec106[i] = 2.0f * fZec458[i] - fRec106[i - 1];
				fRec107[i] = fZec453[i];
				fRec108[i] = fZec457[i];
				fRec109[i] = fZec458[i];
				fZec459[i] = 1.0f - fZec451[i];
				fZec460[i] = 1.0f - mydsp_faustpower2_f(fZec451[i]);
				fZec461[i] = fZec451[i] * (fRec107[i] * fZec451[i] + 2.0f * fRec108[i] * fZec459[i]) + fRec109[i] * fZec460[i];
				fZec462[i] = fRec100[i - 1] + fSlow68 * fZec452[i] * (fZec461[i] - fRec101[i - 1]);
				fZec463[i] = fSlow68 * fZec452[i] * (fZec455[i] + 1.41442716f) + 1.0f;
				fZec464[i] = fZec462[i] / fZec463[i];
				fRec100[i] = 2.0f * fZec464[i] - fRec100[i - 1];
				fZec465[i] = fRec101[i - 1] + fSlow68 * (fZec452[i] * fZec462[i]) / fZec463[i];
				fRec101[i] = 2.0f * fZec465[i] - fRec101[i - 1];
				fRec102[i] = fZec461[i];
				fRec103[i] = fZec464[i];
				fRec104[i] = fZec465[i];
				fZec466[i] = fZec451[i] * (fRec102[i] * fZec451[i] + 1.41442716f * fRec103[i] * fZec459[i]) + fRec104[i] * fZec460[i];
				fZec467[i] = fRec95[i - 1] + fSlow68 * fZec452[i] * (fZec466[i] - fRec96[i - 1]);
				fZec468[i] = fSlow68 * fZec452[i] * (fZec455[i] + 0.5f) + 1.0f;
				fZec469[i] = fZec467[i] / fZec468[i];
				fRec95[i] = 2.0f * fZec469[i] - fRec95[i - 1];
				fZec470[i] = fRec96[i - 1] + fSlow68 * (fZec452[i] * fZec467[i]) / fZec468[i];
				fRec96[i] = 2.0f * fZec470[i] - fRec96[i - 1];
				fRec97[i] = fZec466[i];
				fRec98[i] = fZec469[i];
				fRec99[i] = fZec470[i];
				fZec471[i] = fRec326[i] + fSlow179 * (fZec110[i] - fRec326[i]);
				fVbargraph16 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec471[i])));
				fZec472[i] = std::pow(10.0f, 0.00833333377f * fZec471[i]);
				fZec473[i] = std::sqrt(fZec472[i]);
				fZec474[i] = fRec588[i - 1] + fSlow155 * (fZec94[i] - fRec589[i - 1]) / fZec473[i];
				fZec475[i] = fSlow155 / fZec473[i];
				fZec476[i] = fSlow155 * (fZec475[i] + 2.0f) / fZec473[i] + 1.0f;
				fZec477[i] = fZec474[i] / fZec476[i];
				fRec588[i] = 2.0f * fZec477[i] - fRec588[i - 1];
				fZec478[i] = fRec589[i - 1] + fSlow155 * fZec474[i] / (fZec473[i] * fZec476[i]);
				fRec589[i] = 2.0f * fZec478[i] - fRec589[i - 1];
				fRec590[i] = fZec94[i];
				fRec591[i] = fZec477[i];
				fRec592[i] = fZec478[i];
				fZec479[i] = fZec472[i] + -1.0f;
				fZec480[i] = mydsp_faustpower2_f(fZec472[i]) + -1.0f;
				fZec481[i] = fRec590[i] + 2.0f * fRec591[i] * fZec479[i] + fRec592[i] * fZec480[i];
				fZec482[i] = fRec583[i - 1] + fSlow155 * (fZec481[i] - fRec584[i - 1]) / fZec473[i];
				fZec483[i] = fSlow155 * (fZec475[i] + 1.41442716f) / fZec473[i] + 1.0f;
				fZec484[i] = fZec482[i] / fZec483[i];
				fRec583[i] = 2.0f * fZec484[i] - fRec583[i - 1];
				fZec485[i] = fRec584[i - 1] + fSlow155 * fZec482[i] / (fZec473[i] * fZec483[i]);
				fRec584[i] = 2.0f * fZec485[i] - fRec584[i - 1];
				fRec585[i] = fZec481[i];
				fRec586[i] = fZec484[i];
				fRec587[i] = fZec485[i];
				fZec486[i] = fRec585[i] + 1.41442716f * fRec586[i] * fZec479[i] + fRec587[i] * fZec480[i];
				fZec487[i] = fRec578[i - 1] + fSlow155 * (fZec486[i] - fRec579[i - 1]) / fZec473[i];
				fZec488[i] = fSlow155 * (fZec475[i] + 0.5f) / fZec473[i] + 1.0f;
				fZec489[i] = fZec487[i] / fZec488[i];
				fRec578[i] = 2.0f * fZec489[i] - fRec578[i - 1];
				fZec490[i] = fRec579[i - 1] + fSlow155 * fZec487[i] / (fZec473[i] * fZec488[i]);
				fRec579[i] = 2.0f * fZec490[i] - fRec579[i - 1];
				fRec580[i] = fZec486[i];
				fRec581[i] = fZec489[i];
				fRec582[i] = fZec490[i];
				fZec491[i] = fRec580[i] + 0.5f * fRec581[i] * fZec479[i] + fRec582[i] * fZec480[i];
				fZec492[i] = fRec350[i] + fSlow198 * (fZec142[i] - fRec350[i]);
				fVbargraph17 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec492[i])));
				fZec493[i] = fZec492[i];
				fZec494[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec493[i]));
				fZec495[i] = std::sqrt(fZec494[i]);
				fZec496[i] = fRec573[i - 1] + fSlow155 * (fZec491[i] - fRec574[i - 1]) / fZec495[i];
				fZec497[i] = fSlow155 / fZec495[i];
				fZec498[i] = fSlow155 * (fZec497[i] + 2.0f) / fZec495[i] + 1.0f;
				fZec499[i] = fZec496[i] / fZec498[i];
				fRec573[i] = 2.0f * fZec499[i] - fRec573[i - 1];
				fZec500[i] = fRec574[i - 1] + fSlow155 * fZec496[i] / (fZec495[i] * fZec498[i]);
				fRec574[i] = 2.0f * fZec500[i] - fRec574[i - 1];
				fRec575[i] = fZec491[i];
				fRec576[i] = fZec499[i];
				fRec577[i] = fZec500[i];
				fZec501[i] = fZec494[i] + -1.0f;
				fZec502[i] = mydsp_faustpower2_f(fZec494[i]) + -1.0f;
				fZec503[i] = fRec575[i] + 2.0f * fRec576[i] * fZec501[i] + fRec577[i] * fZec502[i];
				fZec504[i] = fRec568[i - 1] + fSlow155 * (fZec503[i] - fRec569[i - 1]) / fZec495[i];
				fZec505[i] = fSlow155 * (fZec497[i] + 1.41442716f) / fZec495[i] + 1.0f;
				fZec506[i] = fZec504[i] / fZec505[i];
				fRec568[i] = 2.0f * fZec506[i] - fRec568[i - 1];
				fZec507[i] = fRec569[i - 1] + fSlow155 * fZec504[i] / (fZec495[i] * fZec505[i]);
				fRec569[i] = 2.0f * fZec507[i] - fRec569[i - 1];
				fRec570[i] = fZec503[i];
				fRec571[i] = fZec506[i];
				fRec572[i] = fZec507[i];
				fZec508[i] = fRec570[i] + 1.41442716f * fRec571[i] * fZec501[i] + fRec572[i] * fZec502[i];
				fZec509[i] = fRec563[i - 1] + fSlow155 * (fZec508[i] - fRec564[i - 1]) / fZec495[i];
				fZec510[i] = fSlow155 * (fZec497[i] + 0.5f) / fZec495[i] + 1.0f;
				fZec511[i] = fZec509[i] / fZec510[i];
				fRec563[i] = 2.0f * fZec511[i] - fRec563[i - 1];
				fZec512[i] = fRec564[i - 1] + fSlow155 * fZec509[i] / (fZec495[i] * fZec510[i]);
				fRec564[i] = 2.0f * fZec512[i] - fRec564[i - 1];
				fRec565[i] = fZec508[i];
				fRec566[i] = fZec511[i];
				fRec567[i] = fZec512[i];
				fZec513[i] = fRec565[i] + 0.5f * fRec566[i] * fZec501[i] + fRec567[i] * fZec502[i];
				fZec514[i] = std::pow(10.0f, 0.00833333377f * fZec493[i]);
				fZec515[i] = std::sqrt(fZec514[i]);
				fZec516[i] = fRec558[i - 1] + fSlow144 * (fZec513[i] - fRec559[i - 1]) / fZec515[i];
				fZec517[i] = fSlow144 / fZec515[i];
				fZec518[i] = fSlow144 * (fZec517[i] + 2.0f) / fZec515[i] + 1.0f;
				fZec519[i] = fZec516[i] / fZec518[i];
				fRec558[i] = 2.0f * fZec519[i] - fRec558[i - 1];
				fZec520[i] = fRec559[i - 1] + fSlow144 * fZec516[i] / (fZec515[i] * fZec518[i]);
				fRec559[i] = 2.0f * fZec520[i] - fRec559[i - 1];
				fRec560[i] = fZec513[i];
				fRec561[i] = fZec519[i];
				fRec562[i] = fZec520[i];
				fZec521[i] = fZec514[i] + -1.0f;
				fZec522[i] = mydsp_faustpower2_f(fZec514[i]) + -1.0f;
				fZec523[i] = fRec560[i] + 2.0f * fRec561[i] * fZec521[i] + fRec562[i] * fZec522[i];
				fZec524[i] = fRec553[i - 1] + fSlow144 * (fZec523[i] - fRec554[i - 1]) / fZec515[i];
				fZec525[i] = fSlow144 * (fZec517[i] + 1.41442716f) / fZec515[i] + 1.0f;
				fZec526[i] = fZec524[i] / fZec525[i];
				fRec553[i] = 2.0f * fZec526[i] - fRec553[i - 1];
				fZec527[i] = fRec554[i - 1] + fSlow144 * fZec524[i] / (fZec515[i] * fZec525[i]);
				fRec554[i] = 2.0f * fZec527[i] - fRec554[i - 1];
				fRec555[i] = fZec523[i];
				fRec556[i] = fZec526[i];
				fRec557[i] = fZec527[i];
				fZec528[i] = fRec555[i] + 1.41442716f * fRec556[i] * fZec521[i] + fRec557[i] * fZec522[i];
				fZec529[i] = fRec548[i - 1] + fSlow144 * (fZec528[i] - fRec549[i - 1]) / fZec515[i];
				fZec530[i] = fSlow144 * (fZec517[i] + 0.5f) / fZec515[i] + 1.0f;
				fZec531[i] = fZec529[i] / fZec530[i];
				fRec548[i] = 2.0f * fZec531[i] - fRec548[i - 1];
				fZec532[i] = fRec549[i - 1] + fSlow144 * fZec529[i] / (fZec515[i] * fZec530[i]);
				fRec549[i] = 2.0f * fZec532[i] - fRec549[i - 1];
				fRec550[i] = fZec528[i];
				fRec551[i] = fZec531[i];
				fRec552[i] = fZec532[i];
				fZec533[i] = fRec550[i] + 0.5f * fRec551[i] * fZec521[i] + fRec552[i] * fZec522[i];
				fZec534[i] = fRec356[i] + fSlow214 * (fZec195[i] - fRec356[i]);
				fVbargraph18 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec534[i])));
				fZec535[i] = fZec534[i];
				fZec536[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec535[i]));
				fZec537[i] = std::sqrt(fZec536[i]);
				fZec538[i] = fRec543[i - 1] + fSlow144 * (fZec533[i] - fRec544[i - 1]) / fZec537[i];
				fZec539[i] = fSlow144 / fZec537[i];
				fZec540[i] = fSlow144 * (fZec539[i] + 2.0f) / fZec537[i] + 1.0f;
				fZec541[i] = fZec538[i] / fZec540[i];
				fRec543[i] = 2.0f * fZec541[i] - fRec543[i - 1];
				fZec542[i] = fRec544[i - 1] + fSlow144 * fZec538[i] / (fZec537[i] * fZec540[i]);
				fRec544[i] = 2.0f * fZec542[i] - fRec544[i - 1];
				fRec545[i] = fZec533[i];
				fRec546[i] = fZec541[i];
				fRec547[i] = fZec542[i];
				fZec543[i] = fZec536[i] + -1.0f;
				fZec544[i] = mydsp_faustpower2_f(fZec536[i]) + -1.0f;
				fZec545[i] = fRec545[i] + 2.0f * fRec546[i] * fZec543[i] + fRec547[i] * fZec544[i];
				fZec546[i] = fRec538[i - 1] + fSlow144 * (fZec545[i] - fRec539[i - 1]) / fZec537[i];
				fZec547[i] = fSlow144 * (fZec539[i] + 1.41442716f) / fZec537[i] + 1.0f;
				fZec548[i] = fZec546[i] / fZec547[i];
				fRec538[i] = 2.0f * fZec548[i] - fRec538[i - 1];
				fZec549[i] = fRec539[i - 1] + fSlow144 * fZec546[i] / (fZec537[i] * fZec547[i]);
				fRec539[i] = 2.0f * fZec549[i] - fRec539[i - 1];
				fRec540[i] = fZec545[i];
				fRec541[i] = fZec548[i];
				fRec542[i] = fZec549[i];
				fZec550[i] = fRec540[i] + 1.41442716f * fRec541[i] * fZec543[i] + fRec542[i] * fZec544[i];
				fZec551[i] = fRec533[i - 1] + fSlow144 * (fZec550[i] - fRec534[i - 1]) / fZec537[i];
				fZec552[i] = fSlow144 * (fZec539[i] + 0.5f) / fZec537[i] + 1.0f;
				fZec553[i] = fZec551[i] / fZec552[i];
				fRec533[i] = 2.0f * fZec553[i] - fRec533[i - 1];
				fZec554[i] = fRec534[i - 1] + fSlow144 * fZec551[i] / (fZec537[i] * fZec552[i]);
				fRec534[i] = 2.0f * fZec554[i] - fRec534[i - 1];
				fRec535[i] = fZec550[i];
				fRec536[i] = fZec553[i];
				fRec537[i] = fZec554[i];
				fZec555[i] = fRec535[i] + 0.5f * fRec536[i] * fZec543[i] + fRec537[i] * fZec544[i];
				fZec556[i] = std::pow(10.0f, 0.00833333377f * fZec535[i]);
				fZec557[i] = std::sqrt(fZec556[i]);
				fZec558[i] = fRec528[i - 1] + fSlow133 * (fZec555[i] - fRec529[i - 1]) / fZec557[i];
				fZec559[i] = fSlow133 / fZec557[i];
				fZec560[i] = fSlow133 * (fZec559[i] + 2.0f) / fZec557[i] + 1.0f;
				fZec561[i] = fZec558[i] / fZec560[i];
				fRec528[i] = 2.0f * fZec561[i] - fRec528[i - 1];
				fZec562[i] = fRec529[i - 1] + fSlow133 * fZec558[i] / (fZec557[i] * fZec560[i]);
				fRec529[i] = 2.0f * fZec562[i] - fRec529[i - 1];
				fRec530[i] = fZec555[i];
				fRec531[i] = fZec561[i];
				fRec532[i] = fZec562[i];
				fZec563[i] = fZec556[i] + -1.0f;
				fZec564[i] = mydsp_faustpower2_f(fZec556[i]) + -1.0f;
				fZec565[i] = fRec530[i] + 2.0f * fRec531[i] * fZec563[i] + fRec532[i] * fZec564[i];
				fZec566[i] = fRec523[i - 1] + fSlow133 * (fZec565[i] - fRec524[i - 1]) / fZec557[i];
				fZec567[i] = fSlow133 * (fZec559[i] + 1.41442716f) / fZec557[i] + 1.0f;
				fZec568[i] = fZec566[i] / fZec567[i];
				fRec523[i] = 2.0f * fZec568[i] - fRec523[i - 1];
				fZec569[i] = fRec524[i - 1] + fSlow133 * fZec566[i] / (fZec557[i] * fZec567[i]);
				fRec524[i] = 2.0f * fZec569[i] - fRec524[i - 1];
				fRec525[i] = fZec565[i];
				fRec526[i] = fZec568[i];
				fRec527[i] = fZec569[i];
				fZec570[i] = fRec525[i] + 1.41442716f * fRec526[i] * fZec563[i] + fRec527[i] * fZec564[i];
				fZec571[i] = fRec518[i - 1] + fSlow133 * (fZec570[i] - fRec519[i - 1]) / fZec557[i];
				fZec572[i] = fSlow133 * (fZec559[i] + 0.5f) / fZec557[i] + 1.0f;
				fZec573[i] = fZec571[i] / fZec572[i];
				fRec518[i] = 2.0f * fZec573[i] - fRec518[i - 1];
				fZec574[i] = fRec519[i - 1] + fSlow133 * fZec571[i] / (fZec557[i] * fZec572[i]);
				fRec519[i] = 2.0f * fZec574[i] - fRec519[i - 1];
				fRec520[i] = fZec570[i];
				fRec521[i] = fZec573[i];
				fRec522[i] = fZec574[i];
				fZec575[i] = fRec520[i] + 0.5f * fRec521[i] * fZec563[i] + fRec522[i] * fZec564[i];
				fZec576[i] = fRec362[i] + fSlow230 * (fZec248[i] - fRec362[i]);
				fVbargraph19 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec576[i])));
				fZec577[i] = fZec576[i];
				fZec578[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec577[i]));
				fZec579[i] = std::sqrt(fZec578[i]);
				fZec580[i] = fRec513[i - 1] + fSlow133 * (fZec575[i] - fRec514[i - 1]) / fZec579[i];
				fZec581[i] = fSlow133 / fZec579[i];
				fZec582[i] = fSlow133 * (fZec581[i] + 2.0f) / fZec579[i] + 1.0f;
				fZec583[i] = fZec580[i] / fZec582[i];
				fRec513[i] = 2.0f * fZec583[i] - fRec513[i - 1];
				fZec584[i] = fRec514[i - 1] + fSlow133 * fZec580[i] / (fZec579[i] * fZec582[i]);
				fRec514[i] = 2.0f * fZec584[i] - fRec514[i - 1];
				fRec515[i] = fZec575[i];
				fRec516[i] = fZec583[i];
				fRec517[i] = fZec584[i];
				fZec585[i] = fZec578[i] + -1.0f;
				fZec586[i] = mydsp_faustpower2_f(fZec578[i]) + -1.0f;
				fZec587[i] = fRec515[i] + 2.0f * fRec516[i] * fZec585[i] + fRec517[i] * fZec586[i];
				fZec588[i] = fRec508[i - 1] + fSlow133 * (fZec587[i] - fRec509[i - 1]) / fZec579[i];
				fZec589[i] = fSlow133 * (fZec581[i] + 1.41442716f) / fZec579[i] + 1.0f;
				fZec590[i] = fZec588[i] / fZec589[i];
				fRec508[i] = 2.0f * fZec590[i] - fRec508[i - 1];
				fZec591[i] = fRec509[i - 1] + fSlow133 * fZec588[i] / (fZec579[i] * fZec589[i]);
				fRec509[i] = 2.0f * fZec591[i] - fRec509[i - 1];
				fRec510[i] = fZec587[i];
				fRec511[i] = fZec590[i];
				fRec512[i] = fZec591[i];
				fZec592[i] = fRec510[i] + 1.41442716f * fRec511[i] * fZec585[i] + fRec512[i] * fZec586[i];
				fZec593[i] = fRec503[i - 1] + fSlow133 * (fZec592[i] - fRec504[i - 1]) / fZec579[i];
				fZec594[i] = fSlow133 * (fZec581[i] + 0.5f) / fZec579[i] + 1.0f;
				fZec595[i] = fZec593[i] / fZec594[i];
				fRec503[i] = 2.0f * fZec595[i] - fRec503[i - 1];
				fZec596[i] = fRec504[i - 1] + fSlow133 * fZec593[i] / (fZec579[i] * fZec594[i]);
				fRec504[i] = 2.0f * fZec596[i] - fRec504[i - 1];
				fRec505[i] = fZec592[i];
				fRec506[i] = fZec595[i];
				fRec507[i] = fZec596[i];
				fZec597[i] = fRec505[i] + 0.5f * fRec506[i] * fZec585[i] + fRec507[i] * fZec586[i];
				fZec598[i] = std::pow(10.0f, 0.00833333377f * fZec577[i]);
				fZec599[i] = std::sqrt(fZec598[i]);
				fZec600[i] = fRec498[i - 1] + fSlow122 * (fZec597[i] - fRec499[i - 1]) / fZec599[i];
				fZec601[i] = fSlow122 / fZec599[i];
				fZec602[i] = fSlow122 * (fZec601[i] + 2.0f) / fZec599[i] + 1.0f;
				fZec603[i] = fZec600[i] / fZec602[i];
				fRec498[i] = 2.0f * fZec603[i] - fRec498[i - 1];
				fZec604[i] = fRec499[i - 1] + fSlow122 * fZec600[i] / (fZec599[i] * fZec602[i]);
				fRec499[i] = 2.0f * fZec604[i] - fRec499[i - 1];
				fRec500[i] = fZec597[i];
				fRec501[i] = fZec603[i];
				fRec502[i] = fZec604[i];
				fZec605[i] = fZec598[i] + -1.0f;
				fZec606[i] = mydsp_faustpower2_f(fZec598[i]) + -1.0f;
				fZec607[i] = fRec500[i] + 2.0f * fRec501[i] * fZec605[i] + fRec502[i] * fZec606[i];
				fZec608[i] = fRec493[i - 1] + fSlow122 * (fZec607[i] - fRec494[i - 1]) / fZec599[i];
				fZec609[i] = fSlow122 * (fZec601[i] + 1.41442716f) / fZec599[i] + 1.0f;
				fZec610[i] = fZec608[i] / fZec609[i];
				fRec493[i] = 2.0f * fZec610[i] - fRec493[i - 1];
				fZec611[i] = fRec494[i - 1] + fSlow122 * fZec608[i] / (fZec599[i] * fZec609[i]);
				fRec494[i] = 2.0f * fZec611[i] - fRec494[i - 1];
				fRec495[i] = fZec607[i];
				fRec496[i] = fZec610[i];
				fRec497[i] = fZec611[i];
				fZec612[i] = fRec495[i] + 1.41442716f * fRec496[i] * fZec605[i] + fRec497[i] * fZec606[i];
				fZec613[i] = fRec488[i - 1] + fSlow122 * (fZec612[i] - fRec489[i - 1]) / fZec599[i];
				fZec614[i] = fSlow122 * (fZec601[i] + 0.5f) / fZec599[i] + 1.0f;
				fZec615[i] = fZec613[i] / fZec614[i];
				fRec488[i] = 2.0f * fZec615[i] - fRec488[i - 1];
				fZec616[i] = fRec489[i - 1] + fSlow122 * fZec613[i] / (fZec599[i] * fZec614[i]);
				fRec489[i] = 2.0f * fZec616[i] - fRec489[i - 1];
				fRec490[i] = fZec612[i];
				fRec491[i] = fZec615[i];
				fRec492[i] = fZec616[i];
				fZec617[i] = fRec490[i] + 0.5f * fRec491[i] * fZec605[i] + fRec492[i] * fZec606[i];
				fZec618[i] = fRec368[i] + fSlow246 * (fZec301[i] - fRec368[i]);
				fVbargraph20 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec618[i])));
				fZec619[i] = fZec618[i];
				fZec620[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec619[i]));
				fZec621[i] = std::sqrt(fZec620[i]);
				fZec622[i] = fRec483[i - 1] + fSlow122 * (fZec617[i] - fRec484[i - 1]) / fZec621[i];
				fZec623[i] = fSlow122 / fZec621[i];
				fZec624[i] = fSlow122 * (fZec623[i] + 2.0f) / fZec621[i] + 1.0f;
				fZec625[i] = fZec622[i] / fZec624[i];
				fRec483[i] = 2.0f * fZec625[i] - fRec483[i - 1];
				fZec626[i] = fRec484[i - 1] + fSlow122 * fZec622[i] / (fZec621[i] * fZec624[i]);
				fRec484[i] = 2.0f * fZec626[i] - fRec484[i - 1];
				fRec485[i] = fZec617[i];
				fRec486[i] = fZec625[i];
				fRec487[i] = fZec626[i];
				fZec627[i] = fZec620[i] + -1.0f;
				fZec628[i] = mydsp_faustpower2_f(fZec620[i]) + -1.0f;
				fZec629[i] = fRec485[i] + 2.0f * fRec486[i] * fZec627[i] + fRec487[i] * fZec628[i];
				fZec630[i] = fRec478[i - 1] + fSlow122 * (fZec629[i] - fRec479[i - 1]) / fZec621[i];
				fZec631[i] = fSlow122 * (fZec623[i] + 1.41442716f) / fZec621[i] + 1.0f;
				fZec632[i] = fZec630[i] / fZec631[i];
				fRec478[i] = 2.0f * fZec632[i] - fRec478[i - 1];
				fZec633[i] = fRec479[i - 1] + fSlow122 * fZec630[i] / (fZec621[i] * fZec631[i]);
				fRec479[i] = 2.0f * fZec633[i] - fRec479[i - 1];
				fRec480[i] = fZec629[i];
				fRec481[i] = fZec632[i];
				fRec482[i] = fZec633[i];
				fZec634[i] = fRec480[i] + 1.41442716f * fRec481[i] * fZec627[i] + fRec482[i] * fZec628[i];
				fZec635[i] = fRec473[i - 1] + fSlow122 * (fZec634[i] - fRec474[i - 1]) / fZec621[i];
				fZec636[i] = fSlow122 * (fZec623[i] + 0.5f) / fZec621[i] + 1.0f;
				fZec637[i] = fZec635[i] / fZec636[i];
				fRec473[i] = 2.0f * fZec637[i] - fRec473[i - 1];
				fZec638[i] = fRec474[i - 1] + fSlow122 * fZec635[i] / (fZec621[i] * fZec636[i]);
				fRec474[i] = 2.0f * fZec638[i] - fRec474[i - 1];
				fRec475[i] = fZec634[i];
				fRec476[i] = fZec637[i];
				fRec477[i] = fZec638[i];
				fZec639[i] = fRec475[i] + 0.5f * fRec476[i] * fZec627[i] + fRec477[i] * fZec628[i];
				fZec640[i] = std::pow(10.0f, 0.00833333377f * fZec619[i]);
				fZec641[i] = std::sqrt(fZec640[i]);
				fZec642[i] = fRec468[i - 1] + fSlow111 * (fZec639[i] - fRec469[i - 1]) / fZec641[i];
				fZec643[i] = fSlow111 / fZec641[i];
				fZec644[i] = fSlow111 * (fZec643[i] + 2.0f) / fZec641[i] + 1.0f;
				fZec645[i] = fZec642[i] / fZec644[i];
				fRec468[i] = 2.0f * fZec645[i] - fRec468[i - 1];
				fZec646[i] = fRec469[i - 1] + fSlow111 * fZec642[i] / (fZec641[i] * fZec644[i]);
				fRec469[i] = 2.0f * fZec646[i] - fRec469[i - 1];
				fRec470[i] = fZec639[i];
				fRec471[i] = fZec645[i];
				fRec472[i] = fZec646[i];
				fZec647[i] = fZec640[i] + -1.0f;
				fZec648[i] = mydsp_faustpower2_f(fZec640[i]) + -1.0f;
				fZec649[i] = fRec470[i] + 2.0f * fRec471[i] * fZec647[i] + fRec472[i] * fZec648[i];
				fZec650[i] = fRec463[i - 1] + fSlow111 * (fZec649[i] - fRec464[i - 1]) / fZec641[i];
				fZec651[i] = fSlow111 * (fZec643[i] + 1.41442716f) / fZec641[i] + 1.0f;
				fZec652[i] = fZec650[i] / fZec651[i];
				fRec463[i] = 2.0f * fZec652[i] - fRec463[i - 1];
				fZec653[i] = fRec464[i - 1] + fSlow111 * fZec650[i] / (fZec641[i] * fZec651[i]);
				fRec464[i] = 2.0f * fZec653[i] - fRec464[i - 1];
				fRec465[i] = fZec649[i];
				fRec466[i] = fZec652[i];
				fRec467[i] = fZec653[i];
				fZec654[i] = fRec465[i] + 1.41442716f * fRec466[i] * fZec647[i] + fRec467[i] * fZec648[i];
				fZec655[i] = fRec458[i - 1] + fSlow111 * (fZec654[i] - fRec459[i - 1]) / fZec641[i];
				fZec656[i] = fSlow111 * (fZec643[i] + 0.5f) / fZec641[i] + 1.0f;
				fZec657[i] = fZec655[i] / fZec656[i];
				fRec458[i] = 2.0f * fZec657[i] - fRec458[i - 1];
				fZec658[i] = fRec459[i - 1] + fSlow111 * fZec655[i] / (fZec641[i] * fZec656[i]);
				fRec459[i] = 2.0f * fZec658[i] - fRec459[i - 1];
				fRec460[i] = fZec654[i];
				fRec461[i] = fZec657[i];
				fRec462[i] = fZec658[i];
				fZec659[i] = fRec460[i] + 0.5f * fRec461[i] * fZec647[i] + fRec462[i] * fZec648[i];
				fZec660[i] = fRec374[i] + fSlow262 * (fZec354[i] - fRec374[i]);
				fVbargraph21 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec660[i])));
				fZec661[i] = fZec660[i];
				fZec662[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec661[i]));
				fZec663[i] = std::sqrt(fZec662[i]);
				fZec664[i] = fRec453[i - 1] + fSlow111 * (fZec659[i] - fRec454[i - 1]) / fZec663[i];
				fZec665[i] = fSlow111 / fZec663[i];
				fZec666[i] = fSlow111 * (fZec665[i] + 2.0f) / fZec663[i] + 1.0f;
				fZec667[i] = fZec664[i] / fZec666[i];
				fRec453[i] = 2.0f * fZec667[i] - fRec453[i - 1];
				fZec668[i] = fRec454[i - 1] + fSlow111 * fZec664[i] / (fZec663[i] * fZec666[i]);
				fRec454[i] = 2.0f * fZec668[i] - fRec454[i - 1];
				fRec455[i] = fZec659[i];
				fRec456[i] = fZec667[i];
				fRec457[i] = fZec668[i];
				fZec669[i] = fZec662[i] + -1.0f;
				fZec670[i] = mydsp_faustpower2_f(fZec662[i]) + -1.0f;
				fZec671[i] = fRec455[i] + 2.0f * fRec456[i] * fZec669[i] + fRec457[i] * fZec670[i];
				fZec672[i] = fRec448[i - 1] + fSlow111 * (fZec671[i] - fRec449[i - 1]) / fZec663[i];
				fZec673[i] = fSlow111 * (fZec665[i] + 1.41442716f) / fZec663[i] + 1.0f;
				fZec674[i] = fZec672[i] / fZec673[i];
				fRec448[i] = 2.0f * fZec674[i] - fRec448[i - 1];
				fZec675[i] = fRec449[i - 1] + fSlow111 * fZec672[i] / (fZec663[i] * fZec673[i]);
				fRec449[i] = 2.0f * fZec675[i] - fRec449[i - 1];
				fRec450[i] = fZec671[i];
				fRec451[i] = fZec674[i];
				fRec452[i] = fZec675[i];
				fZec676[i] = fRec450[i] + 1.41442716f * fRec451[i] * fZec669[i] + fRec452[i] * fZec670[i];
				fZec677[i] = fRec443[i - 1] + fSlow111 * (fZec676[i] - fRec444[i - 1]) / fZec663[i];
				fZec678[i] = fSlow111 * (fZec665[i] + 0.5f) / fZec663[i] + 1.0f;
				fZec679[i] = fZec677[i] / fZec678[i];
				fRec443[i] = 2.0f * fZec679[i] - fRec443[i - 1];
				fZec680[i] = fRec444[i - 1] + fSlow111 * fZec677[i] / (fZec663[i] * fZec678[i]);
				fRec444[i] = 2.0f * fZec680[i] - fRec444[i - 1];
				fRec445[i] = fZec676[i];
				fRec446[i] = fZec679[i];
				fRec447[i] = fZec680[i];
				fZec681[i] = fRec445[i] + 0.5f * fRec446[i] * fZec669[i] + fRec447[i] * fZec670[i];
				fZec682[i] = std::pow(10.0f, 0.00833333377f * fZec661[i]);
				fZec683[i] = std::sqrt(fZec682[i]);
				fZec684[i] = fRec438[i - 1] + fSlow100 * (fZec681[i] - fRec439[i - 1]) / fZec683[i];
				fZec685[i] = fSlow100 / fZec683[i];
				fZec686[i] = fSlow100 * (fZec685[i] + 2.0f) / fZec683[i] + 1.0f;
				fZec687[i] = fZec684[i] / fZec686[i];
				fRec438[i] = 2.0f * fZec687[i] - fRec438[i - 1];
				fZec688[i] = fRec439[i - 1] + fSlow100 * fZec684[i] / (fZec683[i] * fZec686[i]);
				fRec439[i] = 2.0f * fZec688[i] - fRec439[i - 1];
				fRec440[i] = fZec681[i];
				fRec441[i] = fZec687[i];
				fRec442[i] = fZec688[i];
				fZec689[i] = fZec682[i] + -1.0f;
				fZec690[i] = mydsp_faustpower2_f(fZec682[i]) + -1.0f;
				fZec691[i] = fRec440[i] + 2.0f * fRec441[i] * fZec689[i] + fRec442[i] * fZec690[i];
				fZec692[i] = fRec433[i - 1] + fSlow100 * (fZec691[i] - fRec434[i - 1]) / fZec683[i];
				fZec693[i] = fSlow100 * (fZec685[i] + 1.41442716f) / fZec683[i] + 1.0f;
				fZec694[i] = fZec692[i] / fZec693[i];
				fRec433[i] = 2.0f * fZec694[i] - fRec433[i - 1];
				fZec695[i] = fRec434[i - 1] + fSlow100 * fZec692[i] / (fZec683[i] * fZec693[i]);
				fRec434[i] = 2.0f * fZec695[i] - fRec434[i - 1];
				fRec435[i] = fZec691[i];
				fRec436[i] = fZec694[i];
				fRec437[i] = fZec695[i];
				fZec696[i] = fRec435[i] + 1.41442716f * fRec436[i] * fZec689[i] + fRec437[i] * fZec690[i];
				fZec697[i] = fRec428[i - 1] + fSlow100 * (fZec696[i] - fRec429[i - 1]) / fZec683[i];
				fZec698[i] = fSlow100 * (fZec685[i] + 0.5f) / fZec683[i] + 1.0f;
				fZec699[i] = fZec697[i] / fZec698[i];
				fRec428[i] = 2.0f * fZec699[i] - fRec428[i - 1];
				fZec700[i] = fRec429[i - 1] + fSlow100 * fZec697[i] / (fZec683[i] * fZec698[i]);
				fRec429[i] = 2.0f * fZec700[i] - fRec429[i - 1];
				fRec430[i] = fZec696[i];
				fRec431[i] = fZec699[i];
				fRec432[i] = fZec700[i];
				fZec701[i] = fRec430[i] + 0.5f * fRec431[i] * fZec689[i] + fRec432[i] * fZec690[i];
				fZec702[i] = fRec380[i] + fSlow278 * (fZec407[i] - fRec380[i]);
				fVbargraph22 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec702[i])));
				fZec703[i] = fZec702[i];
				fZec704[i] = std::pow(10.0f, 0.0250000004f * (0.0f - 0.333333343f * fZec703[i]));
				fZec705[i] = std::sqrt(fZec704[i]);
				fZec706[i] = fRec423[i - 1] + fSlow100 * (fZec701[i] - fRec424[i - 1]) / fZec705[i];
				fZec707[i] = fSlow100 / fZec705[i];
				fZec708[i] = fSlow100 * (fZec707[i] + 2.0f) / fZec705[i] + 1.0f;
				fZec709[i] = fZec706[i] / fZec708[i];
				fRec423[i] = 2.0f * fZec709[i] - fRec423[i - 1];
				fZec710[i] = fRec424[i - 1] + fSlow100 * fZec706[i] / (fZec705[i] * fZec708[i]);
				fRec424[i] = 2.0f * fZec710[i] - fRec424[i - 1];
				fRec425[i] = fZec701[i];
				fRec426[i] = fZec709[i];
				fRec427[i] = fZec710[i];
				fZec711[i] = fZec704[i] + -1.0f;
				fZec712[i] = mydsp_faustpower2_f(fZec704[i]) + -1.0f;
				fZec713[i] = fRec425[i] + 2.0f * fRec426[i] * fZec711[i] + fRec427[i] * fZec712[i];
				fZec714[i] = fRec418[i - 1] + fSlow100 * (fZec713[i] - fRec419[i - 1]) / fZec705[i];
				fZec715[i] = fSlow100 * (fZec707[i] + 1.41442716f) / fZec705[i] + 1.0f;
				fZec716[i] = fZec714[i] / fZec715[i];
				fRec418[i] = 2.0f * fZec716[i] - fRec418[i - 1];
				fZec717[i] = fRec419[i - 1] + fSlow100 * fZec714[i] / (fZec705[i] * fZec715[i]);
				fRec419[i] = 2.0f * fZec717[i] - fRec419[i - 1];
				fRec420[i] = fZec713[i];
				fRec421[i] = fZec716[i];
				fRec422[i] = fZec717[i];
				fZec718[i] = fRec420[i] + 1.41442716f * fRec421[i] * fZec711[i] + fRec422[i] * fZec712[i];
				fZec719[i] = fRec413[i - 1] + fSlow100 * (fZec718[i] - fRec414[i - 1]) / fZec705[i];
				fZec720[i] = fSlow100 * (fZec707[i] + 0.5f) / fZec705[i] + 1.0f;
				fZec721[i] = fZec719[i] / fZec720[i];
				fRec413[i] = 2.0f * fZec721[i] - fRec413[i - 1];
				fZec722[i] = fRec414[i - 1] + fSlow100 * fZec719[i] / (fZec705[i] * fZec720[i]);
				fRec414[i] = 2.0f * fZec722[i] - fRec414[i - 1];
				fRec415[i] = fZec718[i];
				fRec416[i] = fZec721[i];
				fRec417[i] = fZec722[i];
				fZec723[i] = fRec415[i] + 0.5f * fRec416[i] * fZec711[i] + fRec417[i] * fZec712[i];
				fZec724[i] = std::pow(10.0f, 0.00833333377f * fZec703[i]);
				fZec725[i] = std::sqrt(fZec724[i]);
				fZec726[i] = fRec408[i - 1] + fSlow68 * (fZec723[i] - fRec409[i - 1]) / fZec725[i];
				fZec727[i] = fSlow68 / fZec725[i];
				fZec728[i] = fSlow68 * (fZec727[i] + 2.0f) / fZec725[i] + 1.0f;
				fZec729[i] = fZec726[i] / fZec728[i];
				fRec408[i] = 2.0f * fZec729[i] - fRec408[i - 1];
				fZec730[i] = fRec409[i - 1] + fSlow68 * fZec726[i] / (fZec725[i] * fZec728[i]);
				fRec409[i] = 2.0f * fZec730[i] - fRec409[i - 1];
				fRec410[i] = fZec723[i];
				fRec411[i] = fZec729[i];
				fRec412[i] = fZec730[i];
				fZec731[i] = fZec724[i] + -1.0f;
				fZec732[i] = mydsp_faustpower2_f(fZec724[i]) + -1.0f;
				fZec733[i] = fRec410[i] + 2.0f * fRec411[i] * fZec731[i] + fRec412[i] * fZec732[i];
				fZec734[i] = fRec403[i - 1] + fSlow68 * (fZec733[i] - fRec404[i - 1]) / fZec725[i];
				fZec735[i] = fSlow68 * (fZec727[i] + 1.41442716f) / fZec725[i] + 1.0f;
				fZec736[i] = fZec734[i] / fZec735[i];
				fRec403[i] = 2.0f * fZec736[i] - fRec403[i - 1];
				fZec737[i] = fRec404[i - 1] + fSlow68 * fZec734[i] / (fZec725[i] * fZec735[i]);
				fRec404[i] = 2.0f * fZec737[i] - fRec404[i - 1];
				fRec405[i] = fZec733[i];
				fRec406[i] = fZec736[i];
				fRec407[i] = fZec737[i];
				fZec738[i] = fRec405[i] + 1.41442716f * fRec406[i] * fZec731[i] + fRec407[i] * fZec732[i];
				fZec739[i] = fRec398[i - 1] + fSlow68 * (fZec738[i] - fRec399[i - 1]) / fZec725[i];
				fZec740[i] = fSlow68 * (fZec727[i] + 0.5f) / fZec725[i] + 1.0f;
				fZec741[i] = fZec739[i] / fZec740[i];
				fRec398[i] = 2.0f * fZec741[i] - fRec398[i - 1];
				fZec742[i] = fRec399[i - 1] + fSlow68 * fZec739[i] / (fZec725[i] * fZec740[i]);
				fRec399[i] = 2.0f * fZec742[i] - fRec399[i - 1];
				fRec400[i] = fZec738[i];
				fRec401[i] = fZec741[i];
				fRec402[i] = fZec742[i];
				fZec743[i] = fRec91[i] + fSlow279 * (fZec449[i] - fRec91[i]);
				fVbargraph23 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fZec743[i])));
				fZec744[i] = std::pow(10.0f, 0.00833333377f * fZec743[i]);
				fZec745[i] = std::sqrt(fZec744[i]);
				fZec746[i] = fRec400[i] + 0.5f * fRec401[i] * fZec731[i] + fRec402[i] * fZec732[i];
				fZec747[i] = fRec393[i - 1] + fSlow68 * fZec745[i] * (fZec746[i] - fRec394[i - 1]);
				fZec748[i] = fSlow68 * fZec745[i];
				fZec749[i] = fSlow68 * fZec745[i] * (fZec748[i] + 2.0f) + 1.0f;
				fZec750[i] = fZec747[i] / fZec749[i];
				fRec393[i] = 2.0f * fZec750[i] - fRec393[i - 1];
				fZec751[i] = fRec394[i - 1] + fSlow68 * (fZec745[i] * fZec747[i]) / fZec749[i];
				fRec394[i] = 2.0f * fZec751[i] - fRec394[i - 1];
				fRec395[i] = fZec746[i];
				fRec396[i] = fZec750[i];
				fRec397[i] = fZec751[i];
				fZec752[i] = 1.0f - fZec744[i];
				fZec753[i] = 1.0f - mydsp_faustpower2_f(fZec744[i]);
				fZec754[i] = fZec744[i] * (fRec395[i] * fZec744[i] + 2.0f * fRec396[i] * fZec752[i]) + fRec397[i] * fZec753[i];
				fZec755[i] = fRec388[i - 1] + fSlow68 * fZec745[i] * (fZec754[i] - fRec389[i - 1]);
				fZec756[i] = fSlow68 * fZec745[i] * (fZec748[i] + 1.41442716f) + 1.0f;
				fZec757[i] = fZec755[i] / fZec756[i];
				fRec388[i] = 2.0f * fZec757[i] - fRec388[i - 1];
				fZec758[i] = fRec389[i - 1] + fSlow68 * (fZec745[i] * fZec755[i]) / fZec756[i];
				fRec389[i] = 2.0f * fZec758[i] - fRec389[i - 1];
				fRec390[i] = fZec754[i];
				fRec391[i] = fZec757[i];
				fRec392[i] = fZec758[i];
				fZec759[i] = fZec744[i] * (fRec390[i] * fZec744[i] + 1.41442716f * fRec391[i] * fZec752[i]) + fRec392[i] * fZec753[i];
				fZec760[i] = fRec383[i - 1] + fSlow68 * fZec745[i] * (fZec759[i] - fRec384[i - 1]);
				fZec761[i] = fSlow68 * fZec745[i] * (fZec748[i] + 0.5f) + 1.0f;
				fZec762[i] = fZec760[i] / fZec761[i];
				fRec383[i] = 2.0f * fZec762[i] - fRec383[i - 1];
				fZec763[i] = fRec384[i - 1] + fSlow68 * (fZec745[i] * fZec760[i]) / fZec761[i];
				fRec384[i] = 2.0f * fZec763[i] - fRec384[i - 1];
				fRec385[i] = fZec759[i];
				fRec386[i] = fZec762[i];
				fRec387[i] = fZec763[i];
				fZec764[i] = std::fabs(fRec5[i - 1]);
				fZec765[i] = fRec7[i] * fZec63[i];
				fZec767[i] = fZec451[i] * (fRec97[i] * fZec451[i] + 0.5f * fRec98[i] * fZec459[i]) + fRec99[i] * fZec460[i];
				fZec768[i] = fZec744[i] * (fRec385[i] * fZec744[i] + 0.5f * fRec386[i] * fZec752[i]) + fRec387[i] * fZec753[i];
				fZec769[i] = fZec765[i] * fZec86[i] + fZec766[i] * (fZec767[i] + fZec768[i]);
				fRec594[(i + fRec594_idx) & 131071] = fRec594[((i + fRec594_idx) - 1) & 131071] + mydsp_faustpower2_f(fZec764[i] + fSlow280 * (std::fabs(fZec769[i]) - fZec764[i]));
				fZec770[i] = std::sqrt(fSlow282 * (fRec594[(i + fRec594_idx) & 131071] - fRec594[((i + fRec594_idx) - iSlow283) & 131071]));
				fZec771[i] = ((fZec770[i] > fRec593[i - 1]) ? fSlow286 : 0.0f);
				fRec593[i] = fZec770[i] * (1.0f - fZec771[i]) + fRec593[i - 1] * fZec771[i];
				fZec772[i] = std::fabs(fRec6[i - 1]);
				fZec773[i] = fZec765[i] * fZec87[i] + fZec766[i] * (fZec767[i] - fZec768[i]);
				fRec596[(i + fRec596_idx) & 131071] = fRec596[((i + fRec596_idx) - 1) & 131071] + mydsp_faustpower2_f(fZec772[i] + fSlow280 * (std::fabs(fZec773[i]) - fZec772[i]));
				fZec774[i] = std::sqrt(fSlow282 * (fRec596[(i + fRec596_idx) & 131071] - fRec596[((i + fRec596_idx) - iSlow283) & 131071]));
				fZec775[i] = ((fZec774[i] > fRec595[i - 1]) ? fSlow286 : 0.0f);
				fRec595[i] = fZec774[i] * (1.0f - fZec775[i]) + fRec595[i - 1] * fZec775[i];
				fZec776[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, fRec593[i]));
				iZec777[i] = (fZec776[i] > fSlow292) + (fZec776[i] > fSlow293);
				fZec778[i] = fZec776[i] - fSlow289;
				float fThen194 = fZec778[i];
				float fElse194 = fSlow294 * mydsp_faustpower2_f(fSlow291 + fZec778[i]);
				float fThen195 = ((iZec777[i] == 1) ? fElse194 : fThen194);
				fZec779[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, fRec595[i]));
				iZec780[i] = (fZec779[i] > fSlow292) + (fZec779[i] > fSlow293);
				fZec781[i] = fZec779[i] - fSlow289;
				float fThen196 = fZec781[i];
				float fElse196 = fSlow294 * mydsp_faustpower2_f(fSlow291 + fZec781[i]);
				float fThen197 = ((iZec780[i] == 1) ? fElse196 : fThen196);
				fZec782[i] = std::min<float>(std::pow(10.0f, 0.0500000007f * (0.0f - fSlow287 * std::max<float>(0.0f, ((iZec777[i] == 0) ? 0.0f : fThen195)))), std::pow(10.0f, 0.0500000007f * (0.0f - fSlow287 * std::max<float>(0.0f, ((iZec780[i] == 0) ? 0.0f : fThen197)))));
				fVbargraph24 = FAUSTFLOAT(20.0f * std::log10(std::max<float>(1.17549435e-38f, fZec782[i])));
				fZec783[i] = fZec782[i];
				fRec5[i] = fZec769[i] * fZec783[i];
				fRec6[i] = fZec773[i] * fZec783[i];
				fZec785[i] = fRec5[i] * fRec597[i] * fZec784[i] + fRec598[i] * fZec769[i];
				fZec786[i] = std::fabs(fZec785[i]);
				fZec787[i] = ((fZec786[i] > fRec600[i - 1]) ? 0.0f : fSlow300);
				fRec600[i] = fZec786[i] * (1.0f - fZec787[i]) + fRec600[i - 1] * fZec787[i];
				fZec788[i] = fRec598[i] * fZec773[i] + fRec597[i] * fRec6[i] * fZec784[i];
				fZec789[i] = std::fabs(fZec788[i]);
				fZec790[i] = ((fZec789[i] > fRec601[i - 1]) ? 0.0f : fSlow300);
				fRec601[i] = fZec789[i] * (1.0f - fZec790[i]) + fRec601[i - 1] * fZec790[i];
				fZec791[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, fRec600[i]));
				iZec792[i] = 2 * (fZec791[i] > fSlow301);
				fZec793[i] = fZec791[i] - fSlow301;
				float fThen202 = fZec793[i];
				float fElse202 = 4194304.0f * mydsp_faustpower2_f(fZec793[i]);
				float fThen203 = ((iZec792[i] == 1) ? fElse202 : fThen202);
				fZec794[i] = 20.0f * std::log10(std::max<float>(1.17549435e-38f, fRec601[i]));
				iZec795[i] = 2 * (fZec794[i] > fSlow301);
				fZec796[i] = fZec794[i] - fSlow301;
				float fThen204 = fZec796[i];
				float fElse204 = 4194304.0f * mydsp_faustpower2_f(fZec796[i]);
				float fThen205 = ((iZec795[i] == 1) ? fElse204 : fThen204);
				fZec797[i] = std::min<float>(std::pow(10.0f, 0.0500000007f * (0.0f - std::max<float>(0.0f, ((iZec792[i] == 0) ? 0.0f : fThen203)))), std::pow(10.0f, 0.0500000007f * (0.0f - std::max<float>(0.0f, ((iZec795[i] == 0) ? 0.0f : fThen205)))));
				fVbargraph25 = FAUSTFLOAT(20.0f * std::log10(std::max<float>(1.17549435e-38f, fZec797[i])));
				fZec798[i] = fRec599[i] + (1.0f - fRec599[i]) * fZec797[i];
				fRec3[i] = fZec785[i] * fZec798[i];
				fRec4[i] = fZec788[i] * fZec798[i];
				fRec1[i] = fRec3[i];
				fRec2[i] = fRec4[i];
			}
			/* Post code */
			for (int j749 = 0; j749 < 4; j749 = j749 + 1) {
				fRec601_perm[j749] = fRec601_tmp[vsize + j749];
			}
			for (int j747 = 0; j747 < 4; j747 = j747 + 1) {
				fRec600_perm[j747] = fRec600_tmp[vsize + j747];
			}
			fRec596_idx_save = vsize;
			for (int j735 = 0; j735 < 4; j735 = j735 + 1) {
				fRec595_perm[j735] = fRec595_tmp[vsize + j735];
			}
			fRec594_idx_save = vsize;
			for (int j733 = 0; j733 < 4; j733 = j733 + 1) {
				fRec593_perm[j733] = fRec593_tmp[vsize + j733];
			}
			for (int j565 = 0; j565 < 4; j565 = j565 + 1) {
				fRec588_perm[j565] = fRec588_tmp[vsize + j565];
			}
			for (int j567 = 0; j567 < 4; j567 = j567 + 1) {
				fRec589_perm[j567] = fRec589_tmp[vsize + j567];
			}
			for (int j569 = 0; j569 < 4; j569 = j569 + 1) {
				fRec583_perm[j569] = fRec583_tmp[vsize + j569];
			}
			for (int j571 = 0; j571 < 4; j571 = j571 + 1) {
				fRec584_perm[j571] = fRec584_tmp[vsize + j571];
			}
			for (int j573 = 0; j573 < 4; j573 = j573 + 1) {
				fRec578_perm[j573] = fRec578_tmp[vsize + j573];
			}
			for (int j575 = 0; j575 < 4; j575 = j575 + 1) {
				fRec579_perm[j575] = fRec579_tmp[vsize + j575];
			}
			for (int j577 = 0; j577 < 4; j577 = j577 + 1) {
				fRec573_perm[j577] = fRec573_tmp[vsize + j577];
			}
			for (int j579 = 0; j579 < 4; j579 = j579 + 1) {
				fRec574_perm[j579] = fRec574_tmp[vsize + j579];
			}
			for (int j581 = 0; j581 < 4; j581 = j581 + 1) {
				fRec568_perm[j581] = fRec568_tmp[vsize + j581];
			}
			for (int j583 = 0; j583 < 4; j583 = j583 + 1) {
				fRec569_perm[j583] = fRec569_tmp[vsize + j583];
			}
			for (int j585 = 0; j585 < 4; j585 = j585 + 1) {
				fRec563_perm[j585] = fRec563_tmp[vsize + j585];
			}
			for (int j587 = 0; j587 < 4; j587 = j587 + 1) {
				fRec564_perm[j587] = fRec564_tmp[vsize + j587];
			}
			for (int j589 = 0; j589 < 4; j589 = j589 + 1) {
				fRec558_perm[j589] = fRec558_tmp[vsize + j589];
			}
			for (int j591 = 0; j591 < 4; j591 = j591 + 1) {
				fRec559_perm[j591] = fRec559_tmp[vsize + j591];
			}
			for (int j593 = 0; j593 < 4; j593 = j593 + 1) {
				fRec553_perm[j593] = fRec553_tmp[vsize + j593];
			}
			for (int j595 = 0; j595 < 4; j595 = j595 + 1) {
				fRec554_perm[j595] = fRec554_tmp[vsize + j595];
			}
			for (int j597 = 0; j597 < 4; j597 = j597 + 1) {
				fRec548_perm[j597] = fRec548_tmp[vsize + j597];
			}
			for (int j599 = 0; j599 < 4; j599 = j599 + 1) {
				fRec549_perm[j599] = fRec549_tmp[vsize + j599];
			}
			for (int j601 = 0; j601 < 4; j601 = j601 + 1) {
				fRec543_perm[j601] = fRec543_tmp[vsize + j601];
			}
			for (int j603 = 0; j603 < 4; j603 = j603 + 1) {
				fRec544_perm[j603] = fRec544_tmp[vsize + j603];
			}
			for (int j605 = 0; j605 < 4; j605 = j605 + 1) {
				fRec538_perm[j605] = fRec538_tmp[vsize + j605];
			}
			for (int j607 = 0; j607 < 4; j607 = j607 + 1) {
				fRec539_perm[j607] = fRec539_tmp[vsize + j607];
			}
			for (int j609 = 0; j609 < 4; j609 = j609 + 1) {
				fRec533_perm[j609] = fRec533_tmp[vsize + j609];
			}
			for (int j611 = 0; j611 < 4; j611 = j611 + 1) {
				fRec534_perm[j611] = fRec534_tmp[vsize + j611];
			}
			for (int j613 = 0; j613 < 4; j613 = j613 + 1) {
				fRec528_perm[j613] = fRec528_tmp[vsize + j613];
			}
			for (int j615 = 0; j615 < 4; j615 = j615 + 1) {
				fRec529_perm[j615] = fRec529_tmp[vsize + j615];
			}
			for (int j617 = 0; j617 < 4; j617 = j617 + 1) {
				fRec523_perm[j617] = fRec523_tmp[vsize + j617];
			}
			for (int j619 = 0; j619 < 4; j619 = j619 + 1) {
				fRec524_perm[j619] = fRec524_tmp[vsize + j619];
			}
			for (int j621 = 0; j621 < 4; j621 = j621 + 1) {
				fRec518_perm[j621] = fRec518_tmp[vsize + j621];
			}
			for (int j623 = 0; j623 < 4; j623 = j623 + 1) {
				fRec519_perm[j623] = fRec519_tmp[vsize + j623];
			}
			for (int j625 = 0; j625 < 4; j625 = j625 + 1) {
				fRec513_perm[j625] = fRec513_tmp[vsize + j625];
			}
			for (int j627 = 0; j627 < 4; j627 = j627 + 1) {
				fRec514_perm[j627] = fRec514_tmp[vsize + j627];
			}
			for (int j629 = 0; j629 < 4; j629 = j629 + 1) {
				fRec508_perm[j629] = fRec508_tmp[vsize + j629];
			}
			for (int j631 = 0; j631 < 4; j631 = j631 + 1) {
				fRec509_perm[j631] = fRec509_tmp[vsize + j631];
			}
			for (int j633 = 0; j633 < 4; j633 = j633 + 1) {
				fRec503_perm[j633] = fRec503_tmp[vsize + j633];
			}
			for (int j635 = 0; j635 < 4; j635 = j635 + 1) {
				fRec504_perm[j635] = fRec504_tmp[vsize + j635];
			}
			for (int j637 = 0; j637 < 4; j637 = j637 + 1) {
				fRec498_perm[j637] = fRec498_tmp[vsize + j637];
			}
			for (int j639 = 0; j639 < 4; j639 = j639 + 1) {
				fRec499_perm[j639] = fRec499_tmp[vsize + j639];
			}
			for (int j641 = 0; j641 < 4; j641 = j641 + 1) {
				fRec493_perm[j641] = fRec493_tmp[vsize + j641];
			}
			for (int j643 = 0; j643 < 4; j643 = j643 + 1) {
				fRec494_perm[j643] = fRec494_tmp[vsize + j643];
			}
			for (int j645 = 0; j645 < 4; j645 = j645 + 1) {
				fRec488_perm[j645] = fRec488_tmp[vsize + j645];
			}
			for (int j647 = 0; j647 < 4; j647 = j647 + 1) {
				fRec489_perm[j647] = fRec489_tmp[vsize + j647];
			}
			for (int j649 = 0; j649 < 4; j649 = j649 + 1) {
				fRec483_perm[j649] = fRec483_tmp[vsize + j649];
			}
			for (int j651 = 0; j651 < 4; j651 = j651 + 1) {
				fRec484_perm[j651] = fRec484_tmp[vsize + j651];
			}
			for (int j653 = 0; j653 < 4; j653 = j653 + 1) {
				fRec478_perm[j653] = fRec478_tmp[vsize + j653];
			}
			for (int j655 = 0; j655 < 4; j655 = j655 + 1) {
				fRec479_perm[j655] = fRec479_tmp[vsize + j655];
			}
			for (int j657 = 0; j657 < 4; j657 = j657 + 1) {
				fRec473_perm[j657] = fRec473_tmp[vsize + j657];
			}
			for (int j659 = 0; j659 < 4; j659 = j659 + 1) {
				fRec474_perm[j659] = fRec474_tmp[vsize + j659];
			}
			for (int j661 = 0; j661 < 4; j661 = j661 + 1) {
				fRec468_perm[j661] = fRec468_tmp[vsize + j661];
			}
			for (int j663 = 0; j663 < 4; j663 = j663 + 1) {
				fRec469_perm[j663] = fRec469_tmp[vsize + j663];
			}
			for (int j665 = 0; j665 < 4; j665 = j665 + 1) {
				fRec463_perm[j665] = fRec463_tmp[vsize + j665];
			}
			for (int j667 = 0; j667 < 4; j667 = j667 + 1) {
				fRec464_perm[j667] = fRec464_tmp[vsize + j667];
			}
			for (int j669 = 0; j669 < 4; j669 = j669 + 1) {
				fRec458_perm[j669] = fRec458_tmp[vsize + j669];
			}
			for (int j671 = 0; j671 < 4; j671 = j671 + 1) {
				fRec459_perm[j671] = fRec459_tmp[vsize + j671];
			}
			for (int j673 = 0; j673 < 4; j673 = j673 + 1) {
				fRec453_perm[j673] = fRec453_tmp[vsize + j673];
			}
			for (int j675 = 0; j675 < 4; j675 = j675 + 1) {
				fRec454_perm[j675] = fRec454_tmp[vsize + j675];
			}
			for (int j677 = 0; j677 < 4; j677 = j677 + 1) {
				fRec448_perm[j677] = fRec448_tmp[vsize + j677];
			}
			for (int j679 = 0; j679 < 4; j679 = j679 + 1) {
				fRec449_perm[j679] = fRec449_tmp[vsize + j679];
			}
			for (int j681 = 0; j681 < 4; j681 = j681 + 1) {
				fRec443_perm[j681] = fRec443_tmp[vsize + j681];
			}
			for (int j683 = 0; j683 < 4; j683 = j683 + 1) {
				fRec444_perm[j683] = fRec444_tmp[vsize + j683];
			}
			for (int j685 = 0; j685 < 4; j685 = j685 + 1) {
				fRec438_perm[j685] = fRec438_tmp[vsize + j685];
			}
			for (int j687 = 0; j687 < 4; j687 = j687 + 1) {
				fRec439_perm[j687] = fRec439_tmp[vsize + j687];
			}
			for (int j689 = 0; j689 < 4; j689 = j689 + 1) {
				fRec433_perm[j689] = fRec433_tmp[vsize + j689];
			}
			for (int j691 = 0; j691 < 4; j691 = j691 + 1) {
				fRec434_perm[j691] = fRec434_tmp[vsize + j691];
			}
			for (int j693 = 0; j693 < 4; j693 = j693 + 1) {
				fRec428_perm[j693] = fRec428_tmp[vsize + j693];
			}
			for (int j695 = 0; j695 < 4; j695 = j695 + 1) {
				fRec429_perm[j695] = fRec429_tmp[vsize + j695];
			}
			for (int j697 = 0; j697 < 4; j697 = j697 + 1) {
				fRec423_perm[j697] = fRec423_tmp[vsize + j697];
			}
			for (int j699 = 0; j699 < 4; j699 = j699 + 1) {
				fRec424_perm[j699] = fRec424_tmp[vsize + j699];
			}
			for (int j701 = 0; j701 < 4; j701 = j701 + 1) {
				fRec418_perm[j701] = fRec418_tmp[vsize + j701];
			}
			for (int j703 = 0; j703 < 4; j703 = j703 + 1) {
				fRec419_perm[j703] = fRec419_tmp[vsize + j703];
			}
			for (int j705 = 0; j705 < 4; j705 = j705 + 1) {
				fRec413_perm[j705] = fRec413_tmp[vsize + j705];
			}
			for (int j707 = 0; j707 < 4; j707 = j707 + 1) {
				fRec414_perm[j707] = fRec414_tmp[vsize + j707];
			}
			for (int j709 = 0; j709 < 4; j709 = j709 + 1) {
				fRec408_perm[j709] = fRec408_tmp[vsize + j709];
			}
			for (int j711 = 0; j711 < 4; j711 = j711 + 1) {
				fRec409_perm[j711] = fRec409_tmp[vsize + j711];
			}
			for (int j713 = 0; j713 < 4; j713 = j713 + 1) {
				fRec403_perm[j713] = fRec403_tmp[vsize + j713];
			}
			for (int j715 = 0; j715 < 4; j715 = j715 + 1) {
				fRec404_perm[j715] = fRec404_tmp[vsize + j715];
			}
			for (int j717 = 0; j717 < 4; j717 = j717 + 1) {
				fRec398_perm[j717] = fRec398_tmp[vsize + j717];
			}
			for (int j719 = 0; j719 < 4; j719 = j719 + 1) {
				fRec399_perm[j719] = fRec399_tmp[vsize + j719];
			}
			for (int j721 = 0; j721 < 4; j721 = j721 + 1) {
				fRec393_perm[j721] = fRec393_tmp[vsize + j721];
			}
			for (int j723 = 0; j723 < 4; j723 = j723 + 1) {
				fRec394_perm[j723] = fRec394_tmp[vsize + j723];
			}
			for (int j725 = 0; j725 < 4; j725 = j725 + 1) {
				fRec388_perm[j725] = fRec388_tmp[vsize + j725];
			}
			for (int j727 = 0; j727 < 4; j727 = j727 + 1) {
				fRec389_perm[j727] = fRec389_tmp[vsize + j727];
			}
			for (int j729 = 0; j729 < 4; j729 = j729 + 1) {
				fRec383_perm[j729] = fRec383_tmp[vsize + j729];
			}
			for (int j731 = 0; j731 < 4; j731 = j731 + 1) {
				fRec384_perm[j731] = fRec384_tmp[vsize + j731];
			}
			for (int j523 = 0; j523 < 4; j523 = j523 + 1) {
				fRec382_perm[j523] = fRec382_tmp[vsize + j523];
			}
			for (int j525 = 0; j525 < 4; j525 = j525 + 1) {
				fRec381_perm[j525] = fRec381_tmp[vsize + j525];
			}
			for (int j527 = 0; j527 < 4; j527 = j527 + 1) {
				fRec380_perm[j527] = fRec380_tmp[vsize + j527];
			}
			for (int j517 = 0; j517 < 4; j517 = j517 + 1) {
				fRec379_perm[j517] = fRec379_tmp[vsize + j517];
			}
			for (int j519 = 0; j519 < 4; j519 = j519 + 1) {
				fRec378_perm[j519] = fRec378_tmp[vsize + j519];
			}
			for (int j521 = 0; j521 < 4; j521 = j521 + 1) {
				fRec377_perm[j521] = fRec377_tmp[vsize + j521];
			}
			for (int j487 = 0; j487 < 4; j487 = j487 + 1) {
				fRec376_perm[j487] = fRec376_tmp[vsize + j487];
			}
			for (int j489 = 0; j489 < 4; j489 = j489 + 1) {
				fRec375_perm[j489] = fRec375_tmp[vsize + j489];
			}
			for (int j491 = 0; j491 < 4; j491 = j491 + 1) {
				fRec374_perm[j491] = fRec374_tmp[vsize + j491];
			}
			for (int j481 = 0; j481 < 4; j481 = j481 + 1) {
				fRec373_perm[j481] = fRec373_tmp[vsize + j481];
			}
			for (int j483 = 0; j483 < 4; j483 = j483 + 1) {
				fRec372_perm[j483] = fRec372_tmp[vsize + j483];
			}
			for (int j485 = 0; j485 < 4; j485 = j485 + 1) {
				fRec371_perm[j485] = fRec371_tmp[vsize + j485];
			}
			for (int j451 = 0; j451 < 4; j451 = j451 + 1) {
				fRec370_perm[j451] = fRec370_tmp[vsize + j451];
			}
			for (int j453 = 0; j453 < 4; j453 = j453 + 1) {
				fRec369_perm[j453] = fRec369_tmp[vsize + j453];
			}
			for (int j455 = 0; j455 < 4; j455 = j455 + 1) {
				fRec368_perm[j455] = fRec368_tmp[vsize + j455];
			}
			for (int j445 = 0; j445 < 4; j445 = j445 + 1) {
				fRec367_perm[j445] = fRec367_tmp[vsize + j445];
			}
			for (int j447 = 0; j447 < 4; j447 = j447 + 1) {
				fRec366_perm[j447] = fRec366_tmp[vsize + j447];
			}
			for (int j449 = 0; j449 < 4; j449 = j449 + 1) {
				fRec365_perm[j449] = fRec365_tmp[vsize + j449];
			}
			for (int j415 = 0; j415 < 4; j415 = j415 + 1) {
				fRec364_perm[j415] = fRec364_tmp[vsize + j415];
			}
			for (int j417 = 0; j417 < 4; j417 = j417 + 1) {
				fRec363_perm[j417] = fRec363_tmp[vsize + j417];
			}
			for (int j419 = 0; j419 < 4; j419 = j419 + 1) {
				fRec362_perm[j419] = fRec362_tmp[vsize + j419];
			}
			for (int j409 = 0; j409 < 4; j409 = j409 + 1) {
				fRec361_perm[j409] = fRec361_tmp[vsize + j409];
			}
			for (int j411 = 0; j411 < 4; j411 = j411 + 1) {
				fRec360_perm[j411] = fRec360_tmp[vsize + j411];
			}
			for (int j413 = 0; j413 < 4; j413 = j413 + 1) {
				fRec359_perm[j413] = fRec359_tmp[vsize + j413];
			}
			for (int j379 = 0; j379 < 4; j379 = j379 + 1) {
				fRec358_perm[j379] = fRec358_tmp[vsize + j379];
			}
			for (int j381 = 0; j381 < 4; j381 = j381 + 1) {
				fRec357_perm[j381] = fRec357_tmp[vsize + j381];
			}
			for (int j383 = 0; j383 < 4; j383 = j383 + 1) {
				fRec356_perm[j383] = fRec356_tmp[vsize + j383];
			}
			for (int j373 = 0; j373 < 4; j373 = j373 + 1) {
				fRec355_perm[j373] = fRec355_tmp[vsize + j373];
			}
			for (int j375 = 0; j375 < 4; j375 = j375 + 1) {
				fRec354_perm[j375] = fRec354_tmp[vsize + j375];
			}
			for (int j377 = 0; j377 < 4; j377 = j377 + 1) {
				fRec353_perm[j377] = fRec353_tmp[vsize + j377];
			}
			for (int j343 = 0; j343 < 4; j343 = j343 + 1) {
				fRec352_perm[j343] = fRec352_tmp[vsize + j343];
			}
			for (int j345 = 0; j345 < 4; j345 = j345 + 1) {
				fRec351_perm[j345] = fRec351_tmp[vsize + j345];
			}
			for (int j347 = 0; j347 < 4; j347 = j347 + 1) {
				fRec350_perm[j347] = fRec350_tmp[vsize + j347];
			}
			for (int j337 = 0; j337 < 4; j337 = j337 + 1) {
				fRec349_perm[j337] = fRec349_tmp[vsize + j337];
			}
			for (int j339 = 0; j339 < 4; j339 = j339 + 1) {
				fRec348_perm[j339] = fRec348_tmp[vsize + j339];
			}
			for (int j341 = 0; j341 < 4; j341 = j341 + 1) {
				fRec347_perm[j341] = fRec347_tmp[vsize + j341];
			}
			for (int j283 = 0; j283 < 4; j283 = j283 + 1) {
				fRec346_perm[j283] = fRec346_tmp[vsize + j283];
			}
			for (int j285 = 0; j285 < 4; j285 = j285 + 1) {
				fRec345_perm[j285] = fRec345_tmp[vsize + j285];
			}
			for (int j287 = 0; j287 < 4; j287 = j287 + 1) {
				fRec344_perm[j287] = fRec344_tmp[vsize + j287];
			}
			for (int j289 = 0; j289 < 4; j289 = j289 + 1) {
				fRec343_perm[j289] = fRec343_tmp[vsize + j289];
			}
			for (int j291 = 0; j291 < 4; j291 = j291 + 1) {
				fRec342_perm[j291] = fRec342_tmp[vsize + j291];
			}
			for (int j293 = 0; j293 < 4; j293 = j293 + 1) {
				fRec341_perm[j293] = fRec341_tmp[vsize + j293];
			}
			for (int j295 = 0; j295 < 4; j295 = j295 + 1) {
				fRec340_perm[j295] = fRec340_tmp[vsize + j295];
			}
			for (int j297 = 0; j297 < 4; j297 = j297 + 1) {
				fRec339_perm[j297] = fRec339_tmp[vsize + j297];
			}
			for (int j299 = 0; j299 < 4; j299 = j299 + 1) {
				fRec338_perm[j299] = fRec338_tmp[vsize + j299];
			}
			for (int j301 = 0; j301 < 4; j301 = j301 + 1) {
				fRec337_perm[j301] = fRec337_tmp[vsize + j301];
			}
			for (int j303 = 0; j303 < 4; j303 = j303 + 1) {
				fRec336_perm[j303] = fRec336_tmp[vsize + j303];
			}
			for (int j305 = 0; j305 < 4; j305 = j305 + 1) {
				fRec335_perm[j305] = fRec335_tmp[vsize + j305];
			}
			for (int j307 = 0; j307 < 4; j307 = j307 + 1) {
				fRec334_perm[j307] = fRec334_tmp[vsize + j307];
			}
			for (int j309 = 0; j309 < 4; j309 = j309 + 1) {
				fRec333_perm[j309] = fRec333_tmp[vsize + j309];
			}
			for (int j311 = 0; j311 < 4; j311 = j311 + 1) {
				fRec332_perm[j311] = fRec332_tmp[vsize + j311];
			}
			for (int j313 = 0; j313 < 4; j313 = j313 + 1) {
				fRec331_perm[j313] = fRec331_tmp[vsize + j313];
			}
			for (int j315 = 0; j315 < 4; j315 = j315 + 1) {
				fRec330_perm[j315] = fRec330_tmp[vsize + j315];
			}
			for (int j317 = 0; j317 < 4; j317 = j317 + 1) {
				fRec329_perm[j317] = fRec329_tmp[vsize + j317];
			}
			for (int j319 = 0; j319 < 4; j319 = j319 + 1) {
				fRec328_perm[j319] = fRec328_tmp[vsize + j319];
			}
			for (int j321 = 0; j321 < 4; j321 = j321 + 1) {
				fRec327_perm[j321] = fRec327_tmp[vsize + j321];
			}
			for (int j323 = 0; j323 < 4; j323 = j323 + 1) {
				fRec326_perm[j323] = fRec326_tmp[vsize + j323];
			}
			for (int j241 = 0; j241 < 4; j241 = j241 + 1) {
				fRec325_perm[j241] = fRec325_tmp[vsize + j241];
			}
			for (int j243 = 0; j243 < 4; j243 = j243 + 1) {
				fRec324_perm[j243] = fRec324_tmp[vsize + j243];
			}
			for (int j245 = 0; j245 < 4; j245 = j245 + 1) {
				fRec323_perm[j245] = fRec323_tmp[vsize + j245];
			}
			for (int j247 = 0; j247 < 4; j247 = j247 + 1) {
				fRec322_perm[j247] = fRec322_tmp[vsize + j247];
			}
			for (int j249 = 0; j249 < 4; j249 = j249 + 1) {
				fRec321_perm[j249] = fRec321_tmp[vsize + j249];
			}
			for (int j251 = 0; j251 < 4; j251 = j251 + 1) {
				fRec320_perm[j251] = fRec320_tmp[vsize + j251];
			}
			for (int j253 = 0; j253 < 4; j253 = j253 + 1) {
				fRec319_perm[j253] = fRec319_tmp[vsize + j253];
			}
			for (int j255 = 0; j255 < 4; j255 = j255 + 1) {
				fRec318_perm[j255] = fRec318_tmp[vsize + j255];
			}
			for (int j257 = 0; j257 < 4; j257 = j257 + 1) {
				fRec317_perm[j257] = fRec317_tmp[vsize + j257];
			}
			for (int j259 = 0; j259 < 4; j259 = j259 + 1) {
				fRec316_perm[j259] = fRec316_tmp[vsize + j259];
			}
			for (int j261 = 0; j261 < 4; j261 = j261 + 1) {
				fRec315_perm[j261] = fRec315_tmp[vsize + j261];
			}
			for (int j263 = 0; j263 < 4; j263 = j263 + 1) {
				fRec314_perm[j263] = fRec314_tmp[vsize + j263];
			}
			for (int j265 = 0; j265 < 4; j265 = j265 + 1) {
				fRec313_perm[j265] = fRec313_tmp[vsize + j265];
			}
			for (int j267 = 0; j267 < 4; j267 = j267 + 1) {
				fRec312_perm[j267] = fRec312_tmp[vsize + j267];
			}
			for (int j269 = 0; j269 < 4; j269 = j269 + 1) {
				fRec311_perm[j269] = fRec311_tmp[vsize + j269];
			}
			for (int j271 = 0; j271 < 4; j271 = j271 + 1) {
				fRec310_perm[j271] = fRec310_tmp[vsize + j271];
			}
			for (int j273 = 0; j273 < 4; j273 = j273 + 1) {
				fRec309_perm[j273] = fRec309_tmp[vsize + j273];
			}
			for (int j275 = 0; j275 < 4; j275 = j275 + 1) {
				fRec308_perm[j275] = fRec308_tmp[vsize + j275];
			}
			for (int j277 = 0; j277 < 4; j277 = j277 + 1) {
				fRec307_perm[j277] = fRec307_tmp[vsize + j277];
			}
			for (int j279 = 0; j279 < 4; j279 = j279 + 1) {
				fRec306_perm[j279] = fRec306_tmp[vsize + j279];
			}
			for (int j281 = 0; j281 < 4; j281 = j281 + 1) {
				fRec305_perm[j281] = fRec305_tmp[vsize + j281];
			}
			for (int j325 = 0; j325 < 4; j325 = j325 + 1) {
				fRec300_perm[j325] = fRec300_tmp[vsize + j325];
			}
			for (int j327 = 0; j327 < 4; j327 = j327 + 1) {
				fRec301_perm[j327] = fRec301_tmp[vsize + j327];
			}
			for (int j329 = 0; j329 < 4; j329 = j329 + 1) {
				fRec295_perm[j329] = fRec295_tmp[vsize + j329];
			}
			for (int j331 = 0; j331 < 4; j331 = j331 + 1) {
				fRec296_perm[j331] = fRec296_tmp[vsize + j331];
			}
			for (int j333 = 0; j333 < 4; j333 = j333 + 1) {
				fRec290_perm[j333] = fRec290_tmp[vsize + j333];
			}
			for (int j335 = 0; j335 < 4; j335 = j335 + 1) {
				fRec291_perm[j335] = fRec291_tmp[vsize + j335];
			}
			for (int j349 = 0; j349 < 4; j349 = j349 + 1) {
				fRec285_perm[j349] = fRec285_tmp[vsize + j349];
			}
			for (int j351 = 0; j351 < 4; j351 = j351 + 1) {
				fRec286_perm[j351] = fRec286_tmp[vsize + j351];
			}
			for (int j353 = 0; j353 < 4; j353 = j353 + 1) {
				fRec280_perm[j353] = fRec280_tmp[vsize + j353];
			}
			for (int j355 = 0; j355 < 4; j355 = j355 + 1) {
				fRec281_perm[j355] = fRec281_tmp[vsize + j355];
			}
			for (int j357 = 0; j357 < 4; j357 = j357 + 1) {
				fRec275_perm[j357] = fRec275_tmp[vsize + j357];
			}
			for (int j359 = 0; j359 < 4; j359 = j359 + 1) {
				fRec276_perm[j359] = fRec276_tmp[vsize + j359];
			}
			for (int j361 = 0; j361 < 4; j361 = j361 + 1) {
				fRec270_perm[j361] = fRec270_tmp[vsize + j361];
			}
			for (int j363 = 0; j363 < 4; j363 = j363 + 1) {
				fRec271_perm[j363] = fRec271_tmp[vsize + j363];
			}
			for (int j365 = 0; j365 < 4; j365 = j365 + 1) {
				fRec265_perm[j365] = fRec265_tmp[vsize + j365];
			}
			for (int j367 = 0; j367 < 4; j367 = j367 + 1) {
				fRec266_perm[j367] = fRec266_tmp[vsize + j367];
			}
			for (int j369 = 0; j369 < 4; j369 = j369 + 1) {
				fRec260_perm[j369] = fRec260_tmp[vsize + j369];
			}
			for (int j371 = 0; j371 < 4; j371 = j371 + 1) {
				fRec261_perm[j371] = fRec261_tmp[vsize + j371];
			}
			for (int j385 = 0; j385 < 4; j385 = j385 + 1) {
				fRec255_perm[j385] = fRec255_tmp[vsize + j385];
			}
			for (int j387 = 0; j387 < 4; j387 = j387 + 1) {
				fRec256_perm[j387] = fRec256_tmp[vsize + j387];
			}
			for (int j389 = 0; j389 < 4; j389 = j389 + 1) {
				fRec250_perm[j389] = fRec250_tmp[vsize + j389];
			}
			for (int j391 = 0; j391 < 4; j391 = j391 + 1) {
				fRec251_perm[j391] = fRec251_tmp[vsize + j391];
			}
			for (int j393 = 0; j393 < 4; j393 = j393 + 1) {
				fRec245_perm[j393] = fRec245_tmp[vsize + j393];
			}
			for (int j395 = 0; j395 < 4; j395 = j395 + 1) {
				fRec246_perm[j395] = fRec246_tmp[vsize + j395];
			}
			for (int j397 = 0; j397 < 4; j397 = j397 + 1) {
				fRec240_perm[j397] = fRec240_tmp[vsize + j397];
			}
			for (int j399 = 0; j399 < 4; j399 = j399 + 1) {
				fRec241_perm[j399] = fRec241_tmp[vsize + j399];
			}
			for (int j401 = 0; j401 < 4; j401 = j401 + 1) {
				fRec235_perm[j401] = fRec235_tmp[vsize + j401];
			}
			for (int j403 = 0; j403 < 4; j403 = j403 + 1) {
				fRec236_perm[j403] = fRec236_tmp[vsize + j403];
			}
			for (int j405 = 0; j405 < 4; j405 = j405 + 1) {
				fRec230_perm[j405] = fRec230_tmp[vsize + j405];
			}
			for (int j407 = 0; j407 < 4; j407 = j407 + 1) {
				fRec231_perm[j407] = fRec231_tmp[vsize + j407];
			}
			for (int j421 = 0; j421 < 4; j421 = j421 + 1) {
				fRec225_perm[j421] = fRec225_tmp[vsize + j421];
			}
			for (int j423 = 0; j423 < 4; j423 = j423 + 1) {
				fRec226_perm[j423] = fRec226_tmp[vsize + j423];
			}
			for (int j425 = 0; j425 < 4; j425 = j425 + 1) {
				fRec220_perm[j425] = fRec220_tmp[vsize + j425];
			}
			for (int j427 = 0; j427 < 4; j427 = j427 + 1) {
				fRec221_perm[j427] = fRec221_tmp[vsize + j427];
			}
			for (int j429 = 0; j429 < 4; j429 = j429 + 1) {
				fRec215_perm[j429] = fRec215_tmp[vsize + j429];
			}
			for (int j431 = 0; j431 < 4; j431 = j431 + 1) {
				fRec216_perm[j431] = fRec216_tmp[vsize + j431];
			}
			for (int j433 = 0; j433 < 4; j433 = j433 + 1) {
				fRec210_perm[j433] = fRec210_tmp[vsize + j433];
			}
			for (int j435 = 0; j435 < 4; j435 = j435 + 1) {
				fRec211_perm[j435] = fRec211_tmp[vsize + j435];
			}
			for (int j437 = 0; j437 < 4; j437 = j437 + 1) {
				fRec205_perm[j437] = fRec205_tmp[vsize + j437];
			}
			for (int j439 = 0; j439 < 4; j439 = j439 + 1) {
				fRec206_perm[j439] = fRec206_tmp[vsize + j439];
			}
			for (int j441 = 0; j441 < 4; j441 = j441 + 1) {
				fRec200_perm[j441] = fRec200_tmp[vsize + j441];
			}
			for (int j443 = 0; j443 < 4; j443 = j443 + 1) {
				fRec201_perm[j443] = fRec201_tmp[vsize + j443];
			}
			for (int j457 = 0; j457 < 4; j457 = j457 + 1) {
				fRec195_perm[j457] = fRec195_tmp[vsize + j457];
			}
			for (int j459 = 0; j459 < 4; j459 = j459 + 1) {
				fRec196_perm[j459] = fRec196_tmp[vsize + j459];
			}
			for (int j461 = 0; j461 < 4; j461 = j461 + 1) {
				fRec190_perm[j461] = fRec190_tmp[vsize + j461];
			}
			for (int j463 = 0; j463 < 4; j463 = j463 + 1) {
				fRec191_perm[j463] = fRec191_tmp[vsize + j463];
			}
			for (int j465 = 0; j465 < 4; j465 = j465 + 1) {
				fRec185_perm[j465] = fRec185_tmp[vsize + j465];
			}
			for (int j467 = 0; j467 < 4; j467 = j467 + 1) {
				fRec186_perm[j467] = fRec186_tmp[vsize + j467];
			}
			for (int j469 = 0; j469 < 4; j469 = j469 + 1) {
				fRec180_perm[j469] = fRec180_tmp[vsize + j469];
			}
			for (int j471 = 0; j471 < 4; j471 = j471 + 1) {
				fRec181_perm[j471] = fRec181_tmp[vsize + j471];
			}
			for (int j473 = 0; j473 < 4; j473 = j473 + 1) {
				fRec175_perm[j473] = fRec175_tmp[vsize + j473];
			}
			for (int j475 = 0; j475 < 4; j475 = j475 + 1) {
				fRec176_perm[j475] = fRec176_tmp[vsize + j475];
			}
			for (int j477 = 0; j477 < 4; j477 = j477 + 1) {
				fRec170_perm[j477] = fRec170_tmp[vsize + j477];
			}
			for (int j479 = 0; j479 < 4; j479 = j479 + 1) {
				fRec171_perm[j479] = fRec171_tmp[vsize + j479];
			}
			for (int j493 = 0; j493 < 4; j493 = j493 + 1) {
				fRec165_perm[j493] = fRec165_tmp[vsize + j493];
			}
			for (int j495 = 0; j495 < 4; j495 = j495 + 1) {
				fRec166_perm[j495] = fRec166_tmp[vsize + j495];
			}
			for (int j497 = 0; j497 < 4; j497 = j497 + 1) {
				fRec160_perm[j497] = fRec160_tmp[vsize + j497];
			}
			for (int j499 = 0; j499 < 4; j499 = j499 + 1) {
				fRec161_perm[j499] = fRec161_tmp[vsize + j499];
			}
			for (int j501 = 0; j501 < 4; j501 = j501 + 1) {
				fRec155_perm[j501] = fRec155_tmp[vsize + j501];
			}
			for (int j503 = 0; j503 < 4; j503 = j503 + 1) {
				fRec156_perm[j503] = fRec156_tmp[vsize + j503];
			}
			for (int j505 = 0; j505 < 4; j505 = j505 + 1) {
				fRec150_perm[j505] = fRec150_tmp[vsize + j505];
			}
			for (int j507 = 0; j507 < 4; j507 = j507 + 1) {
				fRec151_perm[j507] = fRec151_tmp[vsize + j507];
			}
			for (int j509 = 0; j509 < 4; j509 = j509 + 1) {
				fRec145_perm[j509] = fRec145_tmp[vsize + j509];
			}
			for (int j511 = 0; j511 < 4; j511 = j511 + 1) {
				fRec146_perm[j511] = fRec146_tmp[vsize + j511];
			}
			for (int j513 = 0; j513 < 4; j513 = j513 + 1) {
				fRec140_perm[j513] = fRec140_tmp[vsize + j513];
			}
			for (int j515 = 0; j515 < 4; j515 = j515 + 1) {
				fRec141_perm[j515] = fRec141_tmp[vsize + j515];
			}
			for (int j529 = 0; j529 < 4; j529 = j529 + 1) {
				fRec135_perm[j529] = fRec135_tmp[vsize + j529];
			}
			for (int j531 = 0; j531 < 4; j531 = j531 + 1) {
				fRec136_perm[j531] = fRec136_tmp[vsize + j531];
			}
			for (int j533 = 0; j533 < 4; j533 = j533 + 1) {
				fRec130_perm[j533] = fRec130_tmp[vsize + j533];
			}
			for (int j535 = 0; j535 < 4; j535 = j535 + 1) {
				fRec131_perm[j535] = fRec131_tmp[vsize + j535];
			}
			for (int j537 = 0; j537 < 4; j537 = j537 + 1) {
				fRec125_perm[j537] = fRec125_tmp[vsize + j537];
			}
			for (int j539 = 0; j539 < 4; j539 = j539 + 1) {
				fRec126_perm[j539] = fRec126_tmp[vsize + j539];
			}
			for (int j541 = 0; j541 < 4; j541 = j541 + 1) {
				fRec120_perm[j541] = fRec120_tmp[vsize + j541];
			}
			for (int j543 = 0; j543 < 4; j543 = j543 + 1) {
				fRec121_perm[j543] = fRec121_tmp[vsize + j543];
			}
			for (int j545 = 0; j545 < 4; j545 = j545 + 1) {
				fRec115_perm[j545] = fRec115_tmp[vsize + j545];
			}
			for (int j547 = 0; j547 < 4; j547 = j547 + 1) {
				fRec116_perm[j547] = fRec116_tmp[vsize + j547];
			}
			for (int j549 = 0; j549 < 4; j549 = j549 + 1) {
				fRec110_perm[j549] = fRec110_tmp[vsize + j549];
			}
			for (int j551 = 0; j551 < 4; j551 = j551 + 1) {
				fRec111_perm[j551] = fRec111_tmp[vsize + j551];
			}
			for (int j553 = 0; j553 < 4; j553 = j553 + 1) {
				fRec105_perm[j553] = fRec105_tmp[vsize + j553];
			}
			for (int j555 = 0; j555 < 4; j555 = j555 + 1) {
				fRec106_perm[j555] = fRec106_tmp[vsize + j555];
			}
			for (int j557 = 0; j557 < 4; j557 = j557 + 1) {
				fRec100_perm[j557] = fRec100_tmp[vsize + j557];
			}
			for (int j559 = 0; j559 < 4; j559 = j559 + 1) {
				fRec101_perm[j559] = fRec101_tmp[vsize + j559];
			}
			for (int j561 = 0; j561 < 4; j561 = j561 + 1) {
				fRec95_perm[j561] = fRec95_tmp[vsize + j561];
			}
			for (int j563 = 0; j563 < 4; j563 = j563 + 1) {
				fRec96_perm[j563] = fRec96_tmp[vsize + j563];
			}
			for (int j233 = 0; j233 < 4; j233 = j233 + 1) {
				fRec94_perm[j233] = fRec94_tmp[vsize + j233];
			}
			for (int j235 = 0; j235 < 4; j235 = j235 + 1) {
				fRec93_perm[j235] = fRec93_tmp[vsize + j235];
			}
			for (int j237 = 0; j237 < 4; j237 = j237 + 1) {
				fRec92_perm[j237] = fRec92_tmp[vsize + j237];
			}
			for (int j239 = 0; j239 < 4; j239 = j239 + 1) {
				fRec91_perm[j239] = fRec91_tmp[vsize + j239];
			}
			for (int j225 = 0; j225 < 4; j225 = j225 + 1) {
				fRec90_perm[j225] = fRec90_tmp[vsize + j225];
			}
			for (int j227 = 0; j227 < 4; j227 = j227 + 1) {
				fRec89_perm[j227] = fRec89_tmp[vsize + j227];
			}
			for (int j229 = 0; j229 < 4; j229 = j229 + 1) {
				fRec88_perm[j229] = fRec88_tmp[vsize + j229];
			}
			for (int j231 = 0; j231 < 4; j231 = j231 + 1) {
				fRec87_perm[j231] = fRec87_tmp[vsize + j231];
			}
			fRec85_idx_save = vsize;
			for (int j221 = 0; j221 < 4; j221 = j221 + 1) {
				fRec84_perm[j221] = fRec84_tmp[vsize + j221];
			}
			fRec83_idx_save = vsize;
			for (int j219 = 0; j219 < 4; j219 = j219 + 1) {
				fRec82_perm[j219] = fRec82_tmp[vsize + j219];
			}
			for (int j201 = 0; j201 < 4; j201 = j201 + 1) {
				fYec89_perm[j201] = fYec89_tmp[vsize + j201];
			}
			for (int j203 = 0; j203 < 4; j203 = j203 + 1) {
				fYec90_perm[j203] = fYec90_tmp[vsize + j203];
			}
			for (int j205 = 0; j205 < 8; j205 = j205 + 1) {
				fYec91_perm[j205] = fYec91_tmp[vsize + j205];
			}
			for (int j207 = 0; j207 < 16; j207 = j207 + 1) {
				fYec92_perm[j207] = fYec92_tmp[vsize + j207];
			}
			fYec93_idx_save = vsize;
			fYec94_idx_save = vsize;
			fYec95_idx_save = vsize;
			fYec96_idx_save = vsize;
			fYec97_idx_save = vsize;
			fYec98_idx_save = vsize;
			fYec99_idx_save = vsize;
			fYec100_idx_save = vsize;
			fYec101_idx_save = vsize;
			fYec102_idx_save = vsize;
			fYec103_idx_save = vsize;
			fYec104_idx_save = vsize;
			fYec105_idx_save = vsize;
			for (int j193 = 0; j193 < 4; j193 = j193 + 1) {
				fYec72_perm[j193] = fYec72_tmp[vsize + j193];
			}
			for (int j195 = 0; j195 < 4; j195 = j195 + 1) {
				fYec73_perm[j195] = fYec73_tmp[vsize + j195];
			}
			for (int j197 = 0; j197 < 8; j197 = j197 + 1) {
				fYec74_perm[j197] = fYec74_tmp[vsize + j197];
			}
			for (int j199 = 0; j199 < 16; j199 = j199 + 1) {
				fYec75_perm[j199] = fYec75_tmp[vsize + j199];
			}
			fYec76_idx_save = vsize;
			fYec77_idx_save = vsize;
			fYec78_idx_save = vsize;
			fYec79_idx_save = vsize;
			fYec80_idx_save = vsize;
			fYec81_idx_save = vsize;
			fYec82_idx_save = vsize;
			fYec83_idx_save = vsize;
			fYec84_idx_save = vsize;
			fYec85_idx_save = vsize;
			fYec86_idx_save = vsize;
			fYec87_idx_save = vsize;
			fYec88_idx_save = vsize;
			for (int j187 = 0; j187 < 4; j187 = j187 + 1) {
				fYec71_perm[j187] = fYec71_tmp[vsize + j187];
			}
			for (int j181 = 0; j181 < 4; j181 = j181 + 1) {
				fYec70_perm[j181] = fYec70_tmp[vsize + j181];
			}
			for (int j183 = 0; j183 < 4; j183 = j183 + 1) {
				fRec78_perm[j183] = fRec78_tmp[vsize + j183];
			}
			for (int j185 = 0; j185 < 4; j185 = j185 + 1) {
				fRec77_perm[j185] = fRec77_tmp[vsize + j185];
			}
			for (int j189 = 0; j189 < 4; j189 = j189 + 1) {
				fRec76_perm[j189] = fRec76_tmp[vsize + j189];
			}
			for (int j191 = 0; j191 < 4; j191 = j191 + 1) {
				fRec75_perm[j191] = fRec75_tmp[vsize + j191];
			}
			for (int j175 = 0; j175 < 4; j175 = j175 + 1) {
				fYec69_perm[j175] = fYec69_tmp[vsize + j175];
			}
			for (int j169 = 0; j169 < 4; j169 = j169 + 1) {
				fYec68_perm[j169] = fYec68_tmp[vsize + j169];
			}
			for (int j171 = 0; j171 < 4; j171 = j171 + 1) {
				fRec74_perm[j171] = fRec74_tmp[vsize + j171];
			}
			for (int j173 = 0; j173 < 4; j173 = j173 + 1) {
				fRec73_perm[j173] = fRec73_tmp[vsize + j173];
			}
			for (int j177 = 0; j177 < 4; j177 = j177 + 1) {
				fRec72_perm[j177] = fRec72_tmp[vsize + j177];
			}
			for (int j179 = 0; j179 < 4; j179 = j179 + 1) {
				fRec71_perm[j179] = fRec71_tmp[vsize + j179];
			}
			for (int j209 = 0; j209 < 4; j209 = j209 + 1) {
				fRec10_perm[j209] = fRec10_tmp[vsize + j209];
			}
			for (int j211 = 0; j211 < 4; j211 = j211 + 1) {
				fRec9_perm[j211] = fRec9_tmp[vsize + j211];
			}
			for (int j737 = 0; j737 < 4; j737 = j737 + 1) {
				fRec5_perm[j737] = fRec5_tmp[vsize + j737];
			}
			for (int j739 = 0; j739 < 4; j739 = j739 + 1) {
				fRec6_perm[j739] = fRec6_tmp[vsize + j739];
			}
			for (int j751 = 0; j751 < 4; j751 = j751 + 1) {
				fRec3_perm[j751] = fRec3_tmp[vsize + j751];
			}
			for (int j753 = 0; j753 < 4; j753 = j753 + 1) {
				fRec4_perm[j753] = fRec4_tmp[vsize + j753];
			}
			for (int j755 = 0; j755 < 4; j755 = j755 + 1) {
				fRec1_perm[j755] = fRec1_tmp[vsize + j755];
			}
			for (int j757 = 0; j757 < 4; j757 = j757 + 1) {
				fRec2_perm[j757] = fRec2_tmp[vsize + j757];
			}
			/* Vectorizable loop 182 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec799[i] = 1.0f - fRec0[i];
			}
			/* Vectorizable loop 183 */
			/* Pre code */
			for (int j758 = 0; j758 < 4; j758 = j758 + 1) {
				fYec106_tmp[j758] = fYec106_perm[j758];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec106[i] = float(input0[i]) * fRec0[i] + fRec1[i] * fZec799[i];
			}
			/* Post code */
			for (int j759 = 0; j759 < 4; j759 = j759 + 1) {
				fYec106_perm[j759] = fYec106_tmp[vsize + j759];
			}
			/* Vectorizable loop 184 */
			/* Pre code */
			for (int j774 = 0; j774 < 4; j774 = j774 + 1) {
				fYec109_tmp[j774] = fYec109_perm[j774];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec109[i] = float(input1[i]) * fRec0[i] + fRec2[i] * fZec799[i];
			}
			/* Post code */
			for (int j775 = 0; j775 < 4; j775 = j775 + 1) {
				fYec109_perm[j775] = fYec109_tmp[vsize + j775];
			}
			/* Recursive loop 185 */
			/* Pre code */
			for (int j762 = 0; j762 < 4; j762 = j762 + 1) {
				fYec107_tmp[j762] = fYec107_perm[j762];
			}
			for (int j764 = 0; j764 < 4; j764 = j764 + 1) {
				fRec606_tmp[j764] = fRec606_perm[j764];
			}
			for (int j766 = 0; j766 < 4; j766 = j766 + 1) {
				fRec605_tmp[j766] = fRec605_perm[j766];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec107[i] = 0.0f - fConst8 * (fConst9 * fRec605[i - 1] - fConst10 * fYec106[i - 1]);
				fRec606[i] = fYec107[i - 1] + fConst8 * (fConst11 * fYec106[i] - 2.0f * (fConst13 * fRec606[i - 1] - fConst14 * fYec106[i - 1]));
				fRec605[i] = fRec606[i];
			}
			/* Post code */
			for (int j763 = 0; j763 < 4; j763 = j763 + 1) {
				fYec107_perm[j763] = fYec107_tmp[vsize + j763];
			}
			for (int j765 = 0; j765 < 4; j765 = j765 + 1) {
				fRec606_perm[j765] = fRec606_tmp[vsize + j765];
			}
			for (int j767 = 0; j767 < 4; j767 = j767 + 1) {
				fRec605_perm[j767] = fRec605_tmp[vsize + j767];
			}
			/* Recursive loop 186 */
			/* Pre code */
			for (int j776 = 0; j776 < 4; j776 = j776 + 1) {
				fYec110_tmp[j776] = fYec110_perm[j776];
			}
			for (int j778 = 0; j778 < 4; j778 = j778 + 1) {
				fRec610_tmp[j778] = fRec610_perm[j778];
			}
			for (int j780 = 0; j780 < 4; j780 = j780 + 1) {
				fRec609_tmp[j780] = fRec609_perm[j780];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec110[i] = 0.0f - fConst8 * (fConst9 * fRec609[i - 1] - fConst10 * fYec109[i - 1]);
				fRec610[i] = fYec110[i - 1] + fConst8 * (fConst11 * fYec109[i] - 2.0f * (fConst13 * fRec610[i - 1] - fConst14 * fYec109[i - 1]));
				fRec609[i] = fRec610[i];
			}
			/* Post code */
			for (int j777 = 0; j777 < 4; j777 = j777 + 1) {
				fYec110_perm[j777] = fYec110_tmp[vsize + j777];
			}
			for (int j779 = 0; j779 < 4; j779 = j779 + 1) {
				fRec610_perm[j779] = fRec610_tmp[vsize + j779];
			}
			for (int j781 = 0; j781 < 4; j781 = j781 + 1) {
				fRec609_perm[j781] = fRec609_tmp[vsize + j781];
			}
			/* Recursive loop 187 */
			/* Pre code */
			for (int j768 = 0; j768 < 4; j768 = j768 + 1) {
				fYec108_tmp[j768] = fYec108_perm[j768];
			}
			for (int j770 = 0; j770 < 4; j770 = j770 + 1) {
				fRec604_tmp[j770] = fRec604_perm[j770];
			}
			for (int j772 = 0; j772 < 4; j772 = j772 + 1) {
				fRec603_tmp[j772] = fRec603_perm[j772];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec108[i] = 0.500327051f * fRec605[i - 1] - fConst20 * fRec603[i - 1];
				fRec604[i] = fConst18 * fRec605[i - 1] + fConst19 * (fYec108[i - 1] - fConst21 * fRec604[i - 1] + 0.500327051f * fRec605[i]);
				fRec603[i] = fRec604[i];
			}
			/* Post code */
			for (int j769 = 0; j769 < 4; j769 = j769 + 1) {
				fYec108_perm[j769] = fYec108_tmp[vsize + j769];
			}
			for (int j771 = 0; j771 < 4; j771 = j771 + 1) {
				fRec604_perm[j771] = fRec604_tmp[vsize + j771];
			}
			for (int j773 = 0; j773 < 4; j773 = j773 + 1) {
				fRec603_perm[j773] = fRec603_tmp[vsize + j773];
			}
			/* Recursive loop 188 */
			/* Pre code */
			for (int j782 = 0; j782 < 4; j782 = j782 + 1) {
				fYec111_tmp[j782] = fYec111_perm[j782];
			}
			for (int j784 = 0; j784 < 4; j784 = j784 + 1) {
				fRec608_tmp[j784] = fRec608_perm[j784];
			}
			for (int j786 = 0; j786 < 4; j786 = j786 + 1) {
				fRec607_tmp[j786] = fRec607_perm[j786];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec111[i] = 0.500327051f * fRec609[i - 1] - fConst20 * fRec607[i - 1];
				fRec608[i] = fConst18 * fRec609[i - 1] + fConst19 * (fYec111[i - 1] - fConst21 * fRec608[i - 1] + 0.500327051f * fRec609[i]);
				fRec607[i] = fRec608[i];
			}
			/* Post code */
			for (int j783 = 0; j783 < 4; j783 = j783 + 1) {
				fYec111_perm[j783] = fYec111_tmp[vsize + j783];
			}
			for (int j785 = 0; j785 < 4; j785 = j785 + 1) {
				fRec608_perm[j785] = fRec608_tmp[vsize + j785];
			}
			for (int j787 = 0; j787 < 4; j787 = j787 + 1) {
				fRec607_perm[j787] = fRec607_tmp[vsize + j787];
			}
			/* Vectorizable loop 189 */
			/* Pre code */
			for (int j788 = 0; j788 < 4; j788 = j788 + 1) {
				fYec112_tmp[j788] = fYec112_perm[j788];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec112[i] = mydsp_faustpower2_f(fRec603[i]);
			}
			/* Post code */
			for (int j789 = 0; j789 < 4; j789 = j789 + 1) {
				fYec112_perm[j789] = fYec112_tmp[vsize + j789];
			}
			/* Vectorizable loop 190 */
			/* Pre code */
			for (int j796 = 0; j796 < 4; j796 = j796 + 1) {
				fYec132_tmp[j796] = fYec132_perm[j796];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec132[i] = mydsp_faustpower2_f(fRec607[i]);
			}
			/* Post code */
			for (int j797 = 0; j797 < 4; j797 = j797 + 1) {
				fYec132_perm[j797] = fYec132_tmp[vsize + j797];
			}
			/* Vectorizable loop 191 */
			/* Pre code */
			for (int j790 = 0; j790 < 4; j790 = j790 + 1) {
				fYec113_tmp[j790] = fYec113_perm[j790];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec113[i] = fYec112[i] + fYec112[i - 1];
			}
			/* Post code */
			for (int j791 = 0; j791 < 4; j791 = j791 + 1) {
				fYec113_perm[j791] = fYec113_tmp[vsize + j791];
			}
			/* Vectorizable loop 192 */
			/* Pre code */
			for (int j798 = 0; j798 < 4; j798 = j798 + 1) {
				fYec133_tmp[j798] = fYec133_perm[j798];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec133[i] = fYec132[i] + fYec132[i - 1];
			}
			/* Post code */
			for (int j799 = 0; j799 < 4; j799 = j799 + 1) {
				fYec133_perm[j799] = fYec133_tmp[vsize + j799];
			}
			/* Vectorizable loop 193 */
			/* Pre code */
			for (int j792 = 0; j792 < 8; j792 = j792 + 1) {
				fYec114_tmp[j792] = fYec114_perm[j792];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec114[i] = fYec113[i] + fYec113[i - 2];
			}
			/* Post code */
			for (int j793 = 0; j793 < 8; j793 = j793 + 1) {
				fYec114_perm[j793] = fYec114_tmp[vsize + j793];
			}
			/* Vectorizable loop 194 */
			/* Pre code */
			for (int j800 = 0; j800 < 8; j800 = j800 + 1) {
				fYec134_tmp[j800] = fYec134_perm[j800];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec134[i] = fYec133[i] + fYec133[i - 2];
			}
			/* Post code */
			for (int j801 = 0; j801 < 8; j801 = j801 + 1) {
				fYec134_perm[j801] = fYec134_tmp[vsize + j801];
			}
			/* Vectorizable loop 195 */
			/* Pre code */
			for (int j794 = 0; j794 < 16; j794 = j794 + 1) {
				fYec115_tmp[j794] = fYec115_perm[j794];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec115[i] = fYec114[i] + fYec114[i - 4];
			}
			/* Post code */
			for (int j795 = 0; j795 < 16; j795 = j795 + 1) {
				fYec115_perm[j795] = fYec115_tmp[vsize + j795];
			}
			/* Vectorizable loop 196 */
			/* Pre code */
			for (int j802 = 0; j802 < 16; j802 = j802 + 1) {
				fYec135_tmp[j802] = fYec135_perm[j802];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec135[i] = fYec134[i] + fYec134[i - 4];
			}
			/* Post code */
			for (int j803 = 0; j803 < 16; j803 = j803 + 1) {
				fYec135_perm[j803] = fYec135_tmp[vsize + j803];
			}
			/* Vectorizable loop 197 */
			/* Pre code */
			fYec116_idx = (fYec116_idx + fYec116_idx_save) & 63;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec116[(i + fYec116_idx) & 63] = fYec115[i] + fYec115[i - 8];
			}
			/* Post code */
			fYec116_idx_save = vsize;
			/* Vectorizable loop 198 */
			/* Pre code */
			fYec136_idx = (fYec136_idx + fYec136_idx_save) & 63;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec136[(i + fYec136_idx) & 63] = fYec135[i] + fYec135[i - 8];
			}
			/* Post code */
			fYec136_idx_save = vsize;
			/* Vectorizable loop 199 */
			/* Pre code */
			fYec117_idx = (fYec117_idx + fYec117_idx_save) & 127;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec117[(i + fYec117_idx) & 127] = fYec116[(i + fYec116_idx) & 63] + fYec116[((i + fYec116_idx) - 16) & 63];
			}
			/* Post code */
			fYec117_idx_save = vsize;
			/* Vectorizable loop 200 */
			/* Pre code */
			fYec137_idx = (fYec137_idx + fYec137_idx_save) & 127;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec137[(i + fYec137_idx) & 127] = fYec136[(i + fYec136_idx) & 63] + fYec136[((i + fYec136_idx) - 16) & 63];
			}
			/* Post code */
			fYec137_idx_save = vsize;
			/* Vectorizable loop 201 */
			/* Pre code */
			fYec118_idx = (fYec118_idx + fYec118_idx_save) & 255;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec118[(i + fYec118_idx) & 255] = fYec117[(i + fYec117_idx) & 127] + fYec117[((i + fYec117_idx) - 32) & 127];
			}
			/* Post code */
			fYec118_idx_save = vsize;
			/* Vectorizable loop 202 */
			/* Pre code */
			fYec138_idx = (fYec138_idx + fYec138_idx_save) & 255;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec138[(i + fYec138_idx) & 255] = fYec137[(i + fYec137_idx) & 127] + fYec137[((i + fYec137_idx) - 32) & 127];
			}
			/* Post code */
			fYec138_idx_save = vsize;
			/* Vectorizable loop 203 */
			/* Pre code */
			fYec119_idx = (fYec119_idx + fYec119_idx_save) & 511;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec119[(i + fYec119_idx) & 511] = fYec118[(i + fYec118_idx) & 255] + fYec118[((i + fYec118_idx) - 64) & 255];
			}
			/* Post code */
			fYec119_idx_save = vsize;
			/* Vectorizable loop 204 */
			/* Pre code */
			fYec139_idx = (fYec139_idx + fYec139_idx_save) & 511;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec139[(i + fYec139_idx) & 511] = fYec138[(i + fYec138_idx) & 255] + fYec138[((i + fYec138_idx) - 64) & 255];
			}
			/* Post code */
			fYec139_idx_save = vsize;
			/* Vectorizable loop 205 */
			/* Pre code */
			fYec120_idx = (fYec120_idx + fYec120_idx_save) & 1023;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec120[(i + fYec120_idx) & 1023] = fYec119[(i + fYec119_idx) & 511] + fYec119[((i + fYec119_idx) - 128) & 511];
			}
			/* Post code */
			fYec120_idx_save = vsize;
			/* Vectorizable loop 206 */
			/* Pre code */
			fYec140_idx = (fYec140_idx + fYec140_idx_save) & 1023;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec140[(i + fYec140_idx) & 1023] = fYec139[(i + fYec139_idx) & 511] + fYec139[((i + fYec139_idx) - 128) & 511];
			}
			/* Post code */
			fYec140_idx_save = vsize;
			/* Vectorizable loop 207 */
			/* Pre code */
			fYec121_idx = (fYec121_idx + fYec121_idx_save) & 2047;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec121[(i + fYec121_idx) & 2047] = fYec120[(i + fYec120_idx) & 1023] + fYec120[((i + fYec120_idx) - 256) & 1023];
			}
			/* Post code */
			fYec121_idx_save = vsize;
			/* Vectorizable loop 208 */
			/* Pre code */
			fYec141_idx = (fYec141_idx + fYec141_idx_save) & 2047;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec141[(i + fYec141_idx) & 2047] = fYec140[(i + fYec140_idx) & 1023] + fYec140[((i + fYec140_idx) - 256) & 1023];
			}
			/* Post code */
			fYec141_idx_save = vsize;
			/* Vectorizable loop 209 */
			/* Pre code */
			fYec122_idx = (fYec122_idx + fYec122_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec122[(i + fYec122_idx) & 4095] = fYec121[(i + fYec121_idx) & 2047] + fYec121[((i + fYec121_idx) - 512) & 2047];
			}
			/* Post code */
			fYec122_idx_save = vsize;
			/* Vectorizable loop 210 */
			/* Pre code */
			fYec142_idx = (fYec142_idx + fYec142_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec142[(i + fYec142_idx) & 4095] = fYec141[(i + fYec141_idx) & 2047] + fYec141[((i + fYec141_idx) - 512) & 2047];
			}
			/* Post code */
			fYec142_idx_save = vsize;
			/* Vectorizable loop 211 */
			/* Pre code */
			fYec123_idx = (fYec123_idx + fYec123_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec123[(i + fYec123_idx) & 8191] = fYec122[(i + fYec122_idx) & 4095] + fYec122[((i + fYec122_idx) - 1024) & 4095];
			}
			/* Post code */
			fYec123_idx_save = vsize;
			/* Vectorizable loop 212 */
			/* Pre code */
			fYec143_idx = (fYec143_idx + fYec143_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec143[(i + fYec143_idx) & 8191] = fYec142[(i + fYec142_idx) & 4095] + fYec142[((i + fYec142_idx) - 1024) & 4095];
			}
			/* Post code */
			fYec143_idx_save = vsize;
			/* Vectorizable loop 213 */
			/* Pre code */
			fYec124_idx = (fYec124_idx + fYec124_idx_save) & 16383;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec124[(i + fYec124_idx) & 16383] = fYec123[(i + fYec123_idx) & 8191] + fYec123[((i + fYec123_idx) - 2048) & 8191];
			}
			/* Post code */
			fYec124_idx_save = vsize;
			/* Vectorizable loop 214 */
			/* Pre code */
			fYec144_idx = (fYec144_idx + fYec144_idx_save) & 16383;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec144[(i + fYec144_idx) & 16383] = fYec143[(i + fYec143_idx) & 8191] + fYec143[((i + fYec143_idx) - 2048) & 8191];
			}
			/* Post code */
			fYec144_idx_save = vsize;
			/* Vectorizable loop 215 */
			/* Pre code */
			fYec125_idx = (fYec125_idx + fYec125_idx_save) & 32767;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec125[(i + fYec125_idx) & 32767] = fYec124[(i + fYec124_idx) & 16383] + fYec124[((i + fYec124_idx) - 4096) & 16383];
			}
			/* Post code */
			fYec125_idx_save = vsize;
			/* Vectorizable loop 216 */
			/* Pre code */
			fYec145_idx = (fYec145_idx + fYec145_idx_save) & 32767;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec145[(i + fYec145_idx) & 32767] = fYec144[(i + fYec144_idx) & 16383] + fYec144[((i + fYec144_idx) - 4096) & 16383];
			}
			/* Post code */
			fYec145_idx_save = vsize;
			/* Vectorizable loop 217 */
			/* Pre code */
			fYec126_idx = (fYec126_idx + fYec126_idx_save) & 65535;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec126[(i + fYec126_idx) & 65535] = fYec125[(i + fYec125_idx) & 32767] + fYec125[((i + fYec125_idx) - 8192) & 32767];
			}
			/* Post code */
			fYec126_idx_save = vsize;
			/* Vectorizable loop 218 */
			/* Pre code */
			fYec146_idx = (fYec146_idx + fYec146_idx_save) & 65535;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec146[(i + fYec146_idx) & 65535] = fYec145[(i + fYec145_idx) & 32767] + fYec145[((i + fYec145_idx) - 8192) & 32767];
			}
			/* Post code */
			fYec146_idx_save = vsize;
			/* Vectorizable loop 219 */
			/* Pre code */
			fYec127_idx = (fYec127_idx + fYec127_idx_save) & 131071;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec127[(i + fYec127_idx) & 131071] = fYec126[(i + fYec126_idx) & 65535] + fYec126[((i + fYec126_idx) - 16384) & 65535];
			}
			/* Post code */
			fYec127_idx_save = vsize;
			/* Vectorizable loop 220 */
			/* Pre code */
			fYec147_idx = (fYec147_idx + fYec147_idx_save) & 131071;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec147[(i + fYec147_idx) & 131071] = fYec146[(i + fYec146_idx) & 65535] + fYec146[((i + fYec146_idx) - 16384) & 65535];
			}
			/* Post code */
			fYec147_idx_save = vsize;
			/* Vectorizable loop 221 */
			/* Pre code */
			fYec128_idx = (fYec128_idx + fYec128_idx_save) & 262143;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec128[(i + fYec128_idx) & 262143] = fYec127[(i + fYec127_idx) & 131071] + fYec127[((i + fYec127_idx) - 32768) & 131071];
			}
			/* Post code */
			fYec128_idx_save = vsize;
			/* Vectorizable loop 222 */
			/* Pre code */
			fYec148_idx = (fYec148_idx + fYec148_idx_save) & 262143;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec148[(i + fYec148_idx) & 262143] = fYec147[(i + fYec147_idx) & 131071] + fYec147[((i + fYec147_idx) - 32768) & 131071];
			}
			/* Post code */
			fYec148_idx_save = vsize;
			/* Vectorizable loop 223 */
			/* Pre code */
			fYec129_idx = (fYec129_idx + fYec129_idx_save) & 524287;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec129[(i + fYec129_idx) & 524287] = fYec128[(i + fYec128_idx) & 262143] + fYec128[((i + fYec128_idx) - 65536) & 262143];
			}
			/* Post code */
			fYec129_idx_save = vsize;
			/* Vectorizable loop 224 */
			/* Pre code */
			fYec149_idx = (fYec149_idx + fYec149_idx_save) & 524287;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec149[(i + fYec149_idx) & 524287] = fYec148[(i + fYec148_idx) & 262143] + fYec148[((i + fYec148_idx) - 65536) & 262143];
			}
			/* Post code */
			fYec149_idx_save = vsize;
			/* Vectorizable loop 225 */
			/* Pre code */
			fYec130_idx = (fYec130_idx + fYec130_idx_save) & 1048575;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec130[(i + fYec130_idx) & 1048575] = fYec129[(i + fYec129_idx) & 524287] + fYec129[((i + fYec129_idx) - 131072) & 524287];
			}
			/* Post code */
			fYec130_idx_save = vsize;
			/* Vectorizable loop 226 */
			/* Pre code */
			fYec150_idx = (fYec150_idx + fYec150_idx_save) & 1048575;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec150[(i + fYec150_idx) & 1048575] = fYec149[(i + fYec149_idx) & 524287] + fYec149[((i + fYec149_idx) - 131072) & 524287];
			}
			/* Post code */
			fYec150_idx_save = vsize;
			/* Vectorizable loop 227 */
			/* Pre code */
			fYec131_idx = (fYec131_idx + fYec131_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec131[(i + fYec131_idx) & 2097151] = fYec130[(i + fYec130_idx) & 1048575] + fYec130[((i + fYec130_idx) - 262144) & 1048575];
			}
			/* Post code */
			fYec131_idx_save = vsize;
			/* Vectorizable loop 228 */
			/* Pre code */
			fYec151_idx = (fYec151_idx + fYec151_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec151[(i + fYec151_idx) & 2097151] = fYec150[(i + fYec150_idx) & 1048575] + fYec150[((i + fYec150_idx) - 262144) & 1048575];
			}
			/* Post code */
			fYec151_idx_save = vsize;
			/* Vectorizable loop 229 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				float fElse206 = fYec131[((i + fYec131_idx) - iConst61) & 2097151];
				float fElse207 = fYec130[((i + fYec130_idx) - iConst63) & 1048575];
				float fElse208 = fYec129[((i + fYec129_idx) - iConst65) & 524287];
				float fElse209 = fYec128[((i + fYec128_idx) - iConst67) & 262143];
				float fElse210 = fYec127[((i + fYec127_idx) - iConst69) & 131071];
				float fElse211 = fYec126[((i + fYec126_idx) - iConst71) & 65535];
				float fElse212 = fYec125[((i + fYec125_idx) - iConst73) & 32767];
				float fElse213 = fYec124[((i + fYec124_idx) - iConst75) & 16383];
				float fElse214 = fYec123[((i + fYec123_idx) - iConst77) & 8191];
				float fElse215 = fYec122[((i + fYec122_idx) - iConst79) & 4095];
				float fElse216 = fYec121[((i + fYec121_idx) - iConst81) & 2047];
				float fElse217 = fYec120[((i + fYec120_idx) - iConst83) & 1023];
				float fElse218 = fYec119[((i + fYec119_idx) - iConst85) & 511];
				float fElse219 = fYec118[((i + fYec118_idx) - iConst87) & 255];
				float fElse220 = fYec117[((i + fYec117_idx) - iConst89) & 127];
				float fElse221 = fYec116[((i + fYec116_idx) - iConst91) & 63];
				float fElse222 = fYec115[i - iConst93];
				float fElse223 = fYec114[i - iConst95];
				float fElse224 = fYec112[i];
				float fElse225 = fYec113[i - iConst96];
				float fElse226 = fYec151[((i + fYec151_idx) - iConst61) & 2097151];
				float fElse227 = fYec150[((i + fYec150_idx) - iConst63) & 1048575];
				float fElse228 = fYec149[((i + fYec149_idx) - iConst65) & 524287];
				float fElse229 = fYec148[((i + fYec148_idx) - iConst67) & 262143];
				float fElse230 = fYec147[((i + fYec147_idx) - iConst69) & 131071];
				float fElse231 = fYec146[((i + fYec146_idx) - iConst71) & 65535];
				float fElse232 = fYec145[((i + fYec145_idx) - iConst73) & 32767];
				float fElse233 = fYec144[((i + fYec144_idx) - iConst75) & 16383];
				float fElse234 = fYec143[((i + fYec143_idx) - iConst77) & 8191];
				float fElse235 = fYec142[((i + fYec142_idx) - iConst79) & 4095];
				float fElse236 = fYec141[((i + fYec141_idx) - iConst81) & 2047];
				float fElse237 = fYec140[((i + fYec140_idx) - iConst83) & 1023];
				float fElse238 = fYec139[((i + fYec139_idx) - iConst85) & 511];
				float fElse239 = fYec138[((i + fYec138_idx) - iConst87) & 255];
				float fElse240 = fYec137[((i + fYec137_idx) - iConst89) & 127];
				float fElse241 = fYec136[((i + fYec136_idx) - iConst91) & 63];
				float fElse242 = fYec135[i - iConst93];
				float fElse243 = fYec134[i - iConst95];
				float fElse244 = fYec132[i];
				float fElse245 = fYec133[i - iConst96];
				fVbargraph27 = FAUSTFLOAT(4.34294462f * std::log(std::max<float>(9.99999996e-13f, fConst23 * (((iConst24) ? fElse206 : 0.0f) + ((iConst62) ? fElse207 : 0.0f) + ((iConst64) ? fElse208 : 0.0f) + ((iConst66) ? fElse209 : 0.0f) + ((iConst68) ? fElse210 : 0.0f) + ((iConst70) ? fElse211 : 0.0f) + ((iConst72) ? fElse212 : 0.0f) + ((iConst74) ? fElse213 : 0.0f) + ((iConst76) ? fElse214 : 0.0f) + ((iConst78) ? fElse215 : 0.0f) + ((iConst80) ? fElse216 : 0.0f) + ((iConst82) ? fElse217 : 0.0f) + ((iConst84) ? fElse218 : 0.0f) + ((iConst86) ? fElse219 : 0.0f) + ((iConst88) ? fElse220 : 0.0f) + ((iConst90) ? fElse221 : 0.0f) + ((iConst92) ? fElse222 : 0.0f) + ((iConst94) ? fElse223 : 0.0f) + ((iConst96) ? fElse224 : 0.0f) + ((iConst97) ? fElse225 : 0.0f) + ((iConst24) ? fElse226 : 0.0f) + ((iConst62) ? fElse227 : 0.0f) + ((iConst64) ? fElse228 : 0.0f) + ((iConst66) ? fElse229 : 0.0f) + ((iConst68) ? fElse230 : 0.0f) + ((iConst70) ? fElse231 : 0.0f) + ((iConst72) ? fElse232 : 0.0f) + ((iConst74) ? fElse233 : 0.0f) + ((iConst76) ? fElse234 : 0.0f) + ((iConst78) ? fElse235 : 0.0f) + ((iConst80) ? fElse236 : 0.0f) + ((iConst82) ? fElse237 : 0.0f) + ((iConst84) ? fElse238 : 0.0f) + ((iConst86) ? fElse239 : 0.0f) + ((iConst88) ? fElse240 : 0.0f) + ((iConst90) ? fElse241 : 0.0f) + ((iConst92) ? fElse242 : 0.0f) + ((iConst94) ? fElse243 : 0.0f) + ((iConst96) ? fElse244 : 0.0f) + ((iConst97) ? fElse245 : 0.0f)))) + -0.690999985f);
				fZec800[i] = fYec109[i];
			}
			/* Recursive loop 230 */
			/* Pre code */
			for (int j760 = 0; j760 < 4; j760 = j760 + 1) {
				fRec602_tmp[j760] = fRec602_perm[j760];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec602[i] = std::max<float>(fRec602[i - 1] - fConst3, std::min<float>(10.0f, 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::max<float>(0.000316227757f, std::fabs(fYec106[i]))))));
			}
			/* Post code */
			for (int j761 = 0; j761 < 4; j761 = j761 + 1) {
				fRec602_perm[j761] = fRec602_tmp[vsize + j761];
			}
			/* Recursive loop 231 */
			/* Pre code */
			for (int j804 = 0; j804 < 4; j804 = j804 + 1) {
				fRec611_tmp[j804] = fRec611_perm[j804];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec611[i] = std::max<float>(fRec611[i - 1] - fConst3, std::min<float>(10.0f, 20.0f * std::log10(std::max<float>(1.17549435e-38f, std::max<float>(0.000316227757f, std::fabs(fZec800[i]))))));
			}
			/* Post code */
			for (int j805 = 0; j805 < 4; j805 = j805 + 1) {
				fRec611_perm[j805] = fRec611_tmp[vsize + j805];
			}
			/* Vectorizable loop 232 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph26 = FAUSTFLOAT(fRec602[i]);
				output0[i] = FAUSTFLOAT(fYec106[i]);
			}
			/* Vectorizable loop 233 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph28 = FAUSTFLOAT(fRec611[i]);
				output1[i] = FAUSTFLOAT(fZec800[i]);
			}
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



// --------------------------------------------------------------------------------------------------------------------

START_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

class FaustGeneratedPlugin : public Plugin
{
protected:
    ScopedPointer<mydsp> dsp;

public:
    FaustGeneratedPlugin(const uint32_t extraParameters = 0,
                         const uint32_t extraPrograms = 0,
                         const uint32_t extraStates = 0)
        : Plugin(kParameterCount + extraParameters, kProgramCount + extraPrograms, kStateCount + extraStates)
    {
        dsp = new mydsp;
        dsp->init(getSampleRate());

        // passive controls are only updated on first run, make sure they have valid values now
        dsp->fVbargraph0 = 0;
        dsp->fVbargraph1 = 0;
        dsp->fVbargraph2 = 0;
        dsp->fVbargraph5 = 0;
        dsp->fVbargraph27 = 0;
        dsp->fVbargraph26 = 0;
        dsp->fVbargraph28 = 0;
        dsp->fVbargraph3 = 0;
        dsp->fVbargraph4 = 0;
        dsp->fVbargraph6 = 0;
        dsp->fVbargraph7 = 0;
        dsp->fVbargraph8 = 0;
        dsp->fVbargraph16 = 0;
        dsp->fVbargraph9 = 0;
        dsp->fVbargraph17 = 0;
        dsp->fVbargraph10 = 0;
        dsp->fVbargraph18 = 0;
        dsp->fVbargraph11 = 0;
        dsp->fVbargraph19 = 0;
        dsp->fVbargraph12 = 0;
        dsp->fVbargraph20 = 0;
        dsp->fVbargraph13 = 0;
        dsp->fVbargraph21 = 0;
        dsp->fVbargraph14 = 0;
        dsp->fVbargraph22 = 0;
        dsp->fVbargraph15 = 0;
        dsp->fVbargraph23 = 0;
        dsp->fVbargraph24 = 0;
        dsp->fVbargraph25 = 0;
        
    }

    /*
    void printCurrentValues()
    {
        d_stdout("==== preset data start ===");
        printf("%.12g,", dsp->fCheckbox0);
        printf("%.12g,", dsp->fVslider14);
        printf("%.12g,", dsp->fVslider0);
        printf("%.12g,", dsp->fCheckbox8);
        printf("%.12g,", dsp->fCheckbox9);
        printf("%.12g,", dsp->fCheckbox6);
        printf("%.12g,", dsp->fCheckbox7);
        printf("%.12g,", dsp->fCheckbox5);
        printf("%.12g,", dsp->fCheckbox4);
        printf("%.12g,", dsp->fVslider4);
        printf("%.12g,", dsp->fVslider1);
        printf("%.12g,", dsp->fVslider3);
        printf("%.12g,", dsp->fVslider2);
        printf("%.12g,", dsp->fCheckbox3);
        printf("%.12g,", dsp->fVslider5);
        printf("%.12g,", dsp->fVslider6);
        printf("%.12g,", dsp->fVslider7);
        printf("%.12g,", dsp->fVslider8);
        printf("%.12g,", dsp->fVslider9);
        printf("%.12g,", dsp->fCheckbox2);
        printf("%.12g,", dsp->fVslider11);
        printf("%.12g,", dsp->fVslider10);
        printf("%.12g,", dsp->fVslider13);
        printf("%.12g,", dsp->fVslider12);
        printf("%.12g,", dsp->fCheckbox10);
        printf("%.12g,", dsp->fVslider21);
        printf("%.12g,", dsp->fVslider22);
        printf("%.12g,", dsp->fVslider19);
        printf("%.12g,", dsp->fVslider18);
        printf("%.12g,", dsp->fVslider23);
        printf("%.12g,", dsp->fVslider24);
        printf("%.12g,", dsp->fVslider17);
        printf("%.12g,", dsp->fVslider16);
        printf("%.12g,", dsp->fVslider15);
        printf("%.12g,", dsp->fCheckbox1);
        printf("%.12g,", dsp->fVslider27);
        printf("%.12g,", dsp->fVslider35);
        printf("%.12g,", dsp->fVslider31);
        printf("%.12g,", dsp->fVslider33);
        printf("%.12g,", dsp->fVslider36);
        printf("%.12g,", dsp->fVslider37);
        printf("%.12g,", dsp->fVslider25);
        printf("%.12g,", dsp->fVslider28);
        printf("%.12g,", dsp->fVslider29);
        printf("%.12g,", dsp->fVslider32);
        printf("%.12g,", dsp->fVslider34);
        printf("%.12g,", dsp->fVslider30);
        printf("%.12g,", dsp->fVslider38);
        printf("%.12g,", dsp->fVslider26);
        printf("%.12g,", dsp->fVslider20);
        printf("%.12g,", dsp->fCheckbox11);
        printf("%.12g,", dsp->fVslider42);
        printf("%.12g,", dsp->fVslider43);
        printf("%.12g,", dsp->fVslider41);
        printf("%.12g,", dsp->fVslider40);
        printf("%.12g,", dsp->fVslider44);
        printf("%.12g,", dsp->fVslider39);
        printf("%.12g,", dsp->fVslider45);
        printf("%.12g,", dsp->fCheckbox12);
        printf("%.12g,", dsp->fVslider47);
        printf("%.12g,", dsp->fVslider46);
        
        d_stdout("\n==== preset data end ===");
    }
    */

protected:
   /* -----------------------------------------------------------------------------------------------------------------
    * Information */

    const char* getLabel() const override
    {
        return "master_me";
    }

    const char* getDescription() const override
    {
        return "";
    }

    const char* getMaker() const override
    {
        return "Klaus Scheuermann";
    }

    const char* getHomePage() const override
    {
        return "https://4ohm.de/";
    }

    const char* getLicense() const override
    {
        return "GPLv3+";
    }

    uint32_t getVersion() const override
    {
        return d_version(1, 0, 0);
    }

    int64_t getUniqueId() const override
    {
        // FIXME provide a way to set this in meta data
        return d_cconst('F', 'I', 'X', 'M');
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Init */

    void initAudioPort(const bool input, const uint32_t index, AudioPort& port) override
    {
        /* make assumptions related to IO.
         * 1 audio port means mono, 2 means stereo.
         */
        
            
            
        port.groupId = kPortGroupStereo;
            
        

        // everything else is as default
        Plugin::initAudioPort(input, index, port);
    }

    void initParameter(const uint32_t index, Parameter& param) override
    {
        switch (index)
        {
        case kParameter_global_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[0];
            param.unit = kParameterUnits[0];
            param.symbol = kParameterSymbols[0];
            param.shortName = "";
            param.ranges.def = kParameterRanges[0].def;
            param.ranges.min = kParameterRanges[0].min;
            param.ranges.max = kParameterRanges[0].max;
            break;
        case kParameter_target:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[1];
            param.unit = kParameterUnits[1];
            param.symbol = kParameterSymbols[1];
            param.shortName = "";
            param.ranges.def = kParameterRanges[1].def;
            param.ranges.min = kParameterRanges[1].min;
            param.ranges.max = kParameterRanges[1].max;
            break;
        case kParameter_in_gain:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[2];
            param.unit = kParameterUnits[2];
            param.symbol = kParameterSymbols[2];
            param.shortName = "";
            param.ranges.def = kParameterRanges[2].def;
            param.ranges.min = kParameterRanges[2].min;
            param.ranges.max = kParameterRanges[2].max;
            break;
        case kParameter_phase_l:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[3];
            param.unit = kParameterUnits[3];
            param.symbol = kParameterSymbols[3];
            param.shortName = "";
            param.ranges.def = kParameterRanges[3].def;
            param.ranges.min = kParameterRanges[3].min;
            param.ranges.max = kParameterRanges[3].max;
            break;
        case kParameter_phase_r:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[4];
            param.unit = kParameterUnits[4];
            param.symbol = kParameterSymbols[4];
            param.shortName = "";
            param.ranges.def = kParameterRanges[4].def;
            param.ranges.min = kParameterRanges[4].min;
            param.ranges.max = kParameterRanges[4].max;
            break;
        case kParameter_mono:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[5];
            param.unit = kParameterUnits[5];
            param.symbol = kParameterSymbols[5];
            param.shortName = "";
            param.ranges.def = kParameterRanges[5].def;
            param.ranges.min = kParameterRanges[5].min;
            param.ranges.max = kParameterRanges[5].max;
            break;
        case kParameter_dc_blocker:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[6];
            param.unit = kParameterUnits[6];
            param.symbol = kParameterSymbols[6];
            param.shortName = "";
            param.ranges.def = kParameterRanges[6].def;
            param.ranges.min = kParameterRanges[6].min;
            param.ranges.max = kParameterRanges[6].max;
            break;
        case kParameter_stereo_correct:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[7];
            param.unit = kParameterUnits[7];
            param.symbol = kParameterSymbols[7];
            param.shortName = "";
            param.ranges.def = kParameterRanges[7].def;
            param.ranges.min = kParameterRanges[7].min;
            param.ranges.max = kParameterRanges[7].max;
            break;
        case kParameter_gate_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[8];
            param.unit = kParameterUnits[8];
            param.symbol = kParameterSymbols[8];
            param.shortName = "";
            param.ranges.def = kParameterRanges[8].def;
            param.ranges.min = kParameterRanges[8].min;
            param.ranges.max = kParameterRanges[8].max;
            break;
        case kParameter_gate_threshold:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[9];
            param.unit = kParameterUnits[9];
            param.symbol = kParameterSymbols[9];
            param.shortName = "";
            param.ranges.def = kParameterRanges[9].def;
            param.ranges.min = kParameterRanges[9].min;
            param.ranges.max = kParameterRanges[9].max;
            break;
        case kParameter_gate_attack:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[10];
            param.unit = kParameterUnits[10];
            param.symbol = kParameterSymbols[10];
            param.shortName = "";
            param.ranges.def = kParameterRanges[10].def;
            param.ranges.min = kParameterRanges[10].min;
            param.ranges.max = kParameterRanges[10].max;
            break;
        case kParameter_gate_hold:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[11];
            param.unit = kParameterUnits[11];
            param.symbol = kParameterSymbols[11];
            param.shortName = "";
            param.ranges.def = kParameterRanges[11].def;
            param.ranges.min = kParameterRanges[11].min;
            param.ranges.max = kParameterRanges[11].max;
            break;
        case kParameter_gate_release:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[12];
            param.unit = kParameterUnits[12];
            param.symbol = kParameterSymbols[12];
            param.shortName = "";
            param.ranges.def = kParameterRanges[12].def;
            param.ranges.min = kParameterRanges[12].min;
            param.ranges.max = kParameterRanges[12].max;
            break;
        case kParameter_eq_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[13];
            param.unit = kParameterUnits[13];
            param.symbol = kParameterSymbols[13];
            param.shortName = "";
            param.ranges.def = kParameterRanges[13].def;
            param.ranges.min = kParameterRanges[13].min;
            param.ranges.max = kParameterRanges[13].max;
            break;
        case kParameter_eq_highpass_freq:
            param.hints = kParameterIsAutomatable
            
            
            
            
                |kParameterIsLogarithmic
            
            ;
            param.name = kParameterNames[14];
            param.unit = kParameterUnits[14];
            param.symbol = kParameterSymbols[14];
            param.shortName = "";
            param.ranges.def = kParameterRanges[14].def;
            param.ranges.min = kParameterRanges[14].min;
            param.ranges.max = kParameterRanges[14].max;
            break;
        case kParameter_eq_tilt_gain:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[15];
            param.unit = kParameterUnits[15];
            param.symbol = kParameterSymbols[15];
            param.shortName = "";
            param.ranges.def = kParameterRanges[15].def;
            param.ranges.min = kParameterRanges[15].min;
            param.ranges.max = kParameterRanges[15].max;
            break;
        case kParameter_eq_side_gain:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[16];
            param.unit = kParameterUnits[16];
            param.symbol = kParameterSymbols[16];
            param.shortName = "";
            param.ranges.def = kParameterRanges[16].def;
            param.ranges.min = kParameterRanges[16].min;
            param.ranges.max = kParameterRanges[16].max;
            break;
        case kParameter_eq_side_freq:
            param.hints = kParameterIsAutomatable
            
            
            
            
                |kParameterIsLogarithmic
            
            ;
            param.name = kParameterNames[17];
            param.unit = kParameterUnits[17];
            param.symbol = kParameterSymbols[17];
            param.shortName = "";
            param.ranges.def = kParameterRanges[17].def;
            param.ranges.min = kParameterRanges[17].min;
            param.ranges.max = kParameterRanges[17].max;
            break;
        case kParameter_eq_side_bandwidth:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[18];
            param.unit = kParameterUnits[18];
            param.symbol = kParameterSymbols[18];
            param.shortName = "";
            param.ranges.def = kParameterRanges[18].def;
            param.ranges.min = kParameterRanges[18].min;
            param.ranges.max = kParameterRanges[18].max;
            break;
        case kParameter_leveler_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[19];
            param.unit = kParameterUnits[19];
            param.symbol = kParameterSymbols[19];
            param.shortName = "";
            param.ranges.def = kParameterRanges[19].def;
            param.ranges.min = kParameterRanges[19].min;
            param.ranges.max = kParameterRanges[19].max;
            break;
        case kParameter_leveler_speed:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[20];
            param.unit = kParameterUnits[20];
            param.symbol = kParameterSymbols[20];
            param.shortName = "";
            param.ranges.def = kParameterRanges[20].def;
            param.ranges.min = kParameterRanges[20].min;
            param.ranges.max = kParameterRanges[20].max;
            break;
        case kParameter_leveler_brake_threshold:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[21];
            param.unit = kParameterUnits[21];
            param.symbol = kParameterSymbols[21];
            param.shortName = "";
            param.ranges.def = kParameterRanges[21].def;
            param.ranges.min = kParameterRanges[21].min;
            param.ranges.max = kParameterRanges[21].max;
            break;
        case kParameter_leveler_max_plus:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[22];
            param.unit = kParameterUnits[22];
            param.symbol = kParameterSymbols[22];
            param.shortName = "";
            param.ranges.def = kParameterRanges[22].def;
            param.ranges.min = kParameterRanges[22].min;
            param.ranges.max = kParameterRanges[22].max;
            break;
        case kParameter_leveler_max_minus:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[23];
            param.unit = kParameterUnits[23];
            param.symbol = kParameterSymbols[23];
            param.shortName = "";
            param.ranges.def = kParameterRanges[23].def;
            param.ranges.min = kParameterRanges[23].min;
            param.ranges.max = kParameterRanges[23].max;
            break;
        case kParameter_kneecomp_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[24];
            param.unit = kParameterUnits[24];
            param.symbol = kParameterSymbols[24];
            param.shortName = "";
            param.ranges.def = kParameterRanges[24].def;
            param.ranges.min = kParameterRanges[24].min;
            param.ranges.max = kParameterRanges[24].max;
            break;
        case kParameter_kneecomp_strength:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[25];
            param.unit = kParameterUnits[25];
            param.symbol = kParameterSymbols[25];
            param.shortName = "";
            param.ranges.def = kParameterRanges[25].def;
            param.ranges.min = kParameterRanges[25].min;
            param.ranges.max = kParameterRanges[25].max;
            break;
        case kParameter_kneecomp_threshold:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[26];
            param.unit = kParameterUnits[26];
            param.symbol = kParameterSymbols[26];
            param.shortName = "";
            param.ranges.def = kParameterRanges[26].def;
            param.ranges.min = kParameterRanges[26].min;
            param.ranges.max = kParameterRanges[26].max;
            break;
        case kParameter_kneecomp_attack:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[27];
            param.unit = kParameterUnits[27];
            param.symbol = kParameterSymbols[27];
            param.shortName = "";
            param.ranges.def = kParameterRanges[27].def;
            param.ranges.min = kParameterRanges[27].min;
            param.ranges.max = kParameterRanges[27].max;
            break;
        case kParameter_kneecomp_release:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[28];
            param.unit = kParameterUnits[28];
            param.symbol = kParameterSymbols[28];
            param.shortName = "";
            param.ranges.def = kParameterRanges[28].def;
            param.ranges.min = kParameterRanges[28].min;
            param.ranges.max = kParameterRanges[28].max;
            break;
        case kParameter_kneecomp_knee:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[29];
            param.unit = kParameterUnits[29];
            param.symbol = kParameterSymbols[29];
            param.shortName = "";
            param.ranges.def = kParameterRanges[29].def;
            param.ranges.min = kParameterRanges[29].min;
            param.ranges.max = kParameterRanges[29].max;
            break;
        case kParameter_kneecomp_link:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[30];
            param.unit = kParameterUnits[30];
            param.symbol = kParameterSymbols[30];
            param.shortName = "";
            param.ranges.def = kParameterRanges[30].def;
            param.ranges.min = kParameterRanges[30].min;
            param.ranges.max = kParameterRanges[30].max;
            break;
        case kParameter_kneecomp_fffb:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[31];
            param.unit = kParameterUnits[31];
            param.symbol = kParameterSymbols[31];
            param.shortName = "";
            param.ranges.def = kParameterRanges[31].def;
            param.ranges.min = kParameterRanges[31].min;
            param.ranges.max = kParameterRanges[31].max;
            break;
        case kParameter_kneecomp_makeup:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[32];
            param.unit = kParameterUnits[32];
            param.symbol = kParameterSymbols[32];
            param.shortName = "";
            param.ranges.def = kParameterRanges[32].def;
            param.ranges.min = kParameterRanges[32].min;
            param.ranges.max = kParameterRanges[32].max;
            break;
        case kParameter_kneecomp_drywet:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[33];
            param.unit = kParameterUnits[33];
            param.symbol = kParameterSymbols[33];
            param.shortName = "";
            param.ranges.def = kParameterRanges[33].def;
            param.ranges.min = kParameterRanges[33].min;
            param.ranges.max = kParameterRanges[33].max;
            break;
        case kParameter_mscomp_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[34];
            param.unit = kParameterUnits[34];
            param.symbol = kParameterSymbols[34];
            param.shortName = "";
            param.ranges.def = kParameterRanges[34].def;
            param.ranges.min = kParameterRanges[34].min;
            param.ranges.max = kParameterRanges[34].max;
            break;
        case kParameter_mscomp_low_strength:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[35];
            param.unit = kParameterUnits[35];
            param.symbol = kParameterSymbols[35];
            param.shortName = "";
            param.ranges.def = kParameterRanges[35].def;
            param.ranges.min = kParameterRanges[35].min;
            param.ranges.max = kParameterRanges[35].max;
            break;
        case kParameter_mscomp_low_threshold:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[36];
            param.unit = kParameterUnits[36];
            param.symbol = kParameterSymbols[36];
            param.shortName = "";
            param.ranges.def = kParameterRanges[36].def;
            param.ranges.min = kParameterRanges[36].min;
            param.ranges.max = kParameterRanges[36].max;
            break;
        case kParameter_mscomp_low_attack:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[37];
            param.unit = kParameterUnits[37];
            param.symbol = kParameterSymbols[37];
            param.shortName = "";
            param.ranges.def = kParameterRanges[37].def;
            param.ranges.min = kParameterRanges[37].min;
            param.ranges.max = kParameterRanges[37].max;
            break;
        case kParameter_mscomp_low_release:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[38];
            param.unit = kParameterUnits[38];
            param.symbol = kParameterSymbols[38];
            param.shortName = "";
            param.ranges.def = kParameterRanges[38].def;
            param.ranges.min = kParameterRanges[38].min;
            param.ranges.max = kParameterRanges[38].max;
            break;
        case kParameter_mscomp_low_knee:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[39];
            param.unit = kParameterUnits[39];
            param.symbol = kParameterSymbols[39];
            param.shortName = "";
            param.ranges.def = kParameterRanges[39].def;
            param.ranges.min = kParameterRanges[39].min;
            param.ranges.max = kParameterRanges[39].max;
            break;
        case kParameter_mscomp_low_link:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[40];
            param.unit = kParameterUnits[40];
            param.symbol = kParameterSymbols[40];
            param.shortName = "";
            param.ranges.def = kParameterRanges[40].def;
            param.ranges.min = kParameterRanges[40].min;
            param.ranges.max = kParameterRanges[40].max;
            break;
        case kParameter_mscomp_low_crossover:
            param.hints = kParameterIsAutomatable
            
            
            
            
                |kParameterIsLogarithmic
            
            ;
            param.name = kParameterNames[41];
            param.unit = kParameterUnits[41];
            param.symbol = kParameterSymbols[41];
            param.shortName = "";
            param.ranges.def = kParameterRanges[41].def;
            param.ranges.min = kParameterRanges[41].min;
            param.ranges.max = kParameterRanges[41].max;
            break;
        case kParameter_mscomp_high_strength:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[42];
            param.unit = kParameterUnits[42];
            param.symbol = kParameterSymbols[42];
            param.shortName = "";
            param.ranges.def = kParameterRanges[42].def;
            param.ranges.min = kParameterRanges[42].min;
            param.ranges.max = kParameterRanges[42].max;
            break;
        case kParameter_mscomp_high_threshold:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[43];
            param.unit = kParameterUnits[43];
            param.symbol = kParameterSymbols[43];
            param.shortName = "";
            param.ranges.def = kParameterRanges[43].def;
            param.ranges.min = kParameterRanges[43].min;
            param.ranges.max = kParameterRanges[43].max;
            break;
        case kParameter_mscomp_high_attack:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[44];
            param.unit = kParameterUnits[44];
            param.symbol = kParameterSymbols[44];
            param.shortName = "";
            param.ranges.def = kParameterRanges[44].def;
            param.ranges.min = kParameterRanges[44].min;
            param.ranges.max = kParameterRanges[44].max;
            break;
        case kParameter_mscomp_high_release:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[45];
            param.unit = kParameterUnits[45];
            param.symbol = kParameterSymbols[45];
            param.shortName = "";
            param.ranges.def = kParameterRanges[45].def;
            param.ranges.min = kParameterRanges[45].min;
            param.ranges.max = kParameterRanges[45].max;
            break;
        case kParameter_mscomp_high_knee:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[46];
            param.unit = kParameterUnits[46];
            param.symbol = kParameterSymbols[46];
            param.shortName = "";
            param.ranges.def = kParameterRanges[46].def;
            param.ranges.min = kParameterRanges[46].min;
            param.ranges.max = kParameterRanges[46].max;
            break;
        case kParameter_mscomp_high_link:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[47];
            param.unit = kParameterUnits[47];
            param.symbol = kParameterSymbols[47];
            param.shortName = "";
            param.ranges.def = kParameterRanges[47].def;
            param.ranges.min = kParameterRanges[47].min;
            param.ranges.max = kParameterRanges[47].max;
            break;
        case kParameter_mscomp_high_crossover:
            param.hints = kParameterIsAutomatable
            
            
            
            
                |kParameterIsLogarithmic
            
            ;
            param.name = kParameterNames[48];
            param.unit = kParameterUnits[48];
            param.symbol = kParameterSymbols[48];
            param.shortName = "";
            param.ranges.def = kParameterRanges[48].def;
            param.ranges.min = kParameterRanges[48].min;
            param.ranges.max = kParameterRanges[48].max;
            break;
        case kParameter_mscomp_output_gain:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[49];
            param.unit = kParameterUnits[49];
            param.symbol = kParameterSymbols[49];
            param.shortName = "";
            param.ranges.def = kParameterRanges[49].def;
            param.ranges.min = kParameterRanges[49].min;
            param.ranges.max = kParameterRanges[49].max;
            break;
        case kParameter_limiter_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[50];
            param.unit = kParameterUnits[50];
            param.symbol = kParameterSymbols[50];
            param.shortName = "";
            param.ranges.def = kParameterRanges[50].def;
            param.ranges.min = kParameterRanges[50].min;
            param.ranges.max = kParameterRanges[50].max;
            break;
        case kParameter_limiter_strength:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[51];
            param.unit = kParameterUnits[51];
            param.symbol = kParameterSymbols[51];
            param.shortName = "";
            param.ranges.def = kParameterRanges[51].def;
            param.ranges.min = kParameterRanges[51].min;
            param.ranges.max = kParameterRanges[51].max;
            break;
        case kParameter_limiter_threshold:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[52];
            param.unit = kParameterUnits[52];
            param.symbol = kParameterSymbols[52];
            param.shortName = "";
            param.ranges.def = kParameterRanges[52].def;
            param.ranges.min = kParameterRanges[52].min;
            param.ranges.max = kParameterRanges[52].max;
            break;
        case kParameter_limiter_attack:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[53];
            param.unit = kParameterUnits[53];
            param.symbol = kParameterSymbols[53];
            param.shortName = "";
            param.ranges.def = kParameterRanges[53].def;
            param.ranges.min = kParameterRanges[53].min;
            param.ranges.max = kParameterRanges[53].max;
            break;
        case kParameter_limiter_release:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[54];
            param.unit = kParameterUnits[54];
            param.symbol = kParameterSymbols[54];
            param.shortName = "";
            param.ranges.def = kParameterRanges[54].def;
            param.ranges.min = kParameterRanges[54].min;
            param.ranges.max = kParameterRanges[54].max;
            break;
        case kParameter_limiter_knee:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[55];
            param.unit = kParameterUnits[55];
            param.symbol = kParameterSymbols[55];
            param.shortName = "";
            param.ranges.def = kParameterRanges[55].def;
            param.ranges.min = kParameterRanges[55].min;
            param.ranges.max = kParameterRanges[55].max;
            break;
        case kParameter_limiter_fffb:
            param.hints = kParameterIsAutomatable
            
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[56];
            param.unit = kParameterUnits[56];
            param.symbol = kParameterSymbols[56];
            param.shortName = "";
            param.ranges.def = kParameterRanges[56].def;
            param.ranges.min = kParameterRanges[56].min;
            param.ranges.max = kParameterRanges[56].max;
            break;
        case kParameter_limiter_makeup:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[57];
            param.unit = kParameterUnits[57];
            param.symbol = kParameterSymbols[57];
            param.shortName = "";
            param.ranges.def = kParameterRanges[57].def;
            param.ranges.min = kParameterRanges[57].min;
            param.ranges.max = kParameterRanges[57].max;
            break;
        case kParameter_brickwall_bypass:
            param.hints = kParameterIsAutomatable
            
            
                |kParameterIsBoolean
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[58];
            param.unit = kParameterUnits[58];
            param.symbol = kParameterSymbols[58];
            param.shortName = "";
            param.ranges.def = kParameterRanges[58].def;
            param.ranges.min = kParameterRanges[58].min;
            param.ranges.max = kParameterRanges[58].max;
            break;
        case kParameter_brickwall_ceiling:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[59];
            param.unit = kParameterUnits[59];
            param.symbol = kParameterSymbols[59];
            param.shortName = "";
            param.ranges.def = kParameterRanges[59].def;
            param.ranges.min = kParameterRanges[59].min;
            param.ranges.max = kParameterRanges[59].max;
            break;
        case kParameter_brickwall_release:
            param.hints = kParameterIsAutomatable
            
            
            
            
            ;
            param.name = kParameterNames[60];
            param.unit = kParameterUnits[60];
            param.symbol = kParameterSymbols[60];
            param.shortName = "";
            param.ranges.def = kParameterRanges[60].def;
            param.ranges.min = kParameterRanges[60].min;
            param.ranges.max = kParameterRanges[60].max;
            break;
        
        case kParameter_peakmeter_in_l:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[61];
            param.unit = kParameterUnits[61];
            param.symbol = kParameterSymbols[61];
            param.shortName = "";
            param.ranges.def = kParameterRanges[61].def;
            param.ranges.min = kParameterRanges[61].min;
            param.ranges.max = kParameterRanges[61].max;
            break;
        case kParameter_peakmeter_in_r:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[62];
            param.unit = kParameterUnits[62];
            param.symbol = kParameterSymbols[62];
            param.shortName = "";
            param.ranges.def = kParameterRanges[62].def;
            param.ranges.min = kParameterRanges[62].min;
            param.ranges.max = kParameterRanges[62].max;
            break;
        case kParameter_lufs_in:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[63];
            param.unit = kParameterUnits[63];
            param.symbol = kParameterSymbols[63];
            param.shortName = "";
            param.ranges.def = kParameterRanges[63].def;
            param.ranges.min = kParameterRanges[63].min;
            param.ranges.max = kParameterRanges[63].max;
            break;
        case kParameter_leveler_gain:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[64];
            param.unit = kParameterUnits[64];
            param.symbol = kParameterSymbols[64];
            param.shortName = "";
            param.ranges.def = kParameterRanges[64].def;
            param.ranges.min = kParameterRanges[64].min;
            param.ranges.max = kParameterRanges[64].max;
            break;
        case kParameter_lufs_out:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[65];
            param.unit = kParameterUnits[65];
            param.symbol = kParameterSymbols[65];
            param.shortName = "";
            param.ranges.def = kParameterRanges[65].def;
            param.ranges.min = kParameterRanges[65].min;
            param.ranges.max = kParameterRanges[65].max;
            break;
        case kParameter_peakmeter_out_l:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[66];
            param.unit = kParameterUnits[66];
            param.symbol = kParameterSymbols[66];
            param.shortName = "";
            param.ranges.def = kParameterRanges[66].def;
            param.ranges.min = kParameterRanges[66].min;
            param.ranges.max = kParameterRanges[66].max;
            break;
        case kParameter_peakmeter_out_r:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[67];
            param.unit = kParameterUnits[67];
            param.symbol = kParameterSymbols[67];
            param.shortName = "";
            param.ranges.def = kParameterRanges[67].def;
            param.ranges.min = kParameterRanges[67].min;
            param.ranges.max = kParameterRanges[67].max;
            break;
        case kParameter_gate_meter:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[68];
            param.unit = kParameterUnits[68];
            param.symbol = kParameterSymbols[68];
            param.shortName = "";
            param.ranges.def = kParameterRanges[68].def;
            param.ranges.min = kParameterRanges[68].min;
            param.ranges.max = kParameterRanges[68].max;
            break;
        case kParameter_leveler_brake:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
                |kParameterIsInteger
            
            
            ;
            param.name = kParameterNames[69];
            param.unit = kParameterUnits[69];
            param.symbol = kParameterSymbols[69];
            param.shortName = "";
            param.ranges.def = kParameterRanges[69].def;
            param.ranges.min = kParameterRanges[69].min;
            param.ranges.max = kParameterRanges[69].max;
            break;
        case kParameter_kneecomp_meter_0:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[70];
            param.unit = kParameterUnits[70];
            param.symbol = kParameterSymbols[70];
            param.shortName = "";
            param.ranges.def = kParameterRanges[70].def;
            param.ranges.min = kParameterRanges[70].min;
            param.ranges.max = kParameterRanges[70].max;
            break;
        case kParameter_kneecomp_meter_1:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[71];
            param.unit = kParameterUnits[71];
            param.symbol = kParameterSymbols[71];
            param.shortName = "";
            param.ranges.def = kParameterRanges[71].def;
            param.ranges.min = kParameterRanges[71].min;
            param.ranges.max = kParameterRanges[71].max;
            break;
        case kParameter_msredux11:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[72];
            param.unit = kParameterUnits[72];
            param.symbol = kParameterSymbols[72];
            param.shortName = "";
            param.ranges.def = kParameterRanges[72].def;
            param.ranges.min = kParameterRanges[72].min;
            param.ranges.max = kParameterRanges[72].max;
            break;
        case kParameter_msredux12:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[73];
            param.unit = kParameterUnits[73];
            param.symbol = kParameterSymbols[73];
            param.shortName = "";
            param.ranges.def = kParameterRanges[73].def;
            param.ranges.min = kParameterRanges[73].min;
            param.ranges.max = kParameterRanges[73].max;
            break;
        case kParameter_msredux21:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[74];
            param.unit = kParameterUnits[74];
            param.symbol = kParameterSymbols[74];
            param.shortName = "";
            param.ranges.def = kParameterRanges[74].def;
            param.ranges.min = kParameterRanges[74].min;
            param.ranges.max = kParameterRanges[74].max;
            break;
        case kParameter_msredux22:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[75];
            param.unit = kParameterUnits[75];
            param.symbol = kParameterSymbols[75];
            param.shortName = "";
            param.ranges.def = kParameterRanges[75].def;
            param.ranges.min = kParameterRanges[75].min;
            param.ranges.max = kParameterRanges[75].max;
            break;
        case kParameter_msredux31:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[76];
            param.unit = kParameterUnits[76];
            param.symbol = kParameterSymbols[76];
            param.shortName = "";
            param.ranges.def = kParameterRanges[76].def;
            param.ranges.min = kParameterRanges[76].min;
            param.ranges.max = kParameterRanges[76].max;
            break;
        case kParameter_msredux32:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[77];
            param.unit = kParameterUnits[77];
            param.symbol = kParameterSymbols[77];
            param.shortName = "";
            param.ranges.def = kParameterRanges[77].def;
            param.ranges.min = kParameterRanges[77].min;
            param.ranges.max = kParameterRanges[77].max;
            break;
        case kParameter_msredux41:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[78];
            param.unit = kParameterUnits[78];
            param.symbol = kParameterSymbols[78];
            param.shortName = "";
            param.ranges.def = kParameterRanges[78].def;
            param.ranges.min = kParameterRanges[78].min;
            param.ranges.max = kParameterRanges[78].max;
            break;
        case kParameter_msredux42:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[79];
            param.unit = kParameterUnits[79];
            param.symbol = kParameterSymbols[79];
            param.shortName = "";
            param.ranges.def = kParameterRanges[79].def;
            param.ranges.min = kParameterRanges[79].min;
            param.ranges.max = kParameterRanges[79].max;
            break;
        case kParameter_msredux51:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[80];
            param.unit = kParameterUnits[80];
            param.symbol = kParameterSymbols[80];
            param.shortName = "";
            param.ranges.def = kParameterRanges[80].def;
            param.ranges.min = kParameterRanges[80].min;
            param.ranges.max = kParameterRanges[80].max;
            break;
        case kParameter_msredux52:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[81];
            param.unit = kParameterUnits[81];
            param.symbol = kParameterSymbols[81];
            param.shortName = "";
            param.ranges.def = kParameterRanges[81].def;
            param.ranges.min = kParameterRanges[81].min;
            param.ranges.max = kParameterRanges[81].max;
            break;
        case kParameter_msredux61:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[82];
            param.unit = kParameterUnits[82];
            param.symbol = kParameterSymbols[82];
            param.shortName = "";
            param.ranges.def = kParameterRanges[82].def;
            param.ranges.min = kParameterRanges[82].min;
            param.ranges.max = kParameterRanges[82].max;
            break;
        case kParameter_msredux62:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[83];
            param.unit = kParameterUnits[83];
            param.symbol = kParameterSymbols[83];
            param.shortName = "";
            param.ranges.def = kParameterRanges[83].def;
            param.ranges.min = kParameterRanges[83].min;
            param.ranges.max = kParameterRanges[83].max;
            break;
        case kParameter_msredux71:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[84];
            param.unit = kParameterUnits[84];
            param.symbol = kParameterSymbols[84];
            param.shortName = "";
            param.ranges.def = kParameterRanges[84].def;
            param.ranges.min = kParameterRanges[84].min;
            param.ranges.max = kParameterRanges[84].max;
            break;
        case kParameter_msredux72:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[85];
            param.unit = kParameterUnits[85];
            param.symbol = kParameterSymbols[85];
            param.shortName = "";
            param.ranges.def = kParameterRanges[85].def;
            param.ranges.min = kParameterRanges[85].min;
            param.ranges.max = kParameterRanges[85].max;
            break;
        case kParameter_msredux81:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[86];
            param.unit = kParameterUnits[86];
            param.symbol = kParameterSymbols[86];
            param.shortName = "";
            param.ranges.def = kParameterRanges[86].def;
            param.ranges.min = kParameterRanges[86].min;
            param.ranges.max = kParameterRanges[86].max;
            break;
        case kParameter_msredux82:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[87];
            param.unit = kParameterUnits[87];
            param.symbol = kParameterSymbols[87];
            param.shortName = "";
            param.ranges.def = kParameterRanges[87].def;
            param.ranges.min = kParameterRanges[87].min;
            param.ranges.max = kParameterRanges[87].max;
            break;
        case kParameter_limiter_gain_reduction:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[88];
            param.unit = kParameterUnits[88];
            param.symbol = kParameterSymbols[88];
            param.shortName = "";
            param.ranges.def = kParameterRanges[88].def;
            param.ranges.min = kParameterRanges[88].min;
            param.ranges.max = kParameterRanges[88].max;
            break;
        case kParameter_brickwall_limit:
            param.hints = kParameterIsAutomatable|kParameterIsOutput
            
            
            
            ;
            param.name = kParameterNames[89];
            param.unit = kParameterUnits[89];
            param.symbol = kParameterSymbols[89];
            param.shortName = "";
            param.ranges.def = kParameterRanges[89].def;
            param.ranges.min = kParameterRanges[89].min;
            param.ranges.max = kParameterRanges[89].max;
            break;
        
        }
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Internal data */

    float getParameterValue(const uint32_t index) const override
    {
        switch (index)
        {
        case kParameter_global_bypass:
            return dsp->fCheckbox0;
        case kParameter_target:
            return dsp->fVslider14;
        case kParameter_in_gain:
            return dsp->fVslider0;
        case kParameter_phase_l:
            return dsp->fCheckbox8;
        case kParameter_phase_r:
            return dsp->fCheckbox9;
        case kParameter_mono:
            return dsp->fCheckbox6;
        case kParameter_dc_blocker:
            return dsp->fCheckbox7;
        case kParameter_stereo_correct:
            return dsp->fCheckbox5;
        case kParameter_gate_bypass:
            return dsp->fCheckbox4;
        case kParameter_gate_threshold:
            return dsp->fVslider4;
        case kParameter_gate_attack:
            return dsp->fVslider1;
        case kParameter_gate_hold:
            return dsp->fVslider3;
        case kParameter_gate_release:
            return dsp->fVslider2;
        case kParameter_eq_bypass:
            return dsp->fCheckbox3;
        case kParameter_eq_highpass_freq:
            return dsp->fVslider5;
        case kParameter_eq_tilt_gain:
            return dsp->fVslider6;
        case kParameter_eq_side_gain:
            return dsp->fVslider7;
        case kParameter_eq_side_freq:
            return dsp->fVslider8;
        case kParameter_eq_side_bandwidth:
            return dsp->fVslider9;
        case kParameter_leveler_bypass:
            return dsp->fCheckbox2;
        case kParameter_leveler_speed:
            return dsp->fVslider11;
        case kParameter_leveler_brake_threshold:
            return dsp->fVslider10;
        case kParameter_leveler_max_plus:
            return dsp->fVslider13;
        case kParameter_leveler_max_minus:
            return dsp->fVslider12;
        case kParameter_kneecomp_bypass:
            return dsp->fCheckbox10;
        case kParameter_kneecomp_strength:
            return dsp->fVslider21;
        case kParameter_kneecomp_threshold:
            return dsp->fVslider22;
        case kParameter_kneecomp_attack:
            return dsp->fVslider19;
        case kParameter_kneecomp_release:
            return dsp->fVslider18;
        case kParameter_kneecomp_knee:
            return dsp->fVslider23;
        case kParameter_kneecomp_link:
            return dsp->fVslider24;
        case kParameter_kneecomp_fffb:
            return dsp->fVslider17;
        case kParameter_kneecomp_makeup:
            return dsp->fVslider16;
        case kParameter_kneecomp_drywet:
            return dsp->fVslider15;
        case kParameter_mscomp_bypass:
            return dsp->fCheckbox1;
        case kParameter_mscomp_low_strength:
            return dsp->fVslider27;
        case kParameter_mscomp_low_threshold:
            return dsp->fVslider35;
        case kParameter_mscomp_low_attack:
            return dsp->fVslider31;
        case kParameter_mscomp_low_release:
            return dsp->fVslider33;
        case kParameter_mscomp_low_knee:
            return dsp->fVslider36;
        case kParameter_mscomp_low_link:
            return dsp->fVslider37;
        case kParameter_mscomp_low_crossover:
            return dsp->fVslider25;
        case kParameter_mscomp_high_strength:
            return dsp->fVslider28;
        case kParameter_mscomp_high_threshold:
            return dsp->fVslider29;
        case kParameter_mscomp_high_attack:
            return dsp->fVslider32;
        case kParameter_mscomp_high_release:
            return dsp->fVslider34;
        case kParameter_mscomp_high_knee:
            return dsp->fVslider30;
        case kParameter_mscomp_high_link:
            return dsp->fVslider38;
        case kParameter_mscomp_high_crossover:
            return dsp->fVslider26;
        case kParameter_mscomp_output_gain:
            return dsp->fVslider20;
        case kParameter_limiter_bypass:
            return dsp->fCheckbox11;
        case kParameter_limiter_strength:
            return dsp->fVslider42;
        case kParameter_limiter_threshold:
            return dsp->fVslider43;
        case kParameter_limiter_attack:
            return dsp->fVslider41;
        case kParameter_limiter_release:
            return dsp->fVslider40;
        case kParameter_limiter_knee:
            return dsp->fVslider44;
        case kParameter_limiter_fffb:
            return dsp->fVslider39;
        case kParameter_limiter_makeup:
            return dsp->fVslider45;
        case kParameter_brickwall_bypass:
            return dsp->fCheckbox12;
        case kParameter_brickwall_ceiling:
            return dsp->fVslider47;
        case kParameter_brickwall_release:
            return dsp->fVslider46;
        case kParameter_peakmeter_in_l:
            return dsp->fVbargraph0;
        case kParameter_peakmeter_in_r:
            return dsp->fVbargraph1;
        case kParameter_lufs_in:
            return dsp->fVbargraph2;
        case kParameter_leveler_gain:
            return dsp->fVbargraph5;
        case kParameter_lufs_out:
            return dsp->fVbargraph27;
        case kParameter_peakmeter_out_l:
            return dsp->fVbargraph26;
        case kParameter_peakmeter_out_r:
            return dsp->fVbargraph28;
        case kParameter_gate_meter:
            return dsp->fVbargraph3;
        case kParameter_leveler_brake:
            return dsp->fVbargraph4;
        case kParameter_kneecomp_meter_0:
            return dsp->fVbargraph6;
        case kParameter_kneecomp_meter_1:
            return dsp->fVbargraph7;
        case kParameter_msredux11:
            return dsp->fVbargraph8;
        case kParameter_msredux12:
            return dsp->fVbargraph16;
        case kParameter_msredux21:
            return dsp->fVbargraph9;
        case kParameter_msredux22:
            return dsp->fVbargraph17;
        case kParameter_msredux31:
            return dsp->fVbargraph10;
        case kParameter_msredux32:
            return dsp->fVbargraph18;
        case kParameter_msredux41:
            return dsp->fVbargraph11;
        case kParameter_msredux42:
            return dsp->fVbargraph19;
        case kParameter_msredux51:
            return dsp->fVbargraph12;
        case kParameter_msredux52:
            return dsp->fVbargraph20;
        case kParameter_msredux61:
            return dsp->fVbargraph13;
        case kParameter_msredux62:
            return dsp->fVbargraph21;
        case kParameter_msredux71:
            return dsp->fVbargraph14;
        case kParameter_msredux72:
            return dsp->fVbargraph22;
        case kParameter_msredux81:
            return dsp->fVbargraph15;
        case kParameter_msredux82:
            return dsp->fVbargraph23;
        case kParameter_limiter_gain_reduction:
            return dsp->fVbargraph24;
        case kParameter_brickwall_limit:
            return dsp->fVbargraph25;
        
        default:
            return 0.0f;
        }
    }

    void setParameterValue(const uint32_t index, const float value) override
    {
        switch (index)
        {
        case kParameter_global_bypass:
            dsp->fCheckbox0 = value;
            break;
        case kParameter_target:
            dsp->fVslider14 = value;
            break;
        case kParameter_in_gain:
            dsp->fVslider0 = value;
            break;
        case kParameter_phase_l:
            dsp->fCheckbox8 = value;
            break;
        case kParameter_phase_r:
            dsp->fCheckbox9 = value;
            break;
        case kParameter_mono:
            dsp->fCheckbox6 = value;
            break;
        case kParameter_dc_blocker:
            dsp->fCheckbox7 = value;
            break;
        case kParameter_stereo_correct:
            dsp->fCheckbox5 = value;
            break;
        case kParameter_gate_bypass:
            dsp->fCheckbox4 = value;
            break;
        case kParameter_gate_threshold:
            dsp->fVslider4 = value;
            break;
        case kParameter_gate_attack:
            dsp->fVslider1 = value;
            break;
        case kParameter_gate_hold:
            dsp->fVslider3 = value;
            break;
        case kParameter_gate_release:
            dsp->fVslider2 = value;
            break;
        case kParameter_eq_bypass:
            dsp->fCheckbox3 = value;
            break;
        case kParameter_eq_highpass_freq:
            dsp->fVslider5 = value;
            break;
        case kParameter_eq_tilt_gain:
            dsp->fVslider6 = value;
            break;
        case kParameter_eq_side_gain:
            dsp->fVslider7 = value;
            break;
        case kParameter_eq_side_freq:
            dsp->fVslider8 = value;
            break;
        case kParameter_eq_side_bandwidth:
            dsp->fVslider9 = value;
            break;
        case kParameter_leveler_bypass:
            dsp->fCheckbox2 = value;
            break;
        case kParameter_leveler_speed:
            dsp->fVslider11 = value;
            break;
        case kParameter_leveler_brake_threshold:
            dsp->fVslider10 = value;
            break;
        case kParameter_leveler_max_plus:
            dsp->fVslider13 = value;
            break;
        case kParameter_leveler_max_minus:
            dsp->fVslider12 = value;
            break;
        case kParameter_kneecomp_bypass:
            dsp->fCheckbox10 = value;
            break;
        case kParameter_kneecomp_strength:
            dsp->fVslider21 = value;
            break;
        case kParameter_kneecomp_threshold:
            dsp->fVslider22 = value;
            break;
        case kParameter_kneecomp_attack:
            dsp->fVslider19 = value;
            break;
        case kParameter_kneecomp_release:
            dsp->fVslider18 = value;
            break;
        case kParameter_kneecomp_knee:
            dsp->fVslider23 = value;
            break;
        case kParameter_kneecomp_link:
            dsp->fVslider24 = value;
            break;
        case kParameter_kneecomp_fffb:
            dsp->fVslider17 = value;
            break;
        case kParameter_kneecomp_makeup:
            dsp->fVslider16 = value;
            break;
        case kParameter_kneecomp_drywet:
            dsp->fVslider15 = value;
            break;
        case kParameter_mscomp_bypass:
            dsp->fCheckbox1 = value;
            break;
        case kParameter_mscomp_low_strength:
            dsp->fVslider27 = value;
            break;
        case kParameter_mscomp_low_threshold:
            dsp->fVslider35 = value;
            break;
        case kParameter_mscomp_low_attack:
            dsp->fVslider31 = value;
            break;
        case kParameter_mscomp_low_release:
            dsp->fVslider33 = value;
            break;
        case kParameter_mscomp_low_knee:
            dsp->fVslider36 = value;
            break;
        case kParameter_mscomp_low_link:
            dsp->fVslider37 = value;
            break;
        case kParameter_mscomp_low_crossover:
            dsp->fVslider25 = value;
            break;
        case kParameter_mscomp_high_strength:
            dsp->fVslider28 = value;
            break;
        case kParameter_mscomp_high_threshold:
            dsp->fVslider29 = value;
            break;
        case kParameter_mscomp_high_attack:
            dsp->fVslider32 = value;
            break;
        case kParameter_mscomp_high_release:
            dsp->fVslider34 = value;
            break;
        case kParameter_mscomp_high_knee:
            dsp->fVslider30 = value;
            break;
        case kParameter_mscomp_high_link:
            dsp->fVslider38 = value;
            break;
        case kParameter_mscomp_high_crossover:
            dsp->fVslider26 = value;
            break;
        case kParameter_mscomp_output_gain:
            dsp->fVslider20 = value;
            break;
        case kParameter_limiter_bypass:
            dsp->fCheckbox11 = value;
            break;
        case kParameter_limiter_strength:
            dsp->fVslider42 = value;
            break;
        case kParameter_limiter_threshold:
            dsp->fVslider43 = value;
            break;
        case kParameter_limiter_attack:
            dsp->fVslider41 = value;
            break;
        case kParameter_limiter_release:
            dsp->fVslider40 = value;
            break;
        case kParameter_limiter_knee:
            dsp->fVslider44 = value;
            break;
        case kParameter_limiter_fffb:
            dsp->fVslider39 = value;
            break;
        case kParameter_limiter_makeup:
            dsp->fVslider45 = value;
            break;
        case kParameter_brickwall_bypass:
            dsp->fCheckbox12 = value;
            break;
        case kParameter_brickwall_ceiling:
            dsp->fVslider47 = value;
            break;
        case kParameter_brickwall_release:
            dsp->fVslider46 = value;
            break;
        
        }
    }

   /* -----------------------------------------------------------------------------------------------------------------
    * Audio/MIDI Processing */

    void run(const float** const inputs, float** const outputs, const uint32_t frames) override
    {
        dsp->compute(frames, const_cast<float**>(inputs), outputs);
    }

    void sampleRateChanged(const double newSampleRate) override
    {
        // retrieve parameter info first
        float params[61] = {
            dsp->fCheckbox0,
            dsp->fVslider14,
            dsp->fVslider0,
            dsp->fCheckbox8,
            dsp->fCheckbox9,
            dsp->fCheckbox6,
            dsp->fCheckbox7,
            dsp->fCheckbox5,
            dsp->fCheckbox4,
            dsp->fVslider4,
            dsp->fVslider1,
            dsp->fVslider3,
            dsp->fVslider2,
            dsp->fCheckbox3,
            dsp->fVslider5,
            dsp->fVslider6,
            dsp->fVslider7,
            dsp->fVslider8,
            dsp->fVslider9,
            dsp->fCheckbox2,
            dsp->fVslider11,
            dsp->fVslider10,
            dsp->fVslider13,
            dsp->fVslider12,
            dsp->fCheckbox10,
            dsp->fVslider21,
            dsp->fVslider22,
            dsp->fVslider19,
            dsp->fVslider18,
            dsp->fVslider23,
            dsp->fVslider24,
            dsp->fVslider17,
            dsp->fVslider16,
            dsp->fVslider15,
            dsp->fCheckbox1,
            dsp->fVslider27,
            dsp->fVslider35,
            dsp->fVslider31,
            dsp->fVslider33,
            dsp->fVslider36,
            dsp->fVslider37,
            dsp->fVslider25,
            dsp->fVslider28,
            dsp->fVslider29,
            dsp->fVslider32,
            dsp->fVslider34,
            dsp->fVslider30,
            dsp->fVslider38,
            dsp->fVslider26,
            dsp->fVslider20,
            dsp->fCheckbox11,
            dsp->fVslider42,
            dsp->fVslider43,
            dsp->fVslider41,
            dsp->fVslider40,
            dsp->fVslider44,
            dsp->fVslider39,
            dsp->fVslider45,
            dsp->fCheckbox12,
            dsp->fVslider47,
            dsp->fVslider46,
            
        };

        // tell dsp to change sample rate
        dsp->init(newSampleRate);

        // set parameters back, which have been reset in the dsp
        dsp->fCheckbox0 = params[0];
        dsp->fVslider14 = params[1];
        dsp->fVslider0 = params[2];
        dsp->fCheckbox8 = params[3];
        dsp->fCheckbox9 = params[4];
        dsp->fCheckbox6 = params[5];
        dsp->fCheckbox7 = params[6];
        dsp->fCheckbox5 = params[7];
        dsp->fCheckbox4 = params[8];
        dsp->fVslider4 = params[9];
        dsp->fVslider1 = params[10];
        dsp->fVslider3 = params[11];
        dsp->fVslider2 = params[12];
        dsp->fCheckbox3 = params[13];
        dsp->fVslider5 = params[14];
        dsp->fVslider6 = params[15];
        dsp->fVslider7 = params[16];
        dsp->fVslider8 = params[17];
        dsp->fVslider9 = params[18];
        dsp->fCheckbox2 = params[19];
        dsp->fVslider11 = params[20];
        dsp->fVslider10 = params[21];
        dsp->fVslider13 = params[22];
        dsp->fVslider12 = params[23];
        dsp->fCheckbox10 = params[24];
        dsp->fVslider21 = params[25];
        dsp->fVslider22 = params[26];
        dsp->fVslider19 = params[27];
        dsp->fVslider18 = params[28];
        dsp->fVslider23 = params[29];
        dsp->fVslider24 = params[30];
        dsp->fVslider17 = params[31];
        dsp->fVslider16 = params[32];
        dsp->fVslider15 = params[33];
        dsp->fCheckbox1 = params[34];
        dsp->fVslider27 = params[35];
        dsp->fVslider35 = params[36];
        dsp->fVslider31 = params[37];
        dsp->fVslider33 = params[38];
        dsp->fVslider36 = params[39];
        dsp->fVslider37 = params[40];
        dsp->fVslider25 = params[41];
        dsp->fVslider28 = params[42];
        dsp->fVslider29 = params[43];
        dsp->fVslider32 = params[44];
        dsp->fVslider34 = params[45];
        dsp->fVslider30 = params[46];
        dsp->fVslider38 = params[47];
        dsp->fVslider26 = params[48];
        dsp->fVslider20 = params[49];
        dsp->fCheckbox11 = params[50];
        dsp->fVslider42 = params[51];
        dsp->fVslider43 = params[52];
        dsp->fVslider41 = params[53];
        dsp->fVslider40 = params[54];
        dsp->fVslider44 = params[55];
        dsp->fVslider39 = params[56];
        dsp->fVslider45 = params[57];
        dsp->fCheckbox12 = params[58];
        dsp->fVslider47 = params[59];
        dsp->fVslider46 = params[60];
        
    }

    // ----------------------------------------------------------------------------------------------------------------

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FaustGeneratedPlugin)
};

// --------------------------------------------------------------------------------------------------------------------

#if 0


Plugin* createPlugin()
{
    return new FaustGeneratedPlugin();
}


#endif

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
