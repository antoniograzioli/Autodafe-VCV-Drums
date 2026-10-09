#include "Autodafe.hpp"
#include "kicks.h"
#include "RawSamplePlayer.hpp"



struct DrumsKick : Module {
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
    
    
	
	DrumsKick() {
		players[0].setSample(KICK_sample1, KICK_sample1_len);
		players[1].setSample(KICK_sample2, KICK_sample2_len);
		players[2].setSample(KICK_sample3, KICK_sample3_len);
		players[3].setSample(KICK_sample4, KICK_sample4_len);
		players[4].setSample(KICK_sample5, KICK_sample5_len);
		players[5].setSample(KICK_sample6, KICK_sample6_len);
		players[6].setSample(KICK_sample7, KICK_sample7_len);
		players[7].setSample(KICK_sample8, KICK_sample8_len);


	config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

      configParam(DrumsKick::SAMPLETYPE, 0.0, 1.0, 0.0, "");

    }

      



	void process(const ProcessArgs &args) override;



    


    json_t *dataToJson() override {
                json_t *rootJ = json_object();

                json_object_set_new(rootJ, "sampletype", json_integer(sampletype));

                return rootJ;
        }

        void dataFromJson(json_t *rootJ) override {
                json_t *stateJ = json_object_get(rootJ, "sampletype");
                if (stateJ) {
                        sampletype = json_integer_value(stateJ);
                }


                
        }


    
};







void DrumsKick::process(const ProcessArgs &args)
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

struct DrumsKickWidget : ModuleWidget {
    DrumsKickWidget(DrumsKick *module);
};

    DrumsKickWidget::DrumsKickWidget(DrumsKick *module) {
		setModule(module);


 

	box.size = Vec(15 * 4, 380);

	{
        SvgPanel *panel = new SvgPanel();
        panel->box.size = box.size;
        panel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DrumsKick.svg")));
        
        addChild(panel);
	}  

	addChild(createWidget<ScrewSilver>(Vec(2,   0)));
	addChild(createWidget<ScrewSilver>(Vec(2, 365)));
    
    addParam(createParam<LEDButton>(Vec(21, 60), module, DrumsKick::SAMPLETYPE));
    
    
    
    
       addChild(createLight<SmallLight<GreenLight>>(Vec(10,100), module, DrumsKick::SAMPLETYPE_LIGHT+0));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,125),  module, DrumsKick::SAMPLETYPE_LIGHT+1));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,150),  module, DrumsKick::SAMPLETYPE_LIGHT+2));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,175),  module, DrumsKick::SAMPLETYPE_LIGHT+3));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,200),  module, DrumsKick::SAMPLETYPE_LIGHT+4));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,225),  module, DrumsKick::SAMPLETYPE_LIGHT+5));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,250),  module, DrumsKick::SAMPLETYPE_LIGHT+6));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,275), module, DrumsKick::SAMPLETYPE_LIGHT+7));

    

	addInput (createInput <PJ3410Port>(Vec( 0, 300), module, DrumsKick::TRIG_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(30, 300), module, DrumsKick::AUDIO_OUTPUT));

}


Model *modelDrumsKick = createModel<DrumsKick, DrumsKickWidget>("DrumsKick");



