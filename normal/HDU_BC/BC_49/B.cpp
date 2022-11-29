#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 50100
using namespace std;
typedef unsigned long long ll;
ll a[N], b[N], k[N], koe = 1000000007;
int n, T, t1, t2, c[N], d[N], flag, cnt, i, j;
char s[N];
int main()
{
    scanf("%d", &T);
    k[0] = 1;
    for (i = 1; i <= 20000; i++) k[i] = k[i - 1] * koe;
    while (T--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (i = 1; i <= n; i++) a[i] = a[i - 1] * koe + s[i];
        b[n + 1] = t1 = t2 = flag = cnt = 0;
        for (i = n; i >= 1; i--) b[i] = b[i + 1] * koe + s[i];
        for (i = 1; i <= n; i++) {
            ll h = b[1] - b[i + 1] * k[i];
            if (h == a[i]) c[++t1] = i;
            h = a[n] - a[n - i] * k[i];
            if (b[n - i + 1] == h) d[++t2] = n - i + 1;
        }
        reverse(c + 1, c + t1 + 1);
        for (i = 1; i <= t1; i++) {
            if (flag) break;
            for (j = 1; j <= t2; j++) {
                int l = c[i] + 1, r = d[j] - 1;
                if (r < l || cnt >= 2e6) break;
                ++cnt;
                ll h1 = a[r] - a[l - 1] * k[r - l + 1];
                ll h2 = b[l] - b[r + 1] * k[r - l + 1];
                if (h1 == h2) flag = 1;
            }
        }
        if (flag) puts("Yes"); else puts("No");
    }
    return 0;
}
