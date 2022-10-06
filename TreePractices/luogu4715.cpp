#include<iostream>
using namespace std;
int n;
int a[999999];
int f(int l,int r){
    if(l==r) return l;
    int mid=(l+r)/2;
    int ll=f(l,mid);
    int rr=f(mid+1,r);
    if(l!=1||r!=(1<<n)){
        if(a[ll]>a[rr]) return ll;
        else return rr;
    }
    if(a[ll]>a[rr]) return rr;
    else return ll;
}
int main(){
    cin>>n;
    for(int i=1;i<=(1<<n);i++){
        cin>>a[i];
    }
    cout<<f(1,(1<<n));
    return 0;
}