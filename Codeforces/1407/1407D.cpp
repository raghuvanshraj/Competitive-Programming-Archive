/**
 *    author:	vulkan
 *    created:	11.09.2020 10:56:47 AM
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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	INPUT_ARR(arr, n);
	vector<pair<int, int>> nxt(n, { -1, -1}), prv(n, { -1, -1});
	stack<int> inc, dec;
	for (int i = 0; i <= n - 1; ++i) {
		while (not inc.empty() and arr[inc.top()] <= arr[i]) {
			nxt[inc.top()].first = i;
			inc.pop();
		}
		inc.push(i);
		while (not dec.empty() and arr[dec.top()] >= arr[i]) {
			nxt[dec.top()].second = i;
			dec.pop();
		}
		dec.push(i);
	}

	while (not inc.empty()) {
		inc.pop();
	}
	while (not dec.empty()) {
		dec.pop();
	}

	for (int i = n - 1; i >= 0; --i) {
		while (not inc.empty() and arr[inc.top()] <= arr[i]) {
			prv[inc.top()].first = i;
			inc.pop();
		}
		inc.push(i);
		while (not dec.empty() and arr[dec.top()] >= arr[i]) {
			prv[dec.top()].second = i;
			dec.pop();
		}
		dec.push(i);
	}

	vector<int> dp(n, INF);
	dp[0] = 0;
	for (int i = 0; i <= n - 1; ++i) {
		if (prv[i].first != -1) {
			dp[i] = min(dp[i], dp[prv[i].first] + 1);
		}
		if (prv[i].second != -1) {
			dp[i] = min(dp[i], dp[prv[i].second] + 1);
		}
		if (nxt[i].first != -1) {
			dp[nxt[i].first] = min(dp[nxt[i].first], dp[i] + 1);
		}
		if (nxt[i].second != -1) {
			dp[nxt[i].second] = min(dp[nxt[i].second], dp[i] + 1);
		}
	}

	cout << dp[n - 1];

	return 0;
}