/**
 *    author:	vulkan
 *    created:	23.06.2020 02:55:31 PM
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

struct dp_t {
	int cnt;
	pair<int, int> idx;
};

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		INPUT_ARR(arr, n);

		indexed_set<int> s(ALL(arr));

		vector<int> a(n);
		for (int i = 0; i <= n - 1; ++i) {
			a[i] = s.order_of_key(arr[i]);
		}

		int m = s.size();
		vector<int> first_pos(m, -1), last_pos(m, -1), cnt(m);
		for (int i = 0; i <= n - 1; ++i) {
			first_pos[a[i]] = (first_pos[a[i]] == -1) ? i : first_pos[a[i]];
			last_pos[a[i]] = i;
			cnt[a[i]]++;
		}

		vector<int> pre_count(m), till_here(n), from_here(n);
		int ans = 0;
		for (int i = 0; i <= n - 1; ++i) {
			pre_count[a[i]]++;
			if (a[i] > 0) {
				till_here[i] = pre_count[a[i] - 1];
			}
			if (a[i] < m - 1) {
				ans = max(ans, pre_count[a[i]] + cnt[a[i] + 1] - pre_count[a[i] + 1]);
				from_here[i] = cnt[a[i] + 1] - pre_count[a[i] + 1];
			}
		}

		vector<dp_t> dp(m);
		dp[0] = {cnt[0], {first_pos[0], last_pos[0]}};
		for (int i = 1; i <= m - 1; ++i) {
			if (last_pos[i - 1] < first_pos[i]) {
				dp[i] = dp[i - 1];
				dp[i].cnt += cnt[i];
				dp[i].idx.second = last_pos[i];
			} else {
				dp[i] = {cnt[i], {first_pos[i], last_pos[i]}};
			}
		}

		for (int i = 0; i <= m - 1; ++i) {
			dp_t curr_dp = dp[i];
			int curr_ans = curr_dp.cnt;
			curr_ans += till_here[curr_dp.idx.first];
			curr_ans += from_here[curr_dp.idx.second];

			ans = max(ans, curr_ans);
		}

		cout << n - ans << endl;
	}

	return 0;
}