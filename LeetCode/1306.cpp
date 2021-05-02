/**
 *    author:	vulkan
 *    created:	16.08.2020 09:05:14 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool canReach(vector<int> &arr, int start) {
	int n = arr.size();
	vector<bool> vis(n);
	vis[start] = true;
	queue<int> qu;
	qu.push(start);
	while (not qu.empty()) {
		int x = qu.front();
		qu.pop();
		if (x - arr[x] >= 0 and not vis[x - arr[x]]) {
			qu.push(x - arr[x]);
			vis[x - arr[x]] = true;
		}
		if (x + arr[x] < n and not vis[x + arr[x]]) {
			qu.push(x + arr[x]);
			vis[x + arr[x]] = true;
		}
	}

	for (int i = 0; i <= n - 1; ++i) {
		if (arr[i] == 0 and vis[i]) {
			return true;
		}
	}

	return false;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int start;
	cin >> start;

	cout << canReach(arr, start);

	return 0;
}