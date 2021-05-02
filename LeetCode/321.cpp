/**
 *    author:	vulkan
 *    created:	08.03.2020 03:55:44 PM
**/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// static bool comp(string a, string b) {
// 	if (a.size() != b.size()) {
// 		return a.size() < b.size();
// 	} else {
// 		return a < b;
// 	}
// }

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
	int n = nums1.size(), m = nums2.size();

	vector<vector<vector<ull>>> dp(n + 1, vector<vector<ull>>(m + 1, vector<ull>(k + 1)));

	for (int i = 1; i < n + 1; ++i) {
		for (int l = 1; l <= min(i, k); ++l) {
			dp[i][0][l] = max({
				dp[i - 1][0][l - 1] * (ull)10 + (ull)nums1[i - 1],
				dp[i - 1][0][l]
			});
		}
	}

	for (int i = 1; i < m + 1; ++i) {
		for (int l = 1; l <= min(i, k); ++l) {
			dp[0][i][l] = max({
				dp[0][i - 1][l - 1] * (ull)10 + (ull)nums2[i - 1],
				dp[0][i - 1][l]
			});
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			int both;
			if (nums1[i - 1] > nums2[j - 1]) {
				both = nums1[i - 1] * 10 + nums2[j - 1];
			} else {
				both = nums2[j - 1] * 10 + nums1[i - 1];
			}

			for (int l = 1; l <= min(i + j, k); ++l) {
				dp[i][j][l] = max({
					dp[i - 1][j][l - 1] * (ull)10 + (ull)nums1[i - 1],
					dp[i][j - 1][l - 1] * (ull)10 + (ull)nums2[j - 1],
					dp[i - 1][j][l],
					dp[i][j - 1][l],
					dp[i - 1][j - 1][l]
				});

				if (l > 1) {
					dp[i][j][l] = max({
						dp[i][j][l],
						dp[i - 1][j - 1][l - 2] * (ull)100 + (ull)both
					});
				}
			}
		}
	}

	vector<int> ans;
	ull int_ans = dp[n][m][k];
	while (int_ans) {
		ans.push_back(int_ans % 10);
		int_ans /= 10;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> nums1(n), nums2(m);
	for (int i = 0; i < n; ++i) {
		cin >> nums1[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> nums2[i];
	}

	int k;
	cin >> k;

	vector<int> ans = maxNumber(nums1, nums2, k);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}

	// string a = "652", b = "654";
	// cout << max(a,b);

	return 0;
}