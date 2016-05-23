//
//  linkedlist.cpp
//  stl
//
//  Created by lewis on 16/5/17.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "linkedlist.h"

//创建一个多项式
Poly* makePoly(int coefficientArr[], int exponentArr[], int n){
    Poly *p = new Poly;
    p->head = new PolyNode;
    p->head->next = 0;
    
    PolyNode *node;
    for (int i = 0; i < n; i++) {
        node = new PolyNode;
        node->coefficient = coefficientArr[i];
        node->exponent = exponentArr[i];
        node->next = p->head->next;
        p->head->next = node;
    }
    
    return p;
}

//将两个多项式相加
//p1 p2没有要求，由p1 p2构造一个排好序的多项式
//把p1 p2合成一个多项式链表，p1 p2可以删除了，只能删除头结点
Poly* addPoly(Poly *p1, Poly *p2){
    Poly *p = new Poly;
    p->head = new PolyNode;
    p->head->next = 0;
    PolyNode *pn;
    PolyNode *tmp;
    bool flag;
    
    //插入poly1
    PolyNode *pn1 = p1->head->next;
    while (pn1) {
        pn = p->head;
        flag = false;
        
        while (pn->next) {
            if (pn1->exponent > pn->next->exponent) {
                tmp = pn1;
                pn1 = pn1->next;
                tmp->next = pn->next;
                pn->next = tmp;
                flag = true;
                break;
            }
            else if (pn1->exponent == pn->next->exponent){
                pn->next->coefficient += pn1->coefficient;
                pn1 = pn1->next;
                flag = true;
                break;
            }
            else{
                pn = pn->next;
            }
        }
        
        //没有插入到新的poly中
        if (!flag) {
            pn->next = pn1;
            pn1 = pn1->next;
            pn->next->next = 0;
        }
    }
    
    //插入poly2
    PolyNode *pn2 = p2->head->next;
    while (pn2) {
        pn = p->head;
        flag = false;
        
        while (pn->next) {
            if (pn2->exponent > pn->next->exponent) {
                tmp = pn2;
                pn2 = pn2->next;
                tmp->next = pn->next;
                pn->next = tmp;
                flag = true;
                break;
            }
            else if (pn2->exponent == pn->next->exponent){
                pn->next->coefficient += pn2->coefficient;
                pn2 = pn2->next;
                flag = true;
                break;
            }
            else{
                pn = pn->next;
            }
        }
        
        //没有插入到新的poly中
        if (!flag) {
            pn->next = pn2;
            pn2 = pn2->next;
            pn->next->next = 0;
        }
    }

    return p;
}

void testPoly(){
    int coefficientArr[5] = {10, 3, 54, 45, 3};
    int exponentArr[5] = {12, 3, 34, 3, 53};
    
    Poly *p1 = makePoly(coefficientArr, exponentArr, 5);
    Poly *p2 = makePoly(coefficientArr, exponentArr, 5);
    Poly *p = addPoly(p1, p2);
    
    PolyNode *node = p->head;
    while (node = node->next) {
        printf(node->next ? "%dx^%d + " : "%dx^%d\n", node->coefficient, node->exponent);
    }
}