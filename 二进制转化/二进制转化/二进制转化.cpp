#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
using namespace std;

int main()
{
	string s = "10000001";
	bitset<8> bs(s);
	cout << bs;
	ofstream f("E:\\360MoveData\\Users\\DELL\\Desktop\\text2.1");
	f<< bs;
	f.close();
}