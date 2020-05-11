/*
对于无向图点双联通缩点, 应该把所有的联通块(除去割点)和割点, 各自当作一点建图, 这样建出来的图
才是图或者森林.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 10005, M = 100005, Q = 10005;

struct NODE {
    int v, next;
} edge[M * 2], ed[M * 2];

int n, m, e, idx, top, cnt, ee, root;
int head[N], dfn[N], low[N], id[N], q[N], h[N], is_g[N];
int scc[M * 2], he[N], vis[N];
int asku[Q], askv[Q], dep[N];
map<pair<int, int>, int> ans;

void init() {
    e = idx = top = 0;
    cnt = n;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(id, -1, sizeof(id));
    memset(is_g, 0, sizeof(is_g));
}

void add_edge(int &e, int u, int v, NODE edge[], int head[]) {
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void get_block() {
    int i, j, u, v;
    for (i = 1; i <= h[0]; i++) {
        u = h[i];
        for (j = head[u]; j != -1; j = edge[j].next) {
            v = edge[j].v;
            if (id[u] == id[v]) scc[j] = cnt;
        }
    }
}

void Tarjan(int u, int fa) {
    int i, j, v, t, now = 0;
    dfn[u] = low[u] = ++idx;
    q[++top] = u;
    for(i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (dfn[v] == 0) {
            now++;
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (u == root && now > 1) is_g[u] = 1;
            if (u != root && dfn[u] <= low[v]) is_g[u] = 1;
            if(dfn[u] <= low[v]) {
                cnt++, h[0] = 0;
                do {
                    t = q[top--];
                    id[t] = cnt;
                    h[++h[0]] = t;
                    //cout << t << " ";
                } while (t != v);
                id[u] = cnt;
                h[++h[0]] = u;
                //cout << u << " ", pause;
                get_block();
            }
        } else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
}

int get(int i) {
    if (id[i] == i) return i;
    return id[i] = get(id[i]);

    /*  防止暴栈的写法
    int r = i, t;
    while (id[r] != r) r = id[r];
    while (id[i] != i) {
        t = id[i];
        id[i] = r;
        i = t;
    }
    */
}

void unin(int i, int j) {
    id[get(i)] = get(j);
}

void dfs(int rt, int n) { // 使用邻接表可优化为 O(E)+O(1)
    int i, v, tmp;
    id[rt] = rt;
    for (i = he[rt]; i != -1; i = ed[i].next) {
        v = ed[i].v;
        if (id[v] != -1) continue;
        dfs(v, n);
        unin(v, rt);
    }
    for (i = head[rt]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (id[v] == -1) continue;
        tmp = get(v);
        if (rt < v) ans[make_pair(rt, v)] = tmp;
        else ans[make_pair(v, rt)] = tmp;
    }
}

void get_dep(int p, int fa, int step) {
    int i, v;
    dep[p] = step;
    for (i = he[p]; i != -1;i = ed[i].next) {
        v = ed[i].v;
        if (v != fa) get_dep(v, p, step + 1);
    }
}

int main() {
    int i, j, k, u, v, x, y, num;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        init();
        for (i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            add_edge(e, u, v, edge, head);
            add_edge(e, v, u, edge, head);
        }
        for (i = 1; i <= n; i++) {
            if (dfn[i] == 0)
                root = i, Tarjan(i, i);
        }
        ee = 0;
        memset(he, -1, sizeof(he));
        k = 0;
        cnt = cnt - n;
        for (i = 1; i <= n; i++) {
            if (! is_g[i]) continue;
            memset(vis, 0, sizeof(vis));
            k++;
            for (j = head[i]; j != -1; j = edge[j].next) {
                if (vis[scc[j] - n]) continue;
                vis[scc[j] - n] = 1;
                add_edge(ee, cnt + k, scc[j] - n, ed, he);
                add_edge(ee, scc[j] - n, cnt + k, ed, he);
            }
        }
        num = cnt + k;
        fill(dep + 1, dep + num + 1, -1);
        for (i = 1; i <= num; i++)
            if (dep[i] == -1) get_dep(i, i, 1);
        scanf("%d", &k);
        e = 0;
        memset(head, -1, sizeof(head));
        for (i = 1; i <= k; i++) {
            scanf("%d %d", &u, &v);
            asku[i] = scc[u * 2 - 1] - n;
            askv[i] = scc[v * 2 - 1] - n;
            if (asku[i] > askv[i]) swap(asku[i], askv[i]);
            if (asku[i] == askv[i]) continue;
            add_edge(e, asku[i], askv[i], edge, head);
            add_edge(e, askv[i], asku[i], edge, head);
        }
        ans.clear();
        memset(id, -1, sizeof(id));
        for (i = 1; i <= cnt; i++) {
            if (id[i] == -1) dfs(i, cnt);
        }
        for (i = 1; i <= k; i++) {
            if (asku[i] == askv[i]) puts("0");
            else {
                u = ans[make_pair(asku[i], askv[i])];
                j = dep[asku[i]] + dep[askv[i]] - 2 * dep[u];
                printf("%d\n", j >> 1);
            }
        }
    }
    return 0;
}
