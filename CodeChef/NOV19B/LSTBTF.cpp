/**
 *    author:	vulkan
 *    created:	09.11.2019 12:15:55 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX_SQUARE 81000001

#define init_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define init_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define init_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
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
typedef pair<long, long> pll;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

bool* precompute_arr() {
	dec(is_square, bool, MAX_SQUARE);
	for (int i = 1; i * i <= MAX_SQUARE; ++i) {
		is_square[i * i] = true;
	}

	return is_square;
}

string lstbtf(int n, bool *is_square) {
	int max_sum = 81 * n;

	dec(sum_squares, psi, max_sum + 1);
	for (int j = 1; j < 10; ++j) {
		sum_squares[j * j].ff = to_string(j);
		sum_squares[j * j].ss = 1;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < 10; ++j) {
			for (int sum = i; sum <= max_sum - (j * j); ++sum) {
				if (sum_squares[sum].ss == i) {
					sum_squares[sum + (j * j)].ff = sum_squares[sum].ff + to_string(j);
					sum_squares[sum + (j * j)].ss = sum_squares[sum].ss + 1;
				}
			}
		}
	}

	for (int i = n; i <= max_sum; ++i) {
		if (sum_squares[i].ss == n and is_square[i]) {
			// sort(all(sum_squares[i].ff));
			return sum_squares[i].ff;
		}
	}

	return "-1";
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool *is_square = precompute_arr();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << lstbtf(n, is_square) << endl;
	}

	return 0;
}