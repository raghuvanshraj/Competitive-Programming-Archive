#include <bits/stdc++.h>

using namespace std;

int countPretty(int l, int r) {
	int num = (r - l + 1) / 10;
	int rem = (r - l + 1) % 10;

	int extraCount = 0;
	for (int i = 0; i < rem; ++i) {
		int currNum = l + (10 * num) + i;
		if (currNum % 10 == 2 or
			currNum % 10 == 3 or
			currNum % 10 == 9) {
			extraCount++;
		}
	}

	return (num * 3) + extraCount;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int l,r;
		cin >> l >> r;

		cout << countPretty(l,r) << endl;
	}
	return 0;
}