/**
 *    author:	vulkan
 *    created:	22.02.2020 03:03:12 PM
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

string all = "abcdefghijklmnopqrstuvwxyz";

void bfs(map<int, si> &graph, vb &visited, string &ans, int start) {
	queue<int> qu;
	qu.push(start);

	while (not qu.empty()) {
		int curr = qu.front();
		qu.pop();
		ans = ans + all[curr];
		si adj_list = graph[curr];
		auto it = adj_list.begin();
		while (it != adj_list.end()) {
			int adj_int = *it;
			if (not visited[adj_int]) {
				qu.push(adj_int);
				visited[adj_int] = true;
			}

			++it;
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string pass;
		cin >> pass;
		if (pass.size() == 1) {
			cout << "YES" << endl << all << endl;
			continue;
		}

		map<int, si> graph;
		for (int i = 1; i < pass.size(); ++i) {
			graph[pass[i - 1] - 'a'].insert(pass[i] - 'a');
			graph[pass[i] - 'a'].insert(pass[i - 1] - 'a');
		}

		bool possible = true, found_end = false;
		for (int i = 0; i < 26; ++i) {
			if (graph.find(all[i] - 'a') != graph.end()) {
				if (graph[all[i] - 'a'].size() > 2) {
					possible = false;
					break;
				} else if (graph[all[i] - 'a'].size() == 1) {
					found_end = true;
				}
			}
		}

		if (possible and found_end) {
			vb visited(26);
			string ans = "";
			for (int i = 0; i < 26; ++i) {
				if (not visited[i] and graph[i].size() == 1) {
					visited[i] = true;
					bfs(graph, visited, ans, i);
				}
			}

			for (int i = 0; i < 26; ++i) {
				if (not visited[i]) {
					ans = ans + all.substr(i, 1);
				}
			}

			cout << "YES" << endl << ans << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}