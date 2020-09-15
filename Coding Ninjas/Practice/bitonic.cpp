#include <bits/stdc++.h>

using namespace std;

int* largestIncreasing(int *arr, int n) {

	int *lis = new int[n]();
	for (int i = 0; i < n; ++i) {

		lis[i] = 1;
	}

	for (int i = 1; i < n; ++i) {
		
		for (int j = 0; j < i; ++j) {
			
			if (arr[i] > arr[j] and lis[i] < lis[j] + 1) {
				
				lis[i] = lis[j] + 1;
			}
		}
	}

	return lis;
}

int* largestDecreasing(int *arr, int n) {

	int *lds = new int[n]();
	for (int i = 0; i < n; ++i) {
		
		lds[i] = 1;
	}

	for (int i = n-2; i >= 0; --i) {
		
		for (int j = n-1; j > i; --j) {
			
			if (arr[i] > arr[j] and lds[i] < lds[j] + 1) {
				
				lds[i] = lds[j] + 1;
			}
		}
	}

	return lds;
}

int largestBitonic(int *arr, int n) {

	int *lis = largestIncreasing(arr, n);
	int *lds = largestDecreasing(arr, n);

	int largest = INT_MIN;
	for (int i = 0; i < n; ++i) {
		largest = max(largest, lis[i] + lds[i] - 1);
	}

	return largest;
}

int main(int argc, char const *argv[]) {
	
	int n;
	cin >> n;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		
		cin >> arr[i];
	}

	cout << largestBitonic(arr, n);
	return 0;
}