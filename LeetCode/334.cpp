/**
 *    author:	vulkan
 *    created:	25.03.2020 09:52:57 AM
**/
#include <bits/stdc++.h>

using namespace std;

bool increasingTriplet(vector<int> &arr) {
	int n = arr.size();
	int a = -1, b = -1, c = -1, d = -1;
	for (int i = 1; i < n; ++i) {
		if (arr[i] > arr[i - 1]) {
			if (b == -1) {
				b = arr[i];
				a = arr[i - 1];
			} else if (c == -1) {
				d = arr[i];
				c = arr[i - 1];

				if (c > b or d > b or c > a) {
					return true;
				} else {
					a = c;
					b = d;
					c = -1;
					d = -1;
				}
			}
		}
	}

	return false;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << increasingTriplet(arr);

	return 0;
}