#include <bits/stdc++.h>

using namespace std;

void BFS(int **edges, int v, bool *isVisited, int start, list<int> &queue)
{
    if (queue.empty())
    {
        return;
    }

    int curr = queue.front();
    cout << curr << " ";
    queue.pop_front();
    isVisited[curr] = true;

    for (int i = 0; i < v; ++i)
    {
        if (edges[curr][i] == 1 and !isVisited[i])
        {
            queue.push_back(i);
            isVisited[i] = true;
        }
    }

    BFS(edges, v, isVisited, queue.front(), queue);
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

    list<int> queue;
    queue.push_back(0);
    BFS(edges, v, isVisited, 0, queue);

  	return 0;
}
