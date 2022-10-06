#include<iostream>
#include<stack>
#include<map>
#include<cmath>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

stack<char> opre;
stack<int> nums;

bool isbigcmp(char a, char b)
{
    if (a == '+' || a == '-')
    {
        if (b == '(' || b == '#'||b=='*'||b=='/')return false;
        return true;
    }
    else if (a == '*' || a == '/')
    {
        if (b == '(')return false;
        return true;
    }
    else if (a == '(')
    {
        if (b == ')')return true;
        return false;
    }
    else if (a == ')')
    {
        return true;
    }
    else if (a == '#')
    {
        if(b=='#')
            return true;
        return false;
    }
}

bool isbigcmp2(char a, char b)
{
    if (a == '+' || a == '-')
    {
        if (b == '(' || b == '#' || b == '*' || b == '/'||b=='+'||b=='-')return false;
        return true;
    }
    else if (a == '*' || a == '/')
    {
        if (b == '(')return false;
        return true;
    }
    else if (a == '(')
    {
        //if (b == ')')return true;
        return false;
    }
    else if (a == ')')
    {
        return true;
    }
    else if (a == '#')
    {
        //if (b == '#')
        //	return true;
        return false;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string fn;
        cin >> fn;
        for (int i = fn.length() - 1; i >= 0; i--)
        {
            if ((fn[i] >= 'a' && fn[i] <= 'z') || (fn[i] >= 'A' && fn[i] <= 'Z') || (fn[i] >= '0' && fn[i] <= '9'))
            {
                int tot = fn[i]-'0';
                int x = 10;
                while (i - 1 >= 0 && isdigit(fn[i - 1]))
                {
                    tot += x * (fn[i - 1] - '0');
                    x *= 10;
                    i--;
                }
                nums.push(tot);
            }
            else
            {
                if (opre.empty() || opre.top() == ')' || fn[i] == ')')
                {
                    opre.push(fn[i]);
                }
                else if (fn[i] == '(')
                {
                    while (opre.top() != ')')
                    {
                        nums.push(opre.top()*1000000);
                        opre.pop();
                    }
                    //nums.push(opre.top());
                    opre.pop();
                }
                else if (isbigcmp(fn[i], opre.top()))
                {
                    opre.push(fn[i]);
                }
                else if (!isbigcmp(fn[i], opre.top()))
                {
                    while (opre.size() != 0 && !isbigcmp(fn[i], opre.top()))
                    {
                        nums.push(opre.top()*1000000);
                        opre.pop();
                    }
                    opre.push(fn[i]);
                }
            }
        }
        while (!opre.empty())
        {
            nums.push(opre.top() * 1000000);
            opre.pop();
        }
        int mm=0;
        while (!nums.empty())
        {

            int x = nums.top();
            if (x > 1000000)
            {
                x /= 1000000;
                if(mm==0){
                    cout << (char)x;
                    mm++;
                }

                else{
                    cout<<" "<<(char)x;
                    mm++;
                }


            }
            else
            {
                if(mm==0){
                    cout << nums.top();
                    mm++;
                }

                else{
                    cout<<" "<<nums.top();
                    mm++;
                }


            }
            nums.pop();
        }
        cout << endl;
        //-----------------------------------------------------------------------------
        int nn=0;
        for (int i = 0; i < fn.length(); i++)
        {
            if ((fn[i] >= 'a' && fn[i] <= 'z') || (fn[i] >= 'A' && fn[i] <= 'Z') || (fn[i] >= '0' && fn[i] <= '9'))
            {
                int tot = fn[i] - '0';
                while (i + 1 <fn.length() && isdigit(fn[i + 1]))
                {
                    tot = tot*10+ (fn[i + 1] - '0');
                    i++;
                }
                //nums.push(tot);
                if(nn==0){
                    cout << tot;
                    nn++;
                }

                else{
                    cout<<" "<<tot;
                    nn++;
                }


            }
            else
            {
                if (opre.empty() || opre.top() == '(' || fn[i] == '(')
                {
                    opre.push(fn[i]);
                }
                else if (fn[i] == ')')
                {
                    while (!opre.empty() && opre.top() != '(')
                    {
                        if(nn==0){
                            cout << opre.top();
                            nn++;
                        }
                        else{
                            cout<<" "<<opre.top();
                            nn++;
                        }
                        //nums.push(opre.top());

                        opre.pop();
                    }
                    //nums.push(opre.top());
                    opre.pop();
                }
                else if (isbigcmp2(fn[i], opre.top()))
                {
                    opre.push(fn[i]);
                }
                else if (!isbigcmp2(fn[i], opre.top()))
                {
                    while (!opre.empty() && !isbigcmp2(fn[i], opre.top())&&opre.top()!='(')
                    {
                        if(nn==0){
                            cout << opre.top();
                            nn++;
                        }
                        else{
                            cout<<" "<<opre.top();
                            nn++;
                        }
                        //nums.push(opre.top());

                        opre.pop();
                    }
                    opre.push(fn[i]);
                }
            }
        }
        //int nn=0;
        while (!opre.empty())
        {
            if(nn==0){
                cout << opre.top();
                nn++;
            }
            else{
                cout<<" "<<opre.top();
                nn++;
            }
            //nums.push(opre.top());

            opre.pop();
        }
        /*while (!nums.empty())
        {
            cout << (char)nums.top()<<" ";
            nums.pop();
        }*/
        cout << endl<<endl;
    }
    return 0;
}



