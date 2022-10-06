#include<iostream>
using namespace std;

#define  ok 1000
#define  error -1000

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
    cin >> n;
    int* p = new int[1000];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    SeqList a;
    a.list_init(p, n);
    a.list_display();
    int in, ele;
    cin >> in >> ele;
    int temp = a.list_insert(in, ele);
    if (temp == ok)
        a.list_display();
    else
        cout << "error" << endl;
    int in2, ele2;
    cin >> in2 >> ele2;
    temp = a.list_insert(in2, ele2);
    if (temp == ok)
        a.list_display();
    else
        cout << "error" << endl;
    int del;
    cin >> del;
    temp = a.list_del(del);
    if (temp == ok)
        a.list_display();
    else
        cout << "error" << endl;
    cin >> del;
    temp = a.list_del(del);
    if (temp == ok)
        a.list_display();
    else
        cout << "error" << endl;
    int findele;
    cin >> findele;
    temp = a.list_get(findele);
    if (temp !=error)
        cout << temp;
    else
        cout << "error" << endl;
    cin >> findele;
    temp = a.list_get(findele);
    if (temp !=error)
        cout << temp;
    else
        cout << "error" << endl;
    return 0;
}