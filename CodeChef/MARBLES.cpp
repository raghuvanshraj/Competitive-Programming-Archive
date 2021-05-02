#include <bits/stdc++.h>

using namespace std;

long long int binomial(long long int n, long long int k) {
	if (k > n-k) {
		k = n-k;
	}

	long long int ans = 1;
	for (long long int i = 0; i < k; ++i) {
		ans *= (n-i);
		ans /= (i+1);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	long long int t;
	cin >> t;
	while (t--) {
		long long int n,k;
		cin >> n >> k;
		cout << binomial(n-1, k-1) << endl;
	}
	return 0;
}