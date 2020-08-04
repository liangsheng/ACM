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

const int N = 1005, INF = 2139062143;

int n, w, h;
pii p[N][2];
vi g[N];
int dp[N], f[N], ok[N];
queue<int> q;

bool gao(pii p0, int id) {
    int flag = 1;
    FOR (i, id, n - 1) {
        if (p[i][0].X <= p0.X && p0.X + 1 <= p[i][1].X && p[i][0].Y <= p0.Y && p0.Y + 1 <= p[i][1].Y) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void bfs(int p) {
    memset(f, 0, sizeof(f));
    f[p] = 1, q.push(p);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        repit (it, g[u]) {
            int v = *it;
            if (!f[v]) f[v] = 1, q.push(v);
        }
    }
    dp[p] = 0;
    rep (i, n) dp[p] += f[i];
}

int main() {
    int t;
    while (~scanf("%d %d %d", &w, &h, &n)) {
        rep (i, n) rep (j, 2) scanf("%d %d", &p[i][j].X, &p[i][j].Y);

        rep (i, n) g[i].clear();
        rep (i, n) {
            FOR (j, i + 1, n - 1) {
                if (p[i][0].X >= p[j][1].X) continue;
                if (p[i][1].X <= p[j][0].X) continue;
                if (p[i][0].Y >= p[j][1].Y) continue;
                if (p[i][1].Y <= p[j][0].Y) continue;
                g[i].pb(j);
            }
        }

        memset(ok, 0, sizeof(ok));
        FORD (i, n - 1, 0) {
            if (gao(mp(p[i][0].X, p[i][0].Y), i + 1)) ok[i] = 1;
            else if (gao(mp(p[i][0].X, p[i][1].Y - 1), i + 1)) ok[i] = 1;
            else if (gao(mp(p[i][1].X - 1, p[i][0].Y), i + 1)) ok[i] = 1;
            else if (gao(mp(p[i][1].X - 1, p[i][1].Y - 1), i + 1)) ok[i] = 1;
        }

        //rep (i, n) sc2(i, ok[i]);
        t = n - 1, dp[n - 1] = 1;
        memset(f, 0, sizeof(f));
        FORD (i, n - 2, 0) {
            if (!ok[i]) continue;
            bfs(i);
            if (t == -1 || dp[i] > dp[t]) t = i;
        }
        printf("%d %d\n", dp[t], t + 1);
    }
    return 0;
}
/*
10 10 5
1 1 4 4
0 0 2 2
3 3 5 5
0 3 2 5
3 0 5 2*/



