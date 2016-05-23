//
//  testPass.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/6.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "testPass.h"
#include <stdio.h>

// 添加一条记录
void Pass::addPass(PassItem *pi){
    pi->next = m_passList->next;
    m_passList->next = pi;
}

// 加密
void Pass::encryption(){
    PassItem *p = m_passList->next;
    
    while (p) {
        p->password = m_encryption->encrypt(p->password);
        p = p->next;
    }
}

// 解密
void Pass::decryption(){
    PassItem *p = m_passList->next;
    
    while (p) {
        p->password = m_encryption->decrypt(p->password);
        p = p->next;
    }
}

void Pass::toString(){
    PassItem *p = m_passList->next;
    
    while (p) {
        printf("password: %s\n", p->password);
        p = p->next;
    }
}
