/**
 *    author:	vulkan
 *    created:	09.04.2020 03:36:58 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define PRINT_ARR(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define PRINT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

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

long solve(vector<vector<int>> &adj_list, vector<vector<int>> &dp, int u, int p, int col_u, int col_p) {
	if (adj_list[u].size() == 1 and p != -1) {
		return col_p == col_u;
	}

	if (dp[u][col_u == col_p] != -1) {
		return dp[u][col_u == col_p];
	}

	long ans = 1;
	long red_inv = 1;
	long black_inv = 1;
	for (int v : adj_list[u]) {
		if (v != p) {
			long vr = solve(adj_list, dp, v, u, 0, col_u);
			long vb = solve(adj_list, dp, v, u, 1, col_u);

			ans = (ans * ((vr + vb) % MOD)) % MOD;
			red_inv = (red_inv * vr) % MOD;
			black_inv = (black_inv * vb) % MOD;
		}
	}

	if (p == -1 or col_u != col_p) {
		if (col_u == 0) {
			ans = (ans - black_inv + MOD) % MOD;
		} else {
			ans = (ans - red_inv + MOD) % MOD;
		}
	}

	dp[u][col_u == col_p] = ans;

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int m = n - 1;
	vector<vector<int>> adj_list(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<vector<int>> dp(n, vector<int>(2, -1));
	long ans1 = solve(adj_list, dp, 0, -1, 0, 0);
	long ans2 = solve(adj_list, dp, 0, -1, 1, 0);

	cout << (ans1 + ans2) % MOD;

	return 0;
}