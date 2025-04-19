#include "Autodafe.hpp"
#include <math.h>


Plugin *pluginInstance;




void init(rack::Plugin *p) {
    pluginInstance = p;
   
    

p->addModel(modelDrumsKick);  

p->addModel(modelDrumsSnare); 

p->addModel(modelDrumsHiHatClosed);  

p->addModel(modelDrumsHiHatOpen);       
       
p->addModel(modelDrumsClaps);

p->addModel(modelDrumsCymbals);

p->addModel(modelDrumsRide);

p->addModel(modelDrumsRimClaves);

p->addModel(modelDrumsMixer);


	}

