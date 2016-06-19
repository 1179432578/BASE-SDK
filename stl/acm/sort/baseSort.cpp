//
//  baseSort.cpp
//  stl
//
//  Created by lewis on 16/6/17.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//基数排序
//http://www.acmerblog.com/radix-sorting-5601.html

//基数排序是一种稳定排序，从低位到高位进行排序，低位确定的次序，只有高位不同时位置关系才能发生变化，相同则不会。
//复杂度O(n)，用一个辅助数组排序，还有一个辅助数组计数

//获得基
int getBase(int d, int exp){
    while (exp) {
        d /= 10;
        exp--;
    }
    
    return d % 10;
}

void baseSort(int a[], int size, int length){
    int *b = new int[size];
    int c[10] = {0};//[0, 9]

    int base;
    for (int k=0; k<length; k++) {
        memset(c, 0, 10*sizeof(int));//每次重置基数个数
        
        for (int i=0; i<size; i++) {//求每个基数的个数
            base = getBase(a[i], k);
            c[base]++;
        }
        
        for (int i=0; i<9; i++) {
            printf("%d ", c[i]);
        }
         printf("\n");
        for (int i=1; i<10; i++) {//求每个基数小于等于它的个数
            c[i] += c[i-1];
        }
        
        for (int i=size-1; i>=0; i--) {//稳定排序
            base = getBase(a[i], k);
            b[c[base]-1] = a[i];
            c[base]--;
        }
        
        for (int i=0; i<size; i++) {//写回原数组，可以改进
            a[i] = b[i];
        }
        
        for (int i=0; i<size; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    
    delete [] b;
}

void testBaseSort(){
    int a[] = {34, 332, 324, 22, 22, 34, 3223, 222, 93};
    int n = sizeof(a)/sizeof(int);
    
    baseSort(a, n, 4);
    
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }

}