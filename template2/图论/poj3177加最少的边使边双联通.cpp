#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 5005, M = 20005;

struct Node {
    int u, v, next;
} edge[M], h[M];

int n, m, e, et, cnt, idx, top;
int head[N], dfn[N], low[N], q[N], id[N], de[N];

void init() {
    e = et = cnt = idx = top = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
}

void add_edge(int u, int v) {
    edge[e].u = u, edge[e].v = v;
    edge[e].next = head[u], head[u] = e++;
}

int Tarjan(int u, int fa) {
    int i, v;
    dfn[u] = low[u] = ++idx;
    q[top++] = u;
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (dfn[v] == 0) {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dfn[u] < low[v]) {
                id[v]= ++cnt;
                h[++et] = edge[i];
                while (q[--top] != v) id[q[top]] = cnt;
            }
        }
        else if(v != fa) low[u] = min(low[u], dfn[v]);
    }
    return 1;
}

void solve() {
    int i, ans = 0;
    for (i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            Tarjan(i, i);
            cnt++;
            while (top--) id[q[top]] = cnt;
        }
    }
    if (cnt == 1) {
        puts("0");
        return;
    }
    memset(de, 0, sizeof(de));
    for (i = 1; i <= et; i++) {
        de[id[h[i].u]]++, de[id[h[i].v]]++;
    }
    for (i = 1; i <= cnt; i++)
        if (de[i] == 1) ans++;
    printf("%d\n", (ans + 1) / 2);
}

int main() {
    file_r("in.txt");
    file_w("out.txt");
    int i, j, u, v;
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        solve();
    }
    return 0;
}
