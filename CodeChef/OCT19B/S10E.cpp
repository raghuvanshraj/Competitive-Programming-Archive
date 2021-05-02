/**
 *    author:	vulkan
 *    created:	12.10.2019 04:22:59 PM
**/
#include <bits/stdc++.h>

using namespace std;

int count_good_prices(int arr[], int n) {
	int count = 0;
	for (int i = 1; i < n; ++i) {
		if (arr[i] < *min_element(arr + max(0, i - 5), arr + i)) {
			count++;
		}
	}

	return count + 1;
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

		cout << count_good_prices(arr, n) << endl;
	}

	return 0;
}