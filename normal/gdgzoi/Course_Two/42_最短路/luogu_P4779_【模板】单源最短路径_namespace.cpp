#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 100005, M = 200005 * 2;
const int INF = numeric_limits<int>::max() / 2;

namespace Graph {
    /*-------------------------- 邻接表存储 begin -------------*/
    int n, e;
    int head[N], pnt[M], nxt[M], wv[M];

    void init(int N) {
        n = N, e = 0;
        // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
        fill(head, head + n + 1, -1);
    }

    void add_edge(int u, int v, int w) {
        pnt[e] = v, wv[e] = w;
        nxt[e] = head[u], head[u] = e++;
    }
    /*-------------------------- 邻接表存储 end ---------------*/

    /*------------- 堆优化 spfa 最短路 O(nlog(m)) begin ---------*/

    int d[N];  // d[i] 表示从起点 s 到 i 的最短距离

    void spfa_heap(int s) {
        for (int i = 1; i <= n; i++) d[i] = INF;
        priority_queue<pii> q;
        q.push({-(d[s] = 0), s});  // 由于要找最小, 所以插入负数
        while (!q.empty()) {

            // 每轮都从 f[i] == 0 的点中, 找到 d[i] 最小的点
            auto [w, p] = q.top();
            q.pop();
            if (d[p] != -w) continue;  // d[p] != w 是已经计算最短路的点

            repe (i, p) {
                int v = pnt[i], tmp = d[p] + wv[i];
                if (tmp < d[v]) q.push({-(d[v] = tmp), v});
            }
        }
    }
    /*------------- 堆优化 spfa 最短路 O(nlog(m)) end -----------*/
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t, u, v, w;
    cin >> n >> m >> s;
    Graph::init(n);  // add_edge() 前一定要 init()
    while (m--) {
        cin >> u >> v >> w;
        Graph::add_edge(u, v, w);  // 有向图只添加 1 条边
        // Graph::add_edge(v, u, w);  // 无向图要添加 2 条边
    }
    Graph::spfa_heap(s);
    for (int i = 1; i <= n; i++) cout << Graph::d[i] << " \n"[i == n];
    return 0;
}