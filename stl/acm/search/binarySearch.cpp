//
//  binarySearch.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/17.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//二分搜索的一些算法
//http://www.acmerblog.com/ubiquitous-binary-search-5345.html

//给一个有N个互不相同的元素的已排序数组，返回小于或等于给定key的最大元素
//方法：最后保留一个范围[l, r] a[l]<=key a[r]>key，a[l]就是要求的元素
int searchLessOrEqual(int a[], int n, int key){
    if (key < a[0]) {
        return -1;//无解
    }
    else if (key >= a[n -1]){
        return a[n-1];
    }
    
    int l = 0;
    int r = n - 1;
    
    int mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        
        if (a[mid] <= key) {
            l = mid;
        }
        else{
            r = mid;
        }
    }
    
    return a[l];
}

void testSearchLessOrEqual(){
    int a[] = {1, 4, 5, 7, 43, 67, 99, 100};
    
    int e = searchLessOrEqual(a, sizeof(a)/sizeof(int), 100);
    printf("%d\n", e);
}
