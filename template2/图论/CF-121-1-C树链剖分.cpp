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

const int V = 100005, E = 200005, INF = ~0U >> 2;

int e, n;
int size[V], f[V], P[V], dep[V], heavy[V];
int head[V], pnt[E], nxt[E], flag[E];
int kf[V], tf[V];
int a[V << 2], b[E];

void init() {
    e = 0;
    fill(head, head + n, -1);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
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
        P[v] = i ^ 1;
        dfs(v, u);
        size[u] += size[v];
        if (size[v] > maxi) maxi = size[v], s = i;
    }
    heavy[u] = s;
    if (s != -1) f[pnt[s]] = u;
}

void init_seg(int k, int s, int t, int tmp) {
    int mid = (s + t) >> 1;
    a[k + tmp] = 0;
    if (s == t) return;
    init_seg(k << 1, s, mid, tmp);
    init_seg(k << 1 | 1, mid + 1, t, tmp);
}

void update(int k, int s, int t, int l, int r, int val, int tmp) {
    int mid = (s + t) >> 1;
    if (t < l || s > r) return;
    if (s >= l && t <= r) a[k + tmp] += val;
    else {
        update(k << 1, s, mid, l, r, val, tmp);
        update(k << 1 | 1, mid + 1, t, l, r, val, tmp);
    }
}

int find(int k, int s, int t, int x, int tmp) {
    int ans, mid = (s + t) >> 1;
    if (x < s || x > t) return 0;
    if (s == t) return a[k + tmp];
    return a[k + tmp] + find(k << 1, s, mid, x, tmp) + find(k << 1 | 1, mid + 1, t, x, tmp);
}

void prepare() {
    int i, v, cnt = 0, num;
    memset(b, 0, sizeof(b));
    for (i = 0; i < n; i++) f[i] = i;
    dep[0] = 0, P[0] = -1;
    dfs(0, -1);
    for (i = 0; i < n; i++) {
        if (heavy[i] != -1) continue;
        v = i, num = 0;
        while (v && pnt[heavy[pnt[P[v]]]] == v) {
            flag[P[v]] = flag[P[v] ^ 1] = num++;
            v = pnt[P[v]];
        }
        if (num == 0) continue;             //轻边
        init_seg(1, 0, num - 1, cnt);
        kf[v] = cnt, tf[v] = num;
        cnt += num << 2;
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

void query(int u, int v) {
    int l, r, p, fa;
    while (u != v) {
        l = P[u];
        if (pnt[heavy[pnt[l]]] == u) {
            fa = find(u);
            p = dep[fa] > dep[v] ? fa : v;
            r = heavy[p];
            assert(flag[l] <= flag[r]);
            update(1, 0, tf[fa] - 1, flag[l], flag[r], 1, kf[fa]);
            u = p;
        } else {
            u = pnt[l];
            b[l]++, b[l ^ 1]++;
        }
    }
}

void ask(int a, int b) {
    int p = lca(a, b);
    query(a, p);
    query(b, p);
}

int m;

int main() {
    int i, j, u, v, w, fa, ans;
    while (scanf("%d", &n) != EOF) {
        init();
        for (i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            u--, v--;
            add_edge(u, v), add_edge(v, u);
        }
        prepare();
        scanf("%d", &m);
        for (i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            u--, v--;
            ask(u, v);
        }
        for (i = 0; i < e; i += 2) {
            v = pnt[i], u = pnt[i ^ 1];
            if (heavy[u] != i && heavy[v] != (i ^ 1)) {
                printf("%d ", b[i]);
            }
            else {
                fa = find(u);
                ans = find(1, 0, tf[fa] - 1, flag[i], kf[fa]);
                printf("%d ", ans);
            }
        }
        puts("");
    }
    return 0;
}
