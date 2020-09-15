#include <bits/stdc++.h>

using namespace std;

int minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
	int i = 0, j = 0, k = 0;
	int x = a.size(), y = b.size(), z = c.size();
	int minDiff = INT_MAX;
	while (i < x and j < y and k < z) {
		int minElt = min({a[i], b[j], c[k]});
		int currDiff = max({a[i], b[j], c[k]}) - minElt;
		minDiff = min(currDiff, minDiff);

		if (a[i] == minElt) {
			i++;
		} else if (b[j] == minElt) {
			j++;
		} else {
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

	cout << minimize(a,b,c);
	return 0;
}