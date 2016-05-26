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
#include <string.h>

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

int findKthMaxWithArray(int a[], int n, int k){
    intersectionSort(a, k);
    inverse(a, k);
    
    int tmp;
    int j;
    for (int i = k; i < n; i++) {
        tmp = a[i];
        
        for (j=k-1; j>=0; j--) {
            if (a[j] < tmp) {
                a[j+1] = a[j];
            }
            else{
                break;
            }
            
        }
        
        a[j+1] = tmp;
    }
    
    return a[k-1];
}

MaxHeap* buildMaxHeap(int a[], int n){
    MaxHeap *heap = new MaxHeap;
    heap->count = n;
    heap->arr = new int[n+1];//a[0]不存储数据
    
    memcpy(heap->arr+1, a, n * sizeof(int));
    
    //下滤，大的漂上来
    for (int i=n/2; i>=1; i--) {
        int key = heap->arr[i];
        int child = 2 * i;
        while (child <= n) {
            if (child+1<=n && heap->arr[child+1] > heap->arr[child]) {
                child++;
            }
            if (heap->arr[child] > key) {
                heap->arr[child/2] = heap->arr[child];
                child *= 2;
            }
            else{
                break;
            }
        }
        heap->arr[child/2] = key;
    }
    
    return heap;
}

int deleteMax(MaxHeap *heap){
    int max = heap->arr[1];

    //下滤
    int key = heap->arr[heap->count--];
    int child = 2;
    while (child <= heap->count) {
        if (child+1<=heap->count && heap->arr[child+1]>heap->arr[child]) {
            child++;
        }
        if (heap->arr[child] > key) {
            heap->arr[child/2] = heap->arr[child];
            child *= 2;
        }
        else{
            break;
        }
    }
    
    heap->arr[child/2] = key;
    
    return max;
}

int findKthMax(int a[], int n, int k){
    MaxHeap *heap = buildMaxHeap(a, n);
    
    int max;
    for (int i=0; i<k; i++) {
        max = deleteMax(heap);
        
    }
    
    return max;
}

void testFindKthMax(){
    int a[] = {34, 23, 214, 23, 231, 345, 23, 22, 23, 1, 4, 2, 3, 6, 5};
    int k = 15;
    
    int kth = findKthMax(a, 15, k);
    
    printf("%dth: %d\n", k, kth);
}