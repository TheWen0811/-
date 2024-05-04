#include<iostream>
#define max 100
#include<string>
#include<iomanip>
#include <fstream>
using namespace std;
int n, m, w, u, x = 1, y = 1;


class m_pro {
public:
	void getnum() {
		if (this->p_num > 6) {
			cout << "现在" << this->name << "有" << this->p_num << "个人\n" << "第一名得分为7，第二名得分为5，第三名得分为3，第四名得分为2，第五名得分为1\n";
		}
		if (this->p_num < 7 && this->p_num>0) {
			cout << "现在" << this->name << "有" << this->p_num << "个人\n" << "每项目取前三名，分别为10，5，2分,其余记成绩为0\n";
		}
		else {
			cout << "该项目无人参加\n";
		}
	}
	m_pro(string name, int p_num, int bianhao) {
		name = this->name;
		p_num = this->p_num;
		bianhao = this->bianhao;
	}
	string name;
	int p_num;
	int bianhao;
};
class w_pro {
public:
	void getnum() {
		if (this->p_num > 6) {
			cout << "现在" << this->name << "有" << this->p_num << "个人\n" << "第一名得分为7，第二名得分为5，第三名得分为3，第四名得分为2，第五名得分为1\n";
		}
		if (this->p_num < 7 && this->p_num>0) {
			cout << "现在" << this->name << "有" << this->p_num << "个人\n" << "每项目取前三名，分别为10，5，2分,其余记成绩为0\n";
		}
		else {
			cout << "该项目无人参加\n";
		}
	}
	w_pro(string name, int p_num, int bianhao) {
		name = this->name;
		p_num = this->p_num;
		bianhao = this->bianhao;
	}
	string name;
	int p_num;
	int bianhao;
};
class u_pro {
public:
	void getnum() {
		if (this->p_num > 6) {
			cout << "现在" << this->name << "有" << this->p_num << "个人\n" << "第一名得分为7，第二名得分为5，第三名得分为3，第四名得分为2，第五名得分为1\n";
		}
		if (this->p_num < 7 && this->p_num>0) {
			cout << "现在" << this->name << "有" << this->p_num << "个人\n" << "每项目取前三名，分别为10，5，2分,其余记成绩为0\n";
		}
		else {
			cout << "该项目无人参加\n";
		}
	}
	u_pro(string name, int p_num, int bianhao) {
		name = this->name;
		p_num = this->p_num;
		bianhao = this->bianhao;
	}
	string name;
	int p_num;
	int bianhao;
};
m_pro** p1 = new m_pro * [max];
w_pro** p2 = new w_pro * [max];
u_pro** p3 = new u_pro * [max];

class student {
public:
	student() {
		s_p1 = NULL;
		s_p2 = NULL;
		s_p3 = NULL;
		s_bianhao = 0;
		s_a_score = 0;
		s_m_score = 0;
		s_w_score = 0;
		s_u_score = 0;
	}

	m_pro** s_p1;
	w_pro** s_p2;
	u_pro** s_p3;
	int s_bianhao;
	int s_a_score;
	int s_m_score;
	int s_w_score;
	int s_u_score;
};
class school {
public:
	school() {
		u_score = 0;
		a_score = 0;
		m_score = 0;
		w_score = 0;
		p_num = 0;
		p1_num = 0;
		p2_num = 0;
		p3_num = 0;
		st = NULL;
	}
	void apply();

	m_pro** s_p1;
	w_pro** s_p2;
	u_pro** s_p3;
	student** st;
	int a_score;
	int m_score;
	int w_score;
	int u_score;
	int p_num;
	int p1_num;
	int p2_num;
	int p3_num;
	int bianhao;
};

class all :public school {
public:
	all() {
		school sc[100];
		for (int i = 0; i < n; i++) {
			sc[i].bianhao = i + 1;
		}
	}
	school* sc;
	void s_find();//查询学校信息
	void registe();//登记成绩
	void sc_find();//成绩查询
	void m_sort();//男子排序
	void w_sort();//女子排序
	void u_sort();//全体排序
	void jianlu();//检录
};

void start() {
	cout << "请输入学校个数:\n";
	cin >> n;
	cout << "请输入男子比赛个数:\n";
	cin >> m;
	cout << "请输入女子比赛个数:\n";
	cin >> w;
	cout << "请输入团体比赛个数:\n";
	cin >> u;

	for (int i = 0; i < m; i++) {
		string name1;
		cout << "请输入第" << i + 1 << "个男子比赛" << "的名字:\n";
		cin >> name1;
		p1[i] = new m_pro(name1, 0, i + 1);

	}
	for (int i = 0; i < w; i++) {
		string name1;
		cout << "请输入第" << i + 1 << "女子比赛" << "的名字:\n";
		cin >> name1;
		p2[i] = new w_pro(name1, 0, i + 1);

	}
	for (int i = 0; i < u; i++) {
		string name1;
		cout << "请输入第" << i + 1 << "团体比赛" << "的名字:\n";
		cin >> name1;
		p3[i] = new u_pro(name1, 0, i + 1);
	}

}
void all::s_find() {
	for (int i = 0; i < n; i++) {
		cout << "编号为" << this->sc[i].bianhao << "的学校:\n男子项目:\n";
		for (int j = 0; j < sizeof(this->sc[i].s_p1) / sizeof(this->sc[i].s_p1[0]); j++) {
			cout << ((*(this->sc + i)->s_p1) + j)->name << "  " << this->sc[i].p1_num << "人\n";
		}
		cout << "女子项目\n";
		for (int j = 0; j < sizeof(this->sc[i].s_p2) / sizeof(this->sc[i].s_p2[0]); j++) {
			cout << ((*(this->sc + i)->s_p2) + j)->name << "  " << this->sc[i].p2_num << "人";
		}
		for (int j = 0; j < sizeof(this->sc[i].s_p3) / sizeof(this->sc[i].s_p3[0]); j++) {
			cout << ((*(this->sc + i)->s_p3) + j)->name << "  " << this->sc[i].p3_num << "人";
		}
	}
}
void all::jianlu() {



}
void all::registe() {
	cout << "男子比赛\n";
	for (int i = 0; i < m; i++) {
		cout << p1[i]->name << endl;
		if (p1[i]->p_num > 6) {
			cout << "请问第一名是哪个人(选择编号)\n";
			int a;
			cin >> a;
			cout << "请问第二名是哪个人(选择编号)\n";
			int b;
			cin >> b;
			cout << "请问第三名是哪个人(选择编号)\n";
			int c;
			cin >> c;
			cout << "请问第四名是哪个人(选择编号)\n";
			int d;
			cin >> d;
			cout << "请问第五名是哪个人(选择编号)\n";
			int e;
			cin >> e;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < this->sc[i].p_num; j++) {
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == a) {
						(*(this->sc + i)->st + j)->s_m_score += 7;
						(*(this->sc + i)->st + j)->s_a_score += 7;
						this->sc[i].a_score += 7;
						this->sc[i].m_score += 7;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == b) {
						(*(this->sc + i)->st + j)->s_m_score += 5;
						(*(this->sc + i)->st + j)->s_a_score += 5;
						this->sc[i].a_score += 5;
						this->sc[i].m_score += 5;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == c) {
						(*(this->sc + i)->st + j)->s_m_score += 3;
						(*(this->sc + i)->st + j)->s_a_score += 3;
						this->sc[i].a_score += 3;
						this->sc[i].m_score += 3;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == d) {
						(*(this->sc + i)->st + j)->s_m_score += 2;
						(*(this->sc + i)->st + j)->s_a_score += 2;
						this->sc[i].a_score += 2;
						this->sc[i].m_score += 2;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == e) {
						(*(this->sc + i)->st + j)->s_m_score += 1;
						(*(this->sc + i)->st + j)->s_a_score += 1;
						this->sc[i].a_score += 1;
						this->sc[i].m_score += 1;
					}
				}
			}
		}
		if (p1[i]->p_num < 7) {
			cout << "请问第一名是哪个人(选择编号)\n";
			int a;
			cin >> a;
			cout << "请问第二名是哪个人(选择编号)\n";
			int b;
			cin >> b;
			cout << "请问第三名是哪个人(选择编号)\n";
			int c;
			cin >> c;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < this->sc[i].p_num; j++) {
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == a) {
						(*(this->sc + i)->st + j)->s_m_score += 5;
						(*(this->sc + i)->st + j)->s_a_score += 5;
						this->sc[i].a_score += 5;
						this->sc[i].m_score += 5;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == b) {
						(*(this->sc + i)->st + j)->s_m_score += 3;
						(*(this->sc + i)->st + j)->s_a_score += 3;
						this->sc[i].a_score += 3;
						this->sc[i].m_score += 3;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == c) {
						(*(this->sc + i)->st + j)->s_m_score += 2;
						(*(this->sc + i)->st + j)->s_a_score += 2;
						this->sc[i].a_score += 2;
						this->sc[i].m_score += 2;
					}
				}
			}
		}

	}
	cout << "女子比赛\n";
	for (int i = 0; i < w; i++) {
		cout << p2[i]->name << endl;
		if (p2[i]->p_num > 6) {
			cout << "请问第一名是哪个人(选择编号)\n";
			int a;
			cin >> a;
			cout << "请问第二名是哪个人(选择编号)\n";
			int b;
			cin >> b;
			cout << "请问第三名是哪个人(选择编号)\n";
			int c;
			cin >> c;
			cout << "请问第四名是哪个人(选择编号)\n";
			int d;
			cin >> d;
			cout << "请问第五名是哪个人(选择编号)\n";
			int e;
			cin >> e;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < this->sc[i].p_num; j++) {
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == a) {
						(*(this->sc + i)->st + j)->s_m_score += 7;
						(*(this->sc + i)->st + j)->s_a_score += 7;
						this->sc[i].a_score += 7;
						this->sc[i].w_score += 7;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == b) {
						(*(this->sc + i)->st + j)->s_m_score += 5;
						(*(this->sc + i)->st + j)->s_a_score += 5;
						this->sc[i].a_score += 5;
						this->sc[i].w_score += 5;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == c) {
						(*(this->sc + i)->st + j)->s_m_score += 3;
						(*(this->sc + i)->st + j)->s_a_score += 3;
						this->sc[i].a_score += 3;
						this->sc[i].w_score += 3;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == d) {
						(*(this->sc + i)->st + j)->s_m_score += 2;
						(*(this->sc + i)->st + j)->s_a_score += 2;
						this->sc[i].a_score += 2;
						this->sc[i].w_score += 2;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == e) {
						(*(this->sc + i)->st + j)->s_m_score += 1;
						(*(this->sc + i)->st + j)->s_a_score += 1;
						this->sc[i].a_score += 1;
						this->sc[i].w_score += 1;
					}
				}
			}
		}
		if (p1[i]->p_num < 7) {
			cout << "请问第一名是哪个人(选择编号)\n";
			int a;
			cin >> a;
			cout << "请问第二名是哪个人(选择编号)\n";
			int b;
			cin >> b;
			cout << "请问第三名是哪个人(选择编号)\n";
			int c;
			cin >> c;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < this->sc[i].p_num; j++) {
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == a) {
						(*(this->sc + i)->st + j)->s_m_score += 5;
						(*(this->sc + i)->st + j)->s_a_score += 5;
						this->sc[i].a_score += 5;
						this->sc[i].w_score += 5;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == b) {
						(*(this->sc + i)->st + j)->s_m_score += 3;
						(*(this->sc + i)->st + j)->s_a_score += 3;
						this->sc[i].a_score += 3;
						this->sc[i].w_score += 3;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == c) {
						(*(this->sc + i)->st + j)->s_m_score += 2;
						(*(this->sc + i)->st + j)->s_a_score += 2;
						this->sc[i].a_score += 2;
						this->sc[i].w_score += 2;
					}
				}
			}
		}
	}
	cout << "团体比赛\n";
	for (int i = 0; i < u; i++) {
		cout << p3[i]->name << endl;
		if (p3[i]->p_num > 6) {
			cout << "请问第一名是哪个人(选择编号)\n";
			int a;
			cin >> a;
			cout << "请问第二名是哪个人(选择编号)\n";
			int b;
			cin >> b;
			cout << "请问第三名是哪个人(选择编号)\n";
			int c;
			cin >> c;
			cout << "请问第四名是哪个人(选择编号)\n";
			int d;
			cin >> d;
			cout << "请问第五名是哪个人(选择编号)\n";
			int e;
			cin >> e;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < this->sc[i].p_num; j++) {
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == a) {
						(*(this->sc + i)->st + j)->s_u_score += 14;
						(*(this->sc + i)->st + j)->s_a_score += 14;
						this->sc[i].a_score += 14;
						this->sc[i].u_score += 14;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == b) {
						(*(this->sc + i)->st + j)->s_u_score += 10;
						(*(this->sc + i)->st + j)->s_a_score += 10;
						this->sc[i].a_score += 10;
						this->sc[i].u_score += 10;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == c) {
						(*(this->sc + i)->st + j)->s_u_score += 6;
						(*(this->sc + i)->st + j)->s_a_score += 6;
						this->sc[i].a_score += 6;
						this->sc[i].u_score += 6;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == d) {
						(*(this->sc + i)->st + j)->s_u_score += 4;
						(*(this->sc + i)->st + j)->s_a_score += 4;
						this->sc[i].a_score += 4;
						this->sc[i].u_score += 4;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == e) {
						(*(this->sc + i)->st + j)->s_u_score += 2;
						(*(this->sc + i)->st + j)->s_a_score += 2;
						this->sc[i].a_score += 2;
						this->sc[i].u_score += 2;
					}
				}
			}
		}
		if (p3[i]->p_num < 7) {
			cout << "请问第一名是哪个人(选择编号)\n";
			int a;
			cin >> a;
			cout << "请问第二名是哪个人(选择编号)\n";
			int b;
			cin >> b;
			cout << "请问第三名是哪个人(选择编号)\n";
			int c;
			cin >> c;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < this->sc[i].p_num; j++) {
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == a) {
						(*(this->sc + i)->st + j)->s_u_score += 10;
						(*(this->sc + i)->st + j)->s_a_score += 10;
						this->sc[i].a_score += 10;
						this->sc[i].u_score += 10;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == b) {
						(*(this->sc + i)->st + j)->s_u_score += 6;
						(*(this->sc + i)->st + j)->s_a_score += 6;
						this->sc[i].a_score += 6;
						this->sc[i].u_score += 6;
					}
					if ((((*(this->sc + i)->st + j)->s_bianhao)) == c) {
						(*(this->sc + i)->st + j)->s_u_score += 4;
						(*(this->sc + i)->st + j)->s_a_score += 4;
						this->sc[i].a_score += 4;
						this->sc[i].u_score += 4;
					}
				}
			}
		}
	}
}
void school::apply() {

	student** newspace = 0;

	if (st != NULL) {
		for (int i = 0; i < p_num; i++) {//如果有学生的话，先将存在的学生的信息放在newspace 
			newspace[i] = st[i];
		}
	}
	int bisai();
	cout << "请问第" << x << "个人想参加哪些比赛(请选择编号)\n";
	student* person = new student;

	m_pro* m_newp[max];
	int p;
	cout << "请问您的性别，若是男，则选1，若是女，则选2\n";
	cin >> p;
	if (p == 1) {
		int q = 1, i = 0;
		cout << "男子比赛(若选完，则按0):\n";
		do {
			cout << "请选择编号\n";
			cin >> q;
			if (q == 0) {
				cout << "男子已选完\n";
				break;
			}
			m_newp[i] = p1[q - 1];//将选的项目放在临时数组中
			i++;
			p1[q - 1]->p_num++;//让该项目的总人数加1
			if (i > 2) {
				cout << "每个运动员只能参加3个比赛\n";
				break;
			}
		} while (1);
		if (i != 0) {
			person->s_p1 = m_newp;//临时数组的信息放在临时人中
			this->s_p1 = m_newp;//更新该学校的男子比赛
			this->p1_num++;//让该学校的男子比赛人数加1
		}

	}
	else {

		int q = 1, i = 0;
		w_pro* w_newp[max];
		cout << "女子比赛(若选完，则按0):\n";
		cout << "请选择编号\n";
		do {
			cin >> q;
			if (q == 0) {
				cout << "女子已选完\n";
				break;
			}
			w_newp[i] = p2[q - 1];
			i++;
			p2[q - 1]->p_num++;
			if (i > 2) {
				cout << "每个运动员只能参加3个比赛\n";
				break;
			}

		} while (1);
		if (i != 0) {
			person->s_p2 = w_newp;
			this->p2_num++;
			this->s_p2 = w_newp;
		}

	}

	int q = 1, i = 0;
	u_pro* u_newp[max];
	cout << "团体比赛(若选完，则按0):\n";
	cout << "请选择编号\n";
	do {
		cin >> q;
		if (q == 0) {
			cout << "团体已选完\n";
			break;
		}
		u_newp[i] = p3[q - 1];
		i++;
		p3[q - 1]->p_num++;
	} while (1);
	this->s_p3 = u_newp;
	if (i != 0) {
		this->p3_num++;
		person->s_p3 = u_newp;
	}

	newspace[this->p_num] = person;//将整个学校的人员数组进行更新,即将此次报名的人加入学校
	this->st = newspace;
	this->st[this->p_num]->s_bianhao = y;
	y++;
	this->p_num++;
}
void bisai() {
	cout << "男子比赛:\n";
	for (int i = 0; i < m; i++) {
		cout << p1[i]->name << ":\n";
		p1[i]->getnum();
	}
	cout << "女子比赛:\n";
	for (int i = 0; i < w; i++) {
		cout << p2[i]->name << ":\n";
		p2[i]->getnum();
	}
	cout << "团体比赛:\n";
	for (int i = 0; i < u; i++) {
		cout << p3[i]->name << ":\n";
		p3[i]->getnum();
	}
}
void all::sc_find() {
	cout << "请问你想查询学校成绩还是参赛成员成绩，若是学校，请按1，若是成员，请按2:\n";
	int a;
	cin >> a;
	if (a == 1) {
		int b = 0;
		cout << "请输入学校编号\n";
		cin >> b;
		for (int i = 0; i < n; i++) {
			if (sc[i].bianhao == b) {
				cout << "该学校总分为" << sc[i].a_score << "  男子比赛分数为" << sc[i].m_score << "  女子比赛分数为" << sc[i].w_score;
				break;
			}
		}
	}
	if (a == 2) {
		int b = 0;
		cout << "请输入学生编号\n";
		cin >> b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < sc[i].p_num; j++) {
				if ((((*(this->sc + i)->st + j)->s_bianhao)) == b) {
					cout << "该学生的总分为" << (*(this->sc + i)->st + j)->s_a_score;
				}
			}
		}
	}
}
void meau() {
	std::cout << "****运动会成绩管理系统*********" << std::endl;
	cout << endl;
	cout << " 1  运动员报名" << endl;
	cout << " 2  查询学校信息" << endl;
	cout << " 3  查询比赛信息" << endl;
	cout << " 4  检录运动员信息" << endl;
	cout << " 5  竞赛成绩登记" << endl;
	cout << " 6  比赛成绩查询" << endl;
	cout << " 7  按总成绩进行排序" << endl;
	cout << " 8  按男团成绩进行排序" << endl;
	cout << " 9  按女团成绩进行排序" << endl;
	cout << " 0  退出该程序" << endl << endl;
}
void all::u_sort() {
	for (int i = 0; i < n; i++) {
		if (sc[i].a_score < sc[i + 1].a_score) {
			int tem = sc[i].a_score;
			sc[i].a_score = sc[i + 1].a_score;
			sc[i + 1].a_score = tem;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sc[i].bianhao << ". " << sc[i].a_score << "   ";
	}
}
void all::m_sort() {
	for (int i = 0; i < n; i++) {
		if (sc[i].m_score < sc[i + 1].m_score) {
			int tem = sc[i].m_score;
			sc[i].m_score = sc[i + 1].m_score;
			sc[i + 1].m_score = tem;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sc[i].bianhao << ". " << sc[i].m_score << "   ";
	}
}
void all::w_sort() {
	for (int i = 0; i < n; i++) {
		if (sc[i].w_score < sc[i + 1].w_score) {
			int tem = sc[i].w_score;
			sc[i].w_score = sc[i + 1].w_score;
			sc[i + 1].w_score = tem;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sc[i].bianhao << ". " << sc[i].w_score << "   ";
	}
}


int main() {

	int num;
	school s[max];
	all al;
	start();

	do {
		meau();
		cout << "请选择要操作的菜单标号:";
		cin >> num;
		while (num > 9 || num < 0)
		{
			cout << "输入有误，请重新输入要操作的项目编号:";
			cin >> num;
		}
		switch (num)
		{
		case 1:
			bisai();
			for (int i = 0; i < n; i++) {
				cout << "请问第" << i + 1 << "个学校有多少人参加\n";
				int b = 0;
				cin >> b;
				for (int j = 0; j < b; j++) {
					al.sc[i].apply();
				}
			}
			break;
		case 2:
			al.s_find();
			break;
		case 3:
			bisai();
			break;
		case 4:
			al.jianlu();
			break;
		case 5:
			al.registe();
			break;
		case 6:
			al.sc_find();
			break;
		case 7:
			al.u_sort();
			break;
		case 8:
			al.m_sort();
			break;
		case 9:
			al.w_sort();
		default:
			return 0;
		}
		system("cls");
	} while (1);


}

