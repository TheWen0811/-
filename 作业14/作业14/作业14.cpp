#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int n = 10;
void data(int arr[], int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void selece_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])min = j;
            if (min != i) {
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
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
    selece_sort(p,n);
    show_data(p, n);
    finish = clock();
    cout << endl << "the time cost is:" << double(finish - start) / CLOCKS_PER_SEC << endl;
}