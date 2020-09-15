/**
 *    author:	vulkan
 *    created:	27.01.2020 12:01:37 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define init_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define init_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define init_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
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
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
std::pair<T, U> operator+(const std::pair<T, U> &a, const std::pair<T, U> &b) {
	return {a.first + b.first, a.second + b.second};
}

template <
    typename T,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
std::pair<T, U> operator-(const std::pair<T, U> &a, const std::pair<T, U> &b) {
	return {a.first - b.first, a.second - b.second};
}

bool comp(pii a, pii b) {
	if (a.ff < b.ff) {
		return true;
	} else if (a.ff == b.ff) {
		return a.ss <= b.ss;
	} else {
		return false;
	}
}

void collecting_packages(pii packages[], int n) {
	sort(packages, packages + n, comp);

	bool possible = true;
	for (int i = 1; i < n; ++i) {
		if (packages[i].ss < packages[i - 1].ss) {
			possible = false;
			break;
		}
	}

	if (possible) {
		string ans = "";
		pii curr_pos = {0, 0};
		for (int i = 0; i < n; ++i) {
			pii delta = packages[i] - curr_pos;
			while (delta.ff--) {
				ans = ans + "R";
			}
			while (delta.ss--) {
				ans = ans + "U";
			}

			curr_pos = packages[i];
		}

		cout << "YES" << endl << ans;
	} else {
		cout << "NO";
	}

	cout << endl;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pii packages[n];
		for (int i = 0; i < n; ++i) {
			cin >> packages[i].ff >> packages[i].ss;
		}

		collecting_packages(packages, n);
	}

	return 0;
}