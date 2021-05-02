/**
 *    author:	vulkan
 *    created:	01.06.2020 07:12:53 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maximum_subarray_sum(vector<int> &arr, bool contain_one = true) {
	int n = arr.size();
	int best = (contain_one) ? INT_MIN : 0;
	int sum = 0;
	for (int i = 0; i <= n - 1; ++i) {
		sum = max(arr[i], sum + arr[i]);
		best = max(best, sum);
	}

	return best;
}

int minimum_subarray_sum(vector<int> &arr, bool contain_one = true) {
	int n = arr.size();
	int best = INT_MAX;
	int sum = 0;
	for (int i = 0; i <= n - 1; ++i) {
		sum = min(arr[i], sum + arr[i]);
		best = min(best, sum);
	}

	if (contain_one) {
		return min(best, *min_element(arr.begin(), arr.end()));
	}

	return best;
}

int maxSubarraySumCircular(vector<int> &arr) {
	bool pos_found = false;
	for (int x : arr) {
		if (x >= 0) {
			pos_found = true;
			break;
		}
	}

	if (not pos_found) {
		return *max_element(arr.begin(), arr.end());
	}

	int sum = accumulate(arr.begin(), arr.end(), 0);
	return max(maximum_subarray_sum(arr), sum - minimum_subarray_sum(arr));
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << maxSubarraySumCircular(arr);

	return 0;
}