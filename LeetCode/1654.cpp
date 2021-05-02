/**
 *    author:	raghuvanshraj
 *    created:	17.11.2020 06:19:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
	return 0;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> forbidden(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> forbidden[i];
	}
	int a, b, x;
	cin >> a >> b >> x;

	cout << minimumJumps(forbidden, a, b, x);

	return 0;
}