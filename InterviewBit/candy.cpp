#include <bits/stdc++.h>

using namespace std;

int candy(vector<int> &arr) {
	int n = arr.size();
	vector<int> candies(n,1);
	for (int i = 1; i < n; ++i) {
		if (arr[i] > arr[i-1]) {
			candies[i] = candies[i-1] + 1;
		}
	}

	for (int i = n-2; i >= 0; --i) {
		if (arr[i] > arr[i+1]) {
			if (candies[i] <= candies[i+1]) {
				candies[i] = candies[i+1] + 1;
			}
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	cout << candies[i] << ' ';
	// }

	// cout << endl << endl;

	return accumulate(candies.begin(), candies.end(), 0);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << candy(arr);
	return 0;
}