#include<iostream>
using namespace std;
int n;
struct LinkList{
    int ele;
    LinkList* left;
    LinkList* right;
};
typedef LinkList* Link;
void init_list(Link node){
    node->left=NULL;
    node->right=NULL;
    node->ele=0;
}
Link find_list(Link node,int k){
    if(k<1||k>n) return NULL;
    while(node->right!=NULL){
        node=node->right;
        if(node->ele==k) return node;
    }
    return NULL;
}
bool insert_list(Link node,int i,int ele,int k){
    if(k<1||k>n) return 0;
    if(i==0){
        Link node2=find_list(node,k);
        if(node2==NULL) return 1;
        Link temp;
        temp->ele=ele;
        temp->right=node2;
        temp->left=node2->left;
        node->left->right=temp;
        node2->left=temp;
    }else{
        Link node2=find_list(node,k);
        if(node2==NULL) return 1;
        Link temp;
        temp->ele=ele;
        temp->left=node2;
        temp->right=node2->right;
        node2->right->left=node2;
        node2->right=temp;
    }
    return 1;
}
bool delete_list(Link node,int k){
    if(k<1||k>n) return 0;
    Link node2=find_list(node,k);
    if(node2==NULL) return 1;
    node2->left->right=node2->right;
    node2->right->left=node2;
    node2->left=NULL;
    node2->right=NULL;
    return 1;
}
void print_list(Link node){
    while(node->right!=NULL){
        node=node->right;
        cout<<node->ele<<" ";
    }
}


int main(){
    int m;
    cin>>n;
    LinkList node;
    init_list(&node);
    LinkList mn;
    mn.ele=1;
    mn.left=&node;
    mn.right=NULL;
    node.right=&mn;
    int num,k;
    for(int i=2;i<=n;i++){
        cin>>k>>num;
        insert_list(&node,num,i,k);
    }
    cin>>m;
    int temp;
    for(int i=0;i<m;i++){
        cin>>temp;
        delete_list(&node,temp);
    }
    print_list(&node);
    return 0;
}