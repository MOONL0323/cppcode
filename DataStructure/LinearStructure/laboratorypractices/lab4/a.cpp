#include<iostream>
using namespace std;
struct list{
    int e;
    list* next;
    int size;
};
int n;
typedef struct list* l;
void insert_list(l head,int n){
    l node=head;
//    while(node->next!=head){
//        node=node->next;
//    }
    for(int i=2;i<=n;i++) {
        l temp = new struct list();
        temp->e = i;
        node->next = temp;
        node=node->next;
    }
    node->next=head;
}
void print_list(l head){
    l node=head;
    do{
        cout<<node->e<<endl;
        node=node->next;
    }while(node!=head);
}
void solve_list(l node,int k,int s){
    l head=node;
    while(--s){
        head=head->next;
    }
    while(1){
        int tmp=k-1;
        while(--tmp){
            head=head->next;
        }
        cout<<head->next->e<<" ";
        head->next=head->next->next;
        head=head->next;
        node->size--;
        if(node->size==1) break;
    }
    cout<<head->e<<endl;
}
int main(){
    int n,k,s;
    while(cin>>n>>k>>s){
        int temp;
        list head;
        head.next=&head;
        head.e=1;
        head.size=n;
        insert_list(&head,n);
        solve_list(&head,k,s);
    }

    return 0;
}
// N个人坐成一个圆环（编号为1 - N），从第S个人开始报数，数到K的人出列，后面的人重新从1开始报数。问最后剩下的人的编号。
// 例如：N = 3，K = 2，S = 1。2号先出列，然后是1号，最后剩下的是3号。
// 要求使用循环链表实现。
// 输入
// 测试数据有多组
// 每组包括3个数N、K、S，表示有N个人，从第S个人开始，数到K出列。(1 <= N <= 10^6，1 <= K <= 10,  1 <= S <= N)
// 输出
// 出列的人的编号