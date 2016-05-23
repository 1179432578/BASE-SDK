//
//  stack.hpp
//  stl
//
//  Created by lewis on 16/5/18.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>

struct Stack{
    int top;
    int size;
    int *arr;
};

Stack* makeStack(int size);

void push(Stack *s, int e);

int pop(Stack *s);

void testStack();

#endif /* stack_hpp */
