/**
 *    author:	vulkan
 *    created:	13.01.2020 02:13:33 PM
**/
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b > a) {
		swap(a, b);
	}

	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b);

	return 0;
}