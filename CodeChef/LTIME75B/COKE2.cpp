/**
 *    author:	vulkan
 *    created:	31.08.2019 09:28:28 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct coke_t {
	int c = 0;
	int p = 0;
};

bool comp(coke_t a, coke_t b) {
	return a.p < b.p;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, q, k, l, r;
		cin >> n >> q >> k >> l >> r;
		coke_t *cans = new coke_t[n]();
		for (int i = 0; i < n; ++i) {
			cin >> cans[i].c >> cans[i].p;
		}

		// for (int i = 0; i < n; ++i) {
		// 	cout << cans[i].c << ' ' << cans[i].p << endl;
		// }

		sort(cans, cans + n, comp);
		for (int i = 0; i < q; ++i) {
			bool is_possible = false;
			for (int j = 0; j < n; ++j) {
				if (cans[j].c > k) {
					int final_temp = max(cans[j].c - i - 1, k);
					if (final_temp >= l and final_temp <= r) {
						is_possible = true;
						cout << cans[j].p << ' ';
						break;
					}
				} else if (cans[j].c < k) {
					int final_temp = min(cans[j].c + i + 1, k);
					if (final_temp >= l and final_temp <= r) {
						is_possible = true;
						cout << cans[j].p << ' ';
						break;
					}
				} else {
					if (cans[j].c >= l and cans[j].c <= r) {
						is_possible = true;
						cout << cans[j].p << ' ';
						break;
					}
				}
			}

			if (not is_possible) {
				cout << "-1" << ' ';
			}
		}

		cout << endl;
	}

	return 0;
}