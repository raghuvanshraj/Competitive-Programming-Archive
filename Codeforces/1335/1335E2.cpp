/**
 *    author:	vulkan
 *    created:	19.04.2020 09:41:14 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define INF 1000000000

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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		INPUT_ARR(arr, n);

		int pre[201][n], suff[201][n];
		for (int i = 0; i <= 200; ++i) {
			for (int j = 0; j <= n - 1; ++j) {
				pre[i][j] = 0;
				suff[i][j] = 0;
			}
		}
		// vector<vector<int>> pre(201, vector<int>(n)), suff(201, vector<int>(n));
		pre[arr[0]][0]++;
		for (int i = 1; i <= n - 1; ++i) {
			for (int j = 0; j <= 200; ++j) {
				pre[j][i] = pre[j][i - 1];
			}

			pre[arr[i]][i]++;
		}

		suff[arr[n - 1]][n - 1]++;
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j <= 200; ++j) {
				suff[j][i] = suff[j][i + 1];
			}

			suff[arr[i]][i]++;
		}

		// for (int i = 0; i <= n-1; ++i) {
		// 	cout << suff[1][i] << ' ' << suff[2][i] << ' ' << suff[3][i] << endl;
		// }

		int ans = INT_MIN;
		for (int i = 0; i <= 200; ++i) {
			ans = max(ans, pre[i][n - 1]);
		}

		// cout << ans << endl;

		for (int j = n - 1; j >= 0; --j) {
			int a = arr[j];
			int x = suff[a][j];
			int i = lower_bound(pre[a], pre[a] + n, suff[a][j]) - pre[a];
			if (i >= j) {
				continue;
			}
			// cout << i << ' ' << j << endl;
			int y = INT_MIN;
			for (int b = 0; b <= 200; ++b) {
				y = max(y, pre[b][j - 1] - pre[b][i]);
			}

			ans = max(ans, 2 * x + y);

			// cout << i << ' ' << j << ": " << x << ' ' << y << endl;
		}

		cout << ans << endl;
	}

	return 0;
}