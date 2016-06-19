//
//  activity.cpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "activity.h"

void activityArrangement(int n, int si[], int fi[], int a[]){
    a[1] = true;
    int j = 1;
    
    for (int i = 2; i <= n; i++) {
        if (si[i] >= fi[j]) {
            a[i] = true;
            j = i;
        }
        else
            a[i] = false;
    }
}

void testActivityArrangement(){
    int n = 5;
    int si[] = {-1, 0, 3, 4, 7, 2,};
    int fi[] = {-1, 4, 5, 6, 10, 11};
    int a[6];
    
    activityArrangement(n, si, fi, a);
    
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            printf("[si, fi)->[%d, %d) \n", si[i], fi[i]);
        }
    }
}