//
// Created by 张翼 on 2021/7/15.
//

#include "ADT_DuLinkList.h"

int ADT_DuLinkList::ListLength_L(DuLinkList L) {
    int length = 0;
    DuLNode *p = L;
    while(p) {
        p = p->next;
        ++length;
    }
    return length;
}

Status ADT_DuLinkList::GetElem_L(DuLinkList L, int i, ElemType &e) {
    DuLNode *p = L->next;
    int j = 1;

    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
}

int ADT_DuLinkList::LocateElem_L(DuLinkList L, ElemType e) {
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
