//
//  graph.hpp
//  stl
//
//  Created by lewis on 16/5/29.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
//后面实现c++std
#include <vector>

/*无向图的邻接表
 *
 */

typedef struct GraphVertex{
//    char *id;
    int identity;
    std::vector<int> adjanceVertices;//邻接顶点
}GraphVertex;

typedef struct Graph{
    GraphVertex **vertices;
    int count;
}Graph;

Graph* makeGraph(int vertexCount);

void addVertex(Graph *g, GraphVertex *v);

void testGraph();

#endif /* graph_hpp */
