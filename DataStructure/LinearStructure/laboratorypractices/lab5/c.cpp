#include<iostream>
#include<queue>
using namespace std;
queue<int> q[99];
queue<int> p[99];
int main(){
    int t;
    int nums[12];
    cin>>t;
    int con=0;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        nums[i]=n;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            q[i].push(num);
        }
    }
    string op;
    int nums2[99];
    int flag2[99];
    for(int i=0;i<t;i++){
        flag2[i]=0;
    }
    int c=0;
    while(true) {
        cin >> op;
        if (op == "STOP") break;
        else if (op == "ENQUEUE") {
            int temp;
            cin >> temp;
            int tmp = 0;
            int s = 0;
            for (int i = 0; i < t; i++) {
                int ntemp = q[i].front();
                if (ntemp == temp) {
                    if (flag2[i] == 0) {
                        nums2[c++] = i;
                        flag2[i] = 1;
                    }
                    p[i].push(temp);
                    break;
                }
                q[i].push(ntemp);
                q[i].pop();
                while (q[i].front() != ntemp) {
                    int ntemp = q[i].front();
                    if (ntemp == temp) {
                        if (flag2[i] == 0) {
                            nums2[c++] = i;
                            flag2[i] = 1;
                        }
                        p[i].push(temp);
                        goto flag;
                    }
                    q[i].push(ntemp);
                    q[i].pop();
                }
                flag:int mm=0;
            }

        } else {
            for (int i = 0; i < t; i++) {
                if (p[nums2[i]].empty()) continue;
                else {
                    cout << p[nums2[i]].front() << " ";
                    p[nums2[i]].pop();
                    break;
                }
            }
        }
    }
    return 0;
}
// 组队列是队列结构中一种常见的队列结构，在很多地方有着广泛应用。组队列是是指队列内的元素分组聚集在一起。组队列包含两种命令：
// 1、 ENQUEUE，表示当有新的元素进入队列，首先会检索是否有同一组的元素已经存在，如果有，则新元素排在同组的最后，如果没有则插入队列末尾。
// 2、 DEQUEUE，表示队列头元素出队
// 3、 STOP，停止操作
// 建议使用C++自带的队列对象queue，编程更方便
// 输入
// 第1行输入一个t(t<=10)，表示1个队列中有多少个组
// 第2行输入一个第1组的元素个数和数值
// 第3行输入一个第2组的元素个数和数
// 以此类推输入完t组以定义同组元素之后，开始输入多个操作命令(<200)，对空的组队列进行操作，例如输入ENQUEUE 100，表示把元素100插入队列
// 输出
// DEQUEUE出队的元素
// 2
// 3 101 102 103
// 3 201 202 203
// ENQUEUE 101
// ENQUEUE 201
// ENQUEUE 102
// ENQUEUE 202
// ENQUEUE 103
// ENQUEUE 203
// DEQUEUE
// DEQUEUE
// DEQUEUE
// STOP

// 101 102 103
// 3 101 102 103
//  3 201 202 203
//  3 301 302 303

//  ENQUEUE 201  ==>>> | 201 |
//  ENQUEUE 301  ==>>> | 201 | 301 |
//  ENQUEUE 102  ==>>> | 201 | 301 | 102 |
//  ENQUEUE 101  ==>>> | 201 | 301 | 102 101 |
//  ENQUEUE 203  ==>>> | 201 203 | 301 | 102 101 |
//  ENQUEUE 302  ==>>> | 201 203 | 301 302 | 102 101 |



// 可以看到队列分组，先入队的组在队列中靠前，出队也靠前：

// DEQUEUE 输出 201，队列变为 | 203 | 301 302 | 102 101 | …