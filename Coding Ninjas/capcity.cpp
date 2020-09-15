#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> edges, int start, unordered_set<int> &visited, stack<int> &finishedVertices)
{
	visited.insert(start);
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (visited.count(edges[start][i]) == 0)
		{
			dfs(edges, edges[start][i], visited, finishedVertices);
		}
	}
	finishedVertices.push(start);
}

void dfs2(vector<vector<int>> edgesT, int start, unordered_set<int> *component, unordered_set<int> &visited)
{
	visited.insert(start);
	component->insert(start);
	for (int i = 0; i < edgesT[start].size(); ++i)
	{
		if (visited.count(edgesT[start][i]) == 0)
		{
			dfs2(edgesT, edgesT[start][i], component, visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getSCC(vector<vector<int>> edges, vector<vector<int>> edgesT, int n)
{
	unordered_set<int> visited;
	stack<int> finishedVertices;
	for (int i = 0; i < n; ++i)
	{
		if (visited.count(i) == 0)
		{
			dfs(edges, i, visited, finishedVertices);
		}
	}
	unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>();
	visited.clear();
	while (finishedVertices.size() != 0)
	{
		int elt = finishedVertices.top();
		finishedVertices.pop();
		if (visited.count(elt) == 0)
		{
			unordered_set<int>* component = new unordered_set<int>();
			dfs2(edgesT, elt, component, visited);
			components->insert(component);
		}
	}

	return components;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> edges(n);
	vector<vector<int>> edgesT(n);
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		edges[x-1].push_back(y-1);
		edgesT[y-1].push_back(x-1);
	}

	unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);

	stack<int> finishedVertices;
	unordered_set<int> visited;
	for (int i = 0; i < n; ++i)
	{
		if (visited.count(i) == 0)
		{
			dfs(edgesT, i, visited, finishedVertices);
		}
	}

	unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
	int capableVertex = finishedVertices.top();
	bool flag = false;
	while (it1 != components->end())
	{
		unordered_set<int> *component = *it1;
		if (component->find(capableVertex) != component->end())
		{
			flag = true;
			unordered_set<int>::iterator it2 = component->begin();
			set<int> sortedComponent;
			while (it2 != component->end())
			{
				sortedComponent.insert(*it2);
				++it2;
			}
			set<int>::iterator it3 = sortedComponent.begin();
			cout << sortedComponent.size() << endl;
			while (it3 != sortedComponent.end())
			{
				cout << *it3 + 1 << " ";
				++it3;
			}
		}

		if (flag)
		{
			break;
		}
		++it1;
	}

	delete components;

	return 0;
}