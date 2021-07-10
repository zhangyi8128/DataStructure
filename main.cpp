#include <iostream>
#include <sample_Triplet.h>
#include "const.h"

void tripletPrint(Triplet T, ElemType e);

int main() {
    system("chcp 65001");
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
    std::cout << "======测试 IsAscending 方式=====" << std::endl;
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
    return 0;
}
void tripletPrint(Triplet T, ElemType e) {
    for (int i = 1; i <= 3; ++i) {
        Get(T, i, e);
        std::cout << "第" << i << "个元素的值为:" << e << "\n";
    }
}

