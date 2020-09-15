#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define MAX 100000

using namespace std;

vector< vector<int> > edgesT(MAX);
vector< vector<int> > edges(MAX);
vector<int> component;
stack<int> finishedVertices;

void dfs(int start, bool *isVisited)
{
	isVisited[start] = true;
	for (int i = 0; i < edgesT[start].size(); ++i)
	{
		if (!isVisited[edgesT[start][i]])
		{
			dfs(edgesT[start][i], isVisited);
		}
	}
	finishedVertices.push(start);
}

void dfs2(int start, bool *isVisited)
{
	isVisited[start] = true;
	component.pb(start);
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!isVisited[edges[start][i]])
		{
			dfs2(edges[start][i], isVisited);
		}
	}
}

void dfs3(int start, bool *isVisited)
{
	isVisited[start] = true;
	for (int i = 0; i < edgesT[start].size(); ++i)
	{
		if (!isVisited[edgesT[start][i]])
		{
			dfs3(edgesT[start][i], isVisited);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		edges[a-1].pb(b-1);
		edgesT[b-1].pb(a-1);
	}
	bool *isVisited = new bool[n]();
	for (int i = 0; i < n; ++i)
	{
		if (!isVisited[i])
		{
			dfs(i, isVisited);
		}
	}

	int validVertex = finishedVertices.top();
	for (int i = 0; i < n; ++i)
	{
		isVisited[i] = false;
	}
	dfs3(validVertex, isVisited);
	for (int i = 0; i < n; ++i)
	{
		if (!isVisited[i])
		{
			cout << 0;
			return 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		isVisited[i] = false;
	}
	dfs2(validVertex, isVisited);
	sort(component.begin(), component.end());
	cout << component.size() << endl;
	for (int i = 0; i < component.size(); ++i)
	{
		cout << component[i]+1 << " ";
	}
	return 0;
}