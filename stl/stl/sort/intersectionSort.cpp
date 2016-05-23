//
//  intersectionSort.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/6.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "sort.h"

void intersectionSort(int a[], int n){
    //每趟排序拿出的待排序元，将它插入前面已排好的序列中
    int sortItem;
    
    //n-1趟排序
    for (int i=1; i<n; i++) {
        //取出第i个元素
        sortItem = a[i];
        //将sortItem插入到已排好序的前i-1个元素中
        //sortItem与[0, i-1]的元素进行比较,将大于sortItem的元素后移
        int j;
        for (j=i-1; j>=0 && a[j]>sortItem; j--) {
            a[j+1] = a[j];
        }
        
        //上述循环退出可能是所有元素都比sortItem大，此时j=-1；或者j>=0,但是a[j]<=sortItem
        //不管那种情况，j+1处的元素要么后移了，要么就是sortItem本身
        a[j+1] = sortItem;
    }
}