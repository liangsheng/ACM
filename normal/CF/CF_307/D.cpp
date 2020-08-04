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

const int E = 2;

LL n, k;
int l, MOD;

int a[E][E], b[E][E];
int tmp[E][E];

void mul(int a[E][E], int b[E][E], int e) {
    int i, j, k;
    LL t;
    memset(tmp, 0, sizeof(tmp));
    for (i = 0; i < e; i++) {
        for (k = 0; k < e; k++) {
            if (a[i][k] == 0) continue;
            for (j = 0; j < e; j++) {
                if (b[k][j] == 0) continue;
                t = (LL) a[i][k] * b[k][j] + tmp[i][j];
                tmp[i][j] = t % MOD;
//                tmp[i][j] += a[i][k] * b[k][j];
//                tmp[i][j] %= MOD;
            }
        }
    }
}

void power(LL n) {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < E; i++) b[i][i] = 1;
    while (n) {
        if (n & 1) {
            mul(b, a, E);
            memcpy(b, tmp, sizeof(tmp));
        }
        mul(a, a, E);
        memcpy(a, tmp, sizeof(tmp));
        n >>= 1LL;
    }
}

int power(LL x, LL y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (LL) ans * x % MOD;
        x = (LL) x * x % MOD;
        y >>= 1LL;
    }
   // sc(ans);
    return ans;
}

int main() {
    cout << cos(54.0 / 180.0 * acos(-1)) * 2;
    LL f0, f1, n0, n1, x, INF;
    int ans;
    while (cin >> n >> k >> l >> MOD) {
        if (l == 64) INF = ~0ULL >> 1;
        else INF = (1LL << l) - 1;
        if (k > INF) {
            puts("0");
            continue;
        }
        n0 = n1 = 0, x = k;
        while (x != 0) {
            n1 += x & 1LL;
            x >>= 1LL;
        }
        n0 = l - n1;
        a[0][0] = 1, a[0][1] = 1;
        a[1][0] = 1, a[1][1] = 0;
        power(n - 1);
        f0 = (b[0][0] + b[0][1]) % MOD;
        f0 = (f0 + b[1][0]) % MOD;
        f0 = (f0 + b[1][1]) % MOD;
        f1 = ((power(2, n) - f0) % MOD + MOD) % MOD;
       // sc2(f0, f1);
       // sc2(n0, n1);
        ans = (LL) power(f0, n0) * power(f1, n1) % MOD;
        //sc2(f, n1);
        printf("%d\n", ans);
    }
    return 0;
}



















