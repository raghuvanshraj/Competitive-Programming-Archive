#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull power(ull x, ull y, long p)
{
    ull res = 1; 
 
    x = x % p;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y >> 1;
        x = (x*x) % p;  
    }

    return res;
}


int main()
{
	cout << power(2,3,10);
}