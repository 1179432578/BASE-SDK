//
//  btree.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/10.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "btree.h"

//把一个n,a0,k1,a1,k2,a2...进行分割
void split(BTreeNode *p){

}

// 简单的插入到n,a0,k1,a1,k2,a2...
void insert_Btree(BTreeNode **t, int key){
    //树还没建立
    if (*t == 0) {
        *t = new BTreeNode;
        (*t)->parent = 0;
        (*t)->key[0] = key;
        (*t)->keynum = 1;
    }
    //树已经建立
    else{
        for (int i = (*t)->keynum; i >= 0; i--) {
            if ((*t)->key[i] > key) {
                
            }
        }
        
        if ((*t)->key) {
            
        }
    }
}