#include <bits/stdc++.h>
#define pb(x) push_back(x)

using namespace std;

bool bipartite(vector< vector<int> > edges, int v, int start, bool *isVisited)
{
	if (v == 0)
	{
		return true;
	}

	unordered_set<int> sets[2];
	vector<int> pending;

	sets[0].insert(start);
	pending.push_back(start);
	isVisited[start] = true;
	while (pending.size() > 0)
	{
		int currVertex = pending.back();
		isVisited[currVertex] = true;
		pending.pop_back();
		int currSet = (sets[0].find(currVertex) != sets[0].end()) ? 0 : 1;
		for (int i = 0; i < edges[currVertex].size(); ++i)
		{
			if (sets[0].count(edges[currVertex][i]) == 0 and sets[1].count(edges[currVertex][i]) == 0)
			{
				sets[!currSet].insert(edges[currVertex][i]);
				pending.push_back(edges[currVertex][i]);
			}
			else if (sets[currSet].count(edges[currVertex][i]) > 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int v,e;
		cin >> v >> e;
		vector< vector<int> > edges(v);
		for (int j = 0; j < e; ++j)
		{
			int a,b;
			cin >> a >> b;
			edges[a-1].pb(b-1);
			edges[b-1].pb(a-1);
		}

		bool *isVisited = new bool[v]();
		bool possible = true;
		for (int i = 0; i < v; ++i)
		{
			if (!isVisited[i])
			{
				possible = possible & bipartite(edges, v, i, isVisited);
				if (!possible)
				{
					break;
				}
			}
		}
		string ans = (possible) ? "No suspicious bugs found!" : "Suspicious bugs found!";
		cout << "Scenario #" << i+1 << ":\n" << ans << endl;
	}
	
	return 0;
}