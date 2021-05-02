/**
 *    author:	vulkan
 *    created:	18.03.2020 01:47:41 PM
**/
#include <bits/stdc++.h>

using namespace std;

static bool comp(vector<int> &a, vector<int> &b) {
	if (a[0] != b[0]) {
		return a[0] < b[0];
	} else {
		return a[1] < b[1];
	}
}

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &new_interval) {
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), comp);

	vector<vector<int>> inserted_intervals;
	for (int i = 0; i < n; ++i) {
		if (new_interval[0] == -1) {
			inserted_intervals.push_back(intervals[i]);
			continue;
		}

		if (new_interval[0] > intervals[i][1]) {
			inserted_intervals.push_back(intervals[i]);
		} else if (new_interval[1] < intervals[i][0]) {
			inserted_intervals.push_back(new_interval);
			inserted_intervals.push_back(intervals[i]);

			new_interval[0] = -1;
		} else {
			if (intervals[i][0] <= new_interval[0]) {
				new_interval[0] = intervals[i][0];
			}
			if (intervals[i][1] >= new_interval[1]) {
				new_interval[1] = intervals[i][1];
			}
		}
	}

	if (new_interval[0] != -1) {
		inserted_intervals.push_back(new_interval);
	}

	return inserted_intervals;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> intervals(n, vector<int>(2));
	for (int i = 0; i < n; ++i) {
		cin >> intervals[i][0] >> intervals[i][1];
	}

	vector<int> new_interval(2);
	cin >> new_interval[0] >> new_interval[1];

	vector<vector<int>> inserted_intervals = insert(intervals, new_interval);
	for (int i = 0; i < inserted_intervals.size(); ++i) {
		cout << inserted_intervals[i][0] << ' ' << inserted_intervals[i][1] << endl;
	}

	return 0;
}