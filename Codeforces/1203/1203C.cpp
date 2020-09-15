/**
 *    author:	vulkan
 *    created:	25.08.2019 09:45:37 PM
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll count_divisors(ll n) {
	ll cnt = 0;
	for (int i = 1; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			if (n / i == i) {
				cnt++;
			} else {
				cnt = cnt + 2;
			}
		}
	}

	return cnt;
}

ll total_divisors(ll *arr, int n) {
	ll curr_gcd = arr[0];
	for (int i = 1; i < n; ++i) {
		curr_gcd = (ll)__gcd(curr_gcd, arr[i]);
	}

	return count_divisors(curr_gcd);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll *arr = new ll[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << total_divisors(arr, n);

	return 0;
}