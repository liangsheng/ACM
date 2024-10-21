#include <bits/stdc++.h>
using namespace std;

// 求树的重心
// oiwiki: https://oiwiki.org/graph/tree-centroid/
// 树的重心性质:
// 1、树的重心如果不唯一，则至多有两个，且这两个重心相邻
// 2、以树的重心为根时，所有子树的大小都不超过整棵树大小的一半(思考下为什么？)
// 3、所有子树大小都不超过整棵树一半的节点，必然是重心(思考下为什么？)
// 4、树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么到它们的距离和一样
// 5、把两棵树通过一条边相连得到一棵新的树，那么新的树的重心在连接原来两棵树的重心的路径上
// 6、在一棵树上添加或删除一个叶子，那么它的重心最多只移动一条边的距离
// 以上性质的证明: https://zhuanlan.zhihu.com/p/357938161
struct Graph {
    int n, e;                     // n: 点的个数
    vector<int> head, pnt, nxt;   // 用链式前向星存树     
    vector<int> c;                // c[i] 表示以 i 为根的子树的节点数
    vector<int> w;                // w[i] 表示以 i 为根时, 最大的子树的节点数
    vector<int> centroid;         // 用来存储重心的序号, 重心最多 2 个

    Graph(int n_) {
        n = n_, e = 0;

        head.assign(n + 1, -1);
        pnt.assign(n * 2, 0);
        nxt.assign(n * 2, 0);

        // 注意这里是从 0 开始还是从 1 开始
        c.assign(n + 1, 0);
        w.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        pnt[e] = v, nxt[e] = head[u], head[u] = e++;
    }

    void dfs(int u, int fa) {
        c[u] = 1, w[u] = 0;
        for (int i = head[u]; i != -1; i = nxt[i]) {
            int v = pnt[i];
            if (v == fa) continue;
            dfs(v, u);
            c[u] += c[v];
            w[u] = max(w[u], c[v]);
        }
        w[u] = max(w[u], n - c[u]);                // 来自 u 的父亲
        if (w[u] * 2 <= n) centroid.push_back(u);  // 思考下为什么
    }

    void get_centroid() {
        dfs(1, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, u, v;
    cin >> n;
    
    Graph G(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        G.add_edge(u, v);
        G.add_edge(v, u);
    }
    G.get_centroid();
    cout << G.centroid.size() << ' ' << G.w[G.centroid[0]] << '\n';
    return 0;
}