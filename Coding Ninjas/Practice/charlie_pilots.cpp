#include <bits/stdc++.h>

using namespace std;

struct Pilot {
	int captain;
	int assistant;
};

int minimiseSalary(Pilot *pilots, int n) {
	
}

int main(int argc, char const *argv[]) {
	int n;
	Pilot *pilots = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> pilots[i].captain >> pilots[i].assistant;
	}

	cout << minimiseSalary(pilots, n, 0);

	return 0;
}