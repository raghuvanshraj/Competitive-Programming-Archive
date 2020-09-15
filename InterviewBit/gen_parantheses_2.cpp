#include <bits/stdc++.h>

using namespace std;

void _generateParenthesis(vector<string> &result, int opening, int closing, int n, string currString) {
	if (n < 0) {
		return;
	}
	if (n == 0) {
		if (opening == closing) {
			result.push_back(currString);
		}

		return;
	}

	_generateParenthesis(result, opening+1, closing, n-1, currString + "(");
	if (opening > closing) {
		_generateParenthesis(result, opening, closing+1, n-1, currString + ")");
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	_generateParenthesis(result, 0, 0, 2*n, "");

	return result;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> result = generateParenthesis(n);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	return 0;
}