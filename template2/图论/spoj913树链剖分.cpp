#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int V = 10005, E = 20005, INF = ~0U >> 2;

int e, n;
int size[V], f[V], P[V], dep[V], dis[V], heavy[V];
int head[V], pnt[E], nxt[E], wv[E], flag[E], h[V];
int kf[V], tf[V], a[V];

void init() {
    e = 0;
    fill(head, head + n, -1);
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w, nxt[e] = head[u], head[u] = e++;
}

int find(int x) {
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

void dfs(int u, int fa) {
    int i, v, s = -1, maxi = 0;
    size[u] = 1;
    for (i = head[u]; i != -1; i = nxt[i]) {
        v = pnt[i];
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dis[v] = dis[u] + wv[i];
        P[v] = i ^ 1;
        dfs(v, u);
        size[u] += size[v];
        if (size[v] > maxi) maxi = size[v], s = i;
    }
    heavy[u] = s;
    if (s != -1) f[pnt[s]] = u;
}

void prepare() {
    int i, v, cnt = 0, num;
    for (i = 0; i < n; i++) f[i] = i;
    dep[0] = dis[0] = 0, P[0] = -1;
    dfs(0, -1);
    for (i = 0; i < n; i++) {
        if (heavy[i] != -1) continue;
        v = i, num = 0;
        while (v && pnt[heavy[pnt[P[v]]]] == v) {
            flag[P[v]] = flag[P[v] ^ 1] = num;
            h[num++] = P[v];
            v = pnt[P[v]];
        }
        if (num == 0) continue;             //轻边
        kf[v] = cnt, tf[v] = num;
        copy(h, h + num, a + cnt);
        cnt += num;
    }
}

int lca(int u, int v) {
    int a, b;
    while (1) {
        a = find(u), b = find(v);
        if (a == b) return dep[u] < dep[v] ? u : v;
        if (dep[a] < dep[b]) v = pnt[P[b]];
        else u = pnt[P[a]];
    }
}

int query(int u, int v, int k) {
    int l, r, p, fa, tmp, cnt = 0;
    while (u != v) {
        l = P[u];
        if (pnt[heavy[pnt[l]]] == u) {
            fa = find(u);
            p = dep[fa] > dep[v] ? fa : v;
            r = heavy[p];
            tmp = flag[r] - flag[l] + 1;
            if (tmp + cnt >= k) return pnt[a[kf[fa] + flag[l] + k - cnt - 1]];
            cnt += tmp;
            u = p;
        } else {
            u = pnt[l];
            if (++cnt == k) return u;
        }
    }
}

int ask_kth(int a, int b, int k) {
    int p = lca(a, b), tmp = dep[a] - dep[p] + 1;
    if (k == 1) return a;
    if (k == tmp) return p;
    if (k == tmp + dep[b] - dep[p]) return b;
    if (k > tmp + dep[b] - dep[p]) return -1;
    if (tmp > k) return query(a, p, k - 1);
    tmp = dep[a] + dep[b] - dep[p] * 2;
    return query(b, p, tmp - k + 1);
}

int ask_dis(int a, int b) {
    int p = lca(a, b);
    return dis[a] + dis[b] - 2 * dis[p];
}

int T, m;

int main() {
    int i, j, u, v, x, y, w;
    char cmd[10];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        for (i = 1; i < n; i++) {
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            add_edge(u, v, w), add_edge(v, u, w);
        }
        prepare();
        while (~scanf("%s", cmd)) {
            if (cmd[0] == 'D') {
                if (cmd[1] == 'O') break;
                scanf("%d %d", &u, &v);
                u--, v--;
                printf("%d\n", ask_dis(u, v));
            } else {
                scanf("%d %d %d", &u, &v, &i);
                u--, v--;
                printf("%d\n", ask_kth(u, v, i) + 1);
            }
        }
    }
    return 0;
}
