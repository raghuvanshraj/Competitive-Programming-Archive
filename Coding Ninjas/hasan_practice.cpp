#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

struct city
{
	int x;
	int y;
	int f;
};

ld maxHappiness(city *cities, int n)
{
	ld *dp = new ld[n];
	dp[0] = cities[0].f;
	for (int i = 1; i < n; ++i)
	{
		ld diff_x = cities[i].x - cities[0].x;
		ld diff_y = cities[i].y - cities[0].y;
		dp[i] = cities[i].f + dp[0] - sqrt(pow(diff_x,2) + pow(diff_y,2));
		for (int j = 1; j < i; ++j)
		{
			diff_x = cities[i].x - cities[j].x;
			diff_y = cities[i].y - cities[j].y;
			dp[i] = max(dp[i], dp[j] + cities[i].f - sqrt(pow(diff_x,2) + pow(diff_y,2)));
		}
	}

	return dp[n-1];
}

int main()
{
	cout.precision(20);
	int n;
	cin >> n;
	city *cities = new city[n];
	for(int i = 0; i < n; i++)
	{
		cin >> cities[i].x >> cities[i].y >> cities[i].f;
	}
	printf("%Lf", maxHappiness(cities,n));
	return 0;
}