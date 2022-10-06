#include<iostream>
#include<vector>
#include<cstring>
#define ok 0
#define error -1
struct stack{//单向数组栈
    int size;//记录栈的长度大小
    int cap=10;//记录容量
    int* p;//数组
    int t;//记录指针位置
};
typedef struct stack* Stack;
bool init_stack(Stack s){//初始化栈
    s->p=new int[s->cap];
    if(s->p==NULL) return false;
    s->size=0;
    s->t=0;
    return true;
}
int insert_stack(Stack s,int ele){
    if(s->size==s->cap){
        int* renew=new int[s->cap+1];
        if(renew==NULL) return error;
        memcpy(renew,s->p,sizeof(int)*s->cap);
        delete s->p;
        s->p=renew;
    }
    s->p[s->t]=ele;
    s->t++;
    s->size++;
    return ok;
}
void print_stack(Stack s){
    int len=s->size;
    std::cout<<"[";
    for(int i=len-1;i>=0;--i){
        std::cout<<s->p[i]<<" ";
    }
    std::cout<<"]\n";
}

int main(){
    stack s;
    init_stack(&s);
    int num;
    for(int i=0;i<5;i++){
        std::cin>>num;
        insert_stack(&s,num);
    }
    print_stack(&s);
    return 0;
}