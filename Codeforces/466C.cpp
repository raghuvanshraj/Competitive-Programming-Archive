/**
 *    author:	vulkan
 *    created:	18.03.2020 09:18:35 PM
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

typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;

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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> arr(n);
	input_arr(arr, n);

	ll sum = accumulate(all(arr), 0ll);
	if (sum % 3 == 0) {
		ll section_sum = sum / 3ll;
		vector<bool> left_sum(n);
		ll pre_sum = arr[0];
		left_sum[0] = (arr[0] == section_sum);
		for (int i = 1; i < n; ++i) {
			pre_sum += arr[i];
			if (pre_sum == section_sum) {
				left_sum[i] = true;
			}
		}

		vector<int> right_count(n);
		ll suff_sum = arr[n - 1];
		right_count[n - 1] = (arr[n - 1] == section_sum);
		for (int i = n - 2; i >= 0; --i) {
			suff_sum += arr[i];
			if (suff_sum == section_sum) {
				right_count[i] = right_count[i + 1] + 1;
			} else {
				right_count[i] = right_count[i + 1];
			}
		}

		ll count = 0;
		for (int i = 0; i < n - 2; ++i) {
			if (left_sum[i]) {
				count += ll(right_count[i + 2]);
			}
		}

		cout << count;
	} else {
		cout << "0";
	}

	return 0;
}