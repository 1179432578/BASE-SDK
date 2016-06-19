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
    BinaryNode *left;
    BinaryNode *right = NULL;
    BinaryNode(int v):val(v), left(NULL), right(NULL){}
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

//计算父结点到子结点距离
int calDis(BinaryNode *node, int n1){
    if (!node) {
        return -1;//assert(node)
    }
    if (node->val == n1) {
        return 0;
    }
    
    int dst = calDis(node->left, n1);//左树中查找
    if (dst != -1) {
        return dst + 1;
    }
    
    dst = calDis(node->right, n1);//在右树种查找
    if (dst != -1) {
        return dst + 1;
    }
    
    return -1;
}

//计算两个结点距离
int calDistance(BinaryNode *root, int n1, int n2){
    BinaryNode *lca = findLCA(root, n1, n2);
    
    int dst1 = calDis(lca, n1);
    int dst2 = calDis(lca, n2);
    
    return dst1 + dst2;
}

void testCalDistance(){
    /*
        1
       / \
      2   3
     */
    BinaryNode root(1);
    root.left = new BinaryNode(2);
    root.right = new BinaryNode(3);
    
    printf("%d\n", calDistance(&root, 1, 3));
}