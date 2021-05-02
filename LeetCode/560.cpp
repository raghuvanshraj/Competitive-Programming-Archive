/**
 *    author:	vulkan
 *    created:	22.04.2020 02:28:38 PM
**/
#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &arr, int k) {
	int n = arr.size();
	map<int, int> counts;
	counts[0]++;
	int ans = 0;
	int presum = 0;
	for (int i = 0; i <= n - 1; ++i) {
		presum += arr[i];
		ans += counts[presum - k];
		counts[presum]++;
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
	int k;
	cin >> k;

	cout << subarraySum(arr, k);

	return 0;
}