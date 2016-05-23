//
//  pattern.cpp
//  stl
//
//  Created by 鲁飞 on 16/5/6.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include "pattern.h"

//design pattern

//observer pattern
//游戏开发可用到
class IObserver{
public:
    virtual void update() = 0;
};

class ISubject{
public:
    virtual void addObserver(IObserver *o) = 0;
    
    virtual void deleteObserver(IObserver *o) = 0;
    
    virtual void notifyObservers() = 0;
};

//下面视具体类