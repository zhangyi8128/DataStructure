//
// Created by 张翼 on 2021/7/19.
//

#ifndef DS_ADT_STACK_H
#define DS_ADT_STACK_H
#include "const.h"
#include "ADT_typedef.h"



class ADT_Stack {

public:

    static Status InitStack(SqStack &S);

    static Status DestroyStack(SqStack &S);

    static Status ClearStack(SqStack &S);

    static Status StackEmpty(SqStack &S);

    static int StackLength(SqStack &S);

    static Status GetTop(SqStack &S,SElemType &e);

    static Status Push(SqStack &S,SElemType e);

    static Status Pop(SqStack &S,SElemType &e);

    static Status StackTraverse(SqStack &S,Status (*visit)());

    static void test();
};


#endif //DS_ADT_STACK_H
