#include<stdio.h>
typedef int E;
struct BinarySearchTree{
    E element;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
};
typedef struct BinarySearchTree* Tree;
_Bool create_tree(E ele){
    Tree tree=malloc(sizeof(struct BinarySearchTree));
    if(tree==NULL) return 0;
    tree->element=ele;
    tree->left=NULL;
    tree->right=NULL;
    return 1;
}

int main(){

    return 0;
}