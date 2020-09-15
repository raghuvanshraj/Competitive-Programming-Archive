/**
 *    author:	vulkan
 *    created:	01.09.2019 07:43:54 PM
**/
#include <bits/stdc++.h>

using namespace std;

long max_profit(long arr[][2], long n, long x) {
	long profits[n][2];
	profits[0][0] = arr[0][0];
	profits[0][1] = arr[0][1];
	for (long i = 1; i < n; ++i) {
		profits[i][0] = arr[i][0] + max(profits[i - 1][0], profits[i - 1][1] - x);
		profits[i][1] = arr[i][1] + max(profits[i - 1][1], profits[i - 1][0] - x);
	}

	return max(profits[n - 1][0], profits[n - 1][1]);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long n, x;
	cin >> n >> x;
	long arr[n][2];
	for (long i = 0; i < 2; ++i) {
		for (long j = 0; j < n; ++j) {
			cin >> arr[j][i];
		}
	}

	cout << max_profit(arr, n, x);

	return 0;
}