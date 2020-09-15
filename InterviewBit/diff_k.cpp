#include <bits/stdc++.h>

using namespace std;

int diffPossible(vector<int> &arr, int k) {
	bool found = false;
	int n = arr.size();

	int i = 0, j = 1;
	while (i < n and j < n) {
		int currDiff = arr[j] - arr[i];
		if (currDiff < k) {
			j++;
		} else if (currDiff > k) {
			i++;
		} else {
			return 1;
		}

		if (i >= j) {
			j = i+1;
		}
	}

	return 0;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int k;
	cin >> k;
	cout << diffPossible(arr, k);
	return 0;
}