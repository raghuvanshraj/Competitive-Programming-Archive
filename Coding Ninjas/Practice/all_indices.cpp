#include <bits/stdc++.h>

using namespace std;

void findIndices(int arr[], int n, int x, int output[], int &k, int pos) {

	if (pos == n) {
		
		return;
	}

	if (arr[pos] == x) {
		
		output[k++] = pos;
	}

	findIndices(arr, n, x, output, k, pos+1);
}

int allIndexes(int arr[], int n, int x, int output[]) {

	int k = 0;
	findIndices(arr, n, x, output, k, 0);
	return k;
}

int main(int argc, char const *argv[]) {
	
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		
		cin >> arr[i];
	}

	int x;
	cin >> x;
	int output[n];
	int size = allIndices(arr, n, x, output);
	for (int i = 0; i < size; ++i) {
		
		cout << output[i] << ' ';
	}

	return 0;
}