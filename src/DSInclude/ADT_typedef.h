//
// Created by 张翼 on 2021/7/19.
//

#ifndef DS_ADT_TYPEDEF_H
#define DS_ADT_TYPEDEF_H

// 是否使用自定义数据类型（默认数据类型失效）
#define DRY_ELEMTYPE OK
#if DRY_ELEMTYPE
// 使用多项式时，使默认项失效
#define DEFAULT_ELEMTYPE_

#else
#define POLYNOMIAL_ELEMTYPE_
#endif



/*
 * 多项式
 */
#ifndef POLYNOMIAL_ELEMTYPE_
#define POLYNOMIAL_ELEMTYPE_

// 项的表示，多项式的项作为 LinkList 的数据元素
typedef struct {
    float coef;
    int expn;
} term, ElemType;// term 用于本 ADT，ElemType 为 LinkList 的数据对象名
#endif

/*
 * 带头结点的线性链表
 */
#ifndef LINKLIST_HL_TYPEDEF_
#define LINKLIST_HL_TYPEDEF_
typedef struct LNode {  // 16 内存对齐 4+4+8
    ElemType data;      // 4
    struct LNode *next; // 8
} *Link, *Position;     // 8

typedef struct {
    Link head, tail;    // 8+8
    int len;            // 4
} LinkList;             // 24 = 8+8+4+4 内存对齐
#endif


/*
 * 栈结构
 */
#ifndef STACK_SELEMTYPE_
#define STACK_SELEMTYPE_
typedef int SElemType;
#endif

#ifndef STACK_SQELEMTYPE_
#define STACK_SQELEMTYPE_
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;
#endif
/*
 * 默认的数据类型
 */
#ifndef DEFAULT_ELEMTYPE_
#define DEFAULT_ELEMTYPE_
typedef int ElemType;
#endif
/*
 * 用带表头结点的有序链表表示多项式
 */
typedef LinkList polynomial;

#endif //DS_ADT_TYPEDEF_H
