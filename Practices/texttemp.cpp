#include<iostream>
#include<string>
#include<stack>
using namespace std;

class BiTreeNode{
public:
    char data;
    BiTreeNode* LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode(){}
};

class BiTree{
private:
    BiTreeNode* Root;
    int pos;
    string strTree;
    //BiTreeNode* CreateBiTree;
    void PreOrder(BiTreeNode* t);
    void InOrder(BiTreeNode* t);
    void PostOrder(BiTreeNode* t);
    void PostOrderDemo(BiTreeNode* t);
public:
    BiTree(){};
    ~BiTree(){};
    void CreateTree(string TreeArray);
    BiTreeNode* CreateBiTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
    void PostOrderDemo();
};

void BiTree::CreateTree(string TreeArray){
    pos=0;
    strTree.assign(TreeArray);
    Root=CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree(){
    BiTreeNode* T;
    char ch;
    ch=strTree[pos++];
    if(ch=='0')
        T=NULL;
    else{
        T=new BiTreeNode();
        T->data=ch;
        T->LeftChild=CreateBiTree();
        T->RightChild=CreateBiTree();
    }
    return T;
}

void BiTree::InOrder(){
    InOrder(Root);
}

void BiTree::InOrder(BiTreeNode* t){
    if(t!=NULL){
        InOrder(t->LeftChild);
        cout<<t->data;
        InOrder(t->RightChild);
    }
    //cout<<endl;
    return;
}

void BiTree::PreOrder(){
    PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode* t){
    if(t!=NULL){
        cout<<t->data;
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
    //cout<<endl;
    return;
}

void BiTree::PostOrder(){
    PostOrder(Root);
}

void BiTree::PostOrder(BiTreeNode* t){
    if(t!=NULL){
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data;
    }
    //cout<<endl;
    return;
}

void BiTree::PostOrderDemo() {
    PostOrderDemo(Root);
}

void BiTree::PostOrderDemo(BiTreeNode *t) {
    int tag=0;
    stack<BiTreeNode*> s1;
    stack<int> s2;
    BiTreeNode* T=t;
    if(t==NULL) return;
    else{
        BiTreeNode* p=T;
        do{
            if(p!=NULL){
                s1.push(p);
                tag=0;
                s2.push(tag);
                //if(p->LeftChild)
                p=p->LeftChild;
            }else{
                int temp=s2.top();
                if(temp==0){
                    s2.pop();
                    tag=1;
                    s2.push(tag);
                    BiTreeNode* tmp=s1.top();
                    p=tmp->RightChild;
                }else{
                    p=s1.top();
                    s1.pop();
                    s2.pop();
                    cout<<p->data;
                    p=NULL;
                }
            }
        }while(!s1.empty());
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        BiTree a;
        a.CreateTree(str);
        //a.PostOrder();
        a.PostOrderDemo();
        cout<<endl;
    }
    return 0;
}