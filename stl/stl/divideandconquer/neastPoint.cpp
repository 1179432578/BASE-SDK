//
//  neastPoint.cpp
//  stl
//
//  Created by lewis on 16/6/4.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "neastPoint.h"
#include <math.h>

struct Point{
    int x;
    int y;
};

/*按x坐标进行排序*/
void sortPoints(int num, Point *points){
    //使用插入算法进行排序
    int j, x, y;
    for(int i=1; i<num; i++){
        x = points[i].x;
        y = points[i].y;
        for (j=i-1; j>=0; j--) {
            if (points[j].x > x) {
                points[j+1].x = points[j].x;
                points[j+1].y = points[j].y;
            }
            else{
                break;
            }
        }
        
        points[j+1].x = x;
        points[j+1].y = y;
    }
}

/*分治与合并*/
//out:p1 p2
void np(Point pts[], int left, int right, int *p1, int *p2){
    //一个点直接返回无解
    if (right - left == 0) {
        *p2 = *p1 = -1;
        return;
    }
    //2个点解就为这两点
    else if(right - left ==1){
        *p1 = left;
        *p2 = right;
        return;
    }
    else if(right - left > 1){
        int mid = (left + right) / 2;
        int lp1, lp2, rp1, rp2;
        
        //分治
        np(pts, left, mid, &lp1, &lp2);
        np(pts, mid+1, right, &rp1, &rp2);
        
        //合并
        int dl = sqrt(pow(pts[lp1].x - pts[lp2].x, 2) + pow(pts[lp1].y - pts[lp2].y, 2));
        int dr = sqrt(pow(pts[rp1].x - pts[rp2].x, 2) + pow(pts[rp1].y - pts[rp2].y, 2));
        int d = dl < dr ? (*p1=lp1, *p2=lp2, dl) : (*p1=rp1, *p2=rp2, dr);
        printf("d:%d %d %d\n", d, *p1, *p2);
        
        
        for (int i=left; i<=mid; i++) {
            //里分割线大于等于d的点不满足要求
            if (pts[mid].x - pts[i].x >= d) {
                continue;
            }
            else{
                //可以简化
                for (int j=mid+1; j<=right; j++) {
                    if (pts[j].x - pts[mid].x >= d) {
                        continue;
                    }
                    else{
                        int d2 = sqrt(pow(pts[i].x - pts[j].x, 2) + pow(pts[i].y - pts[j].y, 2));
                        printf("%d %d %d\n", i, j, d2);
                        
                        if (d2 < d) {
                            *p1 = i;
                            *p2 = j;
                            d = d2;
                        }
                    }
                }
            }
        }
    }
    
}

void neastPoint(int num, Point pts[], int *p1, int *p2){
    sortPoints(num, pts);
    
    np(pts, 0, num-1, p1, p2);
}

void testNeastPoint(){
    Point points[8] = {{20, 4}, {23, 23}, {13, 26}, {1, 4}, {2,7}, {78, 23}, {79, 23}, {12, 18}};
    sortPoints(8, points);
    
    for (int i=0; i<8; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
    
    int p1, p2;
    neastPoint(8, points, &p1, &p2);
    printf("p1:(%d, %d)\n", points[p1].x, points[p1].y);
    printf("p2:(%d, %d)\n", points[p2].x, points[p2].y);
    printf("d:%f\n", sqrt(pow(points[p1].x - points[p2].x, 2) + pow(points[p1].y - points[p2].y, 2)));
}