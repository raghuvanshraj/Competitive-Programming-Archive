/**
 *    author:	vulkan
 *    created:	24.02.2020 09:37:49 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define init_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define init_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define init_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define print_arr(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define print_arr2d(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define dec2d(a,t,n,m) t **a = new t*[n](); for (int i = 0; i < n; ++i) a[i] = new t[m]()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef queue<int> qi;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type
    >
pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first + b.first, a.second + b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type
    >
pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first - b.first, a.second - b.second};
}

void bfs(map<int, vi> &graph, int n, int start, map<int, si> &pairs, vb &visited) {
	queue<int> qu;
	vb is_visited(n);
	qu.push(start);
	is_visited[start] = true;

	si dests = pairs[start];
	while (not qu.empty()) {
		int curr = qu.front();
		if (dests.find(curr) != dests.end()) {
			visited[curr] = true;
		}

		qu.pop();
		vi adj_list = graph[curr];
		for (int i = 0; i < adj_list.size(); ++i) {
			if (not is_visited[adj_list[i]]) {
				qu.push(adj_list[i]);
				is_visited[adj_list[i]] = true;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vi arr(n);
		input_arr(arr, n);

		vi swaps(m);
		input_arr(swaps, m);

		map<int, vi> graph;
		for (int i = 0; i < m; ++i) {
			swaps[i]--;
			graph[swaps[i]].pb(swaps[i] + 1);
			graph[swaps[i] + 1].pb(swaps[i]);
		}

		vi final_arr(n);
		init_arr(final_arr, n, arr[i]);
		sort(all(final_arr));

		map<int, si> pairs;
		for (int i = 0; i < n; ++i) {
			int starting_idx = lower_bound(all(final_arr), arr[i]) - final_arr.begin();
			int ending_idx = upper_bound(all(final_arr), arr[i]) - final_arr.begin();

			for (int j = starting_idx; j < ending_idx; ++j) {
				pairs[i].insert(j);
			}
		}

		vb visited(n);
		for (int i = 0; i < n; ++i) {
			bfs(graph, n, i, pairs, visited);
		}

		if (find(all(visited), false) != visited.end()) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	return 0;
}