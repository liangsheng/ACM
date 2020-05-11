#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))
#define rep(i, n) for (int i = 0; i <= n; i++)

using namespace std;
int chh;

const int V = 205, E = V * V * 2, maxint=0x3F3F3F3F;

struct etype {
    int t, c, u;
    etype *next, *pair;
    etype() {}
    etype(int T, int C, int U, etype* N): t(T), c(C), u(U), next(N) {}
    void* operator new(unsigned, void* p) {
        return p;
    }
} *e[V], Te[E+E], *Pe;

int S, T, n, piS, cost;
bool v[V];

void add_edge(int s, int t, int c, int u) {
    //printf("s= %d %d %d %d", s, t, c, u), pause;
    e[s] = new(Pe++) etype(t, +c, u, e[s]);
    e[t] = new(Pe++) etype(s, -c, 0, e[t]);
    e[s]->pair = e[t];
    e[t]->pair = e[s];
}

int aug(int no, int m) {
    if (no == T) return cost += piS * m, m;
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
}

void go() {
    while(modlabel()) {
        do memset(v, 0, sizeof(v));
        while(aug(S, maxint));
    }
    //printf("%d\n", -cost);
}

const int N = 105, INF = 1e7;

int nn, m, num;
int g[N][N];

int main() {
    int i, j, u, v, w;
    while (~scanf("%d %d %d", &nn, &m, &num)) {
        if (nn == 0 && m == 0 && num == 0) break;
        for (i = 0; i <= nn; i++) {
            for (j = 0; j <= nn; j++) g[i][j] = INF;
            g[i][i] = 0;
        }
        for (i = 1; i <= m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] = min(g[u][v], w);
            g[v][u] = g[u][v];
        }
        rep(k, nn) rep(i, nn) rep(j, nn) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
        init(0, 2 * nn + 2);
        add_edge(S, 1, 0, num);
        add_edge(1, T, 0, num);
        for (i = 1; i <= nn; i++) {
            add_edge(1, 2 * i, g[0][i], 1);
            add_edge(2 * i + 1, T, g[i][0], 1);
            add_edge(2 * i, 2 * i + 1, -INF, 1);
        }
        for (i = 1; i < nn; i++) {
            for (j = i + 1; j <= nn; j++) add_edge(2 * i + 1, 2 * j, g[i][j], 1);
        }
        go();
        printf("%d\n", cost + nn * 10000000);
    }
    return 0;
}
