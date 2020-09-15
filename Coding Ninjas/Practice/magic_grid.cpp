#include <bits/stdc++.h>

using namespace std;

int minHealthNeeded(int **magrid, int r, int c) {

	int **minHealth = new int*[r]();
	for (int i = 0; i < r; ++i) {

		minHealth[i] = new int[c]();
	}

	minHealth[r-1][c-1] = 1;
	for (int i = r-2; i >= 0; --i) {
		
		minHealth[i][c-1] = max(minHealth[i+1][c-1] - magrid[i][c-1], 1);
	}
	for (int i = c-2; i >= 0; --i) {
		
		minHealth[r-1][i] = max(minHealth[r-1][i+1] - magrid[r-1][i], 1);
	}

	for (int i = r-2; i >= 0; --i) {
		
		for (int j = c-2; j >= 0; --j) {
		
			minHealth[i][j] = max(min(minHealth[i+1][j], minHealth[i][j+1]) - magrid[i][j], 1);
		}
	}

	return minHealth[0][0];
}

int main(int argc, char const *argv[]) {
	
	int t;
	cin >> t;
	while (t--) {
		
		int r, c;
		cin >> r >> c;
		int **magrid = new int*[r]();
		for (int i = 0; i < r; ++i) {

			magrid[i] = new int[c]();
			for (int j = 0; j < c; ++j) {
				
				cin >> magrid[i][j];
			}
		}

		cout << minHealthNeeded(magrid, r, c) << endl;
	}
	return 0;
}