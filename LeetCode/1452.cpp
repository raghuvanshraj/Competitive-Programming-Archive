/**
 *    author:	vulkan
 *    created:	17.05.2020 11:13:59 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> peopleIndexes(vector<vector<string>> &fav_comps) {
	int n = fav_comps.size();
	map<string, int> shift;
	int curr_shift = 0;
	for (int i = 0; i <= n - 1; ++i) {
		for (string comp : fav_comps[i]) {
			if (not shift.count(comp)) {
				shift[comp] = curr_shift++;
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i <= n - 1; ++i) {
		int subset_mask = 0;
		for (string comp : fav_comps[i]) {
			subset_mask |= (1 << shift[comp]);
		}

		bool is_subset = false;
		for (int j = 0; j <= n - 1; ++j) {
			if (i != j) {
				int curr_mask = 0;
				for (string comp : fav_comps[j]) {
					curr_mask |= (1 << shift[comp]);
				}

				if (((~curr_mask)&subset_mask) == 0) {
					is_subset = true;
					break;
				}
			}
		}

		if (not is_subset) {
			ans.push_back(i);
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<string>> fav_comps(n);
	for (int i = 0; i <= n - 1; ++i) {
		int c;
		cin >> c;
		fav_comps[i] = vector<string>(c);
		for (int j = 0; j <= c - 1; ++j) {
			cin >> fav_comps[i][j];
		}
	}

	vector<int> ans = peopleIndexes(fav_comps);

	return 0;
}