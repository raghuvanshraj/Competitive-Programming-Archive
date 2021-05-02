/**
 *    author:	vulkan
 *    created:	03.06.2020 10:50:06 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int> &arr, int k) {
	int n = arr.size();
	int sum = accumulate(arr.begin(), arr.begin() + k - 1, 0);
	vector<int> sums(n - k + 1);
	for (int i = k - 1; i <= n - 1; ++i) {
		sum += arr[i];
		sums[i - k + 1] = sum;
		sum -= arr[i - k + 1];
	}

	for (int i = 0; i <= n - k; ++i) {
		cout << sums[i] << ' ';
	}
	cout << endl;

	vector<int> left(n - k + 1), right(n - k + 1);
	int curr_max = INT_MIN;
	int idx = -1;
	for (int i = 0; i <= n - k; ++i) {
		if (curr_max < sums[i]) {
			curr_max = sums[i];
			idx = i;
		}

		left[i] = idx;
	}

	curr_max = INT_MIN;
	idx = -1;
	for (int i = n - k; i >= 0; --i) {
		if (curr_max <= sums[i]) {
			curr_max = sums[i];
			idx = i;
		}

		right[i] = idx;
	}

	int left_idx = -1, right_idx = -1, middle_idx = -1;
	int ans = INT_MIN;
	for (int i = k; i <= n - 2 * k; ++i) {
		int curr_ans = sums[left[i - k]] + sums[i] + sums[right[i + k]];
		if (ans < curr_ans) {
			left_idx = left[i - k];
			right_idx = right[i + k];
			middle_idx = i;

			ans = curr_ans;
		}
	}

	return {left_idx, middle_idx, right_idx};
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	vector<int> ans = maxSumOfThreeSubarrays(arr, k);
	for (int i = 0; i <= 2; ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}