//
// Created by 张翼 on 2021/7/13.
//

#include "ADT_LinkList.h"
#include <iostream>
#include <cstdlib>

Status ADT_LinkList::InitList_L(LinkList &L) {
    L = (LinkList) malloc(sizeof(LNode));
    if (!L)exit(OVERFLOW);
    L->data = 0;
    L->next = nullptr;
    return OK;
}

/**
* 算法 2.8
* 初始条件：L 为带头结点的单链表的头指针
* 操作结果：当第 i 个元素存在时， 其值赋给 e 并返回 OK，否则返回 ERROR
* @param L 带头结点的单链表的头指针
* @param i 查询位置
* @param e 查询结构存储变量
* @return 操作执行状态码
*/
Status ADT_LinkList::GetElem_L(LinkList L, int i, ElemType &e) {
    LinkList p = L->next;
    int j = 1;

    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

Status ADT_LinkList::DestroyList_L(LinkList &L) {
    free(L);
    L = nullptr;
    return OK;
}

/**
 * 算法 2.9
* 初始条件：L 为带头结点的单链表的头指针
* 操作结果：在第 i 个元素之前插入元素 e， 成功返回 OK，否则返回 ERROR
* @param L 带头结点的单链表的头指针
* @param i 插入位置
* @param e 待插入数据
* @return 操作执行状态码
*/
Status ADT_LinkList::ListInsert_L(LinkList &L, int i, ElemType e) {
    // ERROR 情况可以合并
    /*
    // 从第 1 个元素开始插入
    if (i < 1) return ERROR;
    // 1、移动到待插入位置 i 或最后，利用辅助结点指针 p
    LNode *p = L;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    // 2、为数据 e 申请结点空间并初始化
    auto E = (LinkList) malloc(sizeof(LNode));
    E->data = e;
    // 3、插入元素
    E->next = p->next;
    p->next = E;
    return OK;
     */

    LNode *q = L;
    int k = 0;
    // 寻找第 i-1 个结点
    while (q && k < i - 1) {
        q = q->next;
        ++k;
    }
    // i 小于 1 或者大于表长加 1
    if (!q || k > i - 1) return ERROR;
    auto s = (LinkList) malloc(sizeof(LNode));
    s->data = e;
    s->next = q->next;
    q->next = s;
    return OK;
}

/**
 * 在带头结点的单链线性表 L 中，删除第 i 个元素，并由 e 返回其值
 * 初始条件：线性表 L 存在且非空，1 <= i
 * 操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减 1,成功返回 OK，否则返回 ERROR。
 * @param L 带头结点的单链表
 * @param i 索引位置 i
 * @param e 结果接收变量
 * @return 操作执行状态码
 */
Status ADT_LinkList::ListDelete_L(LinkList &L, int i, ElemType &e) {
    LNode *p = L;
    int j = 0;
    // 寻找第 i 个结点，并令 p 指向其前驱
    while(p->next && j < i - 1){
        p = p->next;
        ++j;
    }
    if((!p->next) || j > i - 1) return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
     free(q);
    return OK;
}

void ADT_LinkList::listPrint(LinkList L) {
    int i = 1;
    std::cout << "打印 List 成员：\n";
    do {
        L = L->next;
        std::cout << "第" << i++ << "个元素：" << L->data << "\n";
    } while (L->next != nullptr);
    std::cout << std::endl;
}

void ADT_LinkList::Test() {
    LinkList L;
    Status status;
    int i = 0, e = 0;

    std::cout << "======测试 InitList_Sq 方式=====" << std::endl;
    status = InitList_L(L);
    std::cout << "初始化顺序表状态：" << status << std::endl;
    std::cout << "======测试 LinkListInsert 方式=====" << std::endl;
    ListInsert_L(L, 1, 4);
    ListInsert_L(L, 1, 7);
    ListInsert_L(L, 2, 8);
    ListInsert_L(L, 2, 3);
    ListInsert_L(L, 2, 8);
    listPrint(L);
    std::cout << "======测试 GetElem_L 方式=====" << std::endl;
    i = 2;
    GetElem_L(L, i, e);
    std::cout << "第" << i << "个元素为：" << e << std::endl;
    std::cout << "======测试 DestroyList_Sq 方式=====" << std::endl;
    std::cout << "status = " << DestroyList_L(L) << std::endl;
}
