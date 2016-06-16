//
//  findAllAncestor.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/16.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//找出二叉树中某个节点的所有祖先节点
//http://www.acmerblog.com/ancestors-of-a-given-node-6048.html

//方法：使用递归解决
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


bool findAllAncestor(TreeNode *t, int targetVal){
    if (!t) {
        return false;
    }
    
    //递归结束条件
    if (t->val == targetVal) {
        return true;
    }
    
    if (findAllAncestor(t->left, targetVal) ||
        findAllAncestor(t->right, targetVal)) {
        printf("%d ", t->val);
        return true;
    }
    
    return false;
}

void testFindAllAncestor(){
    /*构建树
                1
               / \
              2   4
             /     \
            3       5
     */
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(5);
    
    findAllAncestor(root, 5);
}