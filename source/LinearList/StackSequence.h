//
// Created by 程生 on 2020/7/19.
//

#ifndef LINEARLIST_STACKSEQUENCE_H
#define LINEARLIST_STACKSEQUENCE_H

#include "stdbool.h"


typedef int ElementType ;//数据类型

#define MaxStackCapacity 5 //默认数组容量
// 顺序表--固定容量
typedef struct sqstack{
   // int length;
    int top ;  //两种实现意义都可以：1.指向栈顶，即为可添加的下一个位置。2.指向最顶端的元素的位置，空栈为值-1。
    ElementType element[MaxStackCapacity];
}SQStack ;


SQStack * alloc_init_stack();// 在堆上创建顺序表
bool  isEmpty_stack(SQStack * stack);//是否空
bool  isFull_stack(SQStack * stack);//是否满
bool push(SQStack  * stack , ElementType element);
bool pop(SQStack * stack ,  ElementType * element);

#endif //LINEARLIST_STACKSEQUENCE_H
