#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 20005, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, e, cnt;
int head[N], pnt[M], nxt[M];

void init() {
    e = 0, cnt = 0;  // cnt 存储的是树的重心的个数, 重心存储在 cent[] 中
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

/*-------------------------- 求树的重心 begin -------------*/
// https://oiwiki.com/graph/tree-centroid/
// 树的重心的性质:
// 1、树的重心如果不唯一，则至多有两个，且这两个重心相邻。
// 2、以树的重心为根时，所有子树的大小都不超过整棵树大小的一半。
// 3、树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么到它们的距离和一样。
// 4、把两棵树通过一条边相连得到一棵新的树，那么新的树的重心在连接原来两棵树的重心的路径上。
// 5、在一棵树上添加或删除一个叶子，那么它的重心最多只移动一条边的距离。

int root;     // 求出的树的重心, 记住每次求重心前将 root = -1;
int sz[N];    // 这个节点的「大小」（所有子树上节点数 + 该节点）
int w[N];     // 这个节点的「重量」，即所有子树「大小」的最大值
int cent[2];  // 树的重心, 最多 2 个, 个数是 cnt

void get_centroid(int u, int fa, int n) {
    sz[u] = 1, w[u] = 0;
    repe (i, u) if (pnt[i] != fa) {
        int v = pnt[i];
        get_centroid(v, u, n);
        sz[u] += sz[v];
        w[u] = max(w[u], sz[v]);  // 找出子树种节点数最多的
    }
    w[u] = max(w[u], n - sz[u]);  // 和来自父节点的子树比较
    if (root == -1 || w[u] < w[root] || (w[u] == w[root] && u < root)) root = u;
    // if (w[u] <= n / 2) cent[cnt++] = u;  // 如果想求出所有重心(最多 2 个), 可以用这句话
    
}
/*-------------------------- 求树的重心 end ---------------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int T, x, y;
    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            add_edge(x, y);
            add_edge(y, x);
        }
        // get_centroid(1, -1, n);
        // if (cnt == 2 && cent[0] > cent[1]) swap(cent[0], cent[1]);
        // cout << cent[0] << ' ' << w[cent[0]] << '\n';
        
        root = -1;               // 求重心前记得设置 root = -1;
        get_centroid(1, -1, n);  // 求整个树的重心, 结果放在 root, n 是子树大小
        cout << root << " " << w[root] << '\n';
    }
    return 0; 
}