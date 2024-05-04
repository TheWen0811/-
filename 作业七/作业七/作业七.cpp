using namespace std;
#include <iostream>
void quick_sort(int arr[], int begin, int end) {
	if (begin > end)
		return;
	int tmp = arr[begin];
	int i = begin;
	int j = end;
	while (i != j) {
		while (arr[j] >= tmp && j > i)
			j--;
		while (arr[i] <= tmp && j > i)
			i++;
		if (j > i) {
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	arr[begin] = arr[i];
	arr[i] = tmp;
	quick_sort(arr, begin, i - 1);
	quick_sort(arr, i + 1, end);
}

int main()
{
	int x1;
	cout << "请输入第一个数组的元素个数";
	cin >> x1;
	int* p1 = new int[x1];
	for (int i = 0; i < x1; i++) {
		cout << "请输入第" << i + 1 << "个元素";
		cin >> p1[i];
	}
	quick_sort(p1, 0, x1 - 1);
	cout << "第一次排序的结果:";
	for (int i = 0; i < x1 ; i++) {
		cout << p1[i]<<' ';
		}
	cout << endl;
	int x2;
	cout << "请输入第二个数组的元素个数";
	cin >> x2;
	int* p2 = new int[x2];
	for (int i = 0; i < x2; i++) {
		cout << "请输入第" << i + 1 << "个元素";
		cin >> p2[i];
	}
	quick_sort(p2, 0, x2 - 1);
	cout << "第一次排序的结果:";
	for (int i = 0; i < x2; i++) {
		cout << p2[i] << ' ';
	}
	cout << endl;
	int x3;
	int* p3 = new int[x1 + x2];
	for (int i = 0; i < x1 + x2; i++) {
		if (i < x1) {
			p3[i] = p1[i];
		}
		else if (i >= x1 && i < x1 + x2) {
			p3[i] = p2[i - x1];
		}
	}
	for (int i = 0; i < x1 + x2; i++) {
		cout << p3[i] << ' ';
	}

}

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
    node* locate(T x) {
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
    void sort_list(node* head);
    void add(list &p);
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
    node* p, * q;
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
template <class T>
void list<T>::add(list& b) {
    {
        node* p = head->next;
        while (p != NULL && p->next != NULL) {
            p = p->next;
        }
        if (p == NULL) {
            return;
        }
        p->next = b.head->next;
        count += b.count;
    }
}

int main() {
    list<int> a;
    list<int> b;
    cout << "请输入第一个链表的元素";
    for (int i = 0; i < 5; i++) {
        cout << "请输入第" << i + 1 << "个数";
        int n = 0;
        cin >> n;
        a.insert(a.length() + 1, n);
    }
    cout << "第一次排序:";
    a.sort_list(a.get_head());
    for (int i = 1; i < a.length() + 1; i++) {
        int x = 0;
        a.get_element(i, x);
        cout << x << " ";
    }cout << endl;
    cout << "请输入第二个链表的元素";
    for (int i = 0; i < 5; i++) {
        cout << "请输入第" << i + 1 << "个数";
        int n = 0;
        cin >> n;
        b.insert(b.length() + 1, n);
    }
    cout << "第二次排序:";
    b.sort_list(b.get_head());
    for (int i = 1; i < b.length() + 1; i++) {
        int x = 0;
        b.get_element(i, x);
        cout << x << " ";
    }cout << endl;
    a. add(b);
    a.sort_list(a.get_head());

    for (int i = 1; i < a.length() + 1; i++) {
        int x = 0;
        a.get_element(i, x);
        cout << x << " ";
    }

}



