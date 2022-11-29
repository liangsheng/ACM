#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 405, M = 10005;

struct NODE {
    int v, next;
};

int T, n, m, e, ct, scc;;
int a[M], b[M], c[M];
int head[N], dfn[N], low[N], ins[N], sccf[N];
NODE edge[N * N];
stack<int> s;

void init() {
    e = ct = scc = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ins, 0, sizeof(ins));
    memset(sccf, 0, sizeof(sccf));
}

void add_edge(int u, int v) {
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void Tarjan(int u) {
    int i, v;
    low[u] = dfn[u] = ++ct;
    s.push(u);
    ins[u] = 1;
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (dfn[v] == 0) {
            Tarjan(v);
            low[u] = low[u] < low[v] ? low[u] : low[v];
        } else if (ins[v] && dfn[v] < low[u]) low[u] = dfn[v];
    }
    if (low[u] == dfn[u]) {
        scc++;
        do {
            v = s.top();
            s.pop();
            ins[v] = 0;
            sccf[v] = scc;
        }  while(u != v);
    }
}

bool solve(int mid) {
    int i, j, x1, x2, x3;
    for (i = 0; i < mid; i++) {
        x1 = a[i], x2 = b[i], x3 = c[i];
        if (x3 == 0) {
            add_edge(x1 << 1, x2 << 1 | 1);
            if (x1 != x2) add_edge(x2 << 1, x1 << 1 | 1);
        } else if (x3 == 2) {
            add_edge(x1 << 1 | 1, x2 << 1);
            if (x1 != x2) add_edge(x2 << 1 | 1, x1 << 1);
        } else {
            if (x1 == x2) continue;
            add_edge(x1 << 1, x2 << 1);
            add_edge(x2 << 1, x1 << 1);
            add_edge(x1 << 1 | 1, x2 << 1 | 1);
            add_edge(x2 << 1 | 1, x1 << 1 | 1);
        }
    }
    for (i = 0; i < 2 * n; i++)
        if (dfn[i] == 0) Tarjan(i);
    for (i = 1; i < 2 * n; i += 2)
        if (sccf[i] == sccf[i - 1]) return 0;
    return 1;
}

int main() {
    int i, j, l, r, mid;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (i = 0; i < m; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
        l = 1, r = m;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            init();
            if (solve(mid)) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
