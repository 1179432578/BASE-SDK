//
//  hashtable.hpp
//  stl
//
//  Created by lewis on 16/5/11.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef hashtable_hpp
#define hashtable_hpp

#include <stdio.h>

//拉链法散列表 不使用头结点
typedef struct HashNode{
    int key;
    struct HashNode *next;
};

typedef struct HashTable{
    int tableSize;
    HashNode* *list;
};

HashTable* initHashTable(int size);

HashNode* find(HashTable *t, int key);

void insert(HashTable *t, int key);

void testHashTable();

//开放定址法
enum NodeType {EXISTED, EMPTY, DELETED};

struct HashNode2{
    int key;
    NodeType t;
};

struct HashTable2{
    int size;
    HashNode2 *list;
};

HashTable2* initHashTable2(int size);

int find(HashTable2 *t, int key);

void insert(HashTable2 *t, int key);

void testHashTable2();

#endif /* hashtable_hpp */
