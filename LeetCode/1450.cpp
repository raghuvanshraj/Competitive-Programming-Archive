/**
 *    author:	vulkan
 *    created:	17.05.2020 10:43:07 AM
**/
#include <bits/stdc++.h>

using namespace std;

int busyStudent(vector<int> &start_time, vector<int> &end_time, int query_time) {
	int n = start_time.size();
	vector<int> ans(1002);
	for (int i = 0; i <= n - 1; ++i) {
		ans[start_time[i]]++;
		ans[end_time[i] + 1]--;
	}

	for (int i = 1; i <= query_time; ++i) {
		ans[i] += ans[i - 1];
	}

	return ans[query_time];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> start_time(n), end_time(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> start_time[i];
	}
	for (int i = 0; i <= n - 1; ++i) {
		cin >> end_time[i];
	}
	int query_time;
	cin >> query_time;

	cout << busyStudent(start_time, end_time, query_time);

	return 0;
}