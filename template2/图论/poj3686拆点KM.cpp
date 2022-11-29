#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N  =  2505,  INF = ~0U >> 1;

int n, m;
int g[N][N];
int x[N], y[N], match[N], lx[N], ly[N];

void init() {
    memset(g, 0, sizeof(g));
    memset(match, -1, sizeof(match));
}

int make() {
    int i, j;
    fill(lx + 1, lx + n + 1, 0);
    fill(ly + 1, ly + n * m + 1, 0);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n * m; j++)
            lx[i] = max(lx[i], g[i][j]);
    }
    return 1;
}

int find(int a) {
    int i;
    x[a] = 1;
    for (i = 1; i <= n * m; i++) {
        if (y[i] == 0 && lx[a] + ly[i] == g[a][i]) {
            y[i] = 1;
            if (match[i] == -1 || find(match[i])) {
                match[i] = a;
                return 1;
            }
        }
    }
    return 0;
}

int Kuhn_Munkers() {
    int i, j, k, d;
    int ans = 0;
    make();
    for (i = 1; i <= n; i++) {
        while (1) {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if (find(i)) break;
            d = INF;
            for (k = 1; k <= n; k++) {
                if (x[k] != 1) continue;
                for (j = 1; j <= n * m; j++) {
                    if (y[j] != 0) continue;
                    d = min(d, lx[k] + ly[j] - g[k][j]);
                }
            }
            if (d == INF) break;
            for (j = 1; j <= n; j++)
                if (x[j] == 1) lx[j] -= d;
            for (j = 1; j <= n * m; j++)
                if (y[j]) ly[j] += d;
        }
    }
    for (i = 1; i <= n * m; i++)
        if (match[i] != -1) ans += g[match[i]][i];
    return ans;
}

int T;

int main() {
    int i, j, k, v;
    double ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        init();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                 scanf("%d", &v);
                 for (k = 1; k <= n; k++) g[i][(j - 1) * n + k] = -v * k;
            }
        }
        ans = -Kuhn_Munkers() * 1.0 / n;
        printf("%.6lf\n", ans);
    }
    return 0;
}
