#include <bits/stdc++.h>

using namespace std;

vector<int> pp;
vector<int> qq;
vector<vector<int>> edges(100005);
bool isVisited[100005];

void BFS(int start, int *p, int *q)
{
	queue<int> que;
	que.push(start);
	while (!que.empty())
	{
		int curr = que.front();
		que.pop();
		isVisited[curr] = true;
		pp.push_back(p[curr]);
		qq.push_back(q[curr]);
		for (int i = 0; i < edges[curr].size(); ++i)
		{
			if (!isVisited[edges[curr][i]])
			{
				que.push(edges[curr][i]);
				isVisited[edges[curr][i]] = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		int *p = new int[n];
		int *q = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> p[i];
          	isVisited[i] = false;
         	edges[i].clear();
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> q[i];
		}

		for (int i = 0; i < m; ++i)
		{
			int s,e;
			cin >> s >> e;
			edges[s-1].push_back(e-1);
			edges[e-1].push_back(s-1);
		}

		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			if (!isVisited[i] and !edges[i].empty()) 		
			{
				BFS(i, p, q);
			}
			sort(pp.begin(), pp.end());
			sort(qq.begin(), qq.end());
			if (pp != qq)
			{
				flag = false;
				cout << "NO\n";
				break;
			}
			pp.clear();
			qq.clear();
		}

		if (flag)
		{
			cout << "YES\n";
		}

		pp.clear();
		qq.clear();
	}
	return 0;
}