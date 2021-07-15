//
// Created by 张翼 on 2021/7/13.
//

#ifndef DS_ADT_LINKLIST_H
#define DS_ADT_LINKLIST_H

#include "const.h"
typedef int ElemType;


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


class ADT_LinkList {
// 数据对象：D={ai | ai 属于 ElemSet, i=1,2,...,n, n>=0}
// 数据关系：S={<ai-1,ai> | ai-1, ai 属于 D, i=2,...,n}
public:      // 当线性表的链式表示
// 基本操作

    /**
     * 操作结果：构造一个空的线性表 L
     */
    Status InitList_L(LinkList &L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：销毁线性表 L
     */
    Status DestroyList_L(LinkList &L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：将 L 重置为空表
     */
    Status ClearList_L(LinkList &L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：若 L 为空表，则返回 TRUE，否则返回 FALSE
     */
    Status ListEmpty_L(LinkList L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：返回 L 中数据元素个数
     */
    int ListLength_L(LinkList L);

    /**
     * 初始条件：L 为带头结点的单链表的头指针
     * 操作结果：当第 i 个元素存在时， 其值赋给 e 并返回 OK，否则返回 ERROR
     */
    Status GetElem_L(LinkList L, int i, ElemType &e);

    /**
     * 初始条件：线性表 L 已存在，compare（）是数据元素判定函数
     * 操作结果：返回 L 中第 i 个与 e 满足关系 compare（） 的数据元素的位序。若这样的数据元素不存在，则返回值为 0
     */
    int LocateElem_L(LinkList L, ElemType e);
    static Status Compare_List_L(ElemType a, ElemType b);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：若 cur_e 是 L 的数据元素，且不是第一个，则用 pre_e 返回它的前驱，否则操作失败，pre_e 无定义。
     */
    void PriorElem_L(LinkList L, ElemType cur_e, LinkList &pre_e);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：若 cur_e 是 L 的数据元素，且不是最后一个，则用 next_e 返回它的后继，否则操作失败，next_e 无定义。
     */
    void NextElem_L(LinkList L, ElemType cur_e, LinkList &next_e);

    /**
     * 初始条件：线性表 L 已存在，1 <= i
     * 操作结果：在 L 中第 i 个位置之前插入新的数据元素 e，L 的长度加 1
     */
    Status ListInsert_L(LinkList &L, int i, ElemType e);

    /**
     * 在带头结点的单链线性表 L 中，删除第 i 个元素，并由 e 返回其值
     * 初始条件：线性表 L 存在且非空，1 <= i
     * 操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减 1,成功返回 OK，否则返回 ERROR。
     * @param L 带头结点的单链表
     * @param i 索引位置 i
     * @param e 结果接收变量
     * @return 操作执行状态码
     */
    Status ListDelete_L(LinkList &L, int i, ElemType &e);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：依次对 L 的每个数据元素调用函数 visit（）。一旦 visit（） 失败，则操作失败。
     */
    Status ListTraverse_L(LinkList L, Status (*visit)());


    /**
     * 算法 2.1 已知线性表 La 和 Lb 中的数据元素按值非递减排列
     * 归并 La 和 Lb 得到新的线性表 Lc，Lc 的数据元素也按值非递减排列
     */
    void MergeList_L(LinkList La, LinkList Lb, LinkList &Lc);

    /**
     * 逆位序输入 n 个元素的值，建立带表头结点的单链线性表 L
     * @param L 单链线性表
     * @param n 元素个数
     */
    void CreateList_L(LinkList &L, int n);

    /**
     * 测试用例
     */
    void Test();

    void listPrint(LinkList L);

};


#endif //DS_ADT_LINKLinkList_H
