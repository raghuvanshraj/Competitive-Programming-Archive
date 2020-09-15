#include <bits/stdc++.h>

using namespace std;

int kadane(int *sum, int n) {

	int best = INT_MIN;
	int curr = 0;
	for (int i = 0; i < n; ++i) {
		
		curr += sum[i];
		best = max(best, curr);
		curr = (curr < 0) ? 0 : curr;
	}

	return best;
}

int maxSumRect(int **rect, int n, int m) {

	int maxSum = INT_MIN;
	for (int i = 0; i < m; ++i) {
		
		int *sum = new int[n]();
		for (int j = i; j < m; ++j) {
			
			for (int k = 0; k < n; ++k) {
				
				sum[k] += rect[k][j];
			}

			maxSum = max(kadane(sum, n), maxSum);
		}
	}

	return maxSum;
}

int main(int argc, char const *argv[]) {
	
	int n, m;
	cin >> n >> m;
	int **rect = new int*[n]();
	for (int i = 0; i < n; ++i) {
		
		rect[i] = new int[m]();
		for (int j = 0; j < m; ++j) {
			
			cin >> rect[i][j];
		}
	}

	cout << maxSumRect(rect, n, m);
	return 0;
}