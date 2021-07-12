//
// Created by 张翼 on 2021/7/10.
//

#ifndef DS_ADT_TRIPLET_H
#define DS_ADT_TRIPLET_H

#include "const.h"

typedef int ElemType;

// 采取动态分配的顺序存储结构
typedef ElemType *Triplet;

// ADT = (D, S, P)
class ADT_Triplet {
// 数据对象：D={e1,e2,e3 | e1,e2,e3 属于 ElemSet（定义了关系运算的某个集合}
// 数据关系：S={<e1,e2> , <e2,e3>}

public:
// 基本操作的函数原型说明::P
    /**
     * 操作结果：构造三元组 T，元素 e1，e2，e3 分别被赋以参数 v1，v2 和 v3 的值。
     * @param T 三元组
     * @param v1 值1
     * @param v2 值2
     * @param v3 值3
     * @return 执行状态码
     */
    Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);

    /**
     * 操作结果：三元组 T 被销毁
     * @param T 三元组
     * @return 执行状态码
     */
    Status DestroyTriplet(Triplet &T);

    /**
     * 初始条件：三元组 T 已存在，1 <= i <= 3
     * 操作结果：用 e 返回 T 的第 i 元的值。
     * @param T 三元组
     * @param i 索引
     * @param e 值
     * @return 执行状态码
     */
    Status Get(Triplet T, int i, ElemType &e);

    /**
     * 初始条件：三元组 T 已存在，1 <= i <= 3
     * 操作结果： 用改变 T 的第 i 元的值为 e
     * @param T 三元组
     * @param i 索引
     * @param e 值
     * @return 执行状态码
     */
    Status Put(Triplet &T, int i, ElemType e);

    /**
     * 初始条件：三元组 t 已存在
     * 操作结果：如果 T 的 3 个元素按升序排序，则返回 1， 否则返回 0
     * @param T 三元组
     * @return 执行状态码
     */
    Status IsAscending(Triplet T);

    /**
     * 初始条件：三元组 t 已存在
     * 操作结果：如果 T 的 3 个元素按降序排序，则返回 1， 否则返回 0
     * @param T 三元组
     * @return 执行状态码
     */
    Status IsDescending(Triplet T);

    /**
     * 初始条件：三元组 t 已存在
     * 操作结果：用 e 返回 T 的 3 个元素中的最大值
     * @param T 三元组
     * @param e 值
     * @return 执行状态码
     */
    Status Max(Triplet T, ElemType &e);

    /**
     * 初始条件：三元组 t 已存在
     * 操作结果：用 e 返回 T 的 3 个元素中的最小值
     * @param T 三元组存在
     * @param e 值
     * @return 执行状态码
     */
    Status Min(Triplet T, ElemType &e);

    /**
     * 用于三元组格式输出
     * @param T 三元组
     * @param e 使用已有的变量空间
     */
    void tripletPrint(Triplet T, ElemType e);

    /**
     * Triplet 基本操作，测试用例
     */
    void sampleTripletTest();
};

#endif //DS_ADT_TRIPLET_H
