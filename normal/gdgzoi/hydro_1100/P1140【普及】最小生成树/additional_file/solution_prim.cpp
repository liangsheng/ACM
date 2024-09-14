#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 100005, M = 200005 * 2;
const int INF = numeric_limits<int>::max() / 2;

template <typename T>
struct Graph {
    int n, m, e;
    vector<int> head, pnt, nxt;
    vector<T> wv, d;   // d[i] 表示起点到 i 的最短距离
    vector<bool> f;    // f[i] 表示点 i 是否访问过 

    Graph(int N, int M): n(N), m(M) {
        e = 0;
        head.assign(n + 1, -1), pnt.resize(m);
        wv.resize(m), nxt.resize(m);
        d.resize(n + 1), f.resize(n + 1);
    }

    void add_edge(int u, int v, int w) {
        pnt[e] = v, wv[e] = w;
        nxt[e] = head[u], head[u] = e++;
    }

    /*------------- 堆优化 prim 最小生成树 O(nlog(m)) begin ---------*/

    T prim() {
        T ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) d[i] = INF, f[i] = 0;
        priority_queue<pair<T, int>> q;
        q.push({-(d[1] = 0), 1});
        while (!q.empty()) {
            auto [w, u] = q.top();
            q.pop();
            if (f[u]) continue;
            ans += d[u], f[u] = 1, cnt++;
            repe (i, u) {
                int v = pnt[i];
                if (!f[v] && wv[i] < d[v]) q.push({-(d[v] = wv[i]), v});
            }
        }
        return (cnt == n ? ans : -1);
    }
    /*------------- 堆优化 prim 最小生成树 O(nlog(m)) end -----------*/

    T kruskal() {
        
    }
};

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v, w;
    cin >> n >> m;
    Graph<int> G(n, m * 2);  // add_edge() 前一定要 init()
    while (m--) {
        cin >> u >> v >> w;
        G.add_edge(u, v, w);  // 有向图只添加 1 条边
        G.add_edge(v, u, w);  // 无向图要添加 2 条边
    }
    int ans = G.prim();
    if (ans == -1) cout << "orz" << '\n';
    else cout << ans << '\n';
    return 0;
}