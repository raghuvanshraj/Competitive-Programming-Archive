/**
 *    author:	vulkan
 *    created:	25.08.2019 03:30:01 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool dance_possible(int *arr, int n) {
	if (n == 1) {
		return true;
	}

	bool is_clockwise;
	if (arr[0] + 1 == arr[1] or (arr[0] == n and arr[1] == 1)) {
		is_clockwise = true;
	} else if (arr[0] - 1 == arr[1] or (arr[0] == 1 and arr[1] == n)) {
		is_clockwise = false;
	}

	// cout << is_clockwise << ' ';

	int start_idx, last_idx;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 1) {
			start_idx = i;
		} else if (arr[i] == n) {
			last_idx = i;
		}
	}

	if (is_clockwise) {
		int i = (start_idx + 1) % n;;
		while (i != (start_idx - 1 + n) % n) {
			int next_idx = (i + 1) % n;
			if (arr[next_idx] != arr[i] + 1) {
				return false;
			}

			i = (i + 1) % n;
		}
	} else if (not is_clockwise) {
		int i = (last_idx + 1) % n;
		while (i != (last_idx - 1 + n) % n) {
			int next_idx = (i + 1) % n;
			if (arr[next_idx] != arr[i] - 1) {
				return false;
			}

			i = (i + 1) % n;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int *arr = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		string ans = (dance_possible(arr, n)) ? "YES" : "NO";
		cout << ans << endl;
	}

	return 0;
}