//
// Created by 程生 on 2020/7/21.
//

#include "tree.h"
#include "stdlib.h"
#include "stdio.h"

TreeNode * alloc_node() {
    TreeNode * node = (TreeNode *)malloc(sizeof(struct treenode));
    node->lnode = node->rnode = NULL;
    node->element = 0 ;
    return  node;
}
void addNode(TreeNode * root,TreeNode * node,bool isLeft){
    if (isLeft){root->lnode = node ;}else{root->rnode = node;}

}

TreeNode *  addElement(TreeNode * root,ElementType element,bool isLeft){
    TreeNode * node = alloc_node();
    node->element = element ;
    addNode(root,node,isLeft);
    return  node ;
}

static void printInOrder(TreeNode * root){
    if (root != NULL){
        printInOrder(root->lnode);
        printf("node=%c->",root->element);
        printInOrder(root->rnode);
    }
}
static void printPreOrder(TreeNode * root){
    if (root != NULL){
        printf("node=%c->",root->element);
        printPreOrder(root->lnode);
        printPreOrder(root->rnode);
    }
}
static void printPostOrder(TreeNode * root){
    if (root != NULL){
        printPostOrder(root->lnode);
        printPostOrder(root->rnode);
        printf("node=%c->",root->element);
    }
}
// 使用队列来实现
static void printLevelOrder(TreeNode * root){
    if (root != NULL){
        printf("node=%c->",root->element);
    }
}


void print(TreeNode * root , int order){
    if (order == 1){
        printf("InOrder: ");
        printInOrder(root);
    }else if (order == 2){
        printf("PreOrder: ");
        printPreOrder(root);
    }else if (order == 3){
        printf("PostOrder: ");
        printPostOrder(root);
    }
    printf("\n");
}