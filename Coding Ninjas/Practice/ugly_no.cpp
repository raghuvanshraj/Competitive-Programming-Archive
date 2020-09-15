#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

long long ugly[MAX];

void populateUglyArray() {
	ugly[0] = 1;
	long long next_mult_2 = 2;
	long long next_mult_3 = 3;
	long long next_mult_5 = 5;

	long long i2 = 0;
	long long i3 = 0;
	long long i5 = 0;

	for (int i = 1; i < MAX; ++i) {
		ugly[i] = min(next_mult_2,
					min(next_mult_3,
						next_mult_5));

		if (ugly[i] == next_mult_2) {
			i2++;
			next_mult_2 = ugly[i2] * 2;
		}
		if (ugly[i] == next_mult_3) {
			i3++;
			next_mult_3 = ugly[i3] * 3;
		}
		if (ugly[i] == next_mult_5) {
			i5++;
			next_mult_5 = ugly[i5] * 5;
		}
	}
}

int main(int argc, char const *argv[]) {
	populateUglyArray();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << ugly[n-1] << endl;
	}
	return 0;
}