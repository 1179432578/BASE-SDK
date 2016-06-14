//
//  btree_findLCA.cpp
//  stl
//
//  Created by lewis on 16/6/14.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//寻找二叉树两个节点的最低公共祖先
//http://www.acmerblog.com/lca-lowest-common-ancestor-5574.html

struct BinaryNode{
    int val;
    BinaryNode *left = NULL;
    BinaryNode *right = NULL;
};

//使用递归的方法查找lca，如果结点的左子树与右子树分别包含n1与n2，那么此结点就是lca
//否则lca在子结点中，继续递归进行查找。
BinaryNode* findLCA(BinaryNode *root, int n1, int n2){
    if (root->val == n1 || root->val == n2) {
        return root;
    }
    
    BinaryNode *leftLca = findLCA(root->left, n1, n2);
    BinaryNode *rightLca = findLCA(root->right, n1, n2);
    
    if (leftLca && rightLca) {
        return root;
    }
    
    return leftLca ? leftLca : rightLca;
}