#include <iostream>
using namespace std;
class Tree {
public:
	int l_m = 3;
	int l_c = 3;
	int r_m = 3 - l_m ;
	int r_c = 3 - l_c;
	int b = 1;
	Tree* T_1;
	Tree* T_2;
	Tree* T_3;
	Tree* T_4;
	Tree* T_5;
	Tree* T_6;
	Tree* T_7;
	Tree* T_8;
	Tree* T_9;
	Tree* T_10;
};

void P01(Tree* T) {
	if ((T->b > 0 && T->b == 0) || (T->l_m > T->l_c && T->l_m = 0) || T->r_m > T->r_c && T->r_m = 0) {
		T->b = T->b - 1;
		T->l_c = T->l_c - 1;
	}
	else return;
}
int main() {
	cout << "hello";
}