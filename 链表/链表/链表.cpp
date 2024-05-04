#include <iostream>
using namespace std;
struct student {
	int sid;
	char name[200];
	int age;
};
int main() {
	student st = { 1000,"w1w",11 };
	cout << st.sid << st.name << st.age;
	//st.sid=99;//第一种方式
	struct student* pst;
	pst = &st;
	pst->sid = 99;//pst->sid等价于(*pst).std,而(*pst)等价于st,所以pst->sid等价于st.sid;
	
}
	