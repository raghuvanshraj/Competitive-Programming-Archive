#include <bits/stdc++.h>

using namespace std;

vector<int> BFS(int **edges, int v, bool *isVisited, int start)
{
	list<int> queue;
	vector<int> bfs;
	queue.push_back(start);

	while(!queue.empty())
	{
		start = queue.front();
		bfs.push_back(start);
		isVisited[start] = true;
		queue.pop_front();

		for (int i = 0; i < v; ++i)
		{
			if (edges[start][i] == 1 and !isVisited[i])
			{
				queue.push_back(i);
				isVisited[i] = true;
			}
		}
	}

	return bfs;
}

vector< vector<int> > allConnected(int **edges, int v)
{
	vector< vector<int> > connected;
	bool *isVisited = new bool[v];
	for (int i = 0; i < v; ++i)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < v; ++i)
	{
		for (int i = 0; i < v; ++i)
		{
			if (!isVisited[i])
			{
				vector<int> ans = BFS(edges, v, isVisited, i);
				sort(ans.begin(), ans.end());
				connected.push_back(ans);
			}
		}
	}

	return connected;
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
		int f,s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	vector< vector<int> > connected = allConnected(edges, v);
	for (int i = 0; i < connected.size(); ++i)
	{
		for (int j = 0; j < connected[i].size(); ++j)
		{
			cout << connected[i][j] << " ";
		}

		cout << endl;
	}
	return 0;
}