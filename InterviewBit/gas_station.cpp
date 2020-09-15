#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int> &a, vector<int> &b) {
	int n = a.size();
	int i = 0, j = 1;
	int currGas = a[i] - b[i];
	while (currGas < 0 or i != j) {
		while (currGas < 0 and i != j) {
			currGas -= (a[i] - b[i]);
			i = (i+1) % n;

			if (i == 0) {
				return -1;
			}
		}

		currGas += (a[j] - b[j]);
		j = (j+1) % n;
	}

	return i;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	cout << canCompleteCircuit(a,b);
	return 0;
}