//
//  sort_link_list.cpp
//  stl
//
//  Created by lewis on 16/6/8.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

/*
 *Sort a linked list in O(n log n) time using constant space complexity.
 *http://www.acmerblog.com/leetcode-sort-list-5982.html
 *https://leetcode.com/problems/sort-list/#
 */

/*使用归并排序，数组用归并空间复杂度是线性的而不是常量，但链表合并是不需要额外空间的*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        /*使用快慢指针找到中点*/
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *list2 = slow->next;
        slow->next = NULL;
        head = sortList(head);/*[head, slow]*/
        list2 = sortList(list2);/*[slow->next, nil)*/
        
        return merge(head, list2);
    }
    
    ListNode* merge(ListNode *list1, ListNode *list2){
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode newHead = ListNode(0);/*链表头不存储实际数据*/
        ListNode *p = &newHead;/*链表最后一个元素*/
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            }
            else{
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        
        /*将剩下的链表直接连起来*/
        if (list1) {
            p->next = list1;
        }
        else{
            p->next = list2;
        }
        
        return newHead.next;
    }
};

void testSortLinkedList(){
    ListNode n1(87);
    ListNode n2(817);
    ListNode n3(7);
    ListNode n4(37);
    ListNode n5(83);
    ListNode n6(11);
    ListNode n7(342);
    ListNode n8(72);
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = NULL;
    
    Solution s;
    ListNode *l = s.sortList(&n1);
    
    while (l) {
        printf("%d ", l->val);
        l = l->next;
    }
}
