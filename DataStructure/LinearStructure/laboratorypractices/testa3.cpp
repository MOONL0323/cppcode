#include<iostream>
#include<deque>
using namespace std;
deque<int> q;
int main(){
    int n;
    int num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        q.push_back(num);
    }
    for(int i=0;i<q.size();i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
    
    int j=2;
    while(j--){
        int t,p;
        cin>>t>>p;
        if(t==0){
        while(p--){
            q.push_back(q.front());
            q.pop_front();
        }
        }else if(t==1){
            while(p--){
                q.push_front(q.back());
                q.pop_back();
            }
        for(int i=0;i<q.size();i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
        }
    }
    
    return 0;
}