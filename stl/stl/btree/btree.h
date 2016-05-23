//
//  btree.hpp
//  stl
//
//  Created by 鲁飞 on 16/5/10.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef btree_hpp
#define btree_hpp
//特殊数据结构
//http://www.cnblogs.com/haippy/archive/2013/05/27/3101697.html
//stl
//http://www.cnblogs.com/biyeymyhjob/archive/2012/07/22/2603525.html

//http://www.tuicool.com/articles/rUfiiqn
//http://blog.sina.com.cn/s/blog_4aa65a3f0101acou.html
//balance tree
//btree源码
//http://www.mit.edu/afs.new/sipb/user/gamadrid/nscript/btree.c

//（1）一个m阶B树，或者是空树，或者满足一下性质的m叉树；
//（2）根节点或者是叶子，或者至少有两颗子树，至多是m棵子树；
//（3）除根节点外，所有非终端节点至少是「m/2 （向上取整）棵子树，至多是m棵子树；
//（4）所有叶子节点都在树的同一层上。

//btree的度为4
# define M 4

typedef struct BTreeNode{
    int keynum;//关键字数
    struct BTreeNode *parent;
    int key[M-1];//存放关键字
    struct BTreeNode* children[M];//存放孩子地址
} BTreeNode;

void split(BTreeNode *p);

void insert_Btree(BTreeNode **t, int key);






#endif /* btree_hpp */
