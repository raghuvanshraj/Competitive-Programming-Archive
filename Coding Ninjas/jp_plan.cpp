#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pf(x) pop_front(x)

using namespace std;

void _travelToEdge(int **buildings, int n, int m, list< pair<int,int> > *queue, vector< pair<int,int> > path, int j, bool **visited)
{
	if (queue->empty())
	{
		cout << "NO\n";
		return;
	}

	int currx = queue->front().first;
	int curry = queue->front().second;
	path.pb(queue->front());
	queue->pf();

	visited[currx][curry] = true;

	if (currx == 0 or currx == n-1 or curry == 0 or curry == m-1)
	{
		for (pair<int,int> p : path)
		{
			cout << "YES\n";
			cout << path.size() << endl;
			cout << p.first+1 << " " << p.second+1 << endl;
		}
		return;
	}

	vector< pair<int,int> > possible;
	possible.pb(mp(currx-1,curry));
	possible.pb(mp(currx,curry-1));
	possible.pb(mp(currx+1,curry));
	possible.pb(mp(currx,curry+1));

	for (int i = 0; i < possible.size(); ++i)
	{
		int currht = buildings[currx][curry];
		int finalht = buildings[possible[i].first][possible[i].second];

		if (!visited[possible[i].first][possible[i].second] and currht - finalht <= j and currht >= finalht)
		{
			queue->pb(possible[i]);
		}
	}

	_travelToEdge(buildings, n, m, queue, path, j, visited);
}

void travelToEdge(int **buildings, int n, int m, int startx, int starty, int j)
{
	list< pair<int,int> > *queue;
	queue->pb(mp(startx,starty));
	vector< pair<int,int> > path;

	bool **visited = new bool*[n]();
	for (int i = 0; i < n; ++i)
	{
		visited[i] = new bool[m]();
	}

	_travelToEdge(buildings, n, m, queue, path, j, visited);
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	int **buildings = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		buildings[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> buildings[i][j];
		}
	}

	int dx,dy,j;
	cin >> dx >> dy >> j;
	travelToEdge(buildings, n, m, dx-1, dy-1, j);
	return 0;
}