//
//  binarySerch.cpp
//  stl
//
//  Created by lewis on 16/6/4.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "binarySerch.h"

int bs(int a[], int left, int right, int x){
    if (left >= right) {
        return -1;
    }
    
    int mid = (left + right) / 2;
    if (a[mid] == x) {
        return mid;
    }
    /*每次分成两个子问题，其中有一个没解，直接忽略*/
    else if (a[mid] > x){
        return bs(a, left, mid-1, x);
    }
    else{
        return bs(a, mid+1, right, x);
    }
}

int binarySearch2(int a[], int num, int x){
    return bs(a, 0, num-1, x);
}

void testBinarySearch2(){
    int a[] = {2, 54, 77, 343, 3456, 34344};
    
    int pos = binarySearch2(a, 6, 2);
    
    printf("%d %d\n", pos, a[pos]);
}