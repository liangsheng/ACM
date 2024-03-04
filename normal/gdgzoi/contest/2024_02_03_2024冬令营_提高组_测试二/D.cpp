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
vector<int> q;

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
    q.push_back(u);
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

LL cal_dis(int u, int v) {
    int p = lca(u, v);
    return dis[u] + dis[v] - 2 * dis[p];
}

/*-------------------------- 树链剖分 end -----------------*/

int a[N << 2], b[N << 2];

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
void init(int k, int s, int t) {
    if (s == t) {
        a[k] = 0, b[k] = 0;  // 这里不要写成 a[k] = A[s]; !!! 
        return ;
    }
    int mid = (s + t) >> 1;
    init(k << 1, s, mid);
    init(k << 1 | 1, mid + 1, t);
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
int query(int k, int s, int t, int l, int r) {
    if (s > r || t < l) return 0;
    if (s >= l && t <= r) return a[k];
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    int ans = query(k << 1, s, mid, l, r);
    ans = ans + query(k << 1 | 1, mid + 1, t, l, r);
    return ans;
}
/*-------------------------- 线段树 end ------------------*/

// 计算子树中标记节点的个数
int tol_cnt;
bool ok[N];
int ok_cnt[N];

void cal_cnt() {
    for (int i = n - 1; i >= 0; i--) {
        int u = q[i];
        
        ok_cnt[u] = ok[u];
        repe (j, u) {
            int v = pnt[j];
            if (v == fa[u]) continue;
            ok_cnt[u] += ok_cnt[v];
        }
        // cout << "u= " << u << ", ok_cnt[u]= " << ok_cnt[u] << '\n';
    }
}

int cal_lca() {
    for (int i = n - 1; i >= 0; i--) {
        int u = q[i];
        if (ok_cnt[u] == tol_cnt) return u;
    }
    return 1;
}

LL cal_prim(int rt) {
    LL ans = 0;
    queue<int> q;
    q.push(rt);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        repe (i, u) {
            int v = pnt[i];
            if (v == fa[u]) continue;
            if (ok_cnt[v] > 0) ans += wv[i], q.push(v);
        }
    }
    return ans;
}

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
    // dis[1] = 0;
    dfs1(root, -1, 0);  // dfs1(根节点, -1, 0)
    // dfs2(root, root);      // dfs2(根节点, 根节点)
    // init(1, 1, n);
    // cout << "dis[5]= " << dis[5] << ", dis[6]= " << dis[6] << '\n';

    int m;
    cin >> m;
    string cmd;
    fill(ok, ok + n + 1, 0);
    tol_cnt = 0;
    while (m--) {
        cin >> cmd;
        if (cmd == "?") {
            if (tol_cnt == 0) {
                cout << 0 << '\n';
                continue;
            }
            // cal_cnt();
            int rt = cal_lca();
            cout << cal_prim(rt) << '\n';
            // cout << "rt= " << rt << '\n';
        } else if (cmd == "+") {
            cin >> x;
            ok[x] = 1, tol_cnt++;
            while (x != -1) ok_cnt[x]++, x = fa[x];
        } else if (cmd == "-") {
            cin >> x;
            ok[x] = 0, tol_cnt--;
            while (x != -1) ok_cnt[x]--, x = fa[x];
        }
        // for (int i = 1; i <= n; i++) cout << "i= " << i << ", cnt= " << ok_cnt[i] << '\n';
    }
    return 0;
}

