/**
 *    author:	vulkan
 *    created:	13.01.2020 02:00:17 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> getRow(int k) {
	vector<int> ans;
	ans.push_back(1);
	for (int i = 1; i <= k; ++i) {
		ans.push_back(ans[i - 1] * (k - i + 1) / i);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int k;
	cin >> k;

	vector<int> ans = getRow(k);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}