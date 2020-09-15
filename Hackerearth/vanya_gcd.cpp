/**
 *    author:	vulkan
 *    created:	28.08.2019 08:03:43 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX_ELT 101

using namespace std;

long increasing_subsequences(int arr[], int n) {
	long **dp = new long*[n]();
	for (int i = 0; i < n; ++i) {
		dp[i] = new long[MAX_ELT]();
		dp[i][arr[i]] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j]) {
				for (int k = 0; k < arr[i] + 1; ++k) {
					dp[i][__gcd(k, arr[i])] = (dp[i][__gcd(k, arr[i])] + dp[j][k]) % MOD;
				}
			}
		}
	}

	long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + dp[i][1]) % MOD;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << increasing_subsequences(arr, n);

	return 0;
}