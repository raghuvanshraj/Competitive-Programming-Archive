#include <bits/stdc++.h>

using namespace std;

vector<int> dijstraNode(int **edges, int start, int n, int m)
{
	int *distances = new int[n];
	distances[start] = INT_MIN;
	bool *visited = new bool[n]();
	visited[start] = true;
	for (int i = 0; i < n; ++i)
	{
		if (i != start)
		{
			distances[i] = edges[start][i];
		}
	}

	for (int i = 0; i < n-1; ++i)
	{
		/* code */
	}
}

vector< vector<int> > dijstra(int **edges, int n, int m)
{
	vector< vector<int> > costs;
	for (int i = 0; i < n; ++i)
	{
		vector<int> curr = dijstraNode(edges, i, n, m);
		costs.push_back(curr);
	}

	return costs;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	int **edges = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int x,y,c;
		cin >> x >> y >> c;
		edges[x-1][y-1] = c;
	}

	vector< vector<int> > costs = dijstra(edges, n, m);
	return 0;
}