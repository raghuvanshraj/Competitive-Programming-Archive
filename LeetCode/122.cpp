/**
 *    author:	vulkan
 *    created:	08.03.2020 08:44:35 AM
**/
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices) {
	int n = prices.size();
	int total_profit = 0;
	int cp = -1, sp = -1;
	for (int i = 1; i < n; ++i) {
		if (cp == -1) {
			if (prices[i] >= prices[i - 1]) {
				cp = prices[i - 1];
			}
		} else {
			if (prices[i] <= prices[i - 1]) {
				sp = prices[i - 1];
			}
		}

		if (cp != -1 and sp != -1) {
			total_profit += sp - cp;
			sp = cp = -1;
		}
	}

	if (cp != -1 and prices[n - 1] >= prices[n - 2]) {
		total_profit += prices[n - 1] - cp;
	}

	return total_profit;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; ++i) {
		cin >> prices[i];
	}

	cout << maxProfit(prices);

	return 0;
}