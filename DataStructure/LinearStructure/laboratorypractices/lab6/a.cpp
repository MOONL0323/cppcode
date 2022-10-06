#include<iostream>
#include<string>
using namespace std;
class myString{
private:
    string mainstr;
    int size;

    void GetNext(string p,int next[]){
        int len=p.length();
        int j=0,k=-1;
        next[j]=k;
        while(j<len){
            if(k==-1||p[j]==p[k]){
                j++;
                k++;
                next[j]=k;
            }
            else k=next[k];
        }
    }
    int KMPFind(string p,int pos,int next[]){
        int i=pos,j=0;
        int len1=mainstr.length();
        int len2=p.length();
        while(i<len1&&j<len2){
            if(j==-1||mainstr[i]==p[j]){
                i++;
                j++;
            }
            else j=next[j];
        }
        if(j==len2) return(i-j+1);
        else return 0;
    }

public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p,int pos);
};

myString::myString(){
    size=0;
    mainstr="";
}
myString::~myString(){
    size=0;
    mainstr="";
}

void myString::SetVal(string sp){
    mainstr="";
    mainstr.assign(sp);
    size=mainstr.length();
}

int myString::KMPFindSubstr(string p,int pos){
    int i;
    int L=p.length();
    int* next=new int[L];
    GetNext(p,next);
    for(i=0;i<L;i++){
        cout<<next[i]<<' ';
    }
    cout<<endl;
    int v=-1;
    v=KMPFind(p,pos,next);
    delete[] next;
    return v;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string mainstr;
        cin>>mainstr;
        myString str;
        str.SetVal(mainstr);
        string T;
        cin>>T;
        int v=str.KMPFindSubstr(T,0);
        cout<<v<<endl;
    }
    return 0;
}