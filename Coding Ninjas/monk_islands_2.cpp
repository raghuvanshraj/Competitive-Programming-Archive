#include <bits/stdc++.h>
#define MAX 100000
#define MAX_VALUE 10000000

using namespace std;

int dp[MAX];
vector<vector<int>> edges(MAX);

int _shortestPath(int n, int start, bool *isVisited)
{
    if (start == n-1)
    {
        return 0;
    }

    if (dp[start] > -1)
    {
        return dp[start];
    }

    int route = MAX_VALUE;
    for (int i = 0; i < edges[start].size(); ++i)
    {
        if (!isVisited[edges[start][i]])
        {
            isVisited[edges[start][i]] = true;
            route = min(_shortestPath(n, edges[start][i], isVisited) + 1, route);
            isVisited[edges[start][i]] = false;
        }
    }

    dp[start] = route;
    return route;
}

int shortestPath(int n, int m)
{
    bool *isVisited = new bool[n]();
    isVisited[0] = true;
    return _shortestPath(n, 0, isVisited);
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(int) * MAX);
        for (int i = 0; i < MAX; ++i)
        {
            edges[i].clear();
        }
      
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < m; ++i)
        {
            int s,e;
            cin >> s >> e;
            edges[s-1].push_back(e-1);
            edges[e-1].push_back(s-1);
        }

        int route = shortestPath(n, m);
        cout << route << endl;
    }
    
    return 0;
}