//
//  gcd.cpp
//  stl
//
//  Created by lewis on 16/6/18.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//欧几里得求最大公约数
//http://www.acmerblog.com/extend-gcd-5610.html

//a=qb+r gcd(a,b)=gcd(b,r), if r=0, gcd(b,r)=b

int gcd(int a, int b){
    int tmp;
    while (b) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    
    return a;
}