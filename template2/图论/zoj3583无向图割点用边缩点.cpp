#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define sqr(x) ((x)*(x))

using namespace std;
int chh;

const int N = 105, M = 10005;

struct NODE {
    int u, v, next;
} edge[M];

int n, m, e, idx, top, cnt, root;
int head[N], dfn[N], low[N], id[N], q[N], h[N], is_g[N];
int vis[N], sum[N], scc[M];

void init() {
    e = idx = top = cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(id, -1, sizeof(id));
    memset(is_g, 0, sizeof(is_g));
}

void add_edge(int u, int v) {
    edge[e].u = u, edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void get_block() {
    int i, j, u, v;
    for (i = 1; i <= h[0]; i++) {
        u = h[i];
        for (j = head[u]; j != -1; j = edge[j].next) {
            v = edge[j].v;
            if (id[u] == id[v]) scc[j] = cnt;
        }
    }
}

void Tarjan(int u, int fa) {
    int i, j, v, t, now = 0;
    dfn[u] = low[u] = ++idx;
    q[++top] = u;
    for(i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (dfn[v] == 0) {
            now++;
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (u == root && now > 1) is_g[u] = 1;
            if (u != root && dfn[u] <= low[v]) is_g[u] = 1;
            if(dfn[u] <= low[v]) {
                cnt++, sum[cnt] = h[0] = 0;
                do {
                    t = q[top--];
                    id[t] = cnt;
                    h[++h[0]] = t;
                    sum[cnt]++;
                } while (t != v);
                id[u] = cnt;
                h[++h[0]] = u;
                sum[cnt]++;
                get_block();
            }
        } else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
}

int S, T, res;
int pre[N];

void bfs() {
    int i, u, v, t = 0;
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    vis[S] = 1, q[t++] = S;
    while (t) {
        u = q[--t];
        for (i = head[u]; i != -1; i = edge[i].next) {
            v = edge[i].v;
            if (vis[v]) continue;
            vis[v] = 1, pre[v] = i;
            q[t++] = v;
        }
    }
}

int main() {
    int i, j, k, u, v, p;
    while (scanf("%d %d %d %d", &n, &m, &S, &T) != EOF) {
        init();
        S++, T++;
        for (i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            u++, v++;
            add_edge(u, v), add_edge(v, u);
        }
        bfs();
        for (i = 1; i <= n; i++) {
            if (! vis[i]) continue;
            if (dfn[i] == 0)
                root = i, Tarjan(i, i);
        }
        memset(vis, 0, sizeof(vis));
        res = p = 0;
        for (i = pre[T]; i != -1; i = pre[edge[i].u]) vis[scc[i]] = 1;
        for (i = 1; i <= cnt; i++)
            if (vis[i]) p++, res += sum[i];
        res -= p - 1;
        printf("%d\n", n - res);
    }
    return 0;
}
