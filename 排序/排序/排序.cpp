#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int n = 1000000;
void data(int arr[],int n) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	}
}
void bubble(int arr[], int n) {
	for (int i=0; i < n; i++) {
		for (int j=0; j < n - 1 - i; j++) {
			int temp;
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
		}
		}
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
	bubble(p, n);
	show_data(p,n);

	delete[] p;
	finish = clock();
	cout << endl << "the time cost is:" << double(finish - start) / CLOCKS_PER_SEC << endl;
}