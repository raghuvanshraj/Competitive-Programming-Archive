/**
 *    author:	vulkan
 *    created:	13.01.2022 06:53:52 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> partitionLabels(string s) {
	vector<int> start_idx(26, -1);
	vector<int> end_idx(26);

	int n = s.size();
	for (int i = 0; i <= n - 1; ++i) {
		int x = s[i] - 'a';
		if (start_idx[x] == -1) {
			start_idx[x] = i;
		}
		end_idx[x] = i;
	}

	vector<bool> visited(26);
	int cnt = 0;
	vector<int> ans;
	int curr_start = 0;
	for (int i = 0; i <= n - 1; ++i) {
		int x = s[i] - 'a';
		if (not visited[x]) {
			visited[x] = true;
			cnt++;
		}
		if (i == end_idx[x]) {
			visited[x] = false;
			cnt--;
		}

		if (cnt == 0) {
			ans.push_back(i - curr_start + 1);
			curr_start = i + 1;
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	vector<int> ans = partitionLabels(s);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}