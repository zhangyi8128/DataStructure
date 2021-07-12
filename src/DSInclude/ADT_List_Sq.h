//
// Created by 张翼 on 2021/7/12.
//

#ifndef DS_ADT_LIST_SQ_H
#define DS_ADT_LIST_SQ_H

#include "const.h"
typedef int ElemType;

#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define LIST_INCREMENT 10   // 线性表存储空间的分配增量
typedef struct {
    ElemType *elem;     // 存储空间基址
    int length;         // 当前长度
    int listSize;       // 当前分配的存储容量（以 sizeof(ElemType) 为单位）
}SqList;

typedef SqList List;


class ADT_List_Sq {
// 数据对象：D={ai | ai 属于 ElemSet, i=1,2,...,n, n>=0}
// 数据关系：S={<ai-1,ai> | ai-1, ai 属于 D, i=2,...,n}
public:      // 当线性表的顺序表示
// 基本操作
    /**
     * 操作结果：构造一个空的线性表 L
     */
    Status InitList_Sq(List &L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：销毁线性表 L
     */
    Status DestroyList_Sq(List &L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：将 L 重置为空表
     */
    Status ClearList_Sq(List &L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：若 L 为空表，则返回 TRUE，否则返回 FALSE
     */
    Status ListEmpty_Sq(List L);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：返回 L 中数据元素个数
     */
    Status ListLength_Sq(List L);

    /**
     * 初始条件：线性表 L 已存在，1 <= i <= ListLength(L)
     * 操作结果：用 e 返回 L 中第 i 个数据元素的值
     */
    Status GetElem_Sq(List L, int i, ElemType &e);

    /**
     * 初始条件：线性表 L 已存在，compare（）是数据元素判定函数
     * 操作结果：返回 L 中第 i 个与 e 满足关系 compare（） 的数据元素的位序。若这样的数据元素不存在，则返回值为 0
     */
    int LocateElem_Sq(List L, ElemType e, Status ( *compare)(ElemType , ElemType));

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：若 cur_e 是 L 的数据元素，且不是第一个，则用 pre_e 返回它的前驱，否则操作失败，pre_e 无定义。
     */
    Status PriorElem_Sq(List L, ElemType cur_e, List &pre_e);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：若 cur_e 是 L 的数据元素，且不是最后一个，则用 next_e 返回它的后继，否则操作失败，next_e 无定义。
     */
    Status NextElem_Sq(List L, ElemType cur_e, List &next_e);

    /**
     * 初始条件：线性表 L 已存在，1 <= i <= ListLength(L) + 1
     * 操作结果：在 L 中第 i 个位置之前插入新的数据元素 e，L 的长度加 1
     */
    Status ListInsert_Sq(List &L, int i, ElemType e);

    /**
     * 初始条件：线性表 L 存在且非空，1 <= i <= ListLength(L)
     * 操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减 1
     */
    Status ListDelete_Sq(List &L, int i, ElemType &e);

    /**
     * 初始条件：线性表 L 已存在
     * 操作结果：依次对 L 的每个数据元素调用函数 visit（）。一旦 visit（） 失败，则操作失败。
     */
    Status ListTraverse_Sq(List L, int (*visit)());

    /**
     * 将所有在线性表 Lb 中但不在 La 中的数据元素插入到 La 中
     */
     void Union_Sq(List &La, List Lb);

    /**
     * 算法 2.1 已知线性表 La 和 Lb 中的数据元素按值非递减排列
     * 归并 La 和 Lb 得到新的线性表 Lc，Lc 的数据元素也按值非递减排列
     */
     void MergeList_Sq(List La, List Lb, List &Lc);

     /**
      * 测试用例
      */
     void Test();

     void listPrint(List l);
};


#endif //DS_ADT_LIST_SQ_H
