//
//  singleton.cpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "singleton.h"

static Singleton *s_singleton = NULL;
Singleton* Singleton::getInstance(){
    if (!s_singleton) {
        s_singleton = new Singleton;
    }
    
    return s_singleton;
}

void testSingleton(){
    Singleton *obj = Singleton::getInstance();
    obj->description();
}