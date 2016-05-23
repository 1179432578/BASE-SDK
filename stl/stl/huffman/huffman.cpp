//
//  huffman.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/16.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "huffman.h"
#include <string.h>
#include <stdlib.h>

HuffmanNode* makeHuffmanTree(HuffmanNode *h, int n){
    HuffmanNode *min1;
    HuffmanNode *min2;
    HuffmanNode *p;
    
    //链表中至少还有两个节点才会继续合并
    while (h->sibling && h->sibling->sibling) {
        p = h->sibling->sibling->sibling;
        min1 = h->sibling;
        min2 = h->sibling->sibling;
        
        //找出两个权值最小的节点
        while (p) {
            // p < min1 && p < min2
            if (p->weight < min1->weight && p->weight < min2->weight) {
                //p < min1 < min2
                if (min1->weight < min2->weight) {
                    min2 = p;
                }
                //p < min2 < min1
                else{
                    min1 = p;
                }
            }
            else if (min1->weight < min2->weight){
                //min1 < p < min2
                if (p->weight < min2->weight) {
                    min2 = p;
                }
            }
            else if (min1->weight > min2->weight){
                // min2 < p < min1
                if (p->weight < min1->weight) {
                    min1 = p;
                }
            }
            
            p = p->sibling;
        }//end of while
        
        min1->preSibling->sibling = min1->sibling;
        if (min1->sibling) {
            min1->sibling->preSibling = min1->preSibling;
        }
        
//        printf("dd: ");
//        HuffmanNode *hn = h;
//        while (hn = hn->sibling) {
//            printf("%d ", hn->weight);
//            printf("[%d] ", hn->preSibling->weight);
//        }
//        printf("\n");

        min2->preSibling->sibling = min2->sibling;
        
//                     printf("1111123342222222222%d\n", h->sibling->weight);
        if (min2->sibling) {
            min2->sibling->preSibling = min2->preSibling;
        }
        printf("%d\n",min2->weight);
//        printf("2222222222%d\n", h->sibling->weight);

        //创建一个新节点合并min1 min2
        HuffmanNode *newp = new HuffmanNode;
        newp->weight = min1->weight + min2->weight;
        newp->lchild = min1;
        newp->rchild = min2;
        newp->str = 0;
        
        //把新节点加入到链表中
        if (h->sibling) {
            h->sibling->preSibling = newp;
        }
        newp->sibling = h->sibling;
//        printf("%d\n", h->sibling->weight);
        newp->preSibling = h;
        h->sibling = newp;
      
        
        //test
        HuffmanNode *n = h->sibling;
        while (n) {
            printf("%s:%d ", n->str, n->weight);
            n = n->sibling;
        }
        printf("\n");
    }
    
    //返回创建好的带头结点的huffman树
    return h;
}

void hcode(HuffmanNode *p, char *code){
    //p是叶子
    if (p->str) {
        printf("%s: %s : %d\n", p->str, code, p->weight);
        return;
    }
    if (p->lchild){
        int length = strlen(code);
        char buf[100];//#define N 100
        strcpy(buf, code);
        buf[length] = '0';
        buf[length+1] = '\0';
        hcode(p->lchild, buf);
    }
    if (p->rchild){
        int length = strlen(code);
        char buf[100];//#define N 100
        strcpy(buf, code);
        buf[length] = '1';
        buf[length+1] = '\0';
        hcode(p->rchild, buf);
    }
}

void huffmanCode(HuffmanNode *h){
    HuffmanNode *t = h->sibling;
    
    hcode(t, "");
}

HuffmanNode* makeList(){
    HuffmanNode *h = new HuffmanNode;
    h->sibling = 0;
    
    return h;
}

void insertList(HuffmanNode *h, char *str, int weight){
    HuffmanNode *p = new HuffmanNode;
    p->lchild = 0;
    p->rchild = 0;
    p->weight = weight;
//    p->str = str;
    p->str = new char[strlen(str) + 1];
    strcpy(p->str, str);
    p->sibling = h->sibling;
    p->preSibling = h;
    
    if (h->sibling) {
         h->sibling->preSibling = p;
    }
    
    h->sibling = p;
    h = h->sibling;
    while (h) {
        printf("%s:%d", h->str, h->weight);
        h = h->sibling;
    }
    printf("\n");
}

void testHuffman(){
    HuffmanNode *h = makeList();
    
    char buf[2] = {0};
    for (int i = 0; i <= 127; i++) {
        buf[0] = i;
        insertList(h, buf, rand() % 1000);
    }
    
    makeHuffmanTree(h, 26);
    huffmanCode(h);
}