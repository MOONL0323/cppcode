#include<iostream>
#include <algorithm>

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
        if (i<1 || i>size + 1) return error;
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
    void list_merge(SeqList* str) {
        int i = 0;
        while (str->size--) {
            list_insert(this->size + 1, str->list[i++]);
        }
        sort(this->list, this->list + this->size);
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
    int* num1 = new int[1000];
    for (int i = 0; i < n; i++)
        cin >> num1[i];
    int n2;
    cin >> n2;
    int* num2 = new int[1000];
    for (int i = 0; i < n2; i++) {
        cin >> num2[i];
    }
    SeqList a;
    SeqList b;
    a.list_init(num1, n);
    b.list_init(num2, n2);
    a.list_merge(&b);
    a.list_display();
    return 0;
}