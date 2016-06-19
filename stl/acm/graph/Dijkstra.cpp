//
//  Dijkstra.cpp
//  stl
//
//  Created by lewis on 16/6/19.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#define INFINITY INT_MAX

//单源最短路径
//求某个点到所有点的最短路径，处理有向图
//方法：使用贪心算法，每次求邻近点路径长，如果结果比之前求得的短就把当前结果作为路径长
//为了方便处理，不能使用队列处理每个顶点
//每次选择一个路径最短的未处理顶点进行处理

struct VertexEntry{
    int *adjustVertex;//邻接顶点表
    int *adjustVertexWeight;//邻接顶点的权
    int adjustVertexNum;
    bool known;//是否被处理
    int dst;//路径长
    int path;//到达此顶点的顶点 -1表示没顶点到达它
    VertexEntry(){}
    VertexEntry(bool k, int d, int p, int num, ...){
        known = k;
        dst = d;
        path = p;
        adjustVertexNum = num;
        adjustVertex = new int[num];
        adjustVertexWeight = new int[num];
        
        va_list ap;
        va_start(ap, num);
        
        int v,w;
        for(int i=0; i<num; i++){
            v = va_arg(ap, int);
            w = va_arg(ap, int);
            adjustVertex[i] = v;
            adjustVertexWeight[i] = w;
        }
        
        va_end(ap);
    }
};

//求最短路径
//start:开始顶点
//n:顶点数
void dijkstra(VertexEntry* t, int n){
    int unknownVertex;//处理的顶点索引
    int minDst;
    
    while (true) {
        unknownVertex = -1;//表示当前没有处理的点
        minDst = INFINITY;
        
        //找到当前路径最短的点
        for (int i=0; i<n; i++) {
            if (!t[i].known && t[i].dst < minDst) {
                unknownVertex = i;
                minDst = t[i].dst;
            }
        }
        
        if (unknownVertex == -1) {//没有要处理的点了
            break;
        }
        
        //对邻接顶点进行处理
        for (int i=0; i<t[unknownVertex].adjustVertexNum; i++) {
            int adjustVertex = t[unknownVertex].adjustVertex[i];
            int weight = t[unknownVertex].adjustVertexWeight[i];
            int dst = t[unknownVertex].dst + weight;
            
            if (dst < t[adjustVertex].dst) {
                t[adjustVertex].dst = dst;
                t[adjustVertex].path = unknownVertex;
            }
        }
        
        t[unknownVertex].known = true;//表示处理过了
    }
}

void printPath(VertexEntry *t, int v){
    if (t[v].path != -1) {
        printPath(t, t[v].path);
    }
    
    printf("->%d", v+1);
}

void TestDijkstra(){
    VertexEntry v[7];
    
    //求v0到v1-v5路径长
    v[0] = VertexEntry(false, 0, -1, 2, 1, 2, 3, 1);//1 3
    v[1] = VertexEntry(false, INFINITY, -1, 2, 3, 3, 4, 10);
    v[2] = VertexEntry(false, INFINITY, -1, 1, 0, 4);
    v[3] = VertexEntry(false, INFINITY, -1, 4, 2, 2, 4, 2, 5, 8, 6, 4);
    v[4] = VertexEntry(false, INFINITY, -1, 1, 6, 6);
    v[5] = VertexEntry(false, INFINITY, -1, 0);
    v[6] = VertexEntry(false, INFINITY, -1, 1, 5, 1);
    
    dijkstra(v, 7);
    
    for (int i=0; i<7; i++) {
        printPath(v, i);
        printf("\n");
    }
}