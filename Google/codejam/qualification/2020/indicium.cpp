/**
 *    author:	vulkan
 *    created:	05.04.2020 12:23:51 AM
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

bool is_safe(vector<vector<int>> &ans, int r, int c, int val) {
	int n = ans.size();
	for (int i = 0; i < n; ++i) {
		if (ans[r][i] == val or ans[i][c] == val) {
			return false;
		}
	}

	return true;
}

bool is_complete(vector<vector<int>> &ans, int &r, int &c) {
	int n = ans.size();
	for (r = 0; r < n; ++r) {
		for (c = 0; c < n; ++c) {
			if (ans[r][c] == 0) {
				return false;
			}
		}
	}

	return true;
}

bool solve(vector<vector<int>> &ans, int n, int k) {
	int r = 0, c = 0;
	if (is_complete(ans, r, c)) {
		if (k == 0) {
			return true;
		} else {
			return false;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (is_safe(ans, r, c, i + 1)) {
			ans[r][c] = i + 1;
			if (r == c) {
				k -= i + 1;
			}

			if (k >= 0 and solve(ans, n, k)) {
				return true;
			}

			if (r == c) {
				k += i + 1;
			}

			ans[r][c] = 0;
		}
	}

	return false;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n, k;
		cin >> n >> k;

		vector<vector<int>> ans(n, vector<int>(n));
		bool possible = solve(ans, n, k);

		string ans_string = possible ? "POSSIBLE" : "IMPOSSIBLE";
		cout << "Case #" << t + 1 << ": " << ans_string << endl;
		if (possible) {
			PRINT_ARR2D(ans, n, n);
		}
	}

	return 0;
}