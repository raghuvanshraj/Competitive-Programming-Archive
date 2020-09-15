#include <iostream>

using namespace std;

long long solve(long long A[], int n)
{
	if(n == 0)
		return 0;
		
	long long ret = solve(A, n-1);
	long long count = 0;
	for(int i = n-2; i >= 0; i--)
	{
		if(A[n-1] < A[i])
			count++;
	}
	
	return count+ret;
}

int main()
{
	int n;
	cin >> n;
	long long A[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
		
	cout << solve(A, n);
	
	return 0;
}
