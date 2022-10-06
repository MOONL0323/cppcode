#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
stack<int>s;
int main(){
    string str;
    int flag=1;
    cin>>str;
    int now=0;
    int len=str.length();
    for(int i=0;i<len;i++){
        if(str[i]=='.'){
            s.push(now);
            now=0;
            continue;
        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            int u1=s.top();
            s.pop();
            int u2=s.top();
            s.pop();
            int temp;
            if(str[i]=='+'){
                temp=u2+u1;
            }
            if(str[i]=='-'){
                temp=u2-u1;
            }
            if(str[i]=='*'){
                temp=u2*u1;
            }
            if(str[i]=='/'){
                temp=u2/u1;
            }
            s.push(temp);
        }
        else if(str[i]=='@') break;
        else{
            now*=10;
            now+=str[i]-'0';
        }
    }
    cout<<s.top()<<endl;
    return 0;
}