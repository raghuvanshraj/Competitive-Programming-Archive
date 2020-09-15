/**
 *    author:	vulkan
 *    created:	24.03.2020 09:59:59 AM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define set_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define set_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define set_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define print_arr(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define print_arr2d(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define dec2d(a,t,n,m) t **a = new t*[n](); for (int i = 0; i < n; ++i) a[i] = new t[m]()

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;

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

vector<int> dp;
vector<int> ans;
vector<int> colors;
vector<vector<int>> graph;

void dfs(int v, int p = -1) {
	dp[v] = colors[v];
	for (int c : graph[v]) {
		if (c == p) {
			continue;
		}

		dfs(c, v);
		dp[v] += max(dp[c], 0);
	}
}

void dfs2(int v, int p = -1) {
	ans[v] = dp[v];
	for (int c : graph[v]) {
		if (c == p) {
			continue;
		}

		dp[v] -= max(dp[c], 0);
		dp[c] += max(dp[v], 0);
		dfs2(c, v);
		dp[c] -= max(dp[v], 0);
		dp[v] += max(dp[c], 0);
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	colors = vector<int>(n);
	input_arr(colors, n);
	set_arr(colors, n, (colors[i] == 0) ? colors[i] - 1 : colors[i]);
	graph = vector<vector<int>>(n);
	int m = n - 1;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dp = vector<int>(n);
	ans = vector<int>(n);
	dfs(0);
	dfs2(0);

	print_arr(ans, n);

	return 0;
}