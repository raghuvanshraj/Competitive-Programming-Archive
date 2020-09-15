#include <bits/stdc++.h>

using namespace std;

int eggDrop(int n, int k) {
	int minDrops[n+1][k+1];
	memset(minDrops, 0, sizeof(int) * (n+1) * (k+1));

	for (int i = 0; i < n; ++i) {
		minDrops[i+1][1] = 1;
	}

	for (int i = 1; i < k+1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			
			int res = INT_MIN;
			for (int i = 0; i < count; ++i) {
				/* code */
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int n,k;
	cin >> n >> k;
	cout << eggDrop(n, k);
	return 0;
}