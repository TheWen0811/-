#include <iostream>
#include<stack>
using namespace std;
void f(int n) {
	stack<int> s;
LO:
	if (n > 0) {
		s.push(1);
		s.push(1);
		for (int i = 3; i <= n; i++) {
				int x1 = s.top();
				 s.pop();
				 int x2 = s.top();
				 s.pop();
				cout <<"取出的第一个栈顶元素是"<< x1 << " " << "取出的第二个栈顶元素是"<<x2 << " ";
				s.push(x1);//将第1个栈顶元素放入
				int x3 = x1 + x2;
				s.push(x3);
				cout <<"最终结果为"<< s.top() << " " << endl;
		}
	}
}
int main() {
	int n;
	cin >> n;
	f(n);
}
