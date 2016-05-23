//
//  mergeSort.cpp
//  stl
//
//  Created by lewis on 16/5/7.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "sort.h"

void merge(int a[], int tmpArr[], int lPos, int rPos, int rEndPos){
    int l = lPos;
    int r = rPos;
    int p = lPos;
    
    while (l < rPos && r <= rEndPos) {
        //插入左边的到临时表中
        if (a[l] < a[r]) {
            tmpArr[p++] = a[l++];
        }
        //插入右边的到临时表中
        else{
            tmpArr[p++] = a[r++];
        }
    }
    
    //把剩余左边元素插到临时表中
    while (l < rPos) {
        tmpArr[p++] = a[l++];
    }
    
    //把剩余右边元素插到临时表中
    while (r <= rEndPos) {
        tmpArr[p++] = a[r++];
    }
    
    //把排好序的临时表中元素回插到待排序表
    for (int i = lPos; i <= rEndPos; i++) {
        a[i] = tmpArr[i];
    }
}

void mSort(int a[], int tmpArr[], int l, int r){
    int m;
    if (l < r){
        m = (r + l) / 2;
        mSort(a, tmpArr, l, m);
        mSort(a, tmpArr, m + 1, r);
        merge(a, tmpArr, l, m + 1, r);
    }
}


void mergeSort(int a[], int n){
    int *tmpArr = new int[n];
    
    mSort(a, tmpArr, 0, n - 1);
    
    delete tmpArr;
}
