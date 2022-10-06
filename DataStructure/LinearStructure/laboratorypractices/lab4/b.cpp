#include<iostream>
using namespace std;
struct list {
    int e;
    list* next;
    int size;
};
typedef struct list* l;
void insert_list(l head,int e) {
    l node = head;
    while (node->next) {
        node = node->next;
    }
    l t = new struct list();
    t->e = e;
    node->next = t;
    t->next = NULL;
}
void solve_list(l head,int n) {
    l node=head,node2 = head;
    node = node->next;
    node2 = node2->next;
    while (node2&&node2->next) {
        int temp = node2->e;
        for(int i=0;i<n;i++){
            while (node&&node->next) {

                if (node->next->e == temp) {
                    node->next = node->next->next;
                    head->size--;
                }
                // l node3 = node;
                node = node->next;
//            if (node && node->e == temp) {
//                node3->next = node->next;
//                node = node->next;
//                head->size--;
//            }
            }
            node=node2;
        }

        if (node2->next != NULL) {
            node2 = node2->next;
            node = node2;
        }

    }
}
void print_list(l head,int n) {
    head = head->next;
    cout << n << ":";
    while (head) {
        cout <<" " << head->e;
        head = head->next;
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int num;
        cin >> n;
        list head;
        head.size = n;
        head.next = NULL;
        for (int i = 0; i < n; i++) {
            cin >> num;
            insert_list(&head, num);
        }
        head.size = n;
        solve_list(&head,n);
        print_list(&head,head.size);
    }

    return 0;
}