/**
 *    author:	vulkan
 *    created:	25.03.2020 01:33:17 AM
**/
#include <bits/stdc++.h>

using namespace std;

int fourSumCount(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d) {
	sort(d.begin(), d.end());
	int n = a.size();
	map<int, int> counts;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			counts[a[i] + b[j]]++;
		}
	}

	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			count += counts[-(c[i] + d[j])];
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	cout << fourSumCount(a, b, c, d);

	return 0;
}
