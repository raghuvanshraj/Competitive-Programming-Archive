#include <bits/stdc++.h>
#define pb(x) push_back(x)

using namespace std;

void DFS(int **edges, int v, int start, int end, bool *isVisited, vector<int> *path)
{
	isVisited[start] = true;
	if (start == end)
	{
		path->pb(start);
		return;
	}	

	for (int i = 0; i < v; ++i)
	{
		if (edges[start][i] and !isVisited[i])
		{
			DFS(edges, v, i, end, isVisited, path);
			path->pb(start);
			return;
		}
	}
}

void getDFSPath(int **edges, int v, int start, int end, vector<int> *path)
{
	if (start == end)
	{
		path->pb(start);
		return;
	}
	bool *isVisited = new bool[v]();
	DFS(edges, v, start, end, isVisited, path);
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

	vector<int> *path = new vector<int>(); 
	getDFSPath(edges, v, start, end, path);
	vector<int>::iterator it = path->begin();
	while (it != path->end())
	{
		cout << *it << " ";
		++it;
	}
	return 0;
}