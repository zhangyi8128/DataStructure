//
// Created by 张翼 on 2021/7/19.
//

#ifndef DS_ADT_POLYNOMIAL_H
#define DS_ADT_POLYNOMIAL_H

#include "const.h"
#include "ADT_LinkList_HL.h"




class ADT_Polynomial {
    /**
     * 输入 m 项的系数和指数，建立表示一元多项式的有序链表 P
     */
    void CreatePolyn(polynomial &P, int m);

    /**
     * 销毁一元多项式 P
     */
    void DestroyPolyn(polynomial &P);

    /**
     * 打印输出一元多项式 P
     */
    void PrintPolyn(polynomial P);

    /**
     * 返回一元多项式 P 中的项数
     */
    int PolynLength(polynomial P);

    /**
     * 完成多项式相加运算，即 Pa = Pa + Pb，并销毁一元多项式 Pb
     */
    void AddPolyn(polynomial &Pa, polynomial &Pb);

    /**
     * 完成多项式相减运算，即 Pa = Pa - Pb，并销毁一元多项式 Pb
     */
    void SubtractPolyn(polynomial &Pa, polynomial &Pb);

    /**
     * 完成多项式相乘运算，即 Pa = Pa * Pb，并销毁一元多项式 Pb
     */
    void MultiplyPolyn(polynomial &Pa, polynomial &Pb);

    int cmp(term a, term b){
        if(a.expn < b.expn) return -1;
        else if(a.expn == b.expn) return 0;
        else return 1;
    }

};
//void CreatePolyn(polynomial &P, int m){
//    LinkList L;
//    InitList(L);
//    Link h = GetHead(P);
//    e.coef = 0.0;
//    e.expn = -1;
//    SetCurElem(h, e);
//    for (int i = 1; i <= m; ++i) {
//        std::cin >> e.coef >> e.expn;
//        if (!LocateElem(P, e, q, cmp)) {
//            if (MakeNode(s, e)) InsFirst(q, s);
//        }
//    }
//}

#endif //DS_ADT_POLYNOMIAL_H
