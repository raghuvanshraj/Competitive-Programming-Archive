#include <iostream>

using namespace std;

struct ans
{
	int x;
	int y;
};

ans gcdExtended(int a, int b)
{
	int high = max(a,b);
	int low = min(a,b);
	
	if(low == 0)
	{
		ans a;
		a.x = 1;
		a.y = 0;
		return a;
	}
	
	ans small = gcdExtended(low, high%low);
	ans myAns;
	myAns.x = small.y;
	myAns.y = small.x - (a/b)*small.y;
	
	return myAns;
}

int main()
{
	int a,b;
	cin >> a >> b;
	ans myAns = gcdExtended(a,b);
	cout << myAns.x << endl << myAns.y << endl;
	return 0;
}N