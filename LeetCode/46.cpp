/**
 *    author:	vulkan
 *    created:	15.01.2022 01:33:18 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void _permute(vector<int> &arr, int idx, vector<int> &curr_ans, set<int> &visited) {
	int n = arr.size();
	if (idx == n) {
		ans.push_back(curr_ans);
		return;
	}

	for (int i = 0; i <= n - 1; ++i) {
		if (not visited.count(arr[i])) {
			curr_ans[idx] = arr[i];
			visited.insert(arr[i]);
			_permute(arr, idx + 1, curr_ans, visited);
			visited.erase(arr[i]);
		}
	}
}

vector<vector<int>> permute(vector<int> &arr) {
	vector<int> curr_ans(arr.size());
	set<int> visited;
	_permute(arr, 0, curr_ans, visited);
	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	vector<vector<int>> ans = permute(arr);
	for (auto x : ans) {
		for (int y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}

	return 0;
}