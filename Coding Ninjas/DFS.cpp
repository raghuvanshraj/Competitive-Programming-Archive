#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> edges, int start, bool *isVisited)
{
	isVisited[start] = true;
	cout << start+1 << " ";
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!isVisited[edges[start][i]])
		{
			DFS(edges, edges[start][i], isVisited);
		}
	}
}

int main(int argc, char const *argv[])
{
	int v,e;
	cin >> v >> e;
	vector<vector<int>> edges(v);
	for (int i = 0; i < e; ++i)
	{
		int s,e;
		cin >> s >> e;
		edges[s-1].push_back(e-1);
		edges[e-1].push_back(s-1);
	}

	bool *isVisited = new bool[v]();
	DFS(edges, 0, isVisited);

	return 0;
}