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
#define sqr(r) ((LL) (r) * (r))
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
typedef unsigned long long ULL;

const int N = 55;
const LL INF = 1e18;

int T, n;
LL m, M;
LL g[N][N];
LL a[N];

void init() {
    a[2] = 1, a[3] = 2;
    FOR (i, 4, 50) {
        a[i] = a[i - 1] * 2;
    }
    //FOR (i, 2, 50) cout << "i= " << i << ' ' << a[i] << '\n';
}

void gao() {
    int x, l, r;
    memset(g, 0, sizeof(g));
    if (m == 0) return ;
    if (m == 1) {
        g[1][n] = 1;
        return ;
    }
    FOR (i, 1, n) if (a[i] >= m) {
        x = i;
        break;
    }
    l = 2, r = x - 2 + l - 2;
    m -= a[x - 1];
    g[1][n] = 1;
    FOR (i, l, r) g[1][i] = g[i][n] = 1;
    FOR (i, l, r) FOR (j, i + 1, r) g[i][j] = 1;
    LL t = a[x - 2];
    //sc4(l, r, t, m);
    if (m != 0) {
        g[r + 1][n] = 1;
        FORD (i, r, l) {
            if (m >= t) g[i][r + 1] = 1, m -= t;
            t >>= 1;
        }
        if (m != 0) g[1][r + 1] = 1;
    }
}

int main() {
    file_r("B-large-practice.in");
    file_w("B-large.out");
    int cas = 0;
    init();
    scanf("%d", &T);
    while (T--) {
        cin >> n >> m;
        M = m;
        printf("Case #%d: ", ++cas);
        if (m > a[n]) {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        gao();
        FOR (i, 1, n) {
            FOR (j, 1, n) cout << g[i][j];
            cout << '\n';
        }
        FOR (k, 1, n) FOR (i, 1, n) FOR (j, 1, n) {
            if (k != i && k != j && i != j) g[i][j] += g[i][k] * g[k][j];
        }
        if (g[1][n] != M) printf("%d FUCK\n", g[1][n]);
    }
    return 0;
}
