//
//  testPass.hpp
//  stl
//
//  Created by 鲁飞 on 16/5/6.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef testPass_hpp
#define testPass_hpp
#include "Encryption.h"

typedef struct PassItem{
    char *account;
    char *password;
    char *des;
    struct PassItem *next;
}PassItem;

class Pass{
public:
    Pass(){
        m_passList = new PassItem;
        m_passList->next = 0;
        
        //加密函数 使用了策略模式
        m_encryption = new SimpleEncryption;
    }
//    // 把账号密码表写入磁盘文件
//    void writeFile(char *filename);
//    // 从磁盘文件读取账号密码表到内存
//    void readFile(char *filename);
    
    // 添加一条记录
    void addPass(PassItem *pi);
    
    // 加密
    void encryption();
    
    // 解密
    void decryption();
    
    void toString();
    
//    // 删除一条记录
//    void deletePass(PassItem &pi);
private:
    PassItem *m_passList;//账号密码表 表头，这里用链表来作为表结构
    
    IEncryption *m_encryption;
};

#endif /* testPass_hpp */
