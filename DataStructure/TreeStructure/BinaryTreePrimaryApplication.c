#include<stdio.h>
#include <malloc.h>

typedef char E;
struct Tree{
    E ele;
    struct Tree* left;
    struct Tree* right;
};

typedef struct Tree* TreeNode;
void preOrder(TreeNode root){//传入的是二叉树的根结点
    if(root==NULL) return;
    preOrder(root->left);
    printf("%c\n",root->ele);
    //printf("\n");

    preOrder(root->right);
}
int main(){
    TreeNode a=malloc(sizeof(struct Tree));
    TreeNode b=malloc(sizeof(struct Tree));
    TreeNode c=malloc(sizeof(struct Tree));
    TreeNode d=malloc(sizeof(struct Tree));
    TreeNode e=malloc(sizeof(struct Tree));
    TreeNode f= malloc(sizeof(struct Tree));
    TreeNode g= malloc(sizeof(struct Tree));
    TreeNode h= malloc(sizeof(struct Tree));
    a->ele='A';
    b->ele='B';
    c->ele='C';
    d->ele='D';
    e->ele='E';
    f->ele='F';
    g->ele='G';
    h->ele='H';
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    d->right=NULL;
    d->left=NULL;
    e->left=NULL;
    e->right=NULL;
    f->left=NULL;
    f->right=NULL;
    g->left=NULL;
    g->right=NULL;
    h->left=NULL;
    h->right=NULL;
    preOrder(a);
    return 0;
}