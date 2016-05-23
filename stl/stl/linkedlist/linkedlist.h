//
//  linkedlist.hpp
//  stl
//
//  Created by lewis on 16/5/17.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>

#endif /* linkedlist_hpp */

//coefficient
//exponent

//用链表解决多项式相加

struct PolyNode{
    int coefficient;
    int exponent;
    PolyNode *next;
};

struct Poly{
    PolyNode *head;
};

//创建一个多项式
Poly* makePoly(int coefficientArr[], int exponentArr[], int n);

//将两个多项式相加
Poly* addPoly(Poly *p1, Poly *p2);

void testPoly();