/**
 *    author:	vulkan
 *    created:	26.10.2019 12:38:51 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int training(int arr[], int n, int p) {
	sort(arr, arr + n, greater<int>());
	int prefix[n + 1];
	prefix[0] = 0;
	for (int i = 0; i < n; ++i) {
		prefix[i + 1] = prefix[i] + arr[i];
	}

	int ans = INT_MAX;
	for (int i = 0; i < n - p + 1; ++i) {
		int curr_ans = (p * arr[i]) - (prefix[i + p] - prefix[i]);
		ans = min(curr_ans, ans);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, p;
		cin >> n >> p;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << "Case #" << i + 1 << ": " << training(arr, n, p) << endl;
	}

	return 0;
}