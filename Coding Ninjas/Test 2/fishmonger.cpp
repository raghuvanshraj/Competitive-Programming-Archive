#include <iostream>
#include <cstdio>
using namespace std;
const int N=100;
int a[N][N],b[N][N],t,n,m,ans1,ans2;
bool mark[N];
void rec(int node, int time, int money)
{
    int i;
    if(money>ans1)
        return;
    if(time>t)
        return;
    if(node==n)
    {
        if(ans1>money)
        {
            ans1=money;
            ans2=time;
        }
        else
            if(ans1==money)
                if(time<ans2)
                {
                    ans1=money;
                    ans2=time;
                }
        return;
    }
    for(i=1;i<=n;i++)
        if(i!=node)
        {
            if(mark[i]==false)
            {
                mark[i]=true;
                rec(i,time+a[node][i],money+b[node][i]);
                mark[i]=false;
            }
        }
}
void makefalse()
{
    for(int i=0;i<=n;i++)
        mark[i]=false;
}
int main()
{
    int k,z,i,j,c,d,e,f,g;
    scanf("%d%d",&n,&t);
    while(n!=0 )
    {
        makefalse();
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&b[i][j]);
        ans1=10000000;
        ans2=10000000;
        mark[1]=true;
        rec(1,0,0);
        printf("%d",ans1);
        scanf("%d%d",&n,&t);
    }
    return 0;
}