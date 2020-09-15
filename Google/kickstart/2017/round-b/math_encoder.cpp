/**
 *    author:	vulkan
 *    created:	01.11.2019 09:03:44 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define push_back pb
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
#define deci(a,n) int *a = new int[n]()
#define decl(a,n) long *a = new long[n]()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef unordered_map<string, int> umsi;
typedef set<int> si;
typedef unordered_set<int> usi;

long math_encoder(int arr[], int n) {
	sort(arr, arr + n);
	long f[n], b[n];
	f[0] = 1;
	b[n - 1] = 1;
	for (int i = 1; i < n; ++i) {
		f[i] = ((long)2 * f[i - 1]) % MOD;
		b[n - 1 - i] = ((long)2 * b[n - i]) % MOD;
	}

	long ans = 0;
	for (int i = 0; i < n; ++i) {
		long inc = ((f[i] * (long)arr[i]) % MOD - (b[i] * (long)arr[i]) % MOD + MOD) % MOD;
		ans = (ans + inc) % MOD;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	rep(t, 0, T) {
		int n;
		cin >> n;
		int arr[n];
		rep(i, 0, n) {
			cin >> arr[i];
		}

		long ans = math_encoder(arr, n);

		cout << "Case #" << t + 1 << ": " << ans << endl;
	}

	return 0;
}