/**
 *    author:	vulkan
 *    created:	03.09.2019 08:25:53 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_possible(int arr[], int n, int g) {
	priority_queue<int> que;
	for (int i = 0; i < n; ++i) {
		que.push(arr[i]);
	}

	while (not que.empty()) {
		int x = que.top();
		que.pop();
		if (que.empty()) {
			g -= x;
			if (g < 0) {
				return false;
			}
		} else {
			int y = que.top();
			que.pop();
			g -= y;
			if (g < 0) {
				return false;
			}

			if (x != y) {
				que.push(x - y);
			}
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, g;
		cin >> n >> g;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << ((is_possible(arr, n, g)) ? "YES" : "NO") << endl;
	}

	return 0;
}