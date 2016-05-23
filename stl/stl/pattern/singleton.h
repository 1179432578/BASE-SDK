//
//  singleton.hpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef singleton_hpp
#define singleton_hpp

#include <stdio.h>

//http://c.biancheng.net/cpp/html/1487.html
#define DESCRIPTION(classname, des) \
void description(){ \
    printf("%s: %s\n", #classname, #des); \
}

class Singleton{
public:
    static Singleton* getInstance();
    
    DESCRIPTION(Singleton, "this is a singleton class")
};

void testSingleton();

#endif /* singleton_hpp */
