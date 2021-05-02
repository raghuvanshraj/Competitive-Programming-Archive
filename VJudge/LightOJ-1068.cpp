/**
 *    author:	vulkan
 *    created:	14.08.2020 01:11:26 AM
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

template <typename T, typename U>
istream& operator>>(istream &input, pair<T, U> &b) {
	input >> b.first >> b.second;
	return input;
}

template <typename T, typename U>
ostream& operator<<(ostream &output, pair<T, U> &b) {
	output << b.first << ' ' << b.second;
	return output;
}

int log(int x) {
	int res = 0;
	while (x) {
		x /= 10;
		res++;
	}

	return res;
}

vector<int> convert(int x, int d) {
	vector<int> xd(d);
	for (int i = d - 1; i >= 0; --i) {
		xd[i] = x % 10;
		x /= 10;
	}

	return xd;
}

int dp[11][2][91][901];

int solve(int x, int k) {
	if (x == 0) {
		return 1;
	}

	int d = log(x);
	vector<int> xd = convert(x, d);

	for (int i = 0; i <= xd[0]; ++i) {
		dp[0][i < xd[0]][i][i % k]++;
	}

	for (int i = 1; i <= d - 1; ++i) {
		for (int sum = 0; sum <= 9 * i; ++sum) {
			for (int mod = 0; mod <= min(k - 1, 900); ++mod) {
				for (int x = 0; x <= 9; ++x) {
					dp[i][1][sum + x][(mod * 10 + x) % k] += dp[i - 1][1][sum][mod];
				}
				for (int x = 0; x <= xd[i]; ++x) {
					dp[i][x < xd[i]][sum + x][(mod * 10 + x) % k] += dp[i - 1][0][sum][mod];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9 * d; ++i) {
		if (i % k == 0) {
			ans += dp[d - 1][0][i][0] + dp[d - 1][1][i][0];
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case " << t << ": ";
		int a, b, k;
		cin >> a >> b >> k;

		memset(dp, 0, sizeof(dp));
		int ans_b = solve(b, k);
		memset(dp, 0, sizeof(dp));
		int ans_a = solve(a - 1, k);
		cout << ans_b - ans_a << endl;
	}

	return 0;
}