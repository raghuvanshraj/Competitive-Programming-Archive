/**
 *    author:	vulkan
 *    created:	25.08.2019 11:42:17 AM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int t_n = 0; t_n < t; ++t_n) {
		int d, s;
		cin >> d >> s;
		pair<int, int> *slots = new pair<int, int>[s]();
		long c_sum = 0, e_sum = 0;
		double ratio = -1;
		bool ratio_const = true;
		for (int i = 0; i < s; ++i) {
			cin >> slots[i].first >> slots[i].second;
			c_sum += (long)slots[i].first;
			e_sum += (long)slots[i].second;

			if (ratio == -1 or (slots[i].first / (double)slots[i].second) == ratio) {
				ratio = (slots[i].first / (double)slots[i].second);
			} else {
				ratio_const = false;
			}
		}

		cout << "Case #" << t_n + 1 << ": ";
		pair<int, int> *req = new pair<int, int>[d]();
		for (int i = 0; i < d; ++i) {
			cin >> req[i].first >> req[i].second;
			if (c_sum < req[i].first or e_sum < req[i].second) {
				cout << "N";
			} else {
				cout << "Y";
			}
		}

		cout << endl;
	}

	return 0;
}