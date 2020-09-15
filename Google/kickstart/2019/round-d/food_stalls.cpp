#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull foodStalls(ull *distances, ull *costs, ull n, ull k) {
	ull minCost = INT_MAX;
	for (ull i = 0; i < n; ++i) {
		vector<ull> foodStallCosts;
		for (ull j = 0; j < n; ++j) {
			if (j != i) {
				ull diff;
				if (distances[i] > distances[j]) {
					diff = distances[i] - distances[j];
				} else {
					diff = distances[j] - distances[i];
				}

				foodStallCosts.push_back(costs[j] + diff);
			}
		}

		sort(foodStallCosts.begin(), foodStallCosts.end());
		ull currCost = costs[i];
		for (ull j = 0; j < k; ++j) {
			currCost += foodStallCosts[j];
		}

		minCost = min(minCost, currCost);
	}

	return minCost;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		ull k,n;
		cin >> k >> n;
		ull *distances = new ull[n]();
		for (int i = 0; i < n; ++i) {
			cin >> distances[i];
		}

		ull *costs = new ull[n]();
		for (int i = 0; i < n; ++i) {
			cin >> costs[i];
		}

		cout << "Case #" << i+1 << ": " << foodStalls(distances, costs, n, k) << endl;
	}
	return 0;
}