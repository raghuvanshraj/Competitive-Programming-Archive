#include <bits/stdc++.h>

using namespace std;

int majorityElement(const vector<int> &arr) {
	unordered_map<int,int> counts;
	int n = arr.size();
	int majority_count = floor(n/2);
	for (int i = 0; i < n; ++i) {
		int curr_count = ++counts[arr[i]];
		if (curr_count > majority_count) {
			return arr[i];
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

	cout << majorityElement(arr);
	
	return 0;
}