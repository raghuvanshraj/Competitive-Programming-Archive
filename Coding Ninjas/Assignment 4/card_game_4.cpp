#include <cstdio>
const int N = 1e5 + 1;
long long ans;
int i, j, n, x, c[10], p[10], k[N][10];
int main()
{
    scanf("%d%d", &n, &x);

    for (j = 2; j * j <= x; ++j)
        if (x % j == 0)
            for (p[++*p] = j; x % j == 0; x /= j)
                ++k[0][*p];

    if (x > 1)
        p[++*p] = x, ++k[0][*p];

    for (; i++ < n;)
        for (scanf("%d", &x), j = 0; j++ < *p;)
            for (; x % p[j] == 0; x /= p[j])
                ++k[i][j];

    for (j = i = 0; i++ < n && j <= n; ans += n - j + 1) {
        for (; j <= n;) {
            for (x = 0; x++ < *p && c[x] >= k[0][x];)
                ;

            if (j >= i && x > *p)
                break;

            for (++j, x = 0; x++ < *p; c[x] += k[j][x])
                ;
        }
        
        for (x = 0; x++ < *p; c[x] -= k[i][x])
            ;
    }
    printf("%lld", ans);
}