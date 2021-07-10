//
// Created by 张翼 on 2021/7/10.
//

#ifndef DS_SAMPLE_TRIPLET_H
#define DS_SAMPLE_TRIPLET_H

#include "const.h"

// 采取动态分配的顺序存储结构
typedef ElemType *Triplet;

// 基本操作的函数原型说明
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
    // 操作结果：构造三元组 T，元素 e1，e2，e3 分别被赋以参数 v1，v2 和 v3 的值。

Status DestroyTriplet(Triplet &T);
    // 操作结果：三元组 T 被销毁

Status Get(Triplet T, int i, ElemType &e);
    // 初始条件：三元组 T 已存在，1 <= i <= 3
    // 操作结果：用 e 返回 T 的第 i 元的值。

Status Put(Triplet &T, int i, ElemType e);
    // 初始条件：三元组 T 已存在，1 <= i <= 3
    // 操作结果： 用改变 T 的第 i 元的值为 e

Status IsAscending(Triplet T);
    // 初始条件：三元组 t 已存在
    // 操作结果：如果 T 的 3 个元素按升序排序，则返回 1， 否则返回 0

Status IsDescending(Triplet T);
    // 初始条件：三元组 t 已存在
    // 操作结果：如果 T 的 3 个元素按降序排序，则返回 1， 否则返回 0

Status Max(Triplet T, ElemType &e);
    // 初始条件：三元组 t 已存在
    // 操作结果：用 e 返回 T 的 3 个元素中的最大值

Status Min(Triplet T, ElemType &e);
    // 初始条件：三元组 t 已存在
    // 操作结果：用 e 返回 T 的 3 个元素中的最小值

#endif //DS_SAMPLE_TRIPLET_H
