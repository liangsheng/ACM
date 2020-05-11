#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 105, M = 1005, K = 1005;

struct NODE {
    int v, next;
} edge[M], ask[K];

int e, ee;
int head[N], h[N];

void init() {
    e = ee = 0;
    memset(head, -1, sizeof(head));
    memset(h, -1, sizeof(h));
}

void add_edge(int &e, int u, int v, NODE edge[M], int head[N]) {
    edge[e].v = v, edge[e].next = head[u], head[u] = e++;
}

/*==================================================*\
| LCA 离线算法 O(E)+O(1)
| INIT: id[]置为-1; g[]置为邻接矩阵;
| CALL: for (i=0; i<n; ++i) if (-1==st[i]) dfs(i, n);
|
LCA转化为RMQ的方法: 对树进行DFS遍历, 每当进入或回溯到
| 某个结点i时, 将i的深度存入数组e[]最后一位. 同时记录结点i在
| 数组中第一次出现的位置, 记做r[i]. 结点e[i]的深度记做d[i].
| LCA(T,u,v), 等价于求E[RMQ(d,r[u],r[v])], (r[u]<r[v]).
\*==================================================*/
int id[N], lcs[N][N];

int get(int i) {
    if (id[i] == i) return i;
    return id[i] = get(id[i]);
}

void unin(int i, int j) {
    id[get(i)] = get(j);
}

void dfs(int rt, int n) { // 使用邻接表可优化为 O(E)+O(1)
    int i, v;
    id[rt] = rt;
    for (i = head[rt]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (id[v] != -1) continue;
        dfs(v, n);
        unin(v, rt);
    }
    for (i = h[rt]; i != -1; i = ask[i].next) {
        v = ask[i].v;
        if (id[v] == -1) continue;
        lcs[rt][v] = lcs[v][rt] = get(v);
        cout << rt << " " << v << " " << lcs[rt][v] << endl;
    }
}

int main() {
    int i, j, n, m, k, u, v;
    scanf("%d %d %d", &n, &m, &k);
    init();
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        add_edge(e, u, v, edge, head), add_edge(e, v, u, edge, head);
    }
    for (i = 1; i <= k; i++) {
        scanf("%d %d", &u, &v);
        add_edge(ee, u, v, ask, h), add_edge(ee, v, u, ask, h);
    }
    memset(id, -1, sizeof(id));
    for (i = 1; i <= n; i++) {
        if (id[i] == -1) dfs(i, n);
    }
    return 0;
}
