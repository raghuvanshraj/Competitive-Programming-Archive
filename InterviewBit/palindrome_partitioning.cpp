#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {

	int j = s.size()-1;
	int i = 0;
	while (i <= j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}

void _partition(string s, vector<vector<string>> &palindromes, vector<string> &currPalindrome) {
	int n = s.size();
	if (n == 0) {
		palindromes.push_back(currPalindrome);
		return;
	}

	for (int i = 1; i <= n; ++i) {
		string subString = s.substr(0, i);
		if (isPalindrome(subString)) {
			currPalindrome.push_back(subString);
			string remString = s.substr(i);
			_partition(remString, palindromes, currPalindrome);
			currPalindrome.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> palindromes;
	vector<string> currPalindrome;
	_partition(s, palindromes, currPalindrome);
	
	return palindromes;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	vector<vector<string>> palindromes = partition(s);
	for (int i = 0; i < palindromes.size(); ++i) {
		for (int j = 0; j < palindromes[i].size(); ++j) {
			cout << palindromes[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}