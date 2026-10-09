#include "Autodafe.hpp"
#include "snares.h"
#include "RawSamplePlayer.hpp"



struct DrumsSnare : Module {
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
    
	
	DrumsSnare() {
		players[0].setSample(SNARE_sample1, SNARE_sample1_len);
		players[1].setSample(SNARE_sample2, SNARE_sample2_len);
		players[2].setSample(SNARE_sample3, SNARE_sample3_len);
		players[3].setSample(SNARE_sample4, SNARE_sample4_len);
		players[4].setSample(SNARE_sample5, SNARE_sample5_len);
		players[5].setSample(SNARE_sample6, SNARE_sample6_len);
		players[6].setSample(SNARE_sample7, SNARE_sample7_len);
		players[7].setSample(SNARE_sample8, SNARE_sample8_len);
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

configParam(DrumsSnare::SAMPLETYPE, 0.0, 1.0, 0.0, "");


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








void DrumsSnare::process(const ProcessArgs &args)
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

struct DrumsSnareWidget : ModuleWidget {
    DrumsSnareWidget(DrumsSnare *module);
};

    DrumsSnareWidget::DrumsSnareWidget(DrumsSnare *module) {
		setModule(module);


	box.size = Vec(15 * 4, 380);

	{
        SvgPanel *panel = new SvgPanel();
        panel->box.size = box.size;
        panel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DrumsSnare.svg")));
        
        addChild(panel);
	}

	addChild(createWidget<ScrewSilver>(Vec(15,   0)));
	addChild(createWidget<ScrewSilver>(Vec(15, 365)));
    
    addParam(createParam<LEDButton>(Vec(21, 60), module, DrumsSnare::SAMPLETYPE));
    
    
    

    addChild(createLight<SmallLight<GreenLight>>(Vec(10,100), module, DrumsSnare::SAMPLETYPE_LIGHT+0));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,125),  module, DrumsSnare::SAMPLETYPE_LIGHT+1));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,150),  module, DrumsSnare::SAMPLETYPE_LIGHT+2));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,175),  module, DrumsSnare::SAMPLETYPE_LIGHT+3));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,200),  module, DrumsSnare::SAMPLETYPE_LIGHT+4));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,225),  module, DrumsSnare::SAMPLETYPE_LIGHT+5));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,250),  module, DrumsSnare::SAMPLETYPE_LIGHT+6));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,275), module, DrumsSnare::SAMPLETYPE_LIGHT+7));

    

	addInput (createInput <PJ3410Port>(Vec( 0, 300), module, DrumsSnare::TRIG_INPUT));
	addOutput(createOutput <PJ3410Port>(Vec(30, 300), module, DrumsSnare::AUDIO_OUTPUT));

}
Model *modelDrumsSnare = createModel<DrumsSnare, DrumsSnareWidget>("DrumsSnare");
