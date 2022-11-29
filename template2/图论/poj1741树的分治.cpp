#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 10005, M = N * 4, INF = ~0U >> 2;

struct NODE {
    int v, w, next, an, ab;
} edge[M];

int T, n, m, e, x, y, ea, eb;
int head[N], s[N], dis[N], a[N], b[N];

void init() {
    e = 0;
    fill(head + 1, head + n + 1, -1);
}

void add_edge(int u, int v, int w) {
    edge[e].v = v, edge[e].w = w, edge[e].ab = 1, edge[e].an = e ^ 1;
    edge[e].next = head[u], head[u] = e++;
}

void dfs_cent(int p, int num) {
    int i, v, maxi = -1;
    s[p] = 1;
    for (i = head[p]; i != -1; i = edge[i].next) {
        if (!edge[i].ab) continue;
        v = edge[i].v;
        edge[i].ab = edge[i ^ 1].ab = 0;
        dfs_cent(v, num);
        edge[i].ab = edge[i ^ 1].ab = 1;
        s[p] += s[v];
        maxi = max(maxi, s[v]);
    }
    maxi = max(maxi, num - s[p]);
    if (maxi < x || (maxi == x && p < y)) x = maxi, y = p;
}

void dfs_dis(int p) {
    int i, v;
    s[p] = 1;
    for (i = head[p]; i != -1; i = edge[i].next) {
        if (!edge[i].ab) continue;
        v = edge[i].v;
        dis[v] = edge[i].w + dis[p];
        b[eb++] = dis[v];
        edge[i].ab = edge[i ^ 1].ab = 0;
        dfs_dis(v);
        edge[i].ab = edge[i ^ 1].ab = 1;
        s[p] += s[v];
    }
}

int cal(int a[], int e) {
    int i, j, ans;
    i = ans = 0, j = e - 1;
    while (i < j) {
        if (a[i] + a[j] <= m) {
            ans += j - i;
            i++;
        } else j--;
    }
    return ans;
}

int solve(int p) {
    int i, j, v, t, t2, ans = 0;
    ea = 0, t = 0;
    a[ea++] = 0;
    for (i = head[p]; i != -1; i = edge[i].next) {
        if (! edge[i].ab) continue;
        v = edge[i].v;
        dis[v] = edge[i].w;
        eb = 0;
        b[eb++] = dis[v];
        edge[i].ab = edge[i ^ 1].ab = 0;
        dfs_dis(v);
        edge[i].ab = edge[i ^ 1].ab = 1;
        sort(b, b + eb);
        t += cal(b, eb);
        copy(b, b + eb, a + ea);
        ea += eb;
    }
    sort(a, a + ea);
    ans = cal(a, ea);
    ans -= t;
    for (i = head[p]; i != -1; i = edge[i].next) {
        if (! edge[i].ab) continue;
        v = edge[i].v;
        edge[i].ab = edge[i ^ 1].ab = 0;
        x = INF;
        dfs_cent(v, s[v]);
        ans += solve(y);
        edge[i].ab = edge[i ^ 1].ab = 1;
    }
    return ans;
}

int main() {
    int i, j, u, v, w, ans;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        init();
        for (i = 1; i < n; i++) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w), add_edge(v, u, w);
        }
        x = INF;
        dfs_cent(1, n);
        ans = solve(y);
        printf("%d\n", ans);
    }
    return 0;
}
