/**
 *    author:	vulkan
 *    created:	18.01.2022 01:13:19 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void _subsets(vector<int> &arr, int idx, vector<int> &curr_ans) {
	if (idx == arr.size()) {
		ans.push_back(curr_ans);
		return;
	}

	_subsets(arr, idx + 1, curr_ans);
	curr_ans.push_back(arr[idx]);
	_subsets(arr, idx + 1, curr_ans);
	auto it = --curr_ans.end();
	curr_ans.erase(it);
}

vector<vector<int>> subsets(vector<int> &arr) {
	int n = arr.size();
	vector<int> curr_ans;
	_subsets(arr, 0, curr_ans);

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	vector<vector<int>> ans = subsets(arr);
	for (auto x : ans) {
		for (int y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}

	return 0;
}