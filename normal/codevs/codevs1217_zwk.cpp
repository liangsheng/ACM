#include <bits/stdc++.h>

#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
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
#define ins insert

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

template<class T>
inline char read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while ((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if (c == '-') c = getchar(), tmp = -1;
    while (c >= '0' && c <= '9') x *= 10, x += (c - '0'), c = getchar();
    n = x * tmp;
    return c;
}

template <class T>
inline void write(T n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while (n) {
        data[len++] = n%10;
        n /= 10;
    }
    if (!len) data[len++] = 0;
    while (len--) putchar(data[len] + 48);
}

const int N = 1000005, SZ = 1048576;

int n, m, M;
int a[SZ * 2], b[N];

void init() {
    M = 1;
    while (M < n + 2) M <<= 1;
    FOR (i, 1, n) a[i + M] = b[i];
    FORD (i, M - 1, 1) {
        a[i] = min(a[i << 1], a[i << 1 | 1]);
        a[i << 1] -= a[i];
        a[i << 1 | 1] -= a[i];
    }
}

int gao(int s, int t) {
    int ans, lans = 0, rans = 0;
    s += M, t += M;
    if (s != t) {
        for (; s ^ t ^ 1; s >>= 1, t >>= 1) {
            lans += a[s], rans += a[t];
            if (~s & 1) lans = min(lans, a[s ^ 1]);
            if (t & 1) rans = min(rans, a[t ^ 1]);
        }
    }
    ans = min(lans + a[s], rans + a[t]);
    while (s > 1) ans += a[s >>= 1];
    return ans;
}

void update(int s, int t, int val) {
    int tmp;
    for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) a[s ^ 1] += val;
        if (t & 1) a[t ^ 1] += val;
        tmp = min(a[s], a[s ^ 1]), a[s] -= tmp, a[s ^ 1] -= tmp, a[s >> 1] += tmp;
        tmp = min(a[t], a[t ^ 1]), a[t] -= tmp, a[t ^ 1] -= tmp, a[t >> 1] += tmp;
    }
    for (; s != 1; s >>= 1) {
        tmp = min(a[s], a[s ^ 1]);
        a[s] -= tmp, a[s ^ 1] -= tmp;
        a[s >> 1] += tmp;
    }
}

int main() {
    int d, s, t, c, flag;
    read(n), read(m);
    FOR (i, 1, n) read(b[i]);
    init();
    FOR (k, 1, m) {
        read(d), read(s), read(t);
        c = gao(s, t);
        if (c >= d) update(s, t, -d);
        else {
            write(-1), puts(""), write(k), puts("");
            return 0;
        }
    }
    puts("0");
    return 0;
}
