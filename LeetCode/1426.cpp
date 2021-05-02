/**
 *    author:	vulkan
 *    created:	07.04.2020 01:58:37 PM
**/
#include <bits/stdc++.h>

using namespace std;

int countElements(vector<int> &arr) {
	int n = arr.size();
	set<int> elts;
	for (int i = 0; i < n; ++i) {
		elts.insert(arr[i]);
	}

	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (elts.count(arr[i] + 1)) {
			count++;
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << countElements(arr);

	return 0;
}