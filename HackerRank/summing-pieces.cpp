/**
 *    author:	vulkan
 *    created:	04.09.2019 06:31:01 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<long> get_pieces(long arr[], int n, int pos, pair<bool, vector<long>> dp[]) {
	// if (pos == n) {
	// 	return {0};
	// }

	// if (dp[pos].first) {
	// 	return dp[pos].second;
	// }

	// int curr_sum = 0;
	// vector<long> ans;
	// for (int i = pos; i < n; ++i) {
	// 	curr_sum += arr[i];
	// 	vector<long> sub_ans = get_pieces(arr, n, i+1, dp);
	// 	int m = sub_ans.size();
	// 	for (int j = 0; j < m; ++j) {
	// 		ans.push_back(((curr_sum * (i - pos + 1)) % MOD + sub_ans[j]) % MOD);
	// 	}
	// }

	// dp[pos].first = true;
	// return dp[pos].second = ans;


}

long sum_pieces(long arr[], int n) {
	pair<bool, vector<long>> *dp = new pair<bool, vector<long>>[n]();

	vector<long> pieces = get_pieces(arr, n, 0, dp);
	long ans = 0;
	int m = pieces.size();
	for (int i = 0; i < m; ++i) {
		ans = (ans + pieces[i]) % MOD;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	long arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << sum_pieces(arr, n);

	return 0;
}