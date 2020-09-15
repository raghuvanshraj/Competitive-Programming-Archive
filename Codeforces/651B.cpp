#include <bits/stdc++.h>

using namespace std;

int minHappy(int *arr, int n) {
	sort(arr, arr+n);
	int count = 1, maxCount = 1;
	for (int i = 0; i < n-1; ++i) {
		if (arr[i+1] == arr[i]) {
			count++;
		} else {
			count = 1;
		}

		maxCount = max(maxCount, count);
	}

	return n - maxCount;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << minHappy(arr, n);
	return 0;
}