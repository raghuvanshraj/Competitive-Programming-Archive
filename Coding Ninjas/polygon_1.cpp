#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
 
ld polygonArea(ld *X, ld *Y, int n)
{
    ld area = 0.0;
 
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }
 
    return abs(area / 2.0);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	ld *x = new ld[n]();
	ld *y = new ld[n]();
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> y[i];
	}

	ld ans = polygonArea(x,y,n);
	if (ans == int(ans))
	{
		cout << ans << ".0";
	}
	else
	{
		cout << setprecision(9) << ans;
	}

	return 0;
}