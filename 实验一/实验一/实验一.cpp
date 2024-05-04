#include <iostream>
using namespace std;
void paixu(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp;
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
 }
int main()
{
	const int n = 10;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	paixu(a, n);
   
}
