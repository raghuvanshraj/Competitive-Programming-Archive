/**
 *    author:	vulkan
 *    created:	13.10.2019 03:06:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		float a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = ceil(a / c), y = ceil(b / d);
		if (x + y <= k) {
			cout << x << ' ' << y;
		} else {
			cout << "-1";
		}

		cout << endl;
	}

	return 0;
}