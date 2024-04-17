#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 100010, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int e;
int head[N], pnt[M], nxt[M];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v) {
    pnt[e] = v;
    nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

int a[N];
int Q[N][110];
void spfa(int n, int c) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        Q[i][c] = INF;
        if (a[i] == c) Q[i][c] = 0, q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(), w = Q[u][c];
        q.pop();
        repe (i, u) {
            int v = pnt[i], t = w + 1;
            if (t < Q[v][c]) {
                Q[v][c] = t;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, s, x, y;
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init();
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    for (int i = 1; i <= k; i++) spfa(n, i);
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        sort(Q[i] + 1, Q[i] + k + 1);
        for (int j = 1; j <= s; j++) ans += Q[i][j];
        cout << ans << ' ';
    }
    return 0;
}