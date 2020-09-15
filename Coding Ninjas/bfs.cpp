#include <bits/stdc++.h>

using namespace std;

void BFS(int **edges, int v, bool *isVisited, int start)
{
	list<int> queue;
	queue.push_back(start);

	while(!queue.empty())
	{
		start = queue.front();
		cout << start << " ";
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
}

int main() 
{
    int v, e;
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

    bool *isVisited = new bool[v]();
    for (int i = 0; i < v; ++i)
    {
    	isVisited[i] = false;
    }

    BFS(edges, v, isVisited, 0);

  	return 0;
}
