//
//  norecursion_visit.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/16.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>

//二叉树非递归先序遍历
//http://www.acmerblog.com/iterative-preorder-traversal-5853.html

//方法1：使用辅助栈，把根结点先插入栈中，然后遍历，每遍历一个结点就把她的右孩子跟左孩子压栈，
//然后继续遍历栈中结点，每遍历一个就先把右孩子压入，再压入左孩子，如果访问的结点没有孩子，就
//从栈中弹出，访问栈中剩下元素，如果没有元素了，算法结束

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Stack{
public:
    Stack(int n) : m_capacity(n), m_top(-1){
        m_arr = new TreeNode*[n];
    }
    
    void push(TreeNode *node){
        m_top++;
        checkCapacity(m_top+1);
        
        m_arr[m_top] = node;
    }
    
    TreeNode* pop(){
        assert(m_top > -1);
        return m_arr[m_top--];
    }
    
    bool isEmpty(){
        return m_top == -1;
    }
    
    void checkCapacity(int n){
        if (n > m_capacity) {
            TreeNode **arr = new TreeNode*[n];
            memcpy(arr, m_arr, m_capacity);
            delete [] m_arr;
            m_arr = arr;
            m_capacity = n;
        }
    }
private:
    TreeNode **m_arr;
    int m_top;
    int m_capacity;
};

//先序非递归遍历二叉树
void preOrder(TreeNode *t){
    if (!t) {
        return;
    }
    
    Stack s(8);
    s.push(t);//把树根压栈
    TreeNode *p;
    while (!s.isEmpty()) {
        p  = s.pop();//弹出栈顶元素访问
        printf("%d ", p->val);
        
        //把孩子压入栈中
        if (p->right) {//先压右孩子
            s.push(p->right);
        }
        
        if (p->left) {//再压左孩子
            s.push(p->left);
        }
    }
}

void testPreOreder(){
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
    
    preOrder(root);
}

//方法2：使用辅助栈，每访问一次，把它的右孩子压入栈中，然后继续访问左孩子，同时压入右孩子。
//当没有左右孩子时，从栈中去一个继续进行之前步骤
void preOrder2(TreeNode *t){
    if (!t) {
        return;
    }
    
    Stack s(8);
    s.push(t);
    
    TreeNode *p;
    while (!s.isEmpty()) {
        p = s.pop();
        printf("%d ", p->val);
        
        while (p) {
            if (p->left) {
                printf("%d ", p->left->val);

            }
            
            if (p->right) {
                s.push(p->right);
            }
            
            p = p->left;
        }
    }
}

void testPreOreder2(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(5);
    
    preOrder2(root);
}