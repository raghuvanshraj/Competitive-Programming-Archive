#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &arr) {
	int n = arr.size();
	int l = 0, r = n-1;
	int area = 0;
	while (l < r) {
		area = max(area, min(arr[l], arr[r]) * (r-l));

		if (arr[l] < arr[r]) {
			l++;
		} else {
			r--;
		}
	}

	return area;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << maxArea(arr);
	return 0;
}