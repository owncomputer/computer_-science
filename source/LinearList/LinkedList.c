//
// Created by 程生 on 2020/7/17.
//

#include "LinkedList.h"
#include "stdlib.h"
#include "stdio.h"
LinkedList * alloc_init_linked(){
   LinkedList * list = (LinkedList *) malloc(sizeof(struct linkedlist));//不做空判段，只关心核心逻辑
   list->length = 0;
   list->head = NULL ;

    return  list;
}
bool  isEmpty_linked(LinkedList * list){
    return  list->length == 0 ;
}


static bool getNode(LinkedList * list,int atIndex,Node * * elementNode){
    if (isEmpty_linked(list) || atIndex < -1 || atIndex >= list->length ){
        return  false ;
    }
    Node * node = (Node*)list ;//此处需要注意，我们只需head的值，是可以的，
    int i = -1 ;
    while (i < atIndex){
        node = node->next ;
        i += 1 ;
    }
    *elementNode = node ;



    return  true ;

}
bool update_linked(LinkedList * list , int atIndex,ElementType newElement){
    Node * node ;
    bool res =  getNode(list,atIndex,&node) ;
    if (res){
        node->element = newElement ;
    }

    return  res ;
}
bool del_linked(LinkedList * list , int atIndex){

    Node  * preNode ;
    bool res = getNode(list,atIndex - 1 ,&preNode);
    if (res){
          Node * node = preNode->next ;
          preNode->next = preNode->next->next;
          free(node);
          node = NULL ;
          list->length -= 1 ;
    }
    return  res ;
}

bool getElement_linked(LinkedList * list,int atIndex,ElementType *element) {

    Node * node ;
    bool res =  getNode(list,atIndex,&node);
    if (res){
        *element = node->element ;
    }
    return  res ;
}
int search_linked(LinkedList * list,ElementType element){
    Node * currentNode = (Node * ) list ;
    int index = -1 ;
    while (currentNode->next != NULL){
        currentNode = currentNode->next ;
        index += 1 ;
        if (currentNode->element == element){
            return index ;
        }
    }


    return  index ;
}

bool add_linked(LinkedList  * sqlist , ElementType element){
   Node * node = (Node * )malloc(sizeof(struct linkedlist));
   node->next = NULL ;
   node->element = element ;

    Node * currentNode = (Node * ) sqlist ;
    while (currentNode->next != NULL){
           currentNode = currentNode->next ;
    }
    currentNode->next = node ;

    sqlist->length  += 1 ;
    return  true ;

}
bool insert_linked(LinkedList  * list , int atIndex,ElementType newElement){
     Node * preNode ;
     bool res = getNode(list,atIndex - 1,&preNode);
     if (res){
         Node * node = (Node * )malloc(sizeof(struct linkedlist));
         node->next = NULL ;
         node->element = newElement ;

         node->next = preNode->next;
         preNode->next = node ;
         list->length += 1 ;
     }
    return  res ;
}

void  print(LinkedList  * list){
    Node * currentNode = (Node * )list ;
    int i = 0;
    while (currentNode->next != NULL){

        currentNode = currentNode->next ;
        printf("%d  =  %d \n", i,currentNode->element);
        i += 1 ;

    }
    if (i == 0){
        printf("空链表\n");
    }

}