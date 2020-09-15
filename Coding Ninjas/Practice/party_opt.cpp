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
	Party dp[budget+1];
	memset(dp, 0, sizeof(Party) * (budget+1));

	for (int i = 0; i < n; ++i) {
		for (int j = budget; j >= parties[i].cost; --j) {
			if (dp[j].fun < parties[i].fun + dp[j-parties[i].cost].fun) {
				Party temp = parties[i] + dp[j-parties[i].cost];
				dp[j] = temp;
			}
		}
	}

	int maxFun = dp[budget].fun;
	int minPrice = INT_MAX;
	for (int i = 0; i < budget+1; ++i) {
		if (dp[i].fun == maxFun) {
			minPrice = min(dp[i].cost, minPrice);
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