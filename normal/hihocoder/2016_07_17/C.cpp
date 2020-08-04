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

const int N = 100005, M = N * 10;

int n;
int cnt[N], f[N], s[N];
vi g[N], h[N];
queue<int> q;

void topSort() {
    int u, v, fa;
    set<int> d;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (!f[u]) {
            d.clear();
            repit (it, h[u]) d.insert(s[*it]);
            if (SZ(d) > 1) f[u] = 1, s[u] = u;
            else f[u] = 0, s[u] = *d.begin();
        }
//        if (u == 5) {
//            puts("FFF");
//            repit (it, d) cout << *it << '\n';
//            puts("OVER");
//        }
//        sc3(u, f[u], s[u]);
        repit (it, g[u]) {
            v = *it;
            if (--cnt[v] == 0) q.push(v);
        }
    }
}

int main() {
    int x, t, ans;
    while (~scanf("%d", &n)) {
        FOR (i, 0, n) {
            g[i].clear();
            h[i].clear();
        }
        memset(cnt, 0, sizeof(cnt));
        FOR (i, 1, n) {
            scanf("%d", &cnt[i]);
            rep (j, cnt[i]) {
                scanf("%d", &x);
                g[x].pb(i);
                h[i].pb(x);
            }
        }
        memset(f, 0, sizeof(f));
        repit (it, g[0]) {
            x = *it;
            if (--cnt[x] == 0) q.push(x);
            f[x] = 1, s[x] = x;
        }
        topSort();
        ans = 0;
        FOR (i, 1, n) ans += f[i];
        printf("%d\n", ans);
    }
    return 0;
}
