/**
 *    author:	vulkan
 *    created:	25.08.2019 10:30:53 PM
**/
#include <bits/stdc++.h>
#define MAX 150001

using namespace std;

int max_team(int arr[], int n) {
	sort(arr, arr + n, greater<int>());
	int last = arr[0] + 2, ans = 0;
	for (int i = 0; i < n; ++i) {
		int curr = -1;
		for (int dx = -1; dx < 2; ++dx) {
			if (arr[i] + dx > 0 and arr[i] + dx < last) {
				curr = arr[i] + dx;
			}
		}

		if (curr != -1) {
			last = curr;
			ans++;
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n] = {0};
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << max_team(arr, n);

	return 0;
}