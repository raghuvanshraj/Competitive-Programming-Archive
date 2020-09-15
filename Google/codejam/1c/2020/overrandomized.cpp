/**
 *    author:	vulkan
 *    created:	02.05.2020 03:26:53 PM
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

#define NUM 10000

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int u;
		cin >> u;
		string max_lim(u, '9');
		vector<bool> valid(26);
		vector<pair<int, int>> range(26, {0, 9});
		int lim = NUM;
		while (lim--) {
			string q, r;
			cin >> q >> r;
			if (q == "-1") {
				q = max_lim;
			}

			if (q.size() > r.size()) {
				range[r[0] - 'A'].first = max(range[r[0] - 'A'].first, 1);
			} else {
				range[r[0] - 'A'].first = max(range[r[0] - 'A'].first, 1);
				range[r[0] - 'A'].second = min(range[r[0] - 'A'].second, q[0] - '0');
				if (r.size() > 1 and q[0] == '1') {
					range[r[1] - 'A'].second = min(range[r[1] - 'A'].second, q[1] - '0');
					range[r[1] - 'A'].first = min(range[r[1] - 'A'].first, range[r[1] - 'A'].second);
				}
			}

			for (char c : r) {
				valid[c - 'A'] = true;
			}
		}

		// char y = 'A';
		// for (auto x : range) {
		// 	cout << y << ": " << x << endl;
		// 	y++;
		// }

		string ans(10, ' ');
		for (int i = 0; i <= 9; ++i) {
			for (int j = 0; j <= 25; ++j) {
				if (valid[j]) {
					int curr = max(range[j].first, i);
					if (curr == range[j].second and curr == i) {
						ans[i] = 'A' + j;
						break;
					}
				}
			}

			if (ans[i] == ' ') {
				for (int j = 0; j <= 25; ++j) {
					int curr = max(range[j].first, i);
					if (curr == i) {
						ans[i] = 'A' + j;
						break;
					}
				}
			}
		}

		cout << "Case #" << t + 1 << ": " << ans << endl;
	}

	return 0;
}