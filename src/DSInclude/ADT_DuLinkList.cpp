//
// Created by 张翼 on 2021/7/15.
//

#include "ADT_DuLinkList.h"
#include <iostream>
#include <cstdlib>

int ADT_DuLinkList::ListLength_DuL(DuLinkList L) {
    int length = 0;
    DuLNode *p = L->next;
    while(p != L) {
        p = p->next;
        ++length;
    }
    return length;
}

DuLinkList ADT_DuLinkList::GetElem_DuL(DuLinkList L, int i) {
    DuLNode *p = L->next;
    int j = 1;

    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return NULL;
    else return p;
}

int ADT_DuLinkList::LocateElem_DuL(DuLinkList L, ElemType e) {
    DuLNode *p = L;
    int index = 1;
    while(p){
        if (p->data == e) {
            return index;
        }
        p = p->next;
        ++index;
    }
    return 0;
}

/**
 * 在带头结点的双链循环线性表 L 中第 i 个位置之前插入元素 e
 * @param L 带头结点的双链循环线性表
 * @param i 插入位置， 1 <= i <= L.length + 1
 * @param e 插入元素
 * @return 操作执行码
 */
Status ADT_DuLinkList::ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
    DuLinkList p;
    if(!(p = GetElem_DuL(L, i))) return ERROR;
    auto s = (DuLinkList)malloc(sizeof(DuLNode));
    s->data = e;

    s->prior = p->prior;
    p->prior->next = s;

    s->next = p;
    p->prior = s;
    return OK;
}

Status ADT_DuLinkList::ListDelete_DuL(DuLinkList &L, int i, ElemType &e) {
    if(i < 1 || i > ListLength_DuL(L)) return ERROR;
    DuLNode *p;
    if(!(p = GetElem_DuL(L, i))) return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

void ListPrint_DuL(DuLinkList L){
    DuLNode *p = L->next;
    int i = 1;

    std::cout << "打印 List 成员：\n";
    while(p != L){
        std::cout << "第" << i++ << "个元素：" << p->data << "\n" ;
        p = p->next;
    }
    std::cout << std::endl;
}

Status ADT_DuLinkList::InitList_DuL(DuLinkList &L) {
    if (L) L = (DuLinkList) malloc(sizeof(DuLNode));
    if (!L) exit(OVERFLOW);
    L->next = L;
    L->prior = L;
    return OK;
}

Status ADT_DuLinkList::DestroyList_DuL(DuLinkList &L) {
    if(L) return OK;
    free(L);
    L= nullptr;
    return OK;
}

void ADT_DuLinkList::test() {
    DuLinkList L;
    DuLNode *p;
    Status status;
    int e = 0, index = 0;

    std::cout << "======测试 InitList_DuL 方式=====" << std::endl;
    status = InitList_DuL(L);
    std::cout << "status=" << status << std::endl;

    std::cout << "======测试 ListInsert_DuL 方式=====" << std::endl;
    for (int i = 0; i < 5; ++i) {
        ListInsert_DuL(L, 1, i+5);
    }
    ListPrint_DuL(L);
    std::cout << "======测试 ListDelete_DuL 方式=====" << std::endl;
    index = 3;
    ListDelete_DuL(L,index,e);
    ListPrint_DuL(L);
    std::cout << "删除第"<< index << "个元素，值：" << "e=" << e << std::endl;

    std::cout << "======测试 DestroyList_DuL 方式=====" << std::endl;
    status = DestroyList_DuL(L);
    std::cout << "status=" << status << std::endl;

}
