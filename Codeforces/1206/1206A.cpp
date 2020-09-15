/**
 *    author:	vulkan
 *    created:	24.08.2019 12:17:29 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int *a = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int m;
	cin >> m;
	int *b = new int[m]();
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	cout << *max_element(a, a + n) << ' ' << *max_element(b, b + m);

	return 0;
}