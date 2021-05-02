/**
 *    author:	vulkan
 *    created:	26.10.2019 08:22:59 PM
**/
#include <bits/stdc++.h>

using namespace std;

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

		sort(arr, arr + n);
		int x = (arr[n / 4] > arr[n / 4 - 1]) ? arr[n / 4] : -1;
		int y = (arr[n / 2] > arr[n / 2 - 1]) ? arr[n / 2] : -1;
		int z = (arr[3 * (n / 4)] > arr[3 * (n / 4) - 1]) ? arr[3 * (n / 4)] : -1;

		if (x != -1 and y != -1 and z != -1 and x != y and y != z) {
			cout << x << ' ' << y << ' ' << z << endl;
		} else {
			cout << "-1" << endl;
		}
	}

	return 0;
}