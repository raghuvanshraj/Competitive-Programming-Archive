#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 9000

using namespace std;

unordered_map<int,int> counts;
unordered_set<int> distinctElements;
bool sieve[MAX];

void createSieve() {
	memset(sieve, true, sizeof(bool) * MAX);
	for (int i = 2; i <= sqrt(MAX); ++i) {
		if (sieve[i]) {
			for (int j = i*i; j < MAX; j += i) {
				sieve[j] = false;
			}
		}
	}
}

int primeXOR() {
	int dp[distinctElements.size()+1][MAX];
	memset(dp, 0, sizeof(int) * (distinctElements.size()+1) * (MAX));

	dp[0][0] = 1;
	int i = 1;
	auto it = distinctElements.begin();
	while (it != distinctElements.end()) {
		int elt = *it;
		int eltCount = counts[elt];
		int inclusion = (eltCount + 1) / 2;
		int exclusion = (eltCount / 2) + 1;
		for (int j = 0; j < MAX; ++j) {
			dp[i][j] = ((dp[i-1][j^elt] * inclusion) % MOD + (dp[i-1][j] * exclusion) % MOD) % MOD;
		}

		++it;
		++i;
	}

	int totalCount = 0;
	for (int i = 2; i < MAX; ++i) {
		if (sieve[i]) {
			totalCount = (totalCount + dp[distinctElements.size()][i]) % MOD;
		}
	}

	return totalCount;
}

int main(int argc, char const *argv[]) {
	createSieve();
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int elt;
			cin >> elt;

			distinctElements.insert(elt);
			counts[elt]++;
		}

		cout << primeXOR() << endl;

		counts.clear();
		distinctElements.clear();
	}
	return 0;
}