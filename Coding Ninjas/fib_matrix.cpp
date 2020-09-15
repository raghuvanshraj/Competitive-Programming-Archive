#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > matrixMultiply(vector< vector<int> > A, vector< vector<int> > B)
{
	int rows = A.size();
	int cols = B[0].size();
	vector< vector<int> > AB(rows);
	for(int i = 0; i < rows; i++)
		AB[i].resize(cols);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			AB[i][j] = 0;
			for(int k = 0; k < B.size(); k++)
			{
				AB[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	return AB;
}

vector< vector<int> > matrixExponent(vector< vector<int> > A, int n)
{
	vector< vector<int> > R;
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

int fib(int n)
{
	if(n == 0)
		return 0;

	vector< vector<int> > M;
	vector< vector<int> > start;
	M.push_back({1,1});
	M.push_back({1,0});
	start.push_back({1});
	start.push_back({0});
	vector< vector<int> > R = matrixMultiply(matrixExponent(M,n-1), start);

	return R[0][0];
}

int main()
{
	int n;
	cin >> n;
	cout << fib(n);
	return 0;
}