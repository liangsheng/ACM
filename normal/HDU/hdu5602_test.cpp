#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 105;

bool vis[maxn][maxn];
double dp[maxn][maxn], f[maxn][maxn];

double dfs (int a, int b) {
    if (b > 21) return 0;
    if (a <= b) return 1;

    double ret = 0;
    for (int i = 1; i <= 13; i++) {
        int t = min(i, 10);
        ret += dfs(a, b + t) / 13;
    }
    return ret;
}

int cal(char ch) {
    if (ch == 'A') return 1;
    if (ch == 'T' || ch == 'J' || ch == 'Q' || ch == 'K') return 10;
    return ch - '0';
}

double solve (int a, int b) {
    if (a > 21) return 0;
    if (vis[a][b]) return f[a][b];

    vis[a][b] = true;
    double &ret = f[a][b];
    ret = 0;

    for (int i = 1; i <= 13; i++) {
        int t = min(i, 10);
        ret += solve(a + t, b) / 13;
    }
    return ret = max(ret, dp[a][b]);
}

int main (){
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            dp[i][j] = 1 - dfs(i, j);
        }
    }
    memset(vis, 0, sizeof(vis));

    int cas;
    char s[10];
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", s);

        int a = cal(s[0]) + cal(s[1]), b = cal(s[2]) + cal(s[3]);
        double pi = solve(a, b);
        printf("%.6f\n", pi);
        printf("%s\n", pi > 0.5 ? "YES" : "NO");
    }
    return 0;
}
