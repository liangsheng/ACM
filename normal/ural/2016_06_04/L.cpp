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
#include <stack>
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

const int N = 100005 * 2, M = N * 3;

struct Graph {
    int n, e, ct, scc;
    int head[N], pu[M], pnt[M], nxt[M];
    int dfn[N], low[N], bel[N], ind[N], cf[N], col[N];
    bool ins[N];
    stack<int> s;
    vi g[N];

    void init(int nn) {
        n = nn;
        e = 0;
        ct = 0;   //for deep
        scc = 0;  //the number of lian tong kuai
        memset(head, -1, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        memset(ins, 0, sizeof(ins));
        memset(ind, 0, sizeof(ind));
        memset(col, -1, sizeof(col));
        rep (i, 2 * n) g[i].clear();
    }

    void add_edge(int u, int v) {
        //printf("u= %d v= %d\n", u, v);
        pu[e] = u, pnt[e] = v;
        nxt[e] = head[u], head[u] = e++;
    }

    void tarjan(int u) {
        int v;
        low[u] = dfn[u] = ++ct;
        s.push(u);
        ins[u] = 1;
        repe (i, u) {
            v = pnt[i];
            if (dfn[v] == 0) {
                tarjan(v);
                low[u] = low[u] < low[v] ? low[u] : low[v];
            } else if (ins[v] && dfn[v] < low[u]) low[u] = dfn[v];
        }
        if (low[u] == dfn[u]) {
            do {
                v = s.top();
                s.pop();
                ins[v] = 0;
                bel[v] = scc;
            }  while(u != v);
            scc++;
        }
    }

    void topsort() {
        int u, v;
        rep (i, scc) {
            if (ind[i] == 0) s.push(i);
        }
        while (!s.empty()) {
            u = s.top();
            s.pop();
            if (col[u] == -1) {
                col[u] = 0;
                col[cf[u]] = 1;
            }
            repit (it, g[u]) {
                if (--ind[*it] == 0) s.push(*it);
            }
        }
    }

    bool sat(vi &ans) {
        int u, v;
        rep (i, 2 * n) {
            if (dfn[i] == 0) tarjan(i);
        }
        //rep (i, 2 * n) sc2(i, bel[i]);
        for (int i = 0; i < 2 * n; i += 2) {
            if (bel[i] == bel[i ^ 1]) return 0;
            cf[bel[i]] = bel[i ^ 1];
            cf[bel[i ^ 1]] = bel[i];
        }
        rep (i, e) {
            u = pu[i], v = pnt[i];
            if (bel[u] == bel[v]) continue;
            ind[bel[u]]++;
            g[bel[v]].pb(bel[u]);
        }
        topsort();
        ans.clear();
        for (int i = 0; i < 2 * n; i += 2) {
            if (col[bel[i]]) ans.pb(0);
            else ans.pb(1);
        }
        return 1;
    }
} G;

const int NN = 100005;

int n, m;
int X[NN], Y[NN];
vi g[N];

int main() {
    int sz, u, v;
    bool flag;
    vi ans;
    while (~scanf("%d %d", &n, &m)) {
        FOR (i, 1, m) g[i].clear();
        rep (i, n) {
            scanf("%d %d", &X[i], &Y[i]);
            g[X[i]].pb(i);
            g[Y[i]].pb(i);
        }
        G.init(n);
        FOR (i, 1, m) {
            sz = SZ(g[i]);
            if (sz == 1) continue;
            rep (l, sz) {
                if (X[g[i][l]] == i) u = g[i][l] * 2;
                else u = g[i][l] * 2 + 1;
                FOR (r, l + 1, sz - 1) {
                    if (X[g[i][r]] == i) v = g[i][r] * 2;
                    else v = g[i][r] * 2 + 1;
                    G.add_edge(u, v ^ 1);
                    G.add_edge(v, u ^ 1);
                }
            }
        }
        flag = G.sat(ans);

        int cnt[N];
        memset(cnt, 0, sizeof(cnt));

        if (!flag) puts("No");
        else {
            puts("Yes");
            rep (i, n) {
                if (ans[i] == 0) printf("%d\n", X[i]), cnt[X[i]]++;
                else printf("%d\n", Y[i]), cnt[Y[i]]++;
            }
            FOR (i, 1, m) if (cnt[i] > 1) puts("FUCK");
        }
    }
    return 0;
}
