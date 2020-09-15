/**
 *    author:	vulkan
 *    created:	19.10.2019 01:19:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int s[m];
	for (int i = 0; i < m; ++i) {
		cin >> s[i];
	}

	sort(s, s + m);

	int i = 0, j = 0;
	while (i < n and j < m) {
		if (s[j] < a[i]) {
			cout << s[j++] << ' ';
		} else {
			cout << a[i++] << ' ';
		}
	}

	while (i < n) {
		cout << a[i++] << ' ';
	}

	while (j < m) {
		cout << s[j++] << ' ';
	}

	return 0;
}