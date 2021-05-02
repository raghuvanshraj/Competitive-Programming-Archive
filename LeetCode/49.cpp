/**
 *    author:	vulkan
 *    created:	06.04.2020 07:53:27 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
	int n = strs.size();
	vector<pair<string, int>> strs_cp(n);
	for (int i = 0; i < n; ++i) {
		strs_cp[i] = {strs[i], i};
		sort(strs_cp[i].first.begin(), strs_cp[i].first.end());
	}

	sort(strs_cp.begin(), strs_cp.end());
	vector<vector<string>> ans;
	ans.push_back({strs[strs_cp[0].second]});
	int i = 0;
	for (int j = 1; j < n; ++j) {
		if (strs_cp[j].first == strs_cp[j - 1].first) {
			ans[i].push_back(strs[strs_cp[j].second]);
		} else {
			i++;
			ans.push_back({strs[strs_cp[j].second]});
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; ++i) {
		cin >> strs[i];
	}

	vector<vector<string>> ans = groupAnagrams(strs);
	for (vector<string> curr : ans) {
		for (string s : curr) {
			cout << s << ' ';
		}
		cout << endl;
	}

	return 0;
}