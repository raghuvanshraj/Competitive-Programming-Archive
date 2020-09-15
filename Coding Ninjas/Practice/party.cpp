#include <bits/stdc++.h>

using namespace std;

class Party {
public:
	int cost, fun;
	Party operator +(Party &a) {
		Party c;
		c.cost = a.cost + this->cost;
		c.fun = a.fun + this->fun;

		return c;
	}

	void operator =(Party &a) {
		this->cost = a.cost;
		this->fun = a.fun;
	}
};

void optimizeBudget(Party *parties, int budget, int n) {
	Party dp[budget+1][n+1];

	for (int i = 0; i < budget+1; ++i) {
		for (int j = 0; j < n+1; ++j) {
			if (i == 0 or j == 0) {
				dp[i][j].cost = 0;
				dp[i][j].fun = 0;
				continue;
			}

			if (parties[j-1].cost <= i) {
				if (parties[j-1].fun + dp[i-parties[j-1].cost][j-1].fun > dp[i][j-1].fun) {
					Party temp = parties[j-1] + dp[i-parties[j-1].cost][j-1];
					dp[i][j] = temp;
				} else {
					dp[i][j] = dp[i][j-1];
				}
			} else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}

	int maxFun = dp[budget][n].fun;
	int minPrice = INT_MAX;
	for (int i = 0; i < budget+1; ++i) {
		if (dp[i][n].fun == maxFun) {
			minPrice = min(minPrice, dp[i][n].cost);
		}
	}

	cout << minPrice << ' ' << maxFun << endl;
}

int main(int argc, char const *argv[]) {
	while (true) {
		int budget, n;
		cin >> budget >> n;

		if (budget == 0) {
			break;
		}

		Party *parties = new Party[n]();
		for (int i = 0; i < n; ++i) {
			cin >> parties[i].cost >> parties[i].fun;
		}

		optimizeBudget(parties, budget, n);
	}
	return 0;
}