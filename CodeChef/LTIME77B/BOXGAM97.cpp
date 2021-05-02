/**
 *    author:	vulkan
 *    created:	27.10.2019 09:30:36 AM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, p;
		cin >> n >> k >> p;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		if (k % 2 != 0) {
			if (p == 0) {
				cout << *max_element(arr, arr + n);
			} else {
				cout << *min_element(arr, arr + n);
			}
		} else {
			if (p == 0) {
				vector<int> possible;
				for (int i = 0; i < n; ++i) {
					if (i == 0) {
						possible.push_back(arr[i + 1]);
					} else if (i == n - 1) {
						possible.push_back(arr[i - 1]);
					} else {
						possible.push_back(min({
							arr[i - 1],
							arr[i + 1]
						}));
					}
				}

				cout << *max_element(possible.begin(), possible.end());
			} else {
				vector<int> possible;
				for (int i = 0; i < n; ++i) {
					if (i == 0) {
						possible.push_back(arr[i + 1]);
					} else if (i == n - 1) {
						possible.push_back(arr[i - 1]);
					} else {
						possible.push_back(max({
							arr[i - 1],
							arr[i + 1]
						}));
					}
				}

				cout << *min_element(possible.begin(), possible.end());
			}
		}

		cout << endl;
	}

	return 0;
}