/**
 *    author:	vulkan
 *    created:	16.04.2020 04:34:03 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define INF 1000000000

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define PRINT_ARR(arr) for (auto x : arr) cout << x << ' '; cout << endl
#define PRINT_ARR2D(arr) for (auto x : arr) { for (auto y : x) cout << y << ' '; cout << endl; }

#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first + b.first, a.second + b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first - b.first, a.second - b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type,
    typename V,
    typename = typename enable_if<is_arithmetic<V>::value, V>::type
    >
pair<T, U> operator*(const V &a, const pair<T, U> &b) {
	return {a * b.first, a * b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
istream & operator>>(istream &input, pair<T, U> &b) {
	input >> b.first >> b.second;
	return input;
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
ostream & operator<<(ostream &output, pair<T, U> &b) {
	output << b.first << ' ' << b.second;
	return output;
}

#define N 51
#define M 51
#define K 1001

int dp[N][M][K];
int n, m;
int count = 0;
string board[N];

int solve(int x, int y, int k) {
	if (x < 0 or y < 0 or x == n or y == m) {
		return INF;
	} else if (k == 0) {
		return (x == 0 and y == 0) ? 0 : INF;
	} else if (x == 0 and y == 0) {
		return 0;
	}

	if (dp[x][y][k] != -1) {
		return dp[x][y][k];
	}

	int down = (x > 0) ? (board[x - 1][y] != 'D') : INF;
	int up = (x < n - 1) ? (board[x + 1][y] != 'U') : INF;
	int right = (y > 0) ? (board[x][y - 1] != 'R') : INF;
	int left = (y < m - 1) ? (board[x][y + 1] != 'L') : INF;

	dp[x][y][k] = min({
		down + solve(x - 1, y, k - 1),
		up + solve(x + 1, y, k - 1),
		right + solve(x, y - 1, k - 1),
		left + solve(x, y + 1, k - 1)
	});

	return dp[x][y][k];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> n >> m >> k;
	INPUT_ARR(board, n);
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			for (int l = 0; l <= k; ++l) {
				dp[i][j][l] = -1;
			}
		}
	}

	pair<int, int> final_loc = { -1, -1};
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			if (board[i][j] == '*') {
				final_loc = {i, j};
				break;
			}
		}
	}

	int i = 0, j = 0;
	int max_count = n * m;
	vector<vector<int>> steps(n, vector<int>(m));
	SET_ARR2D(steps, n, m, INF);
	steps[0][0] = 0;
	while (max_count-- and i < n and j < m) {
		int diff_x = 0, diff_y = 0;
		if (board[i][j] == 'R' and j < m - 1) {
			diff_y = 1;
		} else if (board[i][j] == 'L' and j > 0) {
			diff_y = -1;
		} else if (board[i][j] == 'U' and i > 0) {
			diff_x = -1;
		} else if (board[i][j] == 'D' and i < n - 1) {
			diff_x = 1;
		} else {
			break;
		}

		steps[i + diff_x][j + diff_y] = steps[i][j] + 1;
		i += diff_x;
		j += diff_y;
	}

	pair<int, int> diff = final_loc - make_pair(0, 0);
	int man_dist = abs(diff.first) + abs(diff.second);
	if (k < man_dist) {
		cout << "-1";
	} else {
		cout << solve(final_loc.first, final_loc.second, k);
	}

	return 0;
}