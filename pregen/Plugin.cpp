
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

static float mydsp_faustpower6_f(float value) {
	return value * value * value * value * value * value;
}
static float mydsp_faustpower2_f(float value) {
	return value * value;
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
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fCheckbox0;
	float fRec1[2];
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fVslider5;
	float fConst4;
	FAUSTFLOAT fCheckbox1;
	float fRec11[2];
	FAUSTFLOAT fVslider6;
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fVslider8;
	float fConst5;
	float fConst6;
	int iConst7;
	FAUSTFLOAT fVslider9;
	float fRec21[2];
	float fRec20[2];
	FAUSTFLOAT fVbargraph0;
	float fVec0[2];
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fVec1[2];
	float fConst16;
	float fConst17;
	float fRec19[2];
	float fRec18[2];
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fVec2[2];
	float fConst23;
	float fRec17[2];
	float fRec16[2];
	float fVec3[2];
	float fVec4[3];
	int iConst24;
	int iConst25;
	float fVec5[5];
	int iConst26;
	int iConst27;
	float fVec6[12];
	int iConst28;
	int iConst29;
	int IOTA0;
	float fVec7[32];
	int iConst30;
	int iConst31;
	float fVec8[64];
	int iConst32;
	int iConst33;
	float fVec9[128];
	int iConst34;
	int iConst35;
	float fVec10[256];
	int iConst36;
	int iConst37;
	float fVec11[512];
	int iConst38;
	int iConst39;
	float fVec12[1024];
	int iConst40;
	int iConst41;
	float fVec13[2048];
	int iConst42;
	int iConst43;
	float fVec14[4096];
	int iConst44;
	int iConst45;
	float fVec15[8192];
	int iConst46;
	int iConst47;
	float fVec16[16384];
	int iConst48;
	int iConst49;
	float fVec17[32768];
	int iConst50;
	int iConst51;
	float fVec18[65536];
	int iConst52;
	int iConst53;
	float fVec19[131072];
	int iConst54;
	int iConst55;
	float fVec20[262144];
	int iConst56;
	int iConst57;
	float fVec21[524288];
	int iConst58;
	int iConst59;
	float fVec22[1048576];
	int iConst60;
	float fRec26[2];
	FAUSTFLOAT fVbargraph1;
	float fVec23[2];
	float fVec24[2];
	float fRec25[2];
	float fRec24[2];
	float fVec25[2];
	float fRec23[2];
	float fRec22[2];
	float fVec26[2];
	float fVec27[3];
	float fVec28[5];
	float fVec29[12];
	float fVec30[32];
	float fVec31[64];
	float fVec32[128];
	float fVec33[256];
	float fVec34[512];
	float fVec35[1024];
	float fVec36[2048];
	float fVec37[4096];
	float fVec38[8192];
	float fVec39[16384];
	float fVec40[32768];
	float fVec41[65536];
	float fVec42[131072];
	float fVec43[262144];
	float fVec44[524288];
	float fVec45[1048576];
	float fConst61;
	FAUSTFLOAT fVbargraph2;
	float fVec46[2];
	FAUSTFLOAT fCheckbox2;
	float fRec27[2];
	float fConst62;
	float fConst63;
	float fConst64;
	float fRec28[2];
	FAUSTFLOAT fCheckbox3;
	float fRec29[2];
	FAUSTFLOAT fCheckbox4;
	float fRec30[2];
	FAUSTFLOAT fCheckbox5;
	float fConst65;
	float fConst66;
	float fConst67;
	float fRec34[2];
	float fRec33[2];
	float fRec36[2];
	float fRec35[2];
	float fRec37[2];
	float fRec32[2];
	float fConst68;
	float fRec31[2];
	float fRec39[2];
	float fRec38[2];
	float fRec41[2];
	float fRec40[2];
	float fRec43[2];
	float fRec42[2];
	float fRec45[2];
	float fRec44[2];
	FAUSTFLOAT fCheckbox6;
	float fRec46[2];
	float fRec15[2];
	int iVec47[2];
	FAUSTFLOAT fVslider10;
	float fConst69;
	int iRec47[2];
	float fRec14[2];
	FAUSTFLOAT fVbargraph3;
	float fRec13[2];
	int iVec48[2];
	int iRec48[2];
	float fRec12[2];
	FAUSTFLOAT fCheckbox7;
	float fRec49[2];
	FAUSTFLOAT fVslider11;
	float fRec50[2];
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	FAUSTFLOAT fVslider14;
	float fRec59[2];
	float fVec49[2];
	FAUSTFLOAT fVslider15;
	float fRec62[2];
	float fConst70;
	float fConst71;
	float fConst72;
	float fRec61[2];
	float fRec63[2];
	float fVec50[2];
	float fRec60[2];
	float fRec64[2];
	float fVec51[2];
	float fRec67[2];
	float fRec66[2];
	float fRec68[2];
	float fVec52[2];
	float fRec65[2];
	float fRec69[2];
	float fRec55[2];
	float fRec56[2];
	float fRec51[2];
	float fRec52[2];
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	FAUSTFLOAT fVslider18;
	int iConst73;
	float fVec53[2];
	int iConst74;
	float fVec54[3];
	int iConst75;
	float fVec55[5];
	int iConst76;
	int iConst77;
	float fVec56[12];
	int iConst78;
	int iConst79;
	float fVec57[32];
	int iConst80;
	int iConst81;
	float fVec58[64];
	int iConst82;
	int iConst83;
	float fVec59[128];
	int iConst84;
	int iConst85;
	float fVec60[256];
	int iConst86;
	int iConst87;
	float fVec61[512];
	int iConst88;
	int iConst89;
	float fVec62[1024];
	int iConst90;
	int iConst91;
	float fVec63[2048];
	int iConst92;
	int iConst93;
	float fVec64[4096];
	int iConst94;
	int iConst95;
	float fVec65[8192];
	int iConst96;
	int iConst97;
	float fVec66[16384];
	int iConst98;
	int iConst99;
	float fVec67[32768];
	int iConst100;
	float fConst101;
	float fConst102;
	float fRec74[2];
	FAUSTFLOAT fVbargraph4;
	FAUSTFLOAT fVslider19;
	FAUSTFLOAT fVslider20;
	FAUSTFLOAT fVslider21;
	float fConst103;
	int iConst104;
	float fVec68[2];
	float fRec78[2];
	float fRec77[2];
	float fVec69[2];
	float fRec76[2];
	float fRec75[2];
	float fVec70[2];
	float fVec71[3];
	int iConst105;
	int iConst106;
	float fVec72[5];
	int iConst107;
	int iConst108;
	float fVec73[12];
	int iConst109;
	int iConst110;
	float fVec74[32];
	int iConst111;
	int iConst112;
	float fVec75[64];
	int iConst113;
	int iConst114;
	float fVec76[128];
	int iConst115;
	int iConst116;
	float fVec77[256];
	int iConst117;
	int iConst118;
	float fVec78[512];
	int iConst119;
	int iConst120;
	float fVec79[1024];
	int iConst121;
	int iConst122;
	float fVec80[2048];
	int iConst123;
	int iConst124;
	float fVec81[4096];
	int iConst125;
	int iConst126;
	float fVec82[8192];
	int iConst127;
	int iConst128;
	float fVec83[16384];
	int iConst129;
	int iConst130;
	float fVec84[32768];
	int iConst131;
	int iConst132;
	float fVec85[65536];
	int iConst133;
	int iConst134;
	float fVec86[131072];
	int iConst135;
	float fVec87[2];
	float fRec82[2];
	float fRec81[2];
	float fVec88[2];
	float fRec80[2];
	float fRec79[2];
	float fVec89[2];
	float fVec90[3];
	float fVec91[5];
	float fVec92[12];
	float fVec93[32];
	float fVec94[64];
	float fVec95[128];
	float fVec96[256];
	float fVec97[512];
	float fVec98[1024];
	float fVec99[2048];
	float fVec100[4096];
	float fVec101[8192];
	float fVec102[16384];
	float fVec103[32768];
	float fVec104[65536];
	float fVec105[131072];
	float fConst136;
	float fRec73[2];
	FAUSTFLOAT fVbargraph5;
	float fRec72[2];
	FAUSTFLOAT fCheckbox8;
	float fRec83[2];
	FAUSTFLOAT fVslider22;
	float fRec71[262144];
	FAUSTFLOAT fVslider23;
	FAUSTFLOAT fVslider24;
	float fRec70[2];
	FAUSTFLOAT fVslider25;
	float fRec85[262144];
	float fRec84[2];
	FAUSTFLOAT fVslider26;
	FAUSTFLOAT fVbargraph6;
	FAUSTFLOAT fVslider27;
	float fRec86[2];
	FAUSTFLOAT fCheckbox9;
	float fRec87[2];
	FAUSTFLOAT fVbargraph7;
	FAUSTFLOAT fVslider28;
	float fConst137;
	float fRec88[2];
	float fRec10[3];
	float fRec9[3];
	float fRec8[3];
	FAUSTFLOAT fVslider29;
	FAUSTFLOAT fVslider30;
	FAUSTFLOAT fVslider31;
	FAUSTFLOAT fVslider32;
	FAUSTFLOAT fVslider33;
	FAUSTFLOAT fVslider34;
	float fRec7[2];
	float fRec92[3];
	float fRec91[3];
	float fRec90[3];
	float fRec89[2];
	FAUSTFLOAT fVslider35;
	FAUSTFLOAT fVslider36;
	FAUSTFLOAT fVbargraph8;
	FAUSTFLOAT fVslider37;
	FAUSTFLOAT fVslider38;
	float fRec113[3];
	float fRec112[3];
	float fRec111[3];
	float fRec110[3];
	float fRec109[3];
	float fRec108[2];
	float fRec119[3];
	float fRec118[3];
	float fRec117[3];
	float fRec116[3];
	float fRec115[3];
	float fRec114[2];
	FAUSTFLOAT fVbargraph9;
	float fRec155[3];
	float fRec154[3];
	float fRec153[3];
	float fRec152[3];
	float fRec151[3];
	float fRec150[2];
	float fRec161[3];
	float fRec160[3];
	float fRec159[3];
	float fRec158[3];
	float fRec157[3];
	float fRec156[2];
	FAUSTFLOAT fVbargraph10;
	float fRec197[3];
	float fRec196[3];
	float fRec195[3];
	float fRec194[3];
	float fRec193[3];
	float fRec192[2];
	float fRec203[3];
	float fRec202[3];
	float fRec201[3];
	float fRec200[3];
	float fRec199[3];
	float fRec198[2];
	FAUSTFLOAT fVbargraph11;
	float fRec239[3];
	float fRec238[3];
	float fRec237[3];
	float fRec236[3];
	float fRec235[3];
	float fRec234[2];
	float fRec245[3];
	float fRec244[3];
	float fRec243[3];
	float fRec242[3];
	float fRec241[3];
	float fRec240[2];
	FAUSTFLOAT fVbargraph12;
	float fRec281[3];
	float fRec280[3];
	float fRec279[3];
	float fRec278[3];
	float fRec277[3];
	float fRec276[2];
	float fRec287[3];
	float fRec286[3];
	float fRec285[3];
	float fRec284[3];
	float fRec283[3];
	float fRec282[2];
	FAUSTFLOAT fVbargraph13;
	float fRec323[3];
	float fRec322[3];
	float fRec321[3];
	float fRec320[3];
	float fRec319[3];
	float fRec318[2];
	float fRec329[3];
	float fRec328[3];
	float fRec327[3];
	float fRec326[3];
	float fRec325[3];
	float fRec324[2];
	FAUSTFLOAT fVbargraph14;
	float fRec362[3];
	float fRec361[3];
	float fRec360[2];
	float fRec365[3];
	float fRec364[3];
	float fRec363[2];
	FAUSTFLOAT fVbargraph15;
	float fRec376[2];
	float fRec377[2];
	float fRec371[2];
	float fRec372[2];
	float fRec366[2];
	float fRec367[2];
	float fRec355[2];
	float fRec356[2];
	float fRec350[2];
	float fRec351[2];
	float fRec345[2];
	float fRec346[2];
	float fRec340[2];
	float fRec341[2];
	float fRec335[2];
	float fRec336[2];
	float fRec330[2];
	float fRec331[2];
	float fRec313[2];
	float fRec314[2];
	float fRec308[2];
	float fRec309[2];
	float fRec303[2];
	float fRec304[2];
	float fRec298[2];
	float fRec299[2];
	float fRec293[2];
	float fRec294[2];
	float fRec288[2];
	float fRec289[2];
	float fRec271[2];
	float fRec272[2];
	float fRec266[2];
	float fRec267[2];
	float fRec261[2];
	float fRec262[2];
	float fRec256[2];
	float fRec257[2];
	float fRec251[2];
	float fRec252[2];
	float fRec246[2];
	float fRec247[2];
	float fRec229[2];
	float fRec230[2];
	float fRec224[2];
	float fRec225[2];
	float fRec219[2];
	float fRec220[2];
	float fRec214[2];
	float fRec215[2];
	float fRec209[2];
	float fRec210[2];
	float fRec204[2];
	float fRec205[2];
	float fRec187[2];
	float fRec188[2];
	float fRec182[2];
	float fRec183[2];
	float fRec177[2];
	float fRec178[2];
	float fRec172[2];
	float fRec173[2];
	float fRec167[2];
	float fRec168[2];
	float fRec162[2];
	float fRec163[2];
	float fRec145[2];
	float fRec146[2];
	float fRec140[2];
	float fRec141[2];
	float fRec135[2];
	float fRec136[2];
	float fRec130[2];
	float fRec131[2];
	float fRec125[2];
	float fRec126[2];
	float fRec120[2];
	float fRec121[2];
	float fRec103[2];
	float fRec104[2];
	float fRec98[2];
	float fRec99[2];
	float fRec93[2];
	float fRec94[2];
	FAUSTFLOAT fVbargraph16;
	FAUSTFLOAT fVbargraph17;
	FAUSTFLOAT fVbargraph18;
	FAUSTFLOAT fVbargraph19;
	FAUSTFLOAT fVbargraph20;
	FAUSTFLOAT fVbargraph21;
	FAUSTFLOAT fVbargraph22;
	FAUSTFLOAT fVbargraph23;
	float fRec586[2];
	float fRec587[2];
	float fRec581[2];
	float fRec582[2];
	float fRec576[2];
	float fRec577[2];
	float fRec571[2];
	float fRec572[2];
	float fRec566[2];
	float fRec567[2];
	float fRec561[2];
	float fRec562[2];
	float fRec556[2];
	float fRec557[2];
	float fRec551[2];
	float fRec552[2];
	float fRec546[2];
	float fRec547[2];
	float fRec541[2];
	float fRec542[2];
	float fRec536[2];
	float fRec537[2];
	float fRec531[2];
	float fRec532[2];
	float fRec526[2];
	float fRec527[2];
	float fRec521[2];
	float fRec522[2];
	float fRec516[2];
	float fRec517[2];
	float fRec511[2];
	float fRec512[2];
	float fRec506[2];
	float fRec507[2];
	float fRec501[2];
	float fRec502[2];
	float fRec496[2];
	float fRec497[2];
	float fRec491[2];
	float fRec492[2];
	float fRec486[2];
	float fRec487[2];
	float fRec481[2];
	float fRec482[2];
	float fRec476[2];
	float fRec477[2];
	float fRec471[2];
	float fRec472[2];
	float fRec466[2];
	float fRec467[2];
	float fRec461[2];
	float fRec462[2];
	float fRec456[2];
	float fRec457[2];
	float fRec451[2];
	float fRec452[2];
	float fRec446[2];
	float fRec447[2];
	float fRec441[2];
	float fRec442[2];
	float fRec436[2];
	float fRec437[2];
	float fRec431[2];
	float fRec432[2];
	float fRec426[2];
	float fRec427[2];
	float fRec421[2];
	float fRec422[2];
	float fRec416[2];
	float fRec417[2];
	float fRec411[2];
	float fRec412[2];
	float fRec406[2];
	float fRec407[2];
	float fRec401[2];
	float fRec402[2];
	float fRec396[2];
	float fRec397[2];
	float fRec391[2];
	float fRec392[2];
	float fRec386[2];
	float fRec387[2];
	float fRec381[2];
	float fRec382[2];
	FAUSTFLOAT fCheckbox10;
	float fRec591[2];
	FAUSTFLOAT fVslider39;
	float fRec592[2];
	FAUSTFLOAT fCheckbox11;
	float fRec593[2];
	FAUSTFLOAT fVslider40;
	float fRec594[2];
	FAUSTFLOAT fVslider41;
	FAUSTFLOAT fVslider42;
	FAUSTFLOAT fVslider43;
	float fRec598[131072];
	FAUSTFLOAT fVslider44;
	FAUSTFLOAT fVslider45;
	float fRec597[2];
	FAUSTFLOAT fVslider46;
	float fRec600[131072];
	float fRec599[2];
	FAUSTFLOAT fVbargraph24;
	float fRec595[2];
	float fRec596[2];
	FAUSTFLOAT fVslider47;
	float fRec6[2];
	float fRec601[2];
	FAUSTFLOAT fVbargraph25;
	FAUSTFLOAT fCheckbox12;
	float fRec602[2];
	float fRec4[2];
	float fRec5[2];
	float fRec2[3];
	float fRec3[3];
	float fVec106[2];
	float fRec0[2];
	FAUSTFLOAT fVbargraph26;
	float fVec107[2];
	float fVec108[2];
	float fRec607[2];
	float fRec606[2];
	float fVec109[2];
	float fRec605[2];
	float fRec604[2];
	float fVec110[2];
	float fVec111[3];
	float fVec112[5];
	float fVec113[12];
	float fVec114[32];
	float fVec115[64];
	float fVec116[128];
	float fVec117[256];
	float fVec118[512];
	float fVec119[1024];
	float fVec120[2048];
	float fVec121[4096];
	float fVec122[8192];
	float fVec123[16384];
	float fVec124[32768];
	float fVec125[65536];
	float fVec126[131072];
	float fVec127[262144];
	float fVec128[524288];
	float fVec129[1048576];
	float fVec130[2];
	float fRec611[2];
	float fRec610[2];
	float fVec131[2];
	float fRec609[2];
	float fRec608[2];
	float fVec132[2];
	float fVec133[3];
	float fVec134[5];
	float fVec135[12];
	float fVec136[32];
	float fVec137[64];
	float fVec138[128];
	float fVec139[256];
	float fVec140[512];
	float fVec141[1024];
	float fVec142[2048];
	float fVec143[4096];
	float fVec144[8192];
	float fVec145[16384];
	float fVec146[32768];
	float fVec147[65536];
	float fVec148[131072];
	float fVec149[262144];
	float fVec150[524288];
	float fVec151[1048576];
	FAUSTFLOAT fVbargraph27;
	float fRec603[2];
	FAUSTFLOAT fVbargraph28;
	
 public:
	mydsp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("author", "Klaus Scheuermann");
		m->declare("basics.lib/bypass1:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/parallelMin:author", "Bart Brouns");
		m->declare("basics.lib/parallelMin:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelMin:licence", "GPL-3.0");
		m->declare("basics.lib/parallelOp:author", "Bart Brouns");
		m->declare("basics.lib/parallelOp:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelOp:licence", "GPL-3.0");
		m->declare("basics.lib/version", "1.21.0");
		m->declare("compile_options", "-a /tmp/tmpqcmbyo24.cpp -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("compressors.lib/FFcompressor_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/FFcompressor_N_chan:license", "GPLv3");
		m->declare("compressors.lib/RMS_FBFFcompressor_N_chan:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_FBFFcompressor_N_chan:license", "GPLv3");
		m->declare("compressors.lib/RMS_compression_gain_N_chan_db:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_compression_gain_N_chan_db:license", "GPLv3");
		m->declare("compressors.lib/RMS_compression_gain_mono_db:author", "Bart Brouns");
		m->declare("compressors.lib/RMS_compression_gain_mono_db:license", "GPLv3");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/peak_compression_gain_N_chan_db:author", "Bart Brouns");
		m->declare("compressors.lib/peak_compression_gain_N_chan_db:license", "GPLv3");
		m->declare("compressors.lib/peak_compression_gain_mono_db:author", "Bart Brouns");
		m->declare("compressors.lib/peak_compression_gain_mono_db:license", "GPLv3");
		m->declare("compressors.lib/version", "1.6.0");
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
		m->declare("filters.lib/version", "1.7.1");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("interpolators.lib/interpolate_linear:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_linear:licence", "MIT");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/version", "1.4.0");
		m->declare("lib/ebur128.dsp/author", "Jakob Dübel");
		m->declare("lib/ebur128.dsp/license", "ISC");
		m->declare("lib/ebur128.dsp/name", "ITU-R BS.1770-4 prefilter");
		m->declare("lib/ebur128.dsp/version", "1.0");
		m->declare("license", "GPLv3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("misceffects.lib/gate_gain_mono:author", "Julius O. Smith III");
		m->declare("misceffects.lib/gate_gain_mono:license", "STK-4.3");
		m->declare("misceffects.lib/gate_stereo:author", "Julius O. Smith III");
		m->declare("misceffects.lib/gate_stereo:license", "STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.1");
		m->declare("name", "master_me");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "1.6.0");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 8e+01f / fConst0;
		fConst2 = 44.1f / fConst0;
		fConst3 = 1.0f - fConst2;
		fConst4 = 3.1415927f / fConst0;
		fConst5 = 1.0f / fConst0;
		fConst6 = std::rint(3.0f * fConst0);
		iConst7 = int(std::floor(0.5f * fConst6)) % 2;
		fConst8 = std::tan(5283.415f / fConst0);
		fConst9 = 1.7803667f * fConst8;
		fConst10 = mydsp_faustpower2_f(fConst8);
		fConst11 = fConst10 + fConst9 + 1.5848527f;
		fConst12 = 2.0f * (fConst10 + -1.0f);
		fConst13 = fConst10 + (1.5848527f - fConst9);
		fConst14 = 1.4142135f * fConst8;
		fConst15 = fConst10 + (1.0f - fConst14);
		fConst16 = 2.0f * (fConst10 + -1.5848527f);
		fConst17 = 1.0f / (fConst10 + fConst14 + 1.0f);
		fConst18 = std::tan(119.806114f / fConst0);
		fConst19 = mydsp_faustpower2_f(fConst18);
		fConst20 = 1.0006541f * (fConst19 + -1.0f);
		fConst21 = 0.50032705f * (fConst19 + 1.0f);
		fConst22 = fConst21 - fConst18;
		fConst23 = 1.0f / (fConst18 + fConst21);
		iConst24 = int(std::floor(fConst6)) % 2;
		iConst25 = int(std::floor(0.25f * fConst6)) % 2;
		iConst26 = iConst24 + 2 * iConst7;
		iConst27 = int(std::floor(0.125f * fConst6)) % 2;
		iConst28 = iConst26 + 4 * iConst25;
		iConst29 = int(std::floor(0.0625f * fConst6)) % 2;
		iConst30 = iConst28 + 8 * iConst27;
		iConst31 = int(std::floor(0.03125f * fConst6)) % 2;
		iConst32 = iConst30 + 16 * iConst29;
		iConst33 = int(std::floor(0.015625f * fConst6)) % 2;
		iConst34 = iConst32 + 32 * iConst31;
		iConst35 = int(std::floor(0.0078125f * fConst6)) % 2;
		iConst36 = iConst34 + 64 * iConst33;
		iConst37 = int(std::floor(0.00390625f * fConst6)) % 2;
		iConst38 = iConst36 + 128 * iConst35;
		iConst39 = int(std::floor(0.001953125f * fConst6)) % 2;
		iConst40 = iConst38 + 256 * iConst37;
		iConst41 = int(std::floor(0.0009765625f * fConst6)) % 2;
		iConst42 = iConst40 + 512 * iConst39;
		iConst43 = int(std::floor(0.00048828125f * fConst6)) % 2;
		iConst44 = iConst42 + 1024 * iConst41;
		iConst45 = int(std::floor(0.00024414062f * fConst6)) % 2;
		iConst46 = iConst44 + 2048 * iConst43;
		iConst47 = int(std::floor(0.00012207031f * fConst6)) % 2;
		iConst48 = iConst46 + 4096 * iConst45;
		iConst49 = int(std::floor(6.1035156e-05f * fConst6)) % 2;
		iConst50 = iConst48 + 8192 * iConst47;
		iConst51 = int(std::floor(3.0517578e-05f * fConst6)) % 2;
		iConst52 = iConst50 + 16384 * iConst49;
		iConst53 = int(std::floor(1.5258789e-05f * fConst6)) % 2;
		iConst54 = iConst52 + 32768 * iConst51;
		iConst55 = int(std::floor(7.6293945e-06f * fConst6)) % 2;
		iConst56 = iConst54 + 65536 * iConst53;
		iConst57 = int(std::floor(3.8146973e-06f * fConst6)) % 2;
		iConst58 = iConst56 + 131072 * iConst55;
		iConst59 = int(std::floor(1.9073486e-06f * fConst6)) % 2;
		iConst60 = iConst58 + 262144 * iConst57;
		fConst61 = 1.0f / std::max<float>(fConst6, 1.1920929e-07f);
		fConst62 = 31.415926f / fConst0;
		fConst63 = 1.0f - fConst62;
		fConst64 = 1.0f / (fConst62 + 1.0f);
		fConst65 = std::exp(-(12.566371f / fConst0));
		fConst66 = std::exp(-fConst62);
		fConst67 = 1.0f - fConst66;
		fConst68 = 1.0f - fConst65;
		fConst69 = 0.001f * fConst0;
		fConst70 = 1.0f / std::tan(1979.2034f / fConst0);
		fConst71 = 1.0f - fConst70;
		fConst72 = 1.0f / (fConst70 + 1.0f);
		iConst73 = int(std::floor(0.1f * fConst0)) % 2;
		iConst74 = int(std::floor(0.05f * fConst0)) % 2;
		iConst75 = int(std::floor(0.025f * fConst0)) % 2;
		iConst76 = iConst73 + 2 * iConst74;
		iConst77 = int(std::floor(0.0125f * fConst0)) % 2;
		iConst78 = iConst76 + 4 * iConst75;
		iConst79 = int(std::floor(0.00625f * fConst0)) % 2;
		iConst80 = iConst78 + 8 * iConst77;
		iConst81 = int(std::floor(0.003125f * fConst0)) % 2;
		iConst82 = iConst80 + 16 * iConst79;
		iConst83 = int(std::floor(0.0015625f * fConst0)) % 2;
		iConst84 = iConst82 + 32 * iConst81;
		iConst85 = int(std::floor(0.00078125f * fConst0)) % 2;
		iConst86 = iConst84 + 64 * iConst83;
		iConst87 = int(std::floor(0.000390625f * fConst0)) % 2;
		iConst88 = iConst86 + 128 * iConst85;
		iConst89 = int(std::floor(0.0001953125f * fConst0)) % 2;
		iConst90 = iConst88 + 256 * iConst87;
		iConst91 = int(std::floor(9.765625e-05f * fConst0)) % 2;
		iConst92 = iConst90 + 512 * iConst89;
		iConst93 = int(std::floor(4.8828126e-05f * fConst0)) % 2;
		iConst94 = iConst92 + 1024 * iConst91;
		iConst95 = int(std::floor(2.4414063e-05f * fConst0)) % 2;
		iConst96 = iConst94 + 2048 * iConst93;
		iConst97 = int(std::floor(1.2207031e-05f * fConst0)) % 2;
		iConst98 = iConst96 + 4096 * iConst95;
		iConst99 = int(std::floor(6.1035157e-06f * fConst0)) % 2;
		iConst100 = iConst98 + 8192 * iConst97;
		fConst101 = std::exp(-(3.3333333f / fConst0));
		fConst102 = std::exp(-(2e+01f / fConst0));
		fConst103 = std::rint(0.4f * fConst0);
		iConst104 = int(std::floor(0.5f * fConst103)) % 2;
		iConst105 = int(std::floor(fConst103)) % 2;
		iConst106 = int(std::floor(0.25f * fConst103)) % 2;
		iConst107 = iConst105 + 2 * iConst104;
		iConst108 = int(std::floor(0.125f * fConst103)) % 2;
		iConst109 = iConst107 + 4 * iConst106;
		iConst110 = int(std::floor(0.0625f * fConst103)) % 2;
		iConst111 = iConst109 + 8 * iConst108;
		iConst112 = int(std::floor(0.03125f * fConst103)) % 2;
		iConst113 = iConst111 + 16 * iConst110;
		iConst114 = int(std::floor(0.015625f * fConst103)) % 2;
		iConst115 = iConst113 + 32 * iConst112;
		iConst116 = int(std::floor(0.0078125f * fConst103)) % 2;
		iConst117 = iConst115 + 64 * iConst114;
		iConst118 = int(std::floor(0.00390625f * fConst103)) % 2;
		iConst119 = iConst117 + 128 * iConst116;
		iConst120 = int(std::floor(0.001953125f * fConst103)) % 2;
		iConst121 = iConst119 + 256 * iConst118;
		iConst122 = int(std::floor(0.0009765625f * fConst103)) % 2;
		iConst123 = iConst121 + 512 * iConst120;
		iConst124 = int(std::floor(0.00048828125f * fConst103)) % 2;
		iConst125 = iConst123 + 1024 * iConst122;
		iConst126 = int(std::floor(0.00024414062f * fConst103)) % 2;
		iConst127 = iConst125 + 2048 * iConst124;
		iConst128 = int(std::floor(0.00012207031f * fConst103)) % 2;
		iConst129 = iConst127 + 4096 * iConst126;
		iConst130 = int(std::floor(6.1035156e-05f * fConst103)) % 2;
		iConst131 = iConst129 + 8192 * iConst128;
		iConst132 = int(std::floor(3.0517578e-05f * fConst103)) % 2;
		iConst133 = iConst131 + 16384 * iConst130;
		iConst134 = int(std::floor(1.5258789e-05f * fConst103)) % 2;
		iConst135 = iConst133 + 32768 * iConst132;
		fConst136 = 1.0f / std::max<float>(fConst103, 1.1920929e-07f);
		fConst137 = 0.441f / fConst0;
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fVslider0 = FAUSTFLOAT(-1.0f);
		fVslider1 = FAUSTFLOAT(12.0f);
		fVslider2 = FAUSTFLOAT(-18.0f);
		fVslider3 = FAUSTFLOAT(-12.0f);
		fVslider4 = FAUSTFLOAT(6e+01f);
		fVslider5 = FAUSTFLOAT(8e+03f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fVslider6 = FAUSTFLOAT(-9e+01f);
		fVslider7 = FAUSTFLOAT(0.0f);
		fVslider8 = FAUSTFLOAT(5e+02f);
		fVslider9 = FAUSTFLOAT(0.0f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fCheckbox6 = FAUSTFLOAT(0.0f);
		fVslider10 = FAUSTFLOAT(5e+01f);
		fCheckbox7 = FAUSTFLOAT(0.0f);
		fVslider11 = FAUSTFLOAT(0.0f);
		fVslider12 = FAUSTFLOAT(1.0f);
		fVslider13 = FAUSTFLOAT(6e+02f);
		fVslider14 = FAUSTFLOAT(0.0f);
		fVslider15 = FAUSTFLOAT(5.0f);
		fVslider16 = FAUSTFLOAT(6.0f);
		fVslider17 = FAUSTFLOAT(-6.0f);
		fVslider18 = FAUSTFLOAT(-14.0f);
		fVslider19 = FAUSTFLOAT(2e+01f);
		fVslider20 = FAUSTFLOAT(2e+01f);
		fVslider21 = FAUSTFLOAT(2e+01f);
		fCheckbox8 = FAUSTFLOAT(0.0f);
		fVslider22 = FAUSTFLOAT(5e+01f);
		fVslider23 = FAUSTFLOAT(2e+02f);
		fVslider24 = FAUSTFLOAT(2e+01f);
		fVslider25 = FAUSTFLOAT(2e+01f);
		fVslider26 = FAUSTFLOAT(6e+01f);
		fVslider27 = FAUSTFLOAT(0.0f);
		fCheckbox9 = FAUSTFLOAT(0.0f);
		fVslider28 = FAUSTFLOAT(1e+02f);
		fVslider29 = FAUSTFLOAT(1e+01f);
		fVslider30 = FAUSTFLOAT(1e+01f);
		fVslider31 = FAUSTFLOAT(15.0f);
		fVslider32 = FAUSTFLOAT(3.0f);
		fVslider33 = FAUSTFLOAT(1.5e+02f);
		fVslider34 = FAUSTFLOAT(3e+01f);
		fVslider35 = FAUSTFLOAT(6e+01f);
		fVslider36 = FAUSTFLOAT(3e+01f);
		fVslider37 = FAUSTFLOAT(12.0f);
		fVslider38 = FAUSTFLOAT(-6.0f);
		fCheckbox10 = FAUSTFLOAT(0.0f);
		fVslider39 = FAUSTFLOAT(1.0f);
		fCheckbox11 = FAUSTFLOAT(0.0f);
		fVslider40 = FAUSTFLOAT(0.0f);
		fVslider41 = FAUSTFLOAT(8.0f);
		fVslider42 = FAUSTFLOAT(6.0f);
		fVslider43 = FAUSTFLOAT(5e+01f);
		fVslider44 = FAUSTFLOAT(4e+01f);
		fVslider45 = FAUSTFLOAT(1.0f);
		fVslider46 = FAUSTFLOAT(8e+01f);
		fVslider47 = FAUSTFLOAT(75.0f);
		fCheckbox12 = FAUSTFLOAT(0.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec11[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec21[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec20[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec19[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec18[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fVec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec17[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec16[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = l12 + 1) {
			fVec4[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 5; l13 = l13 + 1) {
			fVec5[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 12; l14 = l14 + 1) {
			fVec6[l14] = 0.0f;
		}
		IOTA0 = 0;
		for (int l15 = 0; l15 < 32; l15 = l15 + 1) {
			fVec7[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 64; l16 = l16 + 1) {
			fVec8[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 128; l17 = l17 + 1) {
			fVec9[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 256; l18 = l18 + 1) {
			fVec10[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 512; l19 = l19 + 1) {
			fVec11[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 1024; l20 = l20 + 1) {
			fVec12[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2048; l21 = l21 + 1) {
			fVec13[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 4096; l22 = l22 + 1) {
			fVec14[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 8192; l23 = l23 + 1) {
			fVec15[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 16384; l24 = l24 + 1) {
			fVec16[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 32768; l25 = l25 + 1) {
			fVec17[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 65536; l26 = l26 + 1) {
			fVec18[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 131072; l27 = l27 + 1) {
			fVec19[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 262144; l28 = l28 + 1) {
			fVec20[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 524288; l29 = l29 + 1) {
			fVec21[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 1048576; l30 = l30 + 1) {
			fVec22[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec26[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fVec23[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fVec24[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec25[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec24[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fVec25[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec23[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec22[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fVec26[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 3; l40 = l40 + 1) {
			fVec27[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 5; l41 = l41 + 1) {
			fVec28[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 12; l42 = l42 + 1) {
			fVec29[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 32; l43 = l43 + 1) {
			fVec30[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 64; l44 = l44 + 1) {
			fVec31[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 128; l45 = l45 + 1) {
			fVec32[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 256; l46 = l46 + 1) {
			fVec33[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 512; l47 = l47 + 1) {
			fVec34[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 1024; l48 = l48 + 1) {
			fVec35[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2048; l49 = l49 + 1) {
			fVec36[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 4096; l50 = l50 + 1) {
			fVec37[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 8192; l51 = l51 + 1) {
			fVec38[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 16384; l52 = l52 + 1) {
			fVec39[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 32768; l53 = l53 + 1) {
			fVec40[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 65536; l54 = l54 + 1) {
			fVec41[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 131072; l55 = l55 + 1) {
			fVec42[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 262144; l56 = l56 + 1) {
			fVec43[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 524288; l57 = l57 + 1) {
			fVec44[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 1048576; l58 = l58 + 1) {
			fVec45[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fVec46[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec27[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec28[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec29[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec30[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec34[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			fRec33[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec36[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec35[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec37[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			fRec32[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec31[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec39[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec38[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			fRec41[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			fRec40[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			fRec43[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			fRec42[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec45[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec44[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec46[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			fRec15[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			iVec47[l81] = 0;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			iRec47[l82] = 0;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			fRec14[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fRec13[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			iVec48[l85] = 0;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			iRec48[l86] = 0;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec12[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec49[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			fRec50[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			fRec59[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fVec49[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fRec62[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			fRec61[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			fRec63[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			fVec50[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			fRec60[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec64[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 2; l98 = l98 + 1) {
			fVec51[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fRec67[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			fRec66[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fRec68[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fVec52[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			fRec65[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			fRec69[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fRec55[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fRec56[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			fRec51[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			fRec52[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fVec53[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 3; l110 = l110 + 1) {
			fVec54[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 5; l111 = l111 + 1) {
			fVec55[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 12; l112 = l112 + 1) {
			fVec56[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 32; l113 = l113 + 1) {
			fVec57[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 64; l114 = l114 + 1) {
			fVec58[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 128; l115 = l115 + 1) {
			fVec59[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 256; l116 = l116 + 1) {
			fVec60[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 512; l117 = l117 + 1) {
			fVec61[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 1024; l118 = l118 + 1) {
			fVec62[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 2048; l119 = l119 + 1) {
			fVec63[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 4096; l120 = l120 + 1) {
			fVec64[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 8192; l121 = l121 + 1) {
			fVec65[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 16384; l122 = l122 + 1) {
			fVec66[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 32768; l123 = l123 + 1) {
			fVec67[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec74[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fVec68[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			fRec78[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 2; l127 = l127 + 1) {
			fRec77[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			fVec69[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			fRec76[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 2; l130 = l130 + 1) {
			fRec75[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			fVec70[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 3; l132 = l132 + 1) {
			fVec71[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 5; l133 = l133 + 1) {
			fVec72[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 12; l134 = l134 + 1) {
			fVec73[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 32; l135 = l135 + 1) {
			fVec74[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 64; l136 = l136 + 1) {
			fVec75[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 128; l137 = l137 + 1) {
			fVec76[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 256; l138 = l138 + 1) {
			fVec77[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 512; l139 = l139 + 1) {
			fVec78[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 1024; l140 = l140 + 1) {
			fVec79[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 2048; l141 = l141 + 1) {
			fVec80[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 4096; l142 = l142 + 1) {
			fVec81[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 8192; l143 = l143 + 1) {
			fVec82[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 16384; l144 = l144 + 1) {
			fVec83[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 32768; l145 = l145 + 1) {
			fVec84[l145] = 0.0f;
		}
		for (int l146 = 0; l146 < 65536; l146 = l146 + 1) {
			fVec85[l146] = 0.0f;
		}
		for (int l147 = 0; l147 < 131072; l147 = l147 + 1) {
			fVec86[l147] = 0.0f;
		}
		for (int l148 = 0; l148 < 2; l148 = l148 + 1) {
			fVec87[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			fRec82[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			fRec81[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 2; l151 = l151 + 1) {
			fVec88[l151] = 0.0f;
		}
		for (int l152 = 0; l152 < 2; l152 = l152 + 1) {
			fRec80[l152] = 0.0f;
		}
		for (int l153 = 0; l153 < 2; l153 = l153 + 1) {
			fRec79[l153] = 0.0f;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fVec89[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 3; l155 = l155 + 1) {
			fVec90[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 5; l156 = l156 + 1) {
			fVec91[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 12; l157 = l157 + 1) {
			fVec92[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 32; l158 = l158 + 1) {
			fVec93[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 64; l159 = l159 + 1) {
			fVec94[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 128; l160 = l160 + 1) {
			fVec95[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 256; l161 = l161 + 1) {
			fVec96[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 512; l162 = l162 + 1) {
			fVec97[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 1024; l163 = l163 + 1) {
			fVec98[l163] = 0.0f;
		}
		for (int l164 = 0; l164 < 2048; l164 = l164 + 1) {
			fVec99[l164] = 0.0f;
		}
		for (int l165 = 0; l165 < 4096; l165 = l165 + 1) {
			fVec100[l165] = 0.0f;
		}
		for (int l166 = 0; l166 < 8192; l166 = l166 + 1) {
			fVec101[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 16384; l167 = l167 + 1) {
			fVec102[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 32768; l168 = l168 + 1) {
			fVec103[l168] = 0.0f;
		}
		for (int l169 = 0; l169 < 65536; l169 = l169 + 1) {
			fVec104[l169] = 0.0f;
		}
		for (int l170 = 0; l170 < 131072; l170 = l170 + 1) {
			fVec105[l170] = 0.0f;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			fRec73[l171] = 0.0f;
		}
		for (int l172 = 0; l172 < 2; l172 = l172 + 1) {
			fRec72[l172] = 0.0f;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			fRec83[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 262144; l174 = l174 + 1) {
			fRec71[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 2; l175 = l175 + 1) {
			fRec70[l175] = 0.0f;
		}
		for (int l176 = 0; l176 < 262144; l176 = l176 + 1) {
			fRec85[l176] = 0.0f;
		}
		for (int l177 = 0; l177 < 2; l177 = l177 + 1) {
			fRec84[l177] = 0.0f;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fRec86[l178] = 0.0f;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			fRec87[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fRec88[l180] = 0.0f;
		}
		for (int l181 = 0; l181 < 3; l181 = l181 + 1) {
			fRec10[l181] = 0.0f;
		}
		for (int l182 = 0; l182 < 3; l182 = l182 + 1) {
			fRec9[l182] = 0.0f;
		}
		for (int l183 = 0; l183 < 3; l183 = l183 + 1) {
			fRec8[l183] = 0.0f;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fRec7[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 3; l185 = l185 + 1) {
			fRec92[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 3; l186 = l186 + 1) {
			fRec91[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 3; l187 = l187 + 1) {
			fRec90[l187] = 0.0f;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fRec89[l188] = 0.0f;
		}
		for (int l189 = 0; l189 < 3; l189 = l189 + 1) {
			fRec113[l189] = 0.0f;
		}
		for (int l190 = 0; l190 < 3; l190 = l190 + 1) {
			fRec112[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 3; l191 = l191 + 1) {
			fRec111[l191] = 0.0f;
		}
		for (int l192 = 0; l192 < 3; l192 = l192 + 1) {
			fRec110[l192] = 0.0f;
		}
		for (int l193 = 0; l193 < 3; l193 = l193 + 1) {
			fRec109[l193] = 0.0f;
		}
		for (int l194 = 0; l194 < 2; l194 = l194 + 1) {
			fRec108[l194] = 0.0f;
		}
		for (int l195 = 0; l195 < 3; l195 = l195 + 1) {
			fRec119[l195] = 0.0f;
		}
		for (int l196 = 0; l196 < 3; l196 = l196 + 1) {
			fRec118[l196] = 0.0f;
		}
		for (int l197 = 0; l197 < 3; l197 = l197 + 1) {
			fRec117[l197] = 0.0f;
		}
		for (int l198 = 0; l198 < 3; l198 = l198 + 1) {
			fRec116[l198] = 0.0f;
		}
		for (int l199 = 0; l199 < 3; l199 = l199 + 1) {
			fRec115[l199] = 0.0f;
		}
		for (int l200 = 0; l200 < 2; l200 = l200 + 1) {
			fRec114[l200] = 0.0f;
		}
		for (int l201 = 0; l201 < 3; l201 = l201 + 1) {
			fRec155[l201] = 0.0f;
		}
		for (int l202 = 0; l202 < 3; l202 = l202 + 1) {
			fRec154[l202] = 0.0f;
		}
		for (int l203 = 0; l203 < 3; l203 = l203 + 1) {
			fRec153[l203] = 0.0f;
		}
		for (int l204 = 0; l204 < 3; l204 = l204 + 1) {
			fRec152[l204] = 0.0f;
		}
		for (int l205 = 0; l205 < 3; l205 = l205 + 1) {
			fRec151[l205] = 0.0f;
		}
		for (int l206 = 0; l206 < 2; l206 = l206 + 1) {
			fRec150[l206] = 0.0f;
		}
		for (int l207 = 0; l207 < 3; l207 = l207 + 1) {
			fRec161[l207] = 0.0f;
		}
		for (int l208 = 0; l208 < 3; l208 = l208 + 1) {
			fRec160[l208] = 0.0f;
		}
		for (int l209 = 0; l209 < 3; l209 = l209 + 1) {
			fRec159[l209] = 0.0f;
		}
		for (int l210 = 0; l210 < 3; l210 = l210 + 1) {
			fRec158[l210] = 0.0f;
		}
		for (int l211 = 0; l211 < 3; l211 = l211 + 1) {
			fRec157[l211] = 0.0f;
		}
		for (int l212 = 0; l212 < 2; l212 = l212 + 1) {
			fRec156[l212] = 0.0f;
		}
		for (int l213 = 0; l213 < 3; l213 = l213 + 1) {
			fRec197[l213] = 0.0f;
		}
		for (int l214 = 0; l214 < 3; l214 = l214 + 1) {
			fRec196[l214] = 0.0f;
		}
		for (int l215 = 0; l215 < 3; l215 = l215 + 1) {
			fRec195[l215] = 0.0f;
		}
		for (int l216 = 0; l216 < 3; l216 = l216 + 1) {
			fRec194[l216] = 0.0f;
		}
		for (int l217 = 0; l217 < 3; l217 = l217 + 1) {
			fRec193[l217] = 0.0f;
		}
		for (int l218 = 0; l218 < 2; l218 = l218 + 1) {
			fRec192[l218] = 0.0f;
		}
		for (int l219 = 0; l219 < 3; l219 = l219 + 1) {
			fRec203[l219] = 0.0f;
		}
		for (int l220 = 0; l220 < 3; l220 = l220 + 1) {
			fRec202[l220] = 0.0f;
		}
		for (int l221 = 0; l221 < 3; l221 = l221 + 1) {
			fRec201[l221] = 0.0f;
		}
		for (int l222 = 0; l222 < 3; l222 = l222 + 1) {
			fRec200[l222] = 0.0f;
		}
		for (int l223 = 0; l223 < 3; l223 = l223 + 1) {
			fRec199[l223] = 0.0f;
		}
		for (int l224 = 0; l224 < 2; l224 = l224 + 1) {
			fRec198[l224] = 0.0f;
		}
		for (int l225 = 0; l225 < 3; l225 = l225 + 1) {
			fRec239[l225] = 0.0f;
		}
		for (int l226 = 0; l226 < 3; l226 = l226 + 1) {
			fRec238[l226] = 0.0f;
		}
		for (int l227 = 0; l227 < 3; l227 = l227 + 1) {
			fRec237[l227] = 0.0f;
		}
		for (int l228 = 0; l228 < 3; l228 = l228 + 1) {
			fRec236[l228] = 0.0f;
		}
		for (int l229 = 0; l229 < 3; l229 = l229 + 1) {
			fRec235[l229] = 0.0f;
		}
		for (int l230 = 0; l230 < 2; l230 = l230 + 1) {
			fRec234[l230] = 0.0f;
		}
		for (int l231 = 0; l231 < 3; l231 = l231 + 1) {
			fRec245[l231] = 0.0f;
		}
		for (int l232 = 0; l232 < 3; l232 = l232 + 1) {
			fRec244[l232] = 0.0f;
		}
		for (int l233 = 0; l233 < 3; l233 = l233 + 1) {
			fRec243[l233] = 0.0f;
		}
		for (int l234 = 0; l234 < 3; l234 = l234 + 1) {
			fRec242[l234] = 0.0f;
		}
		for (int l235 = 0; l235 < 3; l235 = l235 + 1) {
			fRec241[l235] = 0.0f;
		}
		for (int l236 = 0; l236 < 2; l236 = l236 + 1) {
			fRec240[l236] = 0.0f;
		}
		for (int l237 = 0; l237 < 3; l237 = l237 + 1) {
			fRec281[l237] = 0.0f;
		}
		for (int l238 = 0; l238 < 3; l238 = l238 + 1) {
			fRec280[l238] = 0.0f;
		}
		for (int l239 = 0; l239 < 3; l239 = l239 + 1) {
			fRec279[l239] = 0.0f;
		}
		for (int l240 = 0; l240 < 3; l240 = l240 + 1) {
			fRec278[l240] = 0.0f;
		}
		for (int l241 = 0; l241 < 3; l241 = l241 + 1) {
			fRec277[l241] = 0.0f;
		}
		for (int l242 = 0; l242 < 2; l242 = l242 + 1) {
			fRec276[l242] = 0.0f;
		}
		for (int l243 = 0; l243 < 3; l243 = l243 + 1) {
			fRec287[l243] = 0.0f;
		}
		for (int l244 = 0; l244 < 3; l244 = l244 + 1) {
			fRec286[l244] = 0.0f;
		}
		for (int l245 = 0; l245 < 3; l245 = l245 + 1) {
			fRec285[l245] = 0.0f;
		}
		for (int l246 = 0; l246 < 3; l246 = l246 + 1) {
			fRec284[l246] = 0.0f;
		}
		for (int l247 = 0; l247 < 3; l247 = l247 + 1) {
			fRec283[l247] = 0.0f;
		}
		for (int l248 = 0; l248 < 2; l248 = l248 + 1) {
			fRec282[l248] = 0.0f;
		}
		for (int l249 = 0; l249 < 3; l249 = l249 + 1) {
			fRec323[l249] = 0.0f;
		}
		for (int l250 = 0; l250 < 3; l250 = l250 + 1) {
			fRec322[l250] = 0.0f;
		}
		for (int l251 = 0; l251 < 3; l251 = l251 + 1) {
			fRec321[l251] = 0.0f;
		}
		for (int l252 = 0; l252 < 3; l252 = l252 + 1) {
			fRec320[l252] = 0.0f;
		}
		for (int l253 = 0; l253 < 3; l253 = l253 + 1) {
			fRec319[l253] = 0.0f;
		}
		for (int l254 = 0; l254 < 2; l254 = l254 + 1) {
			fRec318[l254] = 0.0f;
		}
		for (int l255 = 0; l255 < 3; l255 = l255 + 1) {
			fRec329[l255] = 0.0f;
		}
		for (int l256 = 0; l256 < 3; l256 = l256 + 1) {
			fRec328[l256] = 0.0f;
		}
		for (int l257 = 0; l257 < 3; l257 = l257 + 1) {
			fRec327[l257] = 0.0f;
		}
		for (int l258 = 0; l258 < 3; l258 = l258 + 1) {
			fRec326[l258] = 0.0f;
		}
		for (int l259 = 0; l259 < 3; l259 = l259 + 1) {
			fRec325[l259] = 0.0f;
		}
		for (int l260 = 0; l260 < 2; l260 = l260 + 1) {
			fRec324[l260] = 0.0f;
		}
		for (int l261 = 0; l261 < 3; l261 = l261 + 1) {
			fRec362[l261] = 0.0f;
		}
		for (int l262 = 0; l262 < 3; l262 = l262 + 1) {
			fRec361[l262] = 0.0f;
		}
		for (int l263 = 0; l263 < 2; l263 = l263 + 1) {
			fRec360[l263] = 0.0f;
		}
		for (int l264 = 0; l264 < 3; l264 = l264 + 1) {
			fRec365[l264] = 0.0f;
		}
		for (int l265 = 0; l265 < 3; l265 = l265 + 1) {
			fRec364[l265] = 0.0f;
		}
		for (int l266 = 0; l266 < 2; l266 = l266 + 1) {
			fRec363[l266] = 0.0f;
		}
		for (int l267 = 0; l267 < 2; l267 = l267 + 1) {
			fRec376[l267] = 0.0f;
		}
		for (int l268 = 0; l268 < 2; l268 = l268 + 1) {
			fRec377[l268] = 0.0f;
		}
		for (int l269 = 0; l269 < 2; l269 = l269 + 1) {
			fRec371[l269] = 0.0f;
		}
		for (int l270 = 0; l270 < 2; l270 = l270 + 1) {
			fRec372[l270] = 0.0f;
		}
		for (int l271 = 0; l271 < 2; l271 = l271 + 1) {
			fRec366[l271] = 0.0f;
		}
		for (int l272 = 0; l272 < 2; l272 = l272 + 1) {
			fRec367[l272] = 0.0f;
		}
		for (int l273 = 0; l273 < 2; l273 = l273 + 1) {
			fRec355[l273] = 0.0f;
		}
		for (int l274 = 0; l274 < 2; l274 = l274 + 1) {
			fRec356[l274] = 0.0f;
		}
		for (int l275 = 0; l275 < 2; l275 = l275 + 1) {
			fRec350[l275] = 0.0f;
		}
		for (int l276 = 0; l276 < 2; l276 = l276 + 1) {
			fRec351[l276] = 0.0f;
		}
		for (int l277 = 0; l277 < 2; l277 = l277 + 1) {
			fRec345[l277] = 0.0f;
		}
		for (int l278 = 0; l278 < 2; l278 = l278 + 1) {
			fRec346[l278] = 0.0f;
		}
		for (int l279 = 0; l279 < 2; l279 = l279 + 1) {
			fRec340[l279] = 0.0f;
		}
		for (int l280 = 0; l280 < 2; l280 = l280 + 1) {
			fRec341[l280] = 0.0f;
		}
		for (int l281 = 0; l281 < 2; l281 = l281 + 1) {
			fRec335[l281] = 0.0f;
		}
		for (int l282 = 0; l282 < 2; l282 = l282 + 1) {
			fRec336[l282] = 0.0f;
		}
		for (int l283 = 0; l283 < 2; l283 = l283 + 1) {
			fRec330[l283] = 0.0f;
		}
		for (int l284 = 0; l284 < 2; l284 = l284 + 1) {
			fRec331[l284] = 0.0f;
		}
		for (int l285 = 0; l285 < 2; l285 = l285 + 1) {
			fRec313[l285] = 0.0f;
		}
		for (int l286 = 0; l286 < 2; l286 = l286 + 1) {
			fRec314[l286] = 0.0f;
		}
		for (int l287 = 0; l287 < 2; l287 = l287 + 1) {
			fRec308[l287] = 0.0f;
		}
		for (int l288 = 0; l288 < 2; l288 = l288 + 1) {
			fRec309[l288] = 0.0f;
		}
		for (int l289 = 0; l289 < 2; l289 = l289 + 1) {
			fRec303[l289] = 0.0f;
		}
		for (int l290 = 0; l290 < 2; l290 = l290 + 1) {
			fRec304[l290] = 0.0f;
		}
		for (int l291 = 0; l291 < 2; l291 = l291 + 1) {
			fRec298[l291] = 0.0f;
		}
		for (int l292 = 0; l292 < 2; l292 = l292 + 1) {
			fRec299[l292] = 0.0f;
		}
		for (int l293 = 0; l293 < 2; l293 = l293 + 1) {
			fRec293[l293] = 0.0f;
		}
		for (int l294 = 0; l294 < 2; l294 = l294 + 1) {
			fRec294[l294] = 0.0f;
		}
		for (int l295 = 0; l295 < 2; l295 = l295 + 1) {
			fRec288[l295] = 0.0f;
		}
		for (int l296 = 0; l296 < 2; l296 = l296 + 1) {
			fRec289[l296] = 0.0f;
		}
		for (int l297 = 0; l297 < 2; l297 = l297 + 1) {
			fRec271[l297] = 0.0f;
		}
		for (int l298 = 0; l298 < 2; l298 = l298 + 1) {
			fRec272[l298] = 0.0f;
		}
		for (int l299 = 0; l299 < 2; l299 = l299 + 1) {
			fRec266[l299] = 0.0f;
		}
		for (int l300 = 0; l300 < 2; l300 = l300 + 1) {
			fRec267[l300] = 0.0f;
		}
		for (int l301 = 0; l301 < 2; l301 = l301 + 1) {
			fRec261[l301] = 0.0f;
		}
		for (int l302 = 0; l302 < 2; l302 = l302 + 1) {
			fRec262[l302] = 0.0f;
		}
		for (int l303 = 0; l303 < 2; l303 = l303 + 1) {
			fRec256[l303] = 0.0f;
		}
		for (int l304 = 0; l304 < 2; l304 = l304 + 1) {
			fRec257[l304] = 0.0f;
		}
		for (int l305 = 0; l305 < 2; l305 = l305 + 1) {
			fRec251[l305] = 0.0f;
		}
		for (int l306 = 0; l306 < 2; l306 = l306 + 1) {
			fRec252[l306] = 0.0f;
		}
		for (int l307 = 0; l307 < 2; l307 = l307 + 1) {
			fRec246[l307] = 0.0f;
		}
		for (int l308 = 0; l308 < 2; l308 = l308 + 1) {
			fRec247[l308] = 0.0f;
		}
		for (int l309 = 0; l309 < 2; l309 = l309 + 1) {
			fRec229[l309] = 0.0f;
		}
		for (int l310 = 0; l310 < 2; l310 = l310 + 1) {
			fRec230[l310] = 0.0f;
		}
		for (int l311 = 0; l311 < 2; l311 = l311 + 1) {
			fRec224[l311] = 0.0f;
		}
		for (int l312 = 0; l312 < 2; l312 = l312 + 1) {
			fRec225[l312] = 0.0f;
		}
		for (int l313 = 0; l313 < 2; l313 = l313 + 1) {
			fRec219[l313] = 0.0f;
		}
		for (int l314 = 0; l314 < 2; l314 = l314 + 1) {
			fRec220[l314] = 0.0f;
		}
		for (int l315 = 0; l315 < 2; l315 = l315 + 1) {
			fRec214[l315] = 0.0f;
		}
		for (int l316 = 0; l316 < 2; l316 = l316 + 1) {
			fRec215[l316] = 0.0f;
		}
		for (int l317 = 0; l317 < 2; l317 = l317 + 1) {
			fRec209[l317] = 0.0f;
		}
		for (int l318 = 0; l318 < 2; l318 = l318 + 1) {
			fRec210[l318] = 0.0f;
		}
		for (int l319 = 0; l319 < 2; l319 = l319 + 1) {
			fRec204[l319] = 0.0f;
		}
		for (int l320 = 0; l320 < 2; l320 = l320 + 1) {
			fRec205[l320] = 0.0f;
		}
		for (int l321 = 0; l321 < 2; l321 = l321 + 1) {
			fRec187[l321] = 0.0f;
		}
		for (int l322 = 0; l322 < 2; l322 = l322 + 1) {
			fRec188[l322] = 0.0f;
		}
		for (int l323 = 0; l323 < 2; l323 = l323 + 1) {
			fRec182[l323] = 0.0f;
		}
		for (int l324 = 0; l324 < 2; l324 = l324 + 1) {
			fRec183[l324] = 0.0f;
		}
		for (int l325 = 0; l325 < 2; l325 = l325 + 1) {
			fRec177[l325] = 0.0f;
		}
		for (int l326 = 0; l326 < 2; l326 = l326 + 1) {
			fRec178[l326] = 0.0f;
		}
		for (int l327 = 0; l327 < 2; l327 = l327 + 1) {
			fRec172[l327] = 0.0f;
		}
		for (int l328 = 0; l328 < 2; l328 = l328 + 1) {
			fRec173[l328] = 0.0f;
		}
		for (int l329 = 0; l329 < 2; l329 = l329 + 1) {
			fRec167[l329] = 0.0f;
		}
		for (int l330 = 0; l330 < 2; l330 = l330 + 1) {
			fRec168[l330] = 0.0f;
		}
		for (int l331 = 0; l331 < 2; l331 = l331 + 1) {
			fRec162[l331] = 0.0f;
		}
		for (int l332 = 0; l332 < 2; l332 = l332 + 1) {
			fRec163[l332] = 0.0f;
		}
		for (int l333 = 0; l333 < 2; l333 = l333 + 1) {
			fRec145[l333] = 0.0f;
		}
		for (int l334 = 0; l334 < 2; l334 = l334 + 1) {
			fRec146[l334] = 0.0f;
		}
		for (int l335 = 0; l335 < 2; l335 = l335 + 1) {
			fRec140[l335] = 0.0f;
		}
		for (int l336 = 0; l336 < 2; l336 = l336 + 1) {
			fRec141[l336] = 0.0f;
		}
		for (int l337 = 0; l337 < 2; l337 = l337 + 1) {
			fRec135[l337] = 0.0f;
		}
		for (int l338 = 0; l338 < 2; l338 = l338 + 1) {
			fRec136[l338] = 0.0f;
		}
		for (int l339 = 0; l339 < 2; l339 = l339 + 1) {
			fRec130[l339] = 0.0f;
		}
		for (int l340 = 0; l340 < 2; l340 = l340 + 1) {
			fRec131[l340] = 0.0f;
		}
		for (int l341 = 0; l341 < 2; l341 = l341 + 1) {
			fRec125[l341] = 0.0f;
		}
		for (int l342 = 0; l342 < 2; l342 = l342 + 1) {
			fRec126[l342] = 0.0f;
		}
		for (int l343 = 0; l343 < 2; l343 = l343 + 1) {
			fRec120[l343] = 0.0f;
		}
		for (int l344 = 0; l344 < 2; l344 = l344 + 1) {
			fRec121[l344] = 0.0f;
		}
		for (int l345 = 0; l345 < 2; l345 = l345 + 1) {
			fRec103[l345] = 0.0f;
		}
		for (int l346 = 0; l346 < 2; l346 = l346 + 1) {
			fRec104[l346] = 0.0f;
		}
		for (int l347 = 0; l347 < 2; l347 = l347 + 1) {
			fRec98[l347] = 0.0f;
		}
		for (int l348 = 0; l348 < 2; l348 = l348 + 1) {
			fRec99[l348] = 0.0f;
		}
		for (int l349 = 0; l349 < 2; l349 = l349 + 1) {
			fRec93[l349] = 0.0f;
		}
		for (int l350 = 0; l350 < 2; l350 = l350 + 1) {
			fRec94[l350] = 0.0f;
		}
		for (int l351 = 0; l351 < 2; l351 = l351 + 1) {
			fRec586[l351] = 0.0f;
		}
		for (int l352 = 0; l352 < 2; l352 = l352 + 1) {
			fRec587[l352] = 0.0f;
		}
		for (int l353 = 0; l353 < 2; l353 = l353 + 1) {
			fRec581[l353] = 0.0f;
		}
		for (int l354 = 0; l354 < 2; l354 = l354 + 1) {
			fRec582[l354] = 0.0f;
		}
		for (int l355 = 0; l355 < 2; l355 = l355 + 1) {
			fRec576[l355] = 0.0f;
		}
		for (int l356 = 0; l356 < 2; l356 = l356 + 1) {
			fRec577[l356] = 0.0f;
		}
		for (int l357 = 0; l357 < 2; l357 = l357 + 1) {
			fRec571[l357] = 0.0f;
		}
		for (int l358 = 0; l358 < 2; l358 = l358 + 1) {
			fRec572[l358] = 0.0f;
		}
		for (int l359 = 0; l359 < 2; l359 = l359 + 1) {
			fRec566[l359] = 0.0f;
		}
		for (int l360 = 0; l360 < 2; l360 = l360 + 1) {
			fRec567[l360] = 0.0f;
		}
		for (int l361 = 0; l361 < 2; l361 = l361 + 1) {
			fRec561[l361] = 0.0f;
		}
		for (int l362 = 0; l362 < 2; l362 = l362 + 1) {
			fRec562[l362] = 0.0f;
		}
		for (int l363 = 0; l363 < 2; l363 = l363 + 1) {
			fRec556[l363] = 0.0f;
		}
		for (int l364 = 0; l364 < 2; l364 = l364 + 1) {
			fRec557[l364] = 0.0f;
		}
		for (int l365 = 0; l365 < 2; l365 = l365 + 1) {
			fRec551[l365] = 0.0f;
		}
		for (int l366 = 0; l366 < 2; l366 = l366 + 1) {
			fRec552[l366] = 0.0f;
		}
		for (int l367 = 0; l367 < 2; l367 = l367 + 1) {
			fRec546[l367] = 0.0f;
		}
		for (int l368 = 0; l368 < 2; l368 = l368 + 1) {
			fRec547[l368] = 0.0f;
		}
		for (int l369 = 0; l369 < 2; l369 = l369 + 1) {
			fRec541[l369] = 0.0f;
		}
		for (int l370 = 0; l370 < 2; l370 = l370 + 1) {
			fRec542[l370] = 0.0f;
		}
		for (int l371 = 0; l371 < 2; l371 = l371 + 1) {
			fRec536[l371] = 0.0f;
		}
		for (int l372 = 0; l372 < 2; l372 = l372 + 1) {
			fRec537[l372] = 0.0f;
		}
		for (int l373 = 0; l373 < 2; l373 = l373 + 1) {
			fRec531[l373] = 0.0f;
		}
		for (int l374 = 0; l374 < 2; l374 = l374 + 1) {
			fRec532[l374] = 0.0f;
		}
		for (int l375 = 0; l375 < 2; l375 = l375 + 1) {
			fRec526[l375] = 0.0f;
		}
		for (int l376 = 0; l376 < 2; l376 = l376 + 1) {
			fRec527[l376] = 0.0f;
		}
		for (int l377 = 0; l377 < 2; l377 = l377 + 1) {
			fRec521[l377] = 0.0f;
		}
		for (int l378 = 0; l378 < 2; l378 = l378 + 1) {
			fRec522[l378] = 0.0f;
		}
		for (int l379 = 0; l379 < 2; l379 = l379 + 1) {
			fRec516[l379] = 0.0f;
		}
		for (int l380 = 0; l380 < 2; l380 = l380 + 1) {
			fRec517[l380] = 0.0f;
		}
		for (int l381 = 0; l381 < 2; l381 = l381 + 1) {
			fRec511[l381] = 0.0f;
		}
		for (int l382 = 0; l382 < 2; l382 = l382 + 1) {
			fRec512[l382] = 0.0f;
		}
		for (int l383 = 0; l383 < 2; l383 = l383 + 1) {
			fRec506[l383] = 0.0f;
		}
		for (int l384 = 0; l384 < 2; l384 = l384 + 1) {
			fRec507[l384] = 0.0f;
		}
		for (int l385 = 0; l385 < 2; l385 = l385 + 1) {
			fRec501[l385] = 0.0f;
		}
		for (int l386 = 0; l386 < 2; l386 = l386 + 1) {
			fRec502[l386] = 0.0f;
		}
		for (int l387 = 0; l387 < 2; l387 = l387 + 1) {
			fRec496[l387] = 0.0f;
		}
		for (int l388 = 0; l388 < 2; l388 = l388 + 1) {
			fRec497[l388] = 0.0f;
		}
		for (int l389 = 0; l389 < 2; l389 = l389 + 1) {
			fRec491[l389] = 0.0f;
		}
		for (int l390 = 0; l390 < 2; l390 = l390 + 1) {
			fRec492[l390] = 0.0f;
		}
		for (int l391 = 0; l391 < 2; l391 = l391 + 1) {
			fRec486[l391] = 0.0f;
		}
		for (int l392 = 0; l392 < 2; l392 = l392 + 1) {
			fRec487[l392] = 0.0f;
		}
		for (int l393 = 0; l393 < 2; l393 = l393 + 1) {
			fRec481[l393] = 0.0f;
		}
		for (int l394 = 0; l394 < 2; l394 = l394 + 1) {
			fRec482[l394] = 0.0f;
		}
		for (int l395 = 0; l395 < 2; l395 = l395 + 1) {
			fRec476[l395] = 0.0f;
		}
		for (int l396 = 0; l396 < 2; l396 = l396 + 1) {
			fRec477[l396] = 0.0f;
		}
		for (int l397 = 0; l397 < 2; l397 = l397 + 1) {
			fRec471[l397] = 0.0f;
		}
		for (int l398 = 0; l398 < 2; l398 = l398 + 1) {
			fRec472[l398] = 0.0f;
		}
		for (int l399 = 0; l399 < 2; l399 = l399 + 1) {
			fRec466[l399] = 0.0f;
		}
		for (int l400 = 0; l400 < 2; l400 = l400 + 1) {
			fRec467[l400] = 0.0f;
		}
		for (int l401 = 0; l401 < 2; l401 = l401 + 1) {
			fRec461[l401] = 0.0f;
		}
		for (int l402 = 0; l402 < 2; l402 = l402 + 1) {
			fRec462[l402] = 0.0f;
		}
		for (int l403 = 0; l403 < 2; l403 = l403 + 1) {
			fRec456[l403] = 0.0f;
		}
		for (int l404 = 0; l404 < 2; l404 = l404 + 1) {
			fRec457[l404] = 0.0f;
		}
		for (int l405 = 0; l405 < 2; l405 = l405 + 1) {
			fRec451[l405] = 0.0f;
		}
		for (int l406 = 0; l406 < 2; l406 = l406 + 1) {
			fRec452[l406] = 0.0f;
		}
		for (int l407 = 0; l407 < 2; l407 = l407 + 1) {
			fRec446[l407] = 0.0f;
		}
		for (int l408 = 0; l408 < 2; l408 = l408 + 1) {
			fRec447[l408] = 0.0f;
		}
		for (int l409 = 0; l409 < 2; l409 = l409 + 1) {
			fRec441[l409] = 0.0f;
		}
		for (int l410 = 0; l410 < 2; l410 = l410 + 1) {
			fRec442[l410] = 0.0f;
		}
		for (int l411 = 0; l411 < 2; l411 = l411 + 1) {
			fRec436[l411] = 0.0f;
		}
		for (int l412 = 0; l412 < 2; l412 = l412 + 1) {
			fRec437[l412] = 0.0f;
		}
		for (int l413 = 0; l413 < 2; l413 = l413 + 1) {
			fRec431[l413] = 0.0f;
		}
		for (int l414 = 0; l414 < 2; l414 = l414 + 1) {
			fRec432[l414] = 0.0f;
		}
		for (int l415 = 0; l415 < 2; l415 = l415 + 1) {
			fRec426[l415] = 0.0f;
		}
		for (int l416 = 0; l416 < 2; l416 = l416 + 1) {
			fRec427[l416] = 0.0f;
		}
		for (int l417 = 0; l417 < 2; l417 = l417 + 1) {
			fRec421[l417] = 0.0f;
		}
		for (int l418 = 0; l418 < 2; l418 = l418 + 1) {
			fRec422[l418] = 0.0f;
		}
		for (int l419 = 0; l419 < 2; l419 = l419 + 1) {
			fRec416[l419] = 0.0f;
		}
		for (int l420 = 0; l420 < 2; l420 = l420 + 1) {
			fRec417[l420] = 0.0f;
		}
		for (int l421 = 0; l421 < 2; l421 = l421 + 1) {
			fRec411[l421] = 0.0f;
		}
		for (int l422 = 0; l422 < 2; l422 = l422 + 1) {
			fRec412[l422] = 0.0f;
		}
		for (int l423 = 0; l423 < 2; l423 = l423 + 1) {
			fRec406[l423] = 0.0f;
		}
		for (int l424 = 0; l424 < 2; l424 = l424 + 1) {
			fRec407[l424] = 0.0f;
		}
		for (int l425 = 0; l425 < 2; l425 = l425 + 1) {
			fRec401[l425] = 0.0f;
		}
		for (int l426 = 0; l426 < 2; l426 = l426 + 1) {
			fRec402[l426] = 0.0f;
		}
		for (int l427 = 0; l427 < 2; l427 = l427 + 1) {
			fRec396[l427] = 0.0f;
		}
		for (int l428 = 0; l428 < 2; l428 = l428 + 1) {
			fRec397[l428] = 0.0f;
		}
		for (int l429 = 0; l429 < 2; l429 = l429 + 1) {
			fRec391[l429] = 0.0f;
		}
		for (int l430 = 0; l430 < 2; l430 = l430 + 1) {
			fRec392[l430] = 0.0f;
		}
		for (int l431 = 0; l431 < 2; l431 = l431 + 1) {
			fRec386[l431] = 0.0f;
		}
		for (int l432 = 0; l432 < 2; l432 = l432 + 1) {
			fRec387[l432] = 0.0f;
		}
		for (int l433 = 0; l433 < 2; l433 = l433 + 1) {
			fRec381[l433] = 0.0f;
		}
		for (int l434 = 0; l434 < 2; l434 = l434 + 1) {
			fRec382[l434] = 0.0f;
		}
		for (int l435 = 0; l435 < 2; l435 = l435 + 1) {
			fRec591[l435] = 0.0f;
		}
		for (int l436 = 0; l436 < 2; l436 = l436 + 1) {
			fRec592[l436] = 0.0f;
		}
		for (int l437 = 0; l437 < 2; l437 = l437 + 1) {
			fRec593[l437] = 0.0f;
		}
		for (int l438 = 0; l438 < 2; l438 = l438 + 1) {
			fRec594[l438] = 0.0f;
		}
		for (int l439 = 0; l439 < 131072; l439 = l439 + 1) {
			fRec598[l439] = 0.0f;
		}
		for (int l440 = 0; l440 < 2; l440 = l440 + 1) {
			fRec597[l440] = 0.0f;
		}
		for (int l441 = 0; l441 < 131072; l441 = l441 + 1) {
			fRec600[l441] = 0.0f;
		}
		for (int l442 = 0; l442 < 2; l442 = l442 + 1) {
			fRec599[l442] = 0.0f;
		}
		for (int l443 = 0; l443 < 2; l443 = l443 + 1) {
			fRec595[l443] = 0.0f;
		}
		for (int l444 = 0; l444 < 2; l444 = l444 + 1) {
			fRec596[l444] = 0.0f;
		}
		for (int l445 = 0; l445 < 2; l445 = l445 + 1) {
			fRec6[l445] = 0.0f;
		}
		for (int l446 = 0; l446 < 2; l446 = l446 + 1) {
			fRec601[l446] = 0.0f;
		}
		for (int l447 = 0; l447 < 2; l447 = l447 + 1) {
			fRec602[l447] = 0.0f;
		}
		for (int l448 = 0; l448 < 2; l448 = l448 + 1) {
			fRec4[l448] = 0.0f;
		}
		for (int l449 = 0; l449 < 2; l449 = l449 + 1) {
			fRec5[l449] = 0.0f;
		}
		for (int l450 = 0; l450 < 3; l450 = l450 + 1) {
			fRec2[l450] = 0.0f;
		}
		for (int l451 = 0; l451 < 3; l451 = l451 + 1) {
			fRec3[l451] = 0.0f;
		}
		for (int l452 = 0; l452 < 2; l452 = l452 + 1) {
			fVec106[l452] = 0.0f;
		}
		for (int l453 = 0; l453 < 2; l453 = l453 + 1) {
			fRec0[l453] = 0.0f;
		}
		for (int l454 = 0; l454 < 2; l454 = l454 + 1) {
			fVec107[l454] = 0.0f;
		}
		for (int l455 = 0; l455 < 2; l455 = l455 + 1) {
			fVec108[l455] = 0.0f;
		}
		for (int l456 = 0; l456 < 2; l456 = l456 + 1) {
			fRec607[l456] = 0.0f;
		}
		for (int l457 = 0; l457 < 2; l457 = l457 + 1) {
			fRec606[l457] = 0.0f;
		}
		for (int l458 = 0; l458 < 2; l458 = l458 + 1) {
			fVec109[l458] = 0.0f;
		}
		for (int l459 = 0; l459 < 2; l459 = l459 + 1) {
			fRec605[l459] = 0.0f;
		}
		for (int l460 = 0; l460 < 2; l460 = l460 + 1) {
			fRec604[l460] = 0.0f;
		}
		for (int l461 = 0; l461 < 2; l461 = l461 + 1) {
			fVec110[l461] = 0.0f;
		}
		for (int l462 = 0; l462 < 3; l462 = l462 + 1) {
			fVec111[l462] = 0.0f;
		}
		for (int l463 = 0; l463 < 5; l463 = l463 + 1) {
			fVec112[l463] = 0.0f;
		}
		for (int l464 = 0; l464 < 12; l464 = l464 + 1) {
			fVec113[l464] = 0.0f;
		}
		for (int l465 = 0; l465 < 32; l465 = l465 + 1) {
			fVec114[l465] = 0.0f;
		}
		for (int l466 = 0; l466 < 64; l466 = l466 + 1) {
			fVec115[l466] = 0.0f;
		}
		for (int l467 = 0; l467 < 128; l467 = l467 + 1) {
			fVec116[l467] = 0.0f;
		}
		for (int l468 = 0; l468 < 256; l468 = l468 + 1) {
			fVec117[l468] = 0.0f;
		}
		for (int l469 = 0; l469 < 512; l469 = l469 + 1) {
			fVec118[l469] = 0.0f;
		}
		for (int l470 = 0; l470 < 1024; l470 = l470 + 1) {
			fVec119[l470] = 0.0f;
		}
		for (int l471 = 0; l471 < 2048; l471 = l471 + 1) {
			fVec120[l471] = 0.0f;
		}
		for (int l472 = 0; l472 < 4096; l472 = l472 + 1) {
			fVec121[l472] = 0.0f;
		}
		for (int l473 = 0; l473 < 8192; l473 = l473 + 1) {
			fVec122[l473] = 0.0f;
		}
		for (int l474 = 0; l474 < 16384; l474 = l474 + 1) {
			fVec123[l474] = 0.0f;
		}
		for (int l475 = 0; l475 < 32768; l475 = l475 + 1) {
			fVec124[l475] = 0.0f;
		}
		for (int l476 = 0; l476 < 65536; l476 = l476 + 1) {
			fVec125[l476] = 0.0f;
		}
		for (int l477 = 0; l477 < 131072; l477 = l477 + 1) {
			fVec126[l477] = 0.0f;
		}
		for (int l478 = 0; l478 < 262144; l478 = l478 + 1) {
			fVec127[l478] = 0.0f;
		}
		for (int l479 = 0; l479 < 524288; l479 = l479 + 1) {
			fVec128[l479] = 0.0f;
		}
		for (int l480 = 0; l480 < 1048576; l480 = l480 + 1) {
			fVec129[l480] = 0.0f;
		}
		for (int l481 = 0; l481 < 2; l481 = l481 + 1) {
			fVec130[l481] = 0.0f;
		}
		for (int l482 = 0; l482 < 2; l482 = l482 + 1) {
			fRec611[l482] = 0.0f;
		}
		for (int l483 = 0; l483 < 2; l483 = l483 + 1) {
			fRec610[l483] = 0.0f;
		}
		for (int l484 = 0; l484 < 2; l484 = l484 + 1) {
			fVec131[l484] = 0.0f;
		}
		for (int l485 = 0; l485 < 2; l485 = l485 + 1) {
			fRec609[l485] = 0.0f;
		}
		for (int l486 = 0; l486 < 2; l486 = l486 + 1) {
			fRec608[l486] = 0.0f;
		}
		for (int l487 = 0; l487 < 2; l487 = l487 + 1) {
			fVec132[l487] = 0.0f;
		}
		for (int l488 = 0; l488 < 3; l488 = l488 + 1) {
			fVec133[l488] = 0.0f;
		}
		for (int l489 = 0; l489 < 5; l489 = l489 + 1) {
			fVec134[l489] = 0.0f;
		}
		for (int l490 = 0; l490 < 12; l490 = l490 + 1) {
			fVec135[l490] = 0.0f;
		}
		for (int l491 = 0; l491 < 32; l491 = l491 + 1) {
			fVec136[l491] = 0.0f;
		}
		for (int l492 = 0; l492 < 64; l492 = l492 + 1) {
			fVec137[l492] = 0.0f;
		}
		for (int l493 = 0; l493 < 128; l493 = l493 + 1) {
			fVec138[l493] = 0.0f;
		}
		for (int l494 = 0; l494 < 256; l494 = l494 + 1) {
			fVec139[l494] = 0.0f;
		}
		for (int l495 = 0; l495 < 512; l495 = l495 + 1) {
			fVec140[l495] = 0.0f;
		}
		for (int l496 = 0; l496 < 1024; l496 = l496 + 1) {
			fVec141[l496] = 0.0f;
		}
		for (int l497 = 0; l497 < 2048; l497 = l497 + 1) {
			fVec142[l497] = 0.0f;
		}
		for (int l498 = 0; l498 < 4096; l498 = l498 + 1) {
			fVec143[l498] = 0.0f;
		}
		for (int l499 = 0; l499 < 8192; l499 = l499 + 1) {
			fVec144[l499] = 0.0f;
		}
		for (int l500 = 0; l500 < 16384; l500 = l500 + 1) {
			fVec145[l500] = 0.0f;
		}
		for (int l501 = 0; l501 < 32768; l501 = l501 + 1) {
			fVec146[l501] = 0.0f;
		}
		for (int l502 = 0; l502 < 65536; l502 = l502 + 1) {
			fVec147[l502] = 0.0f;
		}
		for (int l503 = 0; l503 < 131072; l503 = l503 + 1) {
			fVec148[l503] = 0.0f;
		}
		for (int l504 = 0; l504 < 262144; l504 = l504 + 1) {
			fVec149[l504] = 0.0f;
		}
		for (int l505 = 0; l505 < 524288; l505 = l505 + 1) {
			fVec150[l505] = 0.0f;
		}
		for (int l506 = 0; l506 < 1048576; l506 = l506 + 1) {
			fVec151[l506] = 0.0f;
		}
		for (int l507 = 0; l507 < 2; l507 = l507 + 1) {
			fRec603[l507] = 0.0f;
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
		ui_interface->declare(&fVbargraph1, "0", "");
		ui_interface->declare(&fVbargraph1, "symbol", "peakmeter_in_l");
		ui_interface->declare(&fVbargraph1, "unit", "dB");
		ui_interface->addVerticalBargraph("in L", &fVbargraph1, FAUSTFLOAT(-7e+01f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph0, "1", "");
		ui_interface->declare(&fVbargraph0, "symbol", "peakmeter_in_r");
		ui_interface->declare(&fVbargraph0, "unit", "dB");
		ui_interface->addVerticalBargraph("in R", &fVbargraph0, FAUSTFLOAT(-7e+01f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph2, "2", "");
		ui_interface->declare(&fVbargraph2, "symbol", "lufs_in");
		ui_interface->declare(&fVbargraph2, "unit", "dB");
		ui_interface->addVerticalBargraph("in lufs-s", &fVbargraph2, FAUSTFLOAT(-7e+01f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVslider2, "3", "");
		ui_interface->declare(&fVslider2, "integer", "");
		ui_interface->declare(&fVslider2, "symbol", "target");
		ui_interface->declare(&fVslider2, "unit", "dB");
		ui_interface->addVerticalSlider("Target", &fVslider2, FAUSTFLOAT(-18.0f), FAUSTFLOAT(-5e+01f), FAUSTFLOAT(-2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph5, "4", "");
		ui_interface->declare(&fVbargraph5, "symbol", "leveler_gain");
		ui_interface->declare(&fVbargraph5, "unit", "dB");
		ui_interface->addVerticalBargraph("leveler gain", &fVbargraph5, FAUSTFLOAT(-5e+01f), FAUSTFLOAT(5e+01f));
		ui_interface->declare(&fVbargraph27, "7", "");
		ui_interface->declare(&fVbargraph27, "symbol", "lufs_out");
		ui_interface->declare(&fVbargraph27, "unit", "dB");
		ui_interface->addVerticalBargraph("out lufs-s", &fVbargraph27, FAUSTFLOAT(-7e+01f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph26, "8", "");
		ui_interface->declare(&fVbargraph26, "symbol", "peakmeter_out_l");
		ui_interface->declare(&fVbargraph26, "unit", "dB");
		ui_interface->addVerticalBargraph("out L", &fVbargraph26, FAUSTFLOAT(-7e+01f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph28, "9", "");
		ui_interface->declare(&fVbargraph28, "symbol", "peakmeter_out_r");
		ui_interface->declare(&fVbargraph28, "unit", "dB");
		ui_interface->addVerticalBargraph("out R", &fVbargraph28, FAUSTFLOAT(-7e+01f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->openTabBox("expert");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("pre-processing");
		ui_interface->declare(&fVslider9, "1", "");
		ui_interface->declare(&fVslider9, "symbol", "in_gain");
		ui_interface->declare(&fVslider9, "unit", "dB");
		ui_interface->addVerticalSlider("input gain", &fVslider9, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1e+02f), FAUSTFLOAT(24.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fCheckbox5, "2", "");
		ui_interface->declare(&fCheckbox5, "symbol", "phase_l");
		ui_interface->addCheckButton("phase L", &fCheckbox5);
		ui_interface->declare(&fCheckbox4, "3", "");
		ui_interface->declare(&fCheckbox4, "symbol", "phase_r");
		ui_interface->addCheckButton("phase R", &fCheckbox4);
		ui_interface->declare(&fCheckbox3, "4", "");
		ui_interface->declare(&fCheckbox3, "symbol", "mono");
		ui_interface->addCheckButton("mono", &fCheckbox3);
		ui_interface->declare(&fCheckbox2, "5", "");
		ui_interface->declare(&fCheckbox2, "symbol", "dc_blocker");
		ui_interface->addCheckButton("dc blocker", &fCheckbox2);
		ui_interface->declare(&fCheckbox6, "6", "");
		ui_interface->declare(&fCheckbox6, "symbol", "stereo_correct");
		ui_interface->addCheckButton("stereo correct", &fCheckbox6);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("gate");
		ui_interface->declare(&fCheckbox1, "1", "");
		ui_interface->declare(&fCheckbox1, "symbol", "gate_bypass");
		ui_interface->addCheckButton("gate bypass", &fCheckbox1);
		ui_interface->declare(&fVslider6, "2", "");
		ui_interface->declare(&fVslider6, "symbol", "gate_threshold");
		ui_interface->declare(&fVslider6, "unit", "dB");
		ui_interface->addVerticalSlider("gate threshold", &fVslider6, FAUSTFLOAT(-9e+01f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider7, "3", "");
		ui_interface->declare(&fVslider7, "symbol", "gate_attack");
		ui_interface->declare(&fVslider7, "unit", "ms");
		ui_interface->addVerticalSlider("gate attack", &fVslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider10, "4", "");
		ui_interface->declare(&fVslider10, "symbol", "gate_hold");
		ui_interface->declare(&fVslider10, "unit", "ms");
		ui_interface->addVerticalSlider("gate hold", &fVslider10, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider8, "5", "");
		ui_interface->declare(&fVslider8, "symbol", "gate_release");
		ui_interface->declare(&fVslider8, "unit", "ms");
		ui_interface->addVerticalSlider("gate release", &fVslider8, FAUSTFLOAT(5e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph3, "6", "");
		ui_interface->declare(&fVbargraph3, "symbol", "gate_meter");
		ui_interface->declare(&fVbargraph3, "unit", "dB");
		ui_interface->addVerticalBargraph("gate meter", &fVbargraph3, FAUSTFLOAT(-7e+01f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("eq");
		ui_interface->declare(&fCheckbox7, "1", "");
		ui_interface->declare(&fCheckbox7, "symbol", "eq_bypass");
		ui_interface->addCheckButton("eq bypass", &fCheckbox7);
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("highpass");
		ui_interface->declare(&fVslider15, "1", "");
		ui_interface->declare(&fVslider15, "scale", "log");
		ui_interface->declare(&fVslider15, "symbol", "eq_highpass_freq");
		ui_interface->declare(&fVslider15, "unit", "Hz");
		ui_interface->addVerticalSlider("eq highpass freq", &fVslider15, FAUSTFLOAT(5.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("tilt eq");
		ui_interface->declare(&fVslider14, "1", "");
		ui_interface->declare(&fVslider14, "symbol", "eq_tilt_gain");
		ui_interface->declare(&fVslider14, "unit", "dB");
		ui_interface->addVerticalSlider("eq tilt gain", &fVslider14, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.5f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("side eq");
		ui_interface->declare(&fVslider11, "1", "");
		ui_interface->declare(&fVslider11, "symbol", "eq_side_gain");
		ui_interface->declare(&fVslider11, "unit", "dB");
		ui_interface->addVerticalSlider("eq side gain", &fVslider11, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider13, "2", "");
		ui_interface->declare(&fVslider13, "scale", "log");
		ui_interface->declare(&fVslider13, "symbol", "eq_side_freq");
		ui_interface->declare(&fVslider13, "unit", "Hz");
		ui_interface->addVerticalSlider("eq side freq", &fVslider13, FAUSTFLOAT(6e+02f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider12, "3", "");
		ui_interface->declare(&fVslider12, "symbol", "eq_side_bandwidth");
		ui_interface->addVerticalSlider("eq side bandwidth", &fVslider12, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.5f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("leveler");
		ui_interface->declare(&fCheckbox8, "1", "");
		ui_interface->declare(&fCheckbox8, "symbol", "leveler_bypass");
		ui_interface->addCheckButton("leveler bypass", &fCheckbox8);
		ui_interface->declare(&fVslider19, "4", "");
		ui_interface->declare(&fVslider19, "integer", "");
		ui_interface->declare(&fVslider19, "symbol", "leveler_speed");
		ui_interface->declare(&fVslider19, "unit", "%");
		ui_interface->addVerticalSlider("leveler speed", &fVslider19, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider18, "5", "");
		ui_interface->declare(&fVslider18, "symbol", "leveler_brake_threshold");
		ui_interface->declare(&fVslider18, "unit", "dB");
		ui_interface->addVerticalSlider("leveler brake threshold", &fVslider18, FAUSTFLOAT(-14.0f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph4, "6", "");
		ui_interface->declare(&fVbargraph4, "integer", "");
		ui_interface->declare(&fVbargraph4, "symbol", "leveler_brake");
		ui_interface->declare(&fVbargraph4, "unit", "%");
		ui_interface->addVerticalBargraph("leveler brake", &fVbargraph4, FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f));
		ui_interface->declare(&fVslider21, "7", "");
		ui_interface->declare(&fVslider21, "symbol", "leveler_max_plus");
		ui_interface->declare(&fVslider21, "unit", "dB");
		ui_interface->addVerticalSlider("leveler max +", &fVslider21, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+01f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider20, "8", "");
		ui_interface->declare(&fVslider20, "symbol", "leveler_max_minus");
		ui_interface->declare(&fVslider20, "unit", "dB");
		ui_interface->addVerticalSlider("leveler max -", &fVslider20, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+01f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("kneecomp");
		ui_interface->declare(&fCheckbox9, "0", "");
		ui_interface->declare(&fCheckbox9, "symbol", "kneecomp_bypass");
		ui_interface->addCheckButton("kneecomp bypass", &fCheckbox9);
		ui_interface->declare(&fVslider25, "1", "");
		ui_interface->declare(&fVslider25, "integer", "");
		ui_interface->declare(&fVslider25, "symbol", "kneecomp_strength");
		ui_interface->declare(&fVslider25, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp strength", &fVslider25, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider17, "2", "");
		ui_interface->declare(&fVslider17, "symbol", "kneecomp_threshold");
		ui_interface->declare(&fVslider17, "unit", "dB");
		ui_interface->addVerticalSlider("kneecomp tar-thresh", &fVslider17, FAUSTFLOAT(-6.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider24, "3", "");
		ui_interface->declare(&fVslider24, "symbol", "kneecomp_attack");
		ui_interface->declare(&fVslider24, "unit", "ms");
		ui_interface->addVerticalSlider("kneecomp attack", &fVslider24, FAUSTFLOAT(2e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider23, "4", "");
		ui_interface->declare(&fVslider23, "symbol", "kneecomp_release");
		ui_interface->declare(&fVslider23, "unit", "ms");
		ui_interface->addVerticalSlider("kneecomp release", &fVslider23, FAUSTFLOAT(2e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider16, "5", "");
		ui_interface->declare(&fVslider16, "symbol", "kneecomp_knee");
		ui_interface->declare(&fVslider16, "unit", "dB");
		ui_interface->addVerticalSlider("kneecomp knee", &fVslider16, FAUSTFLOAT(6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider26, "6", "");
		ui_interface->declare(&fVslider26, "integer", "");
		ui_interface->declare(&fVslider26, "symbol", "kneecomp_link");
		ui_interface->declare(&fVslider26, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp link", &fVslider26, FAUSTFLOAT(6e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider22, "7", "");
		ui_interface->declare(&fVslider22, "integer", "");
		ui_interface->declare(&fVslider22, "symbol", "kneecomp_fffb");
		ui_interface->declare(&fVslider22, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp ff-fb", &fVslider22, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider27, "8", "");
		ui_interface->declare(&fVslider27, "symbol", "kneecomp_makeup");
		ui_interface->declare(&fVslider27, "unit", "dB");
		ui_interface->addVerticalSlider("kneecomp makeup", &fVslider27, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider28, "9", "");
		ui_interface->declare(&fVslider28, "integer", "");
		ui_interface->declare(&fVslider28, "symbol", "kneecomp_drywet");
		ui_interface->declare(&fVslider28, "unit", "%");
		ui_interface->addVerticalSlider("kneecomp dry/wet", &fVslider28, FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph7, "symbol", "kneecomp_meter_0");
		ui_interface->declare(&fVbargraph7, "unit", "dB");
		ui_interface->addVerticalBargraph("kneecomp meter 0", &fVbargraph7, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph6, "symbol", "kneecomp_meter_1");
		ui_interface->declare(&fVbargraph6, "unit", "dB");
		ui_interface->addVerticalBargraph("kneecomp meter 1", &fVbargraph6, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("mscomp");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("bypass");
		ui_interface->declare(&fCheckbox10, "0", "");
		ui_interface->declare(&fCheckbox10, "symbol", "mscomp_bypass");
		ui_interface->addCheckButton("mscomp bypass", &fCheckbox10);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("low band");
		ui_interface->declare(&fVslider29, "1", "");
		ui_interface->declare(&fVslider29, "integer", "");
		ui_interface->declare(&fVslider29, "symbol", "mscomp_low_strength");
		ui_interface->declare(&fVslider29, "unit", "%");
		ui_interface->addVerticalSlider("low strength", &fVslider29, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider38, "2", "");
		ui_interface->declare(&fVslider38, "symbol", "mscomp_low_threshold");
		ui_interface->declare(&fVslider38, "unit", "dB");
		ui_interface->addVerticalSlider("low tar-thresh", &fVslider38, FAUSTFLOAT(-6.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider31, "3", "");
		ui_interface->declare(&fVslider31, "symbol", "mscomp_low_attack");
		ui_interface->declare(&fVslider31, "unit", "ms");
		ui_interface->addVerticalSlider("low attack", &fVslider31, FAUSTFLOAT(15.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider33, "4", "");
		ui_interface->declare(&fVslider33, "symbol", "mscomp_low_release");
		ui_interface->declare(&fVslider33, "unit", "ms");
		ui_interface->addVerticalSlider("low release", &fVslider33, FAUSTFLOAT(1.5e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider37, "5", "");
		ui_interface->declare(&fVslider37, "symbol", "mscomp_low_knee");
		ui_interface->declare(&fVslider37, "unit", "dB");
		ui_interface->addVerticalSlider("low knee", &fVslider37, FAUSTFLOAT(12.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider35, "6", "");
		ui_interface->declare(&fVslider35, "integer", "");
		ui_interface->declare(&fVslider35, "symbol", "mscomp_low_link");
		ui_interface->declare(&fVslider35, "unit", "%");
		ui_interface->addVerticalSlider("low link", &fVslider35, FAUSTFLOAT(6e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider4, "7", "");
		ui_interface->declare(&fVslider4, "scale", "log");
		ui_interface->declare(&fVslider4, "symbol", "mscomp_low_crossover");
		ui_interface->declare(&fVslider4, "unit", "Hz");
		ui_interface->addVerticalSlider("low crossover", &fVslider4, FAUSTFLOAT(6e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(4e+03f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("high band");
		ui_interface->declare(&fVslider30, "1", "");
		ui_interface->declare(&fVslider30, "integer", "");
		ui_interface->declare(&fVslider30, "symbol", "mscomp_high_strength");
		ui_interface->declare(&fVslider30, "unit", "%");
		ui_interface->addVerticalSlider("high strength", &fVslider30, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider3, "2", "");
		ui_interface->declare(&fVslider3, "symbol", "mscomp_high_threshold");
		ui_interface->declare(&fVslider3, "unit", "dB");
		ui_interface->addVerticalSlider("high tar-thresh", &fVslider3, FAUSTFLOAT(-12.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.5f));
		ui_interface->declare(&fVslider32, "3", "");
		ui_interface->declare(&fVslider32, "symbol", "mscomp_high_attack");
		ui_interface->declare(&fVslider32, "unit", "ms");
		ui_interface->addVerticalSlider("high attack", &fVslider32, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider34, "4", "");
		ui_interface->declare(&fVslider34, "symbol", "mscomp_high_release");
		ui_interface->declare(&fVslider34, "unit", "ms");
		ui_interface->addVerticalSlider("high release", &fVslider34, FAUSTFLOAT(3e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider1, "5", "");
		ui_interface->declare(&fVslider1, "symbol", "mscomp_high_knee");
		ui_interface->declare(&fVslider1, "unit", "dB");
		ui_interface->addVerticalSlider("high knee", &fVslider1, FAUSTFLOAT(12.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider36, "6", "");
		ui_interface->declare(&fVslider36, "integer", "");
		ui_interface->declare(&fVslider36, "symbol", "mscomp_high_link");
		ui_interface->declare(&fVslider36, "unit", "%");
		ui_interface->addVerticalSlider("high link", &fVslider36, FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider5, "7", "");
		ui_interface->declare(&fVslider5, "scale", "log");
		ui_interface->declare(&fVslider5, "symbol", "mscomp_high_crossover");
		ui_interface->declare(&fVslider5, "unit", "Hz");
		ui_interface->addVerticalSlider("high crossover", &fVslider5, FAUSTFLOAT(8e+03f), FAUSTFLOAT(5e+03f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("out");
		ui_interface->declare(&fVslider39, "3", "");
		ui_interface->declare(&fVslider39, "symbol", "mscomp_output_gain");
		ui_interface->declare(&fVslider39, "unit", "dB");
		ui_interface->addVerticalSlider("makeup", &fVslider39, FAUSTFLOAT(1.0f), FAUSTFLOAT(-6.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.5f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "6", "");
		ui_interface->openHorizontalBox("mscomp_meter");
		ui_interface->declare(&fVbargraph23, "1.1", "");
		ui_interface->declare(&fVbargraph23, "symbol", "msredux11");
		ui_interface->declare(&fVbargraph23, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph23, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph0", &fVbargraph23, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph15, "1.2", "");
		ui_interface->declare(&fVbargraph15, "symbol", "msredux12");
		ui_interface->declare(&fVbargraph15, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph15, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph1", &fVbargraph15, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph22, "2.1", "");
		ui_interface->declare(&fVbargraph22, "symbol", "msredux21");
		ui_interface->declare(&fVbargraph22, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph22, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph2", &fVbargraph22, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph14, "2.2", "");
		ui_interface->declare(&fVbargraph14, "symbol", "msredux22");
		ui_interface->declare(&fVbargraph14, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph14, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph3", &fVbargraph14, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph21, "3.1", "");
		ui_interface->declare(&fVbargraph21, "symbol", "msredux31");
		ui_interface->declare(&fVbargraph21, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph21, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph4", &fVbargraph21, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph13, "3.2", "");
		ui_interface->declare(&fVbargraph13, "symbol", "msredux32");
		ui_interface->declare(&fVbargraph13, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph13, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph5", &fVbargraph13, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph20, "4.1", "");
		ui_interface->declare(&fVbargraph20, "symbol", "msredux41");
		ui_interface->declare(&fVbargraph20, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph20, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph6", &fVbargraph20, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph12, "4.2", "");
		ui_interface->declare(&fVbargraph12, "symbol", "msredux42");
		ui_interface->declare(&fVbargraph12, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph12, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph7", &fVbargraph12, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph19, "5.1", "");
		ui_interface->declare(&fVbargraph19, "symbol", "msredux51");
		ui_interface->declare(&fVbargraph19, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph19, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph8", &fVbargraph19, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph11, "5.2", "");
		ui_interface->declare(&fVbargraph11, "symbol", "msredux52");
		ui_interface->declare(&fVbargraph11, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph11, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph9", &fVbargraph11, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph18, "6.1", "");
		ui_interface->declare(&fVbargraph18, "symbol", "msredux61");
		ui_interface->declare(&fVbargraph18, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph18, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph10", &fVbargraph18, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph10, "6.2", "");
		ui_interface->declare(&fVbargraph10, "symbol", "msredux62");
		ui_interface->declare(&fVbargraph10, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph10, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph11", &fVbargraph10, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph17, "7.1", "");
		ui_interface->declare(&fVbargraph17, "symbol", "msredux71");
		ui_interface->declare(&fVbargraph17, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph17, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph12", &fVbargraph17, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph9, "7.2", "");
		ui_interface->declare(&fVbargraph9, "symbol", "msredux72");
		ui_interface->declare(&fVbargraph9, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph9, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph13", &fVbargraph9, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph16, "8.1", "");
		ui_interface->declare(&fVbargraph16, "symbol", "msredux81");
		ui_interface->declare(&fVbargraph16, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph16, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph14", &fVbargraph16, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->declare(&fVbargraph8, "8.2", "");
		ui_interface->declare(&fVbargraph8, "symbol", "msredux82");
		ui_interface->declare(&fVbargraph8, "tooltip", "gain reduction in db");
		ui_interface->declare(&fVbargraph8, "unit", "dB");
		ui_interface->addVerticalBargraph("vbargraph15", &fVbargraph8, FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "7", "");
		ui_interface->openHorizontalBox("limiter");
		ui_interface->declare(&fCheckbox11, "0", "");
		ui_interface->declare(&fCheckbox11, "symbol", "limiter_bypass");
		ui_interface->addCheckButton("limiter bypass", &fCheckbox11);
		ui_interface->declare(&fVslider46, "1", "");
		ui_interface->declare(&fVslider46, "integer", "");
		ui_interface->declare(&fVslider46, "symbol", "limiter_strength");
		ui_interface->declare(&fVslider46, "unit", "%");
		ui_interface->addVerticalSlider("limiter strength", &fVslider46, FAUSTFLOAT(8e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider42, "2", "");
		ui_interface->declare(&fVslider42, "symbol", "limiter_threshold");
		ui_interface->declare(&fVslider42, "unit", "dB");
		ui_interface->addVerticalSlider("limiter tar-thresh", &fVslider42, FAUSTFLOAT(6.0f), FAUSTFLOAT(-12.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider45, "3", "");
		ui_interface->declare(&fVslider45, "symbol", "limiter_attack");
		ui_interface->declare(&fVslider45, "unit", "ms");
		ui_interface->addVerticalSlider("limiter attack", &fVslider45, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider44, "4", "");
		ui_interface->declare(&fVslider44, "symbol", "limiter_release");
		ui_interface->declare(&fVslider44, "unit", "ms");
		ui_interface->addVerticalSlider("limiter release", &fVslider44, FAUSTFLOAT(4e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider41, "5", "");
		ui_interface->declare(&fVslider41, "symbol", "limiter_knee");
		ui_interface->declare(&fVslider41, "unit", "dB");
		ui_interface->addVerticalSlider("limiter knee", &fVslider41, FAUSTFLOAT(8.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider43, "6", "");
		ui_interface->declare(&fVslider43, "integer", "");
		ui_interface->declare(&fVslider43, "symbol", "limiter_fffb");
		ui_interface->declare(&fVslider43, "unit", "%");
		ui_interface->addVerticalSlider("limiter ff-fb", &fVslider43, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider40, "8", "");
		ui_interface->declare(&fVslider40, "symbol", "limiter_makeup");
		ui_interface->declare(&fVslider40, "unit", "dB");
		ui_interface->addVerticalSlider("limiter makeup", &fVslider40, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.5f));
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
		ui_interface->declare(&fVslider0, "3", "");
		ui_interface->declare(&fVslider0, "symbol", "brickwall_ceiling");
		ui_interface->declare(&fVslider0, "unit", "dB");
		ui_interface->addVerticalSlider("brickwall ceiling", &fVslider0, FAUSTFLOAT(-1.0f), FAUSTFLOAT(-6.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider47, "4", "");
		ui_interface->declare(&fVslider47, "symbol", "brickwall_release");
		ui_interface->declare(&fVslider47, "unit", "ms");
		ui_interface->addVerticalSlider("brickwall release", &fVslider47, FAUSTFLOAT(75.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVbargraph25, "symbol", "brickwall_limit");
		ui_interface->declare(&fVbargraph25, "unit", "dB");
		ui_interface->addVerticalBargraph("lim", &fVbargraph25, FAUSTFLOAT(-2e+01f), FAUSTFLOAT(0.0f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst2 * float(fCheckbox0);
		float fSlow1 = float(fVslider0);
		float fSlow2 = float(fVslider1);
		float fSlow3 = 0.5f * fSlow2;
		float fSlow4 = float(fVslider2);
		float fSlow5 = float(fVslider3);
		float fSlow6 = fSlow5 + fSlow4 + fSlow3;
		float fSlow7 = std::max<float>(1.1920929e-07f, float(fVslider4));
		float fSlow8 = std::pow(std::max<float>(1.1920929e-07f, float(fVslider5)) / fSlow7, 0.16666667f);
		float fSlow9 = std::tan(fConst4 * fSlow7 * mydsp_faustpower6_f(fSlow8));
		float fSlow10 = mydsp_faustpower2_f(fSlow9);
		float fSlow11 = 2.0f * (1.0f - 1.0f / fSlow10);
		float fSlow12 = 1.0f / fSlow9;
		float fSlow13 = (fSlow12 + -0.5176381f) / fSlow9 + 1.0f;
		float fSlow14 = (fSlow12 + 0.5176381f) / fSlow9 + 1.0f;
		float fSlow15 = 1.0f / fSlow14;
		float fSlow16 = (fSlow12 + -1.4142135f) / fSlow9 + 1.0f;
		float fSlow17 = (fSlow12 + 1.4142135f) / fSlow9 + 1.0f;
		float fSlow18 = 1.0f / fSlow17;
		float fSlow19 = (fSlow12 + -1.9318516f) / fSlow9 + 1.0f;
		float fSlow20 = (fSlow12 + 1.9318516f) / fSlow9 + 1.0f;
		float fSlow21 = 1.0f / fSlow20;
		float fSlow22 = fConst2 * float(fCheckbox1);
		float fSlow23 = std::pow(1e+01f, 0.05f * float(fVslider6));
		float fSlow24 = 0.001f * float(fVslider7);
		float fSlow25 = 0.001f * float(fVslider8);
		float fSlow26 = std::min<float>(fSlow24, fSlow25);
		int iSlow27 = std::fabs(fSlow26) < 1.1920929e-07f;
		float fSlow28 = ((iSlow27) ? 0.0f : std::exp(-(fConst5 / ((iSlow27) ? 1.0f : fSlow26))));
		float fSlow29 = 1.0f - fSlow28;
		float fSlow30 = fConst2 * std::pow(1e+01f, 0.05f * float(fVslider9));
		float fSlow31 = fConst2 * (1.0f - float(fCheckbox2));
		float fSlow32 = fConst2 * (1.0f - float(fCheckbox3));
		float fSlow33 = float(fCheckbox4);
		float fSlow34 = fSlow33 - (1.0f - fSlow33);
		float fSlow35 = float(fCheckbox5);
		float fSlow36 = fSlow35 - (1.0f - fSlow35);
		float fSlow37 = fConst2 * (1.0f - float(fCheckbox6));
		int iSlow38 = int(fConst69 * float(fVslider10));
		int iSlow39 = std::fabs(fSlow25) < 1.1920929e-07f;
		float fSlow40 = ((iSlow39) ? 0.0f : std::exp(-(fConst5 / ((iSlow39) ? 1.0f : fSlow25))));
		int iSlow41 = std::fabs(fSlow24) < 1.1920929e-07f;
		float fSlow42 = ((iSlow41) ? 0.0f : std::exp(-(fConst5 / ((iSlow41) ? 1.0f : fSlow24))));
		float fSlow43 = fConst2 * float(fCheckbox7);
		float fSlow44 = fConst2 * float(fVslider11);
		float fSlow45 = float(fVslider12);
		float fSlow46 = float(fVslider13);
		float fSlow47 = std::tan(fConst4 * std::min<float>(8e+03f, fSlow46 * (fSlow45 + 1.0f)));
		float fSlow48 = std::tan(fConst4 * std::max<float>(5e+01f, fSlow46 * (1.0f - fSlow45)));
		float fSlow49 = fConst2 * float(fVslider14);
		float fSlow50 = 1.0f / std::tan(fConst4 * float(fVslider15));
		float fSlow51 = 1.0f - fSlow50;
		float fSlow52 = 1.0f / (fSlow50 + 1.0f);
		float fSlow53 = float(fVslider16);
		float fSlow54 = 0.5f * fSlow53;
		float fSlow55 = fSlow4 + float(fVslider17);
		float fSlow56 = fSlow55 + fSlow54;
		float fSlow57 = float(fVslider18);
		float fSlow58 = fSlow57 + 6.0f;
		float fSlow59 = fSlow57 + -6.0f;
		float fSlow60 = 106.103294f / float(fVslider19);
		float fSlow61 = float(fVslider21);
		float fSlow62 = fConst2 * float(fCheckbox8);
		float fSlow63 = 0.01f * float(fVslider22);
		float fSlow64 = 1.0f - fSlow63;
		int iSlow65 = std::max<int>(1, int(fConst69 * float(fVslider23)));
		int iSlow66 = std::max<int>(0, iSlow65);
		float fSlow67 = 1.0f / float(iSlow65);
		float fSlow68 = 0.001f * float(fVslider24);
		int iSlow69 = std::fabs(fSlow68) < 1.1920929e-07f;
		float fSlow70 = ((iSlow69) ? 0.0f : std::exp(-(fConst5 / ((iSlow69) ? 1.0f : fSlow68))));
		float fSlow71 = fSlow55 - fSlow54;
		float fSlow72 = 0.5f / std::max<float>(1.1920929e-07f, fSlow53);
		float fSlow73 = float(fVslider25);
		float fSlow74 = 0.01f * fSlow73;
		float fSlow75 = float(fVslider26);
		float fSlow76 = fConst2 * float(fVslider27);
		float fSlow77 = fConst2 * float(fCheckbox9);
		float fSlow78 = fConst137 * float(fVslider28);
		float fSlow79 = 1.0f / (fSlow10 * fSlow20);
		float fSlow80 = 1.0f / (fSlow10 * fSlow17);
		float fSlow81 = 1.0f / (fSlow10 * fSlow14);
		float fSlow82 = fSlow4 + fSlow5;
		float fSlow83 = fSlow82 - fSlow3;
		float fSlow84 = 0.5f / std::max<float>(1.1920929e-07f, fSlow2);
		float fSlow85 = float(fVslider29);
		float fSlow86 = float(fVslider30) - fSlow85;
		float fSlow87 = 0.01f * (fSlow85 + fSlow86);
		float fSlow88 = std::max<float>(1.1920929e-07f, 0.001f * float(fVslider31));
		float fSlow89 = std::pow(std::max<float>(1.1920929e-07f, 0.001f * float(fVslider32)) / fSlow88, 0.14285715f);
		float fSlow90 = fSlow88 * mydsp_faustpower7_f(fSlow89);
		int iSlow91 = std::fabs(fSlow90) < 1.1920929e-07f;
		float fSlow92 = ((iSlow91) ? 0.0f : std::exp(-(fConst5 / ((iSlow91) ? 1.0f : fSlow90))));
		float fSlow93 = std::max<float>(1.1920929e-07f, 0.001f * float(fVslider33));
		float fSlow94 = std::pow(std::max<float>(1.1920929e-07f, 0.001f * float(fVslider34)) / fSlow93, 0.14285715f);
		float fSlow95 = fSlow93 * mydsp_faustpower7_f(fSlow94);
		int iSlow96 = std::fabs(fSlow95) < 1.1920929e-07f;
		float fSlow97 = ((iSlow96) ? 0.0f : std::exp(-(fConst5 / ((iSlow96) ? 1.0f : fSlow95))));
		float fSlow98 = float(fVslider35);
		float fSlow99 = float(fVslider36) - fSlow98;
		float fSlow100 = 0.01f * (fSlow98 + fSlow99);
		float fSlow101 = float(fVslider37);
		float fSlow102 = fSlow2 - fSlow101;
		float fSlow103 = fSlow101 + 0.85714287f * fSlow102;
		float fSlow104 = 0.5f * fSlow103;
		float fSlow105 = float(fVslider38);
		float fSlow106 = fSlow5 - fSlow105;
		float fSlow107 = fSlow4 + fSlow105;
		float fSlow108 = fSlow107 + 0.85714287f * fSlow106;
		float fSlow109 = fSlow108 + fSlow104;
		float fSlow110 = std::tan(fConst4 * fSlow7 * mydsp_faustpower5_f(fSlow8));
		float fSlow111 = mydsp_faustpower2_f(fSlow110);
		float fSlow112 = 2.0f * (1.0f - 1.0f / fSlow111);
		float fSlow113 = 1.0f / fSlow110;
		float fSlow114 = (fSlow113 + -0.5176381f) / fSlow110 + 1.0f;
		float fSlow115 = (fSlow113 + 0.5176381f) / fSlow110 + 1.0f;
		float fSlow116 = 1.0f / fSlow115;
		float fSlow117 = (fSlow113 + -1.4142135f) / fSlow110 + 1.0f;
		float fSlow118 = (fSlow113 + 1.4142135f) / fSlow110 + 1.0f;
		float fSlow119 = 1.0f / fSlow118;
		float fSlow120 = (fSlow113 + -1.9318516f) / fSlow110 + 1.0f;
		float fSlow121 = (fSlow113 + 1.9318516f) / fSlow110 + 1.0f;
		float fSlow122 = 1.0f / fSlow121;
		float fSlow123 = 1.0f / (fSlow111 * fSlow121);
		float fSlow124 = 1.0f / (fSlow111 * fSlow118);
		float fSlow125 = 1.0f / (fSlow111 * fSlow115);
		float fSlow126 = fSlow108 - fSlow104;
		float fSlow127 = 0.5f / std::max<float>(1.1920929e-07f, fSlow103);
		float fSlow128 = 0.01f * fSlow85;
		float fSlow129 = fSlow128 + 0.008571428f * fSlow86;
		float fSlow130 = fSlow88 * mydsp_faustpower6_f(fSlow89);
		int iSlow131 = std::fabs(fSlow130) < 1.1920929e-07f;
		float fSlow132 = ((iSlow131) ? 0.0f : std::exp(-(fConst5 / ((iSlow131) ? 1.0f : fSlow130))));
		float fSlow133 = fSlow93 * mydsp_faustpower6_f(fSlow94);
		int iSlow134 = std::fabs(fSlow133) < 1.1920929e-07f;
		float fSlow135 = ((iSlow134) ? 0.0f : std::exp(-(fConst5 / ((iSlow134) ? 1.0f : fSlow133))));
		float fSlow136 = 0.01f * fSlow98;
		float fSlow137 = fSlow136 + 0.008571428f * fSlow99;
		float fSlow138 = fSlow101 + 0.71428573f * fSlow102;
		float fSlow139 = 0.5f * fSlow138;
		float fSlow140 = fSlow107 + 0.71428573f * fSlow106;
		float fSlow141 = fSlow140 + fSlow139;
		float fSlow142 = std::tan(fConst4 * fSlow7 * mydsp_faustpower4_f(fSlow8));
		float fSlow143 = mydsp_faustpower2_f(fSlow142);
		float fSlow144 = 2.0f * (1.0f - 1.0f / fSlow143);
		float fSlow145 = 1.0f / fSlow142;
		float fSlow146 = (fSlow145 + -0.5176381f) / fSlow142 + 1.0f;
		float fSlow147 = (fSlow145 + 0.5176381f) / fSlow142 + 1.0f;
		float fSlow148 = 1.0f / fSlow147;
		float fSlow149 = (fSlow145 + -1.4142135f) / fSlow142 + 1.0f;
		float fSlow150 = (fSlow145 + 1.4142135f) / fSlow142 + 1.0f;
		float fSlow151 = 1.0f / fSlow150;
		float fSlow152 = (fSlow145 + -1.9318516f) / fSlow142 + 1.0f;
		float fSlow153 = (fSlow145 + 1.9318516f) / fSlow142 + 1.0f;
		float fSlow154 = 1.0f / fSlow153;
		float fSlow155 = 1.0f / (fSlow143 * fSlow153);
		float fSlow156 = 1.0f / (fSlow143 * fSlow150);
		float fSlow157 = 1.0f / (fSlow143 * fSlow147);
		float fSlow158 = fSlow140 - fSlow139;
		float fSlow159 = 0.5f / std::max<float>(1.1920929e-07f, fSlow138);
		float fSlow160 = fSlow128 + 0.007142857f * fSlow86;
		float fSlow161 = fSlow88 * mydsp_faustpower5_f(fSlow89);
		int iSlow162 = std::fabs(fSlow161) < 1.1920929e-07f;
		float fSlow163 = ((iSlow162) ? 0.0f : std::exp(-(fConst5 / ((iSlow162) ? 1.0f : fSlow161))));
		float fSlow164 = fSlow93 * mydsp_faustpower5_f(fSlow94);
		int iSlow165 = std::fabs(fSlow164) < 1.1920929e-07f;
		float fSlow166 = ((iSlow165) ? 0.0f : std::exp(-(fConst5 / ((iSlow165) ? 1.0f : fSlow164))));
		float fSlow167 = fSlow136 + 0.007142857f * fSlow99;
		float fSlow168 = fSlow101 + 0.5714286f * fSlow102;
		float fSlow169 = 0.5f * fSlow168;
		float fSlow170 = fSlow107 + 0.5714286f * fSlow106;
		float fSlow171 = fSlow170 + fSlow169;
		float fSlow172 = std::tan(fConst4 * fSlow7 * mydsp_faustpower3_f(fSlow8));
		float fSlow173 = mydsp_faustpower2_f(fSlow172);
		float fSlow174 = 2.0f * (1.0f - 1.0f / fSlow173);
		float fSlow175 = 1.0f / fSlow172;
		float fSlow176 = (fSlow175 + -0.5176381f) / fSlow172 + 1.0f;
		float fSlow177 = (fSlow175 + 0.5176381f) / fSlow172 + 1.0f;
		float fSlow178 = 1.0f / fSlow177;
		float fSlow179 = (fSlow175 + -1.4142135f) / fSlow172 + 1.0f;
		float fSlow180 = (fSlow175 + 1.4142135f) / fSlow172 + 1.0f;
		float fSlow181 = 1.0f / fSlow180;
		float fSlow182 = (fSlow175 + -1.9318516f) / fSlow172 + 1.0f;
		float fSlow183 = (fSlow175 + 1.9318516f) / fSlow172 + 1.0f;
		float fSlow184 = 1.0f / fSlow183;
		float fSlow185 = 1.0f / (fSlow173 * fSlow183);
		float fSlow186 = 1.0f / (fSlow173 * fSlow180);
		float fSlow187 = 1.0f / (fSlow173 * fSlow177);
		float fSlow188 = fSlow170 - fSlow169;
		float fSlow189 = 0.5f / std::max<float>(1.1920929e-07f, fSlow168);
		float fSlow190 = fSlow128 + 0.0057142857f * fSlow86;
		float fSlow191 = fSlow88 * mydsp_faustpower4_f(fSlow89);
		int iSlow192 = std::fabs(fSlow191) < 1.1920929e-07f;
		float fSlow193 = ((iSlow192) ? 0.0f : std::exp(-(fConst5 / ((iSlow192) ? 1.0f : fSlow191))));
		float fSlow194 = fSlow93 * mydsp_faustpower4_f(fSlow94);
		int iSlow195 = std::fabs(fSlow194) < 1.1920929e-07f;
		float fSlow196 = ((iSlow195) ? 0.0f : std::exp(-(fConst5 / ((iSlow195) ? 1.0f : fSlow194))));
		float fSlow197 = fSlow136 + 0.0057142857f * fSlow99;
		float fSlow198 = fSlow101 + 0.42857143f * fSlow102;
		float fSlow199 = 0.5f * fSlow198;
		float fSlow200 = fSlow107 + 0.42857143f * fSlow106;
		float fSlow201 = fSlow200 + fSlow199;
		float fSlow202 = std::tan(fConst4 * fSlow7 * mydsp_faustpower2_f(fSlow8));
		float fSlow203 = mydsp_faustpower2_f(fSlow202);
		float fSlow204 = 2.0f * (1.0f - 1.0f / fSlow203);
		float fSlow205 = 1.0f / fSlow202;
		float fSlow206 = (fSlow205 + -0.5176381f) / fSlow202 + 1.0f;
		float fSlow207 = (fSlow205 + 0.5176381f) / fSlow202 + 1.0f;
		float fSlow208 = 1.0f / fSlow207;
		float fSlow209 = (fSlow205 + -1.4142135f) / fSlow202 + 1.0f;
		float fSlow210 = (fSlow205 + 1.4142135f) / fSlow202 + 1.0f;
		float fSlow211 = 1.0f / fSlow210;
		float fSlow212 = (fSlow205 + -1.9318516f) / fSlow202 + 1.0f;
		float fSlow213 = (fSlow205 + 1.9318516f) / fSlow202 + 1.0f;
		float fSlow214 = 1.0f / fSlow213;
		float fSlow215 = 1.0f / (fSlow203 * fSlow213);
		float fSlow216 = 1.0f / (fSlow203 * fSlow210);
		float fSlow217 = 1.0f / (fSlow203 * fSlow207);
		float fSlow218 = fSlow200 - fSlow199;
		float fSlow219 = 0.5f / std::max<float>(1.1920929e-07f, fSlow198);
		float fSlow220 = fSlow128 + 0.004285714f * fSlow86;
		float fSlow221 = fSlow88 * mydsp_faustpower3_f(fSlow89);
		int iSlow222 = std::fabs(fSlow221) < 1.1920929e-07f;
		float fSlow223 = ((iSlow222) ? 0.0f : std::exp(-(fConst5 / ((iSlow222) ? 1.0f : fSlow221))));
		float fSlow224 = fSlow93 * mydsp_faustpower3_f(fSlow94);
		int iSlow225 = std::fabs(fSlow224) < 1.1920929e-07f;
		float fSlow226 = ((iSlow225) ? 0.0f : std::exp(-(fConst5 / ((iSlow225) ? 1.0f : fSlow224))));
		float fSlow227 = fSlow136 + 0.004285714f * fSlow99;
		float fSlow228 = fSlow101 + 0.2857143f * fSlow102;
		float fSlow229 = 0.5f * fSlow228;
		float fSlow230 = fSlow107 + 0.2857143f * fSlow106;
		float fSlow231 = fSlow230 + fSlow229;
		float fSlow232 = std::tan(fConst4 * fSlow7 * fSlow8);
		float fSlow233 = mydsp_faustpower2_f(fSlow232);
		float fSlow234 = 2.0f * (1.0f - 1.0f / fSlow233);
		float fSlow235 = 1.0f / fSlow232;
		float fSlow236 = (fSlow235 + -0.5176381f) / fSlow232 + 1.0f;
		float fSlow237 = (fSlow235 + 0.5176381f) / fSlow232 + 1.0f;
		float fSlow238 = 1.0f / fSlow237;
		float fSlow239 = (fSlow235 + -1.4142135f) / fSlow232 + 1.0f;
		float fSlow240 = (fSlow235 + 1.4142135f) / fSlow232 + 1.0f;
		float fSlow241 = 1.0f / fSlow240;
		float fSlow242 = (fSlow235 + -1.9318516f) / fSlow232 + 1.0f;
		float fSlow243 = (fSlow235 + 1.9318516f) / fSlow232 + 1.0f;
		float fSlow244 = 1.0f / fSlow243;
		float fSlow245 = 1.0f / (fSlow233 * fSlow243);
		float fSlow246 = 1.0f / (fSlow233 * fSlow240);
		float fSlow247 = 1.0f / (fSlow233 * fSlow237);
		float fSlow248 = fSlow230 - fSlow229;
		float fSlow249 = 0.5f / std::max<float>(1.1920929e-07f, fSlow228);
		float fSlow250 = fSlow128 + 0.0028571428f * fSlow86;
		float fSlow251 = fSlow88 * mydsp_faustpower2_f(fSlow89);
		int iSlow252 = std::fabs(fSlow251) < 1.1920929e-07f;
		float fSlow253 = ((iSlow252) ? 0.0f : std::exp(-(fConst5 / ((iSlow252) ? 1.0f : fSlow251))));
		float fSlow254 = fSlow93 * mydsp_faustpower2_f(fSlow94);
		int iSlow255 = std::fabs(fSlow254) < 1.1920929e-07f;
		float fSlow256 = ((iSlow255) ? 0.0f : std::exp(-(fConst5 / ((iSlow255) ? 1.0f : fSlow254))));
		float fSlow257 = fSlow136 + 0.0028571428f * fSlow99;
		float fSlow258 = fSlow101 + 0.14285715f * fSlow102;
		float fSlow259 = 0.5f * fSlow258;
		float fSlow260 = fSlow107 + 0.14285715f * fSlow106;
		float fSlow261 = fSlow260 + fSlow259;
		float fSlow262 = std::tan(fConst4 * fSlow7);
		float fSlow263 = mydsp_faustpower2_f(fSlow262);
		float fSlow264 = 2.0f * (1.0f - 1.0f / fSlow263);
		float fSlow265 = 1.0f / fSlow262;
		float fSlow266 = (fSlow265 + -0.5176381f) / fSlow262 + 1.0f;
		float fSlow267 = (fSlow265 + 0.5176381f) / fSlow262 + 1.0f;
		float fSlow268 = 1.0f / fSlow267;
		float fSlow269 = (fSlow265 + -1.4142135f) / fSlow262 + 1.0f;
		float fSlow270 = (fSlow265 + 1.4142135f) / fSlow262 + 1.0f;
		float fSlow271 = 1.0f / fSlow270;
		float fSlow272 = (fSlow265 + -1.9318516f) / fSlow262 + 1.0f;
		float fSlow273 = (fSlow265 + 1.9318516f) / fSlow262 + 1.0f;
		float fSlow274 = 1.0f / fSlow273;
		float fSlow275 = 1.0f / (fSlow263 * fSlow273);
		float fSlow276 = 1.0f / (fSlow263 * fSlow270);
		float fSlow277 = 1.0f / (fSlow263 * fSlow267);
		float fSlow278 = fSlow260 - fSlow259;
		float fSlow279 = 0.5f / std::max<float>(1.1920929e-07f, fSlow258);
		float fSlow280 = fSlow128 + 0.0014285714f * fSlow86;
		float fSlow281 = fSlow88 * fSlow89;
		int iSlow282 = std::fabs(fSlow281) < 1.1920929e-07f;
		float fSlow283 = ((iSlow282) ? 0.0f : std::exp(-(fConst5 / ((iSlow282) ? 1.0f : fSlow281))));
		float fSlow284 = fSlow93 * fSlow94;
		int iSlow285 = std::fabs(fSlow284) < 1.1920929e-07f;
		float fSlow286 = ((iSlow285) ? 0.0f : std::exp(-(fConst5 / ((iSlow285) ? 1.0f : fSlow284))));
		float fSlow287 = fSlow136 + 0.0014285714f * fSlow99;
		float fSlow288 = 0.5f * fSlow101;
		float fSlow289 = fSlow105 + fSlow4 + fSlow288;
		float fSlow290 = fSlow107 - fSlow288;
		float fSlow291 = 0.5f / std::max<float>(1.1920929e-07f, fSlow101);
		int iSlow292 = std::fabs(fSlow88) < 1.1920929e-07f;
		float fSlow293 = ((iSlow292) ? 0.0f : std::exp(-(fConst5 / ((iSlow292) ? 1.0f : fSlow88))));
		int iSlow294 = std::fabs(fSlow93) < 1.1920929e-07f;
		float fSlow295 = ((iSlow294) ? 0.0f : std::exp(-(fConst5 / ((iSlow294) ? 1.0f : fSlow93))));
		float fSlow296 = fConst2 * float(fCheckbox10);
		float fSlow297 = fConst2 * std::pow(1e+01f, 0.05f * float(fVslider39));
		float fSlow298 = fConst2 * float(fCheckbox11);
		float fSlow299 = fConst2 * std::pow(1e+01f, 0.05f * float(fVslider40));
		float fSlow300 = float(fVslider41);
		float fSlow301 = 0.5f * fSlow300;
		float fSlow302 = fSlow4 + float(fVslider42);
		float fSlow303 = fSlow302 + fSlow301;
		float fSlow304 = 0.01f * float(fVslider43);
		int iSlow305 = std::max<int>(1, int(fConst69 * float(fVslider44)));
		int iSlow306 = std::max<int>(0, iSlow305);
		float fSlow307 = 1.0f / float(iSlow305);
		float fSlow308 = 0.001f * float(fVslider45);
		int iSlow309 = std::fabs(fSlow308) < 1.1920929e-07f;
		float fSlow310 = ((iSlow309) ? 0.0f : std::exp(-(fConst5 / ((iSlow309) ? 1.0f : fSlow308))));
		float fSlow311 = fSlow302 - fSlow301;
		float fSlow312 = 0.5f / std::max<float>(1.1920929e-07f, fSlow300);
		float fSlow313 = 0.01f * float(fVslider46) * (2.0f - fSlow304);
		float fSlow314 = 0.001f * float(fVslider47);
		int iSlow315 = std::fabs(fSlow314) < 1.1920929e-07f;
		float fSlow316 = ((iSlow315) ? 0.0f : std::exp(-(fConst5 / ((iSlow315) ? 1.0f : fSlow314))));
		float fSlow317 = fConst2 * float(fCheckbox12);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec1[0] = fSlow0 + fConst3 * fRec1[1];
			float fTemp0 = 1.0f - fRec1[0];
			fRec11[0] = fSlow22 + fConst3 * fRec11[1];
			fRec21[0] = fSlow30 + fConst3 * fRec21[1];
			float fTemp1 = float(input1[i0]);
			float fTemp2 = fTemp1 * fRec21[0];
			fRec20[0] = std::max<float>(fRec20[1] - fConst1, std::min<float>(1e+01f, 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::max<float>(0.00031622776f, std::fabs(fTemp2))))));
			fVbargraph0 = FAUSTFLOAT(fRec20[0]);
			float fTemp3 = fTemp2;
			fVec0[0] = fTemp3;
			fVec1[0] = fConst15 * fRec18[1] - fConst13 * fVec0[1];
			fRec19[0] = fConst17 * (fConst16 * fVec0[1] - (fVec1[1] + fConst12 * fRec19[1]) + fConst11 * fTemp3);
			fRec18[0] = fRec19[0];
			fVec2[0] = 0.50032705f * fRec18[1] - fConst22 * fRec16[1];
			fRec17[0] = fConst23 * (fVec2[1] - fConst20 * fRec17[1] - 1.0006541f * fRec18[1] + 0.50032705f * fRec18[0]);
			fRec16[0] = fRec17[0];
			float fTemp4 = mydsp_faustpower2_f(fRec16[0]);
			fVec3[0] = fTemp4;
			float fTemp5 = fTemp4 + fVec3[1];
			fVec4[0] = fTemp5;
			float fTemp6 = fTemp5 + fVec4[2];
			fVec5[0] = fTemp6;
			float fTemp7 = fTemp6 + fVec5[4];
			fVec6[0] = fTemp7;
			float fTemp8 = fTemp7 + fVec6[8];
			fVec7[IOTA0 & 31] = fTemp8;
			float fTemp9 = fTemp8 + fVec7[(IOTA0 - 16) & 31];
			fVec8[IOTA0 & 63] = fTemp9;
			float fTemp10 = fTemp9 + fVec8[(IOTA0 - 32) & 63];
			fVec9[IOTA0 & 127] = fTemp10;
			float fTemp11 = fTemp10 + fVec9[(IOTA0 - 64) & 127];
			fVec10[IOTA0 & 255] = fTemp11;
			float fTemp12 = fTemp11 + fVec10[(IOTA0 - 128) & 255];
			fVec11[IOTA0 & 511] = fTemp12;
			float fTemp13 = fTemp12 + fVec11[(IOTA0 - 256) & 511];
			fVec12[IOTA0 & 1023] = fTemp13;
			float fTemp14 = fTemp13 + fVec12[(IOTA0 - 512) & 1023];
			fVec13[IOTA0 & 2047] = fTemp14;
			float fTemp15 = fTemp14 + fVec13[(IOTA0 - 1024) & 2047];
			fVec14[IOTA0 & 4095] = fTemp15;
			float fTemp16 = fTemp15 + fVec14[(IOTA0 - 2048) & 4095];
			fVec15[IOTA0 & 8191] = fTemp16;
			float fTemp17 = fTemp16 + fVec15[(IOTA0 - 4096) & 8191];
			fVec16[IOTA0 & 16383] = fTemp17;
			float fTemp18 = fTemp17 + fVec16[(IOTA0 - 8192) & 16383];
			fVec17[IOTA0 & 32767] = fTemp18;
			float fTemp19 = fTemp18 + fVec17[(IOTA0 - 16384) & 32767];
			fVec18[IOTA0 & 65535] = fTemp19;
			float fTemp20 = fTemp19 + fVec18[(IOTA0 - 32768) & 65535];
			fVec19[IOTA0 & 131071] = fTemp20;
			float fTemp21 = fTemp20 + fVec19[(IOTA0 - 65536) & 131071];
			fVec20[IOTA0 & 262143] = fTemp21;
			float fTemp22 = fTemp21 + fVec20[(IOTA0 - 131072) & 262143];
			fVec21[IOTA0 & 524287] = fTemp22;
			fVec22[IOTA0 & 1048575] = fTemp22 + fVec21[(IOTA0 - 262144) & 524287];
			float fTemp23 = float(input0[i0]);
			float fTemp24 = fTemp23 * fRec21[0];
			fRec26[0] = std::max<float>(fRec26[1] - fConst1, std::min<float>(1e+01f, 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::max<float>(0.00031622776f, std::fabs(fTemp24))))));
			fVbargraph1 = FAUSTFLOAT(fRec26[0]);
			float fTemp25 = fTemp24;
			fVec23[0] = fTemp25;
			fVec24[0] = fConst15 * fRec24[1] - fConst13 * fVec23[1];
			fRec25[0] = fConst17 * (fConst16 * fVec23[1] - (fVec24[1] + fConst12 * fRec25[1]) + fConst11 * fTemp25);
			fRec24[0] = fRec25[0];
			fVec25[0] = 0.50032705f * fRec24[1] - fConst22 * fRec22[1];
			fRec23[0] = fConst23 * (fVec25[1] - fConst20 * fRec23[1] - 1.0006541f * fRec24[1] + 0.50032705f * fRec24[0]);
			fRec22[0] = fRec23[0];
			float fTemp26 = mydsp_faustpower2_f(fRec22[0]);
			fVec26[0] = fTemp26;
			float fTemp27 = fTemp26 + fVec26[1];
			fVec27[0] = fTemp27;
			float fTemp28 = fTemp27 + fVec27[2];
			fVec28[0] = fTemp28;
			float fTemp29 = fTemp28 + fVec28[4];
			fVec29[0] = fTemp29;
			float fTemp30 = fTemp29 + fVec29[8];
			fVec30[IOTA0 & 31] = fTemp30;
			float fTemp31 = fTemp30 + fVec30[(IOTA0 - 16) & 31];
			fVec31[IOTA0 & 63] = fTemp31;
			float fTemp32 = fTemp31 + fVec31[(IOTA0 - 32) & 63];
			fVec32[IOTA0 & 127] = fTemp32;
			float fTemp33 = fTemp32 + fVec32[(IOTA0 - 64) & 127];
			fVec33[IOTA0 & 255] = fTemp33;
			float fTemp34 = fTemp33 + fVec33[(IOTA0 - 128) & 255];
			fVec34[IOTA0 & 511] = fTemp34;
			float fTemp35 = fTemp34 + fVec34[(IOTA0 - 256) & 511];
			fVec35[IOTA0 & 1023] = fTemp35;
			float fTemp36 = fTemp35 + fVec35[(IOTA0 - 512) & 1023];
			fVec36[IOTA0 & 2047] = fTemp36;
			float fTemp37 = fTemp36 + fVec36[(IOTA0 - 1024) & 2047];
			fVec37[IOTA0 & 4095] = fTemp37;
			float fTemp38 = fTemp37 + fVec37[(IOTA0 - 2048) & 4095];
			fVec38[IOTA0 & 8191] = fTemp38;
			float fTemp39 = fTemp38 + fVec38[(IOTA0 - 4096) & 8191];
			fVec39[IOTA0 & 16383] = fTemp39;
			float fTemp40 = fTemp39 + fVec39[(IOTA0 - 8192) & 16383];
			fVec40[IOTA0 & 32767] = fTemp40;
			float fTemp41 = fTemp40 + fVec40[(IOTA0 - 16384) & 32767];
			fVec41[IOTA0 & 65535] = fTemp41;
			float fTemp42 = fTemp41 + fVec41[(IOTA0 - 32768) & 65535];
			fVec42[IOTA0 & 131071] = fTemp42;
			float fTemp43 = fTemp42 + fVec42[(IOTA0 - 65536) & 131071];
			fVec43[IOTA0 & 262143] = fTemp43;
			float fTemp44 = fTemp43 + fVec43[(IOTA0 - 131072) & 262143];
			fVec44[IOTA0 & 524287] = fTemp44;
			fVec45[IOTA0 & 1048575] = fTemp44 + fVec44[(IOTA0 - 262144) & 524287];
			fVbargraph2 = FAUSTFLOAT(4.3429446f * std::log(std::max<float>(1e-12f, fConst61 * (((iConst59) ? fVec45[(IOTA0 - iConst60) & 1048575] : 0.0f) + ((iConst57) ? fVec44[(IOTA0 - iConst58) & 524287] : 0.0f) + ((iConst55) ? fVec43[(IOTA0 - iConst56) & 262143] : 0.0f) + ((iConst53) ? fVec42[(IOTA0 - iConst54) & 131071] : 0.0f) + ((iConst51) ? fVec41[(IOTA0 - iConst52) & 65535] : 0.0f) + ((iConst49) ? fVec40[(IOTA0 - iConst50) & 32767] : 0.0f) + ((iConst47) ? fVec39[(IOTA0 - iConst48) & 16383] : 0.0f) + ((iConst45) ? fVec38[(IOTA0 - iConst46) & 8191] : 0.0f) + ((iConst43) ? fVec37[(IOTA0 - iConst44) & 4095] : 0.0f) + ((iConst41) ? fVec36[(IOTA0 - iConst42) & 2047] : 0.0f) + ((iConst39) ? fVec35[(IOTA0 - iConst40) & 1023] : 0.0f) + ((iConst37) ? fVec34[(IOTA0 - iConst38) & 511] : 0.0f) + ((iConst35) ? fVec33[(IOTA0 - iConst36) & 255] : 0.0f) + ((iConst33) ? fVec32[(IOTA0 - iConst34) & 127] : 0.0f) + ((iConst31) ? fVec31[(IOTA0 - iConst32) & 63] : 0.0f) + ((iConst29) ? fVec30[(IOTA0 - iConst30) & 31] : 0.0f) + ((iConst27) ? fVec29[iConst28] : 0.0f) + ((iConst25) ? fVec28[iConst26] : 0.0f) + ((iConst24) ? fTemp26 : 0.0f) + ((iConst7) ? fVec27[iConst24] : 0.0f) + ((iConst59) ? fVec22[(IOTA0 - iConst60) & 1048575] : 0.0f) + ((iConst57) ? fVec21[(IOTA0 - iConst58) & 524287] : 0.0f) + ((iConst55) ? fVec20[(IOTA0 - iConst56) & 262143] : 0.0f) + ((iConst53) ? fVec19[(IOTA0 - iConst54) & 131071] : 0.0f) + ((iConst51) ? fVec18[(IOTA0 - iConst52) & 65535] : 0.0f) + ((iConst49) ? fVec17[(IOTA0 - iConst50) & 32767] : 0.0f) + ((iConst47) ? fVec16[(IOTA0 - iConst48) & 16383] : 0.0f) + ((iConst45) ? fVec15[(IOTA0 - iConst46) & 8191] : 0.0f) + ((iConst43) ? fVec14[(IOTA0 - iConst44) & 4095] : 0.0f) + ((iConst41) ? fVec13[(IOTA0 - iConst42) & 2047] : 0.0f) + ((iConst39) ? fVec12[(IOTA0 - iConst40) & 1023] : 0.0f) + ((iConst37) ? fVec11[(IOTA0 - iConst38) & 511] : 0.0f) + ((iConst35) ? fVec10[(IOTA0 - iConst36) & 255] : 0.0f) + ((iConst33) ? fVec9[(IOTA0 - iConst34) & 127] : 0.0f) + ((iConst31) ? fVec8[(IOTA0 - iConst32) & 63] : 0.0f) + ((iConst29) ? fVec7[(IOTA0 - iConst30) & 31] : 0.0f) + ((iConst27) ? fVec6[iConst28] : 0.0f) + ((iConst25) ? fVec5[iConst26] : 0.0f) + ((iConst24) ? fTemp4 : 0.0f) + ((iConst7) ? fVec4[iConst24] : 0.0f)))) + -0.691f);
			float fTemp45 = fTemp3;
			fVec46[0] = fTemp45;
			fRec27[0] = fSlow31 + fConst3 * fRec27[1];
			float fTemp46 = 1.0f - fRec27[0];
			fRec28[0] = fConst64 * (fTemp45 - fVec46[1] + fConst63 * fRec28[1]);
			float fTemp47 = fRec28[0] * fTemp46 + fRec27[0] * fTemp45;
			fRec29[0] = fSlow32 + fConst3 * fRec29[1];
			fRec30[0] = fConst64 * (fTemp25 - fVec23[1] + fConst63 * fRec30[1]);
			float fTemp48 = fTemp25 * fRec27[0] + fRec30[0] * fTemp46;
			float fTemp49 = 0.5f * (1.0f - fRec29[0]) * (fSlow36 * fTemp48 + fSlow34 * fTemp47);
			float fTemp50 = fTemp49 + fSlow34 * fRec29[0] * fTemp47;
			fRec34[0] = fConst66 * fRec34[1] - fConst67 * fTemp50;
			float fTemp51 = fRec34[0] + fTemp50;
			fRec33[0] = fConst66 * fRec33[1] + fConst67 * mydsp_faustpower2_f(-fTemp51);
			float fTemp52 = fSlow36 * fRec29[0] * fTemp48 + fTemp49;
			fRec36[0] = fConst66 * fRec36[1] - fConst67 * fTemp52;
			float fTemp53 = fRec36[0] + fTemp52;
			fRec35[0] = fConst66 * fRec35[1] + fConst67 * mydsp_faustpower2_f(-fTemp53);
			fRec37[0] = fConst66 * fRec37[1] + fConst67 * fTemp53 * fTemp51;
			float fTemp54 = fRec37[0] / std::max<float>(1.1920929e-07f, std::sqrt(fRec35[0]) * std::sqrt(fRec33[0]));
			fRec32[0] = fConst66 * fRec32[1] + fConst67 * float((fTemp54 > -0.9999f) & (fTemp54 < -0.0001f));
			fRec31[0] = fConst68 * fRec32[0] + fConst65 * fRec31[1];
			fRec39[0] = fConst66 * fRec39[1] + fConst67 * float((fTemp54 > 0.0001f) & (fTemp54 < 0.9999f));
			fRec38[0] = fConst68 * fRec39[0] + fConst65 * fRec38[1];
			float fTemp55 = fTemp52 + fTemp50;
			fRec41[0] = fConst66 * fRec41[1] + fConst67 * float((fTemp54 < 0.0001f) & (fTemp54 > -0.0001f));
			fRec40[0] = fConst68 * fRec41[0] + fConst65 * fRec40[1];
			fRec43[0] = fConst66 * fRec43[1] + fConst67 * float(fTemp54 < -0.9999f);
			fRec42[0] = fConst68 * fRec43[0] + fConst65 * fRec42[1];
			fRec45[0] = fConst66 * fRec45[1] + fConst67 * float(fTemp54 > 0.9999f);
			fRec44[0] = fConst68 * fRec45[0] + fConst65 * fRec44[1];
			float fTemp56 = 0.5f * (fRec44[0] * fTemp55 + fRec42[0] * (fTemp52 - fTemp50)) + fRec40[0] * fTemp55;
			fRec46[0] = fSlow37 + fConst3 * fRec46[1];
			float fTemp57 = 1.0f - fRec46[0];
			float fTemp58 = fRec46[0] * fTemp50 + fTemp57 * (fTemp56 + fRec38[0] * fTemp50 + fRec31[0] * fTemp50);
			float fTemp59 = std::fabs(-fTemp58);
			float fTemp60 = fRec46[0] * fTemp52 + fTemp57 * (fTemp56 + fRec38[0] * fTemp52 + fRec31[0] * fTemp52);
			fRec15[0] = std::fabs(std::fabs(-fTemp60) + fTemp59) * fSlow29 + fRec15[1] * fSlow28;
			int iTemp61 = fRec15[0] > fSlow23;
			iVec47[0] = iTemp61;
			iRec47[0] = std::max<int>(iSlow38 * (iTemp61 < iVec47[1]), iRec47[1] + -1);
			float fTemp62 = std::fabs(std::max<float>(float(iTemp61), float(iRec47[0] > 0)));
			float fTemp63 = ((fTemp62 > fRec14[1]) ? fSlow42 : fSlow40);
			fRec14[0] = fTemp62 * (1.0f - fTemp63) + fRec14[1] * fTemp63;
			fVbargraph3 = FAUSTFLOAT(std::max<float>(-7e+01f, 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec14[0]))));
			float fTemp64 = -fTemp60;
			fRec13[0] = fSlow29 * std::fabs(fTemp59 + std::fabs(fTemp64)) + fSlow28 * fRec13[1];
			int iTemp65 = fRec13[0] > fSlow23;
			iVec48[0] = iTemp65;
			iRec48[0] = std::max<int>(iSlow38 * (iTemp65 < iVec48[1]), iRec48[1] + -1);
			float fTemp66 = std::fabs(std::max<float>(float(iTemp65), float(iRec48[0] > 0)));
			float fTemp67 = ((fTemp66 > fRec12[1]) ? fSlow42 : fSlow40);
			fRec12[0] = fTemp66 * (1.0f - fTemp67) + fRec12[1] * fTemp67;
			float fTemp68 = fRec12[0] * (1.0f - fRec11[0]);
			float fTemp69 = fRec11[0] + fTemp68;
			fRec49[0] = fSlow43 + fConst3 * fRec49[1];
			fRec50[0] = fSlow44 + fConst3 * fRec50[1];
			float fTemp70 = 0.025f * fRec50[0];
			float fTemp71 = std::pow(1e+01f, fTemp70);
			float fTemp72 = std::sqrt(fTemp71);
			float fTemp73 = fSlow47 * ((fSlow47 / fTemp72 + 1.4285715f) / fTemp72) + 1.0f;
			float fTemp74 = std::pow(1e+01f, -fTemp70);
			float fTemp75 = std::sqrt(fTemp74);
			float fTemp76 = fSlow48 * ((fSlow48 / fTemp75 + 1.4285715f) / fTemp75) + 1.0f;
			fRec59[0] = fSlow49 + fConst3 * fRec59[1];
			float fTemp77 = 0.05f * fRec59[0];
			float fTemp78 = std::pow(1e+01f, fTemp77);
			float fTemp79 = std::pow(1e+01f, -fTemp77);
			float fTemp80 = fTemp58 * fTemp69;
			fVec49[0] = fTemp80;
			fRec62[0] = -(fSlow52 * (fSlow51 * fRec62[1] + fSlow50 * (fTemp80 - fVec49[1])));
			fRec61[0] = -(fConst72 * (fConst71 * fRec61[1] - (fRec62[0] + fRec62[1])));
			fRec63[0] = -(fConst72 * (fConst71 * fRec63[1] - fConst70 * (fRec62[0] - fRec62[1])));
			float fTemp81 = fRec63[0] + fRec61[0] * fTemp79;
			fVec50[0] = fTemp81;
			fRec60[0] = -(fConst72 * (fConst71 * fRec60[1] - fConst70 * (fTemp81 - fVec50[1])));
			fRec64[0] = -(fConst72 * (fConst71 * fRec64[1] - (fTemp81 + fVec50[1])));
			float fTemp82 = fRec64[0] + fRec60[0] * fTemp78;
			float fTemp83 = fTemp68 * fTemp64 - fRec11[0] * fTemp60;
			fVec51[0] = fTemp83;
			fRec67[0] = -(fSlow52 * (fSlow51 * fRec67[1] - fSlow50 * (fTemp83 - fVec51[1])));
			fRec66[0] = -(fConst72 * (fConst71 * fRec66[1] - (fRec67[0] + fRec67[1])));
			fRec68[0] = -(fConst72 * (fConst71 * fRec68[1] - fConst70 * (fRec67[0] - fRec67[1])));
			float fTemp84 = fRec68[0] + fRec66[0] * fTemp79;
			fVec52[0] = fTemp84;
			fRec65[0] = -(fConst72 * (fConst71 * fRec65[1] - fConst70 * (fTemp84 - fVec52[1])));
			fRec69[0] = -(fConst72 * (fConst71 * fRec69[1] - (fTemp84 + fVec52[1])));
			float fTemp85 = fRec69[0] + fRec65[0] * fTemp78;
			float fTemp86 = fTemp85 - fTemp82;
			float fTemp87 = 0.5f * fTemp86;
			float fTemp88 = fRec55[1] + fSlow48 * ((fTemp87 - fRec56[1]) / fTemp75);
			float fTemp89 = fTemp88 / fTemp76;
			fRec55[0] = 2.0f * fTemp89 - fRec55[1];
			float fTemp90 = fRec56[1] + fSlow48 * (fTemp88 / (fTemp75 * fTemp76));
			fRec56[0] = 2.0f * fTemp90 - fRec56[1];
			float fRec57 = fTemp89;
			float fRec58 = fTemp90;
			float fTemp91 = fRec58 * (mydsp_faustpower2_f(fTemp74) + -1.0f);
			float fTemp92 = fRec57 * (fTemp74 + -1.0f);
			float fTemp93 = fTemp87 + 1.4285715f * fTemp92 + fTemp91;
			float fTemp94 = fRec51[1] + fSlow47 * ((fTemp93 - fRec52[1]) / fTemp72);
			float fTemp95 = fTemp94 / fTemp73;
			fRec51[0] = 2.0f * fTemp95 - fRec51[1];
			float fTemp96 = fRec52[1] + fSlow47 * (fTemp94 / (fTemp72 * fTemp73));
			fRec52[0] = 2.0f * fTemp96 - fRec52[1];
			float fRec53 = fTemp95;
			float fRec54 = fTemp96;
			float fTemp97 = fRec54 * (mydsp_faustpower2_f(fTemp71) + -1.0f) + fTemp91 + 1.4285715f * (fTemp92 + fRec53 * (fTemp71 + -1.0f));
			float fTemp98 = fTemp85 + fTemp82;
			float fTemp99 = 1.0f - fRec49[0];
			float fTemp100 = fTemp99 * (0.5f * (fTemp98 - fTemp86) - fTemp97) - fRec49[0] * fTemp58 * fTemp69;
			float fTemp101 = fRec49[0] * fTemp83 + fTemp99 * (0.5f * (fTemp98 + fTemp86) + fTemp97);
			float fTemp102 = std::fabs(std::fabs(fTemp101) + std::fabs(fTemp100));
			fVec53[0] = fTemp102;
			float fTemp103 = std::max<float>(fTemp102, fVec53[1]);
			fVec54[0] = fTemp103;
			float fTemp104 = std::max<float>(fTemp103, fVec54[2]);
			fVec55[0] = fTemp104;
			float fTemp105 = std::max<float>(fTemp104, fVec55[4]);
			fVec56[0] = fTemp105;
			float fTemp106 = std::max<float>(fTemp105, fVec56[8]);
			fVec57[IOTA0 & 31] = fTemp106;
			float fTemp107 = std::max<float>(fTemp106, fVec57[(IOTA0 - 16) & 31]);
			fVec58[IOTA0 & 63] = fTemp107;
			float fTemp108 = std::max<float>(fTemp107, fVec58[(IOTA0 - 32) & 63]);
			fVec59[IOTA0 & 127] = fTemp108;
			float fTemp109 = std::max<float>(fTemp108, fVec59[(IOTA0 - 64) & 127]);
			fVec60[IOTA0 & 255] = fTemp109;
			float fTemp110 = std::max<float>(fTemp109, fVec60[(IOTA0 - 128) & 255]);
			fVec61[IOTA0 & 511] = fTemp110;
			float fTemp111 = std::max<float>(fTemp110, fVec61[(IOTA0 - 256) & 511]);
			fVec62[IOTA0 & 1023] = fTemp111;
			float fTemp112 = std::max<float>(fTemp111, fVec62[(IOTA0 - 512) & 1023]);
			fVec63[IOTA0 & 2047] = fTemp112;
			float fTemp113 = std::max<float>(fTemp112, fVec63[(IOTA0 - 1024) & 2047]);
			fVec64[IOTA0 & 4095] = fTemp113;
			float fTemp114 = std::max<float>(fTemp113, fVec64[(IOTA0 - 2048) & 4095]);
			fVec65[IOTA0 & 8191] = fTemp114;
			float fTemp115 = std::max<float>(fTemp114, fVec65[(IOTA0 - 4096) & 8191]);
			fVec66[IOTA0 & 16383] = fTemp115;
			fVec67[IOTA0 & 32767] = std::max<float>(fTemp115, fVec66[(IOTA0 - 8192) & 16383]);
			float fTemp116 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(std::max<float>(((iConst73) ? fTemp102 : -3.4028235e+38f), ((iConst74) ? fVec54[iConst73] : -3.4028235e+38f)), ((iConst75) ? fVec55[iConst76] : -3.4028235e+38f)), ((iConst77) ? fVec56[iConst78] : -3.4028235e+38f)), ((iConst79) ? fVec57[(IOTA0 - iConst80) & 31] : -3.4028235e+38f)), ((iConst81) ? fVec58[(IOTA0 - iConst82) & 63] : -3.4028235e+38f)), ((iConst83) ? fVec59[(IOTA0 - iConst84) & 127] : -3.4028235e+38f)), ((iConst85) ? fVec60[(IOTA0 - iConst86) & 255] : -3.4028235e+38f)), ((iConst87) ? fVec61[(IOTA0 - iConst88) & 511] : -3.4028235e+38f)), ((iConst89) ? fVec62[(IOTA0 - iConst90) & 1023] : -3.4028235e+38f)), ((iConst91) ? fVec63[(IOTA0 - iConst92) & 2047] : -3.4028235e+38f)), ((iConst93) ? fVec64[(IOTA0 - iConst94) & 4095] : -3.4028235e+38f)), ((iConst95) ? fVec65[(IOTA0 - iConst96) & 8191] : -3.4028235e+38f)), ((iConst97) ? fVec66[(IOTA0 - iConst98) & 16383] : -3.4028235e+38f)), ((iConst99) ? fVec67[(IOTA0 - iConst100) & 32767] : -3.4028235e+38f))));
			int iTemp117 = (fTemp116 > fSlow59) + (fTemp116 > fSlow58);
			float fTemp118 = std::max<float>(-1.2e+02f, 2.0f * ((iTemp117 == 0) ? fTemp116 - fSlow57 : ((iTemp117 == 1) ? -(0.041666668f * mydsp_faustpower2_f(fTemp116 + -6.0f - fSlow57)) : 0.0f)));
			float fTemp119 = ((fTemp118 > fRec74[1]) ? fConst102 : fConst101);
			fRec74[0] = fTemp118 * (1.0f - fTemp119) + fRec74[1] * fTemp119;
			float fTemp120 = std::min<float>(1.0f, std::max<float>(0.0f, std::pow(1e+01f, 0.05f * fRec74[0])));
			fVbargraph4 = FAUSTFLOAT(1e+02f * (1.0f - fTemp120));
			float fTemp121 = fSlow60 / fTemp120;
			int iTemp122 = std::fabs(fTemp121) < 1.1920929e-07f;
			float fTemp123 = ((iTemp122) ? 0.0f : std::exp(-(fConst5 / ((iTemp122) ? 1.0f : fTemp121))));
			fVec68[0] = fConst15 * fRec77[1] - fConst13 * fRec3[2];
			fRec78[0] = fConst17 * (fConst16 * fRec3[2] - (fVec68[1] + fConst12 * fRec78[1]) + fConst11 * fRec3[1]);
			fRec77[0] = fRec78[0];
			fVec69[0] = 0.50032705f * fRec77[1] - fConst22 * fRec75[1];
			fRec76[0] = fConst23 * (fVec69[1] - fConst20 * fRec76[1] - 1.0006541f * fRec77[1] + 0.50032705f * fRec77[0]);
			fRec75[0] = fRec76[0];
			float fTemp124 = mydsp_faustpower2_f(fRec75[0]);
			fVec70[0] = fTemp124;
			float fTemp125 = fTemp124 + fVec70[1];
			fVec71[0] = fTemp125;
			float fTemp126 = fTemp125 + fVec71[2];
			fVec72[0] = fTemp126;
			float fTemp127 = fTemp126 + fVec72[4];
			fVec73[0] = fTemp127;
			float fTemp128 = fTemp127 + fVec73[8];
			fVec74[IOTA0 & 31] = fTemp128;
			float fTemp129 = fTemp128 + fVec74[(IOTA0 - 16) & 31];
			fVec75[IOTA0 & 63] = fTemp129;
			float fTemp130 = fTemp129 + fVec75[(IOTA0 - 32) & 63];
			fVec76[IOTA0 & 127] = fTemp130;
			float fTemp131 = fTemp130 + fVec76[(IOTA0 - 64) & 127];
			fVec77[IOTA0 & 255] = fTemp131;
			float fTemp132 = fTemp131 + fVec77[(IOTA0 - 128) & 255];
			fVec78[IOTA0 & 511] = fTemp132;
			float fTemp133 = fTemp132 + fVec78[(IOTA0 - 256) & 511];
			fVec79[IOTA0 & 1023] = fTemp133;
			float fTemp134 = fTemp133 + fVec79[(IOTA0 - 512) & 1023];
			fVec80[IOTA0 & 2047] = fTemp134;
			float fTemp135 = fTemp134 + fVec80[(IOTA0 - 1024) & 2047];
			fVec81[IOTA0 & 4095] = fTemp135;
			float fTemp136 = fTemp135 + fVec81[(IOTA0 - 2048) & 4095];
			fVec82[IOTA0 & 8191] = fTemp136;
			float fTemp137 = fTemp136 + fVec82[(IOTA0 - 4096) & 8191];
			fVec83[IOTA0 & 16383] = fTemp137;
			float fTemp138 = fTemp137 + fVec83[(IOTA0 - 8192) & 16383];
			fVec84[IOTA0 & 32767] = fTemp138;
			float fTemp139 = fTemp138 + fVec84[(IOTA0 - 16384) & 32767];
			fVec85[IOTA0 & 65535] = fTemp139;
			fVec86[IOTA0 & 131071] = fTemp139 + fVec85[(IOTA0 - 32768) & 65535];
			fVec87[0] = fConst15 * fRec81[1] - fConst13 * fRec2[2];
			fRec82[0] = fConst17 * (fConst16 * fRec2[2] - (fVec87[1] + fConst12 * fRec82[1]) + fConst11 * fRec2[1]);
			fRec81[0] = fRec82[0];
			fVec88[0] = 0.50032705f * fRec81[1] - fConst22 * fRec79[1];
			fRec80[0] = fConst23 * (fVec88[1] - fConst20 * fRec80[1] - 1.0006541f * fRec81[1] + 0.50032705f * fRec81[0]);
			fRec79[0] = fRec80[0];
			float fTemp140 = mydsp_faustpower2_f(fRec79[0]);
			fVec89[0] = fTemp140;
			float fTemp141 = fTemp140 + fVec89[1];
			fVec90[0] = fTemp141;
			float fTemp142 = fTemp141 + fVec90[2];
			fVec91[0] = fTemp142;
			float fTemp143 = fTemp142 + fVec91[4];
			fVec92[0] = fTemp143;
			float fTemp144 = fTemp143 + fVec92[8];
			fVec93[IOTA0 & 31] = fTemp144;
			float fTemp145 = fTemp144 + fVec93[(IOTA0 - 16) & 31];
			fVec94[IOTA0 & 63] = fTemp145;
			float fTemp146 = fTemp145 + fVec94[(IOTA0 - 32) & 63];
			fVec95[IOTA0 & 127] = fTemp146;
			float fTemp147 = fTemp146 + fVec95[(IOTA0 - 64) & 127];
			fVec96[IOTA0 & 255] = fTemp147;
			float fTemp148 = fTemp147 + fVec96[(IOTA0 - 128) & 255];
			fVec97[IOTA0 & 511] = fTemp148;
			float fTemp149 = fTemp148 + fVec97[(IOTA0 - 256) & 511];
			fVec98[IOTA0 & 1023] = fTemp149;
			float fTemp150 = fTemp149 + fVec98[(IOTA0 - 512) & 1023];
			fVec99[IOTA0 & 2047] = fTemp150;
			float fTemp151 = fTemp150 + fVec99[(IOTA0 - 1024) & 2047];
			fVec100[IOTA0 & 4095] = fTemp151;
			float fTemp152 = fTemp151 + fVec100[(IOTA0 - 2048) & 4095];
			fVec101[IOTA0 & 8191] = fTemp152;
			float fTemp153 = fTemp152 + fVec101[(IOTA0 - 4096) & 8191];
			fVec102[IOTA0 & 16383] = fTemp153;
			float fTemp154 = fTemp153 + fVec102[(IOTA0 - 8192) & 16383];
			fVec103[IOTA0 & 32767] = fTemp154;
			float fTemp155 = fTemp154 + fVec103[(IOTA0 - 16384) & 32767];
			fVec104[IOTA0 & 65535] = fTemp155;
			fVec105[IOTA0 & 131071] = fTemp155 + fVec104[(IOTA0 - 32768) & 65535];
			fRec73[0] = (1.0f - fTemp123) * std::max<float>(-(float(fVslider20)), std::min<float>(fSlow61, fSlow4 + fRec72[1] + (0.691f - 4.3429446f * std::log(std::max<float>(1e-12f, fConst136 * (((iConst134) ? fVec105[(IOTA0 - iConst135) & 131071] : 0.0f) + ((iConst132) ? fVec104[(IOTA0 - iConst133) & 65535] : 0.0f) + ((iConst130) ? fVec103[(IOTA0 - iConst131) & 32767] : 0.0f) + ((iConst128) ? fVec102[(IOTA0 - iConst129) & 16383] : 0.0f) + ((iConst126) ? fVec101[(IOTA0 - iConst127) & 8191] : 0.0f) + ((iConst124) ? fVec100[(IOTA0 - iConst125) & 4095] : 0.0f) + ((iConst122) ? fVec99[(IOTA0 - iConst123) & 2047] : 0.0f) + ((iConst120) ? fVec98[(IOTA0 - iConst121) & 1023] : 0.0f) + ((iConst118) ? fVec97[(IOTA0 - iConst119) & 511] : 0.0f) + ((iConst116) ? fVec96[(IOTA0 - iConst117) & 255] : 0.0f) + ((iConst114) ? fVec95[(IOTA0 - iConst115) & 127] : 0.0f) + ((iConst112) ? fVec94[(IOTA0 - iConst113) & 63] : 0.0f) + ((iConst110) ? fVec93[(IOTA0 - iConst111) & 31] : 0.0f) + ((iConst108) ? fVec92[iConst109] : 0.0f) + ((iConst106) ? fVec91[iConst107] : 0.0f) + ((iConst105) ? fTemp140 : 0.0f) + ((iConst104) ? fVec90[iConst105] : 0.0f) + ((iConst134) ? fVec86[(IOTA0 - iConst135) & 131071] : 0.0f) + ((iConst132) ? fVec85[(IOTA0 - iConst133) & 65535] : 0.0f) + ((iConst130) ? fVec84[(IOTA0 - iConst131) & 32767] : 0.0f) + ((iConst128) ? fVec83[(IOTA0 - iConst129) & 16383] : 0.0f) + ((iConst126) ? fVec82[(IOTA0 - iConst127) & 8191] : 0.0f) + ((iConst124) ? fVec81[(IOTA0 - iConst125) & 4095] : 0.0f) + ((iConst122) ? fVec80[(IOTA0 - iConst123) & 2047] : 0.0f) + ((iConst120) ? fVec79[(IOTA0 - iConst121) & 1023] : 0.0f) + ((iConst118) ? fVec78[(IOTA0 - iConst119) & 511] : 0.0f) + ((iConst116) ? fVec77[(IOTA0 - iConst117) & 255] : 0.0f) + ((iConst114) ? fVec76[(IOTA0 - iConst115) & 127] : 0.0f) + ((iConst112) ? fVec75[(IOTA0 - iConst113) & 63] : 0.0f) + ((iConst110) ? fVec74[(IOTA0 - iConst111) & 31] : 0.0f) + ((iConst108) ? fVec73[iConst109] : 0.0f) + ((iConst106) ? fVec72[iConst107] : 0.0f) + ((iConst105) ? fTemp124 : 0.0f) + ((iConst104) ? fVec71[iConst105] : 0.0f))))))) + fTemp123 * fRec73[1];
			fVbargraph5 = FAUSTFLOAT(fRec73[0]);
			fRec72[0] = fVbargraph5;
			fRec83[0] = fSlow62 + fConst3 * fRec83[1];
			float fTemp156 = fRec83[0] + (1.0f - fRec83[0]) * std::pow(1e+01f, 0.05f * fRec72[0]);
			float fTemp157 = fSlow63 * fRec5[1] + fSlow64 * fTemp100 * fTemp156;
			float fTemp158 = fSlow63 * fRec4[1] + fSlow64 * fTemp101 * fTemp156;
			fRec71[IOTA0 & 262143] = fRec71[(IOTA0 - 1) & 262143] + mydsp_faustpower2_f(0.5f * (fTemp158 + fTemp157));
			float fTemp159 = std::sqrt(fSlow67 * (fRec71[IOTA0 & 262143] - fRec71[(IOTA0 - iSlow66) & 262143]));
			float fTemp160 = ((fTemp159 > fRec70[1]) ? fSlow70 : 0.0f);
			fRec70[0] = fTemp159 * (1.0f - fTemp160) + fRec70[1] * fTemp160;
			float fTemp161 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec70[0]));
			int iTemp162 = (fTemp161 > fSlow71) + (fTemp161 > fSlow56);
			float fTemp163 = fTemp161 - fSlow55;
			float fTemp164 = std::max<float>(0.0f, ((iTemp162 == 0) ? 0.0f : ((iTemp162 == 1) ? fSlow72 * mydsp_faustpower2_f(fSlow54 + fTemp163) : fTemp163)));
			float fTemp165 = fSlow74 * fTemp164;
			fRec85[IOTA0 & 262143] = fRec85[(IOTA0 - 1) & 262143] + mydsp_faustpower2_f(0.5f * (fTemp158 - fTemp157));
			float fTemp166 = std::sqrt(fSlow67 * (fRec85[IOTA0 & 262143] - fRec85[(IOTA0 - iSlow66) & 262143]));
			float fTemp167 = ((fTemp166 > fRec84[1]) ? fSlow70 : 0.0f);
			fRec84[0] = fTemp166 * (1.0f - fTemp167) + fRec84[1] * fTemp167;
			float fTemp168 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec84[0]));
			int iTemp169 = (fTemp168 > fSlow71) + (fTemp168 > fSlow56);
			float fTemp170 = fTemp168 - fSlow55;
			float fTemp171 = std::max<float>(0.0f, ((iTemp169 == 0) ? 0.0f : ((iTemp169 == 1) ? fSlow72 * mydsp_faustpower2_f(fSlow54 + fTemp170) : fTemp170)));
			float fTemp172 = fSlow74 * fTemp171;
			float fTemp173 = std::min<float>(-fTemp165, -fTemp172);
			float fTemp174 = 0.01f * (fSlow73 * fTemp171 - fSlow75 * (fTemp172 + fTemp173));
			fVbargraph6 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, -fTemp174)));
			fRec86[0] = fSlow76 + fConst3 * fRec86[1];
			fRec87[0] = fSlow77 + fConst3 * fRec87[1];
			float fTemp175 = 1.0f - fRec87[0];
			float fTemp176 = (fRec87[0] + fTemp175 * std::pow(1e+01f, 0.05f * (fRec86[0] + -fTemp174))) * (fTemp101 - fTemp100);
			float fTemp177 = 0.01f * (fSlow73 * fTemp164 - fSlow75 * (fTemp165 + fTemp173));
			fVbargraph7 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, -fTemp177)));
			float fTemp178 = (fRec87[0] + fTemp175 * std::pow(1e+01f, 0.05f * (fRec86[0] + -fTemp177))) * (fTemp101 + fTemp100);
			fRec88[0] = fSlow78 + fConst3 * fRec88[1];
			float fTemp179 = fTemp100 + fRec88[0] * (0.5f * (fTemp178 - fTemp176) - fTemp100);
			float fTemp180 = fTemp101 + fRec88[0] * (0.5f * (fTemp178 + fTemp176) - fTemp101);
			float fTemp181 = 0.5f * fTemp156 * (fTemp180 - fTemp179);
			fRec10[0] = fTemp181 - fSlow21 * (fSlow19 * fRec10[2] + fSlow11 * fRec10[1]);
			float fTemp182 = 2.0f * fRec10[1];
			fRec9[0] = fSlow79 * (fRec10[2] + (fRec10[0] - fTemp182)) - fSlow18 * (fSlow16 * fRec9[2] + fSlow11 * fRec9[1]);
			fRec8[0] = fSlow80 * (fRec9[2] + (fRec9[0] - 2.0f * fRec9[1])) - fSlow15 * (fSlow13 * fRec8[2] + fSlow11 * fRec8[1]);
			float fTemp183 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow81 * (fRec8[2] + (fRec8[0] - 2.0f * fRec8[1])))));
			int iTemp184 = (fTemp183 > fSlow83) + (fTemp183 > fSlow6);
			float fTemp185 = fTemp183 - fSlow82;
			float fTemp186 = std::max<float>(0.0f, ((iTemp184 == 0) ? 0.0f : ((iTemp184 == 1) ? fSlow84 * mydsp_faustpower2_f(fSlow3 + fTemp185) : fTemp185)));
			float fTemp187 = ((-(fSlow87 * fTemp186) > fRec7[1]) ? fSlow97 : fSlow92);
			fRec7[0] = fRec7[1] * fTemp187 - fSlow87 * fTemp186 * (1.0f - fTemp187);
			float fTemp188 = 0.5f * fTemp156 * (fTemp180 + fTemp179);
			fRec92[0] = fTemp188 - fSlow21 * (fSlow19 * fRec92[2] + fSlow11 * fRec92[1]);
			float fTemp189 = 2.0f * fRec92[1];
			fRec91[0] = fSlow79 * (fRec92[2] + (fRec92[0] - fTemp189)) - fSlow18 * (fSlow16 * fRec91[2] + fSlow11 * fRec91[1]);
			fRec90[0] = fSlow80 * (fRec91[2] + (fRec91[0] - 2.0f * fRec91[1])) - fSlow15 * (fSlow13 * fRec90[2] + fSlow11 * fRec90[1]);
			float fTemp190 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow81 * (fRec90[2] + (fRec90[0] - 2.0f * fRec90[1])))));
			int iTemp191 = (fTemp190 > fSlow83) + (fTemp190 > fSlow6);
			float fTemp192 = fTemp190 - fSlow82;
			float fTemp193 = std::max<float>(0.0f, ((iTemp191 == 0) ? 0.0f : ((iTemp191 == 1) ? fSlow84 * mydsp_faustpower2_f(fSlow3 + fTemp192) : fTemp192)));
			float fTemp194 = ((-(fSlow87 * fTemp193) > fRec89[1]) ? fSlow97 : fSlow92);
			fRec89[0] = fRec89[1] * fTemp194 - fSlow87 * fTemp193 * (1.0f - fTemp194);
			float fTemp195 = std::min<float>(fRec89[0], fRec7[0]);
			float fTemp196 = fRec7[0] + fSlow100 * (fTemp195 - fRec7[0]);
			fVbargraph8 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp196)));
			float fTemp197 = std::pow(1e+01f, 0.008333334f * fTemp196);
			float fTemp198 = 1.0f - mydsp_faustpower2_f(fTemp197);
			float fTemp199 = std::sqrt(fTemp197);
			float fTemp200 = fSlow9 * fTemp199;
			float fTemp201 = fSlow9 * fTemp199 * (fTemp200 + 0.5f) + 1.0f;
			float fTemp202 = fSlow9 * fTemp199 * (fTemp200 + 1.4144272f) + 1.0f;
			float fTemp203 = fSlow9 * fTemp199 * (fTemp200 + 2.0f) + 1.0f;
			fRec113[0] = fSlow21 * (fRec10[2] + fRec10[0] + fTemp182) - fSlow18 * (fSlow16 * fRec113[2] + fSlow11 * fRec113[1]);
			fRec112[0] = fSlow18 * (fRec113[2] + fRec113[0] + 2.0f * fRec113[1]) - fSlow15 * (fSlow13 * fRec112[2] + fSlow11 * fRec112[1]);
			fRec111[0] = fSlow15 * (fRec112[2] + fRec112[0] + 2.0f * fRec112[1]) - fSlow122 * (fSlow120 * fRec111[2] + fSlow112 * fRec111[1]);
			float fTemp204 = 2.0f * fRec111[1];
			fRec110[0] = fSlow123 * (fRec111[2] + (fRec111[0] - fTemp204)) - fSlow119 * (fSlow117 * fRec110[2] + fSlow112 * fRec110[1]);
			fRec109[0] = fSlow124 * (fRec110[2] + (fRec110[0] - 2.0f * fRec110[1])) - fSlow116 * (fSlow114 * fRec109[2] + fSlow112 * fRec109[1]);
			float fTemp205 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow125 * (fRec109[2] + (fRec109[0] - 2.0f * fRec109[1])))));
			int iTemp206 = (fTemp205 > fSlow126) + (fTemp205 > fSlow109);
			float fTemp207 = fTemp205 - fSlow108;
			float fTemp208 = std::max<float>(0.0f, ((iTemp206 == 0) ? 0.0f : ((iTemp206 == 1) ? fSlow127 * mydsp_faustpower2_f(fSlow104 + fTemp207) : fTemp207)));
			float fTemp209 = ((-(fSlow129 * fTemp208) > fRec108[1]) ? fSlow135 : fSlow132);
			fRec108[0] = fRec108[1] * fTemp209 - fSlow129 * fTemp208 * (1.0f - fTemp209);
			fRec119[0] = fSlow21 * (fRec92[2] + fRec92[0] + fTemp189) - fSlow18 * (fSlow16 * fRec119[2] + fSlow11 * fRec119[1]);
			fRec118[0] = fSlow18 * (fRec119[2] + fRec119[0] + 2.0f * fRec119[1]) - fSlow15 * (fSlow13 * fRec118[2] + fSlow11 * fRec118[1]);
			fRec117[0] = fSlow15 * (fRec118[2] + fRec118[0] + 2.0f * fRec118[1]) - fSlow122 * (fSlow120 * fRec117[2] + fSlow112 * fRec117[1]);
			float fTemp210 = 2.0f * fRec117[1];
			fRec116[0] = fSlow123 * (fRec117[2] + (fRec117[0] - fTemp210)) - fSlow119 * (fSlow117 * fRec116[2] + fSlow112 * fRec116[1]);
			fRec115[0] = fSlow124 * (fRec116[2] + (fRec116[0] - 2.0f * fRec116[1])) - fSlow116 * (fSlow114 * fRec115[2] + fSlow112 * fRec115[1]);
			float fTemp211 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow125 * (fRec115[2] + (fRec115[0] - 2.0f * fRec115[1])))));
			int iTemp212 = (fTemp211 > fSlow126) + (fTemp211 > fSlow109);
			float fTemp213 = fTemp211 - fSlow108;
			float fTemp214 = std::max<float>(0.0f, ((iTemp212 == 0) ? 0.0f : ((iTemp212 == 1) ? fSlow127 * mydsp_faustpower2_f(fSlow104 + fTemp213) : fTemp213)));
			float fTemp215 = ((-(fSlow129 * fTemp214) > fRec114[1]) ? fSlow135 : fSlow132);
			fRec114[0] = fRec114[1] * fTemp215 - fSlow129 * fTemp214 * (1.0f - fTemp215);
			float fTemp216 = std::min<float>(fRec114[0], fRec108[0]);
			float fTemp217 = fRec108[0] + fSlow137 * (fTemp216 - fRec108[0]);
			fVbargraph9 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp217)));
			float fTemp218 = 0.008333334f * fTemp217;
			float fTemp219 = std::pow(1e+01f, fTemp218);
			float fTemp220 = mydsp_faustpower2_f(fTemp219) + -1.0f;
			float fTemp221 = std::sqrt(fTemp219);
			float fTemp222 = fSlow9 / fTemp221;
			float fTemp223 = fSlow9 * ((fTemp222 + 0.5f) / fTemp221) + 1.0f;
			float fTemp224 = fSlow9 * ((fTemp222 + 1.4144272f) / fTemp221) + 1.0f;
			float fTemp225 = fSlow9 * ((fTemp222 + 2.0f) / fTemp221) + 1.0f;
			float fTemp226 = std::pow(1e+01f, -fTemp218);
			float fTemp227 = mydsp_faustpower2_f(fTemp226) + -1.0f;
			float fTemp228 = std::sqrt(fTemp226);
			float fTemp229 = fSlow110 / fTemp228;
			float fTemp230 = fSlow110 * ((fTemp229 + 0.5f) / fTemp228) + 1.0f;
			float fTemp231 = fSlow110 * ((fTemp229 + 1.4144272f) / fTemp228) + 1.0f;
			float fTemp232 = fSlow110 * ((fTemp229 + 2.0f) / fTemp228) + 1.0f;
			fRec155[0] = fSlow122 * (fRec111[2] + fRec111[0] + fTemp204) - fSlow119 * (fSlow117 * fRec155[2] + fSlow112 * fRec155[1]);
			fRec154[0] = fSlow119 * (fRec155[2] + fRec155[0] + 2.0f * fRec155[1]) - fSlow116 * (fSlow114 * fRec154[2] + fSlow112 * fRec154[1]);
			fRec153[0] = fSlow116 * (fRec154[2] + fRec154[0] + 2.0f * fRec154[1]) - fSlow154 * (fSlow152 * fRec153[2] + fSlow144 * fRec153[1]);
			float fTemp233 = 2.0f * fRec153[1];
			fRec152[0] = fSlow155 * (fRec153[2] + (fRec153[0] - fTemp233)) - fSlow151 * (fSlow149 * fRec152[2] + fSlow144 * fRec152[1]);
			fRec151[0] = fSlow156 * (fRec152[2] + (fRec152[0] - 2.0f * fRec152[1])) - fSlow148 * (fSlow146 * fRec151[2] + fSlow144 * fRec151[1]);
			float fTemp234 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow157 * (fRec151[2] + (fRec151[0] - 2.0f * fRec151[1])))));
			int iTemp235 = (fTemp234 > fSlow158) + (fTemp234 > fSlow141);
			float fTemp236 = fTemp234 - fSlow140;
			float fTemp237 = std::max<float>(0.0f, ((iTemp235 == 0) ? 0.0f : ((iTemp235 == 1) ? fSlow159 * mydsp_faustpower2_f(fSlow139 + fTemp236) : fTemp236)));
			float fTemp238 = ((-(fSlow160 * fTemp237) > fRec150[1]) ? fSlow166 : fSlow163);
			fRec150[0] = fRec150[1] * fTemp238 - fSlow160 * fTemp237 * (1.0f - fTemp238);
			fRec161[0] = fSlow122 * (fRec117[2] + fRec117[0] + fTemp210) - fSlow119 * (fSlow117 * fRec161[2] + fSlow112 * fRec161[1]);
			fRec160[0] = fSlow119 * (fRec161[2] + fRec161[0] + 2.0f * fRec161[1]) - fSlow116 * (fSlow114 * fRec160[2] + fSlow112 * fRec160[1]);
			fRec159[0] = fSlow116 * (fRec160[2] + fRec160[0] + 2.0f * fRec160[1]) - fSlow154 * (fSlow152 * fRec159[2] + fSlow144 * fRec159[1]);
			float fTemp239 = 2.0f * fRec159[1];
			fRec158[0] = fSlow155 * (fRec159[2] + (fRec159[0] - fTemp239)) - fSlow151 * (fSlow149 * fRec158[2] + fSlow144 * fRec158[1]);
			fRec157[0] = fSlow156 * (fRec158[2] + (fRec158[0] - 2.0f * fRec158[1])) - fSlow148 * (fSlow146 * fRec157[2] + fSlow144 * fRec157[1]);
			float fTemp240 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow157 * (fRec157[2] + (fRec157[0] - 2.0f * fRec157[1])))));
			int iTemp241 = (fTemp240 > fSlow158) + (fTemp240 > fSlow141);
			float fTemp242 = fTemp240 - fSlow140;
			float fTemp243 = std::max<float>(0.0f, ((iTemp241 == 0) ? 0.0f : ((iTemp241 == 1) ? fSlow159 * mydsp_faustpower2_f(fSlow139 + fTemp242) : fTemp242)));
			float fTemp244 = ((-(fSlow160 * fTemp243) > fRec156[1]) ? fSlow166 : fSlow163);
			fRec156[0] = fRec156[1] * fTemp244 - fSlow160 * fTemp243 * (1.0f - fTemp244);
			float fTemp245 = std::min<float>(fRec156[0], fRec150[0]);
			float fTemp246 = fRec150[0] + fSlow167 * (fTemp245 - fRec150[0]);
			fVbargraph10 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp246)));
			float fTemp247 = 0.008333334f * fTemp246;
			float fTemp248 = std::pow(1e+01f, fTemp247);
			float fTemp249 = mydsp_faustpower2_f(fTemp248) + -1.0f;
			float fTemp250 = std::sqrt(fTemp248);
			float fTemp251 = fSlow110 / fTemp250;
			float fTemp252 = fSlow110 * ((fTemp251 + 0.5f) / fTemp250) + 1.0f;
			float fTemp253 = fSlow110 * ((fTemp251 + 1.4144272f) / fTemp250) + 1.0f;
			float fTemp254 = fSlow110 * ((fTemp251 + 2.0f) / fTemp250) + 1.0f;
			float fTemp255 = std::pow(1e+01f, -fTemp247);
			float fTemp256 = mydsp_faustpower2_f(fTemp255) + -1.0f;
			float fTemp257 = std::sqrt(fTemp255);
			float fTemp258 = fSlow142 / fTemp257;
			float fTemp259 = fSlow142 * ((fTemp258 + 0.5f) / fTemp257) + 1.0f;
			float fTemp260 = fSlow142 * ((fTemp258 + 1.4144272f) / fTemp257) + 1.0f;
			float fTemp261 = fSlow142 * ((fTemp258 + 2.0f) / fTemp257) + 1.0f;
			fRec197[0] = fSlow154 * (fRec153[2] + fRec153[0] + fTemp233) - fSlow151 * (fSlow149 * fRec197[2] + fSlow144 * fRec197[1]);
			fRec196[0] = fSlow151 * (fRec197[2] + fRec197[0] + 2.0f * fRec197[1]) - fSlow148 * (fSlow146 * fRec196[2] + fSlow144 * fRec196[1]);
			fRec195[0] = fSlow148 * (fRec196[2] + fRec196[0] + 2.0f * fRec196[1]) - fSlow184 * (fSlow182 * fRec195[2] + fSlow174 * fRec195[1]);
			float fTemp262 = 2.0f * fRec195[1];
			fRec194[0] = fSlow185 * (fRec195[2] + (fRec195[0] - fTemp262)) - fSlow181 * (fSlow179 * fRec194[2] + fSlow174 * fRec194[1]);
			fRec193[0] = fSlow186 * (fRec194[2] + (fRec194[0] - 2.0f * fRec194[1])) - fSlow178 * (fSlow176 * fRec193[2] + fSlow174 * fRec193[1]);
			float fTemp263 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow187 * (fRec193[2] + (fRec193[0] - 2.0f * fRec193[1])))));
			int iTemp264 = (fTemp263 > fSlow188) + (fTemp263 > fSlow171);
			float fTemp265 = fTemp263 - fSlow170;
			float fTemp266 = std::max<float>(0.0f, ((iTemp264 == 0) ? 0.0f : ((iTemp264 == 1) ? fSlow189 * mydsp_faustpower2_f(fSlow169 + fTemp265) : fTemp265)));
			float fTemp267 = ((-(fSlow190 * fTemp266) > fRec192[1]) ? fSlow196 : fSlow193);
			fRec192[0] = fRec192[1] * fTemp267 - fSlow190 * fTemp266 * (1.0f - fTemp267);
			fRec203[0] = fSlow154 * (fRec159[2] + fRec159[0] + fTemp239) - fSlow151 * (fSlow149 * fRec203[2] + fSlow144 * fRec203[1]);
			fRec202[0] = fSlow151 * (fRec203[2] + fRec203[0] + 2.0f * fRec203[1]) - fSlow148 * (fSlow146 * fRec202[2] + fSlow144 * fRec202[1]);
			fRec201[0] = fSlow148 * (fRec202[2] + fRec202[0] + 2.0f * fRec202[1]) - fSlow184 * (fSlow182 * fRec201[2] + fSlow174 * fRec201[1]);
			float fTemp268 = 2.0f * fRec201[1];
			fRec200[0] = fSlow185 * (fRec201[2] + (fRec201[0] - fTemp268)) - fSlow181 * (fSlow179 * fRec200[2] + fSlow174 * fRec200[1]);
			fRec199[0] = fSlow186 * (fRec200[2] + (fRec200[0] - 2.0f * fRec200[1])) - fSlow178 * (fSlow176 * fRec199[2] + fSlow174 * fRec199[1]);
			float fTemp269 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow187 * (fRec199[2] + (fRec199[0] - 2.0f * fRec199[1])))));
			int iTemp270 = (fTemp269 > fSlow188) + (fTemp269 > fSlow171);
			float fTemp271 = fTemp269 - fSlow170;
			float fTemp272 = std::max<float>(0.0f, ((iTemp270 == 0) ? 0.0f : ((iTemp270 == 1) ? fSlow189 * mydsp_faustpower2_f(fSlow169 + fTemp271) : fTemp271)));
			float fTemp273 = ((-(fSlow190 * fTemp272) > fRec198[1]) ? fSlow196 : fSlow193);
			fRec198[0] = fRec198[1] * fTemp273 - fSlow190 * fTemp272 * (1.0f - fTemp273);
			float fTemp274 = std::min<float>(fRec198[0], fRec192[0]);
			float fTemp275 = fRec192[0] + fSlow197 * (fTemp274 - fRec192[0]);
			fVbargraph11 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp275)));
			float fTemp276 = 0.008333334f * fTemp275;
			float fTemp277 = std::pow(1e+01f, fTemp276);
			float fTemp278 = mydsp_faustpower2_f(fTemp277) + -1.0f;
			float fTemp279 = std::sqrt(fTemp277);
			float fTemp280 = fSlow142 / fTemp279;
			float fTemp281 = fSlow142 * ((fTemp280 + 0.5f) / fTemp279) + 1.0f;
			float fTemp282 = fSlow142 * ((fTemp280 + 1.4144272f) / fTemp279) + 1.0f;
			float fTemp283 = fSlow142 * ((fTemp280 + 2.0f) / fTemp279) + 1.0f;
			float fTemp284 = std::pow(1e+01f, -fTemp276);
			float fTemp285 = mydsp_faustpower2_f(fTemp284) + -1.0f;
			float fTemp286 = std::sqrt(fTemp284);
			float fTemp287 = fSlow172 / fTemp286;
			float fTemp288 = fSlow172 * ((fTemp287 + 0.5f) / fTemp286) + 1.0f;
			float fTemp289 = fSlow172 * ((fTemp287 + 1.4144272f) / fTemp286) + 1.0f;
			float fTemp290 = fSlow172 * ((fTemp287 + 2.0f) / fTemp286) + 1.0f;
			fRec239[0] = fSlow184 * (fRec195[2] + fRec195[0] + fTemp262) - fSlow181 * (fSlow179 * fRec239[2] + fSlow174 * fRec239[1]);
			fRec238[0] = fSlow181 * (fRec239[2] + fRec239[0] + 2.0f * fRec239[1]) - fSlow178 * (fSlow176 * fRec238[2] + fSlow174 * fRec238[1]);
			fRec237[0] = fSlow178 * (fRec238[2] + fRec238[0] + 2.0f * fRec238[1]) - fSlow214 * (fSlow212 * fRec237[2] + fSlow204 * fRec237[1]);
			float fTemp291 = 2.0f * fRec237[1];
			fRec236[0] = fSlow215 * (fRec237[2] + (fRec237[0] - fTemp291)) - fSlow211 * (fSlow209 * fRec236[2] + fSlow204 * fRec236[1]);
			fRec235[0] = fSlow216 * (fRec236[2] + (fRec236[0] - 2.0f * fRec236[1])) - fSlow208 * (fSlow206 * fRec235[2] + fSlow204 * fRec235[1]);
			float fTemp292 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow217 * (fRec235[2] + (fRec235[0] - 2.0f * fRec235[1])))));
			int iTemp293 = (fTemp292 > fSlow218) + (fTemp292 > fSlow201);
			float fTemp294 = fTemp292 - fSlow200;
			float fTemp295 = std::max<float>(0.0f, ((iTemp293 == 0) ? 0.0f : ((iTemp293 == 1) ? fSlow219 * mydsp_faustpower2_f(fSlow199 + fTemp294) : fTemp294)));
			float fTemp296 = ((-(fSlow220 * fTemp295) > fRec234[1]) ? fSlow226 : fSlow223);
			fRec234[0] = fRec234[1] * fTemp296 - fSlow220 * fTemp295 * (1.0f - fTemp296);
			fRec245[0] = fSlow184 * (fRec201[2] + fRec201[0] + fTemp268) - fSlow181 * (fSlow179 * fRec245[2] + fSlow174 * fRec245[1]);
			fRec244[0] = fSlow181 * (fRec245[2] + fRec245[0] + 2.0f * fRec245[1]) - fSlow178 * (fSlow176 * fRec244[2] + fSlow174 * fRec244[1]);
			fRec243[0] = fSlow178 * (fRec244[2] + fRec244[0] + 2.0f * fRec244[1]) - fSlow214 * (fSlow212 * fRec243[2] + fSlow204 * fRec243[1]);
			float fTemp297 = 2.0f * fRec243[1];
			fRec242[0] = fSlow215 * (fRec243[2] + (fRec243[0] - fTemp297)) - fSlow211 * (fSlow209 * fRec242[2] + fSlow204 * fRec242[1]);
			fRec241[0] = fSlow216 * (fRec242[2] + (fRec242[0] - 2.0f * fRec242[1])) - fSlow208 * (fSlow206 * fRec241[2] + fSlow204 * fRec241[1]);
			float fTemp298 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow217 * (fRec241[2] + (fRec241[0] - 2.0f * fRec241[1])))));
			int iTemp299 = (fTemp298 > fSlow218) + (fTemp298 > fSlow201);
			float fTemp300 = fTemp298 - fSlow200;
			float fTemp301 = std::max<float>(0.0f, ((iTemp299 == 0) ? 0.0f : ((iTemp299 == 1) ? fSlow219 * mydsp_faustpower2_f(fSlow199 + fTemp300) : fTemp300)));
			float fTemp302 = ((-(fSlow220 * fTemp301) > fRec240[1]) ? fSlow226 : fSlow223);
			fRec240[0] = fRec240[1] * fTemp302 - fSlow220 * fTemp301 * (1.0f - fTemp302);
			float fTemp303 = std::min<float>(fRec240[0], fRec234[0]);
			float fTemp304 = fRec234[0] + fSlow227 * (fTemp303 - fRec234[0]);
			fVbargraph12 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp304)));
			float fTemp305 = 0.008333334f * fTemp304;
			float fTemp306 = std::pow(1e+01f, fTemp305);
			float fTemp307 = mydsp_faustpower2_f(fTemp306) + -1.0f;
			float fTemp308 = std::sqrt(fTemp306);
			float fTemp309 = fSlow172 / fTemp308;
			float fTemp310 = fSlow172 * ((fTemp309 + 0.5f) / fTemp308) + 1.0f;
			float fTemp311 = fSlow172 * ((fTemp309 + 1.4144272f) / fTemp308) + 1.0f;
			float fTemp312 = fSlow172 * ((fTemp309 + 2.0f) / fTemp308) + 1.0f;
			float fTemp313 = std::pow(1e+01f, -fTemp305);
			float fTemp314 = mydsp_faustpower2_f(fTemp313) + -1.0f;
			float fTemp315 = std::sqrt(fTemp313);
			float fTemp316 = fSlow202 / fTemp315;
			float fTemp317 = fSlow202 * ((fTemp316 + 0.5f) / fTemp315) + 1.0f;
			float fTemp318 = fSlow202 * ((fTemp316 + 1.4144272f) / fTemp315) + 1.0f;
			float fTemp319 = fSlow202 * ((fTemp316 + 2.0f) / fTemp315) + 1.0f;
			fRec281[0] = fSlow214 * (fRec237[2] + fRec237[0] + fTemp291) - fSlow211 * (fSlow209 * fRec281[2] + fSlow204 * fRec281[1]);
			fRec280[0] = fSlow211 * (fRec281[2] + fRec281[0] + 2.0f * fRec281[1]) - fSlow208 * (fSlow206 * fRec280[2] + fSlow204 * fRec280[1]);
			fRec279[0] = fSlow208 * (fRec280[2] + fRec280[0] + 2.0f * fRec280[1]) - fSlow244 * (fSlow242 * fRec279[2] + fSlow234 * fRec279[1]);
			float fTemp320 = 2.0f * fRec279[1];
			fRec278[0] = fSlow245 * (fRec279[2] + (fRec279[0] - fTemp320)) - fSlow241 * (fSlow239 * fRec278[2] + fSlow234 * fRec278[1]);
			fRec277[0] = fSlow246 * (fRec278[2] + (fRec278[0] - 2.0f * fRec278[1])) - fSlow238 * (fSlow236 * fRec277[2] + fSlow234 * fRec277[1]);
			float fTemp321 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow247 * (fRec277[2] + (fRec277[0] - 2.0f * fRec277[1])))));
			int iTemp322 = (fTemp321 > fSlow248) + (fTemp321 > fSlow231);
			float fTemp323 = fTemp321 - fSlow230;
			float fTemp324 = std::max<float>(0.0f, ((iTemp322 == 0) ? 0.0f : ((iTemp322 == 1) ? fSlow249 * mydsp_faustpower2_f(fSlow229 + fTemp323) : fTemp323)));
			float fTemp325 = ((-(fSlow250 * fTemp324) > fRec276[1]) ? fSlow256 : fSlow253);
			fRec276[0] = fRec276[1] * fTemp325 - fSlow250 * fTemp324 * (1.0f - fTemp325);
			fRec287[0] = fSlow214 * (fRec243[2] + fRec243[0] + fTemp297) - fSlow211 * (fSlow209 * fRec287[2] + fSlow204 * fRec287[1]);
			fRec286[0] = fSlow211 * (fRec287[2] + fRec287[0] + 2.0f * fRec287[1]) - fSlow208 * (fSlow206 * fRec286[2] + fSlow204 * fRec286[1]);
			fRec285[0] = fSlow208 * (fRec286[2] + fRec286[0] + 2.0f * fRec286[1]) - fSlow244 * (fSlow242 * fRec285[2] + fSlow234 * fRec285[1]);
			float fTemp326 = 2.0f * fRec285[1];
			fRec284[0] = fSlow245 * (fRec285[2] + (fRec285[0] - fTemp326)) - fSlow241 * (fSlow239 * fRec284[2] + fSlow234 * fRec284[1]);
			fRec283[0] = fSlow246 * (fRec284[2] + (fRec284[0] - 2.0f * fRec284[1])) - fSlow238 * (fSlow236 * fRec283[2] + fSlow234 * fRec283[1]);
			float fTemp327 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow247 * (fRec283[2] + (fRec283[0] - 2.0f * fRec283[1])))));
			int iTemp328 = (fTemp327 > fSlow248) + (fTemp327 > fSlow231);
			float fTemp329 = fTemp327 - fSlow230;
			float fTemp330 = std::max<float>(0.0f, ((iTemp328 == 0) ? 0.0f : ((iTemp328 == 1) ? fSlow249 * mydsp_faustpower2_f(fSlow229 + fTemp329) : fTemp329)));
			float fTemp331 = ((-(fSlow250 * fTemp330) > fRec282[1]) ? fSlow256 : fSlow253);
			fRec282[0] = fRec282[1] * fTemp331 - fSlow250 * fTemp330 * (1.0f - fTemp331);
			float fTemp332 = std::min<float>(fRec282[0], fRec276[0]);
			float fTemp333 = fRec276[0] + fSlow257 * (fTemp332 - fRec276[0]);
			fVbargraph13 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp333)));
			float fTemp334 = 0.008333334f * fTemp333;
			float fTemp335 = std::pow(1e+01f, fTemp334);
			float fTemp336 = mydsp_faustpower2_f(fTemp335) + -1.0f;
			float fTemp337 = std::sqrt(fTemp335);
			float fTemp338 = fSlow202 / fTemp337;
			float fTemp339 = fSlow202 * ((fTemp338 + 0.5f) / fTemp337) + 1.0f;
			float fTemp340 = fSlow202 * ((fTemp338 + 1.4144272f) / fTemp337) + 1.0f;
			float fTemp341 = fSlow202 * ((fTemp338 + 2.0f) / fTemp337) + 1.0f;
			float fTemp342 = std::pow(1e+01f, -fTemp334);
			float fTemp343 = mydsp_faustpower2_f(fTemp342) + -1.0f;
			float fTemp344 = std::sqrt(fTemp342);
			float fTemp345 = fSlow232 / fTemp344;
			float fTemp346 = fSlow232 * ((fTemp345 + 0.5f) / fTemp344) + 1.0f;
			float fTemp347 = fSlow232 * ((fTemp345 + 1.4144272f) / fTemp344) + 1.0f;
			float fTemp348 = fSlow232 * ((fTemp345 + 2.0f) / fTemp344) + 1.0f;
			fRec323[0] = fSlow244 * (fRec279[2] + fRec279[0] + fTemp320) - fSlow241 * (fSlow239 * fRec323[2] + fSlow234 * fRec323[1]);
			fRec322[0] = fSlow241 * (fRec323[2] + fRec323[0] + 2.0f * fRec323[1]) - fSlow238 * (fSlow236 * fRec322[2] + fSlow234 * fRec322[1]);
			fRec321[0] = fSlow238 * (fRec322[2] + fRec322[0] + 2.0f * fRec322[1]) - fSlow274 * (fSlow272 * fRec321[2] + fSlow264 * fRec321[1]);
			float fTemp349 = 2.0f * fRec321[1];
			fRec320[0] = fSlow275 * (fRec321[2] + (fRec321[0] - fTemp349)) - fSlow271 * (fSlow269 * fRec320[2] + fSlow264 * fRec320[1]);
			fRec319[0] = fSlow276 * (fRec320[2] + (fRec320[0] - 2.0f * fRec320[1])) - fSlow268 * (fSlow266 * fRec319[2] + fSlow264 * fRec319[1]);
			float fTemp350 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow277 * (fRec319[2] + (fRec319[0] - 2.0f * fRec319[1])))));
			int iTemp351 = (fTemp350 > fSlow278) + (fTemp350 > fSlow261);
			float fTemp352 = fTemp350 - fSlow260;
			float fTemp353 = std::max<float>(0.0f, ((iTemp351 == 0) ? 0.0f : ((iTemp351 == 1) ? fSlow279 * mydsp_faustpower2_f(fSlow259 + fTemp352) : fTemp352)));
			float fTemp354 = ((-(fSlow280 * fTemp353) > fRec318[1]) ? fSlow286 : fSlow283);
			fRec318[0] = fRec318[1] * fTemp354 - fSlow280 * fTemp353 * (1.0f - fTemp354);
			fRec329[0] = fSlow244 * (fRec285[2] + fRec285[0] + fTemp326) - fSlow241 * (fSlow239 * fRec329[2] + fSlow234 * fRec329[1]);
			fRec328[0] = fSlow241 * (fRec329[2] + fRec329[0] + 2.0f * fRec329[1]) - fSlow238 * (fSlow236 * fRec328[2] + fSlow234 * fRec328[1]);
			fRec327[0] = fSlow238 * (fRec328[2] + fRec328[0] + 2.0f * fRec328[1]) - fSlow274 * (fSlow272 * fRec327[2] + fSlow264 * fRec327[1]);
			float fTemp355 = 2.0f * fRec327[1];
			fRec326[0] = fSlow275 * (fRec327[2] + (fRec327[0] - fTemp355)) - fSlow271 * (fSlow269 * fRec326[2] + fSlow264 * fRec326[1]);
			fRec325[0] = fSlow276 * (fRec326[2] + (fRec326[0] - 2.0f * fRec326[1])) - fSlow268 * (fSlow266 * fRec325[2] + fSlow264 * fRec325[1]);
			float fTemp356 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow277 * (fRec325[2] + (fRec325[0] - 2.0f * fRec325[1])))));
			int iTemp357 = (fTemp356 > fSlow278) + (fTemp356 > fSlow261);
			float fTemp358 = fTemp356 - fSlow260;
			float fTemp359 = std::max<float>(0.0f, ((iTemp357 == 0) ? 0.0f : ((iTemp357 == 1) ? fSlow279 * mydsp_faustpower2_f(fSlow259 + fTemp358) : fTemp358)));
			float fTemp360 = ((-(fSlow280 * fTemp359) > fRec324[1]) ? fSlow286 : fSlow283);
			fRec324[0] = fRec324[1] * fTemp360 - fSlow280 * fTemp359 * (1.0f - fTemp360);
			float fTemp361 = std::min<float>(fRec324[0], fRec318[0]);
			float fTemp362 = fRec318[0] + fSlow287 * (fTemp361 - fRec318[0]);
			fVbargraph14 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp362)));
			float fTemp363 = 0.008333334f * fTemp362;
			float fTemp364 = std::pow(1e+01f, fTemp363);
			float fTemp365 = mydsp_faustpower2_f(fTemp364) + -1.0f;
			float fTemp366 = std::sqrt(fTemp364);
			float fTemp367 = fSlow232 / fTemp366;
			float fTemp368 = fSlow232 * ((fTemp367 + 0.5f) / fTemp366) + 1.0f;
			float fTemp369 = fSlow232 * ((fTemp367 + 1.4144272f) / fTemp366) + 1.0f;
			float fTemp370 = fSlow232 * ((fTemp367 + 2.0f) / fTemp366) + 1.0f;
			float fTemp371 = std::pow(1e+01f, -fTemp363);
			float fTemp372 = mydsp_faustpower2_f(fTemp371) + -1.0f;
			float fTemp373 = std::sqrt(fTemp371);
			float fTemp374 = fSlow262 / fTemp373;
			float fTemp375 = fSlow262 * ((fTemp374 + 0.5f) / fTemp373) + 1.0f;
			float fTemp376 = fSlow262 * ((fTemp374 + 1.4144272f) / fTemp373) + 1.0f;
			float fTemp377 = fSlow262 * ((fTemp374 + 2.0f) / fTemp373) + 1.0f;
			fRec362[0] = fSlow274 * (fRec321[2] + fRec321[0] + fTemp349) - fSlow271 * (fSlow269 * fRec362[2] + fSlow264 * fRec362[1]);
			fRec361[0] = fSlow271 * (fRec362[2] + fRec362[0] + 2.0f * fRec362[1]) - fSlow268 * (fSlow266 * fRec361[2] + fSlow264 * fRec361[1]);
			float fTemp378 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow268 * (fRec361[2] + fRec361[0] + 2.0f * fRec361[1]))));
			int iTemp379 = (fTemp378 > fSlow290) + (fTemp378 > fSlow289);
			float fTemp380 = fTemp378 - fSlow107;
			float fTemp381 = std::max<float>(0.0f, ((iTemp379 == 0) ? 0.0f : ((iTemp379 == 1) ? fSlow291 * mydsp_faustpower2_f(fSlow288 + fTemp380) : fTemp380)));
			float fTemp382 = ((-(fSlow128 * fTemp381) > fRec360[1]) ? fSlow295 : fSlow293);
			fRec360[0] = fRec360[1] * fTemp382 - fSlow128 * fTemp381 * (1.0f - fTemp382);
			fRec365[0] = fSlow274 * (fRec327[2] + fRec327[0] + fTemp355) - fSlow271 * (fSlow269 * fRec365[2] + fSlow264 * fRec365[1]);
			fRec364[0] = fSlow271 * (fRec365[2] + fRec365[0] + 2.0f * fRec365[1]) - fSlow268 * (fSlow266 * fRec364[2] + fSlow264 * fRec364[1]);
			float fTemp383 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::fabs(fSlow268 * (fRec364[2] + fRec364[0] + 2.0f * fRec364[1]))));
			int iTemp384 = (fTemp383 > fSlow290) + (fTemp383 > fSlow289);
			float fTemp385 = fTemp383 - fSlow107;
			float fTemp386 = std::max<float>(0.0f, ((iTemp384 == 0) ? 0.0f : ((iTemp384 == 1) ? fSlow291 * mydsp_faustpower2_f(fSlow288 + fTemp385) : fTemp385)));
			float fTemp387 = ((-(fSlow128 * fTemp386) > fRec363[1]) ? fSlow295 : fSlow293);
			fRec363[0] = fRec363[1] * fTemp387 - fSlow128 * fTemp386 * (1.0f - fTemp387);
			float fTemp388 = std::min<float>(fRec363[0], fRec360[0]);
			float fTemp389 = fRec360[0] + fSlow136 * (fTemp388 - fRec360[0]);
			fVbargraph15 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp389)));
			float fTemp390 = std::pow(1e+01f, 0.008333334f * fTemp389);
			float fTemp391 = mydsp_faustpower2_f(fTemp390) + -1.0f;
			float fTemp392 = std::sqrt(fTemp390);
			float fTemp393 = fSlow262 / fTemp392;
			float fTemp394 = fSlow262 * ((fTemp393 + 0.5f) / fTemp392) + 1.0f;
			float fTemp395 = fSlow262 * ((fTemp393 + 1.4144272f) / fTemp392) + 1.0f;
			float fTemp396 = fSlow262 * ((fTemp393 + 2.0f) / fTemp392) + 1.0f;
			float fTemp397 = fRec376[1] + fSlow262 * ((fTemp181 - fRec377[1]) / fTemp392);
			float fTemp398 = fTemp397 / fTemp396;
			fRec376[0] = 2.0f * fTemp398 - fRec376[1];
			float fTemp399 = fRec377[1] + fSlow262 * (fTemp397 / (fTemp392 * fTemp396));
			fRec377[0] = 2.0f * fTemp399 - fRec377[1];
			float fRec378 = fTemp181;
			float fRec379 = fTemp398;
			float fRec380 = fTemp399;
			float fTemp400 = fTemp390 + -1.0f;
			float fTemp401 = fRec378 + 2.0f * fRec379 * fTemp400 + fRec380 * fTemp391;
			float fTemp402 = fRec371[1] + fSlow262 * ((fTemp401 - fRec372[1]) / fTemp392);
			float fTemp403 = fTemp402 / fTemp395;
			fRec371[0] = 2.0f * fTemp403 - fRec371[1];
			float fTemp404 = fRec372[1] + fSlow262 * (fTemp402 / (fTemp392 * fTemp395));
			fRec372[0] = 2.0f * fTemp404 - fRec372[1];
			float fRec373 = fTemp401;
			float fRec374 = fTemp403;
			float fRec375 = fTemp404;
			float fTemp405 = fRec373 + 1.4144272f * fRec374 * fTemp400 + fRec375 * fTemp391;
			float fTemp406 = fRec366[1] + fSlow262 * ((fTemp405 - fRec367[1]) / fTemp392);
			float fTemp407 = fTemp406 / fTemp394;
			fRec366[0] = 2.0f * fTemp407 - fRec366[1];
			float fTemp408 = fRec367[1] + fSlow262 * (fTemp406 / (fTemp392 * fTemp394));
			fRec367[0] = 2.0f * fTemp408 - fRec367[1];
			float fRec368 = fTemp405;
			float fRec369 = fTemp407;
			float fRec370 = fTemp408;
			float fTemp409 = fRec368 + 0.5f * fRec369 * fTemp400 + fRec370 * fTemp391;
			float fTemp410 = fRec355[1] + fSlow262 * ((fTemp409 - fRec356[1]) / fTemp373);
			float fTemp411 = fTemp410 / fTemp377;
			fRec355[0] = 2.0f * fTemp411 - fRec355[1];
			float fTemp412 = fRec356[1] + fSlow262 * (fTemp410 / (fTemp373 * fTemp377));
			fRec356[0] = 2.0f * fTemp412 - fRec356[1];
			float fRec357 = fTemp409;
			float fRec358 = fTemp411;
			float fRec359 = fTemp412;
			float fTemp413 = fTemp371 + -1.0f;
			float fTemp414 = fRec357 + 2.0f * fRec358 * fTemp413 + fRec359 * fTemp372;
			float fTemp415 = fRec350[1] + fSlow262 * ((fTemp414 - fRec351[1]) / fTemp373);
			float fTemp416 = fTemp415 / fTemp376;
			fRec350[0] = 2.0f * fTemp416 - fRec350[1];
			float fTemp417 = fRec351[1] + fSlow262 * (fTemp415 / (fTemp373 * fTemp376));
			fRec351[0] = 2.0f * fTemp417 - fRec351[1];
			float fRec352 = fTemp414;
			float fRec353 = fTemp416;
			float fRec354 = fTemp417;
			float fTemp418 = fRec352 + 1.4144272f * fRec353 * fTemp413 + fRec354 * fTemp372;
			float fTemp419 = fRec345[1] + fSlow262 * ((fTemp418 - fRec346[1]) / fTemp373);
			float fTemp420 = fTemp419 / fTemp375;
			fRec345[0] = 2.0f * fTemp420 - fRec345[1];
			float fTemp421 = fRec346[1] + fSlow262 * (fTemp419 / (fTemp373 * fTemp375));
			fRec346[0] = 2.0f * fTemp421 - fRec346[1];
			float fRec347 = fTemp418;
			float fRec348 = fTemp420;
			float fRec349 = fTemp421;
			float fTemp422 = fRec347 + 0.5f * fRec348 * fTemp413 + fRec349 * fTemp372;
			float fTemp423 = fRec340[1] + fSlow232 * ((fTemp422 - fRec341[1]) / fTemp366);
			float fTemp424 = fTemp423 / fTemp370;
			fRec340[0] = 2.0f * fTemp424 - fRec340[1];
			float fTemp425 = fRec341[1] + fSlow232 * (fTemp423 / (fTemp366 * fTemp370));
			fRec341[0] = 2.0f * fTemp425 - fRec341[1];
			float fRec342 = fTemp422;
			float fRec343 = fTemp424;
			float fRec344 = fTemp425;
			float fTemp426 = fTemp364 + -1.0f;
			float fTemp427 = fRec342 + 2.0f * fRec343 * fTemp426 + fRec344 * fTemp365;
			float fTemp428 = fRec335[1] + fSlow232 * ((fTemp427 - fRec336[1]) / fTemp366);
			float fTemp429 = fTemp428 / fTemp369;
			fRec335[0] = 2.0f * fTemp429 - fRec335[1];
			float fTemp430 = fRec336[1] + fSlow232 * (fTemp428 / (fTemp366 * fTemp369));
			fRec336[0] = 2.0f * fTemp430 - fRec336[1];
			float fRec337 = fTemp427;
			float fRec338 = fTemp429;
			float fRec339 = fTemp430;
			float fTemp431 = fRec337 + 1.4144272f * fRec338 * fTemp426 + fRec339 * fTemp365;
			float fTemp432 = fRec330[1] + fSlow232 * ((fTemp431 - fRec331[1]) / fTemp366);
			float fTemp433 = fTemp432 / fTemp368;
			fRec330[0] = 2.0f * fTemp433 - fRec330[1];
			float fTemp434 = fRec331[1] + fSlow232 * (fTemp432 / (fTemp366 * fTemp368));
			fRec331[0] = 2.0f * fTemp434 - fRec331[1];
			float fRec332 = fTemp431;
			float fRec333 = fTemp433;
			float fRec334 = fTemp434;
			float fTemp435 = fRec332 + 0.5f * fRec333 * fTemp426 + fRec334 * fTemp365;
			float fTemp436 = fRec313[1] + fSlow232 * ((fTemp435 - fRec314[1]) / fTemp344);
			float fTemp437 = fTemp436 / fTemp348;
			fRec313[0] = 2.0f * fTemp437 - fRec313[1];
			float fTemp438 = fRec314[1] + fSlow232 * (fTemp436 / (fTemp344 * fTemp348));
			fRec314[0] = 2.0f * fTemp438 - fRec314[1];
			float fRec315 = fTemp435;
			float fRec316 = fTemp437;
			float fRec317 = fTemp438;
			float fTemp439 = fTemp342 + -1.0f;
			float fTemp440 = fRec315 + 2.0f * fRec316 * fTemp439 + fRec317 * fTemp343;
			float fTemp441 = fRec308[1] + fSlow232 * ((fTemp440 - fRec309[1]) / fTemp344);
			float fTemp442 = fTemp441 / fTemp347;
			fRec308[0] = 2.0f * fTemp442 - fRec308[1];
			float fTemp443 = fRec309[1] + fSlow232 * (fTemp441 / (fTemp344 * fTemp347));
			fRec309[0] = 2.0f * fTemp443 - fRec309[1];
			float fRec310 = fTemp440;
			float fRec311 = fTemp442;
			float fRec312 = fTemp443;
			float fTemp444 = fRec310 + 1.4144272f * fRec311 * fTemp439 + fRec312 * fTemp343;
			float fTemp445 = fRec303[1] + fSlow232 * ((fTemp444 - fRec304[1]) / fTemp344);
			float fTemp446 = fTemp445 / fTemp346;
			fRec303[0] = 2.0f * fTemp446 - fRec303[1];
			float fTemp447 = fRec304[1] + fSlow232 * (fTemp445 / (fTemp344 * fTemp346));
			fRec304[0] = 2.0f * fTemp447 - fRec304[1];
			float fRec305 = fTemp444;
			float fRec306 = fTemp446;
			float fRec307 = fTemp447;
			float fTemp448 = fRec305 + 0.5f * fRec306 * fTemp439 + fRec307 * fTemp343;
			float fTemp449 = fRec298[1] + fSlow202 * ((fTemp448 - fRec299[1]) / fTemp337);
			float fTemp450 = fTemp449 / fTemp341;
			fRec298[0] = 2.0f * fTemp450 - fRec298[1];
			float fTemp451 = fRec299[1] + fSlow202 * (fTemp449 / (fTemp337 * fTemp341));
			fRec299[0] = 2.0f * fTemp451 - fRec299[1];
			float fRec300 = fTemp448;
			float fRec301 = fTemp450;
			float fRec302 = fTemp451;
			float fTemp452 = fTemp335 + -1.0f;
			float fTemp453 = fRec300 + 2.0f * fRec301 * fTemp452 + fRec302 * fTemp336;
			float fTemp454 = fRec293[1] + fSlow202 * ((fTemp453 - fRec294[1]) / fTemp337);
			float fTemp455 = fTemp454 / fTemp340;
			fRec293[0] = 2.0f * fTemp455 - fRec293[1];
			float fTemp456 = fRec294[1] + fSlow202 * (fTemp454 / (fTemp337 * fTemp340));
			fRec294[0] = 2.0f * fTemp456 - fRec294[1];
			float fRec295 = fTemp453;
			float fRec296 = fTemp455;
			float fRec297 = fTemp456;
			float fTemp457 = fRec295 + 1.4144272f * fRec296 * fTemp452 + fRec297 * fTemp336;
			float fTemp458 = fRec288[1] + fSlow202 * ((fTemp457 - fRec289[1]) / fTemp337);
			float fTemp459 = fTemp458 / fTemp339;
			fRec288[0] = 2.0f * fTemp459 - fRec288[1];
			float fTemp460 = fRec289[1] + fSlow202 * (fTemp458 / (fTemp337 * fTemp339));
			fRec289[0] = 2.0f * fTemp460 - fRec289[1];
			float fRec290 = fTemp457;
			float fRec291 = fTemp459;
			float fRec292 = fTemp460;
			float fTemp461 = fRec290 + 0.5f * fRec291 * fTemp452 + fRec292 * fTemp336;
			float fTemp462 = fRec271[1] + fSlow202 * ((fTemp461 - fRec272[1]) / fTemp315);
			float fTemp463 = fTemp462 / fTemp319;
			fRec271[0] = 2.0f * fTemp463 - fRec271[1];
			float fTemp464 = fRec272[1] + fSlow202 * (fTemp462 / (fTemp315 * fTemp319));
			fRec272[0] = 2.0f * fTemp464 - fRec272[1];
			float fRec273 = fTemp461;
			float fRec274 = fTemp463;
			float fRec275 = fTemp464;
			float fTemp465 = fTemp313 + -1.0f;
			float fTemp466 = fRec273 + 2.0f * fRec274 * fTemp465 + fRec275 * fTemp314;
			float fTemp467 = fRec266[1] + fSlow202 * ((fTemp466 - fRec267[1]) / fTemp315);
			float fTemp468 = fTemp467 / fTemp318;
			fRec266[0] = 2.0f * fTemp468 - fRec266[1];
			float fTemp469 = fRec267[1] + fSlow202 * (fTemp467 / (fTemp315 * fTemp318));
			fRec267[0] = 2.0f * fTemp469 - fRec267[1];
			float fRec268 = fTemp466;
			float fRec269 = fTemp468;
			float fRec270 = fTemp469;
			float fTemp470 = fRec268 + 1.4144272f * fRec269 * fTemp465 + fRec270 * fTemp314;
			float fTemp471 = fRec261[1] + fSlow202 * ((fTemp470 - fRec262[1]) / fTemp315);
			float fTemp472 = fTemp471 / fTemp317;
			fRec261[0] = 2.0f * fTemp472 - fRec261[1];
			float fTemp473 = fRec262[1] + fSlow202 * (fTemp471 / (fTemp315 * fTemp317));
			fRec262[0] = 2.0f * fTemp473 - fRec262[1];
			float fRec263 = fTemp470;
			float fRec264 = fTemp472;
			float fRec265 = fTemp473;
			float fTemp474 = fRec263 + 0.5f * fRec264 * fTemp465 + fRec265 * fTemp314;
			float fTemp475 = fRec256[1] + fSlow172 * ((fTemp474 - fRec257[1]) / fTemp308);
			float fTemp476 = fTemp475 / fTemp312;
			fRec256[0] = 2.0f * fTemp476 - fRec256[1];
			float fTemp477 = fRec257[1] + fSlow172 * (fTemp475 / (fTemp308 * fTemp312));
			fRec257[0] = 2.0f * fTemp477 - fRec257[1];
			float fRec258 = fTemp474;
			float fRec259 = fTemp476;
			float fRec260 = fTemp477;
			float fTemp478 = fTemp306 + -1.0f;
			float fTemp479 = fRec258 + 2.0f * fRec259 * fTemp478 + fRec260 * fTemp307;
			float fTemp480 = fRec251[1] + fSlow172 * ((fTemp479 - fRec252[1]) / fTemp308);
			float fTemp481 = fTemp480 / fTemp311;
			fRec251[0] = 2.0f * fTemp481 - fRec251[1];
			float fTemp482 = fRec252[1] + fSlow172 * (fTemp480 / (fTemp308 * fTemp311));
			fRec252[0] = 2.0f * fTemp482 - fRec252[1];
			float fRec253 = fTemp479;
			float fRec254 = fTemp481;
			float fRec255 = fTemp482;
			float fTemp483 = fRec253 + 1.4144272f * fRec254 * fTemp478 + fRec255 * fTemp307;
			float fTemp484 = fRec246[1] + fSlow172 * ((fTemp483 - fRec247[1]) / fTemp308);
			float fTemp485 = fTemp484 / fTemp310;
			fRec246[0] = 2.0f * fTemp485 - fRec246[1];
			float fTemp486 = fRec247[1] + fSlow172 * (fTemp484 / (fTemp308 * fTemp310));
			fRec247[0] = 2.0f * fTemp486 - fRec247[1];
			float fRec248 = fTemp483;
			float fRec249 = fTemp485;
			float fRec250 = fTemp486;
			float fTemp487 = fRec248 + 0.5f * fRec249 * fTemp478 + fRec250 * fTemp307;
			float fTemp488 = fRec229[1] + fSlow172 * ((fTemp487 - fRec230[1]) / fTemp286);
			float fTemp489 = fTemp488 / fTemp290;
			fRec229[0] = 2.0f * fTemp489 - fRec229[1];
			float fTemp490 = fRec230[1] + fSlow172 * (fTemp488 / (fTemp286 * fTemp290));
			fRec230[0] = 2.0f * fTemp490 - fRec230[1];
			float fRec231 = fTemp487;
			float fRec232 = fTemp489;
			float fRec233 = fTemp490;
			float fTemp491 = fTemp284 + -1.0f;
			float fTemp492 = fRec231 + 2.0f * fRec232 * fTemp491 + fRec233 * fTemp285;
			float fTemp493 = fRec224[1] + fSlow172 * ((fTemp492 - fRec225[1]) / fTemp286);
			float fTemp494 = fTemp493 / fTemp289;
			fRec224[0] = 2.0f * fTemp494 - fRec224[1];
			float fTemp495 = fRec225[1] + fSlow172 * (fTemp493 / (fTemp286 * fTemp289));
			fRec225[0] = 2.0f * fTemp495 - fRec225[1];
			float fRec226 = fTemp492;
			float fRec227 = fTemp494;
			float fRec228 = fTemp495;
			float fTemp496 = fRec226 + 1.4144272f * fRec227 * fTemp491 + fRec228 * fTemp285;
			float fTemp497 = fRec219[1] + fSlow172 * ((fTemp496 - fRec220[1]) / fTemp286);
			float fTemp498 = fTemp497 / fTemp288;
			fRec219[0] = 2.0f * fTemp498 - fRec219[1];
			float fTemp499 = fRec220[1] + fSlow172 * (fTemp497 / (fTemp286 * fTemp288));
			fRec220[0] = 2.0f * fTemp499 - fRec220[1];
			float fRec221 = fTemp496;
			float fRec222 = fTemp498;
			float fRec223 = fTemp499;
			float fTemp500 = fRec221 + 0.5f * fRec222 * fTemp491 + fRec223 * fTemp285;
			float fTemp501 = fRec214[1] + fSlow142 * ((fTemp500 - fRec215[1]) / fTemp279);
			float fTemp502 = fTemp501 / fTemp283;
			fRec214[0] = 2.0f * fTemp502 - fRec214[1];
			float fTemp503 = fRec215[1] + fSlow142 * (fTemp501 / (fTemp279 * fTemp283));
			fRec215[0] = 2.0f * fTemp503 - fRec215[1];
			float fRec216 = fTemp500;
			float fRec217 = fTemp502;
			float fRec218 = fTemp503;
			float fTemp504 = fTemp277 + -1.0f;
			float fTemp505 = fRec216 + 2.0f * fRec217 * fTemp504 + fRec218 * fTemp278;
			float fTemp506 = fRec209[1] + fSlow142 * ((fTemp505 - fRec210[1]) / fTemp279);
			float fTemp507 = fTemp506 / fTemp282;
			fRec209[0] = 2.0f * fTemp507 - fRec209[1];
			float fTemp508 = fRec210[1] + fSlow142 * (fTemp506 / (fTemp279 * fTemp282));
			fRec210[0] = 2.0f * fTemp508 - fRec210[1];
			float fRec211 = fTemp505;
			float fRec212 = fTemp507;
			float fRec213 = fTemp508;
			float fTemp509 = fRec211 + 1.4144272f * fRec212 * fTemp504 + fRec213 * fTemp278;
			float fTemp510 = fRec204[1] + fSlow142 * ((fTemp509 - fRec205[1]) / fTemp279);
			float fTemp511 = fTemp510 / fTemp281;
			fRec204[0] = 2.0f * fTemp511 - fRec204[1];
			float fTemp512 = fRec205[1] + fSlow142 * (fTemp510 / (fTemp279 * fTemp281));
			fRec205[0] = 2.0f * fTemp512 - fRec205[1];
			float fRec206 = fTemp509;
			float fRec207 = fTemp511;
			float fRec208 = fTemp512;
			float fTemp513 = fRec206 + 0.5f * fRec207 * fTemp504 + fRec208 * fTemp278;
			float fTemp514 = fRec187[1] + fSlow142 * ((fTemp513 - fRec188[1]) / fTemp257);
			float fTemp515 = fTemp514 / fTemp261;
			fRec187[0] = 2.0f * fTemp515 - fRec187[1];
			float fTemp516 = fRec188[1] + fSlow142 * (fTemp514 / (fTemp257 * fTemp261));
			fRec188[0] = 2.0f * fTemp516 - fRec188[1];
			float fRec189 = fTemp513;
			float fRec190 = fTemp515;
			float fRec191 = fTemp516;
			float fTemp517 = fTemp255 + -1.0f;
			float fTemp518 = fRec189 + 2.0f * fRec190 * fTemp517 + fRec191 * fTemp256;
			float fTemp519 = fRec182[1] + fSlow142 * ((fTemp518 - fRec183[1]) / fTemp257);
			float fTemp520 = fTemp519 / fTemp260;
			fRec182[0] = 2.0f * fTemp520 - fRec182[1];
			float fTemp521 = fRec183[1] + fSlow142 * (fTemp519 / (fTemp257 * fTemp260));
			fRec183[0] = 2.0f * fTemp521 - fRec183[1];
			float fRec184 = fTemp518;
			float fRec185 = fTemp520;
			float fRec186 = fTemp521;
			float fTemp522 = fRec184 + 1.4144272f * fRec185 * fTemp517 + fRec186 * fTemp256;
			float fTemp523 = fRec177[1] + fSlow142 * ((fTemp522 - fRec178[1]) / fTemp257);
			float fTemp524 = fTemp523 / fTemp259;
			fRec177[0] = 2.0f * fTemp524 - fRec177[1];
			float fTemp525 = fRec178[1] + fSlow142 * (fTemp523 / (fTemp257 * fTemp259));
			fRec178[0] = 2.0f * fTemp525 - fRec178[1];
			float fRec179 = fTemp522;
			float fRec180 = fTemp524;
			float fRec181 = fTemp525;
			float fTemp526 = fRec179 + 0.5f * fRec180 * fTemp517 + fRec181 * fTemp256;
			float fTemp527 = fRec172[1] + fSlow110 * ((fTemp526 - fRec173[1]) / fTemp250);
			float fTemp528 = fTemp527 / fTemp254;
			fRec172[0] = 2.0f * fTemp528 - fRec172[1];
			float fTemp529 = fRec173[1] + fSlow110 * (fTemp527 / (fTemp250 * fTemp254));
			fRec173[0] = 2.0f * fTemp529 - fRec173[1];
			float fRec174 = fTemp526;
			float fRec175 = fTemp528;
			float fRec176 = fTemp529;
			float fTemp530 = fTemp248 + -1.0f;
			float fTemp531 = fRec174 + 2.0f * fRec175 * fTemp530 + fRec176 * fTemp249;
			float fTemp532 = fRec167[1] + fSlow110 * ((fTemp531 - fRec168[1]) / fTemp250);
			float fTemp533 = fTemp532 / fTemp253;
			fRec167[0] = 2.0f * fTemp533 - fRec167[1];
			float fTemp534 = fRec168[1] + fSlow110 * (fTemp532 / (fTemp250 * fTemp253));
			fRec168[0] = 2.0f * fTemp534 - fRec168[1];
			float fRec169 = fTemp531;
			float fRec170 = fTemp533;
			float fRec171 = fTemp534;
			float fTemp535 = fRec169 + 1.4144272f * fRec170 * fTemp530 + fRec171 * fTemp249;
			float fTemp536 = fRec162[1] + fSlow110 * ((fTemp535 - fRec163[1]) / fTemp250);
			float fTemp537 = fTemp536 / fTemp252;
			fRec162[0] = 2.0f * fTemp537 - fRec162[1];
			float fTemp538 = fRec163[1] + fSlow110 * (fTemp536 / (fTemp250 * fTemp252));
			fRec163[0] = 2.0f * fTemp538 - fRec163[1];
			float fRec164 = fTemp535;
			float fRec165 = fTemp537;
			float fRec166 = fTemp538;
			float fTemp539 = fRec164 + 0.5f * fRec165 * fTemp530 + fRec166 * fTemp249;
			float fTemp540 = fRec145[1] + fSlow110 * ((fTemp539 - fRec146[1]) / fTemp228);
			float fTemp541 = fTemp540 / fTemp232;
			fRec145[0] = 2.0f * fTemp541 - fRec145[1];
			float fTemp542 = fRec146[1] + fSlow110 * (fTemp540 / (fTemp228 * fTemp232));
			fRec146[0] = 2.0f * fTemp542 - fRec146[1];
			float fRec147 = fTemp539;
			float fRec148 = fTemp541;
			float fRec149 = fTemp542;
			float fTemp543 = fTemp226 + -1.0f;
			float fTemp544 = fRec147 + 2.0f * fRec148 * fTemp543 + fRec149 * fTemp227;
			float fTemp545 = fRec140[1] + fSlow110 * ((fTemp544 - fRec141[1]) / fTemp228);
			float fTemp546 = fTemp545 / fTemp231;
			fRec140[0] = 2.0f * fTemp546 - fRec140[1];
			float fTemp547 = fRec141[1] + fSlow110 * (fTemp545 / (fTemp228 * fTemp231));
			fRec141[0] = 2.0f * fTemp547 - fRec141[1];
			float fRec142 = fTemp544;
			float fRec143 = fTemp546;
			float fRec144 = fTemp547;
			float fTemp548 = fRec142 + 1.4144272f * fRec143 * fTemp543 + fRec144 * fTemp227;
			float fTemp549 = fRec135[1] + fSlow110 * ((fTemp548 - fRec136[1]) / fTemp228);
			float fTemp550 = fTemp549 / fTemp230;
			fRec135[0] = 2.0f * fTemp550 - fRec135[1];
			float fTemp551 = fRec136[1] + fSlow110 * (fTemp549 / (fTemp228 * fTemp230));
			fRec136[0] = 2.0f * fTemp551 - fRec136[1];
			float fRec137 = fTemp548;
			float fRec138 = fTemp550;
			float fRec139 = fTemp551;
			float fTemp552 = fRec137 + 0.5f * fRec138 * fTemp543 + fRec139 * fTemp227;
			float fTemp553 = fRec130[1] + fSlow9 * ((fTemp552 - fRec131[1]) / fTemp221);
			float fTemp554 = fTemp553 / fTemp225;
			fRec130[0] = 2.0f * fTemp554 - fRec130[1];
			float fTemp555 = fRec131[1] + fSlow9 * (fTemp553 / (fTemp221 * fTemp225));
			fRec131[0] = 2.0f * fTemp555 - fRec131[1];
			float fRec132 = fTemp552;
			float fRec133 = fTemp554;
			float fRec134 = fTemp555;
			float fTemp556 = fTemp219 + -1.0f;
			float fTemp557 = fRec132 + 2.0f * fRec133 * fTemp556 + fRec134 * fTemp220;
			float fTemp558 = fRec125[1] + fSlow9 * ((fTemp557 - fRec126[1]) / fTemp221);
			float fTemp559 = fTemp558 / fTemp224;
			fRec125[0] = 2.0f * fTemp559 - fRec125[1];
			float fTemp560 = fRec126[1] + fSlow9 * (fTemp558 / (fTemp221 * fTemp224));
			fRec126[0] = 2.0f * fTemp560 - fRec126[1];
			float fRec127 = fTemp557;
			float fRec128 = fTemp559;
			float fRec129 = fTemp560;
			float fTemp561 = fRec127 + 1.4144272f * fRec128 * fTemp556 + fRec129 * fTemp220;
			float fTemp562 = fRec120[1] + fSlow9 * ((fTemp561 - fRec121[1]) / fTemp221);
			float fTemp563 = fTemp562 / fTemp223;
			fRec120[0] = 2.0f * fTemp563 - fRec120[1];
			float fTemp564 = fRec121[1] + fSlow9 * (fTemp562 / (fTemp221 * fTemp223));
			fRec121[0] = 2.0f * fTemp564 - fRec121[1];
			float fRec122 = fTemp561;
			float fRec123 = fTemp563;
			float fRec124 = fTemp564;
			float fTemp565 = fRec122 + 0.5f * fRec123 * fTemp556 + fRec124 * fTemp220;
			float fTemp566 = fRec103[1] + fSlow9 * fTemp199 * (fTemp565 - fRec104[1]);
			float fTemp567 = fTemp566 / fTemp203;
			fRec103[0] = 2.0f * fTemp567 - fRec103[1];
			float fTemp568 = fRec104[1] + fSlow9 * (fTemp199 * fTemp566 / fTemp203);
			fRec104[0] = 2.0f * fTemp568 - fRec104[1];
			float fRec105 = fTemp565;
			float fRec106 = fTemp567;
			float fRec107 = fTemp568;
			float fTemp569 = 1.0f - fTemp197;
			float fTemp570 = fTemp197 * (fRec105 * fTemp197 + 2.0f * fRec106 * fTemp569) + fRec107 * fTemp198;
			float fTemp571 = fRec98[1] + fSlow9 * fTemp199 * (fTemp570 - fRec99[1]);
			float fTemp572 = fTemp571 / fTemp202;
			fRec98[0] = 2.0f * fTemp572 - fRec98[1];
			float fTemp573 = fRec99[1] + fSlow9 * (fTemp199 * fTemp571 / fTemp202);
			fRec99[0] = 2.0f * fTemp573 - fRec99[1];
			float fRec100 = fTemp570;
			float fRec101 = fTemp572;
			float fRec102 = fTemp573;
			float fTemp574 = fTemp197 * (fRec100 * fTemp197 + 1.4144272f * fRec101 * fTemp569) + fRec102 * fTemp198;
			float fTemp575 = fRec93[1] + fSlow9 * fTemp199 * (fTemp574 - fRec94[1]);
			float fTemp576 = fTemp575 / fTemp201;
			fRec93[0] = 2.0f * fTemp576 - fRec93[1];
			float fTemp577 = fRec94[1] + fSlow9 * (fTemp199 * fTemp575 / fTemp201);
			fRec94[0] = 2.0f * fTemp577 - fRec94[1];
			float fRec95 = fTemp574;
			float fRec96 = fTemp576;
			float fRec97 = fTemp577;
			float fTemp578 = fTemp197 * (fRec95 * fTemp197 + 0.5f * fRec96 * fTemp569) + fRec97 * fTemp198;
			float fTemp579 = fRec89[0] + fSlow100 * (fTemp195 - fRec89[0]);
			fVbargraph16 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp579)));
			float fTemp580 = std::pow(1e+01f, 0.008333334f * fTemp579);
			float fTemp581 = 1.0f - mydsp_faustpower2_f(fTemp580);
			float fTemp582 = std::sqrt(fTemp580);
			float fTemp583 = fSlow9 * fTemp582;
			float fTemp584 = fSlow9 * fTemp582 * (fTemp583 + 0.5f) + 1.0f;
			float fTemp585 = fSlow9 * fTemp582 * (fTemp583 + 1.4144272f) + 1.0f;
			float fTemp586 = fSlow9 * fTemp582 * (fTemp583 + 2.0f) + 1.0f;
			float fTemp587 = fRec114[0] + fSlow137 * (fTemp216 - fRec114[0]);
			fVbargraph17 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp587)));
			float fTemp588 = 0.008333334f * fTemp587;
			float fTemp589 = std::pow(1e+01f, fTemp588);
			float fTemp590 = mydsp_faustpower2_f(fTemp589) + -1.0f;
			float fTemp591 = std::sqrt(fTemp589);
			float fTemp592 = fSlow9 / fTemp591;
			float fTemp593 = fSlow9 * ((fTemp592 + 0.5f) / fTemp591) + 1.0f;
			float fTemp594 = fSlow9 * ((fTemp592 + 1.4144272f) / fTemp591) + 1.0f;
			float fTemp595 = fSlow9 * ((fTemp592 + 2.0f) / fTemp591) + 1.0f;
			float fTemp596 = std::pow(1e+01f, -fTemp588);
			float fTemp597 = mydsp_faustpower2_f(fTemp596) + -1.0f;
			float fTemp598 = std::sqrt(fTemp596);
			float fTemp599 = fSlow110 / fTemp598;
			float fTemp600 = fSlow110 * ((fTemp599 + 0.5f) / fTemp598) + 1.0f;
			float fTemp601 = fSlow110 * ((fTemp599 + 1.4144272f) / fTemp598) + 1.0f;
			float fTemp602 = fSlow110 * ((fTemp599 + 2.0f) / fTemp598) + 1.0f;
			float fTemp603 = fRec156[0] + fSlow167 * (fTemp245 - fRec156[0]);
			fVbargraph18 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp603)));
			float fTemp604 = 0.008333334f * fTemp603;
			float fTemp605 = std::pow(1e+01f, fTemp604);
			float fTemp606 = mydsp_faustpower2_f(fTemp605) + -1.0f;
			float fTemp607 = std::sqrt(fTemp605);
			float fTemp608 = fSlow110 / fTemp607;
			float fTemp609 = fSlow110 * ((fTemp608 + 0.5f) / fTemp607) + 1.0f;
			float fTemp610 = fSlow110 * ((fTemp608 + 1.4144272f) / fTemp607) + 1.0f;
			float fTemp611 = fSlow110 * ((fTemp608 + 2.0f) / fTemp607) + 1.0f;
			float fTemp612 = std::pow(1e+01f, -fTemp604);
			float fTemp613 = mydsp_faustpower2_f(fTemp612) + -1.0f;
			float fTemp614 = std::sqrt(fTemp612);
			float fTemp615 = fSlow142 / fTemp614;
			float fTemp616 = fSlow142 * ((fTemp615 + 0.5f) / fTemp614) + 1.0f;
			float fTemp617 = fSlow142 * ((fTemp615 + 1.4144272f) / fTemp614) + 1.0f;
			float fTemp618 = fSlow142 * ((fTemp615 + 2.0f) / fTemp614) + 1.0f;
			float fTemp619 = fRec198[0] + fSlow197 * (fTemp274 - fRec198[0]);
			fVbargraph19 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp619)));
			float fTemp620 = 0.008333334f * fTemp619;
			float fTemp621 = std::pow(1e+01f, fTemp620);
			float fTemp622 = mydsp_faustpower2_f(fTemp621) + -1.0f;
			float fTemp623 = std::sqrt(fTemp621);
			float fTemp624 = fSlow142 / fTemp623;
			float fTemp625 = fSlow142 * ((fTemp624 + 0.5f) / fTemp623) + 1.0f;
			float fTemp626 = fSlow142 * ((fTemp624 + 1.4144272f) / fTemp623) + 1.0f;
			float fTemp627 = fSlow142 * ((fTemp624 + 2.0f) / fTemp623) + 1.0f;
			float fTemp628 = std::pow(1e+01f, -fTemp620);
			float fTemp629 = mydsp_faustpower2_f(fTemp628) + -1.0f;
			float fTemp630 = std::sqrt(fTemp628);
			float fTemp631 = fSlow172 / fTemp630;
			float fTemp632 = fSlow172 * ((fTemp631 + 0.5f) / fTemp630) + 1.0f;
			float fTemp633 = fSlow172 * ((fTemp631 + 1.4144272f) / fTemp630) + 1.0f;
			float fTemp634 = fSlow172 * ((fTemp631 + 2.0f) / fTemp630) + 1.0f;
			float fTemp635 = fRec240[0] + fSlow227 * (fTemp303 - fRec240[0]);
			fVbargraph20 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp635)));
			float fTemp636 = 0.008333334f * fTemp635;
			float fTemp637 = std::pow(1e+01f, fTemp636);
			float fTemp638 = mydsp_faustpower2_f(fTemp637) + -1.0f;
			float fTemp639 = std::sqrt(fTemp637);
			float fTemp640 = fSlow172 / fTemp639;
			float fTemp641 = fSlow172 * ((fTemp640 + 0.5f) / fTemp639) + 1.0f;
			float fTemp642 = fSlow172 * ((fTemp640 + 1.4144272f) / fTemp639) + 1.0f;
			float fTemp643 = fSlow172 * ((fTemp640 + 2.0f) / fTemp639) + 1.0f;
			float fTemp644 = std::pow(1e+01f, -fTemp636);
			float fTemp645 = mydsp_faustpower2_f(fTemp644) + -1.0f;
			float fTemp646 = std::sqrt(fTemp644);
			float fTemp647 = fSlow202 / fTemp646;
			float fTemp648 = fSlow202 * ((fTemp647 + 0.5f) / fTemp646) + 1.0f;
			float fTemp649 = fSlow202 * ((fTemp647 + 1.4144272f) / fTemp646) + 1.0f;
			float fTemp650 = fSlow202 * ((fTemp647 + 2.0f) / fTemp646) + 1.0f;
			float fTemp651 = fRec282[0] + fSlow257 * (fTemp332 - fRec282[0]);
			fVbargraph21 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp651)));
			float fTemp652 = 0.008333334f * fTemp651;
			float fTemp653 = std::pow(1e+01f, fTemp652);
			float fTemp654 = mydsp_faustpower2_f(fTemp653) + -1.0f;
			float fTemp655 = std::sqrt(fTemp653);
			float fTemp656 = fSlow202 / fTemp655;
			float fTemp657 = fSlow202 * ((fTemp656 + 0.5f) / fTemp655) + 1.0f;
			float fTemp658 = fSlow202 * ((fTemp656 + 1.4144272f) / fTemp655) + 1.0f;
			float fTemp659 = fSlow202 * ((fTemp656 + 2.0f) / fTemp655) + 1.0f;
			float fTemp660 = std::pow(1e+01f, -fTemp652);
			float fTemp661 = mydsp_faustpower2_f(fTemp660) + -1.0f;
			float fTemp662 = std::sqrt(fTemp660);
			float fTemp663 = fSlow232 / fTemp662;
			float fTemp664 = fSlow232 * ((fTemp663 + 0.5f) / fTemp662) + 1.0f;
			float fTemp665 = fSlow232 * ((fTemp663 + 1.4144272f) / fTemp662) + 1.0f;
			float fTemp666 = fSlow232 * ((fTemp663 + 2.0f) / fTemp662) + 1.0f;
			float fTemp667 = fRec324[0] + fSlow287 * (fTemp361 - fRec324[0]);
			fVbargraph22 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp667)));
			float fTemp668 = 0.008333334f * fTemp667;
			float fTemp669 = std::pow(1e+01f, fTemp668);
			float fTemp670 = mydsp_faustpower2_f(fTemp669) + -1.0f;
			float fTemp671 = std::sqrt(fTemp669);
			float fTemp672 = fSlow232 / fTemp671;
			float fTemp673 = fSlow232 * ((fTemp672 + 0.5f) / fTemp671) + 1.0f;
			float fTemp674 = fSlow232 * ((fTemp672 + 1.4144272f) / fTemp671) + 1.0f;
			float fTemp675 = fSlow232 * ((fTemp672 + 2.0f) / fTemp671) + 1.0f;
			float fTemp676 = std::pow(1e+01f, -fTemp668);
			float fTemp677 = mydsp_faustpower2_f(fTemp676) + -1.0f;
			float fTemp678 = std::sqrt(fTemp676);
			float fTemp679 = fSlow262 / fTemp678;
			float fTemp680 = fSlow262 * ((fTemp679 + 0.5f) / fTemp678) + 1.0f;
			float fTemp681 = fSlow262 * ((fTemp679 + 1.4144272f) / fTemp678) + 1.0f;
			float fTemp682 = fSlow262 * ((fTemp679 + 2.0f) / fTemp678) + 1.0f;
			float fTemp683 = fRec363[0] + fSlow136 * (fTemp388 - fRec363[0]);
			fVbargraph23 = FAUSTFLOAT(std::min<float>(0.0f, std::max<float>(-6.0f, fTemp683)));
			float fTemp684 = std::pow(1e+01f, 0.008333334f * fTemp683);
			float fTemp685 = mydsp_faustpower2_f(fTemp684) + -1.0f;
			float fTemp686 = std::sqrt(fTemp684);
			float fTemp687 = fSlow262 / fTemp686;
			float fTemp688 = fSlow262 * ((fTemp687 + 0.5f) / fTemp686) + 1.0f;
			float fTemp689 = fSlow262 * ((fTemp687 + 1.4144272f) / fTemp686) + 1.0f;
			float fTemp690 = fSlow262 * ((fTemp687 + 2.0f) / fTemp686) + 1.0f;
			float fTemp691 = fRec586[1] + fSlow262 * ((fTemp188 - fRec587[1]) / fTemp686);
			float fTemp692 = fTemp691 / fTemp690;
			fRec586[0] = 2.0f * fTemp692 - fRec586[1];
			float fTemp693 = fRec587[1] + fSlow262 * (fTemp691 / (fTemp686 * fTemp690));
			fRec587[0] = 2.0f * fTemp693 - fRec587[1];
			float fRec588 = fTemp188;
			float fRec589 = fTemp692;
			float fRec590 = fTemp693;
			float fTemp694 = fTemp684 + -1.0f;
			float fTemp695 = fRec588 + 2.0f * fRec589 * fTemp694 + fRec590 * fTemp685;
			float fTemp696 = fRec581[1] + fSlow262 * ((fTemp695 - fRec582[1]) / fTemp686);
			float fTemp697 = fTemp696 / fTemp689;
			fRec581[0] = 2.0f * fTemp697 - fRec581[1];
			float fTemp698 = fRec582[1] + fSlow262 * (fTemp696 / (fTemp686 * fTemp689));
			fRec582[0] = 2.0f * fTemp698 - fRec582[1];
			float fRec583 = fTemp695;
			float fRec584 = fTemp697;
			float fRec585 = fTemp698;
			float fTemp699 = fRec583 + 1.4144272f * fRec584 * fTemp694 + fRec585 * fTemp685;
			float fTemp700 = fRec576[1] + fSlow262 * ((fTemp699 - fRec577[1]) / fTemp686);
			float fTemp701 = fTemp700 / fTemp688;
			fRec576[0] = 2.0f * fTemp701 - fRec576[1];
			float fTemp702 = fRec577[1] + fSlow262 * (fTemp700 / (fTemp686 * fTemp688));
			fRec577[0] = 2.0f * fTemp702 - fRec577[1];
			float fRec578 = fTemp699;
			float fRec579 = fTemp701;
			float fRec580 = fTemp702;
			float fTemp703 = fRec578 + 0.5f * fRec579 * fTemp694 + fRec580 * fTemp685;
			float fTemp704 = fRec571[1] + fSlow262 * ((fTemp703 - fRec572[1]) / fTemp678);
			float fTemp705 = fTemp704 / fTemp682;
			fRec571[0] = 2.0f * fTemp705 - fRec571[1];
			float fTemp706 = fRec572[1] + fSlow262 * (fTemp704 / (fTemp678 * fTemp682));
			fRec572[0] = 2.0f * fTemp706 - fRec572[1];
			float fRec573 = fTemp703;
			float fRec574 = fTemp705;
			float fRec575 = fTemp706;
			float fTemp707 = fTemp676 + -1.0f;
			float fTemp708 = fRec573 + 2.0f * fRec574 * fTemp707 + fRec575 * fTemp677;
			float fTemp709 = fRec566[1] + fSlow262 * ((fTemp708 - fRec567[1]) / fTemp678);
			float fTemp710 = fTemp709 / fTemp681;
			fRec566[0] = 2.0f * fTemp710 - fRec566[1];
			float fTemp711 = fRec567[1] + fSlow262 * (fTemp709 / (fTemp678 * fTemp681));
			fRec567[0] = 2.0f * fTemp711 - fRec567[1];
			float fRec568 = fTemp708;
			float fRec569 = fTemp710;
			float fRec570 = fTemp711;
			float fTemp712 = fRec568 + 1.4144272f * fRec569 * fTemp707 + fRec570 * fTemp677;
			float fTemp713 = fRec561[1] + fSlow262 * ((fTemp712 - fRec562[1]) / fTemp678);
			float fTemp714 = fTemp713 / fTemp680;
			fRec561[0] = 2.0f * fTemp714 - fRec561[1];
			float fTemp715 = fRec562[1] + fSlow262 * (fTemp713 / (fTemp678 * fTemp680));
			fRec562[0] = 2.0f * fTemp715 - fRec562[1];
			float fRec563 = fTemp712;
			float fRec564 = fTemp714;
			float fRec565 = fTemp715;
			float fTemp716 = fRec563 + 0.5f * fRec564 * fTemp707 + fRec565 * fTemp677;
			float fTemp717 = fRec556[1] + fSlow232 * ((fTemp716 - fRec557[1]) / fTemp671);
			float fTemp718 = fTemp717 / fTemp675;
			fRec556[0] = 2.0f * fTemp718 - fRec556[1];
			float fTemp719 = fRec557[1] + fSlow232 * (fTemp717 / (fTemp671 * fTemp675));
			fRec557[0] = 2.0f * fTemp719 - fRec557[1];
			float fRec558 = fTemp716;
			float fRec559 = fTemp718;
			float fRec560 = fTemp719;
			float fTemp720 = fTemp669 + -1.0f;
			float fTemp721 = fRec558 + 2.0f * fRec559 * fTemp720 + fRec560 * fTemp670;
			float fTemp722 = fRec551[1] + fSlow232 * ((fTemp721 - fRec552[1]) / fTemp671);
			float fTemp723 = fTemp722 / fTemp674;
			fRec551[0] = 2.0f * fTemp723 - fRec551[1];
			float fTemp724 = fRec552[1] + fSlow232 * (fTemp722 / (fTemp671 * fTemp674));
			fRec552[0] = 2.0f * fTemp724 - fRec552[1];
			float fRec553 = fTemp721;
			float fRec554 = fTemp723;
			float fRec555 = fTemp724;
			float fTemp725 = fRec553 + 1.4144272f * fRec554 * fTemp720 + fRec555 * fTemp670;
			float fTemp726 = fRec546[1] + fSlow232 * ((fTemp725 - fRec547[1]) / fTemp671);
			float fTemp727 = fTemp726 / fTemp673;
			fRec546[0] = 2.0f * fTemp727 - fRec546[1];
			float fTemp728 = fRec547[1] + fSlow232 * (fTemp726 / (fTemp671 * fTemp673));
			fRec547[0] = 2.0f * fTemp728 - fRec547[1];
			float fRec548 = fTemp725;
			float fRec549 = fTemp727;
			float fRec550 = fTemp728;
			float fTemp729 = fRec548 + 0.5f * fRec549 * fTemp720 + fRec550 * fTemp670;
			float fTemp730 = fRec541[1] + fSlow232 * ((fTemp729 - fRec542[1]) / fTemp662);
			float fTemp731 = fTemp730 / fTemp666;
			fRec541[0] = 2.0f * fTemp731 - fRec541[1];
			float fTemp732 = fRec542[1] + fSlow232 * (fTemp730 / (fTemp662 * fTemp666));
			fRec542[0] = 2.0f * fTemp732 - fRec542[1];
			float fRec543 = fTemp729;
			float fRec544 = fTemp731;
			float fRec545 = fTemp732;
			float fTemp733 = fTemp660 + -1.0f;
			float fTemp734 = fRec543 + 2.0f * fRec544 * fTemp733 + fRec545 * fTemp661;
			float fTemp735 = fRec536[1] + fSlow232 * ((fTemp734 - fRec537[1]) / fTemp662);
			float fTemp736 = fTemp735 / fTemp665;
			fRec536[0] = 2.0f * fTemp736 - fRec536[1];
			float fTemp737 = fRec537[1] + fSlow232 * (fTemp735 / (fTemp662 * fTemp665));
			fRec537[0] = 2.0f * fTemp737 - fRec537[1];
			float fRec538 = fTemp734;
			float fRec539 = fTemp736;
			float fRec540 = fTemp737;
			float fTemp738 = fRec538 + 1.4144272f * fRec539 * fTemp733 + fRec540 * fTemp661;
			float fTemp739 = fRec531[1] + fSlow232 * ((fTemp738 - fRec532[1]) / fTemp662);
			float fTemp740 = fTemp739 / fTemp664;
			fRec531[0] = 2.0f * fTemp740 - fRec531[1];
			float fTemp741 = fRec532[1] + fSlow232 * (fTemp739 / (fTemp662 * fTemp664));
			fRec532[0] = 2.0f * fTemp741 - fRec532[1];
			float fRec533 = fTemp738;
			float fRec534 = fTemp740;
			float fRec535 = fTemp741;
			float fTemp742 = fRec533 + 0.5f * fRec534 * fTemp733 + fRec535 * fTemp661;
			float fTemp743 = fRec526[1] + fSlow202 * ((fTemp742 - fRec527[1]) / fTemp655);
			float fTemp744 = fTemp743 / fTemp659;
			fRec526[0] = 2.0f * fTemp744 - fRec526[1];
			float fTemp745 = fRec527[1] + fSlow202 * (fTemp743 / (fTemp655 * fTemp659));
			fRec527[0] = 2.0f * fTemp745 - fRec527[1];
			float fRec528 = fTemp742;
			float fRec529 = fTemp744;
			float fRec530 = fTemp745;
			float fTemp746 = fTemp653 + -1.0f;
			float fTemp747 = fRec528 + 2.0f * fRec529 * fTemp746 + fRec530 * fTemp654;
			float fTemp748 = fRec521[1] + fSlow202 * ((fTemp747 - fRec522[1]) / fTemp655);
			float fTemp749 = fTemp748 / fTemp658;
			fRec521[0] = 2.0f * fTemp749 - fRec521[1];
			float fTemp750 = fRec522[1] + fSlow202 * (fTemp748 / (fTemp655 * fTemp658));
			fRec522[0] = 2.0f * fTemp750 - fRec522[1];
			float fRec523 = fTemp747;
			float fRec524 = fTemp749;
			float fRec525 = fTemp750;
			float fTemp751 = fRec523 + 1.4144272f * fRec524 * fTemp746 + fRec525 * fTemp654;
			float fTemp752 = fRec516[1] + fSlow202 * ((fTemp751 - fRec517[1]) / fTemp655);
			float fTemp753 = fTemp752 / fTemp657;
			fRec516[0] = 2.0f * fTemp753 - fRec516[1];
			float fTemp754 = fRec517[1] + fSlow202 * (fTemp752 / (fTemp655 * fTemp657));
			fRec517[0] = 2.0f * fTemp754 - fRec517[1];
			float fRec518 = fTemp751;
			float fRec519 = fTemp753;
			float fRec520 = fTemp754;
			float fTemp755 = fRec518 + 0.5f * fRec519 * fTemp746 + fRec520 * fTemp654;
			float fTemp756 = fRec511[1] + fSlow202 * ((fTemp755 - fRec512[1]) / fTemp646);
			float fTemp757 = fTemp756 / fTemp650;
			fRec511[0] = 2.0f * fTemp757 - fRec511[1];
			float fTemp758 = fRec512[1] + fSlow202 * (fTemp756 / (fTemp646 * fTemp650));
			fRec512[0] = 2.0f * fTemp758 - fRec512[1];
			float fRec513 = fTemp755;
			float fRec514 = fTemp757;
			float fRec515 = fTemp758;
			float fTemp759 = fTemp644 + -1.0f;
			float fTemp760 = fRec513 + 2.0f * fRec514 * fTemp759 + fRec515 * fTemp645;
			float fTemp761 = fRec506[1] + fSlow202 * ((fTemp760 - fRec507[1]) / fTemp646);
			float fTemp762 = fTemp761 / fTemp649;
			fRec506[0] = 2.0f * fTemp762 - fRec506[1];
			float fTemp763 = fRec507[1] + fSlow202 * (fTemp761 / (fTemp646 * fTemp649));
			fRec507[0] = 2.0f * fTemp763 - fRec507[1];
			float fRec508 = fTemp760;
			float fRec509 = fTemp762;
			float fRec510 = fTemp763;
			float fTemp764 = fRec508 + 1.4144272f * fRec509 * fTemp759 + fRec510 * fTemp645;
			float fTemp765 = fRec501[1] + fSlow202 * ((fTemp764 - fRec502[1]) / fTemp646);
			float fTemp766 = fTemp765 / fTemp648;
			fRec501[0] = 2.0f * fTemp766 - fRec501[1];
			float fTemp767 = fRec502[1] + fSlow202 * (fTemp765 / (fTemp646 * fTemp648));
			fRec502[0] = 2.0f * fTemp767 - fRec502[1];
			float fRec503 = fTemp764;
			float fRec504 = fTemp766;
			float fRec505 = fTemp767;
			float fTemp768 = fRec503 + 0.5f * fRec504 * fTemp759 + fRec505 * fTemp645;
			float fTemp769 = fRec496[1] + fSlow172 * ((fTemp768 - fRec497[1]) / fTemp639);
			float fTemp770 = fTemp769 / fTemp643;
			fRec496[0] = 2.0f * fTemp770 - fRec496[1];
			float fTemp771 = fRec497[1] + fSlow172 * (fTemp769 / (fTemp639 * fTemp643));
			fRec497[0] = 2.0f * fTemp771 - fRec497[1];
			float fRec498 = fTemp768;
			float fRec499 = fTemp770;
			float fRec500 = fTemp771;
			float fTemp772 = fTemp637 + -1.0f;
			float fTemp773 = fRec498 + 2.0f * fRec499 * fTemp772 + fRec500 * fTemp638;
			float fTemp774 = fRec491[1] + fSlow172 * ((fTemp773 - fRec492[1]) / fTemp639);
			float fTemp775 = fTemp774 / fTemp642;
			fRec491[0] = 2.0f * fTemp775 - fRec491[1];
			float fTemp776 = fRec492[1] + fSlow172 * (fTemp774 / (fTemp639 * fTemp642));
			fRec492[0] = 2.0f * fTemp776 - fRec492[1];
			float fRec493 = fTemp773;
			float fRec494 = fTemp775;
			float fRec495 = fTemp776;
			float fTemp777 = fRec493 + 1.4144272f * fRec494 * fTemp772 + fRec495 * fTemp638;
			float fTemp778 = fRec486[1] + fSlow172 * ((fTemp777 - fRec487[1]) / fTemp639);
			float fTemp779 = fTemp778 / fTemp641;
			fRec486[0] = 2.0f * fTemp779 - fRec486[1];
			float fTemp780 = fRec487[1] + fSlow172 * (fTemp778 / (fTemp639 * fTemp641));
			fRec487[0] = 2.0f * fTemp780 - fRec487[1];
			float fRec488 = fTemp777;
			float fRec489 = fTemp779;
			float fRec490 = fTemp780;
			float fTemp781 = fRec488 + 0.5f * fRec489 * fTemp772 + fRec490 * fTemp638;
			float fTemp782 = fRec481[1] + fSlow172 * ((fTemp781 - fRec482[1]) / fTemp630);
			float fTemp783 = fTemp782 / fTemp634;
			fRec481[0] = 2.0f * fTemp783 - fRec481[1];
			float fTemp784 = fRec482[1] + fSlow172 * (fTemp782 / (fTemp630 * fTemp634));
			fRec482[0] = 2.0f * fTemp784 - fRec482[1];
			float fRec483 = fTemp781;
			float fRec484 = fTemp783;
			float fRec485 = fTemp784;
			float fTemp785 = fTemp628 + -1.0f;
			float fTemp786 = fRec483 + 2.0f * fRec484 * fTemp785 + fRec485 * fTemp629;
			float fTemp787 = fRec476[1] + fSlow172 * ((fTemp786 - fRec477[1]) / fTemp630);
			float fTemp788 = fTemp787 / fTemp633;
			fRec476[0] = 2.0f * fTemp788 - fRec476[1];
			float fTemp789 = fRec477[1] + fSlow172 * (fTemp787 / (fTemp630 * fTemp633));
			fRec477[0] = 2.0f * fTemp789 - fRec477[1];
			float fRec478 = fTemp786;
			float fRec479 = fTemp788;
			float fRec480 = fTemp789;
			float fTemp790 = fRec478 + 1.4144272f * fRec479 * fTemp785 + fRec480 * fTemp629;
			float fTemp791 = fRec471[1] + fSlow172 * ((fTemp790 - fRec472[1]) / fTemp630);
			float fTemp792 = fTemp791 / fTemp632;
			fRec471[0] = 2.0f * fTemp792 - fRec471[1];
			float fTemp793 = fRec472[1] + fSlow172 * (fTemp791 / (fTemp630 * fTemp632));
			fRec472[0] = 2.0f * fTemp793 - fRec472[1];
			float fRec473 = fTemp790;
			float fRec474 = fTemp792;
			float fRec475 = fTemp793;
			float fTemp794 = fRec473 + 0.5f * fRec474 * fTemp785 + fRec475 * fTemp629;
			float fTemp795 = fRec466[1] + fSlow142 * ((fTemp794 - fRec467[1]) / fTemp623);
			float fTemp796 = fTemp795 / fTemp627;
			fRec466[0] = 2.0f * fTemp796 - fRec466[1];
			float fTemp797 = fRec467[1] + fSlow142 * (fTemp795 / (fTemp623 * fTemp627));
			fRec467[0] = 2.0f * fTemp797 - fRec467[1];
			float fRec468 = fTemp794;
			float fRec469 = fTemp796;
			float fRec470 = fTemp797;
			float fTemp798 = fTemp621 + -1.0f;
			float fTemp799 = fRec468 + 2.0f * fRec469 * fTemp798 + fRec470 * fTemp622;
			float fTemp800 = fRec461[1] + fSlow142 * ((fTemp799 - fRec462[1]) / fTemp623);
			float fTemp801 = fTemp800 / fTemp626;
			fRec461[0] = 2.0f * fTemp801 - fRec461[1];
			float fTemp802 = fRec462[1] + fSlow142 * (fTemp800 / (fTemp623 * fTemp626));
			fRec462[0] = 2.0f * fTemp802 - fRec462[1];
			float fRec463 = fTemp799;
			float fRec464 = fTemp801;
			float fRec465 = fTemp802;
			float fTemp803 = fRec463 + 1.4144272f * fRec464 * fTemp798 + fRec465 * fTemp622;
			float fTemp804 = fRec456[1] + fSlow142 * ((fTemp803 - fRec457[1]) / fTemp623);
			float fTemp805 = fTemp804 / fTemp625;
			fRec456[0] = 2.0f * fTemp805 - fRec456[1];
			float fTemp806 = fRec457[1] + fSlow142 * (fTemp804 / (fTemp623 * fTemp625));
			fRec457[0] = 2.0f * fTemp806 - fRec457[1];
			float fRec458 = fTemp803;
			float fRec459 = fTemp805;
			float fRec460 = fTemp806;
			float fTemp807 = fRec458 + 0.5f * fRec459 * fTemp798 + fRec460 * fTemp622;
			float fTemp808 = fRec451[1] + fSlow142 * ((fTemp807 - fRec452[1]) / fTemp614);
			float fTemp809 = fTemp808 / fTemp618;
			fRec451[0] = 2.0f * fTemp809 - fRec451[1];
			float fTemp810 = fRec452[1] + fSlow142 * (fTemp808 / (fTemp614 * fTemp618));
			fRec452[0] = 2.0f * fTemp810 - fRec452[1];
			float fRec453 = fTemp807;
			float fRec454 = fTemp809;
			float fRec455 = fTemp810;
			float fTemp811 = fTemp612 + -1.0f;
			float fTemp812 = fRec453 + 2.0f * fRec454 * fTemp811 + fRec455 * fTemp613;
			float fTemp813 = fRec446[1] + fSlow142 * ((fTemp812 - fRec447[1]) / fTemp614);
			float fTemp814 = fTemp813 / fTemp617;
			fRec446[0] = 2.0f * fTemp814 - fRec446[1];
			float fTemp815 = fRec447[1] + fSlow142 * (fTemp813 / (fTemp614 * fTemp617));
			fRec447[0] = 2.0f * fTemp815 - fRec447[1];
			float fRec448 = fTemp812;
			float fRec449 = fTemp814;
			float fRec450 = fTemp815;
			float fTemp816 = fRec448 + 1.4144272f * fRec449 * fTemp811 + fRec450 * fTemp613;
			float fTemp817 = fRec441[1] + fSlow142 * ((fTemp816 - fRec442[1]) / fTemp614);
			float fTemp818 = fTemp817 / fTemp616;
			fRec441[0] = 2.0f * fTemp818 - fRec441[1];
			float fTemp819 = fRec442[1] + fSlow142 * (fTemp817 / (fTemp614 * fTemp616));
			fRec442[0] = 2.0f * fTemp819 - fRec442[1];
			float fRec443 = fTemp816;
			float fRec444 = fTemp818;
			float fRec445 = fTemp819;
			float fTemp820 = fRec443 + 0.5f * fRec444 * fTemp811 + fRec445 * fTemp613;
			float fTemp821 = fRec436[1] + fSlow110 * ((fTemp820 - fRec437[1]) / fTemp607);
			float fTemp822 = fTemp821 / fTemp611;
			fRec436[0] = 2.0f * fTemp822 - fRec436[1];
			float fTemp823 = fRec437[1] + fSlow110 * (fTemp821 / (fTemp607 * fTemp611));
			fRec437[0] = 2.0f * fTemp823 - fRec437[1];
			float fRec438 = fTemp820;
			float fRec439 = fTemp822;
			float fRec440 = fTemp823;
			float fTemp824 = fTemp605 + -1.0f;
			float fTemp825 = fRec438 + 2.0f * fRec439 * fTemp824 + fRec440 * fTemp606;
			float fTemp826 = fRec431[1] + fSlow110 * ((fTemp825 - fRec432[1]) / fTemp607);
			float fTemp827 = fTemp826 / fTemp610;
			fRec431[0] = 2.0f * fTemp827 - fRec431[1];
			float fTemp828 = fRec432[1] + fSlow110 * (fTemp826 / (fTemp607 * fTemp610));
			fRec432[0] = 2.0f * fTemp828 - fRec432[1];
			float fRec433 = fTemp825;
			float fRec434 = fTemp827;
			float fRec435 = fTemp828;
			float fTemp829 = fRec433 + 1.4144272f * fRec434 * fTemp824 + fRec435 * fTemp606;
			float fTemp830 = fRec426[1] + fSlow110 * ((fTemp829 - fRec427[1]) / fTemp607);
			float fTemp831 = fTemp830 / fTemp609;
			fRec426[0] = 2.0f * fTemp831 - fRec426[1];
			float fTemp832 = fRec427[1] + fSlow110 * (fTemp830 / (fTemp607 * fTemp609));
			fRec427[0] = 2.0f * fTemp832 - fRec427[1];
			float fRec428 = fTemp829;
			float fRec429 = fTemp831;
			float fRec430 = fTemp832;
			float fTemp833 = fRec428 + 0.5f * fRec429 * fTemp824 + fRec430 * fTemp606;
			float fTemp834 = fRec421[1] + fSlow110 * ((fTemp833 - fRec422[1]) / fTemp598);
			float fTemp835 = fTemp834 / fTemp602;
			fRec421[0] = 2.0f * fTemp835 - fRec421[1];
			float fTemp836 = fRec422[1] + fSlow110 * (fTemp834 / (fTemp598 * fTemp602));
			fRec422[0] = 2.0f * fTemp836 - fRec422[1];
			float fRec423 = fTemp833;
			float fRec424 = fTemp835;
			float fRec425 = fTemp836;
			float fTemp837 = fTemp596 + -1.0f;
			float fTemp838 = fRec423 + 2.0f * fRec424 * fTemp837 + fRec425 * fTemp597;
			float fTemp839 = fRec416[1] + fSlow110 * ((fTemp838 - fRec417[1]) / fTemp598);
			float fTemp840 = fTemp839 / fTemp601;
			fRec416[0] = 2.0f * fTemp840 - fRec416[1];
			float fTemp841 = fRec417[1] + fSlow110 * (fTemp839 / (fTemp598 * fTemp601));
			fRec417[0] = 2.0f * fTemp841 - fRec417[1];
			float fRec418 = fTemp838;
			float fRec419 = fTemp840;
			float fRec420 = fTemp841;
			float fTemp842 = fRec418 + 1.4144272f * fRec419 * fTemp837 + fRec420 * fTemp597;
			float fTemp843 = fRec411[1] + fSlow110 * ((fTemp842 - fRec412[1]) / fTemp598);
			float fTemp844 = fTemp843 / fTemp600;
			fRec411[0] = 2.0f * fTemp844 - fRec411[1];
			float fTemp845 = fRec412[1] + fSlow110 * (fTemp843 / (fTemp598 * fTemp600));
			fRec412[0] = 2.0f * fTemp845 - fRec412[1];
			float fRec413 = fTemp842;
			float fRec414 = fTemp844;
			float fRec415 = fTemp845;
			float fTemp846 = fRec413 + 0.5f * fRec414 * fTemp837 + fRec415 * fTemp597;
			float fTemp847 = fRec406[1] + fSlow9 * ((fTemp846 - fRec407[1]) / fTemp591);
			float fTemp848 = fTemp847 / fTemp595;
			fRec406[0] = 2.0f * fTemp848 - fRec406[1];
			float fTemp849 = fRec407[1] + fSlow9 * (fTemp847 / (fTemp591 * fTemp595));
			fRec407[0] = 2.0f * fTemp849 - fRec407[1];
			float fRec408 = fTemp846;
			float fRec409 = fTemp848;
			float fRec410 = fTemp849;
			float fTemp850 = fTemp589 + -1.0f;
			float fTemp851 = fRec408 + 2.0f * fRec409 * fTemp850 + fRec410 * fTemp590;
			float fTemp852 = fRec401[1] + fSlow9 * ((fTemp851 - fRec402[1]) / fTemp591);
			float fTemp853 = fTemp852 / fTemp594;
			fRec401[0] = 2.0f * fTemp853 - fRec401[1];
			float fTemp854 = fRec402[1] + fSlow9 * (fTemp852 / (fTemp591 * fTemp594));
			fRec402[0] = 2.0f * fTemp854 - fRec402[1];
			float fRec403 = fTemp851;
			float fRec404 = fTemp853;
			float fRec405 = fTemp854;
			float fTemp855 = fRec403 + 1.4144272f * fRec404 * fTemp850 + fRec405 * fTemp590;
			float fTemp856 = fRec396[1] + fSlow9 * ((fTemp855 - fRec397[1]) / fTemp591);
			float fTemp857 = fTemp856 / fTemp593;
			fRec396[0] = 2.0f * fTemp857 - fRec396[1];
			float fTemp858 = fRec397[1] + fSlow9 * (fTemp856 / (fTemp591 * fTemp593));
			fRec397[0] = 2.0f * fTemp858 - fRec397[1];
			float fRec398 = fTemp855;
			float fRec399 = fTemp857;
			float fRec400 = fTemp858;
			float fTemp859 = fRec398 + 0.5f * fRec399 * fTemp850 + fRec400 * fTemp590;
			float fTemp860 = fRec391[1] + fSlow9 * fTemp582 * (fTemp859 - fRec392[1]);
			float fTemp861 = fTemp860 / fTemp586;
			fRec391[0] = 2.0f * fTemp861 - fRec391[1];
			float fTemp862 = fRec392[1] + fSlow9 * (fTemp582 * fTemp860 / fTemp586);
			fRec392[0] = 2.0f * fTemp862 - fRec392[1];
			float fRec393 = fTemp859;
			float fRec394 = fTemp861;
			float fRec395 = fTemp862;
			float fTemp863 = 1.0f - fTemp580;
			float fTemp864 = fTemp580 * (fRec393 * fTemp580 + 2.0f * fRec394 * fTemp863) + fRec395 * fTemp581;
			float fTemp865 = fRec386[1] + fSlow9 * fTemp582 * (fTemp864 - fRec387[1]);
			float fTemp866 = fTemp865 / fTemp585;
			fRec386[0] = 2.0f * fTemp866 - fRec386[1];
			float fTemp867 = fRec387[1] + fSlow9 * (fTemp582 * fTemp865 / fTemp585);
			fRec387[0] = 2.0f * fTemp867 - fRec387[1];
			float fRec388 = fTemp864;
			float fRec389 = fTemp866;
			float fRec390 = fTemp867;
			float fTemp868 = fTemp580 * (fRec388 * fTemp580 + 1.4144272f * fRec389 * fTemp863) + fRec390 * fTemp581;
			float fTemp869 = fRec381[1] + fSlow9 * fTemp582 * (fTemp868 - fRec382[1]);
			float fTemp870 = fTemp869 / fTemp584;
			fRec381[0] = 2.0f * fTemp870 - fRec381[1];
			float fTemp871 = fRec382[1] + fSlow9 * (fTemp582 * fTemp869 / fTemp584);
			fRec382[0] = 2.0f * fTemp871 - fRec382[1];
			float fRec383 = fTemp868;
			float fRec384 = fTemp870;
			float fRec385 = fTemp871;
			float fTemp872 = fTemp580 * (fRec383 * fTemp580 + 0.5f * fRec384 * fTemp863) + fRec385 * fTemp581;
			fRec591[0] = fSlow296 + fConst3 * fRec591[1];
			fRec592[0] = fSlow297 + fConst3 * fRec592[1];
			float fTemp873 = fRec592[0] * (1.0f - fRec591[0]);
			float fTemp874 = fRec591[0] * fTemp156;
			float fTemp875 = fTemp874 * fTemp180 + fTemp873 * (fTemp872 + fTemp578);
			fRec593[0] = fSlow298 + fConst3 * fRec593[1];
			float fTemp876 = 1.0f - fRec593[0];
			fRec594[0] = fSlow299 + fConst3 * fRec594[1];
			float fTemp877 = std::fabs(fRec595[1]);
			fRec598[IOTA0 & 131071] = fRec598[(IOTA0 - 1) & 131071] + mydsp_faustpower2_f(fTemp877 + fSlow304 * (std::fabs(fTemp875) - fTemp877));
			float fTemp878 = std::sqrt(fSlow307 * (fRec598[IOTA0 & 131071] - fRec598[(IOTA0 - iSlow306) & 131071]));
			float fTemp879 = ((fTemp878 > fRec597[1]) ? fSlow310 : 0.0f);
			fRec597[0] = fTemp878 * (1.0f - fTemp879) + fRec597[1] * fTemp879;
			float fTemp880 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec597[0]));
			int iTemp881 = (fTemp880 > fSlow311) + (fTemp880 > fSlow303);
			float fTemp882 = fTemp880 - fSlow302;
			float fTemp883 = std::fabs(fRec596[1]);
			float fTemp884 = fTemp874 * fTemp179 + fTemp873 * (fTemp872 - fTemp578);
			fRec600[IOTA0 & 131071] = fRec600[(IOTA0 - 1) & 131071] + mydsp_faustpower2_f(fTemp883 + fSlow304 * (std::fabs(fTemp884) - fTemp883));
			float fTemp885 = std::sqrt(fSlow307 * (fRec600[IOTA0 & 131071] - fRec600[(IOTA0 - iSlow306) & 131071]));
			float fTemp886 = ((fTemp885 > fRec599[1]) ? fSlow310 : 0.0f);
			fRec599[0] = fTemp885 * (1.0f - fTemp886) + fRec599[1] * fTemp886;
			float fTemp887 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec599[0]));
			int iTemp888 = (fTemp887 > fSlow311) + (fTemp887 > fSlow303);
			float fTemp889 = fTemp887 - fSlow302;
			float fTemp890 = std::min<float>(-(fSlow313 * std::max<float>(0.0f, ((iTemp881 == 0) ? 0.0f : ((iTemp881 == 1) ? fSlow312 * mydsp_faustpower2_f(fSlow301 + fTemp882) : fTemp882)))), -(fSlow313 * std::max<float>(0.0f, ((iTemp888 == 0) ? 0.0f : ((iTemp888 == 1) ? fSlow312 * mydsp_faustpower2_f(fSlow301 + fTemp889) : fTemp889)))));
			fVbargraph24 = FAUSTFLOAT(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fTemp890)));
			float fTemp891 = std::pow(1e+01f, 0.05f * fTemp890);
			fRec595[0] = fTemp875 * fTemp891;
			fRec596[0] = fTemp884 * fTemp891;
			float fTemp892 = fRec595[0] * fRec594[0] * fTemp876 + fRec593[0] * fTemp875;
			float fTemp893 = std::fabs(fTemp892);
			float fTemp894 = ((fTemp893 > fRec6[1]) ? 0.0f : fSlow316);
			fRec6[0] = fTemp893 * (1.0f - fTemp894) + fRec6[1] * fTemp894;
			float fTemp895 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec6[0]));
			int iTemp896 = 2 * (fTemp895 > fSlow1);
			float fTemp897 = fTemp895 - fSlow1;
			float fTemp898 = fRec593[0] * fTemp884 + fRec594[0] * fRec596[0] * fTemp876;
			float fTemp899 = std::fabs(fTemp898);
			float fTemp900 = ((fTemp899 > fRec601[1]) ? 0.0f : fSlow316);
			fRec601[0] = fTemp899 * (1.0f - fTemp900) + fRec601[1] * fTemp900;
			float fTemp901 = 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec601[0]));
			int iTemp902 = 2 * (fTemp901 > fSlow1);
			float fTemp903 = fTemp901 - fSlow1;
			float fTemp904 = std::min<float>(-(std::max<float>(0.0f, ((iTemp896 == 0) ? 0.0f : ((iTemp896 == 1) ? 4194304.0f * mydsp_faustpower2_f(fTemp897) : fTemp897)))), -(std::max<float>(0.0f, ((iTemp902 == 0) ? 0.0f : ((iTemp902 == 1) ? 4194304.0f * mydsp_faustpower2_f(fTemp903) : fTemp903)))));
			fVbargraph25 = FAUSTFLOAT(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fTemp904)));
			fRec602[0] = fSlow317 + fConst3 * fRec602[1];
			float fTemp905 = fRec602[0] + (1.0f - fRec602[0]) * std::pow(1e+01f, 0.05f * fTemp904);
			fRec4[0] = fTemp892 * fTemp905;
			fRec5[0] = fTemp898 * fTemp905;
			fRec2[0] = fRec4[0];
			fRec3[0] = fRec5[0];
			float fTemp906 = fTemp23 * fRec1[0] + fRec2[0] * fTemp0;
			fVec106[0] = fTemp906;
			fRec0[0] = std::max<float>(fRec0[1] - fConst1, std::min<float>(1e+01f, 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::max<float>(0.00031622776f, std::fabs(fTemp906))))));
			fVbargraph26 = FAUSTFLOAT(fRec0[0]);
			output0[i0] = FAUSTFLOAT(fTemp906);
			float fTemp907 = fTemp1 * fRec1[0] + fRec3[0] * fTemp0;
			fVec107[0] = fTemp907;
			fVec108[0] = fConst15 * fRec606[1] - fConst13 * fVec107[1];
			fRec607[0] = fConst17 * (fConst16 * fVec107[1] - (fVec108[1] + fConst12 * fRec607[1]) + fConst11 * fTemp907);
			fRec606[0] = fRec607[0];
			fVec109[0] = 0.50032705f * fRec606[1] - fConst22 * fRec604[1];
			fRec605[0] = fConst23 * (fVec109[1] - fConst20 * fRec605[1] - 1.0006541f * fRec606[1] + 0.50032705f * fRec606[0]);
			fRec604[0] = fRec605[0];
			float fTemp908 = mydsp_faustpower2_f(fRec604[0]);
			fVec110[0] = fTemp908;
			float fTemp909 = fTemp908 + fVec110[1];
			fVec111[0] = fTemp909;
			float fTemp910 = fTemp909 + fVec111[2];
			fVec112[0] = fTemp910;
			float fTemp911 = fTemp910 + fVec112[4];
			fVec113[0] = fTemp911;
			float fTemp912 = fTemp911 + fVec113[8];
			fVec114[IOTA0 & 31] = fTemp912;
			float fTemp913 = fTemp912 + fVec114[(IOTA0 - 16) & 31];
			fVec115[IOTA0 & 63] = fTemp913;
			float fTemp914 = fTemp913 + fVec115[(IOTA0 - 32) & 63];
			fVec116[IOTA0 & 127] = fTemp914;
			float fTemp915 = fTemp914 + fVec116[(IOTA0 - 64) & 127];
			fVec117[IOTA0 & 255] = fTemp915;
			float fTemp916 = fTemp915 + fVec117[(IOTA0 - 128) & 255];
			fVec118[IOTA0 & 511] = fTemp916;
			float fTemp917 = fTemp916 + fVec118[(IOTA0 - 256) & 511];
			fVec119[IOTA0 & 1023] = fTemp917;
			float fTemp918 = fTemp917 + fVec119[(IOTA0 - 512) & 1023];
			fVec120[IOTA0 & 2047] = fTemp918;
			float fTemp919 = fTemp918 + fVec120[(IOTA0 - 1024) & 2047];
			fVec121[IOTA0 & 4095] = fTemp919;
			float fTemp920 = fTemp919 + fVec121[(IOTA0 - 2048) & 4095];
			fVec122[IOTA0 & 8191] = fTemp920;
			float fTemp921 = fTemp920 + fVec122[(IOTA0 - 4096) & 8191];
			fVec123[IOTA0 & 16383] = fTemp921;
			float fTemp922 = fTemp921 + fVec123[(IOTA0 - 8192) & 16383];
			fVec124[IOTA0 & 32767] = fTemp922;
			float fTemp923 = fTemp922 + fVec124[(IOTA0 - 16384) & 32767];
			fVec125[IOTA0 & 65535] = fTemp923;
			float fTemp924 = fTemp923 + fVec125[(IOTA0 - 32768) & 65535];
			fVec126[IOTA0 & 131071] = fTemp924;
			float fTemp925 = fTemp924 + fVec126[(IOTA0 - 65536) & 131071];
			fVec127[IOTA0 & 262143] = fTemp925;
			float fTemp926 = fTemp925 + fVec127[(IOTA0 - 131072) & 262143];
			fVec128[IOTA0 & 524287] = fTemp926;
			fVec129[IOTA0 & 1048575] = fTemp926 + fVec128[(IOTA0 - 262144) & 524287];
			fVec130[0] = fConst15 * fRec610[1] - fConst13 * fVec106[1];
			fRec611[0] = fConst17 * (fConst16 * fVec106[1] - (fVec130[1] + fConst12 * fRec611[1]) + fConst11 * fTemp906);
			fRec610[0] = fRec611[0];
			fVec131[0] = 0.50032705f * fRec610[1] - fConst22 * fRec608[1];
			fRec609[0] = fConst23 * (fVec131[1] - fConst20 * fRec609[1] - 1.0006541f * fRec610[1] + 0.50032705f * fRec610[0]);
			fRec608[0] = fRec609[0];
			float fTemp927 = mydsp_faustpower2_f(fRec608[0]);
			fVec132[0] = fTemp927;
			float fTemp928 = fTemp927 + fVec132[1];
			fVec133[0] = fTemp928;
			float fTemp929 = fTemp928 + fVec133[2];
			fVec134[0] = fTemp929;
			float fTemp930 = fTemp929 + fVec134[4];
			fVec135[0] = fTemp930;
			float fTemp931 = fTemp930 + fVec135[8];
			fVec136[IOTA0 & 31] = fTemp931;
			float fTemp932 = fTemp931 + fVec136[(IOTA0 - 16) & 31];
			fVec137[IOTA0 & 63] = fTemp932;
			float fTemp933 = fTemp932 + fVec137[(IOTA0 - 32) & 63];
			fVec138[IOTA0 & 127] = fTemp933;
			float fTemp934 = fTemp933 + fVec138[(IOTA0 - 64) & 127];
			fVec139[IOTA0 & 255] = fTemp934;
			float fTemp935 = fTemp934 + fVec139[(IOTA0 - 128) & 255];
			fVec140[IOTA0 & 511] = fTemp935;
			float fTemp936 = fTemp935 + fVec140[(IOTA0 - 256) & 511];
			fVec141[IOTA0 & 1023] = fTemp936;
			float fTemp937 = fTemp936 + fVec141[(IOTA0 - 512) & 1023];
			fVec142[IOTA0 & 2047] = fTemp937;
			float fTemp938 = fTemp937 + fVec142[(IOTA0 - 1024) & 2047];
			fVec143[IOTA0 & 4095] = fTemp938;
			float fTemp939 = fTemp938 + fVec143[(IOTA0 - 2048) & 4095];
			fVec144[IOTA0 & 8191] = fTemp939;
			float fTemp940 = fTemp939 + fVec144[(IOTA0 - 4096) & 8191];
			fVec145[IOTA0 & 16383] = fTemp940;
			float fTemp941 = fTemp940 + fVec145[(IOTA0 - 8192) & 16383];
			fVec146[IOTA0 & 32767] = fTemp941;
			float fTemp942 = fTemp941 + fVec146[(IOTA0 - 16384) & 32767];
			fVec147[IOTA0 & 65535] = fTemp942;
			float fTemp943 = fTemp942 + fVec147[(IOTA0 - 32768) & 65535];
			fVec148[IOTA0 & 131071] = fTemp943;
			float fTemp944 = fTemp943 + fVec148[(IOTA0 - 65536) & 131071];
			fVec149[IOTA0 & 262143] = fTemp944;
			float fTemp945 = fTemp944 + fVec149[(IOTA0 - 131072) & 262143];
			fVec150[IOTA0 & 524287] = fTemp945;
			fVec151[IOTA0 & 1048575] = fTemp945 + fVec150[(IOTA0 - 262144) & 524287];
			fVbargraph27 = FAUSTFLOAT(4.3429446f * std::log(std::max<float>(1e-12f, fConst61 * (((iConst59) ? fVec151[(IOTA0 - iConst60) & 1048575] : 0.0f) + ((iConst57) ? fVec150[(IOTA0 - iConst58) & 524287] : 0.0f) + ((iConst55) ? fVec149[(IOTA0 - iConst56) & 262143] : 0.0f) + ((iConst53) ? fVec148[(IOTA0 - iConst54) & 131071] : 0.0f) + ((iConst51) ? fVec147[(IOTA0 - iConst52) & 65535] : 0.0f) + ((iConst49) ? fVec146[(IOTA0 - iConst50) & 32767] : 0.0f) + ((iConst47) ? fVec145[(IOTA0 - iConst48) & 16383] : 0.0f) + ((iConst45) ? fVec144[(IOTA0 - iConst46) & 8191] : 0.0f) + ((iConst43) ? fVec143[(IOTA0 - iConst44) & 4095] : 0.0f) + ((iConst41) ? fVec142[(IOTA0 - iConst42) & 2047] : 0.0f) + ((iConst39) ? fVec141[(IOTA0 - iConst40) & 1023] : 0.0f) + ((iConst37) ? fVec140[(IOTA0 - iConst38) & 511] : 0.0f) + ((iConst35) ? fVec139[(IOTA0 - iConst36) & 255] : 0.0f) + ((iConst33) ? fVec138[(IOTA0 - iConst34) & 127] : 0.0f) + ((iConst31) ? fVec137[(IOTA0 - iConst32) & 63] : 0.0f) + ((iConst29) ? fVec136[(IOTA0 - iConst30) & 31] : 0.0f) + ((iConst27) ? fVec135[iConst28] : 0.0f) + ((iConst25) ? fVec134[iConst26] : 0.0f) + ((iConst24) ? fTemp927 : 0.0f) + ((iConst7) ? fVec133[iConst24] : 0.0f) + ((iConst59) ? fVec129[(IOTA0 - iConst60) & 1048575] : 0.0f) + ((iConst57) ? fVec128[(IOTA0 - iConst58) & 524287] : 0.0f) + ((iConst55) ? fVec127[(IOTA0 - iConst56) & 262143] : 0.0f) + ((iConst53) ? fVec126[(IOTA0 - iConst54) & 131071] : 0.0f) + ((iConst51) ? fVec125[(IOTA0 - iConst52) & 65535] : 0.0f) + ((iConst49) ? fVec124[(IOTA0 - iConst50) & 32767] : 0.0f) + ((iConst47) ? fVec123[(IOTA0 - iConst48) & 16383] : 0.0f) + ((iConst45) ? fVec122[(IOTA0 - iConst46) & 8191] : 0.0f) + ((iConst43) ? fVec121[(IOTA0 - iConst44) & 4095] : 0.0f) + ((iConst41) ? fVec120[(IOTA0 - iConst42) & 2047] : 0.0f) + ((iConst39) ? fVec119[(IOTA0 - iConst40) & 1023] : 0.0f) + ((iConst37) ? fVec118[(IOTA0 - iConst38) & 511] : 0.0f) + ((iConst35) ? fVec117[(IOTA0 - iConst36) & 255] : 0.0f) + ((iConst33) ? fVec116[(IOTA0 - iConst34) & 127] : 0.0f) + ((iConst31) ? fVec115[(IOTA0 - iConst32) & 63] : 0.0f) + ((iConst29) ? fVec114[(IOTA0 - iConst30) & 31] : 0.0f) + ((iConst27) ? fVec113[iConst28] : 0.0f) + ((iConst25) ? fVec112[iConst26] : 0.0f) + ((iConst24) ? fTemp908 : 0.0f) + ((iConst7) ? fVec111[iConst24] : 0.0f)))) + -0.691f);
			float fTemp946 = fTemp907;
			fRec603[0] = std::max<float>(fRec603[1] - fConst1, std::min<float>(1e+01f, 2e+01f * std::log10(std::max<float>(1.1754944e-38f, std::max<float>(0.00031622776f, std::fabs(fTemp946))))));
			fVbargraph28 = FAUSTFLOAT(fRec603[0]);
			output1[i0] = FAUSTFLOAT(fTemp946);
			fRec1[1] = fRec1[0];
			fRec11[1] = fRec11[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fVec2[1] = fVec2[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fVec3[1] = fVec3[0];
			fVec4[2] = fVec4[1];
			fVec4[1] = fVec4[0];
			for (int j0 = 4; j0 > 0; j0 = j0 - 1) {
				fVec5[j0] = fVec5[j0 - 1];
			}
			for (int j1 = 11; j1 > 0; j1 = j1 - 1) {
				fVec6[j1] = fVec6[j1 - 1];
			}
			IOTA0 = IOTA0 + 1;
			fRec26[1] = fRec26[0];
			fVec23[1] = fVec23[0];
			fVec24[1] = fVec24[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fVec25[1] = fVec25[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fVec26[1] = fVec26[0];
			fVec27[2] = fVec27[1];
			fVec27[1] = fVec27[0];
			for (int j2 = 4; j2 > 0; j2 = j2 - 1) {
				fVec28[j2] = fVec28[j2 - 1];
			}
			for (int j3 = 11; j3 > 0; j3 = j3 - 1) {
				fVec29[j3] = fVec29[j3 - 1];
			}
			fVec46[1] = fVec46[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec30[1] = fRec30[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec37[1] = fRec37[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec46[1] = fRec46[0];
			fRec15[1] = fRec15[0];
			iVec47[1] = iVec47[0];
			iRec47[1] = iRec47[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			iVec48[1] = iVec48[0];
			iRec48[1] = iRec48[0];
			fRec12[1] = fRec12[0];
			fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec59[1] = fRec59[0];
			fVec49[1] = fVec49[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec63[1] = fRec63[0];
			fVec50[1] = fVec50[0];
			fRec60[1] = fRec60[0];
			fRec64[1] = fRec64[0];
			fVec51[1] = fVec51[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec68[1] = fRec68[0];
			fVec52[1] = fVec52[0];
			fRec65[1] = fRec65[0];
			fRec69[1] = fRec69[0];
			fRec55[1] = fRec55[0];
			fRec56[1] = fRec56[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fVec53[1] = fVec53[0];
			fVec54[2] = fVec54[1];
			fVec54[1] = fVec54[0];
			for (int j4 = 4; j4 > 0; j4 = j4 - 1) {
				fVec55[j4] = fVec55[j4 - 1];
			}
			for (int j5 = 11; j5 > 0; j5 = j5 - 1) {
				fVec56[j5] = fVec56[j5 - 1];
			}
			fRec74[1] = fRec74[0];
			fVec68[1] = fVec68[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fVec69[1] = fVec69[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fVec70[1] = fVec70[0];
			fVec71[2] = fVec71[1];
			fVec71[1] = fVec71[0];
			for (int j6 = 4; j6 > 0; j6 = j6 - 1) {
				fVec72[j6] = fVec72[j6 - 1];
			}
			for (int j7 = 11; j7 > 0; j7 = j7 - 1) {
				fVec73[j7] = fVec73[j7 - 1];
			}
			fVec87[1] = fVec87[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fVec88[1] = fVec88[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fVec89[1] = fVec89[0];
			fVec90[2] = fVec90[1];
			fVec90[1] = fVec90[0];
			for (int j8 = 4; j8 > 0; j8 = j8 - 1) {
				fVec91[j8] = fVec91[j8 - 1];
			}
			for (int j9 = 11; j9 > 0; j9 = j9 - 1) {
				fVec92[j9] = fVec92[j9 - 1];
			}
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec83[1] = fRec83[0];
			fRec70[1] = fRec70[0];
			fRec84[1] = fRec84[0];
			fRec86[1] = fRec86[0];
			fRec87[1] = fRec87[0];
			fRec88[1] = fRec88[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec91[2] = fRec91[1];
			fRec91[1] = fRec91[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec113[2] = fRec113[1];
			fRec113[1] = fRec113[0];
			fRec112[2] = fRec112[1];
			fRec112[1] = fRec112[0];
			fRec111[2] = fRec111[1];
			fRec111[1] = fRec111[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec108[1] = fRec108[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec116[2] = fRec116[1];
			fRec116[1] = fRec116[0];
			fRec115[2] = fRec115[1];
			fRec115[1] = fRec115[0];
			fRec114[1] = fRec114[0];
			fRec155[2] = fRec155[1];
			fRec155[1] = fRec155[0];
			fRec154[2] = fRec154[1];
			fRec154[1] = fRec154[0];
			fRec153[2] = fRec153[1];
			fRec153[1] = fRec153[0];
			fRec152[2] = fRec152[1];
			fRec152[1] = fRec152[0];
			fRec151[2] = fRec151[1];
			fRec151[1] = fRec151[0];
			fRec150[1] = fRec150[0];
			fRec161[2] = fRec161[1];
			fRec161[1] = fRec161[0];
			fRec160[2] = fRec160[1];
			fRec160[1] = fRec160[0];
			fRec159[2] = fRec159[1];
			fRec159[1] = fRec159[0];
			fRec158[2] = fRec158[1];
			fRec158[1] = fRec158[0];
			fRec157[2] = fRec157[1];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			fRec197[2] = fRec197[1];
			fRec197[1] = fRec197[0];
			fRec196[2] = fRec196[1];
			fRec196[1] = fRec196[0];
			fRec195[2] = fRec195[1];
			fRec195[1] = fRec195[0];
			fRec194[2] = fRec194[1];
			fRec194[1] = fRec194[0];
			fRec193[2] = fRec193[1];
			fRec193[1] = fRec193[0];
			fRec192[1] = fRec192[0];
			fRec203[2] = fRec203[1];
			fRec203[1] = fRec203[0];
			fRec202[2] = fRec202[1];
			fRec202[1] = fRec202[0];
			fRec201[2] = fRec201[1];
			fRec201[1] = fRec201[0];
			fRec200[2] = fRec200[1];
			fRec200[1] = fRec200[0];
			fRec199[2] = fRec199[1];
			fRec199[1] = fRec199[0];
			fRec198[1] = fRec198[0];
			fRec239[2] = fRec239[1];
			fRec239[1] = fRec239[0];
			fRec238[2] = fRec238[1];
			fRec238[1] = fRec238[0];
			fRec237[2] = fRec237[1];
			fRec237[1] = fRec237[0];
			fRec236[2] = fRec236[1];
			fRec236[1] = fRec236[0];
			fRec235[2] = fRec235[1];
			fRec235[1] = fRec235[0];
			fRec234[1] = fRec234[0];
			fRec245[2] = fRec245[1];
			fRec245[1] = fRec245[0];
			fRec244[2] = fRec244[1];
			fRec244[1] = fRec244[0];
			fRec243[2] = fRec243[1];
			fRec243[1] = fRec243[0];
			fRec242[2] = fRec242[1];
			fRec242[1] = fRec242[0];
			fRec241[2] = fRec241[1];
			fRec241[1] = fRec241[0];
			fRec240[1] = fRec240[0];
			fRec281[2] = fRec281[1];
			fRec281[1] = fRec281[0];
			fRec280[2] = fRec280[1];
			fRec280[1] = fRec280[0];
			fRec279[2] = fRec279[1];
			fRec279[1] = fRec279[0];
			fRec278[2] = fRec278[1];
			fRec278[1] = fRec278[0];
			fRec277[2] = fRec277[1];
			fRec277[1] = fRec277[0];
			fRec276[1] = fRec276[0];
			fRec287[2] = fRec287[1];
			fRec287[1] = fRec287[0];
			fRec286[2] = fRec286[1];
			fRec286[1] = fRec286[0];
			fRec285[2] = fRec285[1];
			fRec285[1] = fRec285[0];
			fRec284[2] = fRec284[1];
			fRec284[1] = fRec284[0];
			fRec283[2] = fRec283[1];
			fRec283[1] = fRec283[0];
			fRec282[1] = fRec282[0];
			fRec323[2] = fRec323[1];
			fRec323[1] = fRec323[0];
			fRec322[2] = fRec322[1];
			fRec322[1] = fRec322[0];
			fRec321[2] = fRec321[1];
			fRec321[1] = fRec321[0];
			fRec320[2] = fRec320[1];
			fRec320[1] = fRec320[0];
			fRec319[2] = fRec319[1];
			fRec319[1] = fRec319[0];
			fRec318[1] = fRec318[0];
			fRec329[2] = fRec329[1];
			fRec329[1] = fRec329[0];
			fRec328[2] = fRec328[1];
			fRec328[1] = fRec328[0];
			fRec327[2] = fRec327[1];
			fRec327[1] = fRec327[0];
			fRec326[2] = fRec326[1];
			fRec326[1] = fRec326[0];
			fRec325[2] = fRec325[1];
			fRec325[1] = fRec325[0];
			fRec324[1] = fRec324[0];
			fRec362[2] = fRec362[1];
			fRec362[1] = fRec362[0];
			fRec361[2] = fRec361[1];
			fRec361[1] = fRec361[0];
			fRec360[1] = fRec360[0];
			fRec365[2] = fRec365[1];
			fRec365[1] = fRec365[0];
			fRec364[2] = fRec364[1];
			fRec364[1] = fRec364[0];
			fRec363[1] = fRec363[0];
			fRec376[1] = fRec376[0];
			fRec377[1] = fRec377[0];
			fRec371[1] = fRec371[0];
			fRec372[1] = fRec372[0];
			fRec366[1] = fRec366[0];
			fRec367[1] = fRec367[0];
			fRec355[1] = fRec355[0];
			fRec356[1] = fRec356[0];
			fRec350[1] = fRec350[0];
			fRec351[1] = fRec351[0];
			fRec345[1] = fRec345[0];
			fRec346[1] = fRec346[0];
			fRec340[1] = fRec340[0];
			fRec341[1] = fRec341[0];
			fRec335[1] = fRec335[0];
			fRec336[1] = fRec336[0];
			fRec330[1] = fRec330[0];
			fRec331[1] = fRec331[0];
			fRec313[1] = fRec313[0];
			fRec314[1] = fRec314[0];
			fRec308[1] = fRec308[0];
			fRec309[1] = fRec309[0];
			fRec303[1] = fRec303[0];
			fRec304[1] = fRec304[0];
			fRec298[1] = fRec298[0];
			fRec299[1] = fRec299[0];
			fRec293[1] = fRec293[0];
			fRec294[1] = fRec294[0];
			fRec288[1] = fRec288[0];
			fRec289[1] = fRec289[0];
			fRec271[1] = fRec271[0];
			fRec272[1] = fRec272[0];
			fRec266[1] = fRec266[0];
			fRec267[1] = fRec267[0];
			fRec261[1] = fRec261[0];
			fRec262[1] = fRec262[0];
			fRec256[1] = fRec256[0];
			fRec257[1] = fRec257[0];
			fRec251[1] = fRec251[0];
			fRec252[1] = fRec252[0];
			fRec246[1] = fRec246[0];
			fRec247[1] = fRec247[0];
			fRec229[1] = fRec229[0];
			fRec230[1] = fRec230[0];
			fRec224[1] = fRec224[0];
			fRec225[1] = fRec225[0];
			fRec219[1] = fRec219[0];
			fRec220[1] = fRec220[0];
			fRec214[1] = fRec214[0];
			fRec215[1] = fRec215[0];
			fRec209[1] = fRec209[0];
			fRec210[1] = fRec210[0];
			fRec204[1] = fRec204[0];
			fRec205[1] = fRec205[0];
			fRec187[1] = fRec187[0];
			fRec188[1] = fRec188[0];
			fRec182[1] = fRec182[0];
			fRec183[1] = fRec183[0];
			fRec177[1] = fRec177[0];
			fRec178[1] = fRec178[0];
			fRec172[1] = fRec172[0];
			fRec173[1] = fRec173[0];
			fRec167[1] = fRec167[0];
			fRec168[1] = fRec168[0];
			fRec162[1] = fRec162[0];
			fRec163[1] = fRec163[0];
			fRec145[1] = fRec145[0];
			fRec146[1] = fRec146[0];
			fRec140[1] = fRec140[0];
			fRec141[1] = fRec141[0];
			fRec135[1] = fRec135[0];
			fRec136[1] = fRec136[0];
			fRec130[1] = fRec130[0];
			fRec131[1] = fRec131[0];
			fRec125[1] = fRec125[0];
			fRec126[1] = fRec126[0];
			fRec120[1] = fRec120[0];
			fRec121[1] = fRec121[0];
			fRec103[1] = fRec103[0];
			fRec104[1] = fRec104[0];
			fRec98[1] = fRec98[0];
			fRec99[1] = fRec99[0];
			fRec93[1] = fRec93[0];
			fRec94[1] = fRec94[0];
			fRec586[1] = fRec586[0];
			fRec587[1] = fRec587[0];
			fRec581[1] = fRec581[0];
			fRec582[1] = fRec582[0];
			fRec576[1] = fRec576[0];
			fRec577[1] = fRec577[0];
			fRec571[1] = fRec571[0];
			fRec572[1] = fRec572[0];
			fRec566[1] = fRec566[0];
			fRec567[1] = fRec567[0];
			fRec561[1] = fRec561[0];
			fRec562[1] = fRec562[0];
			fRec556[1] = fRec556[0];
			fRec557[1] = fRec557[0];
			fRec551[1] = fRec551[0];
			fRec552[1] = fRec552[0];
			fRec546[1] = fRec546[0];
			fRec547[1] = fRec547[0];
			fRec541[1] = fRec541[0];
			fRec542[1] = fRec542[0];
			fRec536[1] = fRec536[0];
			fRec537[1] = fRec537[0];
			fRec531[1] = fRec531[0];
			fRec532[1] = fRec532[0];
			fRec526[1] = fRec526[0];
			fRec527[1] = fRec527[0];
			fRec521[1] = fRec521[0];
			fRec522[1] = fRec522[0];
			fRec516[1] = fRec516[0];
			fRec517[1] = fRec517[0];
			fRec511[1] = fRec511[0];
			fRec512[1] = fRec512[0];
			fRec506[1] = fRec506[0];
			fRec507[1] = fRec507[0];
			fRec501[1] = fRec501[0];
			fRec502[1] = fRec502[0];
			fRec496[1] = fRec496[0];
			fRec497[1] = fRec497[0];
			fRec491[1] = fRec491[0];
			fRec492[1] = fRec492[0];
			fRec486[1] = fRec486[0];
			fRec487[1] = fRec487[0];
			fRec481[1] = fRec481[0];
			fRec482[1] = fRec482[0];
			fRec476[1] = fRec476[0];
			fRec477[1] = fRec477[0];
			fRec471[1] = fRec471[0];
			fRec472[1] = fRec472[0];
			fRec466[1] = fRec466[0];
			fRec467[1] = fRec467[0];
			fRec461[1] = fRec461[0];
			fRec462[1] = fRec462[0];
			fRec456[1] = fRec456[0];
			fRec457[1] = fRec457[0];
			fRec451[1] = fRec451[0];
			fRec452[1] = fRec452[0];
			fRec446[1] = fRec446[0];
			fRec447[1] = fRec447[0];
			fRec441[1] = fRec441[0];
			fRec442[1] = fRec442[0];
			fRec436[1] = fRec436[0];
			fRec437[1] = fRec437[0];
			fRec431[1] = fRec431[0];
			fRec432[1] = fRec432[0];
			fRec426[1] = fRec426[0];
			fRec427[1] = fRec427[0];
			fRec421[1] = fRec421[0];
			fRec422[1] = fRec422[0];
			fRec416[1] = fRec416[0];
			fRec417[1] = fRec417[0];
			fRec411[1] = fRec411[0];
			fRec412[1] = fRec412[0];
			fRec406[1] = fRec406[0];
			fRec407[1] = fRec407[0];
			fRec401[1] = fRec401[0];
			fRec402[1] = fRec402[0];
			fRec396[1] = fRec396[0];
			fRec397[1] = fRec397[0];
			fRec391[1] = fRec391[0];
			fRec392[1] = fRec392[0];
			fRec386[1] = fRec386[0];
			fRec387[1] = fRec387[0];
			fRec381[1] = fRec381[0];
			fRec382[1] = fRec382[0];
			fRec591[1] = fRec591[0];
			fRec592[1] = fRec592[0];
			fRec593[1] = fRec593[0];
			fRec594[1] = fRec594[0];
			fRec597[1] = fRec597[0];
			fRec599[1] = fRec599[0];
			fRec595[1] = fRec595[0];
			fRec596[1] = fRec596[0];
			fRec6[1] = fRec6[0];
			fRec601[1] = fRec601[0];
			fRec602[1] = fRec602[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fVec106[1] = fVec106[0];
			fRec0[1] = fRec0[0];
			fVec107[1] = fVec107[0];
			fVec108[1] = fVec108[0];
			fRec607[1] = fRec607[0];
			fRec606[1] = fRec606[0];
			fVec109[1] = fVec109[0];
			fRec605[1] = fRec605[0];
			fRec604[1] = fRec604[0];
			fVec110[1] = fVec110[0];
			fVec111[2] = fVec111[1];
			fVec111[1] = fVec111[0];
			for (int j10 = 4; j10 > 0; j10 = j10 - 1) {
				fVec112[j10] = fVec112[j10 - 1];
			}
			for (int j11 = 11; j11 > 0; j11 = j11 - 1) {
				fVec113[j11] = fVec113[j11 - 1];
			}
			fVec130[1] = fVec130[0];
			fRec611[1] = fRec611[0];
			fRec610[1] = fRec610[0];
			fVec131[1] = fVec131[0];
			fRec609[1] = fRec609[0];
			fRec608[1] = fRec608[0];
			fVec132[1] = fVec132[0];
			fVec133[2] = fVec133[1];
			fVec133[1] = fVec133[0];
			for (int j12 = 4; j12 > 0; j12 = j12 - 1) {
				fVec134[j12] = fVec134[j12 - 1];
			}
			for (int j13 = 11; j13 > 0; j13 = j13 - 1) {
				fVec135[j13] = fVec135[j13 - 1];
			}
			fRec603[1] = fRec603[0];
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
        dsp->fVbargraph1 = 0;
        dsp->fVbargraph0 = 0;
        dsp->fVbargraph2 = 0;
        dsp->fVbargraph5 = 0;
        dsp->fVbargraph27 = 0;
        dsp->fVbargraph26 = 0;
        dsp->fVbargraph28 = 0;
        dsp->fVbargraph3 = 0;
        dsp->fVbargraph4 = 0;
        dsp->fVbargraph7 = 0;
        dsp->fVbargraph6 = 0;
        dsp->fVbargraph23 = 0;
        dsp->fVbargraph15 = 0;
        dsp->fVbargraph22 = 0;
        dsp->fVbargraph14 = 0;
        dsp->fVbargraph21 = 0;
        dsp->fVbargraph13 = 0;
        dsp->fVbargraph20 = 0;
        dsp->fVbargraph12 = 0;
        dsp->fVbargraph19 = 0;
        dsp->fVbargraph11 = 0;
        dsp->fVbargraph18 = 0;
        dsp->fVbargraph10 = 0;
        dsp->fVbargraph17 = 0;
        dsp->fVbargraph9 = 0;
        dsp->fVbargraph16 = 0;
        dsp->fVbargraph8 = 0;
        dsp->fVbargraph24 = 0;
        dsp->fVbargraph25 = 0;
        
    }

    /*
    void printCurrentValues()
    {
        d_stdout("==== preset data start ===");
        printf("%.12g,", dsp->fCheckbox0);
        printf("%.12g,", dsp->fVslider2);
        printf("%.12g,", dsp->fVslider9);
        printf("%.12g,", dsp->fCheckbox5);
        printf("%.12g,", dsp->fCheckbox4);
        printf("%.12g,", dsp->fCheckbox3);
        printf("%.12g,", dsp->fCheckbox2);
        printf("%.12g,", dsp->fCheckbox6);
        printf("%.12g,", dsp->fCheckbox1);
        printf("%.12g,", dsp->fVslider6);
        printf("%.12g,", dsp->fVslider7);
        printf("%.12g,", dsp->fVslider10);
        printf("%.12g,", dsp->fVslider8);
        printf("%.12g,", dsp->fCheckbox7);
        printf("%.12g,", dsp->fVslider15);
        printf("%.12g,", dsp->fVslider14);
        printf("%.12g,", dsp->fVslider11);
        printf("%.12g,", dsp->fVslider13);
        printf("%.12g,", dsp->fVslider12);
        printf("%.12g,", dsp->fCheckbox8);
        printf("%.12g,", dsp->fVslider19);
        printf("%.12g,", dsp->fVslider18);
        printf("%.12g,", dsp->fVslider21);
        printf("%.12g,", dsp->fVslider20);
        printf("%.12g,", dsp->fCheckbox9);
        printf("%.12g,", dsp->fVslider25);
        printf("%.12g,", dsp->fVslider17);
        printf("%.12g,", dsp->fVslider24);
        printf("%.12g,", dsp->fVslider23);
        printf("%.12g,", dsp->fVslider16);
        printf("%.12g,", dsp->fVslider26);
        printf("%.12g,", dsp->fVslider22);
        printf("%.12g,", dsp->fVslider27);
        printf("%.12g,", dsp->fVslider28);
        printf("%.12g,", dsp->fCheckbox10);
        printf("%.12g,", dsp->fVslider29);
        printf("%.12g,", dsp->fVslider38);
        printf("%.12g,", dsp->fVslider31);
        printf("%.12g,", dsp->fVslider33);
        printf("%.12g,", dsp->fVslider37);
        printf("%.12g,", dsp->fVslider35);
        printf("%.12g,", dsp->fVslider4);
        printf("%.12g,", dsp->fVslider30);
        printf("%.12g,", dsp->fVslider3);
        printf("%.12g,", dsp->fVslider32);
        printf("%.12g,", dsp->fVslider34);
        printf("%.12g,", dsp->fVslider1);
        printf("%.12g,", dsp->fVslider36);
        printf("%.12g,", dsp->fVslider5);
        printf("%.12g,", dsp->fVslider39);
        printf("%.12g,", dsp->fCheckbox11);
        printf("%.12g,", dsp->fVslider46);
        printf("%.12g,", dsp->fVslider42);
        printf("%.12g,", dsp->fVslider45);
        printf("%.12g,", dsp->fVslider44);
        printf("%.12g,", dsp->fVslider41);
        printf("%.12g,", dsp->fVslider43);
        printf("%.12g,", dsp->fVslider40);
        printf("%.12g,", dsp->fCheckbox12);
        printf("%.12g,", dsp->fVslider0);
        printf("%.12g,", dsp->fVslider47);
        
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
        return d_version(1, 3, 2);
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
            return dsp->fVslider2;
        case kParameter_in_gain:
            return dsp->fVslider9;
        case kParameter_phase_l:
            return dsp->fCheckbox5;
        case kParameter_phase_r:
            return dsp->fCheckbox4;
        case kParameter_mono:
            return dsp->fCheckbox3;
        case kParameter_dc_blocker:
            return dsp->fCheckbox2;
        case kParameter_stereo_correct:
            return dsp->fCheckbox6;
        case kParameter_gate_bypass:
            return dsp->fCheckbox1;
        case kParameter_gate_threshold:
            return dsp->fVslider6;
        case kParameter_gate_attack:
            return dsp->fVslider7;
        case kParameter_gate_hold:
            return dsp->fVslider10;
        case kParameter_gate_release:
            return dsp->fVslider8;
        case kParameter_eq_bypass:
            return dsp->fCheckbox7;
        case kParameter_eq_highpass_freq:
            return dsp->fVslider15;
        case kParameter_eq_tilt_gain:
            return dsp->fVslider14;
        case kParameter_eq_side_gain:
            return dsp->fVslider11;
        case kParameter_eq_side_freq:
            return dsp->fVslider13;
        case kParameter_eq_side_bandwidth:
            return dsp->fVslider12;
        case kParameter_leveler_bypass:
            return dsp->fCheckbox8;
        case kParameter_leveler_speed:
            return dsp->fVslider19;
        case kParameter_leveler_brake_threshold:
            return dsp->fVslider18;
        case kParameter_leveler_max_plus:
            return dsp->fVslider21;
        case kParameter_leveler_max_minus:
            return dsp->fVslider20;
        case kParameter_kneecomp_bypass:
            return dsp->fCheckbox9;
        case kParameter_kneecomp_strength:
            return dsp->fVslider25;
        case kParameter_kneecomp_threshold:
            return dsp->fVslider17;
        case kParameter_kneecomp_attack:
            return dsp->fVslider24;
        case kParameter_kneecomp_release:
            return dsp->fVslider23;
        case kParameter_kneecomp_knee:
            return dsp->fVslider16;
        case kParameter_kneecomp_link:
            return dsp->fVslider26;
        case kParameter_kneecomp_fffb:
            return dsp->fVslider22;
        case kParameter_kneecomp_makeup:
            return dsp->fVslider27;
        case kParameter_kneecomp_drywet:
            return dsp->fVslider28;
        case kParameter_mscomp_bypass:
            return dsp->fCheckbox10;
        case kParameter_mscomp_low_strength:
            return dsp->fVslider29;
        case kParameter_mscomp_low_threshold:
            return dsp->fVslider38;
        case kParameter_mscomp_low_attack:
            return dsp->fVslider31;
        case kParameter_mscomp_low_release:
            return dsp->fVslider33;
        case kParameter_mscomp_low_knee:
            return dsp->fVslider37;
        case kParameter_mscomp_low_link:
            return dsp->fVslider35;
        case kParameter_mscomp_low_crossover:
            return dsp->fVslider4;
        case kParameter_mscomp_high_strength:
            return dsp->fVslider30;
        case kParameter_mscomp_high_threshold:
            return dsp->fVslider3;
        case kParameter_mscomp_high_attack:
            return dsp->fVslider32;
        case kParameter_mscomp_high_release:
            return dsp->fVslider34;
        case kParameter_mscomp_high_knee:
            return dsp->fVslider1;
        case kParameter_mscomp_high_link:
            return dsp->fVslider36;
        case kParameter_mscomp_high_crossover:
            return dsp->fVslider5;
        case kParameter_mscomp_output_gain:
            return dsp->fVslider39;
        case kParameter_limiter_bypass:
            return dsp->fCheckbox11;
        case kParameter_limiter_strength:
            return dsp->fVslider46;
        case kParameter_limiter_threshold:
            return dsp->fVslider42;
        case kParameter_limiter_attack:
            return dsp->fVslider45;
        case kParameter_limiter_release:
            return dsp->fVslider44;
        case kParameter_limiter_knee:
            return dsp->fVslider41;
        case kParameter_limiter_fffb:
            return dsp->fVslider43;
        case kParameter_limiter_makeup:
            return dsp->fVslider40;
        case kParameter_brickwall_bypass:
            return dsp->fCheckbox12;
        case kParameter_brickwall_ceiling:
            return dsp->fVslider0;
        case kParameter_brickwall_release:
            return dsp->fVslider47;
        case kParameter_peakmeter_in_l:
            return dsp->fVbargraph1;
        case kParameter_peakmeter_in_r:
            return dsp->fVbargraph0;
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
            return dsp->fVbargraph7;
        case kParameter_kneecomp_meter_1:
            return dsp->fVbargraph6;
        case kParameter_msredux11:
            return dsp->fVbargraph23;
        case kParameter_msredux12:
            return dsp->fVbargraph15;
        case kParameter_msredux21:
            return dsp->fVbargraph22;
        case kParameter_msredux22:
            return dsp->fVbargraph14;
        case kParameter_msredux31:
            return dsp->fVbargraph21;
        case kParameter_msredux32:
            return dsp->fVbargraph13;
        case kParameter_msredux41:
            return dsp->fVbargraph20;
        case kParameter_msredux42:
            return dsp->fVbargraph12;
        case kParameter_msredux51:
            return dsp->fVbargraph19;
        case kParameter_msredux52:
            return dsp->fVbargraph11;
        case kParameter_msredux61:
            return dsp->fVbargraph18;
        case kParameter_msredux62:
            return dsp->fVbargraph10;
        case kParameter_msredux71:
            return dsp->fVbargraph17;
        case kParameter_msredux72:
            return dsp->fVbargraph9;
        case kParameter_msredux81:
            return dsp->fVbargraph16;
        case kParameter_msredux82:
            return dsp->fVbargraph8;
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
            dsp->fVslider2 = value;
            break;
        case kParameter_in_gain:
            dsp->fVslider9 = value;
            break;
        case kParameter_phase_l:
            dsp->fCheckbox5 = value;
            break;
        case kParameter_phase_r:
            dsp->fCheckbox4 = value;
            break;
        case kParameter_mono:
            dsp->fCheckbox3 = value;
            break;
        case kParameter_dc_blocker:
            dsp->fCheckbox2 = value;
            break;
        case kParameter_stereo_correct:
            dsp->fCheckbox6 = value;
            break;
        case kParameter_gate_bypass:
            dsp->fCheckbox1 = value;
            break;
        case kParameter_gate_threshold:
            dsp->fVslider6 = value;
            break;
        case kParameter_gate_attack:
            dsp->fVslider7 = value;
            break;
        case kParameter_gate_hold:
            dsp->fVslider10 = value;
            break;
        case kParameter_gate_release:
            dsp->fVslider8 = value;
            break;
        case kParameter_eq_bypass:
            dsp->fCheckbox7 = value;
            break;
        case kParameter_eq_highpass_freq:
            dsp->fVslider15 = value;
            break;
        case kParameter_eq_tilt_gain:
            dsp->fVslider14 = value;
            break;
        case kParameter_eq_side_gain:
            dsp->fVslider11 = value;
            break;
        case kParameter_eq_side_freq:
            dsp->fVslider13 = value;
            break;
        case kParameter_eq_side_bandwidth:
            dsp->fVslider12 = value;
            break;
        case kParameter_leveler_bypass:
            dsp->fCheckbox8 = value;
            break;
        case kParameter_leveler_speed:
            dsp->fVslider19 = value;
            break;
        case kParameter_leveler_brake_threshold:
            dsp->fVslider18 = value;
            break;
        case kParameter_leveler_max_plus:
            dsp->fVslider21 = value;
            break;
        case kParameter_leveler_max_minus:
            dsp->fVslider20 = value;
            break;
        case kParameter_kneecomp_bypass:
            dsp->fCheckbox9 = value;
            break;
        case kParameter_kneecomp_strength:
            dsp->fVslider25 = value;
            break;
        case kParameter_kneecomp_threshold:
            dsp->fVslider17 = value;
            break;
        case kParameter_kneecomp_attack:
            dsp->fVslider24 = value;
            break;
        case kParameter_kneecomp_release:
            dsp->fVslider23 = value;
            break;
        case kParameter_kneecomp_knee:
            dsp->fVslider16 = value;
            break;
        case kParameter_kneecomp_link:
            dsp->fVslider26 = value;
            break;
        case kParameter_kneecomp_fffb:
            dsp->fVslider22 = value;
            break;
        case kParameter_kneecomp_makeup:
            dsp->fVslider27 = value;
            break;
        case kParameter_kneecomp_drywet:
            dsp->fVslider28 = value;
            break;
        case kParameter_mscomp_bypass:
            dsp->fCheckbox10 = value;
            break;
        case kParameter_mscomp_low_strength:
            dsp->fVslider29 = value;
            break;
        case kParameter_mscomp_low_threshold:
            dsp->fVslider38 = value;
            break;
        case kParameter_mscomp_low_attack:
            dsp->fVslider31 = value;
            break;
        case kParameter_mscomp_low_release:
            dsp->fVslider33 = value;
            break;
        case kParameter_mscomp_low_knee:
            dsp->fVslider37 = value;
            break;
        case kParameter_mscomp_low_link:
            dsp->fVslider35 = value;
            break;
        case kParameter_mscomp_low_crossover:
            dsp->fVslider4 = value;
            break;
        case kParameter_mscomp_high_strength:
            dsp->fVslider30 = value;
            break;
        case kParameter_mscomp_high_threshold:
            dsp->fVslider3 = value;
            break;
        case kParameter_mscomp_high_attack:
            dsp->fVslider32 = value;
            break;
        case kParameter_mscomp_high_release:
            dsp->fVslider34 = value;
            break;
        case kParameter_mscomp_high_knee:
            dsp->fVslider1 = value;
            break;
        case kParameter_mscomp_high_link:
            dsp->fVslider36 = value;
            break;
        case kParameter_mscomp_high_crossover:
            dsp->fVslider5 = value;
            break;
        case kParameter_mscomp_output_gain:
            dsp->fVslider39 = value;
            break;
        case kParameter_limiter_bypass:
            dsp->fCheckbox11 = value;
            break;
        case kParameter_limiter_strength:
            dsp->fVslider46 = value;
            break;
        case kParameter_limiter_threshold:
            dsp->fVslider42 = value;
            break;
        case kParameter_limiter_attack:
            dsp->fVslider45 = value;
            break;
        case kParameter_limiter_release:
            dsp->fVslider44 = value;
            break;
        case kParameter_limiter_knee:
            dsp->fVslider41 = value;
            break;
        case kParameter_limiter_fffb:
            dsp->fVslider43 = value;
            break;
        case kParameter_limiter_makeup:
            dsp->fVslider40 = value;
            break;
        case kParameter_brickwall_bypass:
            dsp->fCheckbox12 = value;
            break;
        case kParameter_brickwall_ceiling:
            dsp->fVslider0 = value;
            break;
        case kParameter_brickwall_release:
            dsp->fVslider47 = value;
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
            dsp->fVslider2,
            dsp->fVslider9,
            dsp->fCheckbox5,
            dsp->fCheckbox4,
            dsp->fCheckbox3,
            dsp->fCheckbox2,
            dsp->fCheckbox6,
            dsp->fCheckbox1,
            dsp->fVslider6,
            dsp->fVslider7,
            dsp->fVslider10,
            dsp->fVslider8,
            dsp->fCheckbox7,
            dsp->fVslider15,
            dsp->fVslider14,
            dsp->fVslider11,
            dsp->fVslider13,
            dsp->fVslider12,
            dsp->fCheckbox8,
            dsp->fVslider19,
            dsp->fVslider18,
            dsp->fVslider21,
            dsp->fVslider20,
            dsp->fCheckbox9,
            dsp->fVslider25,
            dsp->fVslider17,
            dsp->fVslider24,
            dsp->fVslider23,
            dsp->fVslider16,
            dsp->fVslider26,
            dsp->fVslider22,
            dsp->fVslider27,
            dsp->fVslider28,
            dsp->fCheckbox10,
            dsp->fVslider29,
            dsp->fVslider38,
            dsp->fVslider31,
            dsp->fVslider33,
            dsp->fVslider37,
            dsp->fVslider35,
            dsp->fVslider4,
            dsp->fVslider30,
            dsp->fVslider3,
            dsp->fVslider32,
            dsp->fVslider34,
            dsp->fVslider1,
            dsp->fVslider36,
            dsp->fVslider5,
            dsp->fVslider39,
            dsp->fCheckbox11,
            dsp->fVslider46,
            dsp->fVslider42,
            dsp->fVslider45,
            dsp->fVslider44,
            dsp->fVslider41,
            dsp->fVslider43,
            dsp->fVslider40,
            dsp->fCheckbox12,
            dsp->fVslider0,
            dsp->fVslider47,
            
        };

        // tell dsp to change sample rate
        dsp->init(newSampleRate);

        // set parameters back, which have been reset in the dsp
        dsp->fCheckbox0 = params[0];
        dsp->fVslider2 = params[1];
        dsp->fVslider9 = params[2];
        dsp->fCheckbox5 = params[3];
        dsp->fCheckbox4 = params[4];
        dsp->fCheckbox3 = params[5];
        dsp->fCheckbox2 = params[6];
        dsp->fCheckbox6 = params[7];
        dsp->fCheckbox1 = params[8];
        dsp->fVslider6 = params[9];
        dsp->fVslider7 = params[10];
        dsp->fVslider10 = params[11];
        dsp->fVslider8 = params[12];
        dsp->fCheckbox7 = params[13];
        dsp->fVslider15 = params[14];
        dsp->fVslider14 = params[15];
        dsp->fVslider11 = params[16];
        dsp->fVslider13 = params[17];
        dsp->fVslider12 = params[18];
        dsp->fCheckbox8 = params[19];
        dsp->fVslider19 = params[20];
        dsp->fVslider18 = params[21];
        dsp->fVslider21 = params[22];
        dsp->fVslider20 = params[23];
        dsp->fCheckbox9 = params[24];
        dsp->fVslider25 = params[25];
        dsp->fVslider17 = params[26];
        dsp->fVslider24 = params[27];
        dsp->fVslider23 = params[28];
        dsp->fVslider16 = params[29];
        dsp->fVslider26 = params[30];
        dsp->fVslider22 = params[31];
        dsp->fVslider27 = params[32];
        dsp->fVslider28 = params[33];
        dsp->fCheckbox10 = params[34];
        dsp->fVslider29 = params[35];
        dsp->fVslider38 = params[36];
        dsp->fVslider31 = params[37];
        dsp->fVslider33 = params[38];
        dsp->fVslider37 = params[39];
        dsp->fVslider35 = params[40];
        dsp->fVslider4 = params[41];
        dsp->fVslider30 = params[42];
        dsp->fVslider3 = params[43];
        dsp->fVslider32 = params[44];
        dsp->fVslider34 = params[45];
        dsp->fVslider1 = params[46];
        dsp->fVslider36 = params[47];
        dsp->fVslider5 = params[48];
        dsp->fVslider39 = params[49];
        dsp->fCheckbox11 = params[50];
        dsp->fVslider46 = params[51];
        dsp->fVslider42 = params[52];
        dsp->fVslider45 = params[53];
        dsp->fVslider44 = params[54];
        dsp->fVslider41 = params[55];
        dsp->fVslider43 = params[56];
        dsp->fVslider40 = params[57];
        dsp->fCheckbox12 = params[58];
        dsp->fVslider0 = params[59];
        dsp->fVslider47 = params[60];
        
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