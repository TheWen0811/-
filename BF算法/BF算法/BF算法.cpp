#include <iostream>
using namespace std;
int BF(char* S, char* T) {
	int s = strlen(S);
	int t = strlen(T);
	int i = 0;
	int j = 0;
	while (i < s && j < t) {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
		if (j == t) {
			return i - j + 1;
		}
		else return 21;
	
}

int main(){
	char a[256];
	char b[256];
	cin >> a >> b;
	cout<<BF(a, b);
}