/**
 *    author:	vulkan
 *    created:	30.01.2022 03:13:31 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool in_range(int i, int n) {
	return i >= 0 and i <= n;
}

int minimumJumps(vector<int> &forbidden, int a, int b, int d) {
	set<int> forbidden_set(forbidden.begin(), forbidden.end());
	int stop = a + b + max(d, *(--forbidden_set.end()));
	queue<tuple<int, int, bool>> qu;
	qu.push({0, 0, true});
	set<pair<int, int>> visited;
	visited.insert({0, true});
	while (not qu.empty()) {
		auto[curr, jumps, back] = qu.front();
		qu.pop();
		if (forbidden_set.count(curr)) {
			continue;
		}

		if (curr == d) {
			return jumps;
		}
		int x = curr + a;
		int y = curr - b;
		if (in_range(x, stop) and not visited.count({x, true})) {
			visited.insert({x, true});
			qu.push({x, jumps + 1, true});
		} else if (in_range(x, stop) and not visited.count({x, false})) {
			visited.insert({x, false});
			qu.push({x, jumps + 1, true});
		}

		if (back and in_range(y, stop) and not visited.count({y, true})) {
			visited.insert({y, true});
			qu.push({y, jumps + 1, false});
		}
	}

	return -1;
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