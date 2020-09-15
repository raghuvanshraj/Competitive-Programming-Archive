#include <bits/stdc++.h>

using namespace std;

bool victory(int *players, int *villains, int n) {
	sort(players, players+n);
	sort(villains, villains+n);

	// for (int i = 0; i < n; ++i) {
	// 	cout << players[i] << ' ' << villains[i] << endl;
	// }

	int currPlayer = 0;
	int currVillain = 0;
	while (currPlayer < n and currVillain < n) {
		while ((players[currPlayer] >= villains[currVillain]) and currVillain < n) {
			players[currPlayer] -= villains[currVillain];
			currVillain++;
		}
		currPlayer++;
	}

	// cout << currPlayer << ' ' << currVillain;

	if (currVillain == n) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *villains = new int[n]();
		int *players = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> villains[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> players[i];
		}

		string ans = (victory(players, villains, n)) ? "WIN" : "LOSE";
		cout << ans << endl;
	}
	return 0;
}