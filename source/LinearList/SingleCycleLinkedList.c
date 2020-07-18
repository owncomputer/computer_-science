//
// Created by 程生 on 2020/7/18.
//

#include "SingleCycleLinkedList.h"
#include "stdlib.h"

CycleList * alloc_init_cycle_linked(){
    CycleList * list = (CycleList *) malloc(sizeof(struct cyclelist));
    list->length = 0 ;
    // list->head = NULL ;不能设置成NULL，不利于后面代码的执行
    list->head = list->rear = (CLNode *)list ;// 指针指向自己(或者说是头指针)
}
bool  isEmpty_cycle_linked(CycleList * list){
    return  list->length == 0; // list.head == (CLNode *)list
}
//bool  isFull(LinkedList * list);//是否满栈 没有作用链表一般不会满
bool update_cycle_linked(CycleList * list , int atIndex,ElementType newElement){

}
bool del_cycle_linked(CycleList * list , int atIndex){

}
bool getElement_cycle_linked(CycleList * list,int atIndex,ElementType *element){

}
int search_cycle_linked(CycleList * list,ElementType element){

}

bool add_cycle_linked(CycleList  * sqlist , ElementType element){

    CLNode * newnode = (CLNode * )malloc(sizeof(struct cyclelistnode));
    newnode->element = element ;
    newnode->next = NULL ;


    // O(1)。此处有取巧之处
    newnode->next = sqlist->rear->next ;
    sqlist->rear->next = newnode ;
    sqlist->rear = newnode;
    sqlist->length += 1 ;

    return  true ;
}
bool insert_cycle_linked(CycleList  * list , ElementType element,ElementType newElement){

}
void  print(CycleList  * list){

}