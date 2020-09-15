/**
 *    author:	vulkan
 *    created:	23.03.2020 11:31:54 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define set_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define set_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define set_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define print_arr(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define print_arr2d(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define dec2d(a,t,n,m) t **a = new t*[n](); for (int i = 0; i < n; ++i) a[i] = new t[m]()

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;

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

bool in(int sum, int l, int r) {
	return (l <= sum and sum <= r);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> sleep_times(n);
	input_arr(sleep_times, n);

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));

	dp[0][0] = 0;
	vector<int> pre_sum(n + 1);
	for (int i = 1; i < n + 1; ++i) {
		pre_sum[i] = pre_sum[i - 1] + sleep_times[i - 1];
		if (in(pre_sum[i] % h, l, r)) {
			dp[i][0] = dp[i - 1][0] + 1;
		} else {
			dp[i][0] = dp[i - 1][0];
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			int curr = in((pre_sum[i] - j + h) % h, l, r);
			if (dp[i - 1][j] != INT_MIN and dp[i - 1][j - 1] != INT_MIN) {
				dp[i][j] = max({
					dp[i][j],
					dp[i - 1][j] + curr,
					dp[i - 1][j - 1] + curr
				});
			} else if (dp[i - 1][j] != INT_MIN) {
				dp[i][j] = max({
					dp[i][j],
					dp[i - 1][j] + curr
				});
			} else if (dp[i - 1][j - 1] != INT_MIN) {
				dp[i][j] = max({
					dp[i][j],
					dp[i - 1][j - 1] + curr
				});
			}
		}
	}

	cout << *max_element(all(dp[n]));

	return 0;
}