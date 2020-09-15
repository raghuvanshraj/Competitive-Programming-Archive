#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,q,c;
	cin >> n >> q >> c;
	vector<long long> stars[101][101];
	for (int i = 0; i < n; ++i)
	{
		int x,y,elt;
		cin >> x >> y >> elt;
		stars[x][y].push_back(elt);
	}
	while (q--)
	{
		long long t;
		cin >> t;
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long brightness = 0;
		for (int i = x1; i <= x2; ++i)
		{
			for (int j = y1; j <= y2; ++j)
			{
				for (int k = 0; k < stars[i][j].size(); ++k)
				{
					brightness += (stars[i][j][k] + t) % (c+1);
				}
			}
		}

		cout << brightness << endl;
	}
	return 0;
}