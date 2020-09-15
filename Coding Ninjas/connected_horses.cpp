#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

void dfs(int **board, int x, int y, int &count, bool **visited, int n, int m)
{
	count++;
	visited[x][y] = true;
	vector< pair<int,int> > possible;
	possible.pb(mp(x+2,y+1));
	possible.pb(mp(x+2,y-1));
	possible.pb(mp(x-2,y+1));
	possible.pb(mp(x-2,y-1));
	possible.pb(mp(x+1,y+2));
	possible.pb(mp(x-1,y+2));
	possible.pb(mp(x+1,y-2));
	possible.pb(mp(x-1,y-2));
	for (int i = 0; i < possible.size(); ++i)
	{
		int x1 = possible[i].first;
		int y1 = possible[i].second;

		if ((x1 < n and x1 >= 0 and y1 < m and y1 >= 0) and !visited[x1][y1])
		{
			if (board[x1][y1])
			{
				dfs(board, x1, y1, count, visited, n, m);
			}
		}
	}
}

ll factorial(ll n)
{
	ll ans = 1;
	for (ll i = 0; i < n; ++i)
	{
		ans = (ans * (i+1)) % MOD;
	}

	return ans;
}

ll connected(int **board, int n, int m, bool **visited)
{
	ll ans = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j] and board[i][j])
			{
				int count = 0;
				dfs(board, i, j, count, visited, n, m);
				ans = (ans * factorial(count)) % MOD;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m,q;
		cin >> n >> m >> q;
		int **board = new int*[n]();
		bool **visited = new bool*[n]();
		for (int i = 0; i < n; ++i)
		{
			board[i] = new int[m]();
			visited[i] = new bool[m]();
		}

		for (int i = 0; i < q; ++i)
		{
			int x,y;
			cin >> x >> y;
			board[x-1][y-1] = 1;
		}
		
		cout << connected(board, n, m, visited) << endl;
	}
	return 0;
}