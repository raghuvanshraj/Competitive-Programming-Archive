/**
 *    author:	vulkan
 *    created:	01.06.2020 06:41:57 PM
**/
#include <bits/stdc++.h>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &arr, int k) {
	int n = arr.size();
	int i = 0, j = 0;
	int curr = arr[0];
	int count = 0;
	while (j < n - 1) {
		if (curr < k) {
			count += j - i + 1;
			curr *= arr[++j];
		} else if (curr >= k) {
			if (i == j) {
				i++;
				j++;
				curr = arr[i];
			} else {
				curr /= arr[i++];
			}
		}
	}

	while (i < n and curr >= k) {
		curr /= arr[i++];
	}

	count += j - i + 1;

	return count;
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << numSubarrayProductLessThanK(arr, k);

	return 0;
}