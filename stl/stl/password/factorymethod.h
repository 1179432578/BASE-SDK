//
//  factorymethod.hpp
//  stl
//
//  Created by lewis on 16/5/11.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef factorymethod_hpp
#define factorymethod_hpp

#include <stdio.h>

//设计模式：简单工厂、工厂方法、抽象工厂
//这3个模式重点是工厂，而不是工厂生产的产品

//下面是手机生产有关的产品、工厂

//产品CPU
class ICPU{
};

class HaisiCPU:public ICPU{
public:
    HaisiCPU(){printf("HaisiCPU\n");};
};

class AppleCPU:public ICPU{
public:
    AppleCPU(){printf("AppleCPU\n");};
};

//产品通信芯片
class ICommuicationChip{
};

class HaisiChip:public ICommuicationChip{
public:
    HaisiChip(){printf("HaisiChip\n");}
};

class AppleChip:public ICommuicationChip{
public:
    AppleChip(){printf("AppleChip\n");}
};

//and so on 还有其它好多手机组件，不再列举

//简单工厂 里面可以是一个静态方法，由这个方法根据需求生产产品
//简单工厂，之所以简单，就是这个工厂生产的产品单一，而且不符合开闭原则，
//一旦有新的产品，那么就需要修改makeProduct里面的代码，而不是扩展代码
class ISimpleCPUFactory{
public:
    static ICPU* makeProduct(char *productName);
};

//工厂方法，这里工厂提取出来了一个接口，不同的的具体工厂生产不同产品，
//当有新的产品需要生产时，开一条新的工厂线进行生产。
//这里的工厂方法实际上是工厂的一条生产线

//生产cpu的工厂方法接口
class IFactoryMethod {
public:
    virtual ICPU* createCPU() = 0;
};

//华为生产cpu的工厂方法
class HuaweiCPUFactoryMethod : public IFactoryMethod{
public:
    virtual ICPU* createCPU(){return new HaisiCPU;};
};

//apple生产cpu工厂方法
class AppleCPUFactoryMethod : public IFactoryMethod{
public:
    virtual ICPU* createCPU(){return new AppleCPU;};
};

//huawei与apple生产通信芯片的就省了


//抽象工厂，这个才是真正的工厂，每个抽象工厂都有手机生产的全套产线
//每个产线又可以是一个工厂方法，让其创建产品参数是一个工厂方法，指定
//不同工厂方法就可以生产不同材料的同类型产品
//下面没使用工厂方法创建

class IAbstractFactory{
public:
    virtual ICPU* createCPU() = 0;
    virtual ICommuicationChip* createChip() = 0;
};

class HUaweiFactory : public IAbstractFactory{
public:
    virtual ICPU* createCPU(){return new HaisiCPU;};
    virtual ICommuicationChip* createChip(){return new HaisiChip;};
};

class AppleFactory : public IAbstractFactory{
public:
    virtual ICPU* createCPU(){return new AppleCPU;};
    virtual ICommuicationChip* createChip(){return new AppleChip;};
};

void testFactoryPartern();

#endif /* factorymethod_hpp */
