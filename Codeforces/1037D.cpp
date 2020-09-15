/**
 *    author:	vulkan
 *    created:	01.04.2020 09:36:49 PM
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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<set<int>> adj_list(n + 1);
	int m = n - 1;
	while (m--) {
		int u, v;
		cin >> u >> v;

		adj_list[u].insert(v);
		adj_list[v].insert(u);
	}

	vector<int> deg(n + 1);
	SET_ARR(deg, n + 1, adj_list[i].size());

	vector<int> bfs(n);
	INPUT_ARR(bfs, n);
	queue<int> qu;
	qu.push(bfs[0]);
	int curr = 0;
	bool valid = true;
	for (int i = 0; i < n; ++i) {
		if (curr == 0) {
			if (not qu.empty()) {
				curr = qu.front();
				qu.pop();
			} else {
				valid = false;
				break;
			}
		} else {
			while (deg[curr] == 0) {
				if (not qu.empty()) {
					curr = qu.front();
					qu.pop();
				} else {
					valid = false;
					break;
				}
			}

			if (adj_list[curr].count(bfs[i])) {
				deg[curr]--;
				deg[bfs[i]]--;

				qu.push(bfs[i]);
			} else {
				valid = false;
				break;
			}
		}
	}

	for (int i = 0; i < n + 1; ++i) {
		if (deg[i]) {
			valid = false;
			break;
		}
	}

	if (bfs[0] != 1) {
		valid = false;
	}

	string ans = valid ? "yes" : "no";
	cout << ans;

	return 0;
}