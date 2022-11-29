#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define pause cout << " press any key to continue...", cin >> ch

#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int ch;

const int N = 3005, M = N << 1, INF = ~0U >> 2;

struct Edge {
    int v, w, next;
} edge[M];

int n, m, q, e, mst;
int head[N], pnt[N], dis[N], d[N];
int f[N][N];
bool vis[N];
map<pair<int, int>, int> cost;

void init() {
    int i, j;
    e = 0;
    for (i = 0; i < n; i++) {
        head[i] = -1;
        for (j = 0; j < n; j++) f[i][j] = INF;
    }
}

void add_edge(int u, int v, int w) {
    edge[e].v = v, edge[e].w = w;
    edge[e].next =head[u], head[u] = e++;
}

void cal_mst(int src) {
    int i, j, x, y, z;
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        f[x][y] = f[y][x] = z;
    }
    for (i = 0; i < n; i++) {
        vis[i] = 0;
        dis[i] = f[src][i];
        pnt[i] = src;
    }
    vis[src] = 1, mst = 0;
    for (i = 1; i < n; i++) {
        x = -1, z = INF;
        for (j = 0; j < n; j++) {
            if (! vis[j] && dis[j] < z)
                z = dis[j], x = j;
        }
        if (x == -1) return;
        mst += z;
        vis[x] = 1;
        d[x] = z;
        add_edge(pnt[x], x, z), add_edge(x, pnt[x], z);
        f[pnt[x]][x] = f[x][pnt[x]] = INF;
        for (j = 0; j < n; j++) {
            if (! vis[j] && dis[j] > f[x][j])
                dis[j] = f[x][j], pnt[j] = x;
        }
    }
}

int dfs1(int u, int fa, int rt) {
    int i, v;
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (v != fa) f[rt][u] = min(f[rt][u], dfs1(v, u, rt));
    }
    return f[rt][u];
}

int dfs2(int u, int fa, int rt) {
    int i, v, ans = f[u][rt];
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (v != fa) ans = min(ans, dfs2(v, u, rt));
    }
    return ans;
}

void cal_min() {
    int i, v, w;
    for (i = 0; i < n; i++) dfs1(i, i, i);
    cost.clear();
    for (i = 1; i < n; i++) {
        v = pnt[i];
        w = dfs2(v, i, i);
        cost[make_pair(v, i)] = cost[make_pair(i, v)] = w;
    }
}

void cal_ans() {
    int i, x, y, z;
    scanf("%d", &q);
    double ans = mst * q;
    for (i = 0; i < q; i++) {
        scanf("%d%d%d", &x, &y, &z);
        if (cost.count(make_pair(x, y))) {
            z = min(z, cost[make_pair(x, y)]);
            ans += z;
            if (pnt[x] == y) ans -= d[x];
            else ans -= d[y];
        }
    }
    printf("%.4lf\n", ans / q);
}

int main() {
    int i, j;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        init();
        cal_mst(0);
        cal_min();
        cal_ans();
    }
    return 0;
}
