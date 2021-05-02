/**
 *    author:	vulkan
 *    created:	29.06.2020 09:51:17 PM
**/
#include <bits/stdc++.h>

using namespace std;

void insert_elt(deque<int> &deq, vector<int> &arr, int i) {
	while (not deq.empty() and arr[deq.back()] <= arr[i]) {
		deq.pop_back();
	}

	deq.push_back(i);
}

void delete_idx(deque<int> &deq, int i) {
	while (not deq.empty() and deq.front() <= i) {
		deq.pop_front();
	}
}

int findMaxValueOfEquation(vector<vector<int>> &pts, int k) {
	int n = pts.size();
	vector<int> x(n), y(n);
	for (int i = 0; i <= n - 1; ++i) {
		x[i] = pts[i][0];
		y[i] = pts[i][1];
	}

	vector<int> sums(n);
	for (int i = 0; i <= n - 1; ++i) {
		sums[i] = x[i] + y[i];
	}

	int ans = INT_MIN;
	int idx = 0;
	deque<int> deq;
	for (int i = 0; i <= n - 1; ++i) {
		int j = lower_bound(x.begin(), x.end(), x[i] + k) - x.begin();
		if (j == n or x[j] - x[i] > k) {
			j--;
		}

		while (idx <= j) {
			insert_elt(deq, sums, idx);
			idx++;
		}

		delete_idx(deq, i);

		if (not deq.empty()) {
			ans = max(ans, sums[deq.front()] + y[i] - x[i]);
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> pts(n, vector<int>(2));
	for (int i = 0; i <= n - 1; ++i) {
		cin >> pts[i][0] >> pts[i][1];
	}
	int k;
	cin >> k;

	cout << findMaxValueOfEquation(pts, k);

	return 0;
}