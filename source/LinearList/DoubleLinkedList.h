//
// Created by 程生 on 2020/7/18.
//

#ifndef LINEARLIST_DOUBLELINKEDLIST_H
#define LINEARLIST_DOUBLELINKEDLIST_H

typedef  int ElementType ;

typedef struct  doublelinkedlistnode{
    struct  doublelinkedlistnode * next ;
    struct  doublelinkedlistnode * previous ;
    ElementType  element;
}DoubleListNode;


typedef  struct  doublelinkedlist{
    DoubleListNode * head ;
    int length;
}DoubleListList;

typedef  struct  doublecyclelinkedlist{
    DoubleListNode * head ;
    DoubleListNode * rear ;
    int length;
}DoubleCycelListList;



#endif //LINEARLIST_DOUBLELINKEDLIST_H
