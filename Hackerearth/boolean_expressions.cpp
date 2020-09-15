#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;
typedef long long ll;

void boolean_expression(string symbols, string operators, ll **t, ll **f, int n) {
	for (int i = 0; i < n; ++i) {
		t[i][i] = (symbols[i] == '1') ? 1 : 0;
		f[i][i] = 1 - t[i][i];
	}

	for (int gap = 1; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			for (int g = 0; g < gap; ++g) {
				int k = i + g;

				ll total_ik = t[i][k] + f[i][k], total_kj = t[k+1][j] + f[k+1][j];
				ll total = (total_ik * total_kj) % MOD;
				if (operators[k] == 'a') {
					t[i][j] = (t[i][j] + (t[i][k] * t[k+1][j]) % MOD) % MOD;
					f[i][j] = (f[i][j] + (total - ((t[i][k] * t[k+1][j]) % MOD) + MOD) % MOD) % MOD;
				} else if (operators[k] == 'o') {
					f[i][j] = (f[i][j] + (f[i][k] * f[k+1][j]) % MOD) % MOD;
					t[i][j] = (t[i][j] + (total - ((f[i][k] * f[k+1][j]) % MOD) + MOD) % MOD) % MOD;
				} else if (operators[k] == 'x') {
					t[i][j] = (t[i][j] + ((f[i][k] * t[k+1][j]) % MOD) + ((t[i][k] * f[k+1][j]) % MOD)) % MOD;
					f[i][j] = (f[i][j] + ((t[i][k] * t[k+1][j]) % MOD) + ((f[i][k] * f[k+1][j]) % MOD)) % MOD;
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	string symbols, operators;
	cin >> symbols >> operators;

	int n = symbols.size();
	ll **t = new ll*[n](), **f = new ll*[n]();
	for (int i = 0; i < n; ++i) {
		t[i] = new ll[n]();
		f[i] = new ll[n]();
	}

	boolean_expression(symbols, operators, t, f, n);

	int q;
	cin >> q;
	while (q--) {
		int l,r;
		string type;
		cin >> l >> r >> type;

		if (type == "true") {
			cout << t[l-1][r-1];
		} else {
			cout << f[l-1][r-1];
		}

		cout << endl;
	}
	
	return 0;
}