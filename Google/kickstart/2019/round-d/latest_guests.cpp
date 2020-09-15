#include <bits/stdc++.h>

using namespace std;

vector<int> latestGuests(int *guestLoc, int *guestType, vector<int> *consulates, int n, int g, int m) {
	vector<int> count(g);
	for (int i = 0; i < g; ++i) {
		count[i] = 1;
	}

	bool *hasChanged = new bool[n]();
	while (m--) {
		for (int i = 0; i < g; ++i) {
			guestLoc[i] = (guestLoc[i] + guestType[i] + n) % n;
			count[i]++;
			hasChanged[guestLoc[i]] = true;
		}

		for (int i = 0; i < n; ++i) {
			if (hasChanged[i]) {
				int consulateSize = consulates[i].size();
				for (int j = 0; j < consulateSize; ++j) {
					count[consulates[i][j]]--;
				}
			}

			consulates[i].erase(consulates[i].begin(), consulates[i].end());
		}

		for (int i = 0; i < g; ++i) {
			consulates[guestLoc[i]].push_back(i);
		}

		for (int i = 0; i < n; ++i) {
			hasChanged[i] = false;
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, g, m;
		cin >> n >> g >> m;
		int *guestLoc = new int[g]();
		int *guestType = new int[g]();
		vector<int> *consulates = new vector<int>[n]();
		for (int j = 0; j < g; ++j) {
			int loc;
			cin >> loc;
			guestLoc[j] = loc-1;
			char type;
			cin >> type;
			guestType[j] = (type == 'C') ? 1 : -1;
			consulates[loc-1].push_back(j);
		}

		vector<int> count = latestGuests(guestLoc, guestType, consulates, n, g, m);
		cout << "Case #" << i+1 << ": ";
		for (int i = 0; i < g; ++i) {
			cout << count[i] << ' ';
		}

		cout << endl;
	}

	return 0;
}