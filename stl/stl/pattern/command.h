//
//  command.hpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef command_hpp
#define command_hpp

#include <stdio.h>

class Command{
public:
    virtual void excute() =0;
};

class Command1 : public Command{
public:
    virtual void excute(){ printf("excute actions\n");};
};

void testCommand();

#endif /* command_hpp */
