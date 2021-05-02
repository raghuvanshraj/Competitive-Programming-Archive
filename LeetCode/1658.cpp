/**
 *    author:	raghuvanshraj
 *    created:	17.11.2020 02:11:32
**/
#include <bits/stdc++.h>

using namespace std;

int minOperations(vector<int> &arr, int x) {
	int n = arr.size();
	int i = 0, j = 0;
	int curr = 0;
	int sum = accumulate(arr.begin(), arr.end(), 0) - x;
	int ans = -1;
	while (j < n) {
		if (curr == sum) {
			ans = max(ans, j - i);
		}

		if (curr < sum) {
			curr += arr[j++];
		} else {
			curr -= arr[i++];
		}

		if (i > j) {
			j = i;
			curr = 0;
		}
	}

	while (i < n) {
		if (curr == sum) {
			ans = max(ans, j - i);
		}

		if (curr >= sum) {
			curr -= arr[i++];
		} else {
			break;
		}
	}

	return (ans != -1) ? n - ans : ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int x;
	cin >> x;

	cout << minOperations(arr, x);

	return 0;
}