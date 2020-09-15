/**
 *    author:	vulkan
 *    created:	13.01.2020 02:44:32 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int hammingDistance(const vector<int> arr) {
	int n = arr.size();
	long bit_set_count[64];
	fill(bit_set_count, bit_set_count + 64, 0);

	for (int i = 0; i < n; ++i) {
		int j = 0;
		int curr_elt = arr[i];
		while (curr_elt > 0) {
			bit_set_count[j] = (bit_set_count[j] + (long)(curr_elt & 1)) % MOD;
			curr_elt >>= 1;
			j++;
		}
	}

	long ans = 0;
	for (int i = 0; i < 64; ++i) {
		ans = (ans + (long)(bit_set_count[i] * (n - bit_set_count[i]) * 2)) % MOD;
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

	cout << hammingDistance(arr);

	return 0;
}