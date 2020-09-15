/**
 *    author:	vulkan
 *    created:	25.08.2019 08:33:07 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_possible(int *sticks, int m) {
	sort(sticks, sticks + m);
	int prod = sticks[0] * sticks[m - 1];
	int i = 1, j = m - 2;
	while (i < j) {
		if (sticks[i] * sticks[j] == prod) {
			if (sticks[i - 1] == sticks[i] and
			        sticks[j + 1] == sticks[j]) {

				i += 2;
				j -= 2;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;

		int m = 4 * n;
		int *sticks = new int[m]();
		for (int i = 0; i < m; ++i) {
			cin >> sticks[i];
		}

		string ans = (is_possible(sticks, m)) ? "YES" : "NO";
		cout << ans << endl;
	}

	return 0;
}