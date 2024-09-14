#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 100005, M = 200005 * 2;
const int INF = numeric_limits<int>::max() / 2;

template <typename T>
struct Graph {
    int n, m, e;
    vector<int> head, pnt, nxt, wv;
    vector<T> d;    // d[i] 表示起点到 i 的最短距离
    vector<int> c;  // c[i] 表示从起点 s 到 i 的最短路中点的个数

    Graph(int N, int M): n(N), m(M) {
        e = 0;
        head.resize(n + 1, -1), pnt.resize(m, 0);
        wv.resize(m, 0), nxt.resize(m, 0);
        d.resize(n + 1), c.assign(n + 1, 0);
    }

    void add_edge(int u, int v, int w) {
        pnt[e] = v, wv[e] = w;
        nxt[e] = head[u], head[u] = e++;
    }

    /*------------- 堆优化 spfa 最短路 O(nlog(m)) begin ---------*/

    void spfa_heap(int s) {
        for (int i = 1; i <= n; i++) d[i] = INF, c[i] = 0;
        priority_queue<pair<T, int>> q;
        q.push({-(d[s] = 0), s}), c[s] = 1;
        while (!q.empty()) {
            auto [w, u] = q.top();
            q.pop();
            if (d[u] != -w) continue;
            if (c[u] >= n + 1) d[u] = -INF;  // 如果有负环, 直接 d[u] = -INF;
            repe (i, u) {
                int v = pnt[i];
                if (c[v] > n) continue ;  // 某个点的最短路中点的个数超过 n, 说明有点重复, 那么有负环
                T tmp = d[u] + wv[i];
                if (tmp < d[v]) {
                    c[v] = c[u] + 1;
                    q.push({-(d[v] = tmp), v});
                }
            }
        }
    }
    /*------------- 堆优化 spfa 最短路 O(nlog(m)) end -----------*/
};

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t, u, v, w;
    cin >> n >> m >> s;
    Graph<int> G(n, m * 2);  // add_edge() 前一定要 init()
    while (m--) {
        cin >> u >> v >> w;
        G.add_edge(u, v, w);  // 有向图只添加 1 条边
        // G.add_edge(v, u, w);  // 无向图要添加 2 条边
    }
    G.spfa_heap(s);
    for (int i = 1; i <= n; i++) cout << G.d[i] << " \n"[i == n];
    return 0;
}