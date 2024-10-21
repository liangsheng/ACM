#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

struct Graph {
    int n, e;                     // n: 点的个数
    vector<int> head, pnt, nxt;   // 用链式前向星存树  
    vector<int> c;                // d[i] 表示以 i 为根节点的子树的节点数
    vector<int> d;                // d[i] 表示以 i 为根节点的子树到 i 的距离和   
    vector<int> dp;               // dp[i] 表示所有点到 i 的距离和 

    Graph(int n_) {
        n = n_, e = 0;
        head.assign(n + 1, -1);
        pnt.assign(n * 2, 0);
        nxt.assign(n * 2, 0);

        c.assign(n + 1, 0);
        d.assign(n + 1, 0);
        dp.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        pnt[e] = v, nxt[e] = head[u], head[u] = e++;
    }

    void dfs(int u, int fa) {
        c[u] = 1, d[u] = 0;
        repe (i, u) if (pnt[i] != fa) {
            int v = pnt[i];
            dfs(v, u);
            c[u] += c[v];
            d[u] += d[v] + c[v];
        }
    }
    
    void gao(int u, int fa, int pre) {
        dp[u] = d[u] + pre;
        repe (i, u) if (pnt[i] != fa) {
            int v = pnt[i];
            gao(v, u, dp[u] - d[v] + n - 2 * c[v]);
        }
    }

    void solve() {
        dfs(1, 0);
        gao(1, 0, 0);
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
    G.solve();
    for (int i = 1; i <= n; i++) cout << G.dp[i] << " \n"[i == n];
    return 0;
}