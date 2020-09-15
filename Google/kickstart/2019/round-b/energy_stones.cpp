/**
 *    author:	vulkan
 *    created:	01.11.2019 10:36:52 AM
**/
#include <bits/stdc++.h>

using namespace std;

struct stone_t {
	int s, e, l;
};

bool comp(stone_t a, stone_t b) {
	return a.s * b.l < b.s * a.l;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		stone_t stones[n];
		for (int i = 0; i < n; ++i) {
			cin >> stones[i].s >> stones[i].e >> stones[i].l;
		}

		sort(stones, stones + n, comp);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += stones[i].s;
		}

		int dp[n][sum + 1];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < sum + 1; ++j) {
				dp[i][j] = 0;
			}
		}

		for (int i = 0; i < sum + 1; ++i) {
			dp[n - 1][i] = max(0, stones[n - 1].e - (stones[n - 1].l * i));
		}

		for (int i = n - 2; i >= 0; --i) {
			for (int j = sum; j >= 0; --j) {
				if (j + stones[i].s <= sum) {
					dp[i][j] = max({
						dp[i + 1][j + stones[i].s] + max(0, stones[i].e - (stones[i].l * j)),
						dp[i + 1][j]
					});
				}
			}
		}

		cout << "Case #" << t + 1 << ": " << dp[0][0] << endl;
	}

	return 0;
};