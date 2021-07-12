//
// Created by 张翼 on 2021/7/10.
//

#ifndef DS_SAMPLE_TRIPLET_C
#define DS_SAMPLE_TRIPLET_C

#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <ADT_Triplet.h>


Status ADT_Triplet::InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3){
    T = (ElemType *) malloc(3 * sizeof(ElemType));
    if(!T) exit(OVERFLOW);
    T[0] = v1;
    T[1] = v2;
    T[2] = v3;
    return OK;
}

Status ADT_Triplet::DestroyTriplet(Triplet &T){
    free(T);
    T = nullptr;
    return OK;
}

Status ADT_Triplet::Get(Triplet T, int i, ElemType &e){
    if (1 > i) return ERROR;
    if (3 < i) return ERROR;
    e = T[i - 1];
    return OK;
}

Status ADT_Triplet::Put(Triplet &T, int i, ElemType e){
    if (1 > i) return ERROR;
    if (3 < i) return ERROR;
    T[i - 1] = e;
    return OK;
}

Status ADT_Triplet::IsAscending(Triplet T){
    return (T[0] >= T[1]) && (T[1] >= T[2]);
}

Status ADT_Triplet::IsDescending(Triplet T){
    return (T[0] <= T[1]) && (T[1] <= T[2]);
}

Status ADT_Triplet::Max(Triplet T, ElemType &e){
    return T[0] > T[1] ? T[0] > T[2] ? T[0] : T[2] : T[1] > T[2] ? T[1] : T[2];
}

Status ADT_Triplet::Min(Triplet T, ElemType &e){
    return T[0] < T[1] ? T[0] < T[2] ? T[0] : T[2] : T[1] < T[2] ? T[1] : T[2];
}

void ADT_Triplet::tripletPrint(Triplet T, ElemType e) {
    for (int i = 1; i <= 3; ++i) {
        Get(T, i, e);
        std::cout << "第" << i << "个元素的值为：" << e << "\n";
    }
}

void ADT_Triplet::sampleTripletTest() {
    Triplet T;
    ElemType e = 0;
    ElemType max = 0;
    ElemType min = 0;
    std::cout << "======测试 InitTriplet 方式=====" << std::endl;
    Status status = InitTriplet(T, 1, 3, 5);
    std::cout << "初始化三元组状态" << status << std::endl;
    tripletPrint(T, e);
    std::cout << "======测试 Put 方式=====" << std::endl;
    Put(T, 1, 7);
    tripletPrint(T, e);
    std::cout << "======测试 IsAscending/IsDescending 方式=====" << std::endl;
    std::cout << "isAscending status=" << IsAscending(T)
              << "\n""isDescending status=" << IsDescending(T)
              << std::endl;
    std::cout << "======测试 max 方式=====" << std::endl;
    std::cout << "status = " << Max(T, max)
              << "\nmax = " << max << std::endl;
    std::cout << "======测试 min 方式=====" << std::endl;
    std::cout << "status = " << Min(T, min)
              << "\nmax = " << min << std::endl;
    std::cout << "======测试 destroyTriplet 方式=====" << std::endl;
    std::cout << "status = " << DestroyTriplet(T) << std::endl;
}

#endif //DS_SAMPLE_TRIPLET_C


