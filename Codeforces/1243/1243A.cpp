/**
 *    author:	vulkan
 *    created:	06.11.2019 09:09:59 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define pb push_back
#define all(v) v.begin(), v.end()
#define deci(a,n) int *a = new int[n]()
#define decl(a,n) long *a = new long[n]()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		sort(arr, arr + n);
		int ans = -1;
		for (int i = 1; i <= n; ++i) {
			int idx = lower_bound(arr, arr + n, i) - arr;
			if (n - idx >= i) {
				ans = i;
			} else {
				break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}