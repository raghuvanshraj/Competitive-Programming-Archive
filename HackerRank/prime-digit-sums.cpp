/**
 *    author:	vulkan
 *    created:	17.04.2020 01:34:04 PM
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

#define N 400000

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int sieve[46] = {false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, true, false, false, false, false, false, true, false, false, false, true, false, true, false, false};
	const vector<int> third_num[19] = {
		{2, 3, 5, 7},
		{1, 2, 4, 6},
		{0, 1, 3, 5, 9},
		{0, 2, 4, 8},
		{1, 3, 7, 9},
		{0, 2, 6, 8},
		{1, 5, 7},
		{0, 4, 6},
		{3, 5, 9},
		{2, 4, 8},
		{1, 3, 7, 9},
		{0, 2, 6, 8},
		{1, 5, 7},
		{0, 4, 6},
		{3, 5, 9},
		{2, 4, 8},
		{1, 3, 7},
		{0, 2, 6},
		{1, 5}
	};

	auto dp = vectors(2, 10, 10, 10, 10, ll());
	vector<int> ans(N + 1);
	ans[1] = 9;
	ans[2] = 90;
	ans[3] = 303;
	for (int a = 1; a <= 9; ++a) {
		for (int b = 0; b <= 9; ++b) {
			for (int c : third_num[a + b]) {
				for (int d : third_num[b + c]) {
					if (sieve[a + b + c + d]) {
						dp[0][a][b][c][d]++;
						ans[4] = (ans[4] + dp[0][a][b][c][d]) % MOD;
					}
				}
			}
		}
	}

	for (int i = 4; i <= N - 1; ++i) {
		ll curr_ans = 0;
		for (int a = 0; a <= 9; ++a) {
			for (int b = 0; b <= 9; ++b) {
				for (int c : third_num[a + b]) {
					for (int d : third_num[b + c]) {
						if (sieve[a + b + c + d] and dp[i % 2][a][b][c][d]) {
							ll curr = dp[i % 2][a][b][c][d];
							dp[i % 2][a][b][c][d] = 0LL;
							for (int x : third_num[c + d]) {
								if (sieve[b + c + d + x] and sieve[a + b + c + d + x]) {
									dp[(i + 1) % 2][b][c][d][x] += curr;
									dp[(i + 1) % 2][b][c][d][x] %= MOD;
									curr_ans += curr;
									curr_ans %= MOD;
								}
							}
						}
					}
				}
			}
		}

		ans[i + 1] = curr_ans % MOD;
	}

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}

	return 0;
}