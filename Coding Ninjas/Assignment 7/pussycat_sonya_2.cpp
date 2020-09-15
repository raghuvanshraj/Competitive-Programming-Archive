#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MA 1000000000000000000 // 1e18
#define M  1000000007
#define MM 1001
#define K  101

int m,n;

long long a[K][MM];
long long s[K][MM];
long long d[100001];
long long c[100001];

int main() {
  int t;
  int i,j,k,l,jl, jr;
  long long r;
  //scanf("%d", &t);
  t=1;

  while(t--) {
    scanf("%d %d", &n, &m);

    for(i=0;i<n;i++) {
      scanf("%d", &l);
      r=0;
      for(j=0;j<l;j++) {
        scanf("%lld", d+j);
        c[j]=d[j];
        //d[j] = a[i][j];
        if (r<d[j]) r=d[j];
      }
      for(j=l;j<m;j++) {
        c[j]=0;
        d[j]=0;
      }
      a[i][0]=0;
      a[i][1]=r;
      for(j=1;j<m;j++) {
        r=0;
        for(k=0;k<l-j+1;k++) {
          d[k]=d[k]+c[k+j];
          if (r<d[k]) r=d[k];
        }
        a[i][j+1]=MAX(a[i][j], r);
        //if (j>m-10)
        //printf("%lld ", a[i][j+1]);
      }
      //puts("");
    }
    for(j=0;j<=m;j++) {
      s[0][j]=a[0][j];
    }

    for(i=1;i<n;i++) {
      s[i][0]=0;
      for(j=1;j<=m;j++) {
        s[i][j]=s[i-1][j];
        for(k=1;k<=j;k++) {
          s[i][j] = MAX(s[i][j], s[i-1][j-k]+a[i][k]);
        }
        //printf("%lld ", s[i][j]);
      }
      //puts("");
    }

    printf("%lld\n", s[n-1][m]);
  }
}