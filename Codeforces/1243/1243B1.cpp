/**
 *    author:	vulkan
 *    created:	06.11.2019 09:30:37 PM
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

void is_possible(string s, string t) {
	int a = -1, b = -1;
	int n = s.size();
	bool possible = true;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			if (a == -1) {
				a = i;
			} else if (b == -1) {
				b = i;
			} else {
				possible = false;
				break;
			}
		}
	}

	if (possible) {
		if (t[b] == t[a] and s[b] == s[a]) {
			cout << "Yes";
		} else {
			cout << "No";
		}
	} else {
		cout << "No";
	}

	cout << endl;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		is_possible(s, t);
	}

	return 0;
}