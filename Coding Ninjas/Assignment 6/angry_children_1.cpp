#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long c[100005];
long long s[100005];

int main() {
    long long n,k;
    cin>>n>>k;
    long long i,j;
    for(i=0;i<n;i++)cin>>c[i];
    sort(c,c+n);
    long long t=0;
    long long min=0;
    for(i=0;i<k-1;i++)t+=c[i];
    s[0]=t;
    for(i=1;i<n-k;i++){t-=c[i-1];t+=c[i+k-2];s[i]=t;}
    for(i=0;i<k;i++)
        min+=(2*i+1-k)*c[i];
    long long temp=min;
    for(i=1;i<n-k;i++)
    {
        temp+=(k-1)*c[i-1]-2*s[i]+(k-1)*c[i+k-1];
        if(temp<min){min=temp;}
    }
    cout<<min<<'\n';
    return 0;
}
