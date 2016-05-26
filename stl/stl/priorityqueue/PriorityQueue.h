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

//创建一个优先队列
PriorityQueue* makePriorityQueue(int capacity);

void insert(PriorityQueue *q, int e);

int deleteMin(PriorityQueue *q);

void tesetPriorityQueue();

//找出第k大的数
//用数组找出k个最大
int findKthMaxWithArray(int a[], int n, int k);

/*最大堆解决找出第k大的数
 *
 */
struct MaxHeap{
    int count;
    int *arr;
};

//由一组数据构建最大堆
MaxHeap* buildMaxHeap(int a[], int n);

int deleteMax(MaxHeap *heap);

int findKthMax(int a[], int, int k);

void testFindKthMax();

#endif /* PriorityQueue_hpp */
