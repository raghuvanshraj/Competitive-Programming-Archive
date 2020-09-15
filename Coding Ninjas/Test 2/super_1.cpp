#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

// LL gcd(LL a, LL b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }

LL BS(LL a, LL b, LL n)
{
    LL high,low,mid,cnt,lcm;
    low = 1;
    high = 1e18;
    lcm = (a * b) / __gcd(a, b);

    while(low <= high)
    {
        mid = (low + high) / 2;
        cnt = (mid / a) + (mid / b) - (mid / lcm);

        if(cnt < n)
            low = mid + 1;
        if(cnt > n)
            high = mid - 1;
        if(cnt == n)
            break;
    }
    while(mid % a && mid % b)
        mid--;
    return mid;
}

int main()
{
    LL a,b,n,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld", &a, &b, &n);
        printf("%lld\n", BS(a, b, n));
    }
    return 0;
}