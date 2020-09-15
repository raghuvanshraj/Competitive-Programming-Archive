/**
 *    author:	vulkan
 *    created:	23.04.2020 07:43:32 PM
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

#define POW2(n) (1LL<<(n))

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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(ALL(arr));

	vector<pair<int, int>> dp(n + 1, {MAX, 0});
	dp[0] = {0, -1};
	for (int i = 0; i <= n - 1; ++i) {
		if (i + 2 < n) {
			if (dp[i + 3].first > dp[i].first + arr[i + 2].first - arr[i].first) {
				dp[i + 3] = {dp[i].first + arr[i + 2].first - arr[i].first, 3};
			}
		}
		if (i + 3 < n) {
			if (dp[i + 4].first > dp[i].first + arr[i + 3].first - arr[i].first) {
				dp[i + 4] = {dp[i].first + arr[i + 3].first - arr[i].first, 4};
			}
		}
		if (i + 4 < n) {
			if (dp[i + 5].first > dp[i].first + arr[i + 4].first - arr[i].first) {
				dp[i + 5] = {dp[i].first + arr[i + 4].first - arr[i].first, 5};
			}
		}
	}

	int res = dp[n].first, k = dp[n].second;
	vector<int> groups(n);
	int i = n;
	int curr_k = k;
	while (i >= 2) {
		int prev = i - dp[i].second;
		for (int j = i; j >= prev + 1; --j) {
			groups[j - 1] = curr_k;
		}
		curr_k--;
		i = prev;
	}

	k -= curr_k;

	vector<int> actual_groups(n);
	for (int i = 0; i <= n - 1; ++i) {
		actual_groups[arr[i].second] = groups[i] - curr_k;
	}

	cout << res << ' ' << k << endl;
	PRINT_ARR(actual_groups);

	return 0;
}