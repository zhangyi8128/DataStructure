//
// Created by 张翼 on 2021/7/19.
//

#include <cstdlib>
#include <iostream>
#include "ADT_Stack.h"

Status ADT_Stack::InitStack(SqStack &S) {
    S.base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);

    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status ADT_Stack::Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType *) realloc(
                S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) exit(OVERFLOW);

        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status ADT_Stack::Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    ++S.stacksize;
    return OK;
}

Status ADT_Stack::ClearStack(SqStack &S) {
    if (S.base == nullptr) return ERROR;
    while (S.top != S.base) {
        S.top--;
        S.stacksize++;
    }
    return OK;
}

Status ADT_Stack::DestroyStack(SqStack &S) {
    ClearStack(S);
    S.stacksize = 0;
    free(S.base);
    S.base = nullptr;
    return OK;
}

Status ADT_Stack::StackEmpty(SqStack &S) {
    if (S.top != S.base) return FALSE;
    else return TRUE;
}

int ADT_Stack::StackLength(SqStack &S) {
    return S.top - S.base;
}

Status ADT_Stack::GetTop(SqStack &S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *S.top;
    return OK;
}

Status ADT_Stack::StackTraverse(SqStack &S, Status (*visit)()) {
    if (S.top == S.base) return ERROR;
    SElemType *p = S.top;
    while (p != S.base && (*visit)()) {
        std::cout << *--p;
    }
    return OK;
}

/**
 * 对于输入一个非负十进制整数，打印输出与其等值的八进制数
 * 1348 --> 2504
 */
void conversion() {
    SqStack S;
    ADT_Stack::InitStack(S);
    int N = 0;
    std::cin >> N;
    while (N) {
        ADT_Stack::Push(S, N % 8);
        N = N / 8;
    }
    SElemType e = 0;
    while (!ADT_Stack::StackEmpty(S)) {
        ADT_Stack::Pop(S, e);
        std::cout << e;
    }
    std::cout << std::endl;
}

/**
 * 括号检测
 */
void braceMatch() {
    SqStack S;
    ADT_Stack::InitStack(S);
    char ch[20];
    int i = 0;
    while (std::cin >> &ch[i++]) {
        // 空格结束输入
        if (ch[i - 1] == '#') break;
        if (ch[i - 1] == '(' || ch[i - 1] == '[' || ch[i - 1] == '{') {
            ADT_Stack::Push(S, ch[i - 1]);
        }
        SElemType e;
        if (ch[i - 1] == '(' || ch[i - 1] == '[' || ch[i - 1] == '{') {
            ADT_Stack::GetTop(S, e);
            if (ch[i - 1] == e) {
                ADT_Stack::Push(S, ch[i - 1]);
            }
        }
    }
    if (S.top == S.base)
        std::cout << "right!" << std::endl;
    else
        std::cout << "wrong" << std::endl;
    ADT_Stack::DestroyStack(S);
}

/**
 * 利用字符栈 S，从中断接收一行并传送至调用过程的数据区
 */
void LineEdit() {
    SqStack S;
    ADT_Stack::InitStack(S);
    char ch = getchar();
    SElemType c;
    while (ch != EOF) {
        while (ch != EOF && ch != '\n') {
            switch (ch) {
                case '#':
                    ADT_Stack::Pop(S, c);
                    break;
                case '@':
                    ADT_Stack::ClearStack(S);
                    break;
                default :
                    ADT_Stack::Push(S, ch);
                    break;
            }
            ch = getchar();
        }
        ADT_Stack::ClearStack(S);
        if (ch != EOF) ch = getchar();
    }
    ADT_Stack::DestroyStack(S);
}




void ADT_Stack::test() {
//    conversion();
//    braceMatch();
    LineEdit();
}





