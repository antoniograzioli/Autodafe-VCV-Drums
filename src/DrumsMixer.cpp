#include "Autodafe.hpp"



struct DrumsMixer : Module {
	enum ParamIds {
		MIX_PARAM,
		CH1_PARAM,
		CH2_PARAM,
		CH3_PARAM,
		CH4_PARAM,
		CH5_PARAM,
		CH6_PARAM,
		CH7_PARAM,
		CH8_PARAM, 
	 

		CH1_PAN_PARAM,
		CH2_PAN_PARAM,
		CH3_PAN_PARAM,
		CH4_PAN_PARAM,
		CH5_PAN_PARAM,
		CH6_PAN_PARAM,
		CH7_PAN_PARAM,
		CH8_PAN_PARAM,
 
		CH1MUTE,
		CH2MUTE,
		CH3MUTE,
		CH4MUTE,
		CH5MUTE,
		CH6MUTE,
		CH7MUTE,
		CH8MUTE,




		NUM_PARAMS
	};
	enum InputIds {
		MIX_CV_INPUT,

		CH1_INPUT,
		CH1_CV_INPUT,
		CH1_CV_PAN_INPUT,

		CH2_INPUT,
		CH2_CV_INPUT,
		CH2_CV_PAN_INPUT,

		CH3_INPUT,
		CH3_CV_INPUT,
		CH3_CV_PAN_INPUT,

		CH4_INPUT,
		CH4_CV_INPUT,
		CH4_CV_PAN_INPUT,

		CH5_INPUT,
		CH5_CV_INPUT,
		CH5_CV_PAN_INPUT,

		CH6_INPUT,
		CH6_CV_INPUT,
		CH6_CV_PAN_INPUT,

		CH7_INPUT,
		CH7_CV_INPUT,
		CH7_CV_PAN_INPUT,

		CH8_INPUT,
		CH8_CV_INPUT,
		CH8_CV_PAN_INPUT,
		

		NUM_INPUTS
	};
	enum OutputIds {
		MIX_OUTPUTL,
		MIX_OUTPUTR,
		CH1_OUTPUT,
		CH2_OUTPUT,
		CH3_OUTPUT,
		CH4_OUTPUT,
		CH5_OUTPUT,
		CH6_OUTPUT,
		CH7_OUTPUT,
		CH8_OUTPUT,
		
		NUM_OUTPUTS
	};

enum LightIds {
    MUTE_LIGHT1,
    MUTE_LIGHT2,
    MUTE_LIGHT3,
    MUTE_LIGHT4,
    MUTE_LIGHT5,
    MUTE_LIGHT6,
    MUTE_LIGHT7,
    MUTE_LIGHT8,
    NUM_LIGHTS
    };


dsp::SchmittTrigger ch1mute;
dsp::SchmittTrigger ch2mute;
dsp::SchmittTrigger ch3mute;
dsp::SchmittTrigger ch4mute;
dsp::SchmittTrigger ch5mute;
dsp::SchmittTrigger ch6mute;
dsp::SchmittTrigger ch7mute;
dsp::SchmittTrigger ch8mute;






float ch1MuteLight;
float ch2MuteLight;
float ch3MuteLight;
float ch4MuteLight;
float ch5MuteLight;
float ch6MuteLight;
float ch7MuteLight;
float ch8MuteLight;

bool ch1m = false;
			bool ch2m = false;
			bool ch3m = false;
			bool ch4m = false;
			bool ch5m = false;
			bool ch6m = false;
			bool ch7m = false;
			bool ch8m = false;



	DrumsMixer() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);



configParam(DrumsMixer::CH1_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH2_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH3_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH4_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH5_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH6_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH7_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH8_PARAM, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH1_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH2_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH3_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH4_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH5_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH6_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH7_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH8_PAN_PARAM, -1.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH1MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH2MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH3MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH4MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH5MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH6MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH7MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::CH8MUTE, 0.0, 1.0, 0.0, "");
configParam(DrumsMixer::MIX_PARAM, 0.0, 1.0, 0.0, "");

	}







	void process(const ProcessArgs &args) override;

	




