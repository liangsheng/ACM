#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 10005, M = 50005, K = 11;
const int INF = numeric_limits<int>::max() / 2;

template <typename T>
struct Graph {
    int n, m, e;
    vector<int> head, pnt, nxt, wv;
    vector<T> d;    // d[i] 表示起点到 i 的最短距离
    vector<int> c;  // c[i] 表示起点到 i 的最短距离经过的点的个数

    Graph(int N, int M): n(N), m(M) {
        e = 0;
        head.resize(n + 1, -1), pnt.resize(m, 0);
        wv.resize(m, 0), nxt.resize(m, 0);
        d.resize(n + 1), c.resize(n + 1);
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
            // auto [w, u] = q.top();
            T w = q.top().first;
            int u = q.top().second;
            q.pop();
            if (d[u] != -w) continue;
            if (c[u] >= n + 1) d[u] = -INF;  // 如果有负环, 直接 d[u] = -INF;
            repe (i, u) {
                int v = pnt[i];
                if (c[v] >= n + 1) continue;  // 这个点已经存在负环了, 不用再更新
                T tmp = d[u] + wv[i];
                if (tmp < d[v]) {
                    d[v] = tmp, c[v] = c[u] + 1;
                    q.push({-d[v], v});
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
    int n, m, u, v, w;
    cin >> n >> m;
    Graph<int> G(n, m);
    int l = 0, r = 0;
    while (m--) {
        cin >> u >> v >> w;
        if (w >= 0) l = min(l, -w);
        else r = max(r, -w);
        G.add_edge(u, v, w);  // 有向图只添加 1 条边
        // G.add_edge(v, u, w);  // 无向图要添加 2 条边
    }
    G.spfa_heap(1);
    if (G.d[n] > 20000000) cout << -1 << '\n';
    else {
        int d = -l;
        // 负数二分, 加一个偏移转成正数二分, 按照之前的写法负数二分会死循环
        l += d, r += d;
        while (l != r) {
            int mid = (l + r) / 2;
            for (int i = 0; i < G.e; i++) G.wv[i] += mid - d;
            G.spfa_heap(1);
            if (G.c[n] > n || G.d[n] < 0) l = mid + 1;
            else r = mid;
            for (int i = 0; i < G.e; i++) G.wv[i] -= mid - d;
        }
        for (int i = 0; i < G.e; i++) G.wv[i] += l - d;
        G.spfa_heap(1);
        cout << G.d[n] << '\n';
    }
    return 0;
}