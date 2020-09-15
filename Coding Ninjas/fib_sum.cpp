#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

vector< vector<ull> > matrixMultiply(vector< vector<ull> > A, vector< vector<ull> > B)
{
	ull rows = A.size();
	ull cols = B[0].size();
	vector< vector<ull> > AB(rows);
	for(ull i = 0; i < rows; i++)
		AB[i].resize(cols);

	for(ull i = 0; i < rows; i++)
	{
		for(ull j = 0; j < cols; j++)
		{
			AB[i][j] = 0;
			for(ull k = 0; k < B.size(); k++)
			{
				AB[i][j] = (AB[i][j]%MOD + (A[i][k]%MOD * B[k][j]%MOD) % MOD) % MOD;
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

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	return (fib(n+2) - fib(m+1) + MOD) % MOD;
}

int main()
{
	ull n,m;
	cin >> m >> n;
	cout << fiboSum(m,n);
	return 0;
}