json_t *dataToJson() override {
		json_t *rootJm = json_object();

		json_t *mutesJ = json_array();
		
			json_t *muteJ1 = json_integer((int) ch1m);
			json_t *muteJ2 = json_integer((int) ch2m);
			json_t *muteJ3 = json_integer((int) ch3m);
			json_t *muteJ4 = json_integer((int) ch4m);
			json_t *muteJ5 = json_integer((int) ch5m);
			json_t *muteJ6 = json_integer((int) ch6m);
			json_t *muteJ7 = json_integer((int) ch7m);
			json_t *muteJ8 = json_integer((int) ch8m);

			json_array_append_new(mutesJ, muteJ1);
			json_array_append_new(mutesJ, muteJ2);
			json_array_append_new(mutesJ, muteJ3);
			json_array_append_new(mutesJ, muteJ4);
			json_array_append_new(mutesJ, muteJ5);
			json_array_append_new(mutesJ, muteJ6);
			json_array_append_new(mutesJ, muteJ7);
			json_array_append_new(mutesJ, muteJ8);
		
		json_object_set_new(rootJm, "autodafeDrumMixerMutes", mutesJ);

		return rootJm;
	}



	void dataFromJson(json_t *rootJm)  override {
		json_t *mutesJ = json_object_get(rootJm, "autodafeDrumMixerMutes");
		
			json_t *muteJ1 = json_array_get(mutesJ, 0);
			json_t *muteJ2 = json_array_get(mutesJ, 1);
			json_t *muteJ3 = json_array_get(mutesJ, 2);
			json_t *muteJ4 = json_array_get(mutesJ, 3);
			json_t *muteJ5 = json_array_get(mutesJ, 4);
			json_t *muteJ6 = json_array_get(mutesJ, 5);
			json_t *muteJ7 = json_array_get(mutesJ, 6);
			json_t *muteJ8 = json_array_get(mutesJ, 7);



			ch1m = !!json_integer_value(muteJ1);
			ch2m = !!json_integer_value(muteJ2);
			ch3m = !!json_integer_value(muteJ3);
			ch4m = !!json_integer_value(muteJ4);
			ch5m = !!json_integer_value(muteJ5);
			ch6m = !!json_integer_value(muteJ6);
			ch7m = !!json_integer_value(muteJ7);
			ch8m = !!json_integer_value(muteJ8);

			



		
	}








void reset() {
		
			ch1m = false;
			ch2m = false;
			ch3m = false;
			ch4m = false;
			ch5m = false;
			ch6m = false;
			ch7m = false;
			ch8m = false;
		 
	}


};


//PAN LEVEL

	 float PanL(
   
   float balance, float cv // -1...+1
   )
{
   float p, gl;




	p=M_PI*(balance+1)/4;

if(cv){gl=::cos(p)*(1-((cv+1)/5));}
	else 
		{gl=::cos(p);}
   
 
  return gl;

}
 
    
   
	 float PanR(
   
   float balance , float cv
   )
{
   float p, gr;

   p=M_PI*(balance+1)/4;

if(cv){gr=::sin(p)*((cv+1)/5);}
	else{gr=::sin(p);}

   

   return gr;

}






void DrumsMixer::process(const ProcessArgs &args) {
		

	//MUTE BUTTONS	




	if (ch1mute.process(params[CH1MUTE].getValue())) {
		ch1m = !ch1m;
		
	}
	lights[MUTE_LIGHT1].value = ch1m ? 1.0 : 0.0;



	if (ch2mute.process(params[CH2MUTE].getValue())) {
		ch2m = !ch2m  ;
		
	}
	lights[MUTE_LIGHT2].value = ch2m ? 1.0 : 0.0;


	if (ch3mute.process(params[CH3MUTE].getValue())) {
		ch3m = !ch3m;
		
	}
	lights[MUTE_LIGHT3].value = ch3m ? 1.0 : 0.0;


	if (ch4mute.process(params[CH4MUTE].getValue())) {
		ch4m = !ch4m;
		
	}
	lights[MUTE_LIGHT4].value  = ch4m ? 1.0 : 0.0;

	
	if (ch5mute.process(params[CH5MUTE].getValue())) {
		ch5m = !ch5m;
		
	}
	lights[MUTE_LIGHT5].value  = ch5m ? 1.0 : 0.0;


	if (ch6mute.process(params[CH6MUTE].getValue())) {
		ch6m = !ch6m;
	
	}
	lights[MUTE_LIGHT6].value  = ch6m ? 1.0 : 0.0;


	if (ch7mute.process(params[CH7MUTE].getValue())) {
		ch7m = !ch7m;
	
	}
	lights[MUTE_LIGHT7].value  = ch7m ? 1.0 : 0.0;


	if (ch8mute.process(params[CH8MUTE].getValue())) {
		ch8m = !ch8m;
		
	}
	lights[MUTE_LIGHT8].value  = ch8m ? 1.0 : 0.0;


 



	float ch1L =  (1-ch1m) * (inputs[CH1_INPUT].getVoltage()) * params[CH1_PARAM].getValue() * PanL(params[CH1_PAN_PARAM].getValue(),(inputs[CH1_CV_PAN_INPUT].getVoltage()))* clamp(inputs[CH1_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch1R =  (1-ch1m) * (inputs[CH1_INPUT].getVoltage()) * params[CH1_PARAM].getValue() * PanR(params[CH1_PAN_PARAM].getValue(),(inputs[CH1_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH1_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	

	float ch2L = (1-ch2m) *(inputs[CH2_INPUT].getVoltage()) * params[CH2_PARAM].getValue() * PanL(params[CH2_PAN_PARAM].getValue(),(inputs[CH2_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH2_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch2R = (1-ch2m) *(inputs[CH2_INPUT].getVoltage()) * params[CH2_PARAM].getValue() * PanR(params[CH2_PAN_PARAM].getValue(),(inputs[CH2_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH2_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	
	float ch3L = (1-ch3m) *(inputs[CH3_INPUT].getVoltage()) * params[CH3_PARAM].getValue() * PanL(params[CH3_PAN_PARAM].getValue(),(inputs[CH3_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH3_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch3R = (1-ch3m) *(inputs[CH3_INPUT].getVoltage()) * params[CH3_PARAM].getValue() * PanR(params[CH3_PAN_PARAM].getValue(),(inputs[CH3_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH3_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);

	float ch4L = (1-ch4m) *(inputs[CH4_INPUT].getVoltage()) * params[CH4_PARAM].getValue() * PanL(params[CH4_PAN_PARAM].getValue(),(inputs[CH4_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH4_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch4R = (1-ch4m) *(inputs[CH4_INPUT].getVoltage()) * params[CH4_PARAM].getValue() * PanR(params[CH4_PAN_PARAM].getValue(),(inputs[CH4_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH4_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);


	float ch5L = (1-ch5m) *(inputs[CH5_INPUT].getVoltage()) * params[CH5_PARAM].getValue() * PanL(params[CH5_PAN_PARAM].getValue(),(inputs[CH5_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH5_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch5R = (1-ch5m) *(inputs[CH5_INPUT].getVoltage()) * params[CH5_PARAM].getValue() * PanR(params[CH5_PAN_PARAM].getValue(),(inputs[CH5_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH5_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);


	float ch6L = (1-ch6m) *(inputs[CH6_INPUT].getVoltage()) * params[CH6_PARAM].getValue() * PanL(params[CH6_PAN_PARAM].getValue(),(inputs[CH6_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH6_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch6R = (1-ch6m) *(inputs[CH6_INPUT].getVoltage()) * params[CH6_PARAM].getValue() * PanR(params[CH6_PAN_PARAM].getValue(),(inputs[CH6_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH6_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch7L = (1-ch7m) *(inputs[CH7_INPUT].getVoltage()) * params[CH7_PARAM].getValue() * PanL(params[CH7_PAN_PARAM].getValue(),(inputs[CH7_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH7_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch7R = (1-ch7m) *(inputs[CH7_INPUT].getVoltage()) * params[CH7_PARAM].getValue() * PanR(params[CH7_PAN_PARAM].getValue(),(inputs[CH7_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH7_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);

	float ch8L = (1-ch8m) *(inputs[CH8_INPUT].getVoltage()) * params[CH8_PARAM].getValue() * PanL(params[CH8_PAN_PARAM].getValue(),(inputs[CH8_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH8_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	float ch8R = (1-ch8m) *(inputs[CH8_INPUT].getVoltage()) * params[CH8_PARAM].getValue() * PanR(params[CH8_PAN_PARAM].getValue(),(inputs[CH8_CV_PAN_INPUT].getVoltage())) * clamp(inputs[CH8_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);

	float mixL = (ch1L + ch2L + ch3L +ch4L + ch5L + ch6L + ch7L + ch8L) * params[MIX_PARAM].getValue() * clamp(inputs[MIX_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
float mixR = (ch1R + ch2R + ch3R +ch4R + ch5R + ch6R + ch7R + ch8R) * params[MIX_PARAM].getValue() * clamp(inputs[MIX_CV_INPUT].getNormalVoltage(10.0f) / 10.0f, 0.0f, 1.0f);
	


	(outputs[CH1_OUTPUT].value= ch1L+ch1R); 
	(outputs[CH2_OUTPUT].value= ch2L+ch2R);
	(outputs[CH3_OUTPUT].value= ch3L+ch3R);
	(outputs[CH4_OUTPUT].value= ch4L+ch4R);
	(outputs[CH5_OUTPUT].value= ch5L+ch5R);
	(outputs[CH6_OUTPUT].value= ch6L+ch6R);
	(outputs[CH7_OUTPUT].value= ch7L+ch7R);
	(outputs[CH8_OUTPUT].value= ch8L+ch8R);

	(outputs[MIX_OUTPUTL].value= mixL);
	(outputs[MIX_OUTPUTR].value= mixR);





}

struct AutodafeGoldLight : ModuleLightWidget {
	AutodafeGoldLight() {
		addBaseColor(nvgRGB(0xb8, 0x99, 0x52));
	}
};




struct DrumsMixerWidget : ModuleWidget {
    DrumsMixerWidget(DrumsMixer *module);
};

    DrumsMixerWidget::DrumsMixerWidget(DrumsMixer *module) {
		setModule(module);



	box.size = Vec(15*37, 380);

	{
		SvgPanel *panel = new SvgPanel();
		panel->box.size = box.size;
		panel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DrumsMixer.svg")));
		
		addChild(panel);
	} 


	addChild(createWidget<ScrewSilver>(Vec(2, 0)));
	addChild(createWidget<ScrewSilver>(Vec(box.size.x-17, 0)));
	addChild(createWidget<ScrewSilver>(Vec(2, 365)));
	addChild(createWidget<ScrewSilver>(Vec(box.size.x-17, 365)));
 
	addParam(createParam<AutodafeKnobBrown>(Vec(50-5, 180), module, DrumsMixer::CH1_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(100-5, 180), module, DrumsMixer::CH2_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(150-5, 180), module, DrumsMixer::CH3_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(200-5, 180), module, DrumsMixer::CH4_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(250-5, 180), module, DrumsMixer::CH5_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(300-5, 180), module, DrumsMixer::CH6_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(350-5, 180), module, DrumsMixer::CH7_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(400-5, 180), module, DrumsMixer::CH8_PARAM));


	addParam(createParam<AutodafeKnobBrown>(Vec(50-5, 230), module, DrumsMixer::CH1_PAN_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(100-5, 230), module, DrumsMixer::CH2_PAN_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(150-5, 230), module, DrumsMixer::CH3_PAN_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(200-5, 230), module, DrumsMixer::CH4_PAN_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(250-5, 230), module, DrumsMixer::CH5_PAN_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(300-5, 230), module, DrumsMixer::CH6_PAN_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(350-5, 230), module, DrumsMixer::CH7_PAN_PARAM));
	addParam(createParam<AutodafeKnobBrown>(Vec(400-5, 230), module, DrumsMixer::CH8_PAN_PARAM));
 

	   addParam(createParam<LEDButton>(Vec(50+3, 280), module, DrumsMixer::CH1MUTE));
	   addParam(createParam<LEDButton>(Vec(100+3, 280), module, DrumsMixer::CH2MUTE));
	   addParam(createParam<LEDButton>(Vec(150+3, 280), module, DrumsMixer::CH3MUTE));
	   addParam(createParam<LEDButton>(Vec(200+3, 280), module, DrumsMixer::CH4MUTE));
	   addParam(createParam<LEDButton>(Vec(250+3, 280), module, DrumsMixer::CH5MUTE));
	   addParam(createParam<LEDButton>(Vec(300+3, 280), module, DrumsMixer::CH6MUTE));
	   addParam(createParam<LEDButton>(Vec(350+3, 280), module, DrumsMixer::CH7MUTE));
	   addParam(createParam<LEDButton>(Vec(400+3, 280), module, DrumsMixer::CH8MUTE));

	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(50+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT1 ));
	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(100+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT2));
	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(150+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT3));
	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(200+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT4));
	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(250+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT5));
	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(300+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT6));
	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(350+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT7));
	   addChild(createLight<MediumLight<AutodafeGoldLight>>(Vec(400+7.5, 280+4.5), module, DrumsMixer::MUTE_LIGHT8));




	addParam(createParam<AutodafeKnobBrownBig>(Vec(468, 170), module, DrumsMixer::MIX_PARAM));
	
 
	addInput(createInput<PJ301MPort>(Vec(50, 50), module, DrumsMixer::CH1_INPUT));
	addInput(createInput<PJ301MPort>(Vec(50, 95), module, DrumsMixer::CH1_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(50, 140), module, DrumsMixer::CH1_CV_PAN_INPUT));

	addInput(createInput<PJ301MPort>(Vec(100, 50), module, DrumsMixer::CH2_INPUT));
	addInput(createInput<PJ301MPort>(Vec(100, 90), module, DrumsMixer::CH2_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(100, 140), module, DrumsMixer::CH2_CV_PAN_INPUT));

	addInput(createInput<PJ301MPort>(Vec(150, 50), module, DrumsMixer::CH3_INPUT));
	addInput(createInput<PJ301MPort>(Vec(150, 90), module, DrumsMixer::CH3_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(150, 140), module, DrumsMixer::CH3_CV_PAN_INPUT));

	addInput(createInput<PJ301MPort>(Vec(200, 50), module, DrumsMixer::CH4_INPUT));
	addInput(createInput<PJ301MPort>(Vec(200, 90), module, DrumsMixer::CH4_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(200, 140), module, DrumsMixer::CH4_CV_PAN_INPUT));

	addInput(createInput<PJ301MPort>(Vec(250, 50), module, DrumsMixer::CH5_INPUT));
	addInput(createInput<PJ301MPort>(Vec(250, 90), module, DrumsMixer::CH5_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(250, 140), module, DrumsMixer::CH5_CV_PAN_INPUT));

	addInput(createInput<PJ301MPort>(Vec(300, 50), module, DrumsMixer::CH6_INPUT));
	addInput(createInput<PJ301MPort>(Vec(300, 90), module, DrumsMixer::CH6_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(300, 140), module, DrumsMixer::CH6_CV_PAN_INPUT));

	addInput(createInput<PJ301MPort>(Vec(350, 50), module, DrumsMixer::CH7_INPUT));
	addInput(createInput<PJ301MPort>(Vec(350, 90), module, DrumsMixer::CH7_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(350, 140), module, DrumsMixer::CH7_CV_PAN_INPUT));

	addInput(createInput<PJ301MPort>(Vec(400, 50), module, DrumsMixer::CH8_INPUT));
	addInput(createInput<PJ301MPort>(Vec(400, 95), module, DrumsMixer::CH8_CV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(400, 140), module, DrumsMixer::CH8_CV_PAN_INPUT));

		addInput(createInput<PJ301MPort>(Vec(480, 50), module, DrumsMixer::MIX_CV_INPUT));



	addOutput(createOutput<PJ301MPort>(Vec(50, 310), module, DrumsMixer::CH1_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(100, 310), module, DrumsMixer::CH2_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(150, 310), module, DrumsMixer::CH3_OUTPUT)); 
	addOutput(createOutput<PJ301MPort>(Vec(200, 310), module, DrumsMixer::CH4_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(250, 310), module, DrumsMixer::CH5_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(300, 310), module, DrumsMixer::CH6_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(350, 310), module, DrumsMixer::CH7_OUTPUT)); 
	addOutput(createOutput<PJ301MPort>(Vec(400, 310), module, DrumsMixer::CH8_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(460, 310), module, DrumsMixer::MIX_OUTPUTL));
	addOutput(createOutput<PJ301MPort>(Vec(500, 310), module, DrumsMixer::MIX_OUTPUTR));

 



	


}


Model *modelDrumsMixer = createModel<DrumsMixer, DrumsMixerWidget>("DrumsMixer");

