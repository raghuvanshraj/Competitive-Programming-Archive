#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
	ll high = max(a,b);
	ll low = min(a,b);
	
	if(low == 0)
		return high;
	
	ll rem = high%low;
	return gcd(low, rem);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		ll m,n;
		ll d;
		cin >> m >> n >> d;
		ll lcm = (m*n) / gcd(m,n);
		ll low = 1;
		ll high = 1e18;
		ll mid;
		while (low <= high)
		{
			mid = (low+high) / 2;
			ll n = (mid / m) + (mid / n) - (mid / lcm);
			if (n < d)
			{
				low = mid+1;
			}
			else if (n > d)
			{
				high = mid-1;
			}
			else
			{
				break;
			}
		}
		while (mid % m != 0 and mid % n != 0)
		{
			mid--;
		}

		cout << mid << endl;
	}
	return 0;
}