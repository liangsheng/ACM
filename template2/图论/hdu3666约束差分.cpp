/*
判断有无解（负环）的时候，如果用spfa，不能用入队次数大于N来判断，会超时。
有如下两种比较可靠的方法（一般情况下）
1：某个点入队次数大于sqrt(N)的时候
2：所有入队次数大于T * （N + M），其中T一般取2
*/

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
#define lowbit(x) ((x) & (-x))

using namespace std;
int chh;

const int N = 805, M = 800 * 400 + 5, INF = ~0U >> 2;

struct NODE {
    int v, next;
    double w;
} edge[M];

int n, m, e, L, R;
int head[N], vis[N], num[N];
double dis[N];
queue<int> q;

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, double w) {
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
}

bool spfa(int src, int tol) {
    int i, u, v, cnt = sqrt(tol) + 1, hh = 0;
    for (i = 1; i <= tol; i++) {
        num[i] = 0, dis[i] = INF;
        vis[i] = 1, q.push(i);
    }
    dis[src] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop(), vis[u] = 0;
        for (i = head[u]; i != -1; i = edge[i].next) {
            v = edge[i].v;
            if (edge[i].w + dis[u] < dis[v]) {
                dis[v] = dis[u] + edge[i].w;
                if (! vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                    //if (++num[v] >= cnt) return 0;
                    if (++hh > 2 * tol) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    int i, j, x;
    double l, r, y;
    while (scanf("%d %d %d %d", &n, &m, &L, &R) != EOF) {
        init();
        l = log(L), r = log(R);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                scanf("%d", &x);
                y = log(x);
                add_edge(i, j + n, y - l);
                add_edge(j + n, i, r - y);
            }
        }
        if (spfa(1, n + m)) puts("YES");
        else puts("NO");
    }
    return 0;
}
