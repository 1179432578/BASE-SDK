//
//  list_reserve.hpp
//  stl
//
//  Created by lewis on 16/5/30.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef list_reserve_hpp
#define list_reserve_hpp

#include <stdio.h>

/*功能: 反转单链表
 *
 */

/*链表也需要建立数据结构代码可以更清楚*/
/*链表节点*/
typedef struct Node{
    int data;
    struct Node *next;
}node;

/*用三个指针：一个指向前、一个当前、一个下一个*/
void reserve(Node **list);

/*往链表添加元素,头部插入*/
void listAdd(Node **list,int data);

/*打印链表中元素的值*/
void printList(Node *list);

/*just for test*/
void testListReserve();

#endif /* list_reserve_hpp */
