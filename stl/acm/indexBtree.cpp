//
//  indexBtree.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/15.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//中序建立线索二叉树
//http://blog.163.com/zhoumhan_0351/blog/static/39954227200991293851204/

struct BNode{
    int val;
    BNode *left;
    BNode *right;
    int ltag;//0:child 1:thread前驱
    int rtag;//0:child 1:thread后继
};

static BNode *pre;//之前处理的结点
void inThread(BNode *node){
    if(!node){ return;}
    if (node->left) {//对左子树建立线索二叉树
        inThread(node->left);
    }
    
    //处理当前结点
    if (!node->left) {//左孩子为NULL，则指向前驱
        node->ltag = 1;
        node->left = pre;
    }
    if(!pre->right){//前驱右孩子为NULL，则指向后继
        pre->rtag = 1;
        pre->right = node;
    }
    
    pre = node;
    
    if(node->right){//对右子树建立线索二叉树
        inThread(node->right);
    }
}

//中序建立线索二叉树，需要建立一个头结点
BNode* inorderThreadBtree(BNode *t){
    BNode *head = new BNode;//线索头结点
    head->rtag = 1;//头结点后驱自己，表示结束
    head->right = head;
    head->ltag = 0;//左孩子指向树的根结点
    head->left = t;
    
    pre = head;
    inThread(t);//递归建立线索二叉树
    
    //最后一个结点线索化
    pre->rtag = 1;
    pre->right = head;
    head->right = pre;//head右孩子表示前驱
    
    return head;
}

//遍历线索二叉树
void visitThreadBtree(BNode *head){
    BNode *p = head->left;//头结点左孩子根结点
    if (!p) {
        return;
    }
    
    while (p && p != head) {
        while (p->ltag == 0) {//一直找到左孩子是线索的，它是线索二叉树第一个结点
            p = p->left;
        }
        printf("%d ", p->val);
        
        while (p->right && p->rtag == 1 && p->right != head) {//访问后继结点
            p = p->right;
            printf("%d ", p->val);
        }
        
        //后继结点找不到了，就到它的右子树中找后继
        p = p->right;
    }
}


void insertBtree(BNode *node, int val){
    if (!node) {
        return;
    }
    
    if (val > node->val) {
        if (!node->right) {
            BNode *p = new BNode;
            p->val = val;
            p->left = NULL;
            p->right = NULL;
            node->right = p;
            node->rtag = 0;
            return;
        }
        insertBtree(node->right, val);
    }
    else{
        if (!node->left) {
            BNode *p = new BNode;
            p->val = val;
            p->left = NULL;
            p->right = NULL;
            node->left = p;
            node->ltag = 0;
            return;
        }
        insertBtree(node->left, val);
    }
}

//创建一个二叉查找树
BNode* makeBtree2(int a[], int n){
    BNode *root = NULL;
    for (int i=0; i<n; i++) {
        if (i==0) {
            root = new BNode;
            root->val = a[0];
            root->left = NULL;
            root->right = NULL;
        }
        else{
            insertBtree(root, a[i]);
        }
    }
    
    return root;
}

void testVisitThreadBtree(){
    int a[] = {34, 23, 3435, 2, 333, 445, 111, 33, 11, 12};
    BNode *t = makeBtree2(a, sizeof(a)/sizeof(int));
    
    BNode *head = inorderThreadBtree(t);
    visitThreadBtree(head);
}