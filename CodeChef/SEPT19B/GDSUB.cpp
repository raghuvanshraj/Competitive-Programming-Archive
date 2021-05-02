/**
 *    author:	vulkan
 *    created:	07.09.2019 11:19:29 AM
**/
#include <bits/stdc++.h>
#define MAX_ELT 100001
#define MOD 1000000007

using namespace std;

long non_duplicate_subsequences(vector<int> &arr, int *counts, int k) {
	int n = arr.size();

	long **dp = new long*[n + 1]();
	for (int i = 0; i < n + 1; ++i) {
		dp[i] = new long[k + 1]();
	}

	for (int i = 0; i < n + 1; ++i) {
		dp[i][0] = 1;
	}

	for (int i = 0; i < k + 1; ++i) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < k + 1; ++j) {
			dp[i][j] = (((long)counts[arr[i - 1]] * dp[i - 1][j - 1]) % MOD + dp[i - 1][j]) % MOD;
		}
	}

	return dp[n][k];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int *counts = new int[MAX_ELT]();
	vector<int> unique_arr;
	for (int i = 0; i < n; ++i) {
		int elt;
		cin >> elt;
		if (counts[elt] == 0) {
			unique_arr.push_back(elt);
		}

		counts[elt]++;
	}

	cout << non_duplicate_subsequences(unique_arr, counts, k) << endl;

	return 0;
}