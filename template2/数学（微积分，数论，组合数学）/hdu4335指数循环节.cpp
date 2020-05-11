/*
a^x = a^(x mod phi(c)+phi(c)) (mod c), x>=phi(c)
*/
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

typedef unsigned long long LL;

const LL INF = ~0LL >> 1, N = 100000;

LL T, b, p, m;

LL getphi(LL n) { //求欧拉函数值
    LL i, ans = 1;
    for (i = 2; i * i <= n; i++) {
        if (n % i) continue;
        n /= i;
        ans *= i - 1;
        while (n % i == 0)  n /= i, ans *= i;
    }
    if (n > 1) ans *= n - 1;
    return ans;
}

LL power(LL x, LL y, LL p) {
    LL ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1LL;
    }
    return ans;
}

int main() {
    LL i, j, ans, tmp, h, ep, cas = 0;
    cin >> T;
    while (T--) {
        cin >> b >> p >> m;
        cout << "Case #" << ++cas << ": ";
        if (m == INF && p == 1 && b == 0) {
            cout << "18446744073709551616" << endl;
            continue;
        }
        tmp = 1, ans = 0, j = 0, ep = getphi(p);
        for (i = 0; i <= p; i++) {
            tmp *= i ? i : 1;
            if (tmp >= ep) j = ep;
            tmp %= ep;
            if (tmp == 0) break;
            h = tmp + j;
            if (i <= m && power(i, h, p) == b) ans++;
        }
        for (j = 0; j < p && j <= m; j++) {
            if (power(j, ep, p) == b) {
                ans += (m - j) / p + 1;
                if (i >= j + 1) ans -= (i - 1 - j) / p + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
