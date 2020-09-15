#include <bits/stdc++.h>
#define MOD 1000000007
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;

long BFS(bool **board, bool **isVisited, int row, int col, int n, int m) {
	isVisited[row][col] = true;
	long count = 0;
	queue<pair<int,int>> vertices;
	vertices.push(mp(row, col));
	while (not vertices.empty()) {
		pair<int,int> currVertex = vertices.front();
		vertices.pop();
		int x = currVertex.first;
		int y = currVertex.second;
		isVisited[x][y] = true;

		vector<pair<int,int>> possiblePositions;
		possiblePositions.pb(mp(x-2,y-1));
		possiblePositions.pb(mp(x-2,y+1));
		possiblePositions.pb(mp(x+2,y+1));
		possiblePositions.pb(mp(x+2,y-1));
		possiblePositions.pb(mp(x-1,y+2));
		possiblePositions.pb(mp(x-1,y-2));
		possiblePositions.pb(mp(x+1,y+2));
		possiblePositions.pb(mp(x+1,y-2));
		
		count = (count + 1) % MOD;
		for (int i = 0; i < possiblePositions.size(); ++i) {
			int x1 = possiblePositions[i].first;
			int y1 = possiblePositions[i].second;

			if (not ((x1 >= 0 and x1 < n) and (y1 >= 0 and y1 < m))) {
				continue;
			}

			if (board[x1][y1] and (not isVisited[x1][y1])) {
				vertices.push(possiblePositions[i]);
				isVisited[x1][y1] = true;
			}
		}
	}

	return count;
}

long factorial(long n) {
	long ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = (ans * i) % MOD;
	}

	return ans;
}

long possiblePermutations(bool **board, int n, int m) {
	long totalPermutations = 1;
	bool **isVisited = new bool*[n]();
	for (int i = 0; i < n; ++i) {
		isVisited[i] = new bool[m]();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((not isVisited[i][j]) and board[i][j]) {
				long count = BFS(board, isVisited, i, j, n, m);
				totalPermutations = (totalPermutations * factorial(count)) % MOD;
			}
		}
	}
	
	return totalPermutations;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n,m,q;
		cin >> n >> m >> q;
		bool **board = new bool*[n]();
		for (int i = 0; i < n; ++i) {
			board[i] = new bool[m]();
		}

		for (int i = 0; i < q; ++i) {
			int x,y;
			cin >> x >> y;
			board[x-1][y-1] = true;
		}

		cout << possiblePermutations(board, n, m) << endl;
	}
	return 0;
}