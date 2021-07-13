//
// Created by 张翼 on 2021/7/12.
//

#include <cstdlib>
#include "ADT_List_Sq.h"
#include <iostream>

/**
 * 算法 2.3
 * 构造一个空的线性表 L
 * @param L 顺序表
 * @return 执行状态码
 */
Status ADT_List_Sq::InitList_Sq(List &L) {
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return OK;
}// initList_Sq

/**
 * 算法 2.4
 * 在顺序线性表 L 中第 i 个位置之前插入新的元素 e
 * i 的合法值为 1 <= i <= ListLength(L) + 1
 * @param L 顺序表
 * @param i 索引
 * @param e 值
 * @return 执行状态码
 */
Status ADT_List_Sq::ListInsert_Sq(List &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return ERROR;
    // 当前存储空间已满，增加分配
    if (L.length >= L.listSize) {
        auto *newBase = (ElemType *) realloc(L.elem, (L.listSize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newBase) exit(OVERFLOW);
        L.elem = newBase;
        L.listSize += LIST_INCREMENT;
    }
    // 插入位置
    ElemType *q = &(L.elem[i - 1]);
    // 插入位置及之后元素右移
    for (ElemType *p = &(L.elem[L.length - 1]); p >= q; --p) *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
}
/**
 * 算法 2.5
 * 在顺序线性表 L 中删除第 i 个元素，并用 e 返回其值
 * @param L 顺序表
 * @param i 要删除的第 i 个元素的索引
 * @param e 接收第 i 个元素值的变量
 * @return 执行状态码
 */
Status ADT_List_Sq::ListDelete_Sq(List &L, int i, ElemType &e) { 
    if(i < 1 || i > L.length) return ERROR;
    ElemType *p = &(L.elem[i - 1]);
    e = *p;
    ElemType *q = &L.elem[L.length - 1];
    for( ++p; p <= q; ++p) *(p-1) = *p;
    --L.length;
    return OK;
}
/**
 * 在顺序线性表 L 中查找第 1 个值与 e 满足 compare（） 的元素的位序
 * 若找到，则返回其在 L 中的位序，否则返回 0
 * @param L 顺序线性表
 * @param e 值 e
 * @param compare 比较函数
 * @return 执行状态码
 */
int ADT_List_Sq::LocateElem_Sq(List L, ElemType e, Status ( *compare)(ElemType , ElemType)){
    int i = 1;
    ElemType *p = L.elem;
    while(i <= L.length && !(*compare)(*p++, e)) ++i;
    if(i <= L.length) return i;
    else return 0;
}

Status ADT_List_Sq::Compare_Sq_Equal(ElemType a, ElemType b){
    if(a == b) return OK;
    else return FALSE;
}

/**
 * 算法 2.7
 * 已知顺序线性表 La 和 Lb 的元素按值非递减排列
 * 归并 La 和 Lb 得到新的顺序线性表 Lc，Lc 的元素也按值非递减排列
 * @param La 顺序线性表1
 * @param Lb 顺序线性表2
 * @param Lc 顺序线性表3
 */
void ADT_List_Sq::MergeList_Sq(List La, List Lb, List &Lc){
    ElemType *pa = La.elem, *pb = Lb.elem;
    Lc.listSize = Lc.length = La.length + Lb.length;
    ElemType *pc = Lc.elem = (ElemType*)malloc(Lc.listSize*sizeof(ElemType));
    if(!Lc.elem)exit(OVERFLOW);
    ElemType *pa_last = &La.elem[La.length-1];
    ElemType *pb_last = &Lb.elem[Lb.length-1];
    // 归并
    while(pa <= pa_last && pb <= pb_last){
        if(*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
}


Status ADT_List_Sq::DestroyList_Sq(List &L) {
    free(L.elem);
    L.elem = nullptr;
    return OK;
}

void ADT_List_Sq::Test() {
    List L;
    List Lb;
    ElemType e;
    ElemType pre_e;
    ElemType next_e;
    Status status;

    std::cout << "======测试 InitList_Sq 方式=====" << std::endl;
    status = InitList_Sq(L);
    std::cout << "初始化顺序表状态：" << status << std::endl;
    listPrint(L);
    std::cout << "======测试 ListInsert_Sq 方式=====" << std::endl;
    ListInsert_Sq(L,1,4);
    ListInsert_Sq(L,2,7);
    ListInsert_Sq(L,2,8);
    ListInsert_Sq(L,2,3);
    ListInsert_Sq(L,2,8);
    listPrint(L);
    std::cout << "======测试 LocateElem_Sq 方式=====" << std::endl;
    Status (*p)(ElemType, ElemType);
    p = Compare_Sq_Equal;
    e = 4;
    int status1 = LocateElem_Sq(L, e, p);
    e = 2;
    int status2 = LocateElem_Sq(L, e, p);
    std::cout << "status1=" << status1
                << "\tstatus2=" << status2 << std::endl;
    std::cout << "======测试 ListDelete_Sq 方式=====" << std::endl;
    ListDelete_Sq(L,1,e);
    listPrint(L);
    std::cout << "======测试 NextElem_Sq 方式=====" << std::endl;
    e = 8;
    NextElem_Sq(L, e, next_e);
    listPrint(L);
    std::cout << "next_e = " << next_e << std::endl;
    std::cout << "======测试 PriorElem_Sq 方式=====" << std::endl;
    e = 8;
    status = PriorElem_Sq(L, e, pre_e);
    listPrint(L);
    std::cout << "pre_e = " << pre_e << std::endl;
    std::cout << "======测试 ListEmpty_Sq 方式=====" << std::endl;
    std::cout << "status = " << ListEmpty_Sq(L) << std::endl;
    std::cout << "======测试 Union_Sq 方式=====" << std::endl;
    InitList_Sq(Lb);
    Union_Sq(Lb, L);
    listPrint(Lb);
    DestroyList_Sq(Lb);
    std::cout << "======测试 ClearList_Sq 方式=====" << std::endl;
    ClearList_Sq(L);
    listPrint(L);


    std::cout << "======测试 DestroyList_Sq 方式=====" << std::endl;
    std::cout << "status = " << DestroyList_Sq(L) << std::endl;
}

void ADT_List_Sq::listPrint(List l) {
    std::cout << "打印 List 成员：\n";
    for (int i = 0; i < l.length; ++i) {
        std::cout << "第" << i << "个元素：" << l.elem[i] << "\n" ;
    }
    std::cout << std::endl;
}

Status ADT_List_Sq::ClearList_Sq(List &L) {
    L.length = 0;
    return OK;
}

Status ADT_List_Sq::ListEmpty_Sq(List L) {
    if(!L.length) return TRUE;
    return FALSE;
}

Status ADT_List_Sq::ListLength_Sq(List L) {
    return L.length;
}

Status ADT_List_Sq::GetElem_Sq(List L, int i, ElemType &e) {
    if(i < 1 || i > L.length) return FALSE;
    e = L.elem[i];
    return OK;
}

Status ADT_List_Sq::PriorElem_Sq(List L, ElemType cur_e, ElemType &pre_e) {
    for(int i = 1; i < L.length; i++){
        if(L.elem[i] == cur_e){
            pre_e = L.elem[i-1];
            return OK;
        }
    }
    return FALSE;
}

Status ADT_List_Sq::NextElem_Sq(List L, ElemType cur_e, ElemType &next_e) {
    for(int i = 1; i < L.length; i++){
        if(L.elem[i] == cur_e){
            next_e = L.elem[i+1];
            return OK;
        }
    }
    return FALSE;
}

void ADT_List_Sq::Union_Sq(List &La, List Lb) {
    if(Lb.length < 0) return;
    for(int i = 0; i < Lb.length; i++){
        if(!LocateElem_Sq(La, Lb.elem[i], Compare_Sq_Equal)) {
            ListInsert_Sq(La, La.length + 1, Lb.elem[i]);
        }
    }
}



