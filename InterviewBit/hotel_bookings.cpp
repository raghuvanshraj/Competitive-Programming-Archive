/**
 *    author:	vulkan
 *    created:	13.01.2020 12:36:44 AM
**/
#include <bits/stdc++.h>

using namespace std;

bool hotel(vector<int> &arrivals, vector<int> &departures, int k) {
	if (k == 0) {
		return false;
	}

	int n = arrivals.size();

	if (n == 0) {
		return true;
	}

	vector<pair<int, bool>> events;
	for (int i = 0; i < n; ++i) {
		events.push_back({
			arrivals[i],
			true
		});

		events.push_back({
			departures[i],
			false
		});
	}

	sort(events.begin(), events.end());

	int m = events.size();
	int count = 0;
	for (int i = 0; i < m; ++i) {
		if (events[i].second) {
			count++;
		} else {
			count--;
		}

		if (count > k) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arrivals(n), departures(n);
	for (int i = 0; i < n; ++i) {
		cin >> arrivals[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> departures[i];
	}

	int k;
	cin >> k;

	cout << hotel(arrivals, departures, k);

	return 0;
}