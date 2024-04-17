#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 10005, M = 50005, K = 11;
const int INF = numeric_limits<int>::max() / 2;

int d[N][K];

template <typename T>
struct Graph {
    int n, m, e;
    vector<int> head, pnt, nxt, wv;

    Graph(int N, int M): n(N), m(M) {
        e = 0;
        head.resize(n + 1, -1), pnt.resize(m, 0);
        wv.resize(m, 0), nxt.resize(m, 0);
    }

    void add_edge(int u, int v, int w) {
        pnt[e] = v, wv[e] = w;
        nxt[e] = head[u], head[u] = e++;
    }

    /*------------- 堆优化 spfa 最短路 O(nlog(m)) begin ---------*/

    void spfa_heap(int s, int k) {
        for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) d[i][j] = INF;
        priority_queue<tuple<T, int, int>> q;
        for (int j = 0; j <= k; j++) q.push({-(d[s][j] = 0), s, j});
        while (!q.empty()) {
            auto [w, u, c] = q.top();
            q.pop();
            if (d[u][c] != -w) continue;
            // cout << "u= " << u << ", c= " << c << " " << d[u][c] << '\n';
            repe (i, u) {
                int v = pnt[i];
                T tmp = d[u][c] + wv[i];
                if (tmp < d[v][c]) q.push({-(d[v][c] = tmp), v, c});
                if (c + 1 <= k && d[u][c] < d[v][c + 1]) q.push({-(d[v][c + 1] = d[u][c]), v, c + 1});
            }
        }
    }

    /*------------- 堆优化 spfa 最短路 O(nlog(m)) end -----------*/
};

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, s, t, u, v, w;
    cin >> n >> m >> k;
    cin >> s >> t; s++, t++;
    Graph<int> G(n, 2 * m);
    while (m--) {
        cin >> u >> v >> w; u++, v++;
        G.add_edge(u, v, w);  // 有向图只添加 1 条边
        G.add_edge(v, u, w);  // 无向图要添加 2 条边
    }
    G.spfa_heap(s, k);
    cout << d[t][k] << '\n';
    return 0;
}