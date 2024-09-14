#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long LL;

const int N = 500005, M = 2000005;
const int MOD = 998244353, INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, m, e;
int head[N], pnt[M], nxt[M];

void init() {
    e = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (LL) ans * x % MOD;
        x = (LL) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

/*-------------------------- 求树的重心&树分治 begin -------*/
// https://oiwiki.com/graph/tree-centroid/
// 树的重心的性质:
// 1、树的重心如果不唯一，则至多有两个，且这两个重心相邻。
// 2、以树的重心为根时，所有子树的大小都不超过整棵树大小的一半。
// 3、树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么到它们的距离和一样。
// 4、把两棵树通过一条边相连得到一棵新的树，那么新的树的重心在连接原来两棵树的重心的路径上。
// 5、在一棵树上添加或删除一个叶子，那么它的重心最多只移动一条边的距离。

int sz[N];    // 这个节点的「大小」（所有子树上节点数 + 该节点）
int w[N];     // 这个节点的「重量」，即所有子树「大小」的最大值
int root;     // 求出的树的重心, 记住每次求重心前将 root = -1;
int vis[N];   // vis[i] == 1, 表示 i 在之前的分治过程中已经访问过

// 获取重心存放在 root, 调用前记得 root = -1;
void get_centroid(int u, int fa, int n) {
    sz[u] = 1, w[u] = 0;
    repe (i, u) {
        int v = pnt[i];
        if (v == fa || vis[v]) continue; 
        get_centroid(v, u, n);
        sz[u] += sz[v];
        w[u] = max(w[u], sz[v]);  // 找出子树种节点数最多的
    }
    w[u] = max(w[u], n - sz[u]);  // 和来自父节点的子树比较
    if (root == -1 || w[u] < w[root] || (w[u] == w[root] && u < root)) root = u;
    // if (w[u] <= n / 2) cent[cnt++] = u;  // 如果想求出所有重心(最多 2 个), 可以用这句话

}

int tol;   // 记录 a[] 的大小, 也就是子树中节点的个数, 使用前记得 tol = 0;
int a[N];  // 记录所有节点
int d[N];  // d[i] 表示 i 到重心的距离

// 计算以 u 为重心的子树种的节点到 u 的距离
void cal_dis(int u, int fa, int dis) {
    a[tol++] = u, d[u] = dis;
    sz[u] = 1;  // 注意: 重新计算 sz, get_centroid() 中计算的 sz 不是以重心为根节点的
    repe (i, u) {
        int v = pnt[i];
        if (v == fa || vis[v]) continue;
        cal_dis(v, u, dis + 1);
        sz[u] += sz[v];
    }
}

int res;

// 解决以 u 为重心的子树的问题, 然后分治下去
void solve(int u, int fa) {
    vis[u] = 1;
    tol = 0;
    a[tol++] = u, d[u] = 0;
    int num = 0;
    repe (i, u) {
        int v = pnt[i];
        if (v == fa || vis[v]) continue;  
        num++;
        cal_dis(v, u, 1);
    }
    for (int i = 0; i < tol; i++) {
        int t = d[a[i]] + 1;
        int x = power(2, t);
        int y = power(2, t - 2);
        // res = ((LL) x * y % MOD + res) % MOD;

        // t++;
        // x = power(2, t);
        // y = power(2, t - 2);
        // res = ((LL) x * y % MOD * (num - 1) % MOD + res) % MOD;
    }

    // 分治下去
    // repe (i, u) {
    //     int v = pnt[i];
    //     if (v == fa || vis[v]) continue;
    //     root = -1;                  // 找重心前记得 root = -1;
    //     get_centroid(v, u, sz[v]);  // 先找子树的重心
    //     solve(root, -1);            // 解决子树问题
    // }
}

/*-------------------------- 求树的重心&树分治 end ---------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> n >> m;
    init();
    bool ok = true;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        x--, y--;
        if (x + 1 != y) ok = false;
        add_edge(x, y);
        add_edge(y, x);
    }

    // 一条链
    if (ok) {
        int ans = 1 + 2 * n;
        for (int i = 2; i <= n; i++) {
            int x = power(2, i);
            int y = (LL) (n - i + 1) * power(2, i - 2) % MOD;
            ans = (ans + (LL) x * y % MOD) % MOD;
            // cout << "i= " << i << ", ans= " << ans << '\n';
        }
        cout << ans << '\n';
        return 0;
    }

    // if (n <= 20) {
    //     vector<vector<int>> f(n, vector<int>(n, 0));
    //     function<void(int, int, int)> dfs = [&](int x, int y, int st) {
    //         f[x][y] |= st;
    //         repe (i, y) {
    //             int v = pnt[i];
    //             if (st >> v & 1) continue;
    //             dfs(x, v, st | 1 << v);
    //         }
    //     };

    //     for (int i = 0; i < n; i++) dfs(i, i, 1 << i);
    //     int ans = 1;
    //     for (int st = 1; st < (1 << n); st++) {
    //         int ok = 0;
    //         rep(i, n) if (st >> i & 1) {
    //             rep (j, n) if (j != i && st >> j & 1) {
    //                 ok |= f[i][j];
    //             }
    //         }
    //         int cnt = 0;
    //         rep (i, n) cnt += (ok >> i & 1) | (st >> i & 1);
    //         // cout << "st= " << st << ", cnt= " << cnt << '\n';
    //         ans = ((LL) ans + power(2, cnt)) % MOD;
    //     }
    //     cout << ans << '\n';
    //     return 0;
    // }

    /*-------------- 开始分治 ------------------------------------------------*/
    res = 1 + 2 * n;
    root = -1;                  // 求重心前记得设置 root = -1;
    fill(vis, vis + n + 1, 0);  // 初始化所有节点都没有访问过
    get_centroid(0, -1, n);     // 求整个树的重心, 结果放在 root, n 是子树大小
    solve(root, -1);            // 解决以 root 为重心的子树问题
    cout << res << '\n';
    /*-------------- 结束分治 ------------------------------------------------*/
    return 0;
}