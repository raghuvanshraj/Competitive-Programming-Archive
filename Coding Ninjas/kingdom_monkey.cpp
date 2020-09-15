#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
typedef long long ll;

vector<vector<int>> edges(MAX);

ll bfs(bool *visited, int start, int n, int m, ll *a)
{
	ll count = 0;
	visited[start] = true;
	queue<int> que;
	que.push(start);
	while (!que.empty())
	{
		int curr = que.front();
		count += a[curr];
		visited[curr]= true;
		que.pop();
		for (int i = 0; i < edges[curr].size(); ++i)
		{
			if (!visited[edges[curr][i]])
			{
				que.push(edges[curr][i]);
				visited[edges[curr][i]] = true;
			}
		}
	}

	return count;
}

ll coins(ll *a, int n, int m)
{
	bool *visited = new bool[n]();
	ll coinsCount = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			coinsCount = max(bfs(visited, i, n, m, a), coinsCount);
		}
	}

	return coinsCount;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		for (int i = 0; i < MAX; ++i)
		{
			edges[i].clear();
		}
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin >> x >> y;
			edges[x-1].push_back(y-1);
			edges[y-1].push_back(x-1);
		}

		ll *a = new ll[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		cout << coins(a, n, m) << endl;
	}
	return 0;
}