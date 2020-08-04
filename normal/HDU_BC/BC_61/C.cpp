#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define ins insert
#define rb rbegin
#define be begin
#define er erase
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 100005, M = 500000, MOD = 1000000007;

int e;
int p[41538 + 5], f[M + 5];
int p1[20], p2[20], c;

inline void scan(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

void init() {
    e = 0;
    FOR (i, 2, M) {
        if (f[i]) continue;
        p[e++] = i;
        for (LL j = (LL) i * i; j <= M; j += i) f[j] = 1;;
    }
}

void gao(int x) {
    int i;
    c = 0;
    for (i = 0; p[i] * p[i] <= x; i++) {
        if (x % p[i]) continue;
        p1[c] = p[i], p2[c] = 0;
        while (x % p[i] == 0) {
            p2[c]++;
            x /= p[i];
        }
        c++;
    }
    if (x != 1) p1[c] = x, p2[c] = 1, c++;
}

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (LL) ans * x % MOD;
        x = (LL) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int n;
int a[N], b[M + 5];

inline void mul(int &x, int y) {
    x = (LL) x * y % MOD;
}

int main() {
    int ans, flag, res;
    init();
    while (~scanf("%d", &n)) {
        ans = 1;
        FOR (i, 1, n) {
            scan(a[i]);
            mul(ans, power(i, a[i]));
        }
        memset(b, 0, sizeof(b));
        FOR (i, 1, n) {
            gao(i);
            rep (k, c) b[p1[k]] += p2[k] * a[i];
        }
        sc(ans);
        res = ans;
        rep (i, M) {
            if (b[i] == 0) continue;
            sc2(i, b[i]);
            res = power(res, b[i] + 1);
        }
        printf("%d\n", res);
    }
    return 0;
}





















