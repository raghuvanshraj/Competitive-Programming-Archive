/**
 *    author:	vulkan
 *    created:	19.05.2020 10:47:30 PM
**/
#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &arr) {
	int n = arr.size();
	unordered_map<int, int> mp;
	int ans = 0;
	for (int x : arr) {
		if (mp[x] == 0) {
			mp[x] = mp[x - mp[x - 1]] = mp[x + mp[x + 1]] = mp[x - 1] + mp[x + 1] + 1;
		}

		ans = max(ans, mp[x]);
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

	cout << longestConsecutive(arr);

	return 0;
}