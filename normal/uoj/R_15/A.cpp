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
#include <cfloat>
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

const int N = 505;

int n, m, k;
vpii ans;

void gao2() {
    if (n == 1) rep (i, m) printf("%d %d\n", 1, i + 1);
    else rep (i, n) printf("%d %d\n", i + 1, 1);
}

void gao3() {
    int f = 0;
    if (m >= k) swap(n, m), f = 1;
    ans.clear();
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i += 2) {
            FOR (j, 1, m) ans.pb(mp(i, j)), ans.pb(mp(i + 1, j));
        }
    } else {
        for (int i = 2; i <= n; i += 2) {
            FOR (j, 1, m) ans.pb(mp(i, j)), ans.pb(mp(i - 1, j));
            FOR (j, 1, m) ans.pb(mp(n, j));
        }
    }
    if (f) repit (it, ans) printf("%d %d\n", it->Y, it->X);
    else repit (it, ans) printf("%d %d\n", it->X, it->Y);
}

void gao() {
    bool t, flag = 0;
    bool g[N][N];
    vpii f[2];
    memset(g, 0, sizeof(g));
    if (n * m % 2 == 0) {
        if (n % 2) swap(n, m), flag = 1;
    }
    FOR (i, 1, n) {
        t = i % 2;
        FOR (j, 1, m) {
            if (j + 1 <= m) f[t].pb(mp(i, j)), f[t].pb(mp(i, j + 1)), j++;
            else f[t].pb(mp(i, j));
            t ^= 1;
        }
    }

//    puts("FFF");
//    repit (it, f[1]) cout << it->X << ' ' << it->Y << '\n';
//    system("pause");
//
//    puts("TTT");
//    repit (it, f[0]) cout << it->X << ' ' << it->Y << '\n';
//    system("pause");

    if (SZ(f[0]) > SZ(f[1])) t = 0;
    else t = 1;
    int id[2] = {0, 0};
    while (id[t] < SZ(f[t])) ans.pb(f[t][id[t]++]), t ^= 1;

    if (flag) repit (it, ans) printf("%d %d\n", it->Y, it->X);
    else repit (it, ans) printf("%d %d\n", it->X, it->Y);
}

int main() {
    while (~scanf("%d %d %d", &n, &m, &k)) {
        if (k == 1) {
            puts("-1");
            continue;
        }
        if (n == 1 || m == 1) {
            gao2();
            continue;
        }
        if (k == 2) {
            puts("-1");
            continue;
        }
        if (min(n, m) < k) {
            gao3();
            continue;
        }
        gao();
    }
    return 0;
}












