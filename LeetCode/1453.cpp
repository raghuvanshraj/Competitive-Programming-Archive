/**
 *    author:	vulkan
 *    created:	17.05.2020 04:49:29 PM
**/
#include <bits/stdc++.h>

using namespace std;

int dist(vector<int> pt1, vector<int> pt2) {
	int x = abs(pt1[0] - pt2[0]), y = abs(pt1[1] - pt2[1]);
	return x * x + y * y;
}

bool comp(set<int> &a, set<int> &b) {
	return a.size() > b.size();
}

int numPoints(vector<vector<int>> &points, int r) {
	// map<int,int> pt_counts;
	int n = points.size();
	vector<set<int>> pts(n);
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n - 1; ++j) {
			if (dist(points[i], points[j]) > 4 * r * r) {
				pts[i].insert(j);
				pts[j].insert(i);
			}
		}
	}

	sort(pts.begin(), pts.end(), comp);

	int ans = n;
	for (int i = 0; i <= n - 1; ++i) {
		if (pts[i].size()) {
			ans--;
			for (int j : pts[i]) {
				pts[j].erase(i);
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
	int r;
	cin >> r;

	cout << numPoints(points, r);

	return 0;
}