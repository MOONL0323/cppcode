#include<iostream>
using namespace std;
#define ok 0
#define error -1

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(){
        next=NULL;
    }
};

class LinkList{
public:
    ListNode* head;
    int len;
    LinkList();
    ~LinkList();
    ListNode* LL_index(int i);
    int LL_get(int i);
    int LL_insert(int i,int item);
    int LL_del(int i);
    void LL_display();
};

LinkList::LinkList(){
    head=new ListNode();
    len=0;
}
LinkList::~LinkList(){
    ListNode *p,*q;
    p=head;
    while(p!=NULL){
        q=p;
        p=p->next;
        delete q;
    }
    len=0;
    head=NULL;
}
void LinkList::LL_display(){
    ListNode *p;
    p=head->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
ListNode* LinkList::LL_index(int i){
    ListNode* node2=head;
    node2=node2->next;
    while(i--){
        node2->next;
    }
    if(node2==NULL) return NULL;
    return node2;
}
int LinkList::LL_get(int i){
    if(i<1) return error;
    ListNode* node2=head;
    //node2=node2->next;
    while(i--){
        node2=node2->next;
        if(node2==NULL) return error;
    }

    return node2->data;
}
int LinkList::LL_insert(int i,int item){
    if(i < 1) return error;
    ListNode* node2=head;
    while (--i) {
        node2 = node2->next;
        if(node2 == NULL) return error;
    }
    ListNode *node = new ListNode();
    //if(node == NULL) return error;   //创建一个新的结点，如果内存空间申请失败返回0
    node->data = item;   //将元素保存到新创建的结点中
    node->next = node2->next;   //先让新插入的节点指向原本位置上的这个结点
    node2->next = node;   //接着将前驱结点指向新的这个结点
    return ok;
}
int LinkList::LL_del(int i){
    ListNode* node2=head;
    while(--i){
        node2=node2->next;
        if(node2==NULL) return error;
    }

    ListNode* temp;
    temp=node2->next;
    node2->next=node2->next->next;
    delete temp;
    return ok;
}
int main(){
    int n;
    cin>>n;
    LinkList node;
    int num;
    for(int i=1;i<=n;i++){
        cin>>num;
        node.LL_insert(i,num);
    }
    node.LL_display();
    for(int i=0;i<2;i++){
        int p,ele;
        cin>>p>>ele;
        int temp=node.LL_insert(p,ele);
        if(temp==error) cout<<"error"<<endl;
        else
        node.LL_display();
    }
    for(int i=0;i<2;i++){
        int p;
        cin>>p;
        int temp=node.LL_del(p);
        if(temp==error) cout<<"error"<<endl;
        else
            node.LL_display();
    }
    for(int i=0;i<2;i++){
        int p;
        cin>>p;
        int temp=node.LL_get(p);
        if(temp==error) cout<<"error"<<endl;
        else
            cout<<temp<<endl;
    }
    return 0;
}
/*
 * 第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置
 */