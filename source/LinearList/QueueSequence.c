//
// Created by 程生 on 2020/7/19.
//

#include "QueueSequence.h"
#include "stdlib.h"
#include "stdio.h"
QueueSQ * alloc_init_queue_sq(){
    QueueSQ * queue = (QueueSQ *) malloc(sizeof( struct queue_sq));
    queue->rear = 0;
    queue->head = 0 ;
   // queue->length = 0 ;
    return  queue ;
}
bool  isEmpty_queue_sq(QueueSQ * queue){
    return   queue->rear == queue->head ;
      // return queue->length == 0 ;
}
// 最大容量-1表示队列满了
bool  isFull_queue_sq(QueueSQ * queue){
    return   ((queue->rear + 1)%MAX_QUEUE_SQ) == queue->head ;
}
//入队
bool enqueue_sq(QueueSQ  * queue , ElementType element){
     if (isFull_queue_sq(queue)){
         return  false ;
     }
     queue->elements[queue->rear] = element ;
     queue->rear = (queue->rear +1)%MAX_QUEUE_SQ ;
     // queue->length += 1 ;
    return  true ;
}
//出队
bool dequeue_sq(QueueSQ * queue , ElementType * element){
    if (isEmpty_queue_sq(queue)){
        return  false ;
    }
    *element =   queue->elements[queue->head] ;
    queue->head = (queue->head + 1 )%MAX_QUEUE_SQ ;
    // queue->length -= 1 ;
    return  true ;
}
// 遍历及查找
int search_queue_sq(QueueSQ * queue,ElementType element){

    int endIndex = MAX_QUEUE_SQ - 1 ;
    bool rearBeforeHead = false ;
    if (queue->rear > queue->head){
         endIndex = queue->rear ;
    } else{
        rearBeforeHead = true ;
    }
    for (int i = queue->head; i <= endIndex; ++i) {
        if (element == queue->elements[i]){
            return  i ;
        }
       // printf(" index=%d , value=%d",i,queue->elements[i]);
    }
    if (rearBeforeHead){
        for (int i = 0; i < queue->rear; ++i) {
            if (element == queue->elements[i]){
                return  i ;
            }
            //printf(" index=%d , value=%d",i,queue->elements[i]);
        }
    }
    return  -1 ;
}

void  print_queue_sq(QueueSQ  * queue){
    if (isEmpty_queue_sq(queue)) {
        return;
    }
    int endIndex = MAX_QUEUE_SQ - 1 ;
    bool rearBeforeHead = false ;
    if (queue->rear > queue->head){
        endIndex = queue->rear -1  ;
    } else{
        rearBeforeHead = true ;
    }
    for (int i = queue->head; i <= endIndex; ++i) {
        printf(" index=%d , value=%d \n",i,queue->elements[i]);
    }
    if (rearBeforeHead){
        for (int i = 0; i < queue->rear; ++i) {
            printf(" index=%d , value=%d\n",i,queue->elements[i]);
        }
    }
}