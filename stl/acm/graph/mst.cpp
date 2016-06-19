//
//  graph.cpp
//  stl
//
//  Created by lewis on 16/6/18.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>

//最小生成树(minimum spanning tree)
//http://www.acmerblog.com/greedy-kruskal-spanning-tree-mst-5326.html

//使用Kruskal算法解决，对图的边根据权重进行排序，然后使用并查集把权重小的边一条条并进来，
//在合并前先进行查找，如果边的两个顶点在两个集合中就合并，否则丢弃(在一个集合里找到，说明形成环路了)。

struct Edge{
    int src, dst;
    int weight;
};

struct Graph{
    Graph(int vNum, int eNum, ...){
        vertexNum = vNum;
        edgeNum = eNum;
        edges = new Edge[edgeNum];
        
        //解析变长参数
        va_list ap;
        va_start(ap, eNum);
        for (int i=0; i<eNum; i++) {
            edges[i].src = va_arg(ap, int);
            edges[i].dst = va_arg(ap, int);
            edges[i].weight = va_arg(ap, int);
        }
        va_end(ap);
    }
    
    int edgeNum;//边数
    int vertexNum;//顶点数
    Edge *edges;//所有边
};

//查找树根
int find(int a[], int e){
    while (a[e] != -1) {
        e = a[e];
    }
    
    return e;
}

//把e2并到e1
void setUnion(int a[], int e1, int e2){
    a[e2] = e1;
}

Edge * kruaskalMST(Graph *g){
    //使用插入排序
    Edge edge;
    int j;
    for (int i=1; i<g->edgeNum; i++) {
        edge = g->edges[i];
        for (j=i-1; j>=0; j--) {
            if (g->edges[j].weight > edge.weight) {
                g->edges[j+1] = g->edges[j];
            }
            else
                break;
        }
        
        g->edges[j+1] = edge;
    }
    
    //使用并查集构建最小生成树 N个顶点有N-1条顶点
    Edge *result = new Edge[g->vertexNum-1];
    int *sets = new int[g->vertexNum];//存储每个数字对应顶点的相连顶点数字，开始时都是单独顶点，值为-1
    for (int i=0; i<g->vertexNum; i++) {
        sets[i] = -1;
    }
    
    //对每条边进行检查，如果顶点在不同连通集合中，就把两个连通集合合并成一个连通集合，此连通集合没有环路
    int r1, r2;//树根
    int addCount = 0;
    for (int i=0; i<g->edgeNum; i++) {
        r1 = find(sets, g->edges[i].src);
        r2 = find(sets, g->edges[i].dst);
        if (r1 != r2) {//两顶点在不同连通图中
//            if (r1 == -1) {//r1为树根，把r1并到r2所在连通图
//                setUnion(sets, r2, r1);
//            }
//            else{
                setUnion(sets, r1, r2);
//            }
            
            result[addCount++] = g->edges[i];//加入结果中
            
            if (addCount >= g->vertexNum-1) {//最大N-1个边
                break;
            }
        }
    }
    
    delete [] sets;
    return result;
}

void testKruaskalMST(){
    Graph g(4, 6, 0, 1, 16, 1, 2, 1, 2, 3, 4, 3, 0, 7, 0, 2, 12, 1, 3, 5);
    
    Edge *edges = kruaskalMST(&g);
    
    for (int i=0; i<g.vertexNum-1; i++) {
        printf("%d-->%d : %d\n", edges[i].src, edges[i].dst, edges[i].weight);
    }
}