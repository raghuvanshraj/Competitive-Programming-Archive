#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

vector< vector<ull> > matrixMultiply(vector< vector<ull> > A, vector< vector<ull> > B)
{
	int rows = A.size();
	int cols = B[0].size();
	vector< vector<ull> > AB(rows);
	for(int i = 0; i < rows; i++)
		AB[i].resize(cols);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			AB[i][j] = 0;
			for(int k = 0; k < B.size(); k++)
			{
				AB[i][j] += (A[i][k]*B[k][j]) % (MOD-1);
			}
		}
	}

	return AB;
}

vector< vector<ull> > matrixExponent(vector< vector<ull> > A, ull n)
{
	vector< vector<ull> > R;
	R.push_back({1,0});
	R.push_back({0,1});

	if(n == 0)
		return R;

	if(n%2 == 0)
	{
		return matrixExponent(matrixMultiply(A,A), n/2);
	}
	else
	{
		return matrixMultiply(A, matrixExponent(matrixMultiply(A,A), n/2));
	}
}

ull fib(ull n)
{
	if(n == 0)
		return 0;

	vector< vector<ull> > M;
	vector< vector<ull> > start;
	M.push_back({1,1});
	M.push_back({1,0});
	start.push_back({1});
	start.push_back({0});
	vector< vector<ull> > R = matrixMultiply(matrixExponent(M,n-1), start);

	return R[0][0];
}

ull power(ull x, ull y, long p)
{
    ull res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ull nIncome(long a, long b, long n)
{
	return ((power(a, fib(n-1), MOD) * power(b, fib(n), MOD)) -1) % MOD;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long a,b,n;
		cin >> a >> b >> n;
		if(n == 0)
		{
			cout << a << endl;
			continue;
		}
		else if(n == 1)
		{
			cout << b << endl;
			continue;
		}
		cout << nIncome(a+1,b+1,n) << endl;
	}
}