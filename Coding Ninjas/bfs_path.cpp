#include <bits/stdc++.h>

using namespace std;

bool BFS(int **edges, int v, bool *isVisited, int s, int e)
{
	if (s == e)
	{
		return true;
	}

	list<int> queue;
	queue.push_back(s);

	while(!queue.empty())
	{
		int start = queue.front();
		isVisited[start] = true;
		if (start == e)
		{
			return true;
		}
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

	return false;
}

bool hasPath(int **edges, int v, int s, int e)
{
	bool *isVisited = new bool[v]();
    for (int i = 0; i < v; ++i)
    {
    	isVisited[i] = false;
    }
	return BFS(edges, v, isVisited, s, e);
}

vector<int> BFS(int **edges, int v, int s, int e, bool *isVisited)
{
	list<int> queue;
	unordered_map<int,int> parent;
	queue.push_back(s);

	while(!queue.empty())
	{
		int start = queue.front();
		isVisited[start] = true;
		queue.pop_front();

		for (int i = 0; i < v; ++i)
		{
			if (edges[start][i] == 1 and !isVisited[i])
			{
				queue.push_back(i);
				parent[i] = start;
				isVisited[i] = true;
				if (i == e)
				{
					break;
				}
			}
		}

		// if (queue.back() == e)
		// {
		// 	break;
		// }
	}

	vector<int> path;
	int curr = e;
	while (curr != s)
	{
		path.push_back(curr);
		curr = parent[curr];
	}

	path.push_back(s);
	return path;
}

vector<int> getBFSPath(int **edges, int v, int start, int end)
{
	bool *isVisited = new bool[v]();
    for (int i = 0; i < v; ++i)
    {
    	isVisited[i] = false;
    }

    return BFS(edges, v, start, end, isVisited);
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
	vector<int> path;
	if (hasPath(edges, v, start, end))
	{
		path = getBFSPath(edges, v, start, end);
	}
	for (int i = 0; i < path.size(); ++i)
	{
		cout << path[i] << " ";
	}

	return 0;
}