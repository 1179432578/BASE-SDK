//
//  fibonacci.cpp
//  stl
//
//  Created by lewis on 16/6/19.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//使用动态规划解决fibonacci，而不是递归，递归会存在许多子问题
//http://www.acmerblog.com/dynamic-programming-4577.html
//fibonacci: f0=1 f1=1 f2=f1+f0=2 f3=f2+f1=3 f4=5 f5=8 f6=13 f7=21


int fi(int *lookup, int n){
    if (lookup[n] == -1) {//查找不到
        if (n <= 1) {
            lookup[n] = 1;
        }
        else{
            lookup[n] = fi(lookup, n-1) + fi(lookup, n-2);
        }
    }
    
    return lookup[n];
}

int fibonacci(int n){
    int *lookup = new int[n+1];
    
    for (int i=0; i<=n; i++) {
        lookup[i] = -1;
    }
    
    return fi(lookup, n);
}

void testFibonacci(){
    printf("%d\n", fibonacci(6));
}