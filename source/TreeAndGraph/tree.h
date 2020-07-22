//
// Created by 程生 on 2020/7/21.
//

#ifndef TREEANDGRAPH_TREE_H
#define TREEANDGRAPH_TREE_H

#include "stdbool.h"
typedef  char ElementType ;

typedef struct treenode{
    struct treenode * lnode;
    struct treenode * rnode;
    ElementType element;
}TreeNode;

TreeNode * alloc_node() ;

void addNode(TreeNode * root,TreeNode * node,bool isLeft);
TreeNode *  addElement(TreeNode * root,ElementType element,bool isLeft);
void print(TreeNode * root , int order);

#endif //TREEANDGRAPH_TREE_H
