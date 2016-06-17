//
//  infixToPostfix.cpp
//  stl
//
//  Created by 鲁飞 on 16/6/17.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <assert.h>

//中缀表达式转为后缀表达式
//http://www.acmerblog.com/infix-to-postfix-6072.html

//方法：从左到右扫描表达式，遇到一般字符直接输出，遇到操作符，检查栈顶，查看栈顶元素的操作符。
//如果栈顶操作符优先级大于遇到的操作符，则弹出栈顶操作符输出，并且继续检查栈中元素，最后把遇到的
//操作符压入栈中，继续扫描。
//遇到）就把栈中所有操作符弹出，输出，直到遇到（,如果没有遇到就报错。
//遇到空白符就跳过
//支持表达书 5+7*(5-3)/3 + 2

//获得操作符优先级
int getPriority(char c){
    switch (c) {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        default:
            break;
    }
    
    return -1;
}

void infixToPostfix(const char *expression){
    char c;
    std::stack<char> s;
    int i = 0;
    while (expression[i]) {
        c = expression[i];
        if (c >= '0' && c <= '9') {//处理数字
            printf("%c", c);//直接输出
        }
        else if (c == '\t' || c == '\n' || c == ' ' ) {//处理空白符
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {//处理操作符
            int priority = getPriority(c);
            
            while (!s.empty()) {//把栈中比c优先级高或相等的操作符弹出输出
                char top = s.top();
                int topProority = getPriority(top);
                
                if (topProority >= priority) {
                    s.pop();
                    printf("%c", top);
                }
                else{
                    break;
                }
            }
            
            s.push(c);//最后把c压入栈中
        }
        else if (c == '(') {//处理左括号
            s.push(c);
        }
        else if (c == ')'){//处理右括号，出现右括号把栈中元素弹出，直到遇到左括号结束
            bool bRight = false;//判断时候有左括号与之匹配
            
            while (!s.empty()) {
                char top = s.top();
                
                if (top != '(') {
                    s.pop();
                    printf("%c", top);
                }
                else if (top == '('){
                    s.pop();//直接弹出,不输出
                    bRight = true;
                    break;
                }
            }
            
            assert(bRight);
        }
        
        i++;
    }
    
    //表达式处理完后，把栈中剩下操作符弹出输出
    while (!s.empty()) {
        char c = s.top();
        s.pop();
        printf("%c", c);
    }
}

void testInfixToPostfix(){
    const char *expression =  "5 + 6    * (3 - 4)";
    
    infixToPostfix(expression);
}