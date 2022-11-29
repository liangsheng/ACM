#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 55;

int n, m;
double p;
double dp[N][N], powa[N], powb[N], c[N][N];

void init() {
    int i, j;
    powa[0] = powb[0] = 1.0;
    for (i = 1; i <= n; i++) {
        powa[i] = powa[i - 1] * p;
        powb[i] = powb[i - 1] * (1.0 - p);
    }
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++) dp[i][j] = -1;
    c[0][0] = 1;
    for (i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}

double dfs(int u, int v) {
    int i, j;
    double k;
    if (u >= m && v >= m) return 0.0;
    if (dp[u][v] != -1) return dp[u][v];
    dp[u][v] = 1.0;
    for (i = 0; i <= n - u; i++) {
        for (j = 0; j <= n - v; j++) {
            if (i == 0 && j == 0) continue;
            dp[u][v] += c[n - u][i] * powa[i] * powb[n - u - i] * c[n - v][j] * powa[j] * powb[n - v - j] * dfs(u + i, v + j);
        }
    }
    k = powb[n - u] * powb[n - v];
    dp[u][v] /= 1.0 - k;
    return dp[u][v];
}

int main() {
    int i, j, u, v;
    while (scanf("%d%d%lf", &n, &m, &p) != EOF) {
        if (n == 0 && m == 0) break;
        init();
        dfs(0, 0);
        printf("%.6lf\n", dp[0][0]);
    }
    return 0;
}
