#include <bits/stdc++.h>
#define MAX 5000
#define pb(x) push_back(x)

using namespace std;

vector< vector<int> > edges(MAX);
vector< vector<int> > edgesT(MAX);
stack<int> finishedVertices;
unordered_set< vector<int> > components;
vector<int> currComponent;

void dfs(int start, bool *isVisited)
{
	isVisited[start] = true;
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!isVisited[edges[start][i]])
		{
			dfs(edges[start][i], isVisited);
		}
	}
	finishedVertices.push(start);
}

void dfs2(int start, bool *isVisited)
{
	isVisited[start] = true;
	currComponent.pb(start);
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
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (!isVisited[edges[start][i]])
		{
			dfs3(edges[start][i], isVisited);
		}
	}
}

void findSCC(int v)
{
	bool *isVisited = new bool[v]();
	for (int i = 0; i < v; ++i)
	{
		if (!isVisited[i])
		{
			dfs(i, isVisited);
		}
	}

	for (int i = 0; i < v; ++i)
	{
		isVisited[i] = false;
	}
	while (!finishedVertices.empty())
	{	
		int elt = finishedVertices.top();
		finishedVertices.pop();
		if (!isVisited[elt])
		{
			dfs2(elt, isVisited);
			components.insert(currComponent);
			currComponent.clear();	
		}
	}
}

int main(int argc, char const *argv[])
{
	while (true)
	{
		int v,e;
		cin >> v;
		if (v == 0)
		{
			break;
		}
		cin >> e;
		for (int i = 0; i < e; ++i)
		{
			int a,b;
			cin >> a >> b;
			edges[a-1].pb(b-1);
			edgesT[b-1].pb(a-1);
		}

		findSCC(v);

		bool *isVisited = new bool[v]();
		for (vector<int> component : components)
		{
			for (int i = 0; i < v; ++i)
			{
				isVisited[i] = false;
			}
			unordered_set<int>::iterator it = component.begin();
			dfs3(*it, isVisited);
			bool foundComponent = true;
			for (int i = 0; i < v; ++i)
			{
				if (isVisited[i] and component.find(i) == component.end())
				{
					foundComponent = false;
					break;
				}
			}

			if (foundComponent)
			{
				while (it != component.end())
				{
					cout << *it << " ";
					++it;
				}
				break;
			}
		}

		edges.clear();
		edgesT.clear();
		components.clear();
		while (!finishedVertices.empty())
		{
			finishedVertices.pop();
		}
	}
	return 0;
}