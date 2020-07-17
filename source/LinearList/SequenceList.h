//
// Created by 程生 on 2020/7/17.
//

#ifndef LINEARLIST_SEQUENCELIST_H
#define LINEARLIST_SEQUENCELIST_H

#include "flags.h"
#include "stdbool.h"


// 简化数据值的类型，直接使用int，让其关注点在数据结构上
typedef int ElementType ;//数据类型

#if FIXSIZE

// 固定大小的顺序链表，这样简化可以使关注点在其结构和操作中
#define MaxCapacity 10 //默认数组容量
// 顺序表--固定容量
typedef struct sqlist{
    int length;
    ElementType element[MaxCapacity];
}SQList ;

#else

#define DefaultCapacity 2 //默认数组容量
  // 顺序表——容量自动扩充，动态性
typedef struct sqlist{
    int capacity;
    int length;
    ElementType element[0]; // 或者可以声明为ElementType * element，这样就是一个指向数组的指针。
}SQList ;


#endif

// 对数据的操作
SQList * alloc_init();// 在堆上创建顺序表
bool  isEmpty(SQList * sqlist);//是否空
bool  isFull(SQList * sqlist);//是否满
bool update(SQList * sqlist , int atIndex,ElementType newElement);
bool del(SQList * sqlist , int atIndex);
bool getElement(SQList * sqlist,int atIndex,ElementType *element);
int search(SQList * sqlist,ElementType element);

// 因为结构不同，故有些方法的使用是不能一样的
#if FIXSIZE
bool add(SQList  * sqlist , ElementType element);
bool insertE(SQList  * list , int atIndex,ElementType newElement);
#else
bool add(SQList * * sqlist , ElementType element);// 此函数可能会改变表的内存，故需要传指针变量的地址
bool insertE(SQList * * sqlist , int atIndex,ElementType newElement);// 此函数可能会改变表的内存，故需要传指针变量的地址
#endif

#endif //LINEARLIST_SEQUENCELIST_H


