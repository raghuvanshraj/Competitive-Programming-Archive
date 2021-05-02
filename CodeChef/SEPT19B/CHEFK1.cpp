/**
 *    author:	vulkan
 *    created:	07.09.2019 05:28:49 PM
**/
#include <bits/stdc++.h>

using namespace std;

long minimize_max_degree(long n, long m) {
	if (m < n - 1 or m > (n * (n + 1)) / 2 or (m == 0 and n > 1)) {
		return -1;
	} else if (m == 0 and n == 1) {
		return 0;
	} else if ((m == 1 and n == 1) or (m == 1 and n == 2)) {
		return 1;
	} else if (m <= n + 1) {
		return 2;
	} else if (m <= 2 * n) {
		return 3;
	}

	m -= n;
	long min_possible = (2 * m) / n;
	while (min_possible * n < 2 * m) {
		min_possible++;
	}

	return min_possible + 1;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long n, m;
		cin >> n >> m;

		cout << minimize_max_degree(n, m) << endl;
	}

	return 0;
}