#include <iostream>
#include <string>
using namespace std;
class information {
public :
	information() {//用构造函数进行初始化
		cout << "******欢迎进入课程考试系统******" << endl;
		year = 0;
		month = 0;
		day = 0;
	}
	void setsubject() {//设置科目名称
		string setsubject;
		cout << "输入考试科目:";
		cin >> setsubject;
		subject = setsubject;
	}
	void getsubject() {//输出科目名称
		cout << "该次考试的科目为" << subject << endl;
	}
	void settime(int setyear, int setmonth, int setday) {//设置考试时间
		year = setyear;
		month = setmonth;
		day = setday;
	}
	void gettime() {//输出考试时间
		cout << "考试时间为" << year << "年" << month << "月" << day << "日" << endl;
	}
	void setclassnu() {//设置班号
		string  a;
		cout << "输入班号:";
		cin >> a;
		classnum = a;
	}
	void getclassnu() {//输出班号
		cout << "班号为" << classnum << endl;
	}
	~information() {
		cout << "按任意键可退出，欢迎再次使用该系统";
		}
private:
	int year, month, day; string subject; string classnum;
};
class students {
public:
	string name;
	char number[30];
	int gread;
	int sum = 0;
};
int main() {
	information in;
	in.setsubject();
	int year, month, day;
	cout << "请依次输入考试日期的年月日：";
	cin >> year >> month >> day;
	in.settime(year, month, day);
	in.setclassnu();
	double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	double A, B, C, D, E, F;
	cout << "输入考试人数:";
	int n;
	cin >> n;
	students *st=new students[n];
	int m;
	cout << "请输入总题号:";
	cin >> m;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "名同学的信息:" << endl;
		cout << "输入姓名："; cin >> st[i].name; 
		cout << "输入学号："; cin >> st[i].number; 
		for (int j = 0; j < m; j++) {
			cout << "请输入第" << j + 1 << "道题的成绩:";
			cin >> st[i].gread;
			st[i].sum += st[i].gread;
		}
	}
	in.gettime();
	in.getsubject();
	in.getclassnu();
	for (int i = 0; i < n; i++) {
		if (st[i].sum > 0 && st[i].sum <= 49)a++;
		if (st[i].sum > 49 && st[i].sum <= 59)b++;
		if (st[i].sum > 59 && st[i].sum <= 69)c++;
		if (st[i].sum > 69 && st[i].sum <= 79)d++;
		if (st[i].sum > 79 && st[i].sum <= 89)e++;
		if (st[i].sum > 89 && st[i].sum <= 100)f++;
	}
	A = a / n * 100;
	B = b / n * 100;
	C = c / n * 100;
	D = d / n * 100;
	E = e / n * 100;
	F = f / n * 100;
	cout << "0-49分的人有" << a << "人" << "占总人数的" << A << "%" << endl;
	cout << "50-59分的人有" << b << "人" << "占总人数的" << B << "%" << endl;
	cout << "60-69分的人有" << c << "人" << "占总人数的" << C << "%" << endl;
	cout << "70-79分的人有" << d << "人" << "占总人数的" << D << "%" << endl;
	cout << "80-89分的人有" << e << "人" << "占总人数的" << E << "%" << endl;
	cout << "90-100分的人有" << f << "人" << "占总人数的" << F << "%" << endl;

}