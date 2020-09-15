#include <bits/stdc++.h>

using namespace std;

void _findStrictlyIncreasingNum(int start, string out, int n)
{
    if (n == 0)
    {
        cout << out << " ";
        return;
    }
 
    for (int i = start; i <= 9; i++)
    {
        string str = out + to_string(i);
        _findStrictlyIncreasingNum(i + 1, str, n - 1);
    }
}

void printIncreasingNumbers(int n)
{
	_findStrictlyIncreasingNum(1,"",n);
}

int main()
{
	int n;
	cin >> n;
	printIncreasingNumbers(n);

	return 0;
}