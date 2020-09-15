/**
 *    author:	vulkan
 *    created:	22.03.2020 07:49:26 PM
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
#define pb push_back
#define mp make_pair

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

pair<string, string> solve(string s, int a, int b) {
	pair<string, string> ans({"", ""});

	int n = s.size();
	vector<int> left_mod(n), right_mod(n);

	left_mod[0] = (s[0] - '0') % a;
	for (int i = 1; i < n; ++i) {
		left_mod[i] = (left_mod[i - 1] * 10 + s[i] - '0') % a;
	}

	right_mod[n - 1] = (s[n - 1] - '0') % b;
	int mult_factor = 10;
	for (int i = n - 2; i >= 0; --i) {
		right_mod[i] = ((s[i] - '0') * mult_factor + right_mod[i + 1]) % b;

		mult_factor = (mult_factor * 10) % b;
	}

	for (int i = 0; i < n - 1; ++i) {
		if (left_mod[i] == 0 and right_mod[i + 1] == 0 and s[i + 1] != '0') {
			ans.first = s.substr(0, i + 1);
			ans.second = s.substr(i + 1);

			break;
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;

	pair<string, string> ans = solve(s, a, b);
	if (not ans.first.empty() and not ans.second.empty()) {
		cout << "YES" << endl << ans.first << endl << ans.second;
	} else {
		cout << "NO";
	}

	return 0;
}