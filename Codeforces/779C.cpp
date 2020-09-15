#include <bits/stdc++.h>

using namespace std;

struct Item {
	int currPrice;
	int discountedPrice;
	int discount;
};

bool comp(Item a, Item b) {
	return a.discount < b.discount;
}

int minCost(Item *items, int n, int k) {
	sort(items, items+n, comp);
	int cost = 0;
	int i = 0;
	while (i < n) {
		if (items[i].discount >= 0) {
			break;
		}

		cost += items[i].currPrice;
		i++;
	}

	while (i < k) {
		cost += items[i].currPrice;
		i++;
	}

	while (i < n) {
		cost += items[i].discountedPrice;
		i++;
	}

	return cost;
}

int main(int argc, char const *argv[]) {
	int n,k;
	cin >> n >> k;
	Item *items = new Item[n]();
	for (int i = 0; i < n; ++i) {
		cin >> items[i].currPrice;
	}
	for (int i = 0; i < n; ++i) {
		cin >> items[i].discountedPrice;
	}
	for (int i = 0; i < n; ++i) {
		items[i].discount = items[i].currPrice - items[i].discountedPrice;
	}

	cout << minCost(items, n, k);
	return 0;
}