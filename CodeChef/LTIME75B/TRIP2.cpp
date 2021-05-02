/**
 *    author:	vulkan
 *    created:	31.08.2019 09:08:32 PM
**/
#include <bits/stdc++.h>

using namespace std;

void is_trip_possible(int arr[], int n, int k) {
	if (n == 1) {
		cout << "YES" << endl;
		cout << k << endl;
		return;
	} else if (k == 2) {
		int seq1[n], seq2[n];
		int curr = 1;
		for (int i = 0; i < n; ++i) {
			seq1[i] = curr;
			seq2[i] = (curr == 1) ? 2 : 1;
			curr = seq2[i];
		}

		int i = 0;
		while (arr[i] == -1) {}

		bool is_one = (seq1[i] == arr[i]);
		for (; i < n; ++i) {
			if (arr[i] == -1) {
				continue;
			} else {
				if (is_one) {
					if (seq1[i] != arr[i]) {
						cout << "NO" << endl;
						return;
					}
				} else {
					if (seq2[i] != arr[i]) {
						cout << "NO" << endl;
						return;
					}
				}
			}
		}

		cout << "YES" << endl;
		if (is_one) {
			for (int i = 0; i < n; ++i) {
				cout << seq1[i] << ' ';
			}

			cout << endl;
		} else {
			for (int i = 0; i < n; ++i) {
				cout << seq1[i] << ' ';
			}

			cout << endl;
		}

		return;
	}

	bool is_possible = true;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			if (arr[i] == -1) {
				for (int j = 0; j < k; ++j) {
					if (j + 1 != arr[i + 1]) {
						arr[i] = j + 1;
						break;
					}
				}

				if (arr[i] == -1) {
					is_possible = false;
					break;
				}
			} else if (arr[i] == arr[i + 1]) {
				is_possible = false;
				break;
			}
		} else if (i == n - 1) {
			if (arr[i] == -1) {
				for (int j = 0; j < k; ++j) {
					if (j + 1 != arr[i - 1]) {
						arr[i] = j + 1;
						break;
					}
				}

				if (arr[i] == -1) {
					is_possible = false;
					break;
				}
			} else if (arr[i] == arr[i - 1]) {
				is_possible = false;
				break;
			}
		} else {
			if (arr[i] == -1) {
				for (int j = 0; j < k; ++j) {
					if (j + 1 != arr[i - 1] and j + 1 != arr[i + 1]) {
						arr[i] = j + 1;
						break;
					}
				}

				if (arr[i] == -1) {
					is_possible = false;
					break;
				}
			} else if (arr[i] == arr[i - 1] or arr[i] == arr[i + 1]) {
				is_possible = false;
				break;
			}
		}
	}

	if (is_possible) {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		is_trip_possible(arr, n, k);
	}

	return 0;
}