#include <iostream>
using namespace std;
int main()
{
	int x;
	cin >> x;
	int* p = new int[x];
	for (int i = 0; i < x; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < x; i++) {
		cout << p[i];
	}
}

