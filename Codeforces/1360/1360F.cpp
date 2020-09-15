/**
 *    author:	vulkan
 *    created:	26.06.2020 10:54:47 AM
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

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		INPUT_ARR(s, n);

		bool possible = false;
		string ans;
		for (int i = 0; i <= n - 1; ++i) {
			int max_diff = 0;
			int s_idx = -1, idx1 = -1, idx2 = -1;
			vector<string> candidates;
			for (int j = 0; j <= n - 1; ++j) {
				int curr_diff = 0;
				for (int idx = 0; idx <= m - 1; ++idx) {
					if (s[i][idx] != s[j][idx]) {
						curr_diff++;
						if (idx1 == -1) {
							idx1 = idx;
						} else if (idx2 == -1) {
							idx2 = idx;
						}
					}
				}

				max_diff = max(max_diff, curr_diff);

				if (curr_diff == 2) {
					if (s_idx == -1) {
						s_idx = j;
					}
				}
			}

			if (max_diff > 2) {
				continue;
			} else if (max_diff <= 1) {
				ans = s[i];
				possible = true;
				break;
			}

			if (s_idx != -1) {
				string curr = s[i];
				curr[idx1] = s[s_idx][idx1];
				candidates.push_back(curr);
				curr = s[i];
				curr[idx2] = s[s_idx][idx2];
				candidates.push_back(curr);
			}

			for (string candidate : candidates) {
				int max_diff = 0;
				for (int i = 0; i <= n - 1; ++i) {
					int curr_diff = 0;
					for (int idx = 0; idx <= m - 1; ++idx) {
						if (candidate[idx] != s[i][idx]) {
							curr_diff++;
						}
					}

					max_diff = max(max_diff, curr_diff);
				}

				if (max_diff == 1) {
					ans = candidate;
					possible = true;
					break;
				}
			}
		}

		if (not possible) {
			cout << "-1" << endl;
		} else {
			cout << ans << endl;
		}
	}

	return 0;
}