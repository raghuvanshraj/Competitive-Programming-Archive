/**
 *    author:	vulkan
 *    created:	14.01.2022 12:46:40 PM
**/
#include <bits/stdc++.h>

using namespace std;

int next_idx(int x, int k, int n) {
	return (x + k) % n;
}

void rotate(vector<int> &arr, int k) {
	int vis = 0;
	int n = arr.size();
	for (int i = 0; i <= n - 1; ++i) {
		int j = i;
		int x = arr[i];
		do {
			int y = arr[next_idx(j, k, n)];
			arr[next_idx(j, k, n)] = x;
			x = y;

			j = next_idx(j, k, n);
		} while (j != i);
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int k;
	cin >> k;

	rotate(arr, k);

	for (int x : arr) {
		cout << x << ' ';
	}

	return 0;
}