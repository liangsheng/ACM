#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 15, M = 30 * 2 + 5;

struct NODE {
    int v, next, id;
} edge[M];

int n, m, e;
int head[N], vis[N], s[N];
set<int> hash;

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int id) {
    edge[e].v = v, edge[e].id = id;
    edge[e].next = head[u], head[u] = e++;
}

bool check(int edge_state) {
    int i, u, v, id, t = 1, top = 0;
    memset(vis, 0, sizeof(vis));
    s[top++] = 0, vis[0] = 1;
    while (top) {
        u = s[--top];
        for (i = head[u]; i != -1; i = edge[i].next) {
            v = edge[i].v, id = edge[i].id;
            if ((1 << id) & edge_state) continue;
            if (vis[v]) continue;
            t++;
            vis[v] = 1;
            s[top++] = v;
        }
    }
    return (t == n);
}

bool search(int node_state, int edge_state) {
    if (hash.count(edge_state)) return 0;
    if (!check(edge_state)) return 0;
    if (node_state == (1 << n) - 1) return 1;
    hash.insert(edge_state);
    int i, j, v, id;
    for (i = 0; i < n; i++) {
        if (!((1 << i) & node_state)) continue;
        for (j = head[i]; j != -1; j = edge[j].next) {
            v = edge[j].v, id = edge[j].id;
            if ((1 << v) & node_state) continue;
            if ((1 << id) & edge_state) continue;
            if (search(node_state | (1 << v), edge_state | (1 << id))) return 1;
        }
    }
    return 0;
}

int main() {
    int i, j, u, v;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == -1 && m == -1) break;
        init();
        for (i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            add_edge(u, v, i), add_edge(v, u, i);
        }
        hash.clear();
        if (search(1, 0)) puts("YES");
        else puts("NO");
    }
    return 0;
}
