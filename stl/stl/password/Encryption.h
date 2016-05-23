//
//  Encryption.hpp
//  stl
//
//  Created by 鲁飞 on 16/5/6.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef Encryption_hpp
#define Encryption_hpp

//使用策略模式 这个是加密解密接口描述
class IEncryption {
public:
    virtual char* encrypt(char *express) = 0;
    
    virtual char* decrypt(char *secret) = 0;
};

class SimpleEncryption : public IEncryption{
    virtual char* encrypt(char *express);
    
    virtual char* decrypt(char *secret);

};

#endif /* Encryption_hpp */
