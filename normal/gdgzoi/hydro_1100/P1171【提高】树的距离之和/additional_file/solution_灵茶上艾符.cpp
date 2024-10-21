#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n); // g[x] 表示 x 的所有邻居
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> ans(n);
        vector<int> size(n, 1); // 注意这里初始化成 1 了，下面只需要累加儿子的子树大小
        function<void(int, int, int)> dfs = [&](int x, int fa, int depth) {
            ans[0] += depth; // depth 为 0 到 x 的距离
            for (int y: g[x]) { // 遍历 x 的邻居 y
                if (y != fa) { // 避免访问父节点
                    dfs(y, x, depth + 1); // x 是 y 的父节点
                    size[x] += size[y]; // 累加 x 的儿子 y 的子树大小
                }
            }
        };
        dfs(0, -1, 0); // 0 没有父节点

        function<void(int, int)> reroot = [&](int x, int fa) {
            for (int y: g[x]) { // 遍历 x 的邻居 y
                if (y != fa) { // 避免访问父节点
                    ans[y] = ans[x] + n - 2 * size[y];
                    reroot(y, x); // x 是 y 的父节点
                }
            }
        };
        reroot(0, -1); // 0 没有父节点
        return ans;
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