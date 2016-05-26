//
//  PriorityQueue.cpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "PriorityQueue.h"
#include "sort.h"
#include "help.h"

PriorityQueue* makePriorityQueue(int capacity){
    PriorityQueue *q = new PriorityQueue();
    q->capacity = capacity;
    q->arr = new int[capacity];
    q->size = 0;
    
    return q;
}

void insert(PriorityQueue *q, int e){
    //queue is full
    if (q->size + 1 > q->capacity) {
        return;
    }
    
    q->arr[q->size++] = e;
//    q->size++;
    
    //上滤
    int child = q->size;
    int parent;
    while (parent = child / 2) {
        if (q->arr[parent - 1] > e) {
            q->arr[child - 1] = q->arr[parent - 1];
            
            child = parent;
        }
        else{
            //父亲小于孩子，符合最小二叉堆要求
            break;
        }
    }
    
    q->arr[child - 1] = e;
}

int deleteMin(PriorityQueue *q){
    if (q->size == 0) {
        return -1;
    }
    
    int min = q->arr[0];
    q->size--;
    
    //把最后一个元素移到第一个元素进行下滤
    int parent = 1;
    int child = 2;
    while (child <= q->size) {
        if (child + 1 <= q->size && q->arr[child] < q->arr[child - 1]) {
            child++;
        }
        
        if (q->arr[child - 1] < q->arr[parent]) {
            q->arr[parent] = q->arr[child - 1];
            child = 2 * child;
        }
        else{
            //父亲比孩子小，符合最小二叉堆要求了
            break;
        }
    }
    
    q->arr[child / 2 - 1] = q->arr[q->size];
    
    return min;
}

void tesetPriorityQueue(){
    PriorityQueue *q = makePriorityQueue(5);
    insert(q, 10);
    insert(q, 9);
    insert(q, 29);
    insert(q, 1);
    insert(q, 3);
    insert(q, 23);
    
    printf("min:%d\n", deleteMin(q));
    printf("min:%d\n", deleteMin(q));
    printf("min:%d\n", deleteMin(q));
    printf("min:%d\n", deleteMin(q));
    printf("min:%d\n", deleteMin(q));
    printf("min:%d\n", deleteMin(q));
    printf("min:%d\n", deleteMin(q));
}

void testFindKthMax(){
//    int a[15] = {34, 23, 214, 23, 231, 345, 23, 22, 23, 1, 4, 2, 3, 6, 5};
    int a[] = {34, 23, 214, 23, 231, 345};
    int k = 3;
    
    intersectionSort(a, k);
    inverse(a, k);
    
    int tmp;
    int j;
    for (int i = k; i < 6; i++) {
        tmp = a[i];
        
        for (j=k-1; j>=0; j--) {
            if (a[j] < tmp) {
                a[j+1] = a[j];
            }
        }
        
        a[j+1] = tmp;
    }
    
    printf("%dth max: %d\n", k, a[k-1]);
}