
#include "stdlib.h"
#include "stdio.h"

#include "SequenceList.c"
#include "LinkedList.c"

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
    print(linkedlist);
    return 0;
}
