/**
 *    author:	vulkan
 *    created:	07.03.2022 11:02:07 AM
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL naturalNumsSum(LL n) {
	return (n * (n + 1)) / 2;
}

LL segSum(LL l, LL r) {
	return naturalNumsSum(r) - naturalNumsSum(l - 1);
}

LL minimalKSum(vector<int> &arr, int k) {
	sort(arr.begin(), arr.end());
	vector<pair<LL, LL>> segs;
	int n = arr.size();
	if (arr[0] != 1) {
		segs.push_back({1, arr[0] - 1});
	}
	for (int i = 1; i <= n - 1; ++i) {
		if (arr[i] > arr[i - 1] + 1) {
			segs.push_back({arr[i - 1] + 1, arr[i] - 1});
		}
	}

	LL sum = 0LL;
	for (auto seg : segs) {
		LL l = seg.first;
		LL r = min(l + k - 1, seg.second);
		sum += segSum(l, r);
		k -= (r - l + 1);
		if (k == 0) {
			break;
		}
	}

	if (k) {
		LL l = arr[n - 1] + 1;
		LL r = l + k - 1;
		sum += segSum(l, r);
	}

	return sum;
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

	cout << minimalKSum(arr, k);

	return 0;
}