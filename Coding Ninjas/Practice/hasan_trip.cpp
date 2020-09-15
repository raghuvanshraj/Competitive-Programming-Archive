#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

struct City {

	int x;
	int y;
	int f;
};

ld operator -(City a, City b) {
	ld diffX = (ld)abs(a.x - b.x);
	ld diffY = (ld)abs(a.y - b.y);

	return sqrt(abs(pow(diffX, 2) + pow(diffY, 2)));
}

ld maxHappiness(City *cities, int n) {

	ld *happiness = new ld[n]();
	happiness[n-1] = (ld)cities[n-1].f;

	for (int i = n-2; i >= 0; --i) {
		
		ld bestHappiness = INT_MIN;
		for (int j = i+1; j < n; ++j) {
			
			ld netHappiness = (ld)(cities[i].f + happiness[j]) - (cities[i] - cities[j]);
			bestHappiness = max(bestHappiness, netHappiness);
		}

		happiness[i] = bestHappiness;
	}

	return happiness[0];
}

int main(int argc, char const *argv[]) {
	
	int n;
	cin >> n;
	City *cities = new City[n]();
	for (int i = 0; i < n; ++i) {
		
		cin >> cities[i].x
			>> cities[i].y
			>> cities[i].f;
	}

	printf("%Lf", maxHappiness(cities, n));
	return 0;
}