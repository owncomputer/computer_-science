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



bool update_linked(LinkedList * list , int atIndex,ElementType newElement){

}
bool del_linked(LinkedList * list , int atIndex){

}

static bool getNode(LinkedList * list,int atIndex,Node * * elementNode){
    if (isEmpty_linked(list) || atIndex < -1 || atIndex >= list->length ){
        return  false ;
    }
    Node * node = (Node*)list ;//此处需要注意，我们只需head的值，是可以的，
    int i = 0 ;
    while (i < atIndex){
        node = node->next ;
        i += 1 ;
    }
    if (atIndex == -1){
        *elementNode = node ;
    } else{
        *elementNode = node->next ;
    }


    return  true ;

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

}

bool add_linked(LinkedList  * sqlist , ElementType element){
   Node * node = (Node * )malloc(sizeof(struct linkedlist));
   node->next = NULL ;
   node->element = element ;

   if (sqlist->head == NULL){
       sqlist->head = node ;
   }else{
       Node * currentNode = (Node * ) sqlist->head ;
       while (currentNode->next != NULL){
           currentNode = currentNode->next ;
       }
       currentNode->next = node ;
   }

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
     }
    return  res ;
}

void  print(LinkedList  * list){
    Node * currentNode = (Node * )list->head ;
    int i = 0 ;
    if (currentNode == NULL){
        printf("空链表\n");
    }else{
        while (currentNode->next != NULL){
            printf("%d  =  %d \n", i,currentNode->element);
            currentNode = currentNode->next ;
            i += 1 ;
        }
        printf("%d  =  %d \n", i,currentNode->element);
    }


}