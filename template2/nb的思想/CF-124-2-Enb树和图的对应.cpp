#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

typedef long long LL;

const int N = 1505, M = N * 2, INF = ~0U >> 2;

struct Point {
    int x, y, h;
} p[N];

struct NODE {
    int v, next;
} edge[M];

int n, e, cp;
int ans[N], size[N], head[N];
bool ab[N];

LL cross(int x1, int y1, int x2, int y2) {
    return (LL) x1 * y2 - (LL) x2 * y1;
}

bool cmp(const Point &arg0, const Point &arg1) {
    return cross(arg0.x - p[cp].x, arg0.y - p[cp].y, arg1.x - p[cp].x, arg1.y - p[cp].y) < 0;
}

void init() {
    e = 0;
    fill(head + 1, head + n + 1, -1);
}

void add_edge(int u, int v) {
    edge[e].v = v, edge[e].next = head[u], head[u] = e++;
}

void dfs(int u, int fa) {
    int i, v;
    size[u] = 1;
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (v == fa) continue;
        dfs(v, u);
        size[u] += size[v];
    }
}

void solve(int id, int l, int r) {
    int i, j, v = INF;
    for (i = l; i <= r; i++)
        if (p[i].x < v) v = p[i].x, j = i;
    swap(p[l], p[j]);
    cp = l;
    ans[p[cp].h] = id, ab[id] = 1;
    if (l == r) return;
    sort(p + l + 1, p + r + 1, cmp);
    j = l;
    for (i = head[id]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (ab[v]) continue;
        solve(v, j + 1, j + size[v]);
        j += size[v];
    }
}

int main() {
    int i, j, u, v;
    while (scanf("%d", &n) != EOF) {
        init();
        for (i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        for (i = 1; i <= n; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
            p[i].h = i;
        }
        dfs(1, -1);
        //cout << "PPPP"; pause;
        //for (i = 1; i <= n; i++) cout << size[i] << endl; pause;
        fill(ab + 1, ab + n + 1, 0);
        solve(1, 1, n);
        for (i = 1; i < n; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
    }
    return 0;
}
