#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <complex>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,b) for(int i=a-1;i>=b;i--)
#define rev(i,n) REV(i,n,0)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define GI ({ int x; scanf("%d",&x); x; })
#define GLL ({ LL x; scanf("%lld",&x); x; })
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define inf (int)(1e9)
#define linf (LL)(1e18)
#define eps (double)(1e-9)
#define leps (LD)(1e-18)
#define PI (double)(3.141592653589793238)

#define MAXN 100005
#define MAX 1100000

int arr[MAXN];

struct Tree{
    LL val;
    LL v;
    int lazy;
    int type;
}tree[MAX];

void build(int node, int a, int b){
    if(a>b)return;
    if(a == b){
        tree[node].lazy = 1001;
        tree[node].type = 0;
        tree[node].val = arr[a]*arr[a];
        tree[node].v = arr[a];
        return;
    }
    tree[node].lazy = 1001;
    tree[node].type = 0;
    build(node*2,a,(a+b)/2);
    build(node*2+1,1 +(a+b)/2,b);
    tree[node].v = tree[node*2].v + tree[node*2 +1].v;
    tree[node].val = tree[node*2].val + tree[node*2+1].val;
}

void update(int node, int a, int b, int i, int j, LL value, int typ){
    if(tree[node].type != 0){
        if(tree[node].type == 1){
            tree[node].val += 2*tree[node].v*tree[node].lazy + (b-a+1)*tree[node].lazy*tree[node].lazy;
            tree[node].v += (b-a+1)*tree[node].lazy;
        }else if(tree[node].type == 2){
            tree[node].val = (b - a + 1)*tree[node].lazy*tree[node].lazy;
            tree[node].v = (b - a + 1)*tree[node].lazy;
        }
        if(a != b){
            tree[node*2].type = tree[node].type;
            tree[node*2+1].type = tree[node].type;
            tree[node*2].lazy = tree[node].lazy;
            tree[node*2+1].lazy = tree[node].lazy;
        }
        tree[node].lazy = 1001;
        tree[node].type = 0;
    }
    if(a > b || a > j || b < i)
        return;
    if(a >= i && b <= j){
        if(typ == 1){
            tree[node].val += 2*tree[node].v*value + (b-a+1)*value*value;
            tree[node].v += (b-a+1)*value;
        }else if(typ == 2){
            tree[node].val = (b - a + 1)*value*value;
            tree[node].v = (b - a + 1)*value;
        }
        if(a != b){
            tree[node*2].type = typ;
            tree[node*2+1].type = typ;
            tree[node*2].lazy = value;
            tree[node*2+1].lazy = value;
        }
        return;
    }
    update(node*2,a,(a+b)/2,i,j,value,typ);
    update(node*2+1,(a+b)/2 + 1,b,i,j,value,typ);
    tree[node].val = tree[node*2].val + tree[node*2+1].val;
    tree[node].v = tree[node*2].v + tree[node*2 + 1].v;
}

LL query(int node, int a, int b, int i, int j){
    if(a > b || a > j || b < i)return 0;
    if(tree[node].type != 0){
        if(tree[node].type == 1){
            tree[node].val += 2*tree[node].v*tree[node].lazy + (b-a+1)*tree[node].lazy*tree[node].lazy;
            tree[node].v += (b-a+1)*tree[node].lazy;
        }else if(tree[node].type == 2){
            tree[node].val = (b - a + 1)*tree[node].lazy*tree[node].lazy;
            tree[node].v = (b - a + 1)*tree[node].lazy;
        }
        if(a != b){
            tree[node*2].type = tree[node].type;
            tree[node*2+1].type = tree[node].type;
            tree[node*2].lazy = tree[node].lazy;
            tree[node*2+1].lazy = tree[node].lazy;
        }
        tree[node].lazy = 1001;
        tree[node].type = 0;
    }
    if(a >= i && b <= j)
        return tree[node].val;
    LL q1 = query(node*2,a,(a+b)/2,i,j);
    LL q2 = query(node*2+1,(a+b)/2+1,b,i,j);
    return q1+q2;
}


int main(){
    int t,cs = 1;
    scanf("%d",&t);
    while(cs <= t){
        printf("Case %d:\n",cs);
        cs++;
        int n,m;
        scanf("%d %d",&n,&m);
        //Tree t[MAX] = {0,0,1001,0};
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        build(1,0,n-1);
        int c, l, r;
        LL val;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&c,&l,&r);
            if(c == 1){
                scanf("%lld",&val);
                update(1,0,n-1,l-1,r-1,val,1);
            }else if(c == 0){
                scanf("%lld",&val);
                update(1,0,n-1,l-1,r-1,val,2);
            }else if(c == 2){
                printf("%lld\n",query(1,0,n-1,l-1,r-1));
            }
        }
    }
	return 0;
}