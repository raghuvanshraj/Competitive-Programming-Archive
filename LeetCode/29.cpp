/**
 *    author:	vulkan
 *    created:	19.01.2022 10:09:03 PM
**/
#include <bits/stdc++.h>

using namespace std;

int divide(int n, int m) {
	bool neg = (n < 0) xor (m < 0);

	n = abs(n);
	m = abs(m);
	int ans = 0;
	while (n > 0) {
		n -= m;
		ans++;
	}
	if (n < 0) {
		ans--;
	}

	return neg ? -ans : ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	cout << divide(n, m);

	return 0;
}