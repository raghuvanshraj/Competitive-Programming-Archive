#include <bits/stdc++.h>

using namespace std;

void _subsetsWithDup(vector<int> arr, int pos, vector<int> &currSubset, set<vector<int>> &subsets) {
	if (pos == arr.size()) {
		subsets.insert(currSubset);
		return;
	}

	currSubset.push_back(arr[pos]);
	_subsetsWithDup(arr, pos+1, currSubset, subsets);
	currSubset.pop_back();
	_subsetsWithDup(arr, pos+1, currSubset, subsets);
}

vector<vector<int>> subsetsWithDup(vector<int> &arr) {
	set<vector<int>> subsets;
	vector<int> currSubset;
	sort(arr.begin(), arr.end());
	_subsetsWithDup(arr, 0, currSubset, subsets);

	vector<vector<int>> vectorSubsets;
	for (auto it = subsets.begin(); it != subsets.end(); it++) {
		vectorSubsets.push_back(*it);
	}

	return vectorSubsets;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<vector<int>> subsets = subsetsWithDup(arr);
	for (int i = 0; i < subsets.size(); ++i) {
		for (int j = 0; j < subsets[i].size(); ++j) {
			cout << subsets[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}