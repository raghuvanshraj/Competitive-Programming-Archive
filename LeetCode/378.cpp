/**
 *    author:	vulkan
 *    created:	25.03.2020 02:14:36 AM
**/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int, int>> pipii;

int kthSmallest(vector<vector<int>> &mat, int k) {
	int n = mat.size();
	priority_queue<pipii, vector<pipii>, greater<pipii>> min_heap;
	for (int i = 0; i < n; ++i) {
		min_heap.push({mat[0][i], {0, i}});
	}

	pipii ans;
	while (k--) {
		ans = min_heap.top();
		min_heap.pop();
		if (ans.second.first < n - 1) {
			min_heap.push({mat[ans.second.first + 1][ans.second.second], {ans.second.first + 1, ans.second.second}});
		}
	}

	return ans.first;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}

	int k;
	cin >> k;

	cout << kthSmallest(mat, k);

	return 0;
}