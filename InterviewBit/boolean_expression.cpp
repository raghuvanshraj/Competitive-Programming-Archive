#include <bits/stdc++.h>
#define MOD 1003

using namespace std;

int cnttrue(string expression) {
	string symbols = "", operators = "";
	int m = expression.size();
	int n = (m + 1) / 2;
	for (int i = 0; i < m; ++i) {
		if (i % 2 == 0) {
			symbols = symbols + expression.substr(i,1);
		} else {
			operators = operators + expression.substr(i,1);
		}
	}

	int **t = new int*[n](), **f = new int*[n]();
	for (int i = 0; i < n; ++i) {
		t[i] = new int[n]();
		f[i] = new int[n]();
	}

	for (int i = 0; i < n; ++i) {
		t[i][i] = (symbols[i] == 'T') ? 1 : 0;
		f[i][i] = 1 - t[i][i];
	}

	for (int gap = 1; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			for (int g = 0; g < gap; ++g) {
				int k = i + g;

				int total_ik = t[i][k] + f[i][k], total_kj = t[k+1][j] + f[k+1][j];
				int total = (total_ik * total_kj) % MOD;
				if (operators[k] == '&') {
					t[i][j] = (t[i][j] + (t[i][k] * t[k+1][j]) % MOD) % MOD;
					f[i][j] = (f[i][j] + (total - ((t[i][k] * t[k+1][j]) % MOD) + MOD) % MOD) % MOD;
				} else if (operators[k] == '|') {
					f[i][j] = (f[i][j] + (f[i][k] * f[k+1][j]) % MOD) % MOD;
					t[i][j] = (t[i][j] + (total - ((f[i][k] * f[k+1][j]) % MOD) + MOD) % MOD) % MOD;
				} else if (operators[k] == '^') {
					t[i][j] = (t[i][j] + ((f[i][k] * t[k+1][j]) % MOD) + ((t[i][k] * f[k+1][j]) % MOD)) % MOD;
					f[i][j] = (f[i][j] + ((t[i][k] * t[k+1][j]) % MOD) + ((f[i][k] * f[k+1][j]) % MOD)) % MOD;
				}
			}
		}
	}

	return t[0][n-1];
}

int main(int argc, char const *argv[]) {
	string expression;
	cin >> expression;

	cout << cnttrue(expression);
	
	return 0;
}