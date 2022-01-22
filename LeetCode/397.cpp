/**
 *    author:	vulkan
 *    created:	21.01.2022 10:24:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int integerReplacement(int n) {
	queue<pair<LL, int>> qu;
	set<LL> visited;
	visited.insert(n);
	qu.push({n, 0});
	while (true) {
		pair<LL, int> curr = qu.front();
		qu.pop();

		LL x = curr.first;
		int cnt = curr.second;
		while (x % 2 == 0) {
			x /= 2;
			cnt++;
		}

		if (x == 1) {
			return cnt;
		}

		if (not visited.count(x - 1)) {
			visited.insert(x - 1);
			qu.push({x - 1, cnt + 1});
		}
		if (x <= INT_MAX and not visited.count(x + 1)) {
			visited.insert(x + 1);
			qu.push({x + 1, cnt + 1});
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	cout << integerReplacement(n);

	return 0;
}