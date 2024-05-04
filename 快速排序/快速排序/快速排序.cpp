#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int n = 100;
void data(int arr[], int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}
    void quick_sort(int arr[], int begin, int end) {
        if (begin > end)
            return;
        int tmp = arr[begin];
        int i = begin;
        int j = end;
        while (i != j) {
            while (arr[j] >= tmp && j > i)
                j--;
            while (arr[i] <= tmp && j > i)
                i++;
            if (j > i) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        arr[begin] = arr[i];
        arr[i] = tmp;
        quick_sort(arr, begin, i - 1);
        quick_sort(arr, i + 1, end);
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
        quick_sort(p, 0, n);
        show_data(p, n);
        finish = clock();
        cout << endl << "the time cost is:" << double(finish - start) / CLOCKS_PER_SEC << endl;
        delete p;
        return 0;
    }
    