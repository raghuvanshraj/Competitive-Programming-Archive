#include <bits/stdc++.h>

using namespace std;

vector<string> keypad = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void _letterCombinations(string num, int pos, vector<string> &result) {
	if (pos == num.size()) {
		return;
	}

	int index = num[pos] - '0';
 	vector<string> newResult;
	for (int i = 0; i < result.size(); ++i) {
		string curr = result[i];
		for (int i = 0; i < keypad[index].size(); ++i) {
			newResult.push_back(curr + keypad[index].substr(i, 1));
		}
	}

	result = newResult;

	_letterCombinations(num, pos+1, result);
}

vector<string> letterCombinations(string num) {
	vector<string> result;
	result.push_back("");
	_letterCombinations(num, 0, result);
	return result;
}

int main(int argc, char const *argv[]) {
	string num;
	cin >> num;
	vector<string> ans = letterCombinations(num);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}