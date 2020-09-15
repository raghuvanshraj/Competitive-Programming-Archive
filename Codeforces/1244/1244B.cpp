/**
 *    author:	vulkan
 *    created:	15.10.2019 05:35:38 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int max_rooms = n;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == '1') {
				int curr_ans = max({
					2 * i,
					2 * (n - i + 1),
					n + 1
				});

				max_rooms = max(max_rooms, curr_ans);
			}
		}

		cout << max_rooms << endl;
	}

	return 0;
}