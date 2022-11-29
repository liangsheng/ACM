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
int size[V], f[V], P[V], dep[V], heavy[V];
int head[V], pnt[E], nxt[E], wv[E], flag[E], h[V];
int kf[V], tf[V];
int a[V << 2];

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
    if (s == t) {
        a[k + tmp] = h[s];
        return;
    }
    init_seg(k << 1, s, mid, tmp);
    init_seg(k << 1 | 1, mid + 1, t, tmp);
    a[k + tmp] = max(a[(k << 1) + tmp], a[(k << 1 | 1) + tmp]);
}

void update(int k, int s, int t, int x, int val, int tmp) {
    int mid = (s + t) >> 1;
    if (x < s || x > t) return;
    if (s == t) {
        a[k + tmp] = val;
        return;
    }
    if (x <= mid) update(k << 1, s, mid, x, val, tmp);
    else update(k << 1 | 1, mid + 1, t, x, val, tmp);
    a[k + tmp] = max(a[(k << 1) + tmp], a[(k << 1 | 1) + tmp]);
}

int find(int k, int s, int t, int l, int r, int tmp) {
    int ans, mid = (s + t) >> 1;
    if (s > r || t < l) return -INF;
    if (s >= l && t <= r) return a[k + tmp];
    ans = find(k << 1, s, mid, l, r, tmp);
    ans = max(ans, find(k << 1 | 1, mid + 1, t, l, r, tmp));
    return ans;
}

void prepare() {
    int i, v, cnt = 0, num;
    for (i = 0; i < n; i++) f[i] = i;
    dep[0] = 0, P[0] = -1;
    dfs(0, -1);
    for (i = 0; i < n; i++) {
        if (heavy[i] != -1) continue;
        v = i, num = 0;
        while (v && pnt[heavy[pnt[P[v]]]] == v) {
            flag[P[v]] = flag[P[v] ^ 1] = num;
            h[num++] = wv[P[v]];
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

int query(int u, int v) {
    int l, r, p, fa, ans = -INF;
    while (u != v) {
        l = P[u];
        if (pnt[heavy[pnt[l]]] == u) {
            fa = find(u);
            p = dep[fa] > dep[v] ? fa : v;
            r = heavy[p];
            assert(flag[l] <= flag[r]);
            ans = max(ans, find(1, 0, tf[fa] - 1, flag[l], flag[r], kf[fa]));
            u = p;
        } else {
            u = pnt[l];
            ans = max(ans, wv[l]);
        }
    }
    return ans;
}

int ask(int a, int b) {
    int p = lca(a, b);
    return max(query(a, p), query(b, p));
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
            if (cmd[0] == 'D') break;
            scanf("%d %d", &u, &v);
            if (cmd[0] == 'Q') {
                u--, v--;
                printf("%d\n", ask(u, v));
            } else {
                x = pnt[2 * u - 1], y = pnt[2 * u - 2];
                if (heavy[x] != 2 * u - 2 && heavy[y] != 2 * u - 1) wv[2 * u - 1] = wv[2 * u - 2] = v;
                else {
                    y = find(x);
                    update(1, 0, tf[y] - 1, flag[2 * u - 1], v, kf[y]);
                }
            }
        }
    }
    return 0;
}
