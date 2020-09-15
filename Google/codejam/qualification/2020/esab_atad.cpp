/**
 *    author:	vulkan
 *    created:	06.04.2020 12:07:47 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define PRINT_ARR(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define PRINT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

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

void flip(vector<int> &ans, int b) {
	for (int i = 1; i <= b; ++i) {
		ans[i] ^= 1;
	}
}

int query(int i) {
	cout << i << endl;
	int val;
	cin >> val;
	return val;
}

int main(int argc, char const *argv[]) {
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int t, b;
	cin >> t >> b;
	while (t--) {
		vector<int> ans(b + 1);
		int l = 1, r = b;
		for (int q = 0; q < 150; q += 2) {
			if (q % 10 == 0 and q != 0) {
				int same_bit = -1, diff_bit = -1;
				for (int i = 1; i < l; ++i) {
					if (ans[i] == ans[b + 1 - i]) {
						same_bit = i;
					} else {
						diff_bit = i;
					}

					if (same_bit != -1 and diff_bit != -1) {
						break;
					}
				}

				if (same_bit != -1 and diff_bit != -1) {
					if (query(diff_bit) != ans[diff_bit]) {
						if (query(same_bit) != ans[same_bit]) {
							flip(ans, b);
						} else {
							reverse(ans.begin() + 1, ans.end());
						}
					} else {
						if (query(same_bit) != ans[same_bit]) {
							flip(ans, b);
							reverse(ans.begin() + 1, ans.end());
						}
					}
				} else {
					query(1);
					if (query(1) != ans[1]) {
						flip(ans, b);
					}
				}

				q += 2;
			}

			ans[l] = query(l);
			ans[r] = query(r);
			l++;
			r--;

			if (l > r) {
				for (int i = 1; i <= b; ++i) {
					cout << ans[i];
				}
				cout << endl;
				string res;
				cin >> res;
				assert(res == "Y");
				break;
			}
		}
	}

	return 0;
}