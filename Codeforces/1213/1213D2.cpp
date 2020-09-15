/**
 *    author:	vulkan
 *    created:	30.08.2019 08:52:52 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct elt_t {
	int moves = 0;
	int count = 0;
};

int min_moves(int *arr, int n, int k) {
	sort(arr, arr + n);
	int max_elt = arr[n - 1];
	elt_t *elts = new elt_t[max_elt + 1]();
	for (int i = 0; i < n; ++i) {
		int curr_elt = arr[i];
		int curr_moves = 0;
		while (true) {
			if (elts[curr_elt].count < k) {
				elts[curr_elt].count++;
				elts[curr_elt].moves += curr_moves;
				if (curr_elt == 0) {
					break;
				}
			}

			if (curr_elt == 0) {
				break;
			}

			curr_moves++;
			curr_elt /= 2;
		}
	}

	int best_moves = INT_MAX;
	for (int i = 0; i < max_elt + 1; ++i) {
		if (elts[i].count == k) {
			best_moves = min(best_moves, elts[i].moves);
		}
	}

	return best_moves;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << min_moves(arr, n, k);

	return 0;
}