//
//  kmp.hpp
//  stl
//
//  Created by 鲁飞 on 16/5/17.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef kmp_hpp
#define kmp_hpp

#include <stdio.h>

//失效连接点
//模式匹配失败时，模式指针回退的地方
//j:0 1 2 3 4 j-1
//p:a b c d e f
//j是失效的点，也就是模式与文本不匹配的指针处

//创建失效点与回退指针之间的映射表
int* makeMap(const char *pattern);

void testKmp();

#endif /* kmp_hpp */
