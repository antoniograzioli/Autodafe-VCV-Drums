#include "Autodafe.hpp"
#include "cymbals.h"



struct DrumsCymbals : Module {
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


    int numsamples = 8;
	dsp::SchmittTrigger trigger;
	dsp::SchmittTrigger sampletypeselector;
    int sampletype = 1;
   
   unsigned count1  = CYMB_sample1_len;
     unsigned count2  = CYMB_sample2_len;
     unsigned count3  = CYMB_sample3_len;
     unsigned count4  = CYMB_sample4_len;
     unsigned count5  = CYMB_sample5_len;
     unsigned count6  = CYMB_sample6_len;
     unsigned count7  = CYMB_sample7_len;
     unsigned count8  = CYMB_sample8_len;
   

	
	DrumsCymbals() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

configParam(DrumsCymbals::SAMPLETYPE, 0.0, 1.0, 0.0, "");
//configParam(DrumsCymbals::PITCH, -12, 12.0, 0.0, "");
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










void DrumsCymbals::process(const ProcessArgs &args)
{
    
    

   
    
    if (sampletypeselector.process(params[SAMPLETYPE].getValue()))
    { 
        
         if (sampletype<numsamples) {
        sampletype++;
            
         }
        else
        {
            sampletype=1;
        }
    }
    for (int i = 0; i < numsamples; i++) {
         lights[SAMPLETYPE_LIGHT+i].value=0.0;
    }
   
    
  lights[SAMPLETYPE_LIGHT + sampletype - 1].value=1.0;

    
	if (trigger.process(inputs[TRIG_INPUT].getVoltage())) {
		count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        count5 = 0;
        count6 = 0;
        count7 = 0;
        count8 = 0;
        
	}
    
    
	if (sampletype == 1)
    {
                if( count1 < CYMB_sample1_len ) {
                    int16_t sample;
                    sample  = CYMB_sample1[count1++];
                    sample |= CYMB_sample1[count1++] << 8;
                    
                    outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / CYMB_sample1_len  ;
                } else {
                    outputs[AUDIO_OUTPUT].value=  0.0 ;
                }
    }
    
    
    
    
    if (sampletype == 2)
    {
        if( count2 < CYMB_sample2_len ) {
            int16_t sample;
            sample  = CYMB_sample2[count2++];
            sample |= CYMB_sample2[count2++] << 8;
            
            outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / CYMB_sample2_len ;
        } else {
            outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
    
    
    
    if (sampletype == 3)
    {
        if( count3 < CYMB_sample3_len ) {
            int16_t sample;
            sample  = CYMB_sample3[count3++];
            sample |= CYMB_sample3[count3++] << 8;
            
           outputs[AUDIO_OUTPUT].value=  5.0 * (float)sample / CYMB_sample3_len ;
        } else {
            outputs[AUDIO_OUTPUT].value=  0.0 ;
        }
    }
    
    
    
    
    
    
    if (sampletype == 4)
    {
        if( count4 < CYMB_sample4_len ) {
            int16_t sample;
            sample  = CYMB_sample4[count4++];
            sample |= CYMB_sample4[count4++] << 8;
            
            outputs[AUDIO_OUTPUT].value=  5.0 * (float)sample / CYMB_sample4_len ;
        } else {
            outputs[AUDIO_OUTPUT].value=  0.0 ;
        }
    }
    
    
    
    if (sampletype == 5)
    {
        if( count5 < CYMB_sample5_len ) {
            int16_t sample;
            sample  = CYMB_sample5[count5++];
            sample |= CYMB_sample5[count5++] << 8;
            
            outputs[AUDIO_OUTPUT].value=  5.0 * (float)sample / CYMB_sample5_len ;
        } else {
            outputs[AUDIO_OUTPUT].value=  0.0 ;
        }
    }
    
    
    
    if (sampletype == 6)
    {
        if( count6 < CYMB_sample6_len ) {
            int16_t sample;
            sample  = CYMB_sample6[count6++];
            sample |= CYMB_sample6[count6++] << 8;
            
            outputs[AUDIO_OUTPUT].value=  5.0 * (float)sample / CYMB_sample6_len ;
        } else {
            outputs[AUDIO_OUTPUT].value=  0.0 ;
        }
    }
    
    
    
    if (sampletype == 7)
    {
        if( count7 < CYMB_sample7_len ) {
            int16_t sample;
            sample  = CYMB_sample7[count7++];
            sample |= CYMB_sample7[count7++] << 8;
            
            outputs[AUDIO_OUTPUT].value=  5.0 * (float)sample / CYMB_sample7_len ;
        } else {
           outputs[AUDIO_OUTPUT].value=  0.0 ;
        }
    }
   
    
    
    
    if (sampletype == 8)
    {
        if( count8 < CYMB_sample8_len ) {
            int16_t sample;
            sample  = CYMB_sample8[count8++];
            sample |= CYMB_sample8[count8++] << 8;
            
           outputs[AUDIO_OUTPUT].value=  5.0 * (float)sample / CYMB_sample8_len ;
        } else {
           outputs[AUDIO_OUTPUT].value=  0.0 ;
        }
    }
    
    
}

struct DrumsCymbalsWidget : ModuleWidget {
    DrumsCymbalsWidget(DrumsCymbals *module);
};

    DrumsCymbalsWidget::DrumsCymbalsWidget(DrumsCymbals *module) {
		setModule(module);



	box.size = Vec(15 * 4, 380);

	{
        SvgPanel *panel = new SvgPanel();
        panel->box.size = box.size;
        panel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DrumsCymbals.svg")));
        addChild(panel);
	}

	addChild(createWidget<ScrewSilver>(Vec(15,   0)));
	addChild(createWidget<ScrewSilver>(Vec(15, 365)));
    
    addParam(createParam<LEDButton>(Vec(21, 60), module, DrumsCymbals::SAMPLETYPE));
    
    //addParam(createParam<Davies1900hBlackKnob>(Vec(30, 80), module, DrumsCymbals::PITCH));
    
     
    
  addChild(createLight<SmallLight<GreenLight>>(Vec(10,100), module, DrumsCymbals::SAMPLETYPE_LIGHT+0));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,125),  module, DrumsCymbals::SAMPLETYPE_LIGHT+1));
    addChild(createLight<SmallLight<GreenLight>>(Vec(10,150),  module, DrumsCymbals::SAMPLETYPE_LIGHT+2));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,175),  module, DrumsCymbals::SAMPLETYPE_LIGHT+3));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,200),  module, DrumsCymbals::SAMPLETYPE_LIGHT+4));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,225),  module, DrumsCymbals::SAMPLETYPE_LIGHT+5));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,250),  module, DrumsCymbals::SAMPLETYPE_LIGHT+6));
     addChild(createLight<SmallLight<GreenLight>>(Vec(10,275), module, DrumsCymbals::SAMPLETYPE_LIGHT+7));

    

	addInput (createInput <PJ3410Port>(Vec( 0, 300), module, DrumsCymbals::TRIG_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(30, 300), module, DrumsCymbals::AUDIO_OUTPUT));

}

Model *modelDrumsCymbals = createModel<DrumsCymbals, DrumsCymbalsWidget>("DrumsCymbals");

