#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int n = 100000;
void data(int arr[], int n) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	}
}
void straight_sort(int arr[], int len)
{
	int tmp;
	int i;
	int j;
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}
void show_data(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
int main() {
	clock_t start, finish;
	start = clock();
	int* p = new int[n];
	data(p, n);
	straight_sort(p, n);
	show_data(p, n);
	delete[] p;
	finish = clock();
	cout << endl << "the time cost is:" << double(finish - start) / CLOCKS_PER_SEC << endl;
}