#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &arr, int k) {
	int j = 0;
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		if (arr[i] != k) {
			arr[j++] = arr[i];
		}
	}

	return j;
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

	int size = removeElement(arr, k);
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
	return 0;
}