/**
 *    author:	vulkan
 *    created:	09.03.2020 03:52:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

static bool comp(pair<int, int> a, pair<int, int> b) {
	return (a.first * a.second) < (b.first * b.second);
}

int maximalRectangle(vector<vector<char>> &matrix) {
	int n = matrix.size(), m;
	if (n > 0) {
		m = matrix[0].size();
		if (m == 0) {
			return 0;
		}
	} else {
		return 0;
	}

	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m));
	vector<vector<pair<int, int>>> counts(n, vector<pair<int, int>>(m));

	if (matrix[0][0] == '1') {
		dp[0][0].first = dp[0][0].second = 1;
		counts[0][0].first = counts[0][0].second = 1;
	}

	for (int i = 1; i < n; ++i) {
		if (matrix[i][0] == '1') {
			counts[i][0].first = counts[i - 1][0].first + 1;
			counts[i][0].second = 1;
		} else {
			counts[i][0].first = counts[i][0].second = 0;
		}

		dp[i][0].first = counts[i][0].first;
		dp[i][0].second = counts[i][0].second;
	}

	for (int i = 1; i < m; ++i) {
		if (matrix[0][i] == '1') {
			counts[0][i].second = counts[0][i - 1].second + 1;
			counts[0][i].first = 1;
		} else {
			counts[0][i].first = counts[0][i].second = 0;
		}

		dp[0][i].first = counts[0][i].first;
		dp[0][i].second = counts[0][i].second;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (matrix[i][j] == '1') {
				counts[i][j].first = counts[i - 1][j].first + 1;
				counts[i][j].second = counts[i][j - 1].second + 1;

				int f_1, f_2, s_1, s_2;
				s_1 = min({
					dp[i - 1][j].second,
					counts[i][j].second
				});

				f_1 = dp[i - 1][j].first + 1;

				f_2 = min({
					dp[i][j - 1].first,
					counts[i][j].first
				});

				s_2 = dp[i][j - 1].second + 1;

				dp[i][j] = max({
					make_pair(f_1, s_1),
					make_pair(f_2, s_2),
					make_pair(1, counts[i][j].second),
					make_pair(counts[i][j].first, 1)
				},
				comp
				              );
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans = max({
				ans,
				dp[i][j].first * dp[i][j].second
			});
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> matrix(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << maximalRectangle(matrix);

	return 0;
}