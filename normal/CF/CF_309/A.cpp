#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 1005, MOD = 1000000007;

int k;
int a[N];

LL c[N * N];

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
    int ans, tol;
    c[0] = 1, c[1] = 1;
    FOR (i, 2, 1000000) c[i] = c[i - 1] * i % MOD;
    //cout << cal(5, 2);
    while (~scanf("%d", &k)) {
        tol = 0;
        rep (i, k) scanf("%d", &a[i]), tol += a[i];
        ans = 1;
        FORD (i, k - 1, 0) {
            ans = (LL) ans * cal(tol - 1, a[i] - 1) % MOD;
            tol -= a[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}




























