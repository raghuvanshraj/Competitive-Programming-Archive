/**
 *    author:	vulkan
 *    created:	07.11.2019 04:30:56 PM
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
typedef pair<long, long> pii;
typedef map<string, int> msi;
typedef map<long, long> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

bool is_consonant(char c) {
	return c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u';
}

bool check_string(string s) {
	int prev_cons = -1;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (is_consonant(s[i])) {
			if (prev_cons == -1 or i - prev_cons > 2) {
				prev_cons = i;
			} else {
				return false;
			}
		}
	}

	return true;
}

mii prime_factorize(ll num) {
	mii primes;
	while (num % 2 == 0) {
		primes[2]++;
		num /= 2;
	}

	for (long i = 3; i * i <= num; i += 2) {
		while (num % i == 0) {
			primes[i]++;
			num /= i;
		}
	}

	if (num > 2) {
		primes[num]++;
	}

	return primes;
}

double weirdo(string s[], int l) {
	long alice_strings = 0, bob_strings = 0;
	long char_counts[26][2], string_counts[26][2];
	init_arr2d(char_counts, 26, 2, 0);
	init_arr2d(string_counts, 26, 2, 0);
	for (int i = 0; i < l; ++i) {
		bool is_alice = check_string(s[i]);
		if (is_alice) {
			alice_strings++;
		} else {
			bob_strings++;
		}

		int n = s[i].size();
		bool found[26];
		init_arr(found, 26, false);
		for (int j = 0; j < n; ++j) {
			char_counts[s[i][j] - 'a'][is_alice]++;
			if (not found[s[i][j] - 'a']) {
				found[s[i][j] - 'a'] = true;
				string_counts[s[i][j] - 'a'][is_alice]++;
			}
		}
	}

	mii primes_ans;
	for (int i = 0; i < 26; ++i) {
		if (string_counts[i][1] > 0) {
			mii primes_x = prime_factorize(string_counts[i][1]);
			mii primes_f = prime_factorize(char_counts[i][1]);

			mii::iterator curr_prime;
			for (curr_prime = primes_x.begin(); curr_prime != primes_x.end(); ++curr_prime) {
				primes_ans[curr_prime->ff] += curr_prime->ss;
			}

			for (curr_prime = primes_f.begin(); curr_prime != primes_f.end(); ++curr_prime) {
				primes_ans[curr_prime->ff] -= (alice_strings * curr_prime->ss);
			}
		}

		if (string_counts[i][0] > 0) {
			mii primes_x = prime_factorize(string_counts[i][0]);
			mii primes_f = prime_factorize(char_counts[i][0]);

			mii::iterator curr_prime;
			for (curr_prime = primes_x.begin(); curr_prime != primes_x.end(); ++curr_prime) {
				primes_ans[curr_prime->ff] -= curr_prime->ss;
			}

			for (curr_prime = primes_f.begin(); curr_prime != primes_f.end(); ++curr_prime) {
				primes_ans[curr_prime->ff] += (bob_strings * curr_prime->ss);
			}
		}
	}

	mii::iterator curr_prime = primes_ans.begin();
	vector<pii> positive, negative;
	while (curr_prime != primes_ans.end()) {
		if (curr_prime->ss > 0) {
			positive.pb({curr_prime->ff, curr_prime->ss});
		} else if (curr_prime->ss < 0) {
			negative.pb({curr_prime->ff, curr_prime->ss});
		}

		++curr_prime;
	}

	long n = positive.size(), m = negative.size();
	long i = 0, j = 0;
	double ans = 1;
	double max_double = numeric_limits<double>::max();
	double min_double = numeric_limits<double>::min();
	while (i < n and j < m) {
		if (max_double / (double)positive[i].ff > ans) {
			ans *= (double)positive[i].ff;
			positive[i].ss--;
			if (positive[i].ss == 0) {
				i++;
			}
		}

		if (min_double * (double)negative[j].ff < ans) {
			ans /= (double)negative[j].ff;
			negative[j].ss++;
			if (negative[j].ss == 0) {
				j++;
			}
		}
	}

	bool flag = false;
	while (i < n) {
		if (max_double / (double)positive[i].ff < ans) {
			flag = true;
			break;
		} else {
			ans *= (double)positive[i].ff;
			positive[i].ss--;
			if (positive[i].ss == 0) {
				i++;
			}
		}
	}

	while (j < m) {
		while (negative[j].ss++) {
			ans /= negative[j].ff;
		}

		j++;
	}

	if (flag or ans > 10000000) {
		return -1;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int l;
		cin >> l;
		string s[l];
		for (int i = 0; i < l; ++i) {
			cin >> s[i];
		}

		double ans = weirdo(s, l);
		if (ans != -1) {
			printf("%.7f\n", ans);
		} else {
			printf("Infinity\n");
		}
	}

	return 0;
}