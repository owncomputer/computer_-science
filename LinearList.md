# 线性表

线性表：实现数据值之间一对一的线性关系的一种数据结构。定义为零个或多个相同特性值的有序集合，第一没有前驱，最后一个没有后继，其它均有前驱和后继数据值。



[TOC]

## 1. 线性表的实现

### 1.1 顺序实现--顺序表

>**关注点**
>
>1. 顺序表为 struct sqlist，别名SQList。它的组成部分。
>2. 对表的各种操作
>3. 表的创建可以在栈上，也可以在堆上。根据需要选择。
>
>详情代码查看[source/LinearList](./source/LinearList/SequenceList.h)

```c
// 简化数据值的类型，直接使用int，让其关注点在数据结构上
typedef int ElementType ;//数据类型

#if FIXSIZE

// 固定大小的顺序链表，这样简化可以使关注点在其结构和操作中
#define MaxCapacity 10 //默认数组容量
// 顺序表--固定容量
typedef struct sqlist{
    int length;
    ElementType element[MaxCapacity];
}SQList ;

#else

#define DefaultCapacity 2 //默认数组容量
  // 顺序表——容量自动扩充，动态性
typedef struct sqlist{
    int capacity;
    int length;
    ElementType element[0]; // 或者可以声明为ElementType * element，这样就是一个指向数组的指针。
}SQList ;


#endif

// 对数据的操作
SQList * alloc_init();// 在堆上创建顺序表
bool  isEmpty(SQList * sqlist);//是否空
bool  isFull(SQList * sqlist);//是否满
bool update(SQList * sqlist , int atIndex,ElementType newElement);
bool del(SQList * sqlist , int atIndex);
bool getElement(SQList * sqlist,int atIndex,ElementType *element);
int search(SQList * sqlist,ElementType element);

// 因为结构不同，故有些方法的使用是不能一样的
#if FIXSIZE
bool add(SQList  * sqlist , ElementType element);
bool insertE(SQList  * list , int atIndex,ElementType newElement);
#else
bool add(SQList * * sqlist , ElementType element);// 此函数可能会改变表的内存，故需要传指针变量的地址
bool insertE(SQList * * sqlist , int atIndex,ElementType newElement);// 此函数可能会改变表的内存，故需要传指针变量的地址
#endif
```





### 1.2 链式实现--单链表

>**关注点**
>
>1. 线性链表的结构 struct  linkedlist，别名LinkedList。结点的结构struct  linkednode，别名Node。
>
>2. 对表的操作
>
>3. LinkedList可以在栈或堆中创建。结点是在堆中。
>
>详情代码查看[source/LinearList](./source/LinearList/LinkedList.h)



```c
typedef  int ElementType  ;
// 表结点的结构
typedef  struct  linkednode{
     struct  linkednode * next;
     ElementType element;
} Node;
// 链式结构的表
typedef  struct  linkedlist{
    struct  linkednode * head;
    int length ;
}LinkedList;


// 对数据的操作
LinkedList * alloc_init_linked();// 在堆上创建顺序表
bool  isEmpty_linked(LinkedList * list);//是否空
//bool  isFull(LinkedList * list);//是否满栈 没有作用链表一般不会满
bool update_linked(LinkedList * list , int atIndex,ElementType newElement);
bool del_linked(LinkedList * list , int atIndex);
bool getElement_linked(LinkedList * list,int atIndex,ElementType *element);
int search_linked(LinkedList * list,ElementType element);

bool add_linked(LinkedList  * sqlist , ElementType element);
bool insert_linked(LinkedList  * list , ElementType element,ElementType newElement);
void  print(LinkedList  * list);
```





### 1.3 线性表的各种扩展

#### 1.3.1 静态链表

> **注意点**
>
> 1. 它的实现思想实际是两条链的集合，一条指向已有数据元素链的第一个结点，另一条指向没有数据元素链的第一个结点。
> 2. 对数据的操作，注意listStatics[0]、listStatics[capacity-1]，及其每个元素中的nextElementIndex的值。

```c
// 顺序表--固定容量
typedef struct sqliststaic{
    int nextElementIndex;
    ElementType element;
}SQListStatic ;

// 声明一个表
const int capacity = 20;
SQListStatic  listStatics[capacity];
//listStatics[0] 指向所有未使用的结点的链的第一个
//listStatics[capacity-1] 指向已经使用元素的第一个结点
  
```
各种操作如下表

![img](./images/datastructure_staticlinked.png)


#### 1.3.2 循环单链表



#### 1.3.3 双链表



#### 1.3.4 循环双链表



#### 1.3.5 顺序循环线性表



## 2. 线性表的应用

### 2.1 队列



### 2.2 栈



