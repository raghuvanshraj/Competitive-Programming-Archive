#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int q;
	cin >> q;
	while (q--) {
		long x,y,k;
		cin >> x >> y >> k;
		long turn = (x+y) / k;
		if (turn % 2 == 0) {
			cout << "Chef\n";
		}
		else {
			cout << "Paja\n";
		}
	}
	return 0;
}