#include <bits/stdc++.h>

using namespace std;

int maxProfit(const vector<int> &prices) {
	int n = prices.size();

	if (n == 1) {
		return 0;
	}

	int max_profit = 0;
	pair<int,int> profits[n/2 + 1];
	for (int i = 0; i < n/2 + 1; ++i) {
		profits[i].first = 0;
		profits[i].second = 0;
	}

	int i = 0;
	int count = 0;
	while (i < n-1) {
		while ((i < n-1) and (prices[i+1] <= prices[i])) {
			i++;
		}

		if (i == n-1) {
			break;
		}

		profits[count].first = i++;

		while ((i < n) and (prices[i] >= prices[i-1])) {
			i++;
		}

		profits[count++].second = i-1;
	}

	for (int i = 0; i < count; ++i) {
		max_profit += (prices[profits[i].second] - prices[profits[i].first]);
	}

	return max_profit;
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