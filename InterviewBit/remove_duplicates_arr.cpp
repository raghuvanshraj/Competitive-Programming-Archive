#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &arr) {
	int j = 0;
	int n = arr.size();
	for (int i = 0; i < n-1; ++i) {
		if (arr[i+1] != arr[i]) {
			arr[j++] = arr[i];
		}
	}

	arr[j++] = arr[n-1];

	return j;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int size = removeDuplicates(arr);
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
	return 0;
}