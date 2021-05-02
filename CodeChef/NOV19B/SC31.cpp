/**
 *    author:	vulkan
 *    created:	07.11.2019 10:51:43 AM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define init_arr(arr,n) for (int i = 0; i < n; ++i) arr[i] = 0
#define init_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = 0;
#define all(v) v.begin(), v.end()
#define dec_i(a,n) int *a = new int[n]()
#define dec_l(a,n) long *a = new long[n]()
#define pb push_back
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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s[n];
		int res = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
			int num = 0;
			int power = 1;
			for (int j = 0; j < 10; ++j) {
				num += ((s[i][j] - '0') * power);
				power *= 2;
			}

			res ^= num;
		}

		int count = 0;
		while (res) {
			count += (res & 1);
			res >>= 1;
		}

		cout << count << endl;
	}

	return 0;
}