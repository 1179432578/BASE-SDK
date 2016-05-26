//
//  help.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/26.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "help.h"

void inverse(int a[], int n){
    int tmp;
    for (int i=0; i<n/2; i++) {
        tmp = a[n-1-i];
        a[n-1-i] = a[i];
        a[i] = tmp;
    }
}

void visit(int a[], int n){
    for (int i=0; i<n; i++) {
        printf(i != n-1 ? "%d ":"%d\n", a[i]);
    }
}