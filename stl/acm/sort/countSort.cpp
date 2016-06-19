//
//  countSort.cpp
//  stl
//
//  Created by lewis on 16/6/18.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//计数排序：非比较排序，对数范围较小的的数组排序
//方法：找出最小与最大，然后建立数组大小为最大与最小之差加一，最后对各个数字进行计数，然后放到正确位置

void countSort(int a[], int n){
    if (n <= 1) {
        return;
    }
    
    //找出最小与最大值
    int min = a[0];
    int max = a[0];
    
    for (int i=1; i<n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        else if (a[i] > max){
            max = a[i];
        }
    }
    
    int count = max - min + 1;
    int *b = new int[n];//用于排序
    int *c = new int[count];//用于计数
    memset(c, 0, sizeof(int) * count);
    
    for (int i=0; i<n; i++) {
        c[a[i]-min]++;//计数加一
    }
    
    for (int i=1; i<count; i++) {
        c[i] += c[i-1];//计算位置
    }
    
    for (int i=0; i<n; i++) {
        b[c[a[i]-min]-1] = a[i];
        c[a[i]-min]--;
    }
    
    memcpy(a, b, sizeof(int)*n);
}

void testCountSort(){
    int a[] = {34, 332, 324, 22, 22, 34, 3223, 222, 93};
    int n = sizeof(a)/sizeof(int);
    
    countSort(a, n);
    
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }

}