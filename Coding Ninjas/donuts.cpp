#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *c = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
	}
	sort(c, c+n, greater<int>());
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += c[i] * pow(2,i);
	}
	cout << ans;
	return 0;
}