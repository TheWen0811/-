#include <iostream>
using namespace std;
const int maxlen = 100;
template <typename T>class stack {
private:
	int count; 
public:
	int data[maxlen];
	stack() {
		count = 0;
	}
	bool empty()const {
		if (count == 0)return true;
		return false;
	}
	bool full()const {
		if (count == maxlen)return true;
		return false;
	}
	bool get_top(T& x)const {
		if (empty())return 0;
		else {
			x = data[count - 1];
			return 1;
		}
	}
		bool push(const T x) {
			if (full())return 0;
			data[count] = x;
			count++;
		}
		bool pop() {
			if (empty()) return 0;
			count--;
			return 1;
		}
	};

	int main() {
		stack<int> s;
		int n, x;
		cin >> n;
		for (int i = 0; i < n; i++) {
			static int x = 1;
			s.push(x);
			s.full();
			x++;
		}
		while (s.empty() != true) {
			s.get_top(x);
			cout << x << ' ';
			s.pop();
		}
		;
	}