/**
 *    author:	vulkan
 *    created:	06.09.2019 07:43:03 PM
**/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

void mat_multiply(int f[2][2], int m[2][2]) {
	int x = ((f[0][0] * m[0][0]) % 10 + (f[0][1] * m[1][0]) % 10) % 10;
	int y = ((f[0][0] * m[0][1]) % 10 + (f[0][1] * m[1][1]) % 10) % 10;
	int z = ((f[1][0] * m[0][0]) % 10 + (f[1][1] * m[1][0]) % 10) % 10;
	int w = ((f[1][0] * m[0][1]) % 10 + (f[1][1] * m[1][1]) % 10) % 10;

	f[0][0] = x;
	f[0][1] = y;
	f[1][0] = z;
	f[1][1] = w;
}

void mat_exp(int f[2][2], ull n) {
	if (n == 0 or n == 1) {
		return;
	}

	int m[2][2] = {{1, 1}, {1, 0}};
	mat_exp(f, n / 2);
	mat_multiply(f, f);

	if (n % 2 != 0) {
		mat_multiply(f, m);
	}
}

int fib_mod_10(ull n) {
	int f[2][2] = {{1, 1}, {1, 0}};
	if (n == 0) {
		return 0;
	}

	mat_exp(f, n - 1);
	return f[0][0];
}

int calc_log(ull n) {
	int count = 0;
	while (n) {
		n /= 2;
		count++;
	}

	return count - 1;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ull t;
	cin >> t;
	while (t--) {
		ull n;
		cin >> n;

		int exp = calc_log(n);
		ull elt_pos = (ull)pow(2, exp);

		cout << fib_mod_10(elt_pos - 1) << endl;
	}

	return 0;
}