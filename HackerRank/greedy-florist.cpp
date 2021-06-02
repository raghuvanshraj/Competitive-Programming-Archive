/**
 *    author:	vulkan
 *    created:	02.09.2019 12:59:21 PM
**/
#include <bits/stdc++.h>

using namespace std;

int get_min_cost(int flowers[], int n, int k) {
	sort(flowers, flowers + n, greater<int>());
	int mult_factor = 1;
	int ans = 0;
	int i = 0;
	while (i < n) {
		if (i + k <= n) {
			ans += mult_factor * accumulate(flowers + i, flowers + i + k, 0);
		} else {
			ans += mult_factor * accumulate(flowers + i, flowers + n, 0);
		}

		mult_factor++;
		i += k;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int flowers[n];
	for (int i = 0; i < n; ++i) {
		cin >> flowers[i];
	}

	cout << get_min_cost(flowers, n, k);

	return 0;
}