/**
 *    author:	vulkan
 *    created:	25.02.2022 10:30:57 AM
**/
#include <bits/stdc++.h>

using namespace std;

int hIndex(vector<int> &arr) {
	int max_elt = *max_element(arr.begin(), arr.end());
	vector<int> cnt(max_elt + 1), atleast(max_elt + 1), atmost(max_elt + 1);
	for (int x : arr) {
		cnt[x]++;
	}

	atmost[0] = cnt[0];
	for (int i = 1; i <= max_elt; ++i) {
		atmost[i] = atmost[i - 1] + cnt[i];
	}

	atleast[max_elt] = cnt[max_elt];
	for (int i = max_elt - 1; i >= 0; --i) {
		atleast[i] = atleast[i + 1] + cnt[i];
	}

	int ans = 0;
	int n = arr.size();
	for (int i = 0; i <= max_elt; ++i) {
		if (atmost[i] >= n - i and atleast[i] >= i) {
			ans = i;
		}
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

	cout << hIndex(arr);

	return 0;
}