//
// Created by 张翼 on 2021/7/19.
//


// 启用自己的 栈结构数据类型
#define STACK_SELEMTYPE_
#define DEFAULT_ELEMTYPE_
#include "ADT_Stack.h"

/**
 * 迷宫求解
 */
typedef int PosType[2]; // x，y 两个坐标分量
typedef int MazeType[5][5]; // 迷宫棋盘
typedef struct {
    // 通道块在路径上的“序号”
    int ord;
    // 通道块在迷宫中的“坐标位置”
    PosType seat;
    // 从此通道块走向下一通道块的“方向”
    int di;
} SElemType;
typedef SElemType ELemType;

//
//bool Pass(PosType pInt);
//
//void FootPrint(PosType pInt);
//
//PosType NextPos(PosType pInt, int i);
//
//Status MazePath(MazeType maze, PosType start, PosType end) {
//    SqStack S;
//    ADT_Stack::InitStack(S);
//    PosType curPos;
//    curPos[0] = start[0], curPos[1] = start[1];
//    do {
//        SElemType e;
//        if (Pass(curPos)) {
//            FootPrint(curPos);
//            int curStep;
//            e.ord = curStep;
//            e.seat[0] = curPos[0];
//            e.seat[1] = curPos[1];
//            e.di = 1;
//            ADT_Stack::Push(S, e);
//            if (curPos == end) return TRUE;
//            curPos = NextPos(curPos, 1);
//            curStep++;
//        } else {
//            if (!ADT_Stack::StackEmpty(S)) {
//                ADT_Stack::Pop(S, e);
//                while(e.di == 4 && !ADT_Stack::StackEmpty(S)) {
//                    MarkPrint(e, seat);
//                    ADT_Stack::Pop(S, e);
//                }
//                if (e.di < 4) {
//                    e.di++;
//                    ADT_Stack::Push(S, e);
//                    curPos = NextPos(e.seat, e.di);
//                }
//            }
//        }
//    } while(!ADT_Stack::StackEmpty(S));
//    return FALSE;
//}
//
//PosType NextPos(PosType pInt, int i) {
//    return nullptr;
//}
//
//void FootPrint(PosType pInt) {
//
//}
//
//bool Pass(PosType pInt) {
//    return false;
//}
