/**
 *    author:	vulkan
 *    created:	25.05.2020 02:21:56 PM
**/
#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> &adj_list, vector<int> &initial, int u = -1) {
	int n = adj_list.size();
	vector<bool> visited(n);
	queue<int> qu;
	for (int x : initial) {
		if (x != u) {
			qu.push(x);
			visited[x] = true;
		}
	}

	while (not qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int y : adj_list[x]) {
			if (y != u and not visited[y]) {
				visited[y] = true;
				qu.push(y);
			}
		}
	}

	return accumulate(visited.begin(), visited.end(), 0);
}

int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
	int n = graph.size();
	vector<vector<int>> adj_list(n);
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= n - 1; ++j) {
			if (graph[i][j]) {
				adj_list[i].push_back(j);
			}
		}
	}

	int count = bfs(adj_list, initial);
	int ans = n - 1;
	int sz = initial.size();
	for (int i = 0; i <= sz - 1; ++i) {
		int curr_count = bfs(adj_list, initial, initial[i]);
		cout << curr_count << endl;
		if (curr_count < count) {
			ans = initial[i];
			count = curr_count;
		} else if (curr_count == count) {
			ans = min(ans, initial[i]);
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= n - 1; ++j) {
			cin >> graph[i][j];
		}
	}
	int k;
	cin >> k;
	vector<int> initial(k);
	for (int i = 0; i <= k - 1; ++i) {
		cin >> initial[i];
	}

	cout << minMalwareSpread(graph, initial);

	return 0;
}