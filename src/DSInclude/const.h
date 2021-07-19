//
// Created by 张翼 on 2021/7/10.
//

#ifndef DS_CONST_H
#define DS_CONST_H
/**
 * 约定数据结构的表示用类型定义 typedef 描述
 * 数据元素类型约定为 ElemType，由用户在使用该数据类型时自行定义
 *
 * 基本操作的算法描述形式
 * 函数类型 函数名（函数参数表） {
 *  //算法说明
 *  语句序列
 *  } // 函数名
 *
 *  一般而言，a、b、c、d、e 等用作数据元素名
 *          i、j、k、m、n 等用作整形变量名
 *          p、q、r 等用作指针变量名
 */

/**
 * 基本函数有
 * 求最大值             max（表达式 1 ，……，表达式 n ）
 * 求最小值             min（表达式 1 ，……，表达式 n ）
 * 求绝对值             abs（表达式）
 * 求不足整数值          floor（表达式）
 * 求进位整数值          ceil（表达式）
 * 判定文件结束          eof（文件变量） 或 eof
 * 判定行结束            eoln（文件变量） 或 eoln
 */

/**
 * 支持短路运算，即：
 * 与运算 && ： 对于 A && B ，当 A 的值为 0 时，不再对 B 求值
 * 或运算 || ： 对于 A || B ，当 A 的值为非 0 时，不再对 B 求值
 */

// 函数结构状态代码
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
// 初始存储空间分配量
#define STACK_INIT_SIZE 100
// 存储空间分配增量
#define STACKINCREMENT 10
// Status 是函数的类型，其值是函数结构状态代码
// 当函数返回值为函数结构状态代码时，函数定义为 Status 类型
typedef     int     Status;
// 用户自定的数据类型
//typedef     int     ElemType;



#endif //DS_CONST_H







