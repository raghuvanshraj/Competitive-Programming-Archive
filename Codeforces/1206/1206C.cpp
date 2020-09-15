/**
 *    author:	vulkan
 *    created:	24.08.2019 01:15:03 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		vector<int> arrangement;
		int curr_odd = 1, curr_even = 2 * n;
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				arrangement.push_back(curr_odd);
				curr_odd += 2;
			} else {
				arrangement.push_back(curr_even);
				curr_even -= 2;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				arrangement.push_back(arrangement[i] + 1);
			} else {
				arrangement.push_back(arrangement[i] - 1);
			}
		}

		for (int i = 0; i < arrangement.size(); ++i) {
			cout << arrangement[i] << ' ';
		}

	}

	return 0;
}