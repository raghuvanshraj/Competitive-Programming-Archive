/**
 *    author:	vulkan
 *    created:	30.08.2019 08:44:01 PM
**/
#include <bits/stdc++.h>

using namespace std;

int min_cost(int *arr, int n) {
	int best_cost = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int curr_cost = 0;
		for (int j = 0; j < n; ++j) {
			if (abs(arr[i] - arr[j]) % 2 == 0) {
				continue;
			} else {
				curr_cost++;
			}
		}

		best_cost = min(best_cost, curr_cost);
	}

	return best_cost;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << min_cost(arr, n);

	return 0;
}