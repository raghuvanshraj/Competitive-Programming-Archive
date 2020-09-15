#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> edges, bool *visited, int start, int n, int m, int *a)
{
	int count = 0;
	visited[start] = true;
	queue<int> que;
	que.push(start);
	while (!que.empty())
	{
		int curr = que.front();
		count += a[curr];
		visited[curr]= true;
		que.pop();
		for (int i = 0; i < edges[curr].size(); ++i)
		{
			if (!visited[edges[curr][i]])
			{
				que.push(edges[curr][i]);
				visited[edges[curr][i]] = true;
			}
		}
	}

	return count;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> edges(n);
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		edges[x-1].push_back(y-1);
		edges[y-1].push_back(x-1);
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << i << ": ";
	// 	for (int j = 0; j < edges[i].size(); ++j)
	// 	{
	// 		cout << edges[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int *a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	bool *visited = new bool[n]();
	cout << bfs(edges, visited, 0, n, m, a);

	return 0;
}