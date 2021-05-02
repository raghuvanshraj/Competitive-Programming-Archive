/**
 *    author:	vulkan
 *    created:	07.06.2020 11:22:11 AM
**/
#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &arr) {
	int n = arr.size();
	for (int i = 0; i <= n - 1; ++i) {
		int x = abs(arr[i]) - 1;
		if (arr[x] > 0) {
			arr[x] *= -1;
		} else {
			return x + 1;
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << findDuplicate(arr);

	return 0;
}