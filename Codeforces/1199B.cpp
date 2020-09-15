#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	double h,l;
	cin >> h >> l;
	double ans = (pow(l,2) / (2 * h)) - h / 2;
	printf("%0.13f\n", ans);
	return 0;
}