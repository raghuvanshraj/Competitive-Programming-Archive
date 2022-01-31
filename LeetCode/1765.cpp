/**
 *    author:	vulkan
 *    created:	30.01.2022 02:07:28 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool in_range(int i, int n) {
	return i >= 0 and i <= n - 1;
}

vector<vector<int>> highestPeak(vector<vector<int>> &is_water) {
	int n = is_water.size();
	int m = is_water[0].size();

	queue<pair<int, int>> qu;
	vector<vector<int>> ans(n, vector<int>(m));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			if (is_water[i][j]) {
				qu.push({i, j});
			}
		}
	}

	vector<pair<int, int>> adj({
		{0, 1},
		{0, -1},
		{1, 0},
		{ -1, 0}
	});

	while (not qu.empty()) {
		pair<int, int> curr = qu.front();
		qu.pop();
		for (pair<int, int> diff : adj) {
			int x = curr.first;
			int y = curr.second;
			int i = x + diff.first;
			int j = y + diff.second;
			if (in_range(i, n) and in_range(j, m) and
			        (not ans[i][j] and not is_water[i][j])) {
				ans[i][j] = ans[x][y] + 1;
				qu.push({i, j});
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> is_water(n, vector<int>(m));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			cin >> is_water[i][j];
		}
	}

	vector<vector<int>> ans = highestPeak(is_water);
	for (auto x : ans) {
		for (int y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}

	return 0;
}