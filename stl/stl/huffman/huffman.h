//
//  huffman.hpp
//  stl
//
//  Created by 鲁飞 on 16/5/16.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef huffman_hpp
#define huffman_hpp

#include <stdio.h>

//读取一串字节，为每个不同码元建立一个带权的节点

struct HuffmanNode{
    int weight;
    HuffmanNode *lchild;
    HuffmanNode *rchild;
    HuffmanNode *sibling;
    HuffmanNode *preSibling;
    char *str;
};

//h:有头结点的链表 每个元素是一个带权值的节点(一颗树)
//n:节点数
HuffmanNode* makeHuffmanTree(HuffmanNode *h, int n);

//编码
void huffmanCode(HuffmanNode *a);

//链表相关操作 带头结点的双向链表
HuffmanNode* makeList();

void insertList(HuffmanNode *h, char *str, int weight);


//huffman test function
void testHuffman();

#endif /* huffman_hpp */
