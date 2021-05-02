/**
 *    author:	vulkan
 *    created:	12.06.2020 11:41:45 PM
**/
#include <bits/stdc++.h>

using namespace std;

int countTriplets(vector<int> &arr) {
	int n = arr.size();
	map<int, vector<int>> mp;
	mp[0].push_back(-1);
	int curr = 0;
	int ans = 0;
	for (int i = 0; i <= n - 1; ++i) {
		curr ^= arr[i];
		for (int j : mp[curr]) {
			ans += i - j - 1;
		}

		mp[curr].push_back(i);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << countTriplets(arr);

	return 0;
}