#include <iostream>
using namespace std;
template<class T>
class list {
public:
    struct node {
        T data;
        node* next;
    };
    list();
    int length();//求长度的函数
    bool get_element(int i, T& x);//按序号取元素
    node* locate( T x) {
        node* p = head->next;
        while (p != NULL) {
            if (p->data == x) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    };//搜索元素运算对应的函数
    bool insert(int i, T x);//插入元素运算对应的函数
    bool delete_element(int i);//删除元素运算对应的函数
    node* get_head() { return head; };//读取链表表头指针的函数
    void sort_list(node* head);//完成列表的合并
private:
    int count;
    node* head;
};

template<class T>
list<T>::list() {
    head = new node;
    head->next = NULL;
    count = 0;
}

template<class T>
int list<T>::length() {
    return count;
}

template<class T>
bool list<T>::get_element(int i, T& x) {
    node* p = head->next;
    int j = 1;
    while (p != NULL && j != i) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    x = p->data;
    return true;
}

template<class T>
bool list<T>::insert(int i, T x) {
    node* p = head;
    int j = 0;
    while (j != i - 1 && p != NULL) {
        p = p->next;
        j++;
    }
    if (i<1 || i>count + 1) {
        return false;
    }
    node* s = new node;
    s->data = x;
    s->next = p->next;
    p->next = s;
    count++;
    return true;
}

template<class T>
bool list<T>::delete_element(int i) {
    node* p = head;
    int j = 0;
    while (j != i - 1 && p->next != NULL) {
        p = p->next;
        j++;
    }
    if (i<1 || i>count) {
        return false;
    }
    node* u = p->next;
    p->next = u->next;
    delete u;
    count--;
    return true;
}
template<class T>
void list<T>::sort_list(node* head) {
    int i, j, t;
   node* p, *q;
   int len = count;
    for (i = 0, p = head->next; i < len - 1; i++, p = p->next) {
        for (j = i + 1, q = p->next; j < len; j++, q = q->next) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}

int main() {
    list<int> a;
    for (int i = 0; i < 5; i++) {
        cout << "请输入第" << i + 1 << "个数";
        int n = 0;
        cin >> n;
        a.insert(a.length() + 1, n);
    }
    a.sort_list(a.get_head());
        for(int i=1;i<a.length()+1;i++){
        int x = 0;
        a.get_element(i, x);
        cout << x << " ";
    }

}