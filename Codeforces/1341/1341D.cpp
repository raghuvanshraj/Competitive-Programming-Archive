/**
 *    author:	vulkan
 *    created:	26.04.2020 09:42:29 PM
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

int encoding[10] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};

int bin2dec(string s) {
	int n = s.size();
	int mult = 1;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		int curr = s[i] - '0';
		ans += curr * mult;
		mult *= 2;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<string> nums(n);
	INPUT_ARR(nums, n);
	vector<int> nums_int(n);
	for (int i = 0; i <= n - 1; ++i) {
		nums_int[i] = bin2dec(nums[i]);
	}

	map<int, int> decoding;
	for (int i = 0; i <= 9; ++i) {
		decoding[encoding[i]] = i;
	}

	auto dp = vectors(n + 1, k + 1, pair<bool, int>());

	for (int i = n; i >= 1; --i) {
		if (decoding.count(nums_int[i - 1])) {
			dp[i][0] = {true, decoding[nums_int[i - 1]]};
		} else {
			break;
		}
	}

	for (int j = 1; j <= k; ++j) {
		for (int l = 9; l >= 0; --l) {
			if ((nums_int[n - 1] & encoding[l]) == nums_int[n - 1]) {
				int diff = nums_int[n - 1] ^ encoding[l];
				int x = __builtin_popcount(diff);
				if (j == x) {
					dp[n][j] = {true, l};
					break;
				}
			}
		}
	}

	for (int i = n - 1; i >= 1; --i) {
		for (int j = 1; j <= k; ++j) {
			for (int l = 9; l >= 0; --l) {
				if ((nums_int[i - 1] & encoding[l]) == nums_int[i - 1]) {
					int diff = nums_int[i - 1] ^ encoding[l];
					int x = __builtin_popcount(diff);
					if (j >= x and dp[i + 1][j - x].first) {
						dp[i][j] = {true, l};
						break;
					}
				}
			}
		}
	}

	if (dp[1][k].first) {
		vector<int> ans(n);
		int j = k;
		for (int i = 1; i <= n; ++i) {
			ans[i - 1] = dp[i][j].second;
			int diff = nums_int[i - 1] ^ encoding[dp[i][j].second];
			int x = __builtin_popcount(diff);
			j -= x;
		}

		for (int x : ans) {
			cout << x;
		}
	} else {
		cout << "-1";
	}

	return 0;
}