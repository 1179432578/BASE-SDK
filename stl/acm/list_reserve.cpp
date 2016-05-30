//
//  list_reserve.cpp
//  stl
//
//  Created by lewis on 16/5/30.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "list_reserve.h"
#include <stdio.h>

void reserve(Node **list){
    Node *current = *list;
    node *pre = NULL;
    node *next = (*list)->next;
    node *tmp;
    
    while (next) {
        tmp = next->next;
        next->next = current;
        current->next = pre;
        
        pre = current;
        current = next;
        next = tmp;
    }
    
    *list = current;
}

void listAdd(Node **list, int data){
    Node *e = new Node;
    e->data = data;
    e->next = *list;
    *list = e;
}

void printList(Node *list){
    Node *p = list;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    
    printf("\n");
}

void testListReserve(){
    Node *l = NULL;
    listAdd(&l, 10);
    listAdd(&l, 20);
    listAdd(&l, 101);
    listAdd(&l, 210);
    listAdd(&l, 130);
    printList(l);
    
    reserve(&l);
    printList(l);
}