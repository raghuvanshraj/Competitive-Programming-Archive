/**
 *    author:	vulkan
 *    created:	25.10.2019 02:08:39 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long* generate_arr(long n, long x, long y, long c, long d, long e1, long e2, long f) {
	x %= f;
	y %= f;
	c %= f;
	d %= f;

	long mult = (c + d) % f;
	long inc = (e1 + e2) % f;
	long *a = new long[n + 1]();
	a[1] = (x + y) % f;
	for (int i = 2; i <= n; ++i) {
		a[i] = ((mult * a[i - 1]) % f + inc) % f;
	}

	return a;
}

long mod_exp(long b, long e) {
	long ans = 1;
	while (e) {
		if (e & 1) {
			ans = (ans * b) % MOD;
		}

		e /= 2;
		b = (b * b) % MOD;
	}

	return ans;
}

long* generate_p(long n, long k) {
	long *p = new long[n + 1]();
	p[1] = k;
	for (int i = 2; i <= n; ++i) {
		long curr = ((mod_exp(i, k) + MOD - 1) % MOD);
		curr = (((curr * i) % MOD) * mod_exp(i - 1, MOD - 2)) % MOD;
		p[i] = (p[i - 1] + curr) % MOD;
	}

	return p;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		long n, k, x, y, c, d, e1, e2, f;
		cin >> n >> k >> x >> y >> c >> d >> e1 >> e2 >> f;

		long *a = generate_arr(n, x, y, c, d, e1, e2, f);
		long *p = generate_p(n, k);

		long ans = 0;
		for (int i = 1; i <= n; ++i) {
			long inc_ans = (((a[i] * (n - i + 1)) % MOD) * p[i]) % MOD;
			ans = (ans + inc_ans) % MOD;
		}

		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}