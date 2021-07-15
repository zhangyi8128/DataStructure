//
// Created by 张翼 on 2021/7/15.
//

#include "ADT_SLinkList.h"
#include <cstdlib>
#include <iostream>

/**
 * 算法 2.13
 * 在静态单链线性表 L 中查找第 1 个值为 e 的元素
 * 若找到，则返回它在 L 中的位序，否则返回 0
 * @param S 静态单链线性表
 * @param e 待查找的值
 * @return 索引位置
 */
int ADT_SLinkList::LocateEle_SL(SLinkList S, ElemType e) {
    int i = S[0].cur;
    while(i && S[i].data != e) i = S[i].cur;
    return i;
}

/**
 * 算法 2.14
 * 将一维数组 space 中各分量链成一个备用链表，space[0].cur 为头指针
 * “0” 表示空指针
 * @param space 一维数组表示的静态链表
 */
void ADT_SLinkList::InitSpace_SL(SLinkList &space) {
    for(int i = 0; i < MAXSIZE - 1; ++i) space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
}

/**
 * 算法 2.15
 * 若备用的空间链表非空，则返回分配的结点下标，否则返回 0
 * @param space
 * @return
 */
int ADT_SLinkList::Malloc_SL(SLinkList &space) {
    int i = space[0].cur;
    if (space[0].cur) space[0].cur = space[i].cur;
    return i;
}

/**
 * 算法 2.16
 * 将下标为 k 的空闲结点回收到备用链表
 * @param space 备用静态链表
 * @param k 待回收的 下标
 */
void ADT_SLinkList::Free_SL(SLinkList &space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}
/**
 * 算法 2.17
 * 依次输入集合 A 和 B 的元素，在一维数组 space 中建立表示集合 (A-B)U(B-A) 的
 * 静态链表，S 为其头指针，假设备用空间足够大，space[0].cur 为其头指针
 * @param space 备用静态链表
 * @param S 头指针
 *
 * 测试：A:6 (c, b, e, g, f, d)
 *      B:4 (a, b, n, f)
 *      结果：(c, n, e, g, f, d, a)
 */
void ADT_SLinkList::difference(SLinkList &space, int &S) {
    // 初始化备用空间
    InitSpace_SL(space);
    // 生成 S 的头结点
    S = Malloc_SL(space);
    // r 指向 S 的当前最后结点
    int r = S;
    int m = 0, n = 0, i = 0, b = 0;
    // 输入 A 和 B 的元素的个数
    std::cin >> m >> n;
    // 建立集合 A 的链表
    for(int j = 1; j <= m; ++j) {
        // 分配结点
        i = Malloc_SL(space);
        std::cin >> space[i].data;
        // 插入到表尾
        space[r].cur = i;
        r = i;
    }
    // 尾结点的指针为空
    space[r].cur = 0;
    // 依次输入 b 的元素，若不再当前表中，则插入，否则删除
    for(int j = 1; j <= n; ++j){
        std::cin >> b;
        // k 指向集合 A 中的第一个结点
        int p = S, k = space[S].cur;
        // 在当前表中查找
        while(k != space[r].cur && space[k].data != b){
            p = k;
            k = space[k].cur;
        }
        // 当前表中不存在该元素，插入在 r 所指结点之后，且 r 的位置不变
        if (k == space[r].cur) {
            i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
            // 该元素已在表中，删除之
        } else {
            space[p].cur = space[k].cur;
            Free_SL(space, k);
            // 若删除的是 r 所指结点，则需修改尾指针
            if(r == k) r = p;
        }
    }
}

void ADT_SLinkList::test(){
    SLinkList space;
    int S = 0;
    difference(space,S);
}
