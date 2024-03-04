#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 10005, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*
 * spoj_375_QTREE - Query on a tree: https://www.spoj.com/problems/QTREE/
 * 题意: 给你一棵带边权树, 可以修改边权, 询问 2 点之间的路劲上的最大值
 */

/*-------------------------- 邻接表存储 begin -------------*/
int n, e, cnt;
int head[N], pnt[M], nxt[M], wv[M];

void init() {
    e = 0, cnt = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w;
    nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

/*-------------------------- 树链剖分 begin ---------------*/
int fa[N];   // 表示节点 x 在树上的父亲
int dep[N];  // 表示节点 x 在树上的深度
int sz[N];   // 表示节点 x 的子树的节点个数
int son[N];  // 表示节点 x 的 重儿子, 节点数最多的子节点, 没有子节点为 -1
int top[N];  // 表示节点 x 所在 重链 的顶部节点（深度最小）
int dfn[N];  // 表示节点 x 的 DFS 序，也是其在线段树中的编号
int rnk[N];  // 表示 DFS 序所对应的节点编号，有 rnk(dfn(x))=x

// 第一次 dfs 求出 fa, dep, sz, son
void dfs1(int u, int pre, int d) {
    dep[u] = d, sz[u] = 1;
    fa[u] = pre, son[u] = -1; 
    repe (i, u) if (pnt[i] != pre) {
        int v = pnt[i];
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
    }
}

// 第二次 dfs 求出 top, dfn, rnk
void dfs2(int u, int p) {
    top[u] = p;
    dfn[u] = ++cnt;  // cnt 是 dfs 序列的序号, 初始为 0
    rnk[cnt] = u;
    if (son[u] == -1) return ;
    dfs2(son[u], p);  // 优先遍历重儿子, 保证重节点在 dfs 序列中连续
    repe (i, u) if (pnt[i] != fa[u]) {
        if (pnt[i] != son[u]) dfs2(pnt[i], pnt[i]);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
        else v = fa[top[v]];
    }
    return dep[u] > dep[v] ? v : u;
}
/*-------------------------- 树链剖分 end -----------------*/

/*-------------------------- 线段树 begin ----------------*/
int a[N << 2];

// 初始化线段树
void init(int k, int s, int t) {
    if (s == t) {
        a[k] = 0;  // 这里可以写自己的初始化逻辑
        return ;
    }
    int mid = (s + t) >> 1;
    init(k << 1, s, mid);
    init(k << 1 | 1, mid + 1, t);
    // 这里可以写自己的初始化逻辑, 这里是求较大值
    a[k] = max(a[k << 1], a[k << 1 | 1]);
}

// 单点更新
void update(int k, int s, int t, int x, int val) {
    if (x < s || x > t) return;
    if (s == t) {
        a[k] = val;
        return;
    }
    int mid = (s + t) >> 1;
    if (x <= mid) update(k << 1, s, mid, x, val);
    else update(k << 1 | 1, mid + 1, t, x, val);
    a[k] = max(a[k << 1], a[k << 1 | 1]);
}

// 区间查询
int query(int k, int s, int t, int l, int r) {
    if (s > r || t < l) return -INF;
    if (s >= l && t <= r) return a[k];
    int mid = (s + t) >> 1;
    int ans = query(k << 1, s, mid, l, r);
    ans = max(ans, query(k << 1 | 1, mid + 1, t, l, r));
    return ans;
}
/*-------------------------- 线段树 end ------------------*/

// 查询 u 到 v 的路径上的最大边权
int ask(int u, int v) {
    int f1 = top[u], f2 = top[v], tmp = 0;
    // f1 == f2 时, u 和 v 在同一条重链上
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
        tmp = max(tmp, query(1, 1, n, dfn[f1], dfn[u]));
        u = fa[f1], f1 = top[u];
    }
    if (u == v) return tmp;
    // 现在 u, v 在同一条重链上了
    if (dep[u] > dep[v]) swap(u, v);
    // 如果是点权, 把 son[u] 改成 u
    return max(tmp, query(1, 1, n, dfn[son[u]], dfn[v]));
}

int b[N][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, x, y, w;
    cin >> T;
    while (T--) {
        cin >> n;
        init();  // 千万不要忘记 init()
        for (int i = 1; i < n; i++) {
            cin >> x >> y >> w;
            add_edge(x, y, w);
            add_edge(y, x, w);
            b[i][0] = x, b[i][1] = y, b[i][2] = w;
        }
        dfs1(1, -1, 0);  // dfs1(根节点, -1, 0)
        dfs2(1, 1);      // dfs2(根节点, 根节点)
        init(1, 1, n);   // 初始化线段树
        for (int i = 1; i < n; i++) {
            if (dep[b[i][0]] > dep[b[i][1]]) {
                swap(b[i][0], b[i][1]);
            }
            // 每个节点与自己的父节点对应边
            update(1, 1, n, dfn[b[i][1]], b[i][2]);
        }

        string cmd;
        while (cin >> cmd) {
            if (cmd[0] == 'D') break;
            cin >> x >> y;
            if (cmd[0] == 'C') update(1, 1, n, dfn[b[x][1]], y);
            else {
                cout << ask(x, y) << '\n';
            }
        }
    }
    return 0;
}