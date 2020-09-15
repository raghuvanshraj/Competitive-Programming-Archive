#include <bits/stdc++.h>

using namespace std;

int findMinCost(int matArr[4], int arr[4]) {
	sort(matArr, matArr+4);
	int cost = 0;
	for (int i = 0; i < 4; ++i) {
		cost += abs(matArr[i] - arr[i]);
	}

	return cost;
}

int minCost(int arr[3][3]) {
	int matCornerElts[] = {arr[0][0], arr[0][2], arr[2][0], arr[2][2]};
	int matSideElts[] = {arr[0][1], arr[1][0], arr[1][2], arr[2][1]};
	int cornerElts[] = {2,4,6,8};
	int sideElts[] = {1,3,7,9};

	return findMinCost(matCornerElts, cornerElts) + findMinCost(matSideElts, sideElts) + abs(arr[1][1] - 5);
}

int main(int argc, char const *argv[]) {
	int arr[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> arr[i][j];
		}
	}

	cout << minCost(arr);
	return 0;
}