/**
 *    author:	vulkan
 *    created:	25.08.2019 12:07:03 PM
**/
#include <bits/stdc++.h>

using namespace std;

void dfs(int **adj, int n, bool is_visited[], int start, int &curr_count) {
	is_visited[start] = true;
	curr_count++;

	for (int i = 0; i < n; ++i) {
		if (not is_visited[i] and adj[start][i] == 1) {
			dfs(adj, n, is_visited, i, curr_count);
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int t_n = 0; t_n < t; ++t_n) {
		int n, m;
		cin >> n >> m;
		int **adj = new int*[n]();
		for (int i = 0; i < n; ++i) {
			adj[i] = new int[n]();
		}

		for (int i = 0; i < m; ++i) {
			int s, e;
			cin >> s >> e;
			adj[s - 1][e - 1] = 1;
			adj[e - 1][s - 1] = 1;
		}

		int min_cost = 0;
		bool is_visited[n] = {false};
		int component_count = 0;
		for (int i = 0; i < n; ++i) {
			if (not is_visited[i]) {
				component_count++;
				int curr_count = 0;
				dfs(adj, n, is_visited, i, curr_count);

				min_cost += curr_count - 1;
			}
		}

		min_cost += 2 * (component_count - 1);

		cout << "Case #" << t_n + 1 << ": " << min_cost << endl;
	}

	return 0;
}