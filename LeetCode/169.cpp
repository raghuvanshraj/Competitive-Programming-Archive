/**
 *    author:	vulkan
 *    created:	15.01.2022 04:55:04 PM
**/
#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &arr) {
	int n = arr.size();
	int x = 0, cnt = 1;
	for (int i = 1; i <= n - 1; ++i) {
		if (arr[x] == arr[i]) {
			cnt++;
		} else {
			cnt--;
		}

		if (cnt == 0) {
			x = i;
			cnt = 1;
		}
	}

	return arr[x];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << majorityElement(arr);

	return 0;
}