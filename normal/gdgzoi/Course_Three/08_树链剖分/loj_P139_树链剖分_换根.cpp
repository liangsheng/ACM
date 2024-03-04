#include <bits/stdc++.h>
#define sc1(x) cout << #x << "= " << x << '\n'
#define sc2(x, y) cout << #x << "= " << x << ", " << #y << "= " << y << '\n'
#define sc3(x, y, z) cout << #x << "= " << x << ", " << #y << "= " << y << ", " << #z << "= " << z << '\n'
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n) for (int i = 1; i <= n; i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

const int N = 100005, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*
 * loj_P139: https://loj.ac/p/139
 * 题意: 给你一棵带点权树, 可以修改点权, 可以换根, 询问 2 点之间的路劲或子树的权值和
 */

/*-------------------------- 邻接表存储 begin -------------*/
int n, e, cnt;
int head[N], pnt[M], nxt[M], wv[M];

void init(int n) {
    e = 0, cnt = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
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

// 查询 u 到 v 的路径上的最后 1 个点(不含 v), 满足 lca(u, v) = v, dep[u] > dep[v]
int first_p(int u, int v) {
    while (top[u] != top[v]) {
        if (fa[top[u]] == v) return top[u];
        u = fa[top[u]];
    }
    return son[v];
}

/*-------------------------- 树链剖分 end -----------------*/

/*-------------------------- 线段树 begin ----------------*/
LL a[N << 2], b[N << 2];

void push_up(int k) {
    a[k] = a[k << 1] + a[k << 1 | 1];
}

void push_down(int k, int s, int t) {
    if (b[k] == 0) return ;
    int l = k << 1, r = l + 1, mid = (s + t) / 2;
    int sl = mid - s + 1, sr = t - mid;
    a[l] = a[l] + sl * b[k];
    a[r] = a[r] + sr * b[k];
    b[l] += b[k], b[r] += b[k];
    b[k] = 0;
}

// 初始化线段树
void init(int k, int s, int t, vector<int>& A) {
    if (s == t) {
        a[k] = A[rnk[s]], b[k] = 0;  // 这里不要写成 a[k] = A[s]; !!! 
        return ;
    }
    int mid = (s + t) >> 1;
    init(k << 1, s, mid, A);
    init(k << 1 | 1, mid + 1, t, A);
    // 这里可以写自己的初始化逻辑, 这里是求和
    push_up(k);
}

// 单点更新
void update(int k, int s, int t, int x, int val) {
    if (x < s || x > t) return;
    if (s == t) {
        a[k] = val;
        return;
    }
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    if (x <= mid) update(k << 1, s, mid, x, val);
    else update(k << 1 | 1, mid + 1, t, x, val);
    push_up(k);
}

// 区间更新
void update(int k, int s, int t, int l, int r, int val) {
    if (t < l || s > r) return;
    if (s >= l && t <= r) {
        a[k] = a[k] + (t - s + 1) * val;
        b[k] += val;
        return;
    }
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    update(k << 1, s, mid, l, r, val);
    update(k << 1 | 1, mid + 1, t, l, r, val);
    push_up(k);
}

// 区间查询
LL query(int k, int s, int t, int l, int r) {
    if (s > r || t < l) return 0;
    if (s >= l && t <= r) return a[k];
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    LL ans = query(k << 1, s, mid, l, r);
    ans = ans + query(k << 1 | 1, mid + 1, t, l, r);
    return ans;
}
/*-------------------------- 线段树 end ------------------*/

// 查询 u 到 v 的路径上的点权和
LL ask_path(int u, int v) {
    LL ans = 0;
    // top[u] == top[v] 时, u 和 v 在同一条重链上
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans = ans + query(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    // 现在 u, v 在同一条重链上了
    if (dep[u] > dep[v]) swap(u, v);
    return ans + query(1, 1, n, dfn[u], dfn[v]);
}

// 将 u 到 v 的路径上的点权加 w
void update_path(int u, int v, int w) {
    // top[u] == top[v] 时, u 和 v 在同一条重链上
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(1, 1, n, dfn[top[u]], dfn[u], w);
        u = fa[top[u]];
    }
    // 现在 u, v 在同一条重链上了
    if (dep[u] > dep[v]) swap(u, v);
    update(1, 1, n, dfn[u], dfn[v], w);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int q, r, nr, x, y, z;
    while (cin >> n) {
        init(n);  // 千万不要忘记 init()
        vector<int> A(n + 1);
        for (int i= 1; i <= n; i++) cin >> A[i];
        for (int i = 2; i <= n; i++) {
            cin >> y;
            add_edge(i, y);
            add_edge(y, i);
        }

        r = 1, nr = r;     // 原来的根是 1
        dfs1(r, -1, 0);    // dfs1(根节点, -1, 0)
        dfs2(r, r);        // dfs2(根节点, 根节点)
        init(1, 1, n, A);  // 初始化线段树

        cin >> q;
        int cmd;
        while (q--) {
            cin >> cmd;
            if (cmd == 1) {         // 以 x 为新的根
                cin >> nr;
            } if (cmd == 2) {       // 表示将树从 x 到 y 结点最短路径上所有节点的值都加上 z
                cin >> x >> y >> z;
                update_path(x, y, z);
            } else if (cmd == 4) {  // 表示求树从 x 到 y 结点最短路径上所有节点的值之和
                cin >> x >> y;
                cout << ask_path(x, y) << '\n';
            } else if (cmd == 3) {  // 表示将以 x 为根节点的子树内所有节点值都加上 z
                cin >> x >> z;
                if (x == nr) {
                    update(1, 1, n, dfn[r], dfn[r] + sz[r] - 1, z);
                } else if (dfn[nr] > dfn[x] && dfn[nr] <= dfn[x] + sz[x] - 1) {  
                     // x 在 nr 到 r 的路径上, 需要处理
                    y = first_p(nr, x);

                    // 先把整颗树 +z
                    update(1, 1, n, dfn[r], dfn[r] + sz[r] - 1, z);

                    // 再把多余的部分做减法, 自己画一画
                    update(1, 1, n, dfn[y], dfn[y] + sz[y] - 1, -z);                   
                } else {
                    // x 不在 nr 到 r 的路径上, 不需要处理
                    update(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, z);
                }
            } else if (cmd == 5) {  // 表示求以 x 为根节点的子树内所有节点值之和
                cin >> x;
                if (x == nr) {
                    cout << query(1, 1, n, dfn[r], dfn[r] + sz[r] - 1) << '\n';
                } else if (dfn[nr] > dfn[x] && dfn[nr] <= dfn[x] + sz[x] - 1) {
                    // x 在 nr 到 r 的路径上, 需要处理
                    y = first_p(nr, x);

                    // 先计算整颗树
                    LL ans = query(1, 1, n, dfn[r], dfn[r] + sz[r] - 1);

                    // 再把多余的部分做减法, 自己画一画
                    ans -= query(1, 1, n, dfn[y], dfn[y] + sz[y] - 1);
                    cout << ans << '\n';
                } else {
                    // x 不在 nr 到 r 的路径上, 不需要处理
                    cout << query(1, 1, n, dfn[x], dfn[x] + sz[x] - 1) << '\n';
                }
            }
        }
    }
    return 0;
}