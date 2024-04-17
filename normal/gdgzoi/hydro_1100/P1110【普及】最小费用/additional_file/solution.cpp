#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;
typedef pair<LL, int> pii;

const int N = 200005, M = 200005 * 4;
const LL INF = numeric_limits<LL>::max() / 2;

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

/*------------- 堆优化 dijkstra最短路 O(nlog(m)) begin ----*/

LL d[N];

void dijkstra_heap(int s) {
    for (int i = 0; i < n; i++) d[i] = INF;
    priority_queue<pii> q;
    q.push({-(d[s] = 0), s});  // 此题求的是最小边权最大
    while (!q.empty()) {

        auto [w, p] = q.top();
        q.pop();
        if (d[p] != -w) continue;  // dp[p] != w 表示 p 已经访问过

        // 用 d[p] 更新其他点的 d[i]
        repe (i, p) {
            int v = pnt[i];
            LL tmp = d[p] + wv[i];
            if (tmp < d[v]) q.push({-(d[v] = tmp), v});
        }
    }
}
/*------------- 堆优化 dijkstra最短路 O(nlog(m)) end ------*/

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> p(2, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> p[0][i] >> p[1][i];

    init();  // add_edge() 前一定要 init()
    for (int k = 0; k < 2; k++) {
        vector<int> c(n);
        for (int i = 0; i < n; i++) c[i] = i;
        sort(c.begin(), c.end(), [&](const int& u, const int& v) {
            return p[k][u] < p[k][v];
        });
        for (int i = 1; i < n; i++) {
            int u = c[i - 1], v = c[i], w = p[k][v] - p[k][u];
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
    }

    dijkstra_heap(0);
    cout << d[n - 1] << '\n';
    return 0;
}