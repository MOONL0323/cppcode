#include<iostream>
#include<string>
#include<queue>
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
    void LevelOrder(BiTreeNode* t);
public:
    BiTree(){};
    ~BiTree(){};
    void CreateTree(string TreeArray);
    BiTreeNode* CreateBiTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();

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

void BiTree::LevelOrder() {
    LevelOrder(Root);
}

void BiTree::LevelOrder(BiTreeNode *t) {
    queue<BiTreeNode*> tq;
    BiTreeNode* p=t;
    if(p!=NULL){
        tq.push(p);
        while(!tq.empty()){
            p=tq.front();
            tq.pop();
            cout<<p->data;
            if(p->LeftChild)
                tq.push(p->LeftChild);
            if(p->RightChild)
                tq.push((p->RightChild));
        }
    }
    return;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        BiTree a;
        a.CreateTree(str);
        a.LevelOrder();
       // a.InOrder();
        cout<<endl;
    }
    return 0;
}