/**
 *    author:	vulkan
 *    created:	13.04.2020 07:55:04 PM
**/
#include <bits/stdc++.h>

using namespace std;

int findMaxLength(vector<int> &arr) {
	int n = arr.size();
	replace(arr.begin(), arr.end(), 0, -1);
	vector<int> prefix(n + 1);
	map<int, int> mp;
	mp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		prefix[i] = prefix[i - 1] + arr[i - 1];
		if (not mp.count(prefix[i])) {
			mp[prefix[i]] = i;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, i - mp[prefix[i]]);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << findMaxLength(arr);

	return 0;
}