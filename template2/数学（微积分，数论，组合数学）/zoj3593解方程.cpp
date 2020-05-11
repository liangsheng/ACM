#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

typedef long long LL;

const LL INF = ~0ULL >> 1;

LL extgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL d = extgcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int main()
{
    LL T, A, B, a, b;
    LL i, j, x0, y0, t1, t2, x1, y1, c, d, p1, p2, t, ans;
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld", &A, &B, &a, &b);
        if (a < b) swap(a, b);
        c = abs(B - A);
        d = extgcd(a, b, x0, y0);
        if (c % d != 0)
        {
            puts("-1");
            continue;
        }
        x0 *= c / d, y0 *= c / d;
        t1 = b / d, t2 = a / d;
        if (x0 < 0)
        {
            t = x0;
            x0 += (-t) / t1 * t1, y0 -= (-t) / t1 * t2;
            while (x0 < 0) x0 += t1, y0 -= t2;
        }
        else if (x0 > 0)
        {
            t = x0;
            x0 -= t / t1 * t1, y0 += t / t1 * t2;
        }
        ans = INF;
        if (y0 >= 0)
        {
            p1 = t1, p2 = t2;
            x1 = x0, y1 = y0;
            if (x1 < y1) swap(x1, y1), swap(p1, p2);
            t = (x1 - y1) / (p1 + p2);
            y1 += t * p2, x1 -= t * p1;
            ans = min(ans, x1);
            x1 -= p1, y1 += p2;
            if (x1 >= 0 && y1 >= 0) ans = min(ans, y1);
        }
        if (y0 < 0) ans = min(ans, x0 - y0);
        x0 -= t1, y0 += t2;
        if (y0 > 0) ans = min(ans, y0 - x0);
        if (y0 < 0)
        {
            t = y0;
            y0 += t / t2 * t2, x0 -= t / t2 * t1;
            while (y0 < 0) y0 += t2, x0 -= t1;
        }
        else if (y0 > 0)
        {
            t = y0;
            y0 -= t / t2 * t2, x0 += t / t2 * t1;
        }
        if (x0 < 0) ans = min(ans, y0 - x0);
        y0 -= t2, x0 += t1;
        if (x0 > 0) ans = min(ans, x0 - y0);
        printf("%lld\n", ans);
    }
    return 0;
}
