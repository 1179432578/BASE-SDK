//
//  Encryption.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/6.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "Encryption.h"

char* SimpleEncryption::encrypt(char *express){
    int i = 0;
    while (express[i] != '\0') {
        express[i] = express[i] + 5;
        i++;
    }
    
    return express;
}

char* SimpleEncryption::decrypt(char *secret){
    int i = 0;
    while (secret[i] != '\0') {
        secret[i] = secret[i] - 5;
        i++;
    }
    
    return secret;
}
