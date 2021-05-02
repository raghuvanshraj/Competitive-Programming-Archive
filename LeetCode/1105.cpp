/**
 *    author:	vulkan
 *    created:	18.04.2020 12:29:50 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minHeightShelves(vector<vector<int>> &books, int shelf_width) {
	int n = books.size();
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int curr_height = 0, curr_width = 0;
		for (int j = i - 1; j >= 0; --j) {
			curr_height = max(curr_height, books[j][1]);
			curr_width += books[j][0];
			if (curr_width > shelf_width) {
				break;
			}

			dp[i] = min(dp[i], dp[j] + curr_height);
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> books(n, vector<int>(2));
	for (int i = 0; i <= n - 1; ++i) {
		cin >> books[i][0] >> books[i][1];
	}

	int shelf_width;
	cin >> shelf_width;

	cout << minHeightShelves(books, shelf_width);

	return 0;
}