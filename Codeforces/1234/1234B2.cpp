/**
 *    author:	vulkan
 *    created:	18.10.2019 04:54:09 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int arr[n];
	map<int, int> last_idx;
	int *final = new int[n]();
	int j = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int curr_last_idx = last_idx[arr[i]];
		if (curr_last_idx == 0 or curr_last_idx < j - k + 1) {
			final[j++] = arr[i];
			last_idx[arr[i]] = j;
		}
	}

	int size = (j > k) ? k : j;
	cout << size << endl;
	for (int i = j - 1; i >= j - size; --i) {
		cout << final[i] << ' ';
	}

	return 0;
}