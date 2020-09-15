#include <bits/stdc++.h>

using namespace std;

vector<int> DFS(int **edges, int v, int start, int end, bool *isVisited)
{
	isVisited[start] = true;
	if (start == end)
	{
		isVisited[start] = true;
		vector<int> smallPath;
		smallPath.push_back(start);
		return smallPath;
	}

	vector<int> smallPath;

	for (int i = 0; i < v; ++i)
	{
		if (edges[start][i] == 1 and !isVisited[i])
		{
			smallPath = DFS(edges, v, i, end, isVisited);
			if (!smallPath.empty())
			{
				break;
			}
		}
	}

	if (smallPath.empty())
	{
		return smallPath;
	}

	smallPath.push_back(start);

	return smallPath;
}

vector<int> getDFSPath(int **edges, int v, int start, int end)
{
	bool *isVisited = new bool[v]();
    for (int i = 0; i < v; ++i)
    {
    	isVisited[i] = false;
    }

    return DFS(edges, v, start, end, isVisited);
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
		edges[s][f] = 1;
		edges[f][s] = 1;
	}
	int start, end;
	cin >> start >> end;
	vector<int> path = getDFSPath(edges, v, start, end);
	if (!path.empty())
	{
		for (int i = 0; i < path.size(); ++i)
		{
			cout << path[i] << " ";
		}
	}

	return 0;
}