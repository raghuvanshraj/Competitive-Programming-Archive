#include <bits/stdc++.h>

using namespace std;

string possibleSumK(int *arr, int n, int k) {
	bool dp[k+1];
	memset(dp, false, sizeof(bool) * (k+1));
	dp[0] = true;

	for (int i = 0; i < n; ++i) {
		for (int j = k; j >= arr[i]; --j) {
			dp[j] = dp[j-arr[i]] or dp[j];
		}
	}

	return (dp[k]) ? "Yes" : "No";
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int k;
	cin >> k;

	cout << possibleSumK(arr, n, k);
	return 0;
}