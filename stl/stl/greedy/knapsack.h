//
//  knapsack.hpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef knapsack_hpp
#define knapsack_hpp

#include <stdio.h>

struct Obj{
    float weight;
    float value;
    float averageValue;
    float loadWeight;
};

void knapsack(float c, int n, Obj **objs);

void testKnapsack();

#endif /* knapsack_hpp */
