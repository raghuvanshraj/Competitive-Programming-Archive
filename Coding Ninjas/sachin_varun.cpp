#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct trip
{
	ll x;
	ll y;
};

trip gcdExtended(ll a, ll b)
{
	int high = max(a,b);
	int low = min(a,b);
	
	if(low == 0)
	{
		trip a;
		a.x = 1;
		a.y = 0;
		return a;
	}
	
	trip small = gcdExtended(low, high%low);
	trip myAns;
	myAns.x = small.y;
	myAns.y = small.x - (a/b)*small.y;
	
	return myAns;
}

ll modInverse(ll a, ll m)
{
	ll ans = gcdExtended(a,m).x;
	cout << (ans%m + m) % m << endl;
	return (ans%m + m) % m;
}

ll count(ll a, ll b, ll d)
{
	cout << a << ' ' << b << ' ' << d << endl;
	ll y1 = ((d%a) * modInverse(b,a)) % a;
	ll n = ((d/b) - y1)/a;
	cout << y1 << endl;
	
	if(d < y1*b)
		return 0;

	return n+1;
}

int main()
{
	ll a;
	ll b;
	ll d;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> d;
		ll g = __gcd(a,b);
		if(d%g != 0)
		{
			cout << 0 << endl;
			continue;
		}
		
		if(d == 0)
		{
			cout << 1 << endl;
			continue;
		}
		
		a /= g;
		b /= g;
		d /= g;
		
		cout << count(a,b,d) << endl;
	}
	
	return 0;
}

