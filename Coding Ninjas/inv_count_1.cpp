#include <iostream>

using namespace std;

long long merge(int arr[], int l, int m, int r) {
	long long inv_count = 0;
	int eltLeft = m-l+1;
	int eltRight = r-m;

	int tempL[eltLeft], tempR[eltRight];
	for(int i = 0; i < eltLeft; i++) {
		tempL[i] = arr[l+i];
	}
	for(int j = 0; j < eltRight; j++) {
		tempR[j] = arr[m+1+j];
	}

	int i = 0;
	int j = 0;
	int k = l;		
	while(i < eltLeft and j < eltRight) {
		if(tempL[i] <= tempR[j]) {
			arr[k] = tempL[i];
			i++;
		}
		else {
			arr[k] = tempR[j];
			j++;
			inv_count += m+1-(i+l);
		}
		k++;
	}

	while(i < eltLeft) {
		arr[k] = tempL[i];
		i++;
		k++;
	}
	while(j < eltRight) {
		arr[k] = tempR[j];
		j++;
		k++;
	}
	return inv_count;
}

long long mergeSort(int arr[], int l, int r) {
	
	long long inv_count = 0;
	if(l < r) {
		int m = (l+r)/2;
		inv_count += mergeSort(arr, l, m);
		inv_count += mergeSort(arr, m+1, r);

		inv_count += merge(arr, l, m, r);
	}
	
	return inv_count;
}

long long solve(int A[], int n)
{
	return mergeSort(A, 0, n-1);
}

int main()
{
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
		
	long long ans = solve(A,n);
	cout << ans;
	
	return 0;
}
