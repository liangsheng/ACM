/*
树的直径(Diameter)是指树上的最长简单路。
直径的求法：两遍BFS (or DFS)
任选一点u为起点，对树进行BFS遍历，找出离u最远的点v
以v为起点，再进行BFS遍历，找出离v最远的点w。则v到w的路径长度即为树的直径
*简单证明
于是原问题可以在O(E)时间内求出
关键在于证明第一次遍历的正确性，也就是对于任意点u，距离它最远的点v一定是最长路的一端。
如果u在最长路上，那么v一定是最长路的一端。可以用反证法：假设v不是最长路的一端，则存在另一点v’使得(u→v’)是最长路的一部分，于是len(u→v’) > len(u→v)。但这与条件“v是距u最远的点”矛盾。
如果u不在最长路上，则u到其距最远点v的路与最长路一定有一交点c，且(c→v)与最长路的后半段重合，即v一定是最长路的一端

树的半径, 中心: 设dis[i]表示树上离点最远的点到i点的距离, 则若dis[j]是min(dis[1], dis[2], ... dis[n]),
j称作树的中心, dis[j]称作树的半径

树的半径的求法: 首先求出树的直径, 则直径上的点i的dis[i]必然是i到直径的两端点的距离的较大值,
而树的半径就是直径上所有dis的最小值
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 2505, M = N << 1, INF = ~0U >> 2;

struct NODE {
    int u, v, w, next;
} edge[M];

int T, n, e, pu;
int head[N], pre[N], dis[N], res[N], s[N];

void init() {
    e = 0;
    fill(head + 1, head + n + 1, -1);
}

void add_edge(int u, int v, int w) {
    edge[e].u = u, edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
}

int bfs(int p, int &w) {
    int i, u, v, ansp = p, top = 0;
    fill(pre + 1, pre + n + 1, -1);
    fill(dis + 1, dis + n + 1, INF);
    dis[p] = 0, w = 0;
    s[top++] = p;
    while (top) {
        u = s[--top];
        for (i = head[u]; i != -1; i = edge[i].next) {
            v = edge[i].v;
            if (dis[v] != INF || v == pu) continue;
            dis[v] = dis[u] + edge[i].w;
            if (dis[v] > w) w = dis[v], ansp = v;
            pre[v] = i;
            s[top++] = v;
        }
    }
    return ansp;
}

int find_path(int p, int &u, int &v) {
    int w;
    u = bfs(p, w);
    v = bfs(u, w);
    return w;
}

int solve() {
    int i, j, u, v, w1, w2, r1, r2, x, t, ans;
    pu = -1;
    ans = find_path(1, u, v);
    res[0] = 0;
    for (i = pre[v]; i != -1; i = pre[edge[i].u]) res[++res[0]] = i;
    for (i = 1; i <= res[0]; i++) {
        x = edge[res[i]].u, pu = edge[res[i]].v;
        w1 = find_path(x, u, v), r1 = w1;
        for (j = pre[v]; j != -1; j = pre[edge[j].u]) {
            x = edge[j].v;
            t = max(dis[x], dis[v] - dis[x]);
            r1 = min(r1, t);
        }
        x = edge[res[i]].v, pu = edge[res[i]].u;
        w2 = find_path(x, u, v), r2 = w2;
        for (j = pre[v]; j != -1; j = pre[edge[j].u]) {
            x = edge[j].v;
            t = max(dis[x], dis[v] - dis[x]);
            r2 = min(r2, t);
        }
        t = max(w1, w2);
        t = max(t, r1 + edge[res[i]].w + r2);
        ans = min(ans, t);
    }
    return ans;
}

int main() {
    int i, j, u, v, w, cas = 0, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        for (i = 1; i < n; i++) {
            scanf("%d %d %d", &u, &v, &w);
            u++, v++;
            add_edge(u, v, w), add_edge(v, u, w);
        }
        ans = solve();
        printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}
