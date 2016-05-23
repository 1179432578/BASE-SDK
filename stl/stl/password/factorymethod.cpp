//
//  factorymethod.cpp
//  stl
//
//  Created by lewis on 16/5/11.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "factorymethod.h"
#include <string.h>

ICPU* ISimpleCPUFactory::makeProduct(char *productName){
    if (strcmp(productName, "HaisiCPU")) {
        return new HaisiCPU;
    }
    else if (strcmp(productName, "AppleCPU")){
        return new AppleCPU;
    }
    
    return 0;
}

void testFactoryPartern(){
    IAbstractFactory *hf = new HUaweiFactory;
    hf->createCPU();
    hf->createChip();
    
    IAbstractFactory *af = new AppleFactory;
    af->createCPU();
    af->createChip();
    
    delete hf;
    delete af;
}