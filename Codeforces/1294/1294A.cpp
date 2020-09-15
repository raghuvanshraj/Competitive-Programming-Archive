/**
 *    author:	vulkan
 *    created:	27.01.2020 10:37:05 AM
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

void collecting_coins(int a, int b, int c, int n) {
	if (((a - 2 * b + c + n) % 3 == 0) and
	        ((c - 2 * a + b + n) % 3 == 0) and
	        ((b - 2 * c + a + n) % 3 == 0)) {

		int x = (a - 2 * b + c + n) / 3;
		int y = (c - 2 * a + b + n) / 3;
		int z = (b - 2 * c + a + n) / 3;

		if (x >= 0 and y >= 0 and z >= 0) {
			cout << "YES";
		} else {
			cout << "NO";
		}
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
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		collecting_coins(a, b, c, n);
	}

	return 0;
}