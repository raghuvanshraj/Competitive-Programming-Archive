/**
 *    author:	vulkan
 *    created:	31.08.2019 09:01:22 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a[3], c[3];
		for (int i = 0; i < 3; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < 3; ++i) {
			cin >> c[i];
		}

		bool is_fair = true;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (a[i] > a[j] and c[i] <= c[j]) {
					is_fair = false;
				} else if (a[i] == a[j] and c[i] != c[j]) {
					is_fair = false;
				} else if (a[i] < a[j] and c[i] >= c[j]) {
					is_fair = false;
				}
			}
		}

		string ans = (is_fair) ? "FAIR" : "NOT FAIR";
		cout << ans << endl;
	}

	return 0;
}