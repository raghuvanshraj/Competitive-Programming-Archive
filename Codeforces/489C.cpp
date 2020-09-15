/**
 *    author:	vulkan
 *    created:	04.09.2019 11:19:52 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_possible(int m, int s) {
	return s >= 0 and s <= 9 * m;
}

string minimize_num(int m, int s) {
	if ((not is_possible(m, s))) {
		return "-1";
	}

	if (s == 0 and m == 1) {
		return "0";
	} else if (s == 0) {
		return "-1";
	}

	string ans = "";
	for (int i = 0; i < m; ++i) {
		for (int d = (i == 0) ? 1 : 0; d < 10; ++d) {
			if (is_possible(m - i - 1, s - d)) {
				ans = ans + to_string(d);
				s -= d;
				break;
			}
		}
	}

	return ans;
}

string maximize_num(int m, int s) {
	if ((not is_possible(m, s))) {
		return "-1";
	}

	if (s == 0 and m == 1) {
		return "0";
	} else if (s == 0) {
		return "-1";
	}

	string ans = "";
	for (int i = 0; i < m; ++i) {
		for (int d = 9; d >= (i == 0) ? 1 : 0; --d) {
			if (is_possible(m - i - 1, s - d)) {
				ans = ans + to_string(d);
				s -= d;
				break;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, s;
	cin >> m >> s;

	string min_num = minimize_num(m, s);
	string max_num = maximize_num(m, s);

	cout << min_num << ' ' << max_num;

	return 0;
}