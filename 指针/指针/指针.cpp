// 指针.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int* p;
	int a[] = { 1,3};
	p = a;
	cout << "*a:" << *a << endl;
	cout << "*a+1:" << *a + 1 << endl;
	cout <<" * (a + 1)" << *(a + 1) << endl;
	cout << "a:" << a << endl;
	cout << "a+1:" << a + 1 << endl;
	cout << "p:" << p << endl;;
	cout << "p+1:" << p + 1 << endl;
	cout << "*p:" << *p << endl;
	cout << "*p+1:" << *p + 1 << endl;
	cout << endl << endl;
	char* op;
	char string[] = { "ABCDE" };
	op = string;
	cout << "*string:" << *string << endl;
	cout << "*string+1:" <<*string + 1<< endl;
	cout << "*(string+1):" << *(string + 1) << endl;
	cout << "string:" << string << endl;
	cout << "string+1:" << string + 1 << endl;
	cout << "op:" << op << endl;;
	cout << "op+1:" << op + 1 << endl;
	cout << "*op:" << *op << endl;
	cout << "*op+1:" << *op + 1 << endl;
	cout << "*(op+1):" << *(op +1)<< endl;
}
