#include <bits/stdc++.h>

using namespace std;

int trap(const vector<int> &arr) {
	int result = 0, left_max = 0, right_max = 0;
	int n = arr.size();
	int l = 0, h = n-1;
	while (l <= h) {
		if (arr[l] < arr[h]) {
			left_max = max(left_max, arr[l]);
			result += left_max - arr[l];

			l++;
		} else {
			right_max = max(right_max, arr[h]);
			result += right_max - arr[h];

			h--;
		}
	}

	return result;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << trap(arr);
	
	return 0;
}