#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;

int main(){
    int n,m;
    int nums;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nums;
        v.push_back(nums);
    }
    for(int i=0;i<m;i++){
        cin>>nums;
        cout<<v[nums-1]<<endl;
    }

    return 0;
}