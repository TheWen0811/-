#include <iostream>
#include<fstream>

int main()
{ 
std::ifstream fin;
std::ofstream fout;
fin.open("myFile,txt", std::ios::in);
fout.open("myFile,txt", std::ios::out);
if (!fout.is_open()||!fin.is_open()) {
	fout << "文件读写失败";
	return 0;
}
fout << "hello";
fout.close();
fin.close();
}

