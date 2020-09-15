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

int main()
{
	vector< vector<int> > A;
	vector< vector<int> > B;
	A.push_back({2,3});
	A.push_back({5,4});
	// A.push_back({7,5});
	B.push_back({1});
	B.push_back({8});
	B.push_back({6});
	vector< vector<int> > AB = matrixMultiply(A,A);
	for(int i = 0; i < AB.size(); i++)
	{
		for(int j = 0; j < AB[0].size(); j++)
		{
			cout << AB[i][j] << " ";
		}

		cout << endl;
	}
	return 0;
}