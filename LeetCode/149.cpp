/**
 *    author:	vulkan
 *    created:	22.05.2020 01:51:37 AM
**/
#include <bits/stdc++.h>

using namespace std;

int maxPoints(vector<vector<int>> &points) {
	int n = points.size();
	if (n == 0) {
		return 0;
	}

	int ans = 1;
	map<vector<int>, int> pt_cnt;
	for (int i = 0; i <= n - 1; ++i) {
		pt_cnt[points[i]]++;
	}

	for (int i = 0; i <= n - 1; ++i) {
		ans = max(ans, pt_cnt[points[i]]);
		map<pair<int, int>, int> cnt;
		for (int j = i + 1; j <= n - 1; ++j) {
			if (points[i] != points[j]) {
				int x = points[j][0] - points[i][0];
				int y = points[j][1] - points[i][1];
				int gcd = __gcd(abs(x), abs(y));
				x /= gcd;
				y /= gcd;

				if (y < 0) {
					x *= -1;
					y *= -1;
				} else if (y == 0) {
					x = 1;
				}

				if (x == 0) {
					y = 1;
				}

				ans = max(ans, ++cnt[ {x, y}] + pt_cnt[points[i]]);
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> points(n, vector<int>(2));
	for (int i = 0; i <= n - 1; ++i) {
		cin >> points[i][0] >> points[i][1];
	}

	cout << maxPoints(points);

	return 0;
}