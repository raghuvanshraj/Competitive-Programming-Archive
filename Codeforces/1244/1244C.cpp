/**
 *    author:	vulkan
 *    created:	13.10.2019 03:42:50 PM
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<ll, ll> extended_euclid(ll a, ll b) {
	if (a == 0) {
		return {0, 1};
	}

	pair<ll, ll> sub_ans = extended_euclid(b % a, a);
	pair<ll, ll> ans;
	ans.second = sub_ans.first;
	ans.first = sub_ans.second - ((b / a) * sub_ans.first);

	return ans;
}

ll mod_inverse(ll a, ll m) {
	ll ans = extended_euclid(a, m).first;
	return ((ans % m) + m) % m;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	ll gcd_wd = __gcd(w, d);
	if (p % gcd_wd != 0) {
		cout << "-1";
	} else {
		p /= gcd_wd;
		w /= gcd_wd;
		d /= gcd_wd;

		ll y = ((p % w) * mod_inverse(d, w)) % w;

		if (d * y > p) {
			cout << "-1";
		} else {
			ll x = (p - d * y) / w;
			ll z = n - x - y;

			if (x < 0 or y < 0 or z < 0) {
				cout << "-1";
			} else {
				cout << x << ' ' << y << ' ' << z;
			}
		}
	}

	return 0;
}