#include<iostream>
using namespace std;

#define  ok 0
#define  error -1

class SeqList {
private:
    int* list;
    int maxsize;
    int size;
public:
    SeqList();
    ~SeqList();
    void list_init(int* p, int i) {
        list = p;
        size = i;
    }
    int list_size() {
        return size;
    }
    int list_insert(int i, int item) {
        if (i<1 || i>size+1) return error;
        for (int j = size; j >= i - 1; j--) {
            list[j + 1] = list[j];
        }
        list[i - 1] = item;
        size++;
        return ok;
    }
    int list_del(int i) {
        if (i<1 || i>size) return error;
        for (int j = i; j < size; j++) {
            list[j - 1] = list[j];
        }
        size--;
        return ok;
    }
    int list_get(int i) {
        if (i<1 || i>size) return error;
        return list[i - 1];
    }
    void list_display() {
        cout << size << " ";
        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
    void multiinsert(int i,int n,int item[]){
        int t=0;
        for(int j=i;j<n+i;j++){
            list_insert(j,item[t]);
            t++;
        }
    }
    void multide(int i,int n){
        while(n--){
            list_del(i);
        }
    }
};

SeqList::SeqList() {
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}
SeqList::~SeqList() {
    delete[] list;
}
int main() {
    int n;
    cin>>n;
    int* p=new int[1000];
    for(int j=0;j<n;j++)
        cin>>p[j];
    SeqList a;
    a.list_init(p,n);
    a.list_display();
    int i;
    cin>>i;
    int k;
    cin>>k;
    int* item=new int[k];
    for(int j=0;j<k;j++)
        cin>>item[j];
    a.multiinsert(i,k,item);
    a.list_display();
    int i2,k2;
    cin>>i2;
    cin>>k2;
    a.multide(i2,k2);
    a.list_display();
    return 0;
}