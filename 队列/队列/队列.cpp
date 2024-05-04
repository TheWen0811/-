
	
#include <iostream>
using namespace std;
const int maxlen = 100;
struct node {
	int data;
	node* next;
};
class queue {
private:
	int count;
	node* front, *rear;
public:
	queue();
	bool empty();
	bool full();
	bool get_front(int& x);
	bool append(const int n);
	bool serve();
};
queue::queue() {
	front = new node;
	rear = front;
	front->next = NULL;
	count = 0;
}
bool queue::empty() {
	return count == 0;
}
bool queue::full() {
	return count == maxlen - 1;
}
bool queue::get_front(int& x) {
	if (empty()) return false;
	x = front->next->data;
	return true;
}
bool queue::append(const int n) {
	if (full()) return false;
	node *s = new node;
	s->data = n;
	s->next = NULL;
	rear->next = s;
	rear = s;
	count++;
	return true;
}
bool queue::serve() {
	if (empty()) return false;
	node* u;
	u = front->next;
	front->next = u->next;
	if (rear == u) rear = front;
	delete u;
	count--;
	return true;
}
void out_number(int n) {
	int s1, s2;
	queue qu;
	qu.append(1);
	for (int i = 1; i <= n; i++) {
		s1 = 0;
		for (int j = 0; j < i; j++) {
			int x = 0;
			qu.get_front(x);
			cout << x << " ";
			qu.append(s1 + x);
			s1 = x;
			qu.serve();
		}
		qu.append(1);
		cout << endl;
	}
}

	int main() {
		int n;
		cout << "请输入需要输出的行数: ";
		cin >> n;
		out_number(n);
		return 0;
	}