#include <bits/stdc++.h>
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef double d;

d calcCross(pair<d,d> vec_1, pair<d,d> vec_2)
{
	return abs((vec_1.first * vec_2.second) - (vec_1.second * vec_2.first));
}

d areaPolygon(d *x, d *y, int n)
{
	if (n < 3)
	{
		return 0;
	}

	d area1 = 0;
	d *remPoints_x = new d[int(ceil(float(n)/2))]();
	d *remPoints_y = new d[int(ceil(float(n)/2))]();
	for (int i = 0; i < n-1; i += 2)
	{
		int pt_1 = i;
		int pt_2 = i+1;
		int pt_3 = i+2;

		pair<d,d> vec_1 = mp(x[pt_2] - x[pt_1], y[pt_2] - y[pt_1]);
		pair<d,d> vec_2 = mp(x[pt_3] - x[pt_2], y[pt_3] - y[pt_2]);

		area1 += calcCross(vec_1,vec_2) / 2;
	}

	for (int i = 0, j = 0; i < n; i += 2, ++j)
	{
		remPoints_x[j] = x[i];
		remPoints_y[j] = y[i];
	}

	d area2 = areaPolygon(remPoints_x, remPoints_y, int(ceil(float(n)/2)));

	return area1 + area2;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	d *x = new d[n]();
	d *y = new d[n]();
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> y[i];
	}

	printf("%0.9f", areaPolygon(x,y,n));

	return 0;
}