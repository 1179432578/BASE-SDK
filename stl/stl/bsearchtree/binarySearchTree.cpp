//
//  binaryTree.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/9.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "binarySearchTree.h"

Btree* makeBtree(){
    Btree *t = new BtreeNode;
    t->left = 0;
    t->right = 0;
    t->parent = 0;
    
    return t;
}


void insertToBtree(Btree **t, int e, Btree *parent){
    if (!*t) {
        *t = new BtreeNode;
        (*t)->left = 0;
        (*t)->right = 0;
        (*t)->parent = parent;
        (*t)->e = e;
    }
    else{
        if (e < (*t)->e) {
            insertToBtree(&((*t)->left), e, *t);
        }
        else{
            insertToBtree(&((*t)->right), e, *t);
        }
    }
}

BtreeNode* searchFromBtree(Btree *t, int e){
    if (t) {
        if (e == t->e) {
            return t;
        }
        else if (e < t->e){
            return searchFromBtree(t->left, e);
        }
        else{
            return searchFromBtree(t->right, e);
        }
    }
    
    return 0;
}

BtreeNode* searchMinFromBtree(Btree *t){
    BtreeNode *p = t;
    while (p->left) {
        p = p->left;
    }
    
    return p;
}

//在删除节点时有三种情况：
//
//1）要删除的节点为叶节点
//
//　　那么直接删除即可。
//
//2）要删除的节点有一个子节点
//
//　　那么删除掉该节点，并用其唯一的子节点代替自己的位置即可。
//
//3）要删除的节点有两个子节点
//
//　　那么首先要找到该节点的右子树的最小值节点k，然后将该k替换掉待删除节点。
//
//最坏情况下，时间复杂度为O(h)+指针的移动开销。
void deleteFromBtree(Btree *t, int e){
    BtreeNode *node = searchFromBtree(t, e);
    
    if (node) {
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = 0;
            }
            else{
                node->parent->right = 0;
            }
        }
        
        //没有孩子 那么直接删除即可
        if (!node->left && !node->right) {
            //删除根节点
            if (node->parent->left == node) {
                node->parent->left = 0;
            }
            delete node;
        }
        //只有一个孩子
        else if ((node->left && !node->right) || (!node->left && node->right)){
            if (node->left) {
                //node是父亲的左节点
                if (node->parent->left == node) {
                    node->parent->left = node->left;
                }
                //
                else{
                    node->parent->right = node->left;
                }
                
                node->left->parent = node->parent;
                delete node;
            }
            else{
                //node是父亲的左节点
                if (node->parent->left == node) {
                    node->parent->left = node->right;
                }
                else{
                    node->parent->right = node->right;
                }
                
                node->right->parent = node->parent;
                delete node;
            }
         }
        //有两个孩子
        else{
            //找出右子树中最小的节点
            BtreeNode *minNode = searchMinFromBtree(node->right);
            
            //node是父亲的左节点
            if (node->parent->left == node) {
                node->parent->left = minNode;
                //设置以前父节点孩子为NULL
                if (minNode->parent->left == minNode) {
                    minNode->parent->left = 0;
                }
                else{
                    minNode->parent->right = 0;
                }
                
                //设置孩子节点
                minNode->left = node->left;
                minNode->right = node->right;
                if (node->left) {
                    node->left->parent = minNode;
                }
                if (node->right) {
                    node->right->parent = minNode;
                }
                
                delete node;
            }
            //
            else{
                node->parent->right = minNode;
                //设置以前父节点孩子为NULL
                if (minNode->parent->left == minNode) {
                    minNode->parent->left = 0;
                }
                else{
                    minNode->parent->right = 0;
                }
                
                //设置孩子节点
                minNode->left = node->left;
                minNode->right = node->right;
                if (node->left) {
                    node->left->parent = minNode;
                }
                if (node->right) {
                    node->right->parent = minNode;
                }
                
                delete node;
            }

        }
    }
}

#include "stdio.h"
void visitBtree(Btree *t){
    if (t) {
        visitBtree(t->left);
        printf("%d\n", t->e);
        visitBtree(t->right);
    }
}

