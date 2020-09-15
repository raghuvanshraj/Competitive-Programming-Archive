#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

int countTriangles(vector<int> &sides) {
	sort(sides.begin(), sides.end());
	int n = sides.size();
	int k = 2;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for
	}

	return triangles.size();
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> sides(n);
	for (int i = 0; i < n; ++i) {
		cin >> sides[i];
	}

	cout << countTriangles(sides);
	return 0;
}