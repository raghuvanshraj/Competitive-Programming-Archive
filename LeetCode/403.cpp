/**
 *    author:	vulkan
 *    created:	14.03.2020 12:23:20 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool canCross(vector<int> &stones) {
	int n = stones.size();
	vector<set<int>> possible_jumps(n);

	if (stones[0] == 0) {
		possible_jumps[0].insert(0);
	}

	if (stones[1] == 1) {
		possible_jumps[1].insert(1);
	}

	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			long dist = long(stones[i] - stones[j]);
			if (possible_jumps[j].find(dist - 1) != possible_jumps[j].end() or
			        possible_jumps[j].find(dist) != possible_jumps[j].end() or
			        possible_jumps[j].find(dist + 1) != possible_jumps[j].end()) {

				possible_jumps[i].insert(dist);
			}
		}
	}

	return (not possible_jumps[n - 1].empty());
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	vector<int> stones(n);
	for (int i = 0; i < n; ++i) {
		cin >> stones[i];
	}

	cout << canCross(stones);

	return 0;
}