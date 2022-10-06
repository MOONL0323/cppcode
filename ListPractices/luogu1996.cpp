#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int t=0;
    while(!q.empty()){
        t++;
        if(t==m){
            int temp=q.front();
            cout<<temp<<" ";
            q.pop();
            t=0;
        }else{
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}