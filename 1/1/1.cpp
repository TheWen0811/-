#include<iostream>
#define MAX 10
#include<iomanip>
#include <fstream>
using namespace std;
int n, m, w;
class gamescore
{
public:
	int academynum;//院系编号
	int score[MAX][MAX];//记录成绩的2维数组
	int totalscore[MAX];//院总分存储数组
	int mentotalscore[MAX];//男团总分存储数组
	int womentotalscore[MAX];//女团总分存储数组
	int projectnum; //项目编号
	gamescore()
	{
		academynum = 0;
		projectnum = 0;
	}
	void search(int academynum, int projectnum);
	void remove(int academynum, int projectnum);
	void repair(int academynum, int projectnum);
	void save();//保存成绩
	void input();
	void sort1();//按院总分排序
	void sort2();//按男团总分排序
	void sort3();//按女团总分排序
	void hold();//存储总分数
	int academytotalscore(int academynum);//院总分
	int academywomentotalscore(int academynum);//院女团总分
	int academymentotalscore(int academynum);//院男团总分
	void output1(int academy);//输出院系的成绩列表	
	void output2(int academynum);//输出院系的团体成绩列表
};
void gamescore::input()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << "输入编号为" << i + 1 << "院系的成绩(每项目取前三名，分别为10，5，2分,其余记成绩为0)" << endl;
		for (j = 0; j < m + w; j++)
		{
			cout << "输入编号为" << i + 1 << "院系的的运动项目编号为" << j + 1 << "的成绩:";
			cin >> score[i][j];
			if (score[i][j] != 0 && score[i][j] != 2 && score[i][j] != 5 && score[i][j] != 10)
			{
				cout << "成绩输入错误，请检查后再输入" << endl;
				cin >> score[i][j];
			}
		}
	}
	if (i = n - 1) cout << "!!输入完毕" << '/n';
}
void gamescore::save()
{
	std::ofstream ofs("运动会成绩.txt");
	ofs << "将最终学院参加的对应项目成绩列表列出(行表示学院编号，列表示项目编号)" <<'/n';

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m + w; j++)
		{
			ofs << score[i][j] << std::setw(5);
		}
		ofs << '/n';
	}
	for (int i = 1; i <= n; i++)
	{
		ofs << "编号为" << i << "的学院总分的成绩为:" << academytotalscore(i) << '/n';
		ofs << "编号为" << i << "的学院男团的成绩为:" << academymentotalscore(i) << '/n';
		ofs << "编号为" << i << "的学院女团的成绩为:" << academywomentotalscore(i) <<'/n';
	}

	ofs.close();
}
int gamescore::academytotalscore(int academynum)//院总分
{
	int sum = score[academynum - 1][0];
	for (int i = 1; i < m + w; i++)
	{

		sum = sum + score[academynum - 1][i];
	}
	return sum;
}
int gamescore::academywomentotalscore(int academynum)//院女团总分
{
	int sum = score[academynum - 1][m];
	for (int i = m + 1; i < m + w; i++)
	{
		sum = sum + score[academynum - 1][i];
	}
	return sum;
}
int gamescore::academymentotalscore(int academynum)//院男团总分
{
	int sum = score[academynum - 1][0];
	for (int i = 1; i < m; i++)
	{

		sum = sum + score[academynum - 1][i];
	}
	return sum;
}

void gamescore::hold()//存储总分
{
	for (int i = 1; i <= n; i++)
	{
		totalscore[i - 1] = academytotalscore(i);
		mentotalscore[i - 1] = academymentotalscore(i);
		womentotalscore[i - 1] = academywomentotalscore(i);
	}
}
void gamescore::sort1()//按院系总分排序
{
	int p, q;
	int a[MAX];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i <= n - 1 - j; i++)
		{
			if (totalscore[i] < totalscore[i + 1])
			{
				p = totalscore[i];
				totalscore[i] = totalscore[i + 1];
				totalscore[i + 1] = p;
				q = a[i];
				a[i] = a[i + 1];
				a[i + 1] = q;
			}
		}
	}
	cout << "按院系总分从大到小排序，以及对应的院系编号为：" <<'/n';
	for (int j = 0; j < n; j++)
	{
		cout << a[j] <<std::setw(5);
	}
	cout <<'/n';
	for (int j = 0; j < n; j++)
	{
		cout << totalscore[j] <<std:: setw(5);
	}
	cout << '/n';
}
void gamescore::sort2()//按男团总分排序
{
	int p, q;
	int a[MAX];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i <= n - 1 - j; i++)
		{
			if (mentotalscore[i] < mentotalscore[i + 1])
			{
				p = mentotalscore[i];
				mentotalscore[i] = mentotalscore[i + 1];
				mentotalscore[i + 1] = p;
				q = a[i];
				a[i] = a[i + 1];
				a[i + 1] = q;
			}
		}
	}
	cout << "按男团总分从大到小排序，以及对应的院系编号为：" << endl;
	for (int j = 0; j < n; j++)
	{
		cout << a[j] <<std:: setw(5);
	}
	cout << endl;
	for (int j= 0; j < n; j++)
	{
		cout << mentotalscore[j] <<std:: setw(5);
	}
	cout << endl;
}
void gamescore::sort3()//按女团总分排序
{
	int p, q;
	int a[MAX];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i <= n - 1 - j; i++)
		{
			if (womentotalscore[i] < womentotalscore[i + 1])
			{
				p = womentotalscore[i];
				womentotalscore[i] = womentotalscore[i + 1];
				womentotalscore[i + 1] = p;
				q = a[i];
				a[i] = a[i + 1];
				a[i + 1] = q;
			}
		}
	}
	cout << "按女团总分从大到小排序，以及对应的院系编号为：" <<'/n';
	for (int j = 0; j < n; j++)
	{
		cout << a[j] <<std:: setw(5);
	}
	cout << '/n';
	for (int j = 0; j < n; j++)
	{
		cout << womentotalscore[j] <<std:: setw(5);
	}
	cout << '/n';
}

void gamescore::search(int academynum, int projectnum)
{
	int j;
	int k;
	do
	{
		cout << "1 查询该院该单项成绩的总分, 2 查询该院总分,,3 查询该院男团总分，4 查询该院女团总分,5 按项目编号查询，0 退出查询" << endl;
		cout << "请选择:";
		cin >> k;
		if (k < 0 || k>5)   //判断输入的操作编号是否在目录中，如果超出范围重新输入
		{
			cout << "输入有误，请重新输入要操作的项目编号";
			cin >> k;
		}
		switch (k)
		{
		case 1:
			cout << "编号为" << academynum << "的学院的第" << projectnum << "个项目的成绩为:";
			cout << score[academynum - 1][projectnum - 1] << endl; break;
		case 2:
			cout << "该院总分为：" << academytotalscore(academynum) << endl; break;
		case 3:
			cout << "该院男团总分为：" << academymentotalscore(academynum) << endl; break;
		case 4:
			cout << "该院女团总分：" << academywomentotalscore(academynum) << endl; break;
		case 5:
			cout << "不同院系对应的第" << projectnum << "个项目的成绩为:" << endl;
			for (j = 0; j < n; j++)
			{
				cout << 1 + j <<std:: setw(5);
			}
			cout << endl;
			for (j = 0; j < n; j++)
			{
				cout << score[j][projectnum - 1] << setw(5);
			}
			cout << endl;
			break;

		default: return;
		}

	} while (1);
}
void gamescore::repair(int academynum, int projectnum)
{
	cout << "请重新输入该项成绩:";
	cin >> score[academynum - 1][projectnum - 1];
	cout << "修改成功" <<'/n';
}
void gamescore::remove(int academynum, int projectnum)
{
	score[academynum - 1][projectnum - 1] = 0;
	cout << "!!删除成功" <<'/n';
}
void gamescore::output1(int academynum)
{
	//cout<<"该学院运动项目编号及对应的成绩如下："<<endl;
	for (int i = 0; i < m + w; i++)
	{
		cout << 1 + i <<std:: setw(5);
	}
	cout << '/n';
	for (int i = 0; i < m + w; i++)
	{
		cout << score[academynum - 1][i] <<std::setw(5);
	}
}
void gamescore::output2(int academynum)
{
	cout << "该院男团成绩为" << academymentotalscore(academynum) << '/n';
	cout << "该院女团成绩为" << academywomentotalscore(academynum) <<'/n';
}

void main()
{
	int projectnum;
	int academynum;
	gamescore a;
	int	num;
		std::cout << "****运动会成绩管理系统*********" <<std:: endl;
	std::cout <<std:: endl;
	std::cout << " 1  输入院系及其参加项目的成绩" << endl;
	std::cout << " 2  查询某个院系参加某个项目的成绩" << endl;
	cout << " 3  修改一个项目的成绩" << endl;
	cout << " 4  删除错误成绩的记录" << endl;
	cout << " 5  输出某个院系的得分表" << endl;
	cout << " 6  输出院系的团体得分表" << endl;
	cout << " 7  对成绩按院系进行排序" << endl;
	cout << " 8  对成绩按男团进行排序" << endl;
	cout << " 9  对成绩按女团进行排序" << endl;
	cout << " 10  保存成绩信息" << endl;
	cout << " 0  退出该程序" << endl << endl;

	cout << "输入参加院系数 n=";
	cin >> n;
	cout << "输入男子项目数 m=";
	cin >> m;
	cout << "输入女子项目数 w=";
	cin >> w;

	do {
		cout << "请选择要操作的菜单标号:";
		cin >> num;
		if (num > 10 || num < 0)
		{
			cout << "输入有误，请重新输入要操作的项目编号:";
			cin >> num;
		}
		switch (num)
		{
		case 1:
			a.input();
			break;
		case 2:
			cout << "输入要查找的院系:";
			cin >> academynum;
			cout << "输入要查询的运动项目编号:";
			cin >> projectnum;
			a.search(academynum, projectnum);
			break;
		case 3:
			cout << "输入要修改的院系编号";
			cin >> academynum;
			cout << "输入要修改的运动项目的编号:";
			cin >> projectnum;
			a.repair(academynum, projectnum);
			break;
		case 4:
			cout << "输入要删除成绩所在的院系的编号:";
			cin >> academynum;
			cout << "输入要删除运动项目编号:";
			cin >> projectnum;
			a.remove(academynum, projectnum);
			break;
		case 5:
			cout << "输入要查询成绩的院系编号:";
			cin >> academynum;
			a.output1(academynum);
			break;
		case 6:
			cout << "输入要查询团体成绩的院系的编号:";
			cin >> academynum;
			a.output2(academynum);
			break;
		case 7:
			cout << "该学院运动项目编号及对应学院总分的成绩如下:";
			a.hold();
			a.sort1(); break;
		case 8:
			cout << "该学院运动项目编号及对应男团的成绩如下:";
			a.hold();
			a.sort2(); break;
		case 9:
			cout << "该学院运动项目编号及对应女团的成绩如下:";
			a.hold();
			a.sort3(); break;
		case 10:
			a.save();
			cout << "!!保存成功" << endl; break;
		default: return;
		}
	} while (1);
}
