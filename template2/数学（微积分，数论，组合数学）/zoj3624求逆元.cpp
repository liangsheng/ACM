#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

typedef long long LL;

const LL N = 200000, MOD = 100000007;

LL m, n, p, q;
LL c[N];

LL extend_gcd(LL a, LL b, LL &x, LL &y) {
    LL t, ret;
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ret = extend_gcd(b,a%b,x,y);
        t = x;
        x = y;
        y = t - a / b * y;
        return ret;
    }
}

LL cal(LL n, LL m) {
    LL x, y, z;
    z = c[m] * c[n - m] % MOD;
    extend_gcd(z, MOD, x, y);
    if (x < 0) x += (-x) / MOD * MOD;
    while (x < 0) x += MOD;
    return c[n] * x % MOD;
}

int main() {
    LL i, j, t1, t2, t3, t4;
    c[1] = 1;
    for (i = 2; i <= N; i++) c[i] = c[i - 1] * i % MOD;
    while (~scanf("%lld %lld %lld %lld", &m, &n, &p, &q)) {
        t1 = cal(m + n, n);
        t2 = cal(m + q - p, q);
        t3 = cal(m + q, q);
        t4 = cal(m + n - p, n);
        t1 = t1 * t2 % MOD;
        t3 = t3 * t4 % MOD;
        printf("%lld\n", (t1 - t3 + MOD * 2) % MOD);
    }
    return 0;
}
