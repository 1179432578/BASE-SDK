//
//  IDecorator.h
//  stl
//
//  Created by 鲁飞 on 16/5/10.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef IDecorator_h
#define IDecorator_h

//可以是一个接口，也可以是一个抽象类
class IDecorator{
public:
    virtual void decoratorOp() = 0;//被装饰的操作
};

//可以由IDecorator派生具体的产品类,也必须要具体产品，不然包装类没有具体物品包装
class ConcreteDecorator : public IDecorator{
public:
    virtual void decoratorOp();
};

//也可以由IDecorator派生需要的包装类
class Decorator : public IDecorator{
public:
    virtual void decoratorOp();
    
    Decorator(IDecorator *dect):m_dect(dect){};//设置装饰类
private:
    IDecorator *m_dect;
};

#endif /* IDecorator_h */
