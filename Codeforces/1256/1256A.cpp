/**
 *    author:	vulkan
 *    created:	04.11.2019 06:53:08 PM
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

	int q;
	cin >> q;
	while (q--) {
		int a, b, n, s;
		cin >> a >> b >> n >> s;
		int l = min(b, s);
		if ((s - l) % n == 0) {
			if ((s - l) / n <= a) {
				cout << "YES";
			} else {
				cout << "NO";
			}
		} else {
			int first_mult = ((s - l) / n) * n;
			first_mult += n;
			if (first_mult <= s and first_mult / n <= a) {
				cout << "YES";
			} else {
				cout << "NO";
			}
		}

		cout << endl;
	}

	return 0;
}