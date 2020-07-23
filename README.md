# computer_-science



[TOC]

# 总览

因GitHub不支持TOC等等一些markdown标记，推荐clone项目到本地，然后用Typora 软件来查看。效果比较好

## 1. 概述





## 2. 数据结构和算法

> 数据结构掌握三块知识：
>
> 1. 数据值(data values)  
> 2. 值之间的关系(relationships among them)
> 3. 数据的操作(operations applied to the data) 

**数据：**现实世界的事物在计算机中的符号表示(或者说是映射)。数据对象：性质相同的数据元素的集合，是数据的子集，大多时候简称数据。数据元素：数据的有意的基本单位。

**结构：**组成整体的各部分的搭配和安排。

**数据结构：**公式：数据结构 = 数据值(data values) + 值之间的关系(relationships among them) + 数据的操作(operations applied to the data) 。

> [Data structure - Wikipedia]
>
> In computer science, a *data structure* is a data organization, management, and storage format that enables efficient access and modification.(在计算机科学中，数据结构是一种能够进行有效访问和修改的数据组织、管理和存储格式。)
>
>  More precisely, a *data structure* is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data(更准确地说，数据结构是数据值、它们之间的关系以及可应用于数据的函数或操作的集合)



**数据类型：**一组性质相同的值的集合及定义在集合上的一些操作的总称。公式： 数据类型 = 值集 + 值集上的操作 。数据类型有两类：原子类型(不可再分的基本类型)、结构类型(若干类型组合而成，可再分)

**算法：**解决特定问题*求解步骤*的描述。在计算机中为指令有限序列。算法有五个特性：输入输出、有穷、确定、可行性。设计算法三个要求：正确、可读、健壮、运行快空间少。

算法度量：运行时间度量+ 存储空间度量。时间度量中有最坏时间复杂度和平均时间复杂度，这两个比较常用。

**常见算法的时间复杂度:** O(1)<O(logn)<O(n)<O(nlogn)<O(n^2)<O(n^3)<O(2^n)<O(n!)

![](./images/datastructure_common_time.png)


### 2.1 数据

#### 2.1.1 数据的表示

在计算机中表示一个数据，例如，表示一个人，有身高、体重、年龄等等。

在不同的语言环境中的语法各不相同，但是它们的底层所表示数据是一致。


在C中的表示一个人

```c
typedef struct Human {
    float hight ;
    float weight;
    int age;
}
```

在C++中的表示一个人

```C++
struct Human{
  public:
    float hight ;
    float weight ;
    int age;
}
或者
class Human{
   public:
    float hight ;
    float weight ;
    int age ;
}
```

在Objective-C中表示一个人

```objective-c
@interface Human : NSObject{
    float hight ;
    float weight ;
    int age ;
}
@implementation Human{
    float hight ;
    float weight ;
    int age ;
}
```

在Swift中的表示一个人

```swift
struct Human{
    var hight:Float = 0
    var weight:Float = 0
    var age:Int32 = 0
}
或者
class Human{
    var hight:Float = 0
    var weight:Float = 0
    var age:Int32 = 0
}
```

#### 2.1.2 数据的值

```C
在C中
struct Human human;//值在栈中

在C++中
Human human ;//值在栈中

在Objective-C中
Human * human = [Human alloc] init];//值在堆中，变量在栈中

在Swift中
var human = Human()//值在堆中，变量在栈中

```
它们所表示的数据的值，也就是Human的值在内存中是一致的。
```
   Human(每格4B)
  --------------   
  |  hight     |
  --------------
  |  weight    |
  --------------   
  |  age       |
  --------------

```

**所以在开发中，根据各自的情况选择合适的开发环境和合适的数据对象的表示。**





### 2.2 数据值之间的关系(结构)

**逻辑结构：**数据值之间的相互关系。它是面向问题的。

**物理结构：**数据的逻辑结构在内存中的存储形式。它是面向计算机的，逻辑结构最终需要存储在物理结构中。

#### 2.2.1四种逻辑关系(结构)

##### 2.2.1.1 值之间没关系的集合关系。
![](./images/datastructure_Collection.png)


##### 2.2.1.2 值之间一对一的线性关系
![](./images/datastructure_linear.png)

这种数据结构的详情实现参见[线性表](./LinearList.md)


##### 2.2.1.3 值之间的一对多的树形关系
![](./images/datastructure_tree.png)

这种数据结构的详情实现参见[树](./Tree.md)

##### 2.2.1.4 值之间的一对多的图形关系

![](./images/datastructure_graph.png)

这种数据结构的详情实现参见[图](./Graph.md)

#### 2.2.2二种物理关系(结构)

##### 2.2.2.1 值之间是顺序结构:逻辑关系 == 物理关系
![](./images/datastructure_sequence.png)
##### 2.2.2.2 值之间是链式结构:逻辑关系 != 物理关系
![](./images/datastructure_link.png)

### 2.3 对数据的操作

#### 2.3.1 四类基本操作:增、删、改、查

#### 2.3.2 各种操作的效率问题--算法问题




### 2.4 常见操作-查找和排序

#### 2.4.1 查找
**定义：**在查找表中确定一个关键字等于给的值的的数据元素。

**按操作分类查找有两种类型**：静态查找(仅查找)和动态查找(查找并添加或删除)。对**静态查找表一般采用线性表来组织数据**，对其进行顺序查找或对其key排序后进行折半查找；**对动态查询表，可以用二叉排序树的组织**并查找。

> 从逻辑上来说,查找所基于的数据结构是集合,**集合中的记录之间没有本质关系**。可是要想获得较高的査找性能,我们就不能不改变数据元素之间的关系,在存储时可以将查找集合组织成**表、树**等结构。
>
> 散列表页可以解决一些查找问题。

**静态查找方式：**

1.顺序查找 2. 有序表的查找(折半、插值、斐波切那查找) 3. 索引之线性索引查找(稠密索引、分块索引、倒排索引)

> 索引有线性索引、树形索引、多级索引
>
> 稠密索引:每个记录对应一个索引项。*索引项必须有序。*
>
> 分块索引所有记录分若干块，块间有序、块内无序。*索引项有最大关键码、记录个数、块首数据元素指针。*



**动态查找方式：**

> 二叉排序树：它是一颗空树，或者具有下面三个性质，左子树不空，其上所有结点的值小于根结点的值，右子树不空，其上所有结点的值大于根结点的值。左右子树也是一棵二叉排序树。
>
> 构造一棵二又排序树的目的,其实并不是为了排序,而是为了提高查找和插入删除关键字的速度。

 1.数据结构的实现 2. 查找算法的实现 3.插入、删除的实现



二叉树的平衡(AVL):每结点的左右子树高度不超过1

AVL的实现原理和算法。



**在外存上查找**(也就是在外设上查询)

数据结构采用**多路查找树**：每个结点的孩子可以有多于2个，每个结点可以存储多个元素。

四种特殊的多路查找树：2-3树、2-3-4树、B树、B+树



**散列表查找：**是一种存储结构也是一种查找技术。





#### 2.4.2 排序

## 3. 设计模式



## 4. 操作系统



## 5. 开发语言

#### 4.1 语言



#### 4.2 C



#### 4.3 C++



#### 4.4 Objective-C



#### 4.5 Swift









