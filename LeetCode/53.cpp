/**
 *    author:	vulkan
 *    created:	03.04.2020 01:45:36 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &arr) {
	int n = arr.size();
	int sum = 0, best = INT_MIN;
	for (int i = 0; i < n; ++i) {
		sum = max(arr[i], sum + arr[i]);
		best = max(sum, best);
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

	cout << maxSubArray(arr);

	return 0;
}