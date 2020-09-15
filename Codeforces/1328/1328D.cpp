/**
 *    author:	vulkan
 *    created:	26.03.2020 08:11:57 PM
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

void bfs(vector<vector<int>> &adj_list, vector<int> &colors, vector<bool> &visited, int u) {
	queue<int> qu;
	qu.push(u);
	colors[u] = 0;
	visited[u] = true;
	while (not qu.empty()) {
		int curr = qu.front();
		qu.pop();
		for (int v : adj_list[curr]) {
			if (not visited[v]) {
				visited[v] = true;
				qu.push(v);
				colors[v] = not colors[curr];
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		input_arr(arr, n);

		vector<vector<int>> adj_list(n);
		for (int i = 1; i < n; ++i) {
			if (arr[i] != arr[i - 1]) {
				adj_list[i].push_back(i - 1);
				adj_list[i - 1].push_back(i);
			}
		}

		if (arr[n - 1] != arr[0]) {
			adj_list[n - 1].push_back(0);
			adj_list[0].push_back(n - 1);
		}

		vector<int> colors(n, -1);

		bool found = false;
		for (int i = 0; i < n; ++i) {
			if (adj_list[i].size() < 2) {
				found = true;
			}
		}

		if (not found) {
			for (int i = 0; i < n; ++i) {
				colors[i] = (i % 2) + 1;
			}

			if (colors[0] == colors[n - 1]) {
				colors[n - 1] = 3;
			}
		} else {
			vector<bool> visited(n);
			for (int i = 0; i < n; ++i) {
				if (not visited[i]) {
					bfs(adj_list, colors, visited, i);
				}
			}

			set_arr(colors, n, colors[i] + 1);
		}

		set<int> unique;
		for (int i = 0; i < n; ++i) {
			unique.insert(colors[i]);
		}

		cout << unique.size() << endl;
		print_arr(colors, n);
	}

	return 0;
}