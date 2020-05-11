#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int N = 105, INF = ~0U >> 2;

int n;
int dp[N][N];
char g[N][N];

int main() {
    int i, j, k, mini, ans;
    while (~scanf("%d", &n)) {
        for (i = 1; i <= n; i++) {
            scanf("%s", g[i] + 1);
            for (j = 1; j <= n; j++) {
                if (g[i][j] == '.') dp[i][j] = dp[i - 1][j] + 1;
                else dp[i][j] = 0;
            }
        }
        ans = 0;
        for (i = 1; i <=n; i++) {
            for (j = 1; j <= n; j++) {
                if (dp[i][j] == 0) continue;
                mini = INF;
                for (k = j; k >= 1; k--) {
                    if (g[i][k] == '#') break;
                    mini = min(mini, dp[i][k]);
                    ans += mini;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
