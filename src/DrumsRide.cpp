#include "Autodafe.hpp"
#include "rides.h"
#include "RawSamplePlayer.hpp"



struct DrumsRide : Module {
	enum ParamIds {
        SAMPLETYPE,
     
		NUM_PARAMS
	};
	enum InputIds {
		TRIG_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		AUDIO_OUTPUT,
		NUM_OUTPUTS
	};

enum LightIds {
    SAMPLETYPE_LIGHT,
    NUM_LIGHTS=SAMPLETYPE_LIGHT + 8
    };
	static constexpr int numSamples = 8;
	dsp::SchmittTrigger trigger;
	dsp::SchmittTrigger sampletypeselector;
    int sampletype = 1;
	RawSamplePlayer players[numSamples];

	
	DrumsRide() {
		players[0].setSample(RIDE_sample1, RIDE_sample1_len);
		players[1].setSample(RIDE_sample2, RIDE_sample2_len);
		players[2].setSample(RIDE_sample3, RIDE_sample3_len);
		players[3].setSample(RIDE_sample4, RIDE_sample4_len);
		players[4].setSample(RIDE_sample5, RIDE_sample5_len);
		players[5].setSample(RIDE_sample6, RIDE_sample6_len);
		players[6].setSample(RIDE_sample7, RIDE_sample7_len);
		players[7].setSample(RIDE_sample8, RIDE_sample8_len);
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

 configParam(DrumsRide::SAMPLETYPE, 0.0, 1.0, 0.0, "");



    }


       


	void process(const ProcessArgs &args) override;




    json_t *dataToJson() override{
                json_t *rootJ = json_object();

                json_object_set_new(rootJ, "sampletype", json_integer(sampletype));

                return rootJ;
        }

        void dataFromJson(json_t *rootJ) override{
                json_t *stateJ = json_object_get(rootJ, "sampletype");
                if (stateJ) {
                        sampletype = json_integer_value(stateJ);
                }
        }

    
    
};









void DrumsRide::process(const ProcessArgs &args)
{
	if (sampletypeselector.process(params[SAMPLETYPE].getValue())) {
		if (sampletype < numSamples)
			sampletype++;
		else
			sampletype = 1;
	}

	for (int i = 0; i < numSamples; i++)
		lights[SAMPLETYPE_LIGHT + i].setBrightness(0.0f);
	lights[SAMPLETYPE_LIGHT + sampletype - 1].setBrightness(1.0f);

	if (trigger.process(inputs[TRIG_INPUT].getVoltage())) {
		for (RawSamplePlayer &player : players)
			player.reset();
	}

	outputs[AUDIO_OUTPUT].setVoltage(5.0f * players[sampletype - 1].next(args.sampleRate));
}

struct DrumsRideWidget : ModuleWidget {
    DrumsRideWidget(DrumsRide *module);
};

    DrumsRideWidget::DrumsRideWidget(DrumsRide *module) {
		setModule(module);




	box.size = Vec(15 * 4, 380);

	{
        SvgPanel *panel = new SvgPanel();
        panel->box.size = box.size;
        panel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DrumsRide.svg")));
        
        addChild(panel);
	}

	addChild(createWidget<ScrewSilver>(Vec(15,   0)));
	addChild(createWidget<ScrewSilver>(Vec(15, 365)));
    
    addParam(createParam<LEDButton>(Vec(21, 60), module, DrumsRide::SAMPLETYPE));
    
    
        addChild(createLight<SmallLight<GreenLight>>(Vec(10,100), module, DrumsRide::SAMPLETYPE_LIGHT+0));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,125),  module, DrumsRide::SAMPLETYPE_LIGHT+1));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,150),  module, DrumsRide::SAMPLETYPE_LIGHT+2));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,175),  module, DrumsRide::SAMPLETYPE_LIGHT+3));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,200),  module, DrumsRide::SAMPLETYPE_LIGHT+4));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,225),  module, DrumsRide::SAMPLETYPE_LIGHT+5));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,250),  module, DrumsRide::SAMPLETYPE_LIGHT+6));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,275), module, DrumsRide::SAMPLETYPE_LIGHT+7));
    

	addInput (createInput <PJ3410Port>(Vec( 0, 300), module, DrumsRide::TRIG_INPUT));
	addOutput(createOutput <PJ3410Port>(Vec(30, 300), module, DrumsRide::AUDIO_OUTPUT));

}



Model *modelDrumsRide = createModel<DrumsRide, DrumsRideWidget>("DrumsRide");

