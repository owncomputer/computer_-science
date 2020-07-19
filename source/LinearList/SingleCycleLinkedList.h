//
// Created by 程生 on 2020/7/18.
//

#ifndef LINEARLIST_SINGLECYCLELINKEDLIST_H
#define LINEARLIST_SINGLECYCLELINKEDLIST_H

#include "stdbool.h"

typedef  int ElementType ;

typedef  struct cyclelistnode{
    struct cyclelistnode *   next ;
    ElementType element;
}CLNode;

typedef  struct cyclelist{
    CLNode * head ;
    CLNode * rear ;
    int length;
}CycleList;


// 对数据的操作
CycleList * alloc_init_cycle_linked();// 在堆上创建顺序表
bool  isEmpty_cycle_linked(CycleList * list);//是否空
//bool  isFull(LinkedList * list);//是否满栈 没有作用链表一般不会满
bool update_cycle_linked(CycleList * list , int atIndex,ElementType newElement);
bool del_cycle_linked(CycleList * list , int atIndex);
bool getElement_cycle_linked(CycleList * list,int atIndex,ElementType *element);
int search_cycle_linked(CycleList * list,ElementType element);

bool add_cycle_linked(CycleList  * sqlist , ElementType element);
bool insert_cycle_linked(CycleList  * list , ElementType element,ElementType newElement);
void  printcycle_linked(CycleList  * list);

#endif //LINEARLIST_SINGLECYCLELINKEDLIST_H
