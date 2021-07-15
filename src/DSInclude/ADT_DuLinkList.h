//
// Created by 张翼 on 2021/7/15.
//

#ifndef DS_ADT_DULINKLIST_H
#define DS_ADT_DULINKLIST_H

#include "const.h"
typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;


class ADT_DuLinkList {

public:
    /**
    * 初始条件：线性表 L 已存在
    * 操作结果：返回 L 中数据元素个数
    */
    int ListLength_L(DuLinkList L);


    /**
     * 初始条件：L 为带头结点的单链表的头指针
     * 操作结果：当第 i 个元素存在时， 其值赋给 e 并返回 OK，否则返回 ERROR
     */
    Status GetElem_L(DuLinkList L, int i, ElemType &e);


    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：返回 L 中第 i 个与 e 相等的数据元素的位序。若这样的数据元素不存在，则返回值为 0
     */
    int LocateElem_L(DuLinkList L, ElemType e);
};


#endif //DS_ADT_DULINKLIST_H
