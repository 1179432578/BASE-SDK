//
//  divideAndConquer.hpp
//  stl
//
//  Created by lewis on 16/6/2.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef divideAndConquer_hpp
#define divideAndConquer_hpp

#include <stdio.h>

struct Point{
    int x;
    int y;
};

/*最近点问题*/
//返回两个最近点
void neastPoint(int num, Point pts[], int *p1, int *p2);

void testNeastPoint();

#endif /* divideAndConquer_hpp */
