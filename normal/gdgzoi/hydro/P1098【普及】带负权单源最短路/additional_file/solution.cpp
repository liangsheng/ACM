#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 100005, M = 200005 * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, m, s, t, e;
int head[N], pnt[M], nxt[M], wv[M];

void init() {
    e = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w;
    nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

/*------------- 堆优化 spfa 最短路 O(nlog(m)) begin -------*/

int d[N];  // d[i] 表示从起点 s 到 i 的最短距离
int c[N];  // c[i] 表示从起点 s 到 i 的最短路中点的个数

bool spfa_heap(int s) {
    priority_queue<pii> q;
    for (int i = 1; i <= n; i++) d[i] = INF, c[i] = 0;
    c[s] = 1, d[s] = 0, q.push({-d[s], s});  // 每次取最小的, 所以插入的时候取负
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (d[u] != -w) continue;
        if (c[u] > n) return true;  // 某个点的最短路中点的个数超过 n, 说明有点重复, 那么有负环
        // cout << "u= " << u << ", d[u]= " << d[u] << ", c[u]= " << c[u] << '\n';
        repe (i, u) {
            int v = pnt[i], tmp = d[u] + wv[i];
            if (tmp < d[v]) {
                c[v] = c[u] + 1;
                q.push({-(d[v] = tmp), v});
            }
        }
    }
    return false;
}
/*------------- 堆优化 spfa 最短路 O(nlog(m)) end --------*/

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, t, u, v, w;
    cin >> n >> m >> s >> t;
    init();  // add_edge() 前一定要 init()
    while (m--) {
        cin >> u >> v >> w;
        add_edge(u, v, w);  // 有向图只添加 1 条边
        // add_edge(v, u, w);  // 本题是有向图
    }
    bool has_circle = spfa_heap(s);
    if (has_circle) cout << "-INF" << '\n';
    else cout << d[t] << '\n';
    return 0;
}