
#include "stdlib.h"
#include "stdio.h"

#include "SequenceList.c"
#include "LinkedList.c"
#include "QueueSequence.c"
#include "StackSequence.c"

int main() {
///////////////////////////////SequenceList////////////////////////////////////////////
    int size = sizeof( struct sqlist);
    //0x00007fd268e00020



#if  FIXSIZE
   // SQList * list = alloc_init(); // heap中创建顺序表
    SQList list ;

#else
    SQList * list = alloc_init(); // heap中创建顺序表
#endif

    add(&list,1);
    add(&list,2);
    printf("SQList size=%d ,sqlist=%ld\n",size , sizeof(list));
    /*
    add(&list,3);
    add(&list,4);
    add(&list,5);
    del(list,0);
     */

    insert(&list,2,3);

   printf("\n");
   ElementType  el ;
#if  FIXSIZE
    for (int i = 0; i < list.length ; ++i) {
        printf(" %d get element is %d   =  %d  , \n",i,getElement(&list,i,&el),el );
    }

#else
    for (int i = 0; i < list->length ; ++i) {
        printf(" %d get element is %d   =  %d  , \n",i,getElement(list,i,&el),el );
    }
#endif

///////////////////////////////LinkedList////////////////////////////////////////////

    LinkedList * linkedlist = alloc_init_linked();

    print(linkedlist);

     add_linked(linkedlist,1);
    add_linked(linkedlist,2);
    insert_linked(linkedlist,2,3);
    print(linkedlist);

    ElementType  elementL ;
    for (int j = 0; j < linkedlist->length; ++j) {
        getElement_linked(linkedlist,j,&elementL);
        printf("j = %d  , element = %d\n" , j , elementL);
    }

    del_linked(linkedlist,0);
    print(linkedlist);

///////////////////////////////Queue////////////////////////////////////////////
    QueueSQ * queue = alloc_init_queue_sq();
    enqueue_sq(queue,1);
    enqueue_sq(queue,2);
    enqueue_sq(queue,3);
    enqueue_sq(queue,4);
    enqueue_sq(queue,5);
    print_queue_sq(queue);
    printf("---------------\n");
    enqueue_sq(queue,6);
    print_queue_sq(queue);
    ElementType  elQ ;
    dequeue_sq(queue,&elQ);
    printf("elQ=%d\n",elQ);
    dequeue_sq(queue,&elQ);
    printf("elQ=%d\n",elQ);
    print_queue_sq(queue);

    enqueue_sq(queue,6);
    enqueue_sq(queue,7);
    print_queue_sq(queue);
    enqueue_sq(queue,8);
    print_queue_sq(queue);

    ///////////////////////////////Stack////////////////////////////////////////////

    SQStack * stack = alloc_init_stack();

    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    push(stack,6);

    ElementType  stck ;
    pop(stack,&stck);
    pop(stack,&stck);

    return 0;
}
