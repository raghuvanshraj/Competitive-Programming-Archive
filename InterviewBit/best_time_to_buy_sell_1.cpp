#include <bits/stdc++.h>

using namespace std;

int maxProfit(const vector<int> &prices) {
	int n = prices.size();
	int *profits = new int[n]();

	stack<int> st;
	for (int i = 0; i < n; ++i) {
		if (st.empty() or prices[i] <= prices[st.top()]) {
			st.push(i);
		} else {
			profits[i] = prices[i] - prices[st.top()];
		}
	}

	while (not st.empty()) {
		int tp = st.top();
		st.pop();
		if (not st.empty()) {
			profits[tp] = prices[tp] - prices[st.top()];
		}
	}

	return *max_element(profits, profits+n);
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