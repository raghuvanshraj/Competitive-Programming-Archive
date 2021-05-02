/**
 *    author:	vulkan
 *    created:	04.09.2019 05:05:52 PM
**/
#include <bits/stdc++.h>

using namespace std;

int greedy_coin_change(int elt) {
	int count = elt / 5;
	elt %= 5;
	count += elt / 2;
	elt %= 2;
	count += elt;

	return count;
}

int min_rounds(int arr[], int n) {
	int min_elt = *min_element(arr, arr + n);
	int ans = INT_MAX;
	for (int i = min_elt - 4; i <= min_elt; ++i) {
		int curr_ans = 0;
		for (int j = 0; j < n; ++j) {
			curr_ans += greedy_coin_change(arr[j] - i);
		}

		ans = min(ans, curr_ans);
	}

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

		cout << min_rounds(arr, n) << endl;
	}

	return 0;
}