/**
 *    author:	vulkan
 *    created:	19.05.2020 08:19:14 PM
**/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr, int k) {
	int n = arr.size();
	int i = 0, j = 0;
	map<int, int> counts;
	int ans = 0;
	while (j < n) {
		if (counts.size() <= k) {
			ans += j - i;
			counts[arr[j++]]++;
		} else {
			if (counts.count(arr[i])) {
				counts[arr[i]]--;
				if (counts[arr[i]] == 0) {
					counts.erase(arr[i]);
				}
			}

			i++;
		}
	}

	while (i < n and counts.size() > k) {
		if (counts.count(arr[i])) {
			counts[arr[i]]--;
			if (counts[arr[i]] == 0) {
				counts.erase(arr[i]);
			}
		}

		i++;
	}

	ans += j - i;

	return ans;
}

int subarraysWithKDistinct(vector<int> &arr, int k) {
	return solve(arr, k) - solve(arr, k - 1);
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << subarraysWithKDistinct(arr, k);

	return 0;
}