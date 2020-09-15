#include <bits/stdc++.h>

using namespace std;

void _combinationSum(vector<int> candidateSet, int start, vector<int> &currCombination, set<vector<int>> &combinations, int sum) {
	int n = candidateSet.size();
	if (sum == 0) {
		combinations.insert(currCombination);
		return;
	}
	if (sum < 0) {
		return;
	}
	if (start == n) {
		return;
	}

	currCombination.push_back(candidateSet[start]);
	_combinationSum(candidateSet, start+1, currCombination, combinations, sum - candidateSet[start]);
	currCombination.pop_back();
	_combinationSum(candidateSet, start+1, currCombination, combinations, sum);
}

vector<vector<int>> combinationSum(vector<int> &candidateSet, int sum) {
	set<vector<int>> combinations;
	vector<int> currCombination;
	sort(candidateSet.begin(), candidateSet.end());
	_combinationSum(candidateSet, 0, currCombination, combinations, sum);
	
	vector<vector<int>> vectorCombinations;
	for (auto it = combinations.begin(); it != combinations.end(); it++) {
		vectorCombinations.push_back(*it);
	}	
	return vectorCombinations;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> candidateSet(n);
	for (int i = 0; i < n; ++i) {
		cin >> candidateSet[i];
	}

	int sum;
	cin >> sum;
	vector<vector<int>> combinations = combinationSum(candidateSet, sum);
	for (int i = 0; i < combinations.size(); ++i) {
		for (int j = 0; j < combinations[i].size(); ++j) {
			cout << combinations[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}