#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
#define GC getchar_unlocked()
#define N 100010
#define MOD 1000000007
int v[N][25];
vector<int> pr;
int f[N];
 
ll ModPow(ll a,ll x,ll p)
{
    ll res=1;
    while(x>0)
    {
        if(x%2!=0)
            res=(res*a)%p;
        a=(a*a)%p;
        x/=2;
    }
    return (res%p);
}
 
 
int scan()
{
    int ret=0;
    int ip=GC;
    for(;ip<'0'||ip>'9';ip=GC);
    for(;ip>='0'&&ip<='9';ip=GC)
        ret=ret*10+ip-'0';
    return ret;
}
 
int main()
{
    int t,i,j,k,x,p,c,n;
    ll ans,temp1,temp2,cs,fr;
    for(i=1;i<N;i++) f[i]=i;
    for(i=2;i*i<N;i++)
        if(f[i]==i)
            for(j=i*i;j<N;j+=i)
                f[j]=min(f[j],i);
    for(i=1;i<N;i++) if(f[i]==i) pr.push_back(i);
    t=scan();
    while(t--)  {
        n=scan();
        for(i=0;i<n;i++) {
            x=scan();
            while(x>1) {
                p=f[x];
                c=0;
                while(f[x]==p) {
                    c++;
                    x/=f[x];
                }
                v[p][c]++;
            }
        }
 
        ans=1LL;
        for(k=0;k<(int)pr.size();k++)
        {
            i=pr[k];
            cs=0;
            for(j=20;j>=1;j--) {
                if(v[i][j] > 0) {
                    temp1=ModPow(i,j,MOD);
                    fr=ModPow(2,cs+v[i][j],MOD-1)-ModPow(2,cs,MOD-1);
                    if(fr<0) fr+=(MOD-1);
                    temp2=ModPow(temp1,fr,MOD);
                    ans=(ans*temp2)%MOD;
                    cs += v[i][j];
                    v[i][j]=0;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}