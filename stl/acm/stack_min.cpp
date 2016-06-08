//
//  stack_min.cpp
//  stl
//
//  Created by lewis on 16/6/8.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。要求函数min、push以及pop的时间复杂度都是O(1)
 *http://www.acmerblog.com/stack-with-min-5990.html
 */

/*思路：使用辅助栈放最小元素信息*/
#define DEFAULTSIZE 16
class Stack{
public:
    Stack(){
        capacity = DEFAULTSIZE;
        _top = -1;
        data = new int[DEFAULTSIZE];
        data2 = new int[DEFAULTSIZE];
    }
    
    int min(){
        if (_top < 0) {
//            exit(-1);
        }
        return data[data2[_top]];
    }
    
    void push(int num){
        if (_top >= capacity) {
            int *newData = new int[capacity*2];
            capacity *= 2;
            memcpy(newData, data, capacity);
            delete [] data;
            data = newData;
            
            int *newData2 = new int[capacity];
            memcpy(newData2, data2, capacity);
            delete [] data2;
            data2 = newData2;
        }
        
        data[++_top] = num;
        if (_top == 0 || num < data[data2[_top-1]]) {
            data2[_top] = _top;
        }
        else{
            data2[_top] = data2[_top-1];
        }
    }
    
    void pop(){
        if (_top < 0) {
            return;
        }
        
        _top--;
    }
    
    int top(){
        if (_top < 0) {
//            exit(-1);
        }
        
        return data[_top];
    }
private:
    int capacity;
    int _top;
    int *data;
    int *data2;/*辅助栈数据，盛放当前栈的最小元素位置*/
};

void testStackMin(){
    Stack s;
    s.push(89);
    s.push(12);
    s.push(92);
    s.push(9);
    s.push(3);
    s.push(78);
    
    printf("%d\n", s.min());
    s.pop();
    printf("%d\n", s.min());
    s.pop();
    printf("%d\n", s.min());
}
