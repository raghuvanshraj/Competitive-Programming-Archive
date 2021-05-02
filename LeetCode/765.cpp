/**
 *    author:	vulkan
 *    created:	24.05.2020 02:34:11 PM
**/
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &adj_list, int u, vector<bool> &visited) {
	int n = adj_list.size();
	queue<int> qu;
	qu.push(u);
	visited[u] = true;
	while (not qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int y : adj_list[x]) {
			if (not visited[y]) {
				visited[y] = true;
				qu.push(y);
			}
		}
	}
}

int minSwapsCouples(vector<int> &arr) {
	int n = arr.size();
	int m = n / 2;
	vector<vector<int>> adj_list(m);
	for (int i = 0; i <= n - 1; i += 2) {
		int u = arr[i] / 2, v = arr[i + 1] / 2;
		if (u != v) {
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
	}

	vector<bool> visited(m);
	int count = 0;
	for (int i = 0; i <= m - 1; ++i) {
		if (not visited[i]) {
			count++;
			bfs(adj_list, i, visited);
		}
	}

	return m - count;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> row(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> row[i];
	}

	cout << minSwapsCouples(row);

	return 0;
}