/**
 *    author:	vulkan
 *    created:	17.04.2020 12:55:37 PM
**/
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<char>> &grid, pair<int, int> start, vector<vector<bool>> &visited) {
	int n = visited.size(), m = visited[0].size();
	queue<pair<int, int>> qu;
	qu.push(start);
	visited[start.first][start.second] = true;
	while (not qu.empty()) {
		pair<int, int> curr = qu.front();
		qu.pop();
		int x = curr.first, y = curr.second;
		if (x > 0 and grid[x - 1][y] == '1' and not visited[x - 1][y]) {
			visited[x - 1][y] = true;
			qu.push({x - 1, y});
		}
		if (x < n - 1 and grid[x + 1][y] == '1' and not visited[x + 1][y]) {
			visited[x + 1][y] = true;
			qu.push({x + 1, y});
		}
		if (y > 0 and grid[x][y - 1] == '1' and not visited[x][y - 1]) {
			visited[x][y - 1] = true;
			qu.push({x, y - 1});
		}
		if (y < m - 1 and grid[x][y + 1] == '1' and not visited[x][y + 1]) {
			visited[x][y + 1] = true;
			qu.push({x, y + 1});
		}
	}
}

int numIslands(vector<vector<char>> &grid) {
	int n = grid.size(), m;
	if (n != 0) {
		m = grid[0].size();
	} else {
		return 0;
	}

	vector<vector<bool>> visited(n, vector<bool>(m));
	int ans = 0;
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			if (grid[i][j] == '1' and not visited[i][j]) {
				bfs(grid, {i, j}, visited);
				ans++;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i <= n - 1; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j <= m - 1; ++j) {
			grid[i][j] = s[j];
		}
	}

	cout << numIslands(grid);

	return 0;
}