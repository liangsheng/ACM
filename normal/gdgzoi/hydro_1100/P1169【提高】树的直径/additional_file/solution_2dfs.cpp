#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

using pii = pair<int, int>;

// 求输的直径
// oiwiki: https://oiwiki.org/graph/tree-diameter/
struct Graph {
    int n, e, c;                     // n: 点的个数, c: 距离根节点最远的点
    vector<int> head, pnt, wv, nxt;  // 用链式前向星存树   
    vector<int> d;                   // d[i] 表示根节点到 i 的距离

    Graph(int n_) {
        n = n_, e = 0;

        head.assign(n + 1, -1);
        wv.assign(2 * n, 0);
        pnt.assign(n * 2, 0);
        nxt.assign(n * 2, 0);

        // 注意: 这里是从 1 开始
        d.assign(n + 1, 0);
    }

    void add_edge(int u, int v, int w) {
        pnt[e] = v, wv[e] = w;
        nxt[e] = head[u], head[u] = e++;
    }

    void dfs(int u, int fa) {
        d[u] = d[fa] + 1;

        // 遍历的时候不要访问父亲节点
        repe (i, u) if (pnt[i] != fa) {
            int v = pnt[i];
            dfs(v, u);
        }
        // 记录距离根节点最远的点
        if (c == -1 || d[u] > d[c]) c = u;
    }

    // 两次 dfs 求树的直径
    int diameter() {
        c = -1, d[0] = -1;
        dfs(1, 0);

        // 再以 c 为根节点做一次 dfs
        dfs(c, 0);
        return d[c];
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
        G.add_edge(u, v, 1);
        G.add_edge(v, u, 1);
    }
    cout << G.diameter() << '\n';

    return 0;
}