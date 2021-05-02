/**
 *    author:	vulkan
 *    created:	28.06.2020 03:46:20 PM
**/
#include <bits/stdc++.h>

using namespace std;

int _minNumberOfSemesters(vector<vector<int>> &adj_list, vector<int> &in_deg, int n, int k, vector<bool> &vis) {
	vector<int> poss;
	for (int i = 1; i <= n; ++i) {
		if (not vis[i] and in_deg[i] == 0) {
			poss.push_back(i);
		}
	}

	int sz = poss.size();
	if (sz == 0) {
		return 0;
	}
	// cout << sz << endl;
	int ans = INT_MAX;
	if (sz > k) {
		int max_elt = ((1 << sz) - 1);
		int min_elt = 1;
		for (int i = min_elt; i <= max_elt; ++i) {
			if (__builtin_popcount(i) == k) {
				for (int j = 0; j <= sz - 1; ++j) {
					if (i & (1 << j)) {
						vis[poss[j]] = true;
						for (int x : adj_list[poss[j]]) {
							in_deg[x]--;
						}
					}
				}

				ans = min(ans, _minNumberOfSemesters(adj_list, in_deg, n, k, vis));

				for (int j = 0; j <= sz - 1; ++j) {
					if (i & (1 << j)) {
						vis[poss[j]] = false;
						for (int x : adj_list[poss[j]]) {
							in_deg[x]++;
						}
					}
				}
			}
		}
	} else {
		for (int i = 0; i <= sz - 1; ++i) {
			vis[poss[i]] = true;
			for (int x : adj_list[poss[i]]) {
				in_deg[x]--;
			}
		}

		ans = _minNumberOfSemesters(adj_list, in_deg, n, k, vis);

		for (int i = 0; i <= sz - 1; ++i) {
			vis[poss[i]] = false;
			for (int x : adj_list[poss[i]]) {
				in_deg[x]++;
			}
		}
	}

	return ans + 1;
}

int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k) {
	vector<vector<int>> adj_list(n + 1);
	vector<int> in_deg(n + 1);
	for (auto dep : dependencies) {
		adj_list[dep[0]].push_back(dep[1]);
		in_deg[dep[1]]++;
	}

	vector<bool> vis(n + 1);
	return _minNumberOfSemesters(adj_list, in_deg, n, k, vis);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int dep_cnt;
	cin >> dep_cnt;
	vector<vector<int>> dependencies(dep_cnt, vector<int>(2));
	for (int i = 0; i <= dep_cnt - 1; ++i) {
		cin >> dependencies[i][0] >> dependencies[i][1];
	}
	int k;
	cin >> k;

	cout << minNumberOfSemesters(n, dependencies, k);

	return 0;
}