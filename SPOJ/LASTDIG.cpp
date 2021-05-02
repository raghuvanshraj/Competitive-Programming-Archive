/**
 *    author:	vulkan
 *    created:	14.09.2020 05:08:49 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int pow_mod(int a, int b, int c) {
	int res = 1;
	while (b) {
		if (b % 2) {
			res = (res * a) % c;
		}

		a = (a * a) % c;
		b /= 2;
	}

	return res;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << pow_mod(a, b, 10) << endl;
	}

	return 0;
}