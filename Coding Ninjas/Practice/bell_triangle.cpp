#include <bits/stdc++.h>

using namespace std;

int bellNo(int n) {
	int bell[n+1][n+1];
	bell[0][0] = 1;
	for (int i = 1; i < n+1; ++i) {
		bell[i][0] = bell[i-1][i-1];

		for (int j = 1; j < i+1; ++j) {
			bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
		}
	}

	return bell[n][0];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	cout << "Bell Nos\n";
	for (int i = 0; i < n+1; ++i) {
		cout << bellNo(i) << ' ';
	}
	return 0;
}