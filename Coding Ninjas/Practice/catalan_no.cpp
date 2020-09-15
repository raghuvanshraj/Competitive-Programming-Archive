#include <bits/stdc++.h>
#define MAX 101

using namespace std;

unsigned long long catalan[MAX];

void populateCatalanArray() {
	catalan[0] = 1;
	for (int i = 1; i < MAX; ++i) {
		for (int j = 0; j < i; ++j) {
			catalan[i] += catalan[j] * catalan[i-j-1];
		}
	}
}

int main(int argc, char const *argv[]) {
	populateCatalanArray();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << catalan[n] << endl;
	}
	return 0;
}