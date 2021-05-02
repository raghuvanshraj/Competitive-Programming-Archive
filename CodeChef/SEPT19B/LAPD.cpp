/**
 *    author:	vulkan
 *    created:	08.09.2019 03:18:38 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n_triplets(int a, int b, int c) {
	int min_ac = min(a, c);
	int max_ac = max(a, c);
	int ans = 0;
	for (int i = 1; i < b + 1; ++i) {
		if (min_ac >= i) {
			ans = (ans + (((a - (i - 1)) * (c - (i - 1))) % MOD) - 1 + MOD) % MOD;
		}

		int range = min(min_ac, i - 1) + 1;
		for (int j = 1; j < range; ++j) {
			int x = (i * i) / j;
			if (x * j <= i * i) {
				x++;
			}

			if (x <= min_ac) {
				ans = (ans + (2 * (min_ac - x + 1 + MOD) % MOD) % MOD) % MOD;
			}
			if (x <= max_ac) {
				ans = (ans + (max_ac - max(min_ac, x) + 1 + MOD) % MOD) % MOD;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		c--;

		cout << n_triplets(a, b, c) << endl;
	}

	return 0;
}