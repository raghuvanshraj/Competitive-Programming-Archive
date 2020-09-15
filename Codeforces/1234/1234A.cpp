/**
 *    author:	vulkan
 *    created:	18.10.2019 04:41:56 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		int sum = accumulate(arr, arr + n, 0);
		if (sum % n == 0) {
			cout << sum / n;
		} else {
			cout << (sum / n) + 1;
		}

		cout << endl;
	}

	return 0;
}