/**
 *    author:	vulkan
 *    created:	10.04.2020 10:19:29 AM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define MAX 1000000001

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

int bfs(map<int, vector<int>> &adj_list, int u) {
	set<int> visited;
	visited.insert(u);
	queue<int> qu;
	qu.push(u);
	int ans = 0;
	while (not qu.empty()) {
		int curr = qu.front();
		qu.pop();
		for (int v : adj_list[curr]) {
			if (not visited.count(v)) {
				visited.insert(v);
				qu.push(v);
			}
		}

		ans++;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	map<int, vector<int>> adj_list;
	set<int> visited;
	int curr_max = 2;
	while (q--) {
		int u, v;
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
		if (visited.count(u) or visited.count(v)) {
			curr_max = max(curr_max, bfs(adj_list, u));
		}

		cout << curr_max << endl;
		visited.insert(u);
		visited.insert(v);
	}

	return 0;
}