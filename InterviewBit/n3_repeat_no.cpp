/**
 *    author:	vulkan
 *    created:	13.01.2020 04:59:21 PM
**/
#include <bits/stdc++.h>

using namespace std;

int repeatedNumber(const vector<int> &arr) {
	int n = arr.size();
	int first = INT_MAX, second = INT_MAX;
	int count_first = 0, count_second = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == first) {
			count_first++;
		} else if (arr[i] == second) {
			count_second++;
		} else if (count_first == 0) {
			count_first++;
			first = arr[i];
		} else if (count_second == 0) {
			count_second++;
			second = arr[i];
		} else {
			count_first--;
			count_second--;
		}
	}

	count_first = 0;
	count_second = 0;

	for (int i = 0; i < n; ++i) {
		if (arr[i] == first) {
			count_first++;
		} else if (arr[i] == second) {
			count_second++;
		}
	}

	if (count_first > n / 3) {
		return first;
	} else if (count_second > n / 3) {
		return second;
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << repeatedNumber(arr);

	return 0;
}