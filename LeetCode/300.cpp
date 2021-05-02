/**
 *    author:	vulkan
 *    created:	28.06.2020 10:39:05 AM
**/
#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int> &arr) {
	int n = arr.size();
	multiset<int> s;
	for (int i = 0; i <= n - 1; ++i) {
		s.insert(arr[i]);
		auto it = s.lower_bound(arr[i]);
		it++;
		if (it != s.end()) {
			s.erase(it);
		}
	}

	return s.size();
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << lengthOfLIS(arr);

	return 0;
}