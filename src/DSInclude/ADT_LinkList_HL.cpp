//
// Created by 张翼 on 2021/7/16.
//

#include "ADT_LinkList_HL.h"
#include <iostream>

void ADT_LinkList_HL::test() {
    LinkList L;
    Link p, q;
    Status status;
    ElemType e;
    // 内存对齐
    std::cout << "Link=" << sizeof(Link)
              << "\nLNode=" << sizeof(LNode)
              << "\nLinkList=" << sizeof(LinkList)
              << "\nElemType=" << sizeof(ElemType)
              << "\nnext=" << sizeof(struct Lnode *)
              << std::endl;

    std::cout << "======测试 MakeNode 方式=====" << std::endl;
    e = 7;
    status = MakeNode(p, e);
    std::cout << "status：" << status << std::endl;

//    std::cout << "======测试 FreeNode 方式=====" << std::endl;
//    FreeNode(p);
//    std::cout << "p：" << p << std::endl;

    std::cout << "======测试 InitList 方式=====" << std::endl;
    status = InitList(L);
    std::cout << "status：" << status << std::endl;


//    std::cout << "======测试 InsFirst 方式=====" << std::endl;
//    InsFirst(L.head, p);
//    std::cout << "p.data：" << p->data << std::endl;
//
//    std::cout << "======测试 DelFirst 方式=====" << std::endl;
//    DelFirst(L.head, q);
//    std::cout << "q.data：" << q->data << std::endl;

    std::cout << "======测试 Append 方式=====" << std::endl;
    Append(L, p);
    MakeNode(q, 5);
    Append(L, q);
    std::cout << "q.data：" << q->data << std::endl;


    std::cout << "======测试 DestroyList 方式=====" << std::endl;
    status = DestroyList(L);
    std::cout << "status：" << status << std::endl;
}

Status ADT_LinkList_HL::MakeNode(Link &p, ElemType e) {
    p = (Link) malloc(sizeof(LNode));
    if (!p) return ERROR;
    p->data = e;
    p->next = nullptr;
    return OK;
}

void ADT_LinkList_HL::FreeNode(Link &p) {
    free(p);
    // 防止野指针
    p = nullptr;
}

Status ADT_LinkList_HL::InitList(LinkList &L) {
    L.head = (Link) malloc(sizeof(LNode));
    L.tail = (Link) malloc(sizeof(LNode));
    if (L.head == nullptr || L.tail == nullptr) return ERROR;
    L.head->next = nullptr;
    L.tail->next = nullptr;
    L.len = 0;
    return OK;
}

Status ADT_LinkList_HL::ClearList(LinkList &L) {
    if (L.len == 0) return OK;

    Link p = L.head->next;
    while (p != nullptr) {
        L.head->next = p->next;
        FreeNode(p);
        p = L.head->next;
    }

    L.tail = L.head;
    L.len = 0;
    return OK;
}

// 先销毁链表的所有结点后再销毁头结点的头指针和尾指针
// 在销毁所有结点后，头指针和尾指针指向同一个区域
Status ADT_LinkList_HL::DestroyList(LinkList &L) {
    // 1.销毁所有结点
    ClearList(L);
    // 2.销毁链表指针(此时头指针和尾指针指向同一个区域)
    free(L.head);
    L.head = nullptr;
    L.tail = nullptr;
    return OK;
}

Status ADT_LinkList_HL::InsFirst(Link h, Link s) {
    s->next = h->next;
    h->next = s;
    return OK;
}

Status ADT_LinkList_HL::DelFirst(Link h, Link &q) {
    Link p = h->next;
    q = p;
    h->next = h->next->next;
    return OK;
}

Status ADT_LinkList_HL::Append(LinkList &L, Link s) {
    if (s == nullptr) return OK;
    Link p = L.tail->next;
    int i = 0;

    // 非空表时，将 s 链接在 L 尾部
    if (p != nullptr) {
        p->next = s;
    } else {
        // 为空表时，头结点指向 s，p 指向 s
        L.head->next = s;
        p = s;
        i = 1;
    }

    while (p->next != nullptr) {
        p = p->next;
        ++i;
    }
    L.tail->next = p;
    L.len += i;
    return OK;
}


