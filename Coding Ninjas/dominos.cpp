#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

vector<int> edges[MAX];
bool visited[MAX];
stack<int> finishedVertices;

void dfs(int start)
{
	visited[start] = true;
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!visited[edges[start][i]])
		{
			dfs(edges[start][i]);
		}
	}
	finishedVertices.push(start);
}

void dfs2(int start)
{
	visited[start] = true;
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!visited[edges[start][i]])
		{
			dfs2(edges[start][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < MAX; ++i)
		{
			edges[i].clear();
		}
		memset(visited, false, MAX * (sizeof(bool)));
		int n,m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin >> x >> y;
			edges[x-1].push_back(y-1);
		}

		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}
		memset(visited, false, MAX * (sizeof(bool)));
		int count = 0;
		while (!finishedVertices.empty())
		{
			int v = finishedVertices.top();
			finishedVertices.pop();
			if (!visited[v])
			{
				dfs2(v);
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}