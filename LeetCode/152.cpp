/**
 *    author:	vulkan
 *    created:	05.03.2020 02:44:49 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &arr) {
	int n = arr.size();
	int max_ending_here = 1, min_ending_here = 1, best = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > 0) {
			max_ending_here *= arr[i];
			min_ending_here = min(min_ending_here * arr[i], 1);
		} else if (arr[i] == 0) {
			max_ending_here = 0;
			min_ending_here = 1;
		} else {
			swap(max_ending_here, min_ending_here);
			max_ending_here *= arr[i];
			min_ending_here *= arr[i];
		}

		best = max(best, max_ending_here);

		if (max_ending_here <= 0) {
			max_ending_here = 1;
		}
	}

	return best;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << maxProduct(arr);

	return 0;
}