//
//  quickSort.cpp
//  stl
//
//  Created by lewis on 16/5/8.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "sort.h"
#include <stdio.h>
//a,b不能同一个变量，不然变成0了
//#define swap(a, b) a = a + b; b = a - b; a = a - b;
#define swap(a, b) int tmp = a; a = b; b = tmp;

//选择pivot 使用三数中值
int chooseBase(int a[], int l, int r){
    int center = (l + r) / 2;

    if (r - l > 1) {
        if (a[l] > a[center]) {
            swap(a[l], a[center]);
        }
        if (a[l] > a[r]) {
            swap(a[l], a[r]);
        }
        if (a[center] > a[r]) {
            swap(a[center], a[r]);
        }
    }
    else{
        if (a[l] < a[r]) {
            swap(a[l], a[r]);
        }
    }
    
    swap(a[center], a[r]); //a[r] is pivot
    return a[r];
}
//a至少3个元素，不然不能用3数中值
void qSort(int a[], int l, int r){
    if (l >= r) {
        return;
    }
    
    int i = l;
    int j = r;
    int pivot = chooseBase(a, l, r);
    
    while (true) {
        while (a[++i] < pivot) {} //i from l+1
        while (a[--j] > pivot) {} //j from r-1
        
        if (i < j) {
            swap(a[i], a[j]);
        }
        else{
            break;
        }
    }
    swap(a[i], a[r]);
    
    qSort(a, l, i - 1);
    qSort(a, i + 1, r);
}

void quickSort(int a[], int n){
    qSort(a, 0, n - 1);
}

