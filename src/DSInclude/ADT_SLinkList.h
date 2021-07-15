//
// Created by 张翼 on 2021/7/15.
//

#ifndef DS_ADT_SLINKLIST_H
#define DS_ADT_SLINKLIST_H

#include "const.h"
typedef char ElemType;

/**
 * 静态链表
 * 用一维数组来描述线性链表
 */
#define MAXSIZE 1000
typedef struct{
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE];

class ADT_SLinkList {
// 数据对象：D={ai | ai 属于 ElemSet, i=1,2,...,n, n>=0}
// 数据关系：S={<ai-1,ai> | ai-1, ai 属于 D, i=2,...,n}
public:      // 当线性表的链式表示
// 基本操作

    /**
     * 初始状态：已存在静态单链线性表，待查找的值 e
     * 操作结果：成功返回它在 L 中的位序，否则返回 0
     */
    int LocateEle_SL(SLinkList S, ElemType e);

    /**
     * 初始状态：已存在静态单链线性表。（引用，头结点要改变）
     * 操作结果：space 指向一个备用链表的头结点
     */
    void InitSpace_SL(SLinkList &space);

    /**
     * 若备用的空间链表非空，则返回分配的结点下标，否则返回 0
     * @param space
     * @return
     */
    int Malloc_SL(SLinkList &space);

    /**
     * 将下标为 k 的空闲结点回收到备用链表
     * @param space 备用静态链表
     * @param k 待回收的 下标
     */
    void Free_SL(SLinkList &space, int k);

    /**
     * 依次输入集合 A 和 B 的元素，在一维数组 space 中建立表示集合 (A-B)U(B-A) 的
     * 静态链表，S 为其头指针，假设备用空间足够大，space[0].cur 为其头指针
     */
    void difference(SLinkList &space, int &S);

    void test();
};


#endif //DS_ADT_SLINKLIST_H
