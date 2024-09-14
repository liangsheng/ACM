#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

const int N = 500005, M = 500005 * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, m, e;
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

bool f[505][505];

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, x, y;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = (s[i - 1] == '(' ? 1 : -1);
    init();
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add_edge(x, y, 1);
        add_edge(y, x, 1);
    }
    
    auto ok = [&](int x, int y) {
        if (a[x] == -1) return false;
        for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) f[i][j] = 0;
        queue<pair<int, int>> q;
        q.push({x, 1}), f[x][1] = 1;
        // int cnt = 0;
        while (!q.empty()) {
            auto [u, d] = q.front();
            if (u == y && d == 0) return true;
            q.pop();
            repe (i, u) {
                int v = pnt[i], t = d + a[v];
                if (t < 0 || t > n || f[v][t]) continue;
                q.push({v, t}), f[v][t] = 1;
            }
        }
        return f[y][0];
    };

    while (q--) {
        cin >> x >> y;
        cout << (ok(x, y) ? 1 : 0);
    }
    cout << '\n';
    return 0;
}