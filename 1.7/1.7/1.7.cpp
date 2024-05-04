#include <iostream>
using namespace std;
struct Arr {
	int* pBase;
	int len;
	int cnt;
	int increment;  
};
void init_arr(Arr* parr, int length);
bool append_arr(Arr* parr,int val );//追加
bool insert_arr(Arr* parr, int pos, int val);
bool delete_arr(Arr* parr, int pos, int* pval);
int get();
bool is_empty(Arr* parr);
bool is_full(Arr* parr);
void sort_arr();
void show_arr(Arr* parr);
void inversion_arr();

int main() {
	Arr arr;  
	init_arr(&arr,6);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	insert_arr(&arr, 1, 99);
	show_arr(&arr);

}
void init_arr(Arr *parr,int length) {
	parr->pBase=(int *)malloc(sizeof(int)*length); //parr->pBase相当于parr所指向的结构体中的pBase成员 
	if (NULL == parr->pBase) {
		cout << "失败";
		exit(-1);
	}
	else {
		parr->len = length;
		parr->cnt = 0;
	}
}
bool is_empty(struct Arr* parr) {
	if (0 == parr->cnt)
		return true;
	else 
		return false;
}
void show_arr(Arr* parr) 
{for (int i = 0; i < parr->cnt; i++) {
		cout <<int(parr->pBase[i])<<" ";
	}
} 
bool is_full(Arr* parr) {
	if (parr->cnt == parr->len)
		return true;
	else
		return false; 
}
bool append_arr(Arr* parr, int val) {
	if (is_full(parr))
		return false;
	else parr->pBase[parr->cnt] = val;
	parr->cnt++; 
	return true;
}
bool insert_arr(Arr* parr, int pos, int val) {
	int i;
	for (i = parr->cnt - 1; i >=pos - 1; --i) {
		parr->pBase[i + 1] = parr->pBase[i];
	}
	parr->pBase[pos - 1] = val;
	parr->cnt++;
	return true;
}