#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))

using namespace std;
int chh;

const int N = 305, MOD = 10007;

int T, n, m;
int x[N], y[N], vis[N];
int g[N][N];

void bfs() {
    int i, v;
    queue<int> q;
    fill(vis, vis + n, 0);
    q.push(0), vis[0] = 1;
    while (! q.empty()) {
        v = q.front(), q.pop();
        for (i = 0; i < n; i++) {
            if (!g[v][i] || vis[i]) continue;
            vis[i] = 1, q.push(i);
        }
    }
}

int det(int n) {
    int i, j, k, row, col, tmp = 1, flag = 0, res;
    for (col = 0; col < n; col++) {
        row = col;
        for (i = row; i < n; i++)
            if (g[i][col] != 0) break;
        if (i != row) {
            for (j = col; j < n; j++) swap(g[i][j], g[row][j]);
            flag ^= 1;
        }
        for (i = row + 1; i < n; i++) {
            if (g[i][col] == 0) continue;
            tmp = tmp * g[row][col] % MOD;
            for (j = col + 1; j < n; j++) {
                g[i][j] = (g[i][j] * g[row][col] - g[row][j] * g[i][col]);
                g[i][j] = (g[i][j] + MOD * MOD * 2) % MOD;
            }
        }
    }
    for (res = 1; res < MOD; res++) {
        if ((tmp * res % MOD) == 1) break;
    }
    for (i = 0; i < n; i++) res = res * g[i][i] % MOD;
    if (flag) res = MOD - res;
    return res;
}

int main() {
    int i, j, k, ans;
    bool f;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
        memset(g, 0, sizeof(g));
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (sqr(x[i] - x[j]) + sqr(y[i] - y[j]) > m * m) continue;
                f = 1;
                for (k = 0; k < n && f; k++) {
                    if (k == i || k == j) continue;
                    if (x[k] < min(x[i], x[j]) || x[k] > max(x[i], x[j])) continue;
                    if ((x[k] - x[i]) * (y[j] - y[i]) == (y[k] - y[i]) * (x[j] - x[i])) f = 0;
                }
                if (f) g[i][j] = g[j][i] = 1;
            }
        }
        bfs();
        f = 1;
        for (i = 0; i < n && f; i++) {
            if (! vis[i]) f = 0;
        }
        if (! f) {
            puts("-1");
            continue;
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (g[i][j]) {
                    g[i][i]++, g[j][j]++;
                    g[i][j] = g[j][i] = MOD - 1;
                }
            }
        }
        ans = det(n - 1);
        printf("%d\n", ans);
    }
    return 0;
}
