#include <bits/stdc++.h>

using namespace std;

void _permute(vector<int> &arr, bool *visited, int index, vector<int> &currAns, vector<vector<int>> &ans) {
	int n = arr.size();
	if (index == n) {
		ans.push_back(currAns);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (not visited[i]) {
			visited[i] = true;
			currAns.push_back(arr[i]);
			_permute(arr, visited, index+1, currAns, ans);
			currAns.pop_back();
			visited[i] = false;
		}
	}
}

vector<vector<int>> permute(vector<int> &arr) {
	bool *visited = new bool[arr.size()]();
	vector<int> currAns;
	vector<vector<int>> ans;
	_permute(arr, visited, 0, currAns, ans);

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<vector<int>> perm = permute(arr);
	for (int i = 0; i < perm.size(); ++i) {
		for (int j = 0; j < n; ++j) {
			cout << perm[i][j] << ' ';
		}

		cout << endl;
	}
	return 0;
}