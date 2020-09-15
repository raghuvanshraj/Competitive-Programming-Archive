#include <bits/stdc++.h>

using namespace std;

void _combine(vector<int> &arr, int start, vector<vector<int>> &combinations, vector<int> &currCombination, bool *visited, int k) {
	if (k == 0) {
		combinations.push_back(currCombination);
		return;
	}
	
	int n = arr.size();
	for (int i = start; i < n; ++i) {
		if (not visited[i]) {
			visited[i] = true;
			currCombination.push_back(arr[i]);
			_combine(arr, i+1, combinations, currCombination, visited, k-1);
			currCombination.pop_back();
			visited[i] = false;
		}
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = i+1;
	}
	vector<vector<int>> combinations;
	if (k == 0) {
		return combinations;
	}
	vector<int> currCombination;
	bool *visited = new bool[n]();
	_combine(arr, 0, combinations, currCombination, visited, k);

	return combinations;
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> combinations = combine(n, k);
	for (int i = 0; i < combinations.size(); ++i) {
		for (int j = 0; j < combinations[i].size(); ++j) {
			cout << combinations[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}