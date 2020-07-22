#include "stdlib.h"
#include "stdio.h"
#include "tree.c"
int main() {
    /*
     *                      A
     *
     *               B           C
     *
     *           D             E    F
     *
     *        G     H           I
     */

    TreeNode * root = alloc_node();

    root->element = 'A';

    TreeNode * newNodeL =   addElement(root,'B', true);
    TreeNode * newNodeL_1 =   addElement(newNodeL,'D', true);
    TreeNode * newNodeL_1_1 =   addElement(newNodeL_1,'G', true);
    TreeNode * newNodeL_1_2 =   addElement(newNodeL_1,'H', false);

    TreeNode * newNodeR =   addElement(root,'C', false);

    TreeNode * newNodeR_1 =   addElement(newNodeR,'E', true);
    TreeNode * newNodeR_2 =   addElement(newNodeR,'F', false);
    TreeNode * newNodeR_1_2 =   addElement(newNodeR_1,'I', false);

    print(root,1);
    print(root,2);
    print(root,3);
    return 0;
}
