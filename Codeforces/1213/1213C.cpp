/**
 *    author:	vulkan
 *    created:	31.08.2019 06:42:41 PM
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum_divisors(ll n, ll m) {
	ll k = n / m;
	ll *cycle = new ll[10]();
	for (int i = 0; i < 10; ++i) {
		cycle[i] = (m * (i + 1)) % 10;
	}

	return (k / 10) * accumulate(cycle, cycle + 10, 0LL) +
	       accumulate(cycle, cycle + (k % 10), 0LL);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		ll n, m;
		cin >> n >> m;

		cout << sum_divisors(n, m) << endl;
	}

	return 0;
}