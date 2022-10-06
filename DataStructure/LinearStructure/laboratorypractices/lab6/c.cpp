#include<iostream>
#include<algorithm>
using namespace std;
int compare_num(string a,string b){
    int len1=a.length();
    int len2=b.length();
    int len=min(len1,len2);
    int m=0;
    for(int i=0;i<len;i++){
        if(a[i]==b[i]) m++;
        else break;
    }
    return m;
}
int solve(string str){
    int len=str.length();
    string* s=new string[len];
    for(int i=0;i<len;i++){
        s[i]=str.substr(i,len);
    }
    sort(s,s+len);
    int maxn=0;
    for(int i=0;i<len-1;i++){
        int v=compare_num(s[i],s[i+1]);
        if(v>maxn){
            maxn=v;
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
        char temp=str[0];
        int m=0;
        for(int i=0;i<len;i++){
            if(str[i]==temp) m++;
        }
        if(m==len){
            cout<<len/2<<endl;
            continue;
        }
        int v= solve(str);
        if(v==0) cout<<"-1"<<endl;
        else cout<<v<<endl;
    }
    return 0;
}