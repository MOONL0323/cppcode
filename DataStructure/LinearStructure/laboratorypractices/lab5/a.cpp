#include<iostream>
#include<stack>
#include <cstring>

using namespace std;
struct node{
    int x;
    int y;
};

int map[999][999];
bool book[999][999];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    int t;
    cin>>t;
    while(t--){
        stack<node> path;
        stack<node> path1;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                book[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>map[i][j];
            }
        }
        node a{};
        a.x=0;a.y=0;
        if(map[0][0]==1){
            goto flag;
        }
        path.push(a);

        book[0][0]=true;
        while(true){
            if(path.empty()) break;
            for(int i=0;i<4;i++){
                node temp=path.top();
                int x=temp.x;int y=temp.y;
                if(x==n-1&&y==n-1) goto flag;
                int ux=x+dx[i];
                int uy=y+dy[i];
                if(ux<0||ux>n-1||uy<0||uy>n-1||map[ux][uy]==1||book[ux][uy]==1) continue;
                else{
                    book[ux][uy]=true;
                    node tmp{};
                    tmp.x=ux;
                    tmp.y=uy;
                    path.push(tmp);
                    i=-1;
                    if(ux==n-1&&uy==n-1) goto flag;
                }
            }
            path.pop();
        }
        flag:
        while(!path.empty()) {
            path1.push(path.top());
            path.pop();
        }
            int i=0;
            int flag2=0;//以下是输出路径的代码
            while (!path1.empty()){
                flag2=1;
                node cpos = path1.top();
                if ( (++i)%4 == 0 )
                    cout<<'['<<cpos.x<<','<<cpos.y<<']'<<"--"<<endl;
                else
                    cout<<'['<<cpos.x<<','<<cpos.y<<']'<<"--";
                path1.pop();
            }
            if(flag2==1)
                cout<<"END"<<endl;
        if(flag2==0)
            cout<<"no path"<<endl; //找不到路径输出no path

    }
    return 0;
}
// 题目描述
// 给出一个N*N的迷宫矩阵示意图，从起点[0,0]出发，寻找路径到达终点[N-1, N-1]
// 要求使用堆栈对象来实现，具体算法参考课本3.2.4节51页
// 输入
// 第一行输入t，表示有t个迷宫
// 第二行输入n，表示第一个迷宫有n行n列
// 第三行起，输入迷宫每一行的每个方格的状态，0表示可通过，1表示不可通过
// 输入n行
// 以此类推输入下一个迷宫
// 输出
// 逐个输出迷宫的路径
// 如果迷宫不存在路径，则输出no path并回车
// 如果迷宫存在路径，将路径中每个方格的x和y坐标输出，从起点到终点，每输出四个方格就换行，最终以单词END结尾，具体格式参考示范数据
// 输出的代码参考如下：
// //path是保存路径的堆栈，堆栈中每个元素都包含x坐标和y坐标，用属性xp和yp表示
// //path1是一个临时堆栈，把path的数据倒序输出到path1，使得路径按正序输出
//  if (!path.empty()) //找到路径
//  { //......若干代码，实现path的数据导入path1
//  i=0;  //以下是输出路径的代码
//  while (!path1.empty())
//  { cpos = path1.top();
//  if ( (++i)%4 == 0 )
//  cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;
//  else
//  cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";
//  path1.pop();
//  }
//  cout<<"END"<<endl;
//  }
//  else
//  cout<<"no path"<<endl; //找不到路径输出no path

// 2
// 8
// 0 0 0 1 1 1 1 1
// 1 0 0 0 1 0 0 1
// 1 0 0 0 1 0 0 0
// 1 1 0 0 0 0 0 1
// 0 0 1 1 0 1 1 0
// 0 0 0 0 0 0 1 1
// 1 1 1 1 1 0 0 1
// 0 0 0 0 1 0 0 0
// 7
// 0 0 0 1 1 1 1
// 1 0 0 1 0 0 1
// 1 0 0 1 0 0 0
// 1 1 0 0 0 0 1
// 0 0 1 1 0 1 0
// 1 0 0 0 0 1 0
// 0 0 0 0 1 1 0

// [0,0]--[0,1]--[0,2]--[1,2]--
// [1,3]--[2,3]--[3,3]--[3,4]--
// [4,4]--[5,4]--[5,5]--[6,5]--
// [6,6]--[7,6]--[7,7]--END
// no path

// 按照课本的算法，向右，向下、向左、向上逆时针探索路径。


