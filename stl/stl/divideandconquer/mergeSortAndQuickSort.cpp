//
//  mergeSortAndQuickSort.cpp
//  stl
//
//  Created by lewis on 16/6/4.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "mergeSortAndQuickSort.h"

void ms2(int a[], int tmp[] , int l, int r){
    /*子问题不再可分，子问题本身就是问题解了*/
    if (l >= r) {
        return;
    }
    
    /*求解子问题*/
    int mid = (l + r) / 2;
    ms2(a, tmp, l, mid);
    ms2(a, tmp, mid+1, r);
    
    /*合并子问题*/
    /*把子问题解合并到tmp中*/
    int i = l;
    int j = mid+1;
    int k = l;
    while (i <= mid && j <=r) {
        tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];
    }
    
    /*把子问题剩下解复制到tmp*/
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    
    /*把tmp复制到原问题空间中*/
    for (int i=l; i<=r; i++) {
        a[i] = tmp[i];
    }
}

void mergeSort2(int a[], int num){
    int *tmp = new int[num];
    ms2(a, tmp , 0, num-1);
    
    delete [] tmp;
}

void testMergeSort2(){
    int a[] = {2, 5, 54, 435, 2, 35, 454, 34, 34, 56, 565};
    
    mergeSort2(a, sizeof(a)/sizeof(int));
    
    for (int i=0; i<sizeof(a)/sizeof(int); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}