/*
题意:给定一棵树,问删除哪个点,使余下的各个子树结点个数的最大值最小
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

const int N = 20005, M = N * 4, INF = ~0U >> 2;

struct NODE {
    int v, next;
} edge[M];

int T, n, e, x, y;
int head[N], s[N];

void init() {
    e = 0;
    fill(head + 1, head + n + 1, -1);
}

void add_edge(int u, int v) {
    edge[e].v = v, edge[e].next = head[u], head[u] = e++;
}

void dfs(int p, int fa) {
    int i, v, maxi = -1;
    s[p] = 1;
    for (i = head[p]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (v == fa) continue;
        dfs(v, p);
        s[p] += s[v];
        maxi = max(maxi, s[v]);
    }
    if (fa != -1) maxi = max(maxi, n - s[p]);
    if (maxi == -1) return;
    if (maxi < x || (maxi == x && p < y)) x = maxi, y = p;
}

int main() {
    int i, j, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        for (i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        x = INF;
        dfs(1, -1);
        printf("%d %d\n", y, x);
    }
    return 0;
}
