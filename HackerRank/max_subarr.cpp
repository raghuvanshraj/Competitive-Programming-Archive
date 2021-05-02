/**
 *    author:	vulkan
 *    created:	03.09.2019 10:23:29 AM
**/
#include <bits/stdc++.h>

using namespace std;

int kadane(int arr[], int n) {
	int curr_sum = 0, best_sum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		curr_sum += arr[i];
		best_sum = max(best_sum, curr_sum);
		if (curr_sum < 0) {
			curr_sum = 0;
		}
	}

	return best_sum;
}

int max_sum_subsequence(int arr[], int n) {
	int max_sum = 0;
	for (int i = 0; i < n; ++i) {
		max_sum += (arr[i] > 0) ? arr[i] : 0;
	}

	if (max_sum == 0) {
		max_sum = *max_element(arr, arr + n);
	}

	return max_sum;
}

pair<int, int> get_max(int arr[], int n) {
	pair<int, int> ans;
	ans.first = kadane(arr, n);
	ans.second = max_sum_subsequence(arr, n);

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		pair<int, int> ans = get_max(arr, n);
		cout << ans.first << ' ' << ans.second << endl;
	}

	return 0;
}