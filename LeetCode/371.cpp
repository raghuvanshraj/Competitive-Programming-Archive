/**
 *    author:	vulkan
 *    created:	20.01.2022 10:28:40 AM
**/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> add(int x, int y, int carry) {
	if (x and y) {
		return {carry, 1};
	} else if ((not x) and (not y)) {
		return {carry, 0};
	}

	return {not carry, carry};
}

int getSum(int a, int b) {
	if (b > a) {
		swap(a, b);
	}

	int ans = 0;
	int carry = 0;
	while (a) {
		pair<int, int> curr = add(a & 1, b & 1, carry);
		ans <<= 1;
		ans |= curr.first;
		carry = curr.second;

		a >>= 1;
		b >>= 1;
	}

	if (carry) {
		ans <<= 1;
		ans |= carry;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int a, b;
	cin >> a >> b;

	cout << getSum(a, b);

	return 0;
}