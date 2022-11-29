/*
每个点找其最小的入边In[v] ? 如果有除跟节点以外的点找不到入边,则无解 : 否则答案累加In[v]
看看有没有环 ? 无环则已经找到解,返回答案 : 将环缩点
重新构图,每条边[u->v]的权值减去In[v],然后重复第一步
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf (1 << 30)
#define mod 1000000007
#define N 1005
#define M 1005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct Point {
    int x, y, z;
};

struct NODE {
    int u, v, w;
    int next;
};

int n, x, y, z, e, s;
int head[N], id[N], in[N], vis[N], pre[N];
Point p[N];
NODE edge[1200000];

int dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

int add_edge(int u, int v, int w) {
    edge[e].u = u;
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
}

int init() {
    e = s = 0;
    memset(head, -1, sizeof(head));
    return 1;
}

int directedMST(int root) {
    int i, u, v, nv = n + 1, ans = 0, cntnode;
    while (1) {
        for (i = 0; i < nv; i++) in[i] = inf;
        for (i = 0; i < e; i++) {
            u = edge[i].u, v = edge[i].v;
            if (edge[i].w < in[v] && u != v) in[v] = edge[i].w, pre[v] = u;
        }
        for (i = 0; i < nv; i++) {
            if (i == root) continue;
            if (in[i] == inf) return -1;
        }
        cntnode = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for (i = 0; i < nv; i++) {
            ans += in[i];
            v = i;
            while (vis[v] != i && id[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1) {
                for (u = pre[v]; u != v; u = pre[u]) id[u] = cntnode;
                id[v] = cntnode++;
            }
        }
        if (cntnode == 0) break;
        for (i = 0; i < nv; i++)
            if (id[i] == -1) id[i] = cntnode++;
        for (i = 0; i < e; i++) {
            v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            if (edge[i].u != edge[i].v) edge[i].w -= in[v];
        }
        nv = cntnode;
        root = id[root];
    }
    return ans;
}

int main() {
    int i, j, k, t, cost;
    while (scanf("%d%d%d%d", &n, &x, &y, &z) != EOF) {
        if (n == 0) break;
        init();
        for (i = 1; i <= n; i++) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
            add_edge(s, i, x * p[i].z);
        }
        for (i = 1; i <= n; i++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &t);
                if (t == i) continue;
                cost = dist(p[i], p[t]) * y;
                if (p[i].z < p[t].z) cost += z;
                add_edge(i, t, cost);
            }
        }
        printf("%d\n",directedMST(0));
    }
    system("pause");
    return 0;
}
