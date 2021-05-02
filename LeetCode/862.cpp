/**
 *    author:	vulkan
 *    created:	25.10.2019 08:05:18 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int shortestSubarray(vector<int> &arr, int k) {
	int n = arr.size();
	int prefix[n + 1];
	prefix[0] = 0;
	for (int i = 1; i <= n; ++i) {
		prefix[i] = prefix[i - 1] + arr[i - 1];
	}

	deque<int> monoq;
	int ans = n + 1;
	for (int i = 0; i <= n; ++i) {
		while (not monoq.empty() and prefix[i] <= prefix[monoq.back()]) {
			monoq.pop_back();
		}

		while (not monoq.empty() and prefix[i] >= prefix[monoq.front()] + k) {
			ans = min(ans, i - monoq.front());
			monoq.pop_front();
		}

		monoq.push_back(i);
	}

	return (ans < n + 1) ? ans : -1;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int k;
	cin >> k;

	cout << shortestSubarray(arr, k);

	return 0;
}