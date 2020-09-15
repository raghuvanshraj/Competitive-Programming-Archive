/**
 *    author:	vulkan
 *    created:	19.04.2020 11:41:38 PM
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

#define MAX_CHARS 26

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

		auto pre = vectors(MAX_CHARS + 1, n, int()), suff = vectors(MAX_CHARS + 1, n, int());
		pre[arr[0]][0]++;
		for (int i = 1; i <= n - 1; ++i) {
			for (int j = 0; j <= MAX_CHARS; ++j) {
				pre[j][i] = pre[j][i - 1];
			}

			pre[arr[i]][i]++;
		}

		suff[arr[n - 1]][n - 1]++;
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j <= MAX_CHARS; ++j) {
				suff[j][i] = suff[j][i + 1];
			}

			suff[arr[i]][i]++;
		}

		int ans = INT_MIN;
		for (int i = 0; i <= MAX_CHARS; ++i) {
			ans = max(ans, pre[i][n - 1]);
		}

		for (int j = n - 1; j >= 0; --j) {
			int a = arr[j];
			int x = suff[a][j];
			int i = lower_bound(ALL(pre[a]), suff[a][j]) - pre[a].begin();
			if (i >= j) {
				continue;
			}

			int y = INT_MIN;
			for (int b = 0; b <= MAX_CHARS; ++b) {
				y = max(y, pre[b][j - 1] - pre[b][i]);
			}

			ans = max(ans, 2 * x + y);
		}

		cout << ans << endl;
	}

	return 0;
}