//
//  graph.cpp
//  stl
//
//  Created by lewis on 16/5/29.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "graph.h"

Graph* makeGraph(int vertexCount){
    Graph *g = new Graph;
    g->vertices = new GraphVertex*[vertexCount];
    g->count = vertexCount;
    
    return g;
}

void addVertex(Graph *g, GraphVertex *v){
    g->vertices[v->identity]  = v;
}

void testGraph(){
    Graph *g = makeGraph(4);
    
    GraphVertex v0;
    v0.identity = 0;
    v0.adjanceVertices.push_back(1);
    v0.adjanceVertices.push_back(2);
    v0.adjanceVertices.push_back(3);
    addVertex(g, &v0);
    
    GraphVertex v1;
    v1.identity = 1;
    v1.adjanceVertices.push_back(2);
    v1.adjanceVertices.push_back(3);
    addVertex(g, &v1);
    
    GraphVertex v2;
    v2.identity = 2;
    v2.adjanceVertices.push_back(2);
    v2.adjanceVertices.push_back(3);
    addVertex(g, &v2);
    
    GraphVertex v3;
    v3.identity = 3;
    v3.adjanceVertices.push_back(2);
    v3.adjanceVertices.push_back(3);
    addVertex(g, &v3);
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<g->vertices[i]->adjanceVertices.size(); j++) {
            printf("(%d, %d) ", i, g->vertices[i]->adjanceVertices[j]);
        }
        printf("\n");
    }
}