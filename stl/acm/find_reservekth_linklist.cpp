//
//  find_reservekth_linklist.cpp
//  stl
//
//  Created by lewis on 16/6/8.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

/*
 *题目：输入一个单向链表，输出该链表中倒数第k个结点。链表的倒数第0个结点为链表的尾指针
 *http://www.acmerblog.com/interview-10-2438.html
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    /*思路：保持两个指针，让第一个指针先走k步，然后两指针一起走，
      当第一个指针到达尾指针，第二个指针位置正好是倒数第k个结点*/
    ListNode* findRKth(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        int n = 0;
        while (p1 && n < k) {/*走k步*/
            p1 = p1->next;
            n++;
        }
        
        if (!p1) {/*链表长度小于k*/
            return NULL;
        }
        
        /*p1 p2一起前进，直到p1到链表尾*/
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p2;
    }
};

void testFindKthInLinkedList(){
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
    ListNode *l = s.findRKth(&n1, 7);
    
    printf("%d\n", l->val);
}