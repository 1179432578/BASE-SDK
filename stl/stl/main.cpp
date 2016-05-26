//
//  main.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/5.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "testPass.h"

#include <functional>
#include "IDecorator.h"
#include "factorymethod.h"
#include "hashtable.h"
#include "linkedlist.h"
#include "stack.h"
#include "PriorityQueue.h"
#include "activity.h"
#include "knapsack.h"
#include "singleton.h"
#include "command.h"

void print(int a[], int n){
    int i = 0;
    while (i < n) {
        printf("%d ", a[i++]);
    }
    printf("\n");
}

int* generateLargeArray(int n){
    int *a = new int[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = random() % 1024;
    }
    
    return a;
}
//3d
//http://blog.csdn.net/zsq306650083/article/details/8773996
//http://blog.csdn.net/pizi0475/article/details/9840921
//计算函数执行时间
void calculateFunExcuteTime(std::function<void()> fun, const char *funName){
    clock_t t =  clock();
    fun();
    t = clock() - t;
    
    printf("%s: %fs\n", funName, 1.0f * t / CLOCKS_PER_SEC);
}

int main(int argc, const char * argv[]) {
//    const int SIZE =100000;
//    int *a;
//    calculateFunExcuteTime([&a](){a = generateLargeArray(SIZE);}, "generateLargeArray");
    
    testFindKthMax();
    
}
