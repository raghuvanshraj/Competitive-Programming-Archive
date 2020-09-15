#include <bits/stdc++.h>

using namespace std;

int minJumps(int *steps, int n) {
	int *minJumpsTillHere = new int[n]();
	memset(minJumpsTillHere, -1, sizeof(int) * n);

	minJumpsTillHere[0] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (steps[j] == 0 or minJumpsTillHere[j] == -1) {
				continue;
			}

			if (i - j <= steps[j]) {
				if (minJumpsTillHere[i] == -1) {
					minJumpsTillHere[i] = minJumpsTillHere[j] + 1;
				} else {
					minJumpsTillHere[i] = min(minJumpsTillHere[i], minJumpsTillHere[j] + 1);
				}
			}
		}
	}

	// cout << endl << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cout << minJumpsTillHere[i] << ' ';
	// }

	return minJumpsTillHere[n-1];
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *steps = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> steps[i];
		}

		cout << minJumps(steps, n) << endl;
	}
	return 0;
}