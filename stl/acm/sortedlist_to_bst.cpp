//
//  sortedlist_to_bst.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/15.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//把升序链表转化为二叉搜索树
//http://www.acmerblog.com/convert-sorted-list-to-binary-search-tree-6124.html
//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/


//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {//使用快慢指针与递归解决
        if (!head) {
            return NULL;
        }
        if (head && !head->next) {
             return new TreeNode(head->val);
        }
        
        ListNode *preSlow = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            preSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *mid = new TreeNode(slow->val);
        
        if (preSlow) {
            preSlow->next = NULL;
            mid->left = sortedListToBST(head);
        }
        
        if (slow->next) {
            mid->right = sortedListToBST(slow->next);
        }
        
        return mid;
    }
    
};