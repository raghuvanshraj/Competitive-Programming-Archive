#include <bits/stdc++.h>
#define MAX 5000
#define pb(x) push_back(x)

using namespace std;

vector< vector<int> > edges(MAX);
vector< vector<int> > edgesT(MAX);
stack<int> finishedVertices;

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

void dfs2(int start, bool *isVisited, unordered_set<int> *component)
{
	isVisited[start] = true;
	component->insert(start);
	for (int i = 0; i < edgesT[start].size(); ++i)
	{
		if (!isVisited[edgesT[start][i]])
		{
			dfs2(edgesT[start][i], isVisited, component);
		}
	}
}

unordered_set< unordered_set<int>* > getSCC(int v)
{
	bool *isVisited = new bool[v]();
	unordered_set< unordered_set<int>* > components;
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
			unordered_set<int> *component = new unordered_set<int>();
			dfs2(elt, isVisited, component);
			components.insert(component);
		}
	}

	return components;
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

		unordered_set< unordered_set<int>* > components = getSCC(v);
		// auto it1 = components.begin();
		// while (it1 != components.end())
		// {
		// 	unordered_set<int> *component = *it1;
		// 	auto it2 = component->begin();
		// 	while (it2 != component->end())
		// 	{
		// 		cout << *it2 + 1 << " ";
		// 		++it2;
		// 	}
		// 	cout << endl;
		// 	++it1;
		// }

		unordered_set< unordered_set<int>* >::iterator it1 = components.begin();
		set<int> final;
		while (it1 != components.end())
		{
			unordered_set<int> *component = *it1;
			bool *isVisited = new bool[v]();
			dfs3(*(component->begin()), isVisited);
			bool found = true;
			for (int i = 0; i < v; ++i)
			{
				if (isVisited[i] and component->find(i) == component->end())
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				unordered_set<int>::iterator it2 = component->begin();
				while (it2 != component->end())
				{
					final.insert(*it2);
					++it2;
				}
			}
			++it1;
		}

		set<int>::iterator it3 = final.begin();
		while (it3 != final.end())
		{
			cout << *it3 + 1 << " ";
			++it3;
		}
		cout << endl;

		for (int i = 0; i < v; ++i)
		{
			edges[i].clear();
			edgesT[i].clear();
		}
	}
	return 0;
}