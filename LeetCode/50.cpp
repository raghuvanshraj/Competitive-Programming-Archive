/**
 *    author:	vulkan
 *    created:	07.06.2020 12:14:02 PM
**/
#include <bits/stdc++.h>

using namespace std;

double pow(double a, int b) {
	double res = 1;
	while (b) {
		if (b % 2) {
			res *= a;
		}

		a = a * a;;
		b /= 2;
	}

	return res;
}

double myPow(double x, int n) {
	double ans = pow(x, abs(n));
	if (n < 0) {
		ans = 1.0 / ans;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	double x;
	int n;
	cin >> x >> n;

	printf("%.5f\n", myPow(x, n));

	return 0;
}