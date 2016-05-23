//
//  knapsack.cpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "knapsack.h"
#include <stdlib.h>

void knapsack(float c, int n, Obj **objs){
    //对objs进行排序，按单位价值由小到大排列
    //使用插入排序
    Obj *sortItem;
    int i;
    int j;
    for (i = 1; i < n; i++) {
        sortItem = objs[i];
        
        for (j = i - 1; j >= 0; j--) {
            if (objs[j]->averageValue > sortItem->averageValue) {
                objs[j + 1] = objs[j];
            }
            else
                break;
        }
        objs[j + 1] = sortItem;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if ((c = c - objs[i]->weight) > 0) {
            //全部放入背包
            objs[i]->loadWeight = objs[i]->weight;
        }
        else{
            //部分放入背包，并且结束
            objs[i]->loadWeight = objs[i]->weight + c;
            break;
        }
    }
}

void testKnapsack(){
    float c = 100;
    int n = 10;
    
    Obj **objs = new Obj*[n];
    for (int i = 0; i < n; i++) {
        objs[i] = new Obj;
        objs[i]->weight = rand() % 50;
        objs[i]->value = rand() % 100;
        objs[i]->averageValue = objs[i]->value / objs[i]->weight;
        objs[i]->loadWeight = 0;
    }
    
    knapsack(c, n, objs);
    
    for (int i = 0; i < n; i++) {
        printf("id=%d weight:%f value:%f averageValue:%f loadWight:%f\n",
               i, objs[i]->weight, objs[i]->value, objs[i]->averageValue, objs[i]->loadWeight);
    }
}

