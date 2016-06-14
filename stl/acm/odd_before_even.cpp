//
//  odd_before_even.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/14.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "stdio.h"

/*
 *调整数组顺序使奇数位于偶数前面
 *http://www.acmerblog.com/offer-6-2429.html
 */

//数组中奇偶相对位置没要求，可以使用两个指针，一个前一个后，然后把奇偶进行交换，跟快排的交换一样
//有要求的话，就用两个数组，一个奇数数组、一个偶数数组，最后把这两个数组再写回原来数组
void adjustArray(int a[], int n){
    int i = 0;//奇数指针
    int j = n - 1;//偶数指针
    
    while (i < j) {
        //找到一个偶数
        while (i<j && a[i]%2) {
            i++;
            
        }
        //找到一个奇数
        while (j>i && a[j]%2==0) {
            j--;
            
        }
        //交换奇数偶数
        if (a[i] != a[j]) {
            a[i] = a[i] + a[j];
            a[j] = a[i] - a[j];
            a[i] = a[i] - a[j];
        }
        
        i++;
        j++;
    }
}

void testAdjustArray(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 33};
    int n =  sizeof(a)/sizeof(int);
    adjustArray(a, n);
    
    for (int i=0; i<n; i++) {
        printf(i!=n-1 ? "%d " : "%d\n", a[i]);
    }
}