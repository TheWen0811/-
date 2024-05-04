#include <iostream>
using namespace std;
int main() {
	cout << "如果你要选择您恋人的性别，您的选择是：" << endl;
	cout << "A:男生" << endl;
	cout << "B:女生";
	char a;
	cin >> a;
	if (a == 'A') {
		cout << "您喜欢男生";

	}
	if (a == 'B') {
		cout << "您喜欢女生";
	}
}