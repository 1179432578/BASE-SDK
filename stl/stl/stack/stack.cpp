//
//  stack.cpp
//  stl
//
//  Created by lewis on 16/5/18.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "stack.h"
#include <assert.h>

Stack* makeStack(int size){
    Stack *s = new Stack;
    s->top = -1;
    s->arr = new int[size];
    s->size = size;
    
    return s;
}

void push(Stack *s, int e){
    if (s->top == s->size - 1) {
//        error
        assert(s->top < s->size - 1);
        return;
    }
    
    s->arr[++s->top] = e;
}

int pop(Stack *s){
    if (s->top == -1) {
        //        error
        assert(s->top > -1);
        return 0;
    }
    
    return s->arr[s->top--];
}

void testStack(){
    Stack *s = makeStack(4);
    
    push(s, 100);
    push(s, 20);
    push(s, 10340);
    push(s, 10340);
    
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
}