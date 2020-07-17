//
// Created by 程生 on 2020/7/17.
//

#include "SequenceList.h"
#include  "stdlib.h"
#include "memory.h"
#include "stdio.h"

SQList * alloc_init(){
#if FIXSIZE
   SQList * sqlist= (SQList *) malloc(sizeof(struct sqlist)) ;
   memset(sqlist,0,sizeof(struct sqlist));
#else
    SQList * sqlist= (SQList *) malloc(sizeof(struct sqlist) + sizeof(ElementType)*DefaultCapacity) ;
     memset(sqlist,0,sizeof(struct sqlist) + sizeof(ElementType)*DefaultCapacity);
    sqlist->capacity = DefaultCapacity ;
#endif
    sqlist->length = 0 ;
    return  sqlist ;
}

#if !FIXSIZE
static  void reallocSqlist(SQList * * list){
    SQList * sqlist = *list ;
    int new_size =  sizeof(struct sqlist) +    (sizeof(ElementType))*(sqlist->capacity)*2 ;
    SQList * newlist = (SQList *)malloc(new_size) ; //假定分配成功
    memset(newlist,0,new_size);
    int copy_size = sizeof(struct sqlist) +  (sizeof(ElementType))*(sqlist->capacity) ;
    memcpy(newlist,sqlist,copy_size) ;// 拷贝原来的数据值
    newlist->capacity = (sqlist->capacity)*2 ;// 更新容量
    printf("old address = %p",*list);
    free(*list); //释放旧内容

    *list =  newlist; //指向新的内存
    printf("new address = %p",*list);

}
#endif


bool  isEmpty(SQList * sqlist){
    //sqlist不能为空
    return sqlist->length == 0 ;
}
bool  isFull(SQList * sqlist){
    //sqlist不能为空
#if FIXSIZE
    return sqlist->length == MaxCapacity ;
#else
    return sqlist->length == sqlist->capacity ;
#endif
}

#if FIXSIZE
bool add(SQList  * list , ElementType element){
    if(list != NULL ){
        if(isFull(list)){
            printf("表满了 = %p",list);
            return false ;
        }
        SQList * sqlist = list ;
        sqlist->element[sqlist->length] = element;
        sqlist->length += 1 ;

        return  true ;
    }
    return  false ;
}
#else
bool add(SQList * * list , ElementType element){
    if(list != NULL && *list != NULL){
        // 数据满了，需要扩容。一般按原先两倍开始扩容
        if(isFull(*list)){
            reallocSqlist(list);
        }
        SQList * sqlist = *list ;
        sqlist->element[sqlist->length] = element;
        sqlist->length += 1 ;

        return  true ;
    }
    return  false ;
}
#endif

bool update(SQList * sqlist , int atIndex,ElementType newElement){
    if (atIndex >=0 && atIndex < sqlist->length){
        sqlist->element[atIndex] = newElement ;
        return  true;
    }
    return  false ;
}
#if FIXSIZE
bool insert(SQList  * list , int atIndex,ElementType newElement){

    // 位置不对 直接返回false
    if (atIndex  < 0 && atIndex > MaxCapacity-1 ){
        return false ;
    }
    if (isFull(list)){
        return false ;
    }

    SQList * sqlist = list ;
    for (int i = sqlist->length -1; i > atIndex   ; --i) {
        sqlist->element[i+1] = sqlist->element[i] ; //atIndex之后的每个值向后移动
    }
    sqlist->element[atIndex] = newElement ;
    sqlist->length += 1 ;
    return  true ;
}
#else
bool insert(SQList * * list , int atIndex,ElementType newElement){



     // 位置不对 直接返回false
    if (atIndex  < 0 && atIndex > (*list)->length  ){
        return false ;
    }
     if(isFull(*list)){
         reallocSqlist(list);
     }


    SQList * sqlist = *list ;
    for (int i = sqlist->length -1; i > atIndex   ; --i) {
        sqlist->element[i+1] = sqlist->element[i] ; //atIndex之后的每个值向后移动
    }
    sqlist->element[atIndex] = newElement ;
    sqlist->length += 1 ;
    return  true ;
}
#endif


bool del(SQList * sqlist , int atIndex){
    if (atIndex >=0 && atIndex < sqlist->length){
        for (int i = atIndex; i < sqlist->length -1  ; ++i) {
            sqlist->element[i] = sqlist->element[i+1] ; //atIndex之后的每个值向前移动
        }
        sqlist->length -= 1 ;
        return  true ;
    }
    return  false ;
}
bool getElement(SQList * sqlist,int atIndex,ElementType *element){
    if (atIndex >=0 && atIndex < sqlist->length) {
        *element =    sqlist->element[atIndex];
        return  true ;
    }
    return  false;
}

// 最普通的循环遍历，时间复杂度O(n)
static  int searchEvery(SQList * sqlist,ElementType element){
    for (int i = 0; i < sqlist->length; ++i) {
        if (sqlist->element[i] == element){
            return  i ;
        }
    }
    return  -1 ;
}
//这里面的查找可以通过各种优化算法来实现，提高效率,
int search(SQList * sqlist,ElementType element){
    return searchEvery(sqlist,element);
}
