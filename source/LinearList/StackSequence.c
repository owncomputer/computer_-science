//
// Created by 程生 on 2020/7/19.
//

#include "StackSequence.h"
#include "stdlib.h"

SQStack * alloc_init_stack(){
    SQStack * stack = (SQStack * )malloc(sizeof(struct sqstack));
    stack->top = 0 ;
    return  stack ;
}
bool  isEmpty_stack(SQStack * stack){
    return  stack->top == 0 ;
}
bool  isFull_stack(SQStack * stack){
    return  stack->top == MaxStackCapacity ;
}
bool push(SQStack  * stack , ElementType element){
      if (isFull_stack(stack)){
          return  false ;
      }
      stack->element[stack->top] = element;
      stack->top += 1 ;
    return  true ;
}
bool pop(SQStack * stack ,  ElementType * element){
    if (isEmpty_stack(stack)){
        return  false ;
    }
    stack->top -= 1 ;
    *element = stack->element[stack->top] ;
    return  true ;
}