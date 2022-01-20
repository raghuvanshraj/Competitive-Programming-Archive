/**
 *    author:	vulkan
 *    created:	19.01.2022 09:59:35 PM
**/
#include <bits/stdc++.h>

using namespace std;

int countPrimes(int n) {
	if (n < 2) {
		return 0;
	}

	n--;
	vector<bool> sieve(n + 1, true);
	sieve[0] = sieve[1] = false;
	for (int i = 2; i * i <= n; ++i) {
		if (sieve[i]) {
			for (int j = i * i; j <= n; j += i) {
				sieve[j] = false;
			}
		}
	}

	return accumulate(sieve.begin(), sieve.end(), 0);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	cout << countPrimes(n);

	return 0;
}