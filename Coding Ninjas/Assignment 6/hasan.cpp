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
	dp[n-1] = cities[n-1].f;
	for (int i = n-2; i >= 0; --i)
	{
		ld diff_x = cities[i].x - cities[n-1].x;
		ld diff_y = cities[i].y - cities[n-1].y;
		dp[i] = cities[i].f + dp[n-1] - sqrt(pow(diff_x,2) + pow(diff_y,2));
		for (int j = i+1; j < n-1; ++j)
		{
			diff_x = cities[i].x - cities[j].x;	
			diff_y = cities[i].y - cities[j].y;
			dp[i] = max(dp[i], cities[i].f + dp[j] - sqrt(pow(diff_x,2) + pow(diff_y,2)));
		}
	}

	return dp[0];
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