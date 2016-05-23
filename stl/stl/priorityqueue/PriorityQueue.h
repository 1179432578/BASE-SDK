//
//  PriorityQueue.hpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <stdio.h>

//优先队列 最小堆实现
struct PriorityQueue{
    int capacity;
    int size;
    int *arr;
};

PriorityQueue* makePriorityQueue(int capacity);

void insert(PriorityQueue *q, int e);

int deleteMin(PriorityQueue *q);

void tesetPriorityQueue();



#endif /* PriorityQueue_hpp */
