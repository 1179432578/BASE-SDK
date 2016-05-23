//
//  kmp.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/17.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "kmp.h"
#include <string.h>

//简化代码
int* makeMap(const char *pattern){
    int length = strlen(pattern);
    int *map = new int[length];
    
    //求失效点0到length-1的链接值
    for (int j = 0; j < length; j++) {
        //k是j的失效链接值，测试0-
        //p[0, k-1] = p[j-k , j-1]
        
        int k;
        //默认为0
        map[j] = 0;
        for (k = 0; k <= j / 2; k++) {
            //比较p[0, k-1]与p[j-k , j-1]，如果p[0, k-1] != [j-k , j-1],那么k是失效链接点
            bool test = true;
            for (int i = 0; i < k; i++) {
                if (pattern[i] != pattern[j-k+i]) {
                    test = false;
                    break;
                }
            }
            //p[0,k-1]==p[j-k,j-1], k为链接点，继续测下个k
            if (test) {
                map[j] = k;
            }
        }
        
    }
    
    return map;
}

void testKmp(){
    int *map = makeMap("ababab");
    
    for (int i = 0; i < 6; i++) {
        printf("j:%d k:%d\n", i, map[i]);
    }
    
}