#include <iostream>

using namespace std;

long merge(int arr[], int l, int m, int r) {
	long sum = 0;
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
		if(tempL[i] >= tempR[j]) {
			arr[k] = tempL[i];
			i++;
		}
		else {
			arr[k] = tempR[j];
			j++;
			for(int v = i; v < eltLeft; v++)
				sum += tempL[v];
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
	
	return sum;
}

long mergeSort(int arr[], int l, int r) {
	
	long sum = 0;
	if(l < r) {
		int m = (l+r)/2;
		sum += mergeSort(arr, l, m);
		sum += mergeSort(arr, m+1, r);

		sum += merge(arr, l, m, r);
	}
	
	return sum;
}

long solve(int A[], int n)
{
	return mergeSort(A, 0, n-1);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int A[n];
		for(int i = 0; i < n; i++)
			cin >> A[i];
			
		long ans = solve(A,n);
		cout << ans << endl;
	}
	
	return 0;
}
