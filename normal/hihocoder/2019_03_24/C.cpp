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

const int N = 10005;

struct NODE {
    int u, v;
    int next;
};

int n, m, e, ct, scc;
int head[N], dfn[N], low[N], ins[N], sccf[N];
NODE edge[N];
stack<int> s;

void init() {
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(ins, 0, sizeof(ins));
    memset(sccf, 0, sizeof(sccf));  
    e = 0;
    ct = 0;
    scc = 0;
}

void add_edge(int u, int v) {
    edge[e].u = u;
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void tarjan(int u) { 
    int i, v;
    low[u] = dfn[u] = ++ct;
    s.push(u);
    ins[u] = 1;
    for (i = head[u]; i != -1; i = edge[i].next){
        v = edge[i].v;
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = low[u] < low[v] ? low[u] : low[v];       
        }
        else if (ins[v] && dfn[v] < low[u]) low[u] = dfn[v];          
    }
    if (low[u] == dfn[u]){
        scc++;
        do {
            v = s.top();
            s.pop();
            ins[v] = 0;
            sccf[v] = scc; 
        }  while(u != v);        
    }
}

vi g[N];
int cnt[N], dp[N];
bool vis[N];

void dfs(int u) {
    vis[u] = 1;
    repit (it, g[u]) {
        if (vis[*it]) continue;
        dfs(*it);
    }
}

int get_ans() {
    int x, y;
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    FOR (i, 1, n) {
        g[i].clear();
        cnt[sccf[i]]++;
    }
    // FOR (i, 1, n) cout << "i= " << i << ' ' << sccf[i] << '\n';
    // FOR (i, 1, n) sccf[i] = i, cnt[i] = 1;
    // scc = n;
    rep (i, e) {
        x = sccf[edge[i].u], y = sccf[edge[i].v];
        if (x == y) continue;
        // cout << "x= " << x << ' ' << y << '\n';
        g[x].pb(y);
    }
    FOR (i, 1, n) {
        x = sccf[i];
        if (dp[x] == 0) {
            memset(vis, 0, sizeof(vis));
            dfs(x);
            FOR (j, 1, scc) dp[x] += vis[j] ? cnt[j]: 0;
        }
        printf("%d\n", dp[x]);
    }
}

int main() {
    int x, y;
    while (~in2(n, m)) {
        init();
        rep (i, m) {
            in2(x, y);
            // g[x].pb(y);
            add_edge(x, y);
        }
        // FOR (i, 1, n) {
        //     memset(vis, 0, sizeof(vis));
        //     dfs(i);
        //     int ans = 0;
        //     FOR (i, 1, n) ans += vis[i];
        //     printf("%d\n", ans);
        // }
        FOR (i, 1, n) if (dfn[i] == 0) tarjan(i);
        // FOR (i, 1, n) cout << i << ' ' << sccf[i] << '\n';
        get_ans();
    }
    return 0;
}
