//
//  hashtable.cpp
//  stl
//
//  Created by lewis on 16/5/11.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "hashtable.h"
#include <string.h>

HashTable* initHashTable(int size){
    HashTable *t = new HashTable;
    
    t->tableSize = size;
    
    t->list = new HashNode*[size];
    memset(t->list, 0, sizeof(HashNode*) * size);
    
    return t;
}

HashNode* find(HashTable *t, int key){
    //calculate hash value
    int hash = key;
    //calculate position
    int pos = hash % t->tableSize;
    
    HashNode *p = t->list[pos];
    while (p) {
        if (p->key == key) {
            return p;
        }
        
        p = p->next;
    }
    
    return 0;
}

void insert(HashTable *t, int key){
    //这里定义hash表中存在key的节点时直接返回
    if (find(t, key)) {
        return;
    }
    
    //calculate hash value
    int hash = key;
    //calculate position
    int pos = hash % t->tableSize;
    
    HashNode *p = new HashNode;
    p->key = key;
    if (t->list[pos] == 0) {
        t->list[pos] = p;
        p->next = 0;
    }
    else{
        p->next = t->list[pos];
        t->list[pos] = p;
    }
}

//测试函数，以后每个有效代码都建立测试代码，创建一个代码测试库，实现公共需要的测试接口
void testHashTable(){
    HashTable *t = initHashTable(100);
    
    for (int i= 0; i < 1000; i++) {
        insert(t, i);
    }
    
    printf("测试查找是否正确\n");
    for (int i = 0; i < 100; i++) {
        HashNode *p = find(t, i);
        printf("%d == %d \n", i, p->key);
    }
    
    //打印hashtable每个位置处的链表元素
    HashNode *p;
    for (int i = 0; i < t->tableSize; i++) {
        printf("pos: %d->", i);
        p = t->list[i];
        while (p) {
            printf("%d ", p->key);
            p = p->next;
        }
        printf("\n");
    }
}

HashTable2* initHashTable2(int size){
    HashTable2 *t = new HashTable2;
    t->size = size;
    t->list = new HashNode2[size];
    
    for (int i=0; i < t->size; i++) {
        t->list[i].t = EMPTY;
    }
    return t;
}

int find(HashTable2 *t, int key){
    int pos = key*3 % t->size;//hash码就等于key。求hash码需要详细设计，减少冲突
    int collisionNum = 0;
//    printf("\n%d pos:%d\n", key, pos);
    while (collisionNum < t->size && t->list[pos].t != EMPTY && t->list[pos].key != key ) {
//        printf(" %d,", pos);
        pos += 2 * ++collisionNum - 1;// i++; pos = pos + i*i;
//        printf("%d", pos);
        if (pos >= t->size) {
            //pos = pos - t->size;
            pos = pos % t->size;
        }
    }
    
    return pos;
}

void insert(HashTable2 *t, int key){
    int pos = find(t, key);
    
    if (t->list[pos].t != EXISTED) {
        t->list[pos].t = EXISTED;
        t->list[pos].key = key;
    }
}

void testHashTable2(){
    HashTable2 *t = initHashTable2(23);
    
    for (int i = 0; i < 100; i++) {
        insert(t, i);
    }
    
    for (int i = 0; i < 100; i++) {
        int pos = find(t, i);
        
        if (t->list[pos].t == EXISTED && t->list[pos].key == i) {
            printf("%d==%d-》pos: %d\n", i, t->list[pos].key, pos);
        }
    }
}