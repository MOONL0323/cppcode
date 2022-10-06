#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a[2][3];
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=2;i>=0;i--){
            for(int j=0;j<2;j++){
                cout<<*(*(a+j)+i)<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}