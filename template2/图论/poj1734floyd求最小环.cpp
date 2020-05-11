#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int ch;

const int N = 110, INF = 100000000;

int n, m, num;
int g[N][N], dis[N][N], f[N][N], res[N];

void dfs(int i, int j) {
    int k = f[i][j];
    if (k == 0)
    {
        res[num++] = j;
        return;
    }
    dfs(i, k);
    dfs(k, j);
}

int main() {
    int i, j, k, mini, u, v, w;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++)
                g[i][j] = g[j][i] = dis[i][j] = dis[j][i] = INF;
            g[i][i] = dis[i][i] = 0;
        }
        for (i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if (w < g[u][v]) {
                g[u][v] = g[v][u] = w;
                dis[u][v] = dis[v][u] = w;
            }
        }
        mini = INF;
        memset(f, 0, sizeof(f));
        for (k = 1; k <= n; k++) {
            for (i = 1; i < k; i++)
                for (j = i + 1; j < k; j++) {
                    if (dis[i][j] + g[i][k] + g[k][j] < mini) {
                        mini = dis[i][j] + g[i][k] + g[k][j];
                        num = 0;
                        res[num++] = i;
                        dfs(i, j);
                        res[num++] = k;
                    }
                }
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        f[i][j] = k;
                    }
        }
        if (mini == INF) puts("No solution.");
        else for(i = 0; i < num; i++) printf("%d%c", res[i], i == num - 1 ? '\n' : ' ');
    }
    return 0;
}
