/**
 *    author:	vulkan
 *    created:	03.06.2020 10:25:30 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &a, vector<vector<int>> &b) {
	int n = a.size(), m = b.size();
	if (n == 0 or m == 0) {
		return {};
	}

	int i = 0, j = 0;
	vector<vector<int>> ans;
	while (i < n and j < m) {
		if (a[i][1] < b[j][0]) {
			i++;
		} else if (b[j][1] < a[i][0]) {
			j++;
		} else {
			ans.push_back({
				max(a[i][0], b[j][0]),
				min(a[i][1], b[j][1])
			});

			if (a[i][1] < b[j][1]) {
				i++;
			} else if (a[i][1] > b[j][1]) {
				j++;
			} else {
				i++;
				j++;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(2)), b(m, vector<int>(2));
	for (int i = 0; i <= n - 1; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 0; i <= m - 1; ++i) {
		cin >> b[i][0] >> b[i][1];
	}

	vector<vector<int>> ans = intervalIntersection(a, b);
	for (vector<int> curr : ans) {
		cout << curr[0] << ' ' << curr[1] << endl;
	}

	return 0;
}