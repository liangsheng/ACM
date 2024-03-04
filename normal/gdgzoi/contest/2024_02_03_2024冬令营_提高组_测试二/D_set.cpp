#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

const int N = 100005, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, e, cnt;
int head[N], pnt[M], nxt[M];
LL wv[M], dis[N];

void init() {
    e = 0, cnt = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v, LL w) {
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
        dis[v] = dis[u] + wv[i];
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

LL get_dis(int u, int v) {
    int p = lca(u, v);
    return dis[u] + dis[v] - 2 * dis[p];
}

/*-------------------------- 树链剖分 end -----------------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int x, y, root = 1;
    LL w;
    cin >> n;
    init();  // 千万不要忘记 init()
    for (int i = 1; i < n; i++) {
        cin >> x >> y >> w;
        add_edge(x, y, w);
        add_edge(y, x, w);
    }
    dis[1] = 0;
    dfs1(root, -1, 0);  // dfs1(根节点, -1, 0)
    dfs2(root, root);      // dfs2(根节点, 根节点)
    // for (int i = 1; i <= n; i++) printf("i= %d, dfn= %d\n", i, dfn[i]);

    set<int> s;
    auto get_nxt = [&](int x) {
        auto it = s.upper_bound(dfn[x]);
        return (it == s.end() ? *s.begin() : *it);
    };
    auto get_pre = [&](int x) {
        auto it = s.lower_bound(dfn[x]);
        return (it == s.begin() ? *s.rbegin() : *(--it));
    };

    LL m, ans = 0;
    cin >> m;
    string cmd;
    while (m--) {
        cin >> cmd;
        if (cmd == "?") cout << ans / 2 << '\n';
        else if (cmd == "+") {
            cin >> x;
            s.insert(dfn[x]);
            int p = rnk[get_pre(x)], q = rnk[get_nxt(x)];
            // printf("x= %d, p= %d, q= %d\n", x, p, q);
            ans += get_dis(p, x) + get_dis(x, q) - get_dis(p, q);
        } else if (cmd == "-") {
            cin >> x;
            int p = rnk[get_pre(x)], q = rnk[get_nxt(x)];
            ans += get_dis(p, q) - get_dis(p, x) - get_dis(x, q);
            s.erase(dfn[x]);
        }
    }
    return 0;
}
