//
//  IDecorator.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/10.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "IDecorator.h"

#include <stdio.h>

static int i = 0;

void ConcreteDecorator::decoratorOp(){
    printf("ConcreteDecorator %d /", i);
};


void Decorator::decoratorOp(){
    m_dect->decoratorOp();
    printf("Decorator %d /", i);
}