#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 20005, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*
 * 小视野_课程三_9_树分治_B_聪聪可可: http://gdgzoi.com/problem.php?cid=2240&pid=1
 * 题意: 给定一棵有 n 个点带边权的树，问有多少条路径的长度是 3 的倍数
 */

/*-------------------------- 邻接表存储 begin -------------*/
int n, e;
int head[N], pnt[M], nxt[M], wv[M];

void init() {
    e = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w;
    nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

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

int ans;
int dp[N][3];

void cal(int u, int fa, int dis) {
    memset(dp[u], 0, sizeof(dp[u]));
    dp[u][dis % 3]++;
    sz[u] = 1;  // 注意: 重新计算 sz, get_centroid() 中计算的 sz 不是以重心为根节点的
    repe (i, u) {
        int v = pnt[i];
        if (v == fa || vis[v]) continue;
        cal(v, u, (dis + wv[i]) % 3);
        sz[u] += sz[v];
        for (int j = 0; j < 3; j++) dp[u][j] += dp[v][j];
    }
}

// 解决以 u 为重心的子树的问题, 然后分治下去
void solve(int u, int fa) {
    vis[u] = 1;
    memset(dp[u], 0, sizeof(dp[u]));
    repe (i, u) {
        int v = pnt[i];
        if (v == fa || vis[v]) continue;  
        cal(v, u, wv[i] % 3);
        ans += dp[v][0];
        for (int j = 0; j < 3; j++) ans += dp[v][j] * dp[u][(3 - j) % 3];
        for (int j = 0; j < 3; j++) dp[u][j] += dp[v][j];
    }
    // cout << "u= " << u << ", ans= " << ans << '\n';

    // 分治下去
    repe (i, u) {
        int v = pnt[i];
        if (v == fa || vis[v]) continue;
        root = -1;                  // 找重心前记得 root = -1;
        get_centroid(v, u, sz[v]);  // 先找子树的重心
        solve(root, -1);            // 解决子树问题
    }
}

/*-------------------------- 求树的重心&树分治 end ---------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int x, y, z;
    while (cin >> n) {
        init();  // add_edge 前不要忘记 init()
        for (int i = 1; i < n; i++) {
            cin >> x >> y >> z;
            add_edge(x, y, z % 3);
            add_edge(y, x, z);
        }

        ans = 0;

        /*-------------- 开始分治 ------------------------------------------------*/
        root = -1;                  // 求重心前记得设置 root = -1;
        fill(vis, vis + n + 1, 0);  // 初始化所有节点都没有访问过
        get_centroid(1, -1, n);     // 求整个树的重心, 结果放在 root, n 是子树大小
        solve(root, -1);            // 解决以 root 为重心的子树问题
        /*-------------- 结束分治 ------------------------------------------------*/

        // cout << "ans= " << ans << '\n';

        ans = ans * 2 + n;
        int tol = n * n, d = __gcd(ans, tol);
        cout << ans / d << '/' << tol / d << '\n';
    }
    return 0; 
}