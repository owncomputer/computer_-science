//
// Created by 程生 on 2020/7/17.
//

#ifndef LINEARLIST_LINKEDLIST_H
#define LINEARLIST_LINKEDLIST_H

#include "stdbool.h"
typedef  int ElementType  ;
// 表结点的结构
typedef  struct  linkednode{
     struct  linkednode * next;
     ElementType element;
} Node;
// 链式结构的表
typedef  struct  linkedlist{
    struct  linkednode * head;
    int length ;
}LinkedList;


// 对数据的操作
LinkedList * alloc_init_linked();// 在堆上创建顺序表
bool  isEmpty_linked(LinkedList * list);//是否空
//bool  isFull(LinkedList * list);//是否满栈 没有作用链表一般不会满
bool update_linked(LinkedList * list , int atIndex,ElementType newElement);
bool del_linked(LinkedList * list , int atIndex);
bool getElement_linked(LinkedList * list,int atIndex,ElementType *element);
int search_linked(LinkedList * list,ElementType element);

bool add_linked(LinkedList  * sqlist , ElementType element);
bool insert_linked(LinkedList  * list , ElementType element,ElementType newElement);
void  print(LinkedList  * list);
#endif //LINEARLIST_LINKEDLIST_H
