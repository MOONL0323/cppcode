#include<iostream>
using namespace std;
struct LinkList{
    int ele;
    int len;
    LinkList* next;
};
typedef LinkList* list;
void init_list(list head){
    head->next=NULL;
    head->len=0;
}
bool insert_list(list head,int i,int ele){
    if(i<1) return false;
    while(--i){
        head=head->next;
        if(head==NULL) return 0;
    }
    list node=new LinkList();
    node->ele=ele;
    node->next=head->next;
    head->next=node;
    head->len++;
    return true;
}
void print_list(list head){
    head=head->next;
    while(head){
        cout<<head->ele<<" ";
        head=head->next;
    }
    cout<<endl;
}
bool swap(list head,int pa, int pb){
    if(pa<1||pb<1) return false;
    list n1=head,n2=head;
    while(--pa){
        n1=n1->next;
        if(n2==NULL||n2->next==NULL) return false;


    }
    list t1=n1->next;
    while(--pb){
        n2=n2->next;
        if(n2==NULL||n2->next==NULL) return false;

    }
    list t2=n2->next;
    //list t3=t1->next;
    if(t2!=NULL){
        list t4=t2->next;
        n1->next=t2;
        t2->next=t1->next;
        n2->next=t1;
        t1->next=t4;
    }
    else{
        n1->next=t2;
        t2->next=t1->next;
        n2->next=t1;
        t1->next=NULL;
    }

    return true;

}

int main(){
    int n;
    int num;
    LinkList head;
    init_list(&head);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num;
        insert_list(&head,i,num);
    }
    print_list(&head);
    int pa,pb;
    for(int i=0;i<2;i++){
        cin>>pa>>pb;
        int temp=swap(&head,pa,pb);
        if(temp==false) cout<<"error"<<endl;
        else print_list(&head);
    }
    return 0;
}