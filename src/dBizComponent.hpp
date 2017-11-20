#pragma once
#include "app.hpp"
#include "asset.hpp"


namespace rack {
////////////////////
// Colors
////////////////////

#define COLOR_BLACK_TRANSPARENT nvgRGBA(0x00, 0x00, 0x00, 0x00)
#define COLOR_BLACK nvgRGB(0x00, 0x00, 0x00)
#define COLOR_WHITE nvgRGB(0xff, 0xff, 0xff)
#define COLOR_RED nvgRGB(0xed, 0x2c, 0x24)
#define COLOR_ORANGE nvgRGB(0xf2, 0xb1, 0x20)
#define COLOR_YELLOW nvgRGB(0xf9, 0xdf, 0x1c)
#define COLOR_GREEN nvgRGB(0x90, 0xc7, 0x3e)
#define COLOR_CYAN nvgRGB(0x22, 0xe6, 0xef)
#define COLOR_BLUE nvgRGB(0x29, 0xb2, 0xef)
#define COLOR_PURPLE nvgRGB(0xd5, 0x2b, 0xed)

////////////////////
// Knobs
////////////////////
struct VerboL : SVGKnob {
	VerboL() {
		minAngle = -0.83*M_PI;
		maxAngle = 0.83*M_PI;
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/knobs/VerboL.svg")));
		box.size = Vec(80, 80);
	}
};

struct VerboS : SVGKnob {
	VerboS() {
		minAngle = -0.83*M_PI;
		maxAngle = 0.83*M_PI;
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/knobs/VerboS.svg")));
		box.size = Vec(35, 35);
	}
};



struct SmallKnob : SVGKnob {
	SmallKnob() {
		minAngle = -0.83*M_PI;
		maxAngle = 0.83*M_PI;
	}
};


struct SmallOra : SmallKnob {
	SmallOra() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/knobs/SmallOra.svg")));
	}
};

struct SmallOraSnapKnob : SmallOra {
	SmallOraSnapKnob() {
		snap = true;
	};
};

struct LargeOra : SmallOra {
	LargeOra() {
		box.size = Vec(45, 45);
	}
};
struct MicroOra : SmallOra
{
	MicroOra()
	{
		box.size = Vec(25, 25);
	}
};

struct SmallBlu : SmallKnob {
	SmallBlu() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/SmallBlu.svg")));
	}
};
struct MicroBlu : SmallBlu
{
	MicroBlu()
	{
		box.size = Vec(25, 25);
	}
};

struct LargeBlu : SmallBlu {
	LargeBlu() {
		box.size = Vec(45, 45);
	}
};

struct SmallAzz : SmallKnob {
	SmallAzz() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/SmallAzz.svg")));
	}
};

struct LargeAzz : SmallAzz {
	LargeAzz() {
		box.size = Vec(45, 45);
	}
};

struct SmallAzzSnapKnob : SmallAzz {
	SmallAzzSnapKnob() {
		snap = true;
	};
};

struct SmallVio : SmallKnob {
	SmallVio() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/SmallVio.svg")));
	}
};

struct LargeVio : SmallVio {
	LargeVio() {
		box.size = Vec(45, 45);
	}
};	

struct SmallVioSnapKnob : SmallVio {
	SmallVioSnapKnob() {
		snap = true;
	};
};

struct SmallYel : SmallKnob {
	SmallYel() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/SmallYel.svg")));
	}
};

struct LargeYel : SmallYel {
	LargeYel() {
		box.size = Vec(45, 45);
	}
};

struct SmallGre : SmallKnob {
	SmallGre() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/SmallGre.svg")));
	}
};

struct LargeGre : SmallGre {
	LargeGre() {
		box.size = Vec(45, 45);
	}
};

struct SmallCre : SmallKnob {
	SmallCre() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/SmallCre.svg")));
	}
};

struct LargeCre : SmallCre {
	LargeCre() {
		box.size = Vec(45, 45);
	}
};

struct SmallBla : SmallKnob {
	SmallBla() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/SmallBla.svg")));
	}
};

struct LargeBla : SmallBla {
	LargeBla() {
		box.size = Vec(45, 45);
	}
};


struct DaviesKnob : SVGKnob {
	DaviesKnob() {
		minAngle = -0.83*M_PI;
		maxAngle = 0.83*M_PI;
		box.size = Vec(15, 15);
	}
};

struct DaviesGre : DaviesKnob {
	DaviesGre() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/DaviesGre.svg")));
	}
};
struct LDaviesGre : DaviesGre {
		LDaviesGre() {
		box.size = Vec(45, 45);	
	}
};

struct DaviesWhy : DaviesKnob
{
	DaviesWhy()
	{
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/DaviesWhy.svg")));
	}
};
struct LDaviesWhy : DaviesWhy
{
	LDaviesWhy()
	{
		box.size = Vec(45, 45);
	}
};

struct DaviesWhySnapKnob : DaviesWhy {
	DaviesWhySnapKnob() {
		snap = true;
	};
};

struct DaviesAzz : DaviesKnob {
	DaviesAzz() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/DaviesAzz.svg")));
	}
};
struct LDaviesAzz : DaviesAzz {
		LDaviesAzz() {
		box.size = Vec(45, 45);	
	}
};

struct DaviesPur : DaviesKnob {
	DaviesPur() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/DaviesPur.svg")));
	}
};
struct LDaviesPur : DaviesPur {
		LDaviesPur() {
		box.size = Vec(45, 45);	
	}
};

struct DaviesBlu : DaviesKnob {
	DaviesBlu() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/DaviesBlu.svg")));
	}
};
struct LDaviesBlu : DaviesBlu {
		LDaviesBlu() {
		box.size = Vec(45, 45);	
	}
};

struct DaviesRed : DaviesKnob {
	DaviesRed() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/DaviesRed.svg")));
	}
};
struct LDaviesRed : DaviesRed {
		LDaviesRed() {
		box.size = Vec(45, 45);	
	}
};

struct DaviesYel : DaviesKnob {
	DaviesYel() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/DaviesYel.svg")));
	}
};
struct LDaviesYel : DaviesYel {
		LDaviesYel() {
		box.size = Vec(45, 45);	
	}
};


struct RoundAzz : DaviesKnob {
	RoundAzz() {
		box.size = Vec(30, 30);
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/RoundAzz.svg")));
	}
};
struct RoundRed : DaviesKnob
{
	RoundRed(){
		box.size = Vec(30, 30);
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/RoundRed.svg")));
	}
};
struct RoundWhy : DaviesKnob
{
	RoundWhy(){
	box.size = Vec(30, 30);
	setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/RoundWhy.svg")));
	}
};

struct RoundWhySnapKnob : RoundWhy {
	RoundWhySnapKnob() {
		snap = true;
	};
};

struct LRoundWhy : RoundWhy {
	LRoundWhy() {
		box.size = Vec (45,45);
	}
};

struct RoundBlu : DaviesKnob {
	RoundBlu() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/RoundBlu.svg")));
	}
};

struct LRoundBlu : RoundBlu {
	LRoundBlu() {
		box.size = Vec (45,45);
	}
};

struct FlatA : DaviesKnob {
	FlatA() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/FlatA.svg")));
		box.size = Vec (30,30);
	}
};
struct FlatASnap : FlatA {
	FlatASnap() {
		snap = true;
	}
};

struct FlatR : DaviesKnob {
	FlatR() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/FlatR.svg")));
		box.size = Vec (30,30);

	}
};
struct FlatS : DaviesKnob {
	FlatS() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/FlatS.svg")));
		box.size = Vec (30,30);

	}
};
struct FlatG : DaviesKnob {
	FlatG() {
		setSVG(SVG::load(assetGlobal("plugins/dBiz/res/Knobs/FlatG.svg")));
		box.size = Vec (30,30);

	}
};

// struct DaviesKnobSnapKnob : DaviesKnob, SnapKnob {};

//////////////////////
//slider
///////////////////

struct SlidePot : SVGSlider {
	SlidePot() {
		Vec margin = Vec(3.5, 3.5);
		maxHandlePos = Vec(-1, -2).plus(margin);
		minHandlePos = Vec(-1, 87).plus(margin);
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/Slider/SlidePot.svg"));
		background->wrap();
		background->box.pos = margin;
		box.size = background->box.size.plus(margin.mult(2));
		handle->svg = SVG::load(assetGlobal("plugins/dBiz/res/Slider/SlidePotHandle.svg"));
		handle->wrap();
	}
};

struct SlidePot2 : SVGSlider
{
	SlidePot2()
	{
		Vec margin = Vec(3.5, 3.5);
		maxHandlePos = Vec(-10, -2).plus(margin);
		minHandlePos = Vec(-10, 87).plus(margin);
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/Slider/SlidePot.svg"));
		background->wrap();
		background->box.pos = margin;
		box.size = background->box.size.plus(margin.mult(2));
		handle->svg = SVG::load(assetGlobal("plugins/dBiz/res/Slider/SlidePotHandle2.svg"));
		handle->wrap();
	}
};
////////////////////
// Lights
////////////////////
struct OrangeLight : ModuleLightWidget
{
	OrangeLight()
	{
		addBaseColor(COLOR_ORANGE);
	}
};

struct CyanLight : ModuleLightWidget
{
	CyanLight()
	{
		addBaseColor(COLOR_CYAN);
	}
};


struct PurpleLight : ModuleLightWidget
{
	PurpleLight()
	{
		addBaseColor(COLOR_PURPLE);
	}
};

template <typename BASE>
struct BigLight : BASE
{
	BigLight()
	{
		this->box.size = Vec(20, 20);
	}
};
template <typename BASE>
struct HugeLight : BASE
{
	HugeLight()
	{
		this->box.size = Vec(24, 24);
	}
};

struct OBPLight : ModuleLightWidget
{
	OBPLight()
	{
		addBaseColor(COLOR_ORANGE);
		addBaseColor(COLOR_BLUE);
		addBaseColor(COLOR_PURPLE);
	}
};

////////////////////
// Jacks
////////////////////

struct PJ301MRPort : SVGPort {
	PJ301MRPort() {
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/jack/PJ301MR.svg"));
		background->wrap();
		box.size = background->box.size;
	}
};

struct PJ301MLPort : SVGPort {
	PJ301MLPort() {
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/jack/PJ301ML.svg"));
		background->wrap();
		box.size = background->box.size;
	}
};

struct PJ301MIPort : SVGPort {
	PJ301MIPort() {
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/jack/PJ301MA.svg"));
		background->wrap();
		box.size = background->box.size;
	}
};

struct PJ301MOrPort : SVGPort
{
	PJ301MOrPort()
	{
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/jack/PJ301MO.svg"));
		background->wrap();
		box.size = background->box.size;
	}
};

struct PJ301MOPort : SVGPort {
	PJ301MOPort() {
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/jack/PJ301MB.svg"));
		background->wrap();
		box.size = background->box.size;
	}
};

struct PJ301MCPort : SVGPort {
	PJ301MCPort() {
		background->svg = SVG::load(assetGlobal("plugins/dBiz/res/jack/PJ301MW.svg"));
		background->wrap();
		box.size = background->box.size;
	}
};



//
////////////////////////
//  SWITCHES
////////////////////////////////////////////////

struct CKSSS : SVGSwitch, ToggleSwitch
{
	CKSSS()
	{
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/CKSS_0.svg")));
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/CKSS_1.svg")));
	}
};

struct LEDB : SVGSwitch, ToggleSwitch
{
	LEDB()
	{
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/LEDB_0.svg")));
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/LEDB_1.svg")));
	}
};

struct MCKSSS : SVGSwitch, ToggleSwitch
{
	MCKSSS()
	{
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/MCKSSS_0.svg")));
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/MCKSSS_1.svg")));
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/MCKSSS_2.svg")));
	}
};

struct BPush : SVGSwitch, MomentarySwitch
{
	BPush()
	{
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/BPush_0.svg")));
		addFrame(SVG::load(assetGlobal("plugins/dBiz/res/switch/BPush_1.svg")));
	}
};
}

