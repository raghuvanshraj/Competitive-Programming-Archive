#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

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
		if (edges[i].empty())
		{
			continue;
		}
		
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
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> q[i];
		}

		vector<vector<int>> edges(n);
		for (int i = 0; i < m; ++i)
		{
			int s,e;
			cin >> s >> e;
			edges[s-1].push_back(e-1);
			edges[e-1].push_back(s-1);
		}

		vector<vector<int>> components = getConnected(edges, n, m);
		vector<set<int>> componentsP;
		vector<set<int>> componentsQ;
		vector<int> tempP;
		vector<int> tempQ;
		bool flag = true;
		for (int i = 0; i < components.size(); ++i)
		{
			for (int j = 0; j < components[i].size(); ++j)
			{
				tempP.push_back(p[components[i][j] - 1]);
				tempQ.push_back(q[components[i][j] - 1]);
			}
			sort(tempP.begin(), tempP.end());
			sort(tempQ.begin(), tempQ.end());
			for (int k = 0; k < tempP.size(); ++k)
			{
				if (tempP[k] != tempQ[k])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				cout << "NO\n";
				break;
			}
		}

		if (flag)
		{
			cout << "YES\n";
		}
	}

	return 0;
}