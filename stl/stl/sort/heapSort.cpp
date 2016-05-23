//
//  heapSort.cpp
//  stl
//
//  Created by lewis on 16/5/7.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "sort.h"

//heap的操作有： 建立最小堆，最小堆的插入、删除
//heap sort用max-heap来进行对元素进行有小到大排序，当然也可以使用min-heap由大到小排序

//把一个子树构建成一个max-heap.可以优化里面的代码，写的不够简练，但是逻辑很清楚
//http://jingyan.baidu.com/article/5225f26b057d5de6fa0908f3.html
void adjustHeap(int a[], int i, int n){
    int leftChild;
    int tmp;
    
    //i的左右孩子都在
    if (2 * i + 1 < n - 1 && 2 * i + 2 <= n - 1 ) {
        leftChild = i * 2 + 1;
        
        //a[i]大于左右孩子，表示i子树是max-heap了，所以直接返回
        if (a[i] > a[leftChild] && a[i] > a[leftChild + 1]) {
            return;
        }
        else{
            //左孩子大，i与左孩子交换，并递归处理左子树
            if (a[leftChild] > a[leftChild + 1]) {
                tmp = a[i];
                a[i] = a[leftChild];
                a[leftChild] = tmp;
                adjustHeap(a, leftChild, n);
            }
            //右孩子大，i与右孩子交换，并递归处理右子树
            else{
                tmp = a[i];
                a[i] = a[leftChild + 1];
                a[leftChild + 1] = tmp;
                adjustHeap(a, leftChild + 1, n);
            }
        }
    }
    //i只有左孩子
    else if (2 * i + 1 <= n - 1){
        leftChild = i * 2 + 1;
        
        //左孩子大，i与左孩子交换，并递归处理左子树
        if (a[leftChild] > a[i]) {
            tmp = a[i];
            a[i] = a[leftChild];
            a[leftChild] = tmp;
            adjustHeap(a, leftChild, n);
        }
        else{
            return;
        }
    }
    //i没孩子,直接返回
    else{
        return;
    }
}

void heapSort(int a[], int n){
    //对每个非叶子节点为root的子树建立max-heap，最后形成一个max-heap
    for (int i = n / 2; i >=0; i--) {
        adjustHeap(a, i, n);
    }
    
    int tmp;
    //0~i是max-heap，i+1~n-1是有序表，每次从max-heap中去除最大的放到有序表中
    for (int i = n - 1; i > 0; i--) {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        
        adjustHeap(a, 0, i);
    }
}

void adjustHeap2(int a[], int i, int n){
    int child;
    int tmp;
    
    //存在左孩子，一旦没左孩子就返回
    for(tmp = a[i];  (child = 2 * i + 1) <= n - 1; i = child){
        //存在左右孩子，并且左孩子小于右孩子
        if (child != n - 1 && a[child + 1] > a[child]) {
            child++;
        }
        
        if(tmp < a[child]){
            a[i] = a[child];
        }
        else{
            break;
        }
    }
    
    a[i] = tmp;
}

void heapSort2(int a[], int n){
    //对每个非叶子节点为root的子树建立max-heap，最后形成一个max-heap
    for (int i = n / 2; i >=0; i--) {
        adjustHeap(a, i, n);
    }
    
    int tmp;
    //0~i是max-heap，i+1~n-1是有序表，每次从max-heap中去除最大的放到有序表中
    for (int i = n - 1; i > 0; i--) {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        
        adjustHeap2(a, 0, i);
    }
}
