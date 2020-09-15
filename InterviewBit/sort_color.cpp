#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &arr) {
	int i = 0;
	int n = arr.size();
	for (int x = 0; x < n; ++x) {
		if (arr[x] == 0) {
			swap(arr[i++], arr[x]);
		}
	}
	for (int x = i; x < n; ++x) {
		if (arr[x] == 1) {
			swap(arr[i++], arr[x]);
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sortColors(arr);
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << ' ';
	}
	return 0;
}