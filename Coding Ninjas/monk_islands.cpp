#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int dp[MAX];

int _shortestPath(int **edges, int n, int start, bool *isVisited)
{
	if (start == n-1)
	{
		return 0;
	}

	if (dp[start] > -1)
	{
		return dp[start];
	}

	int route = MAX;
	for (int i = 0; i < n; ++i)
	{
		if (edges[start][i] and !isVisited[i])
		{
			isVisited[i] = true;
			route = min(_shortestPath(edges, n, i, isVisited) + 1, route);
			isVisited[i] = false;
		}
	}

	dp[start] = route;
	return route;
}

int shortestPath(int **edges, int n, int m)
{
	bool *isVisited = new bool[n]();
	isVisited[0] = true;
	return _shortestPath(edges, n, 0, isVisited);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(int) * MAX);
		int n,m;
		cin >> n >> m;
		int **edges = new int*[n]();
		for (int i = 0; i < n; ++i)
		{
			edges[i] = new int[n]();
		}

		for (int i = 0; i < m; ++i)
		{
			int s,e;
			cin >> s >> e;
			edges[s-1][e-1] = 1;
			edges[e-1][s-1] = 1;
		}

		int route = shortestPath(edges, n, m);
		cout << route << endl;
	}
	return 0;
}