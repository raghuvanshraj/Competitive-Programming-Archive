/**
 *    author:	vulkan
 *    created:	21.01.2022 09:06:42 PM
**/
#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &arr) {
	int sp = arr[0];
	int fp = arr[arr[0]];
	while (sp != fp) {
		sp = arr[sp];
		fp = arr[arr[fp]];
	}

	fp = 0;
	while (fp != sp) {
		fp = arr[fp];
		sp = arr[sp];
	}

	return sp;
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