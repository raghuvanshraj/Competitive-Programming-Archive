#include <bits/stdc++.h>
 
using namespace std;
 
int find_lis(int *arr, int n) {
	int lis[n] = {1};
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] >= arr[j]) {
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}
 
	return *max_element(lis, lis+n);
}
 
int arr_shuffle(int *arr[3], int n) {
	
 
	int lis[3] = {0};
	for (int i = 0; i < 3; ++i) {
		lis[i] = find_lis(arr[i], n);
	}
 
	sort(lis, lis+3, greater<int>());
 
	return lis[0] + lis[1];
}
 
int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int *arr[3];
	for (int i = 0; i < 3; ++i) {
		arr[i] = new int[n]();
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
 
	cout << arr_shuffle(arr, n);
	
	return 0;
}