/**
 *    author:	vulkan
 *    created:	05.05.2020 04:26:33 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define MAX 1000000000
#define MIN -1000000000

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

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

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
    typename = typename enable_if<is_arithmetic<U>::value, U>::type,
    typename V,
    typename = typename enable_if<is_arithmetic<V>::value, V>::type
    >
pair<T, U> operator*(const pair<T, U> &b, const V &a) {
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

struct qu_t {
	int v;
	int p;
	int dist;
};

LL multi_source_bfs(vector<vector<int>> &adj_list, int k) {
	int n = adj_list.size();
	queue<qu_t> qu;
	for (int i = 0; i <= n - 1; ++i) {
		qu.push({i, -1, 0});
	}

	LL count = 0LL;
	while (not qu.empty()) {
		qu_t curr = qu.front();
		int x = curr.v, p = curr.p, dist = curr.dist;
		qu.pop();
		if (dist < k) {
			for (int y : adj_list[x]) {
				if (y != p) {
					qu.push({y, x, dist + 1});
				}
			}
		} else if (dist == k) {
			count++;
		}
	}

	return count / 2LL;
}

vector<vector<LL>> dp;
LL ans = 0;

void solve(vector<vector<int>> &adj_list, int u, int p, int k) {
	dp[u][0] = 1LL;
	for (int v : adj_list[u]) {
		if (v != p) {
			solve(adj_list, v, u, k);
			for (int i = 1; i <= k; ++i) {
				dp[u][i] += dp[v][i - 1];
			}

			LL count = 0LL;
			for (int i = 1; i <= k - 1; ++i) {
				count += dp[v][i - 1] * (dp[u][k - i] - dp[v][k - i - 1]);
			}

			ans += count;
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj_list(n);
	int m = n - 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	dp = vectors(n, k + 1, LL());
	solve(adj_list, 0, -1, k);

	for (int i = 0; i <= n - 1; ++i) {
		ans += dp[i][k];
	}

	cout << ans;

	return 0;
}