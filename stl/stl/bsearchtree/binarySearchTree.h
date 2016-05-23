//
//  binaryTree.hpp
//  stl
//
//  Created by 鲁飞 on 16/5/9.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

/**************************binary search tree******************************/

//http://www.cnblogs.com/elaron/archive/2013/04/11/3015155.html
//二叉树
//二叉树的创建、查找、删除
//可能创建的一颗二叉树是线性的，那么它的查找效率就跟数组一样低了
//这个二叉树带有头结点，没头结点变成不方便，代码要写很多，还容易出错

typedef struct BtreeNode{
    int e;
    struct BtreeNode *left;
    struct BtreeNode *right;
    struct BtreeNode *parent;
}BtreeNode;

typedef BtreeNode Btree;

//带头结点的
Btree* makeBtree();

//头结点的左孩子为树根
void insertToBtree(Btree **t, int e, Btree *parent);

void deleteFromBtree(Btree *t, int e);

BtreeNode* searchFromBtree(Btree *t, int e);

void visitBtree(Btree *t);

#endif /* binaryTree_hpp */
