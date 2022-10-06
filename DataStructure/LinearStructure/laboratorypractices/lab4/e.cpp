#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> s;
stack<char> temp;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int len=str.length();
        for(int i=0;i<len;i++){
            if(str[i]=='#'){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(str[i]);
            } 
        }
        if(s.empty()){
            cout<<"NULL"<<endl;
        }else{
            while(!s.empty()){
                temp.push(s.top());
                s.pop();
            }
            while(!temp.empty()){
                cout<<temp.top();
                temp.pop();
            }
            cout<<endl;
        }
       
    }
    return 0;
}
// 使用C++的STL堆栈对象，编写程序实现行编辑功能。行编辑功能是：当输入#字符，则执行退格操作；如果无字符可退就不操作，不会报错
// 本程序默认不会显示#字符，所以连续输入多个#表示连续执行多次退格操作
// 每输入一行字符打回车则表示字符串结束
// 注意：必须使用堆栈实现，而且结果必须是正序输出
// 输入
// 第一行输入一个整数t，表示有t行字符串要输入
// 第二行起输入一行字符串，共输入t行
// 输出
// 每行输出最终处理后的结果，如果一行输入的字符串经过处理后没有字符输出，则直接输出NULL
// 4
// chinaa#
// sb#zb#u
// ##shen###zhen###
// chi##a#####

// china
// szu
// sz
// NULL