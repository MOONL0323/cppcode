#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> >v;
int main(){
    int n,q;
    cin>>n>>q;
    int t,i,j,k;
    while(q--){
        cin>>t>>i>>j>>k;
        if(t==1){
            if(k==0){
                v[i][j]=-1;
            }
            else v[i][j]=k;
        }
        else{
            cout<<v[i][j]<<endl;
        }
    }
    return 0;
}