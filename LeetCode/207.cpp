/**
 *    author:	vulkan
 *    created:	19.01.2022 07:16:53 PM
**/
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &adj_list, vector<int> &in_deg) {
	int n = adj_list.size();
	queue<int> qu;
	for (int i = 0; i <= n - 1; ++i) {
		if (in_deg[i] == 0) {
			qu.push(i);
		}
	}
	while (not qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int y : adj_list[x]) {
			in_deg[y]--;
			if (in_deg[y] == 0) {
				qu.push(y);
			}
		}
	}
}

bool canFinish(int n, vector<vector<int>> &pre) {
	vector<vector<int>> adj_list(n);
	vector<int> in_deg(n);
	int m = pre.size();
	for (int i = 0; i <= m - 1; ++i) {
		int u = pre[i][0], v = pre[i][1];
		adj_list[v].push_back(u);
		in_deg[u]++;
	}

	bfs(adj_list, in_deg);

	for (int i = 0; i <= n - 1; ++i) {
		if (in_deg[i] > 0) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> pre(m, vector<int>(2));
	for (int i = 0; i <= m - 1; ++i) {
		cin >> pre[i][0] >> pre[i][1];
	}

	cout << canFinish(n, pre);

	return 0;
}