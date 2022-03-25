/**
 *    author:	vulkan
 *    created:	25.02.2022 08:47:31 AM
**/
#include <bits/stdc++.h>

using namespace std;

static bool comparator(vector<int> &a, vector<int> &b) {
	if (a[0] != b[0]) {
		return a[0] < b[0];
	}
	return a[1] < b[1];
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
	sort(intervals.begin(), intervals.end(), comparator);
	vector<vector<int>> ans;
	vector<int> curr_interval = intervals[0];
	for (auto interval : intervals) {
		if (curr_interval[1]  < interval[0]) {
			ans.push_back(curr_interval);
			curr_interval = interval;
		}
		curr_interval[1] = max(curr_interval[1], interval[1]);
	}
	ans.push_back(curr_interval);

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> intervals(n, vector<int>(2));
	for (int i = 0; i <= n - 1; ++i) {
		cin >> intervals[i][0] >> intervals[i][1];
	}

	vector<vector<int>> ans = merge(intervals);
	for (auto x : ans) {
		cout << x[0] << ' ' << x[1] << endl;
	}

	return 0;
}