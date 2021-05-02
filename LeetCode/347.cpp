/**
 *    author:	vulkan
 *    created:	25.03.2020 02:30:21 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &arr, int k) {
	int n = arr.size();
	map<int, int> counts;
	for (int i = 0; i < n; ++i) {
		counts[arr[i]]++;
	}

	set<int> visited;
	priority_queue<pair<int, int>> max_heap;
	for (int i = 0; i < n; ++i) {
		if (visited.find(arr[i]) == visited.end()) {
			visited.insert(arr[i]);
			max_heap.push({counts[arr[i]], arr[i]});
		}
	}

	vector<int> ans(k);
	for (int i = 0; i < k; ++i) {
		ans[i] = max_heap.top().second;
		max_heap.pop();
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int k;
	cin >> k;

	vector<int> ans = topKFrequent(arr, k);
	for (int i = 0; i < k; ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}