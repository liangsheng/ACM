#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

using pii = pair<int, int>;

// 求输的直径
// oiwiki: https://oiwiki.org/graph/tree-diameter/
struct Graph {
    int n, e, di;                    // n: 点的个数, di: 输的直径
    vector<int> head, pnt, wv, nxt;  // 用链式前向星存树   
    vector<int> d1;                  // d1[i] 表示从 i 开始往下延伸的最长距离
    vector<int> d2;                  // d2[i] 表示从 i 开始往下延伸的次长距离, 和 d1[i] 无公共边

    Graph(int n_) {
        n = n_, e = 0;

        head.assign(n + 1, -1);
        wv.assign(2 * n, 0);
        pnt.assign(n * 2, 0);
        nxt.assign(n * 2, 0);

        // 注意: 这里是从 1 开始
        d1.assign(n + 1, 0);
        d2.assign(n + 1, 0);
    }

    void add_edge(int u, int v, int w) {
        pnt[e] = v, wv[e] = w;
        nxt[e] = head[u], head[u] = e++;
    }

    void dfs(int u, int fa) {
        d1[u] = 0, d2[u] = 0;
        repe (i, u) if (pnt[i] != fa) {
            int v = pnt[i];
            dfs(v, u);
            int t = d1[v] + wv[i];
            if (t > d1[u]) d2[u] = d1[u], d1[u] = t;
            else if (t > d2[u]) d2[u] = t;
        }
        di = max(di, d1[u] + d2[u]);
    }

    // 两次 dfs 求树的直径
    int diameter() {
        di = 0;
        dfs(1, 0);
        return di;
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