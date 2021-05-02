#include <bits/stdc++.h>

using namespace std;

int points(int *goals, int *fouls, int n) {
	int *points = new int[n]();
	int max_points = 0;
	for (int i = 0; i < n; ++i) {
		int curr_points = (goals[i] * 20) - (fouls[i] * 10);
		points[i] = (curr_points >= 0) ? curr_points : 0;
		max_points = max(max_points, points[i]);
	}

	return max_points;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *goals = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> goals[i];
		}

		int *fouls = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> fouls[i];
		}

		cout << points(goals, fouls, n) << endl;
	}
	return 0;
}