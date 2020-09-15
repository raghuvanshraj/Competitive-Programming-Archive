/**
 *    author:	vulkan
 *    created:	02.04.2020 05:24:24 PM
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

pair<vector<int>, vector<int>> dec2bin(ll l, ll r) {
	vector<int> l_bin, r_bin;
	while (r) {
		l_bin.push_back(l & 1);
		r_bin.push_back(r & 1);

		l /= 2;
		r /= 2;
	}

	reverse(ALL(l_bin));
	reverse(ALL(r_bin));

	return {l_bin, r_bin};
}

ll bin2dec(vector<int> bin) {
	ll ans = 0;
	ll m = 1;
	int n = bin.size();
	for (int i = n - 1; i >= 0; --i) {
		ans += ll(bin[i]) * m;
		m *= 2LL;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		ll l, r;
		cin >> l >> r;
		pair<vector<int>, vector<int>> bin = dec2bin(l, r);

		vector<int> l_bin = bin.first;
		vector<int> r_bin = bin.second;

		vector<int> ans(r_bin.size(), 1);
		int size = r_bin.size();
		bool possible = false;
		for (int i = 0; i < size; ++i) {
			if (l_bin[i] == 0 and r_bin[i] == 1) {
				ans[i] = 0;
				possible = true;

				break;
			} else if (l_bin[i] == 0 and r_bin[i] == 0) {
				ans[i] = 0;
			}
		}

		if (possible) {
			int opt1 = accumulate(ALL(ans), 0);
			int opt2 = accumulate(ALL(r_bin), 0);

			if (opt1 >= opt2) {
				cout << bin2dec(ans);
			} else {
				cout << r;
			}
		} else {
			cout << r;
		}

		cout << endl;
	}

	return 0;
}