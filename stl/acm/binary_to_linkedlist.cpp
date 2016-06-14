//
//  binary_to_linkedlist.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/14.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
//http://www.acmerblog.com/great-tree-list-5814.html
struct BinaryNode{
    int val;
    BinaryNode *left = NULL;//pre
    BinaryNode *right = NULL;//next
};

//使用中序遍历递归的把二叉树转化为链表
void btl(BinaryNode *btree){
    //递归结束条件:当节点是叶子结点时直接返回
    if (!btree->left && !btree->right) {
        return;
    }
    BinaryNode *leftLastNode = NULL;
    BinaryNode *rightFirstNode = NULL;
    //对左子树进行变换并获得最大结点
    if (btree->left){
        btl(btree->left);
        //获得左子树最大/最后一个结点
        leftLastNode = btree->left;
        while (leftLastNode->right) {
            leftLastNode = leftLastNode->right;
        }
    }
    //对右子树进行变换并获得最小结点
    if (btree->right) {
        btl(btree->right);
        //获得右子树最小/第一个结点
        rightFirstNode = btree->right;
        while (rightFirstNode->left) {
            rightFirstNode = rightFirstNode->left;
        }
    }
    
    //把左子树最大结点与右子树最小结点与父结点合并
    if (leftLastNode && rightFirstNode) {
        btree->left = leftLastNode;
        leftLastNode->right = btree;
        btree->right = rightFirstNode;
        rightFirstNode->left = btree;
    }
    else if (leftLastNode){
        leftLastNode->right = btree;
        btree->left = leftLastNode;
    }
    else if (rightFirstNode){
        btree->right = rightFirstNode;
        rightFirstNode->left = btree;
    }
  
}

//二叉树转化为链表
BinaryNode* btreeToLinkedlist(BinaryNode *btree){
    btl(btree);
    
    //找到最小结点并返回
    BinaryNode *p = btree;
    while (p->left) {
        p = p->left;
    }
    
    return p;
}

void insertBtree(BinaryNode *node, int val){
    if (!node) {
        return;
    }
    
    if (val > node->val) {
        if (!node->right) {
            BinaryNode *p = new BinaryNode;
            p->val = val;
            node->right = p;
            return;
        }
        insertBtree(node->right, val);
    }
    else{
        if (!node->left) {
            BinaryNode *p = new BinaryNode;
            p->val = val;
            node->left = p;
            return;
        }
        insertBtree(node->left, val);
    }
}

//创建一个二叉查找树
BinaryNode* makeBtree(int a[], int n){
    BinaryNode *root = NULL;
    for (int i=0; i<n; i++) {
        if (i==0) {
            root = new BinaryNode;
            root->val = a[0];
        }
        else{
            insertBtree(root, a[i]);
        }
    }
    
    return root;
}

void testBtreeToLinkedlist(){
    //构建一个二叉查找数
//    BinaryNode n1;
//    n1.val = 20;
//    BinaryNode n2;
//    n2.val = 50;
//    BinaryNode n3;
//    n3.val = 30;
//    BinaryNode n4;
//    n4.val = 90;
//    BinaryNode n5;
//    n5.val = 10;
//    
//    n1.right = &n2;
//    n2.left = &n3;
//    n2.right = &n4;
//    n1.left = &n5;
    int a[] = {3, 45, 63, 112,  45, 55, 33, 22, 22, 234, 3, 0};
    BinaryNode *btree = makeBtree(a, sizeof(a)/sizeof(int));
    
    BinaryNode *list = btreeToLinkedlist(btree);
    
    while (list) {
        printf("%d ", list->val);
        list = list->right;
    }
}
