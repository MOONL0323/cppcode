#include<iostream>
typedef int E;
class LinkList{
    struct List
    {
        E ele;
        List* left;
        List* right;
    }*node;
    bool init_list(E ele);
    bool insert_list(E ele,int i);
    bool delete_list(int i);
    bool delete_list(E ele);
    E find_list(int i);
    int find_list(E ele);
    void print_list();
};
bool LinkList::init_list(E ele){
    this->node->left=nullptr;
    this->node->right=nullptr;
    this->node->ele=ele;
}
bool LinkList::insert_list(E ele,int i){
    
}
int main(){

    return 0;
}