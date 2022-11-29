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

const int V = 205, E = V * V * 2, maxint=0x3F3F3F3F;

struct etype {
    int t, c, u;
    etype *next, *pair;
    etype() {}
    etype(int T, int C, int U, etype* N): t(T), c(C), u(U), next(N) {}
    void* operator new(size_t, void* p) {
        return p;
    }
} *e[V], Te[E+E], *Pe;

int S, T, n, piS, cost, flow;
bool v[V];

void add_edge(int s, int t, int c, int u) {
    //printf("s= %d %d %d %d", s, t, c, u), pause;
    e[s] = new(Pe++) etype(t, +c, u, e[s]);
    e[t] = new(Pe++) etype(s, -c, 0, e[t]);
    e[s]->pair = e[t];
    e[t]->pair = e[s];
}

int aug(int no, int m) {
    if (no == T) {
        cost += piS * m;
        flow += m;
        return m;
    }
    v[no] = true;
    int l = m;
    for (etype *i = e[no]; i; i = i->next)
        if (i->u && !i->c && !v[i->t]) {
            int d = aug(i->t, l < i->u ? l : i->u);
            i->u -= d, i->pair->u += d, l -= d;
            if (!l) return m;
        }
    return m - l;
}

bool modlabel() {
    static int d[V];
    memset(d, 0x3F, sizeof(d));
    d[T] = 0;
    static deque<int> Q;
    Q.push_back(T);
    while(Q.size()) {
        int dt, no = Q.front();
        Q.pop_front();
        for(etype *i = e[no]; i; i = i->next)
            if(i->pair->u && (dt = d[no] - i->c) < d[i->t])
                (d[i->t] = dt) <= d[Q.size() ? Q.front() : 0]
                ? Q.push_front(i->t) : Q.push_back(i->t);
    }
    for(int i = 0; i < n; ++i)
        for(etype *j = e[i]; j; j = j->next)
            j->c += d[j->t] - d[i];
    piS += d[S];
    return d[S] < maxint;
}

void init(int ss, int tt) {
    Pe = Te;
    memset(e,0,sizeof(e));
    S = ss, T = tt, n = tt + 1;
    piS = cost = 0;
    flow = 0;
}

void go() {
    while(modlabel()) {
        do memset(v, 0, sizeof(v));
        while(aug(S, maxint));
    }
    //printf("%d\n", -cost);
}

const int N = 105, INF = 1e7;

int nn, m;
int a[N], b[N], g[N][N];

int main() {
    int x, y, sum, gg;
    while (~scanf("%d %d", &nn, &m)) {
        sum = gg = 0;
        FOR (i, 1, nn) scanf("%d", &a[i]), sum += a[i];
        FOR (i, 1, nn) scanf("%d", &b[i]), gg += b[i];
        FOR (i, 1, nn) {
            FOR (j, 1, nn) g[i][j] = INF;
            g[i][i] = 0;
        }
        FOR (i, 1, m) {
            scanf("%d %d", &x, &y);
            g[x][y] = g[y][x] = 1;
        }
        if (gg != sum) {
            puts("-1");
            continue;
        }
        FOR (k, 1, nn) FOR (i, 1, nn) FOR (j, 1, nn) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
        init(0, 2 * nn + 1);
        FOR (i, 1, nn) add_edge(S, i, 0, a[i]);
        FOR (i, 1, nn) add_edge(i + nn, T, 0, b[i]);
        FOR (i, 1, nn) FOR (j, 1, nn) {
            if (g[i][j] == INF) continue;
            add_edge(i, j + nn, g[i][j], INF);
        }
        go();
        //cout << "flow= " << flow << '\n';
        if (flow != sum) puts("-1");
        else printf("%d\n", cost);
    }
    return 0;
}










