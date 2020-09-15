#include <bits/stdc++.h>

using namespace std;

int mice(vector<int> &arr, vector<int> &holes) {
	sort(arr.begin(), arr.end());
	sort(holes.begin(), holes.end());

	int maxDifference = 0;
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		maxDifference = max(maxDifference, abs(arr[i] - holes[i]));
	}

	return maxDifference;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n), holes(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> holes[i];
	}

	cout << mice(arr, holes);
	return 0;
}