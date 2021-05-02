/**
 *    author:	vulkan
 *    created:	10.03.2020 12:53:21 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool operator<(vector<int> &a, vector<int> &b) {
	return ((a[0] < b[0]) and (a[1] < b[1]));
}

int maxEnvelopes(vector<vector<int>> envelopes) {
	sort(envelopes.begin(), envelopes.end());

	int n = envelopes.size();
	if (n == 0) {
		return 0;
	}

	vector<int> dp(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (envelopes[j] < envelopes[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> envelopes(n, vector<int>(2));
	for (int i = 0; i < n; ++i) {
		cin >> envelopes[i][0] >> envelopes[i][1];
	}

	cout << maxEnvelopes(envelopes);

	return 0;
}