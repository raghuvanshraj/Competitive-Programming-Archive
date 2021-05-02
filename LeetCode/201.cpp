/**
 *    author:	vulkan
 *    created:	23.04.2020 01:33:00 PM
**/
#include <bits/stdc++.h>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
	int shift = 0;
	while (m != n) {
		m >>= 1;
		n >>= 1;
		shift++;
	}

	return n << shift;
}

int main(int argc, char const *argv[]) {
	int m, n;
	cin >> m >> n;

	cout << rangeBitwiseAnd(m, n);

	return 0;
}