/**
 *    author:	vulkan
 *    created:	19.02.2020 06:17:31 PM
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

void bfs(vector<int> edges[], vector<int> &start, vector<int> &end, vector<int> &ans) {
	queue<int> qu;
	int n = start.size() + end.size();
	vector<int> dist(n, INT_MAX);
	for (int i = 0; i < start.size(); ++i) {
		qu.push(start[i]);
		dist[start[i]] = 0;
	}

	while (not qu.empty()) {
		int curr = qu.front();
		qu.pop();
		for (int i = 0; i < edges[curr].size(); ++i) {
			if (dist[edges[curr][i]] == INT_MAX) {
				dist[edges[curr][i]] = dist[curr] + 1;
				qu.push(edges[curr][i]);
			}
		}
	}

	for (int i = 0; i < end.size(); ++i) {
		ans[end[i]] = dist[end[i]];
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	input_arr(arr, n);

	vector<int> edges[n];
	for (int i = 0; i < n; ++i) {
		int left = i - arr[i];
		int right = i + arr[i];

		if (left >= 0) {
			edges[left].pb(i);
		}

		if (right < n) {
			edges[right].pb(i);
		}
	}

	vector<int> ans(n);
	init_arr(ans, n, INT_MAX);

	vector<int> odd, even;
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 2) {
			odd.pb(i);
		} else {
			even.pb(i);
		}
	}

	bfs(edges, odd, even, ans);
	bfs(edges, even, odd, ans);

	replace(all(ans), INT_MAX, -1);
	print_arr(ans, n);

	return 0;
}