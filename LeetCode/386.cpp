/**
 *    author:	vulkan
 *    created:	22.01.2022 10:41:56 AM
**/
#include <bits/stdc++.h>

using namespace std;

void _lexicalOrder(vector<int> &ans, int x, int n) {
	if (x > n) {
		return;
	}
	if (x <= n) {
		ans.push_back(x);
	}

	for (int i = 0; i <= 9; ++i) {
		_lexicalOrder(ans, x * 10 + i, n);
	}
}

vector<int> lexicalOrder(int n) {
	vector<int> ans;
	for (int i = 1; i <= 9; ++i) {
		_lexicalOrder(ans, i, n);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	vector<int> ans = lexicalOrder(n);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}