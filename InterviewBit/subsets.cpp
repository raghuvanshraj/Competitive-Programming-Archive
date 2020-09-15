#include <bits/stdc++.h>

using namespace std;

void _subsets(vector<int> &arr, int pos, vector<vector<int>> &subsetsArr) {
	if (pos == arr.size()) {
		return;
	}

	int n = subsetsArr.size();
	for (int i = 0; i < n; ++i) {
		vector<int> curr = subsetsArr[i];
		curr.push_back(arr[pos]);
		subsetsArr.push_back(curr);
	}

	_subsets(arr, pos+1, subsetsArr);
}

vector<vector<int>> subsets(vector<int> &arr) {
	vector<vector<int>> subsetsArr;
	vector<int> empty;
	subsetsArr.push_back(empty);
	sort(arr.begin(), arr.end());
	_subsets(arr, 0, subsetsArr);

	sort(subsetsArr.begin(), subsetsArr.end());

	return subsetsArr;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<vector<int>> subsetsArr = subsets(arr);
	for (int i = 0; i < subsetsArr.size(); ++i) {
		for (int j = 0; j < subsetsArr[i].size(); ++j) {
			cout << subsetsArr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
