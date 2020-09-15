#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, vector<int> &b, vector<int> &c) {
	int i = 0, j = 0, k = 0;
	int minDiff = INT_MAX;

	int x = a.size(), y = b.size(), z = c.size();
	while (i < x and j < y and k < z) {
		int minX = min({a[i], b[j], c[k]});
		int maxX = max({a[i], b[j], c[k]});

		minDiff = min(minDiff, maxX - minX);

		if (a[i] == minX) {
			i++;
		} else if (b[j] == minX) {
			j++;
		} else if (c[k] == minX) {
			k++;
		}
	}

	return minDiff;
}

int main(int argc, char const *argv[]) {
	int x,y,z;
	cin >> x >> y >> z;
	vector<int> a(x), b(y), c(z);
	for (int i = 0; i < x; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < y; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < z; ++i) {
		cin >> c[i];
	}

	cout << solve(a,b,c);
	return 0;
}