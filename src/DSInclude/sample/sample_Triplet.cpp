//
// Created by 张翼 on 2021/7/10.
//

#ifndef DS_SAMPLE_TRIPLET_H

#include <sample_Triplet.h>
#include <malloc.h>
#include <stdlib.h>

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3){
    T = (ElemType *) malloc(3 * sizeof(ElemType));
    if(!T) exit(OVERFLOW);
    T[0] = v1;
    T[1] = v2;
    T[2] = v3;
    return OK;
}

Status DestroyTriplet(Triplet &T){
    free(T);
    T = nullptr;
    return OK;
}

Status Get(Triplet T, int i, ElemType &e){
    if (1 > i) return ERROR;
    if (3 < i) return ERROR;
    e = T[i - 1];
    return OK;
}

Status Put(Triplet &T, int i, ElemType e){
    if (1 > i) return ERROR;
    if (3 < i) return ERROR;
    T[i - 1] = e;
    return OK;
}

Status IsAscending(Triplet T){
    return (T[0] >= T[1]) && (T[1] >= T[2]);
}

Status IsDescending(Triplet T){
    return (T[0] <= T[1]) && (T[1] <= T[2]);
}

Status Max(Triplet T, ElemType &e){
    return T[0] > T[1] ? T[0] > T[2] ? T[0] : T[2] : T[1] > T[2] ? T[1] : T[2];
}

Status Min(Triplet T, ElemType &e){
    return T[0] < T[1] ? T[0] < T[2] ? T[0] : T[2] : T[1] < T[2] ? T[1] : T[2];
}
#endif //DS_SAMPLE_TRIPLET_H

