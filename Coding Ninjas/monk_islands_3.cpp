#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

vector<vector<int>> edges(MAX);

int shortestPath(int n, int start)
{
	int *distance = new int[n]();
	bool *visited = new bool[n]();
	queue<int> que;
	que.push(start);
	while (!que.empty())
	{
		int curr = que.front();
		que.pop();
		visited[curr] = true;
		for (int i = 0; i < edges[curr].size(); ++i)
		{
			if (!visited[edges[curr][i]])
			{
				que.push(edges[curr][i]);
				distance[edges[curr][i]] = distance[curr]+1;
				visited[edges[curr][i]] = true;
			}
		}
	}

	return distance[n-1];
}

int main(int argc, char const *argv[])
{
	int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < m; ++i)
        {
            int s,e;
            cin >> s >> e;
            edges[s-1].push_back(e-1);
            edges[e-1].push_back(s-1);
        }

        int route = shortestPath(n, 0);
        cout << route << endl;
    }
    
	return 0;
}