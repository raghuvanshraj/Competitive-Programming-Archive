#include <bits/stdc++.h>

using namespace std;

int polygonArea(int *X, int *Y, int n)
{
    int area = 0;
 
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }
 
    return abs(area / 2);
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int *dist = new int[s.size()]();
	for (int i = 0; i < s.size(); ++i)
	{
		cin >> dist[i];
	}
	int *x = new int[s.size()]();
	int *y = new int[s.size()]();
	for (int i = 0; i < s.size()-1; ++i)
	{
		switch(s[i])
		{
			case 'N':
			{
				y[i+1] = y[i] + dist[i];
				x[i+1] = x[i];
			}
			break;

			case 'E':
			{
				x[i+1] = x[i] + dist[i];
				y[i+1] = y[i];
			}
			break;

			case 'W':
			{
				x[i+1] = x[i] - dist[i];
				y[i+1] = y[i];
			}
			break;

			case 'S':
			{
				y[i+1] = y[i] - dist[i];
				x[i+1] = x[i];
			}
		}
	}

	cout << polygonArea(x,y,s.size());

	return 0;
}