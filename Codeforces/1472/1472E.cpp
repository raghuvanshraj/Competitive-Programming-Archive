/**
 *    author:	vulkan
 *    created:	09.01.2021 01:01:50 PM
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

struct person_t {
	int idx;
	LL h;
	LL w;
};

bool comp_h(person_t &a, person_t &b) {
	return a.h > b.h;
}

int binary_search(vector<person_t> &arr, int n, int x) {
	int i = 0, j = n - 1;
	int ans = -1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (arr[mid].h >= x) {
			i = mid + 1;
		} else {
			ans = mid;
			j = mid - 1;
		}
	}

	return ans;
}

void solve(vector<person_t> &arr, vector<int> &ans, vector<int> &suff, int n, bool do_swap = false) {
	for (int i = 0; i <= n - 1; ++i) {
		if (ans[arr[i].idx] == -1) {
			int x = arr[i].h, y = arr[i].w;
			if (do_swap) {
				swap(x, y);
			}
			int j = binary_search(arr, n, x);
			if (j == i) {
				j++;
			}
			if (j != -1 and j < n and arr[suff[j]].w < y) {
				ans[arr[i].idx] = arr[suff[j]].idx + 1;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<person_t> arr(n);
		for (int i = 0; i <= n - 1; ++i) {
			arr[i].idx = i;
			cin >> arr[i].h >> arr[i].w;
		}

		sort(ALL(arr), comp_h);

		vector<int> suff(n);
		suff[n - 1] = n - 1;
		for (int i = n - 2; i >= 0; --i) {
			suff[i] = (arr[i].w < arr[suff[i + 1]].w) ? i : suff[i + 1];
		}

		vector<int> ans(n, -1);
		solve(arr, ans, suff, n);
		solve(arr, ans, suff, n, true);

		PRINT_ARR(ans);
	}

	return 0;
}