#include <bits/stdc++.h>

using namespace std;

bool BFS(int **edges, bool *isVisited, int v, int start, int end)
{
	list<int> que;
	que.push_back(start);
	isVisited[start] = true;

	while (!que.empty())
	{
		int curr = que.front();
		if (curr == end)
		{
			return true;
		}
		que.pop_front();
		for (int i = 0; i < v; ++i)
		{
			if (edges[curr][i] and !isVisited[i])
			{
				que.push_back(i);
				isVisited[i] = true;
			}
		}
	}

	return false;
}

bool hasPath(int **edges, int v, int start, int end)
{
	if (start == end)
	{
		return true;
	}
	bool *isVisited = new bool[v]();
	return BFS(edges, isVisited, v, start, end);
}

int main(int argc, char const *argv[])
{
	int v,e;
	cin >> v >> e;
	int **edges = new int*[v]();
	for (int i = 0; i < v; ++i)
	{
		edges[i] = new int[v]();
	}

	for (int i = 0; i < e; ++i)
	{
		int a,b;
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}

	int start, end;
	cin >> start >> end;
	bool isPath = hasPath(edges, v, start, end);
	string ans = (isPath) ? "true" : "false";
	cout << ans;
	return 0;
}