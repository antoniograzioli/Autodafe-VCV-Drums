#include "rack.hpp"


using namespace rack;


////////////////////
// module widgets
////////////////////

extern Plugin *pluginInstance;






extern Model *modelDrumsKick;

extern Model *modelDrumsSnare;

extern Model *modelDrumsHiHatClosed;

extern Model *modelDrumsHiHatOpen;

extern Model *modelDrumsClaps;

extern Model *modelDrumsCymbals;

extern Model *modelDrumsRide;

extern Model *modelDrumsRimClaves;

extern Model *modelDrumsMixer;
















struct AutodafeKnobBrown : SvgKnob {
	AutodafeKnobBrown() {
		box.size = Vec(20, 20);
		minAngle = -0.75*M_PI;
		maxAngle = 0.75*M_PI;
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/AutodafeKnobBrown.svg")));
	}
};




struct AutodafeKnobBrownBig : SvgKnob {
	AutodafeKnobBrownBig() {
		box.size = Vec(35, 35);
		minAngle = -0.75*M_PI;
		maxAngle = 0.75*M_PI;
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/AutodafeKnobBrownBig.svg")));
	}
};

