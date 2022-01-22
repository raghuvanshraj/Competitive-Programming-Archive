/**
 *    author:	vulkan
 *    created:	20.01.2022 11:31:53 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> countSmaller(vector<int> &arr) {
	int n = arr.size();
	multiset<int> s;
	vector<int> cnt(n);
	for (int i = n - 1; i >= 0; --i) {
		s.insert(arr[i]);
		auto it = s.lower_bound(arr[i]);
		if (it != s.end()) {
			cnt[i] = distance(s.begin(), it);
		}
	}

	return cnt;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	vector<int> ans = countSmaller(arr);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}