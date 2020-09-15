/**
 *    author:	vulkan
 *    created:	30.08.2019 06:36:53 PM
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll get_length(ll n) {
	ll msb = 0;
	while (n) {
		msb++;
		n /= 2;
	}

	return 2 * (ll)pow(2, msb - 1) - 1;
}

int is_one(ll n, ll i, ll len) {
	if (n < 2) {
		return n;
	}

	ll mid = (len - 1) / 2;
	if (i == mid) {
		return n % 2;
	}

	if (i < mid) {
		return is_one(n / 2, i, len / 2);
	} else {
		return is_one(n / 2, i - (mid + 1), len / 2);
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, l, r;
	cin >> n >> l >> r;
	l--;

	int ans = 0;
	ll len = get_length(n);
	for (ll i = l; i < r; ++i) {
		ans += is_one(n, i, len);
	}

	cout << ans;

	return 0;
}