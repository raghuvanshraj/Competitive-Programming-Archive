/**
 *    author:	vulkan
 *    created:	01.02.2020 12:43:55 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define init_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define init_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define init_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define print_arr(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define print_arr2d(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define dec2d(a,t,n,m) t **a = new t*[n](); for (int i = 0; i < n; ++i) a[i] = new t[m]()
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef queue<int> qi;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type
    >
pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first + b.first, a.second + b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type
    >
pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first - b.first, a.second - b.second};
}

int max_occupancy(int arr[], int n) {
	int count = 1;
	int curr_largest = arr[0] - 1;
	for (int i = 1; i < n; ++i) {
		if (curr_largest < arr[i] - 1) {
			curr_largest = arr[i] - 1;
			count++;
		} else if (curr_largest < arr[i]) {
			curr_largest = arr[i];
			count++;
		} else if (curr_largest == arr[i]) {
			curr_largest = arr[i] + 1;
			count++;
		}
	}

	return count;
}

int min_occupancy(int arr[], int n) {
	int dp[n + 1][3];
	init_arr2d(dp, n + 1, 3, 0);

	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i < n + 1; ++i) {
		if (arr[i - 2] < arr[i - 1]) {
			if (arr[i - 1] - arr[i - 2] == 1) {
				dp[i][0] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1]
				});

				dp[i][1] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2]
				});

				dp[i][2] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2] + 1
				});
			} else if (arr[i - 1] - arr[i - 2] == 2) {
				dp[i][0] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2]
				});

				dp[i][1] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2] + 1
				});

				dp[i][2] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2] + 1
				});
			} else {
				dp[i][0] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2] + 1
				});

				dp[i][1] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2] + 1
				});

				dp[i][2] = min({
					dp[i - 1][0] + 1,
					dp[i - 1][1] + 1,
					dp[i - 1][2] + 1
				});
			}
		} else {
			dp[i][0] = dp[i - 1][0];

			dp[i][1] = min({
				dp[i - 1][0] + 1,
				dp[i - 1][1]
			});

			dp[i][2] = min({
				dp[i - 1][0] + 1,
				dp[i - 1][1] + 1,
				dp[i - 1][2]
			});
		}
	}

	return min({
		dp[n][0],
		dp[n][1],
		dp[n][2]
	});
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n];
	input_arr(arr, n);

	sort(arr, arr + n);

	cout << min_occupancy(arr, n) << ' ' << max_occupancy(arr, n) << endl;

	return 0;
}