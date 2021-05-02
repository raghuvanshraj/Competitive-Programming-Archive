/**
 *    author:	vulkan
 *    created:	25.05.2020 10:42:28 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_similar(string &a, string &b) {
	int n = a.size();
	int count = 0;
	for (int i = 0; i <= n - 1; ++i) {
		count += (a[i] != b[i]);
	}

	return count <= 2;
}

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

int numSimilarGroups(vector<string> &arr) {
	int n = arr.size();
	vector<vector<int>> adj_list(n);
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n - 1; ++j) {
			if (is_similar(arr[i], arr[j])) {
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
			}
		}
	}

	int ans = 0;
	vector<bool> visited(n);
	for (int i = 0; i <= n - 1; ++i) {
		if (not visited[i]) {
			ans++;
			bfs(adj_list, i, visited);
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << numSimilarGroups(arr);

	return 0;
}