/**
 *    author:	vulkan
 *    created:	12.09.2019 12:38:21 AM
**/
#include <bits/stdc++.h>
#define MAX_K 1000001

using namespace std;

long count_ranges(int arr[], int n, int k) {

}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;

		cout << count_ranges(arr, n, k) << endl;
	}

	return 0;
}