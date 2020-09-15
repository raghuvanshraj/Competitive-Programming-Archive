/**
 *    author:	vulkan
 *    created:	22.01.2020 04:03:52 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

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
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	long a[n], b[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	long ans[2][n];
	init_arr2d(ans, 2, n, 0);

	ans[0][0] = (long)a[0];
	ans[1][0] = (long)b[0];
	for (int i = 1; i < n; ++i) {
		if (i % 2 == 0) {
			ans[1][i] = ans[1][i - 1] + b[i];
			ans[0][i] = ans[0][i - 1] + a[i];
		} else {
			ans[1][i] = ans[1][i - 1] + a[i];
			ans[0][i] = ans[0][i - 1] + b[i];
		}
	}

	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;
		type--;
		l--;
		r--;
		int f_idx = (type ^ (l % 2));
		if (l > 0) {
			cout << ans[f_idx][r] - ans[f_idx][l - 1] << endl;
		} else {
			cout << ans[f_idx][r] << endl;
		}
	}

	return 0;
}