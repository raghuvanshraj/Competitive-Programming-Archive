#include <bits/stdc++.h>

using namespace std;

int bulbs(vector<int> &arr) {
	int n = arr.size();
	int minToggles = 0;
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if ((arr[i] ^ flag) == 0) {
			arr[i] = 1;
			minToggles++;
			flag = not flag;
		}
	}

	return minToggles;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << bulbs(arr);
	return 0;
}