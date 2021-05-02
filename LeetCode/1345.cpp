/**
 *    author:	vulkan
 *    created:	16.08.2020 09:17:37 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minJumps(vector<int> &arr) {
	int n = arr.size();
	map<int, vector<int>> idx;
	for (int i = 0; i <= n - 1; ++i) {
		if (not idx[arr[i]].empty() and idx[arr[i]].back() == i - 1) {
			idx[arr[i]].pop_back();
		}
		idx[arr[i]].push_back(i);
	}

	queue<pair<int, int>> qu;
	qu.push({0, 0});
	vector<bool> vis(n);
	vis[0] = true;
	while (not qu.empty()) {
		auto x = qu.front();
		qu.pop();
		if (x.first == n - 1) {
			return x.second;
		}

		if (x.first + 1 < n and not vis[x.first + 1]) {
			qu.push({x.first + 1, x.second + 1});
			vis[x.first + 1] = true;
		}
		if (x.first - 1 >= 0 and not vis[x.first - 1]) {
			qu.push({x.first - 1, x.second + 1});
			vis[x.first - 1] = true;
		}

		for (int y : idx[arr[x.first]]) {
			if (not vis[y]) {
				qu.push({y, x.second + 1});
				vis[y] = true;
			}
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << minJumps(arr);

	return 0;
}