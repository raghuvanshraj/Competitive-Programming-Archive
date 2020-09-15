/**
 *    author:	vulkan
 *    created:	28.08.2019 05:40:01 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct city_t {
	double x, y, f;
};

double find_distance(city_t a, city_t b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double max_happiness(city_t *cities, int n) {
	double dp[n];
	dp[0] = cities[0].f;
	for (int i = 1; i < n; ++i) {
		dp[i] = INT_MIN;;
		for (int j = 0; j < i; ++j) {
			double happiness_increase = cities[i].f - find_distance(cities[i], cities[j]);
			dp[i] = max(dp[i], dp[j] + happiness_increase);
		}
	}

	return dp[n - 1];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	city_t *cities = new city_t[n]();
	for (int i = 0; i < n; ++i) {
		cin >> cities[i].x >> cities[i].y >> cities[i].f;
	}

	printf("%.6f\n", max_happiness(cities, n));

	return 0;
}