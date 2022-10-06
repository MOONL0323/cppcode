#include<iostream>
using namespace std;
struct list{
    char e;
    list* next;
    int size;
};
typedef list* l;
void insert_list(l head,int k,char e){
    l node=head;
    while(k--){
        node=node->next;
    }
    l temp=new struct list();
    temp->e=e;
    temp->next=node->next;
    node->next=temp;
    head->size++;
}
void print_list(l node){
    l head=node;
    head=head->next;
    if(head==NULL){
        cout<<"-"<<endl;
        return;
    }
    while(head) {
        cout << head->e;
        head=head->next;
    }
    cout<<endl;
}
void solve_list(l head){
    l node1=head,node2=head;
    while(node1&&node1->next){
        char temp=node1->next->e;
        if(node1->next->next&&node1->next->next->next&&node1->next->next->e==temp&&node1->next->next->next->e==temp){
            l node3=node1->next->next->next;
            while(1){
                if(node3->next&&node3->next->e==temp) node3=node3->next;
                else break;
            }
            node1->next=node3->next;
            node1=head;
        }
        else node1=node1->next;
    }

}
int main(){
    string str;
    cin>>str;
    int len=str.length();
    list m;
    m.next=NULL;
    m.size=0;
    for(int i=0;i<len;i++){
        insert_list(&m,i,str[i]);
    }
    int n;
    cin>>n;
    char c;
    int p;
    for(int i=0;i<n;i++){
        cin>>p>>c;
        insert_list(&m,p,c);
        solve_list(&m);
        print_list(&m);
    }

    return 0;
}
//题目描述
//祖玛是一款曾经风靡全球的游戏，其玩法是：在一条轨道上初始排列着若干个彩色珠子，
// 其中任意三个相邻的珠子不会完全同色。此后，你可以发射珠子到轨道上并加入原有序列中。
// 一旦有三个或更多同色的珠子变成相邻，它们就会立即消失。这类消除现象可能会连锁式发生，
// 其间你将暂时不能发射珠子。
//给定轨道上初始的珠子序列，然后是玩家所做的一系列操作。你的任务是，
// 在各次操作之后及时计算出新的珠子序列。
//输入
//第一行是一个由大写字母'A'~'Z'组成的字符串，表示轨道上初始的珠子序列，
// 不同的字母表示不同的颜色。
//第二行是一个数字n，表示玩家共有n次操作。
//接下来的n行依次对应于各次操作。每次操作由一个数字k和一个大写字母描述，
// 以空格分隔。其中，大写字母为新珠子的颜色。若插入前共有m颗珠子，位置0至m-1，
// 则k ∈ [0, m]表示新珠子嵌入在轨道上的位置。
//输出
//输出共n行，依次给出各次操作（及可能随即发生的消除现象）之后轨道上的珠子序列。
//如果轨道上已没有珠子，则以“-”表示。
//ACCBA
//5
//1 B
//0 A
//2 B
//4 C
//0 A
//
//        ABCCBA
//AABCCBA
//        AABBCCBA
//-
//A