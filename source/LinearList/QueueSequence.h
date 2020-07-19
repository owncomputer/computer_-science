//
// Created by 程生 on 2020/7/19.
//

#ifndef LINEARLIST_QUEUESEQUENCE_H
#define LINEARLIST_QUEUESEQUENCE_H

#include "stdbool.h"

#define  MAX_QUEUE_SQ 6

typedef  int ElementType ;

// (rear + 1)%MAX_QUEUE_SQ == head ,表示队列满了
// head == rear ，表示队列空了
typedef struct queue_sq{
    int head ; // 指向头元素位置，
    int rear ;//指向尾元素的下一个位置。
   // int length ; 可添加一个变量，提高一些操作的效率
    ElementType elements[MAX_QUEUE_SQ];
}QueueSQ;

// 对数据的操作
QueueSQ * alloc_init_queue_sq();// 在堆上创建顺序表
bool  isEmpty_queue_sq(QueueSQ * queue);//是否空
bool  isFull_queue_sq(QueueSQ * queue);//是否空
bool enqueue_sq(QueueSQ  * queue , ElementType element);
bool dequeue_sq(QueueSQ * queue , ElementType * element);
int search_queue_sq(QueueSQ * queue,ElementType element);
void  print_queue_sq(QueueSQ  * list);

#endif //LINEARLIST_QUEUESEQUENCE_H
