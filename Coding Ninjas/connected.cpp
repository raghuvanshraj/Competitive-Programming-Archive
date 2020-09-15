#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> edges, int start, bool *isVisited, vector<int>* component)
{
	isVisited[start] = true;
	component->push_back(start+1);
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!isVisited[edges[start][i]])
		{
			DFS(edges, edges[start][i], isVisited, component);
		}
	}
}

vector<vector<int>> getConnected(vector<vector<int>> edges, int v, int e)
{
	vector<vector<int>> components;
	bool *isVisited = new bool[v]();

	for (int i = 0; i < v; ++i)
	{
		vector<int>* component = new vector<int>();
		if (!isVisited[i])
		{
			DFS(edges, i, isVisited, component);
			components.push_back(*component);
			component->clear();
		}
	}

	return components;
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

	vector<vector<int>> components = getConnected(edges, v, e);
	for (int i = 0; i < components.size(); ++i)
	{
		for (int j = 0; j < components[i].size(); ++j)
		{
			cout << components[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}