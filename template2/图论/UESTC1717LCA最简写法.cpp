#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 100005, M = N * 2, DEP = 20;

struct NODE {
    int v, w, next;
} edge[M];

int T, n, m, e;
int head[N], dis[N], dp[N][DEP], dep[N];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w) {
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
}

void dfs(int u, int fa, int d, int s) {
    int i, v, w;
    dis[u] = d, dep[u] = s;
    dp[u][0] = fa;
    for (i = 1; i < DEP; i++) dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (v == fa) continue;
        w = d + edge[i].w;
        dfs(v, u, w, s + 1);
    }
}

int LCA(int a, int b) {
    if (dep[a] < dep[b])swap(a, b);
    for (int i = DEP - 1; i >= 0; i--)
        if (dep[dp[a][i]] >= dep[b]) a = dp[a][i];
    if (a == b) return a;
    for (int i = DEP - 1; i >= 0; i--)
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i], b = dp[b][i];
        }
    return dp[a][0];
}

int main() {
    int i, c1, c2, u, v, w, uu, vv, ww, t1, t2, ans, cas = 0;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d:\n", ++cas);
        scanf("%d %d", &n, &m);
        init();
        for (i = 1; i < n; i++) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w), add_edge(v, u, w);
        }
        dfs(1, 1, 0, 1);
        scanf("%d %d %d", &uu, &vv, &ww);
        for (i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            c1 = LCA(u, v);
            ans = dis[u] + dis[v] - 2 * dis[c1];
            c1 = LCA(u, uu), c2 = LCA(v, vv);
            t1 = dis[u] + dis[uu] - 2 * dis[c1] + dis[v] + dis[vv] - 2 * dis[c2] + ww;
            c1 = LCA(u, vv), c2 = LCA(v, uu);
            t2 = dis[u] + dis[vv] - 2 * dis[c1] + dis[v] + dis[uu] - 2 * dis[c2] + ww;
            t1 = min(t1, t2);
            if (t1 >= ans) puts("0");
            else printf("%d\n", ans - t1);
        }
    }
    return 0;
}
