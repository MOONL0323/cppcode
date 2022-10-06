#include<iostream>
using namespace std;
int GetNext(string p,int next[],int l){
    int maxn=-1;
    int len=p.length();
    int j=0,k=-1;
    next[j]=k;
    while(j<len){
        if(k==-1||p[j]==p[k]){
            j++;
            k++;
            next[j]=k;
        }
        else k=next[k];
    }
    for(int i=0;i<l;i++){
        if(next[l]>maxn){
            maxn=next[l];
        }
    }
    return maxn;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int len=str.length();
        int* next=new int[len];
        int v=GetNext(str,next,len);
        if(v==-1||v==0){
            cout<<"empty"<<endl;
        }
        else{
            for(int i=0;i<v;i++){
                cout<<str[i];
            }
            cout<<endl;
        }
        delete[] next;
    }
    return 0;
}
