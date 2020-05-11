// 解法: 这题如果用普通背包解法, 时间复杂度O(N * C), 必然超时.
//       注意到Vi和Ci较小, 所以物品种类最多只有100种. 所以正确
//       解法为先将物品分类, 在调用多重背包算法.

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxc = 10005;

int dp[maxc], re[11][11], cost;

void Pack(int v, int c, int k) {
    for (int m = 1; k > 0; m += m) {
        if (m > k)
            m = k;
        k -= m;
        int vv = v * m, cc = c * m;
        for (int j = cost; j - cc >= 0; j--) {
            if (dp[j] < dp[j-cc] + vv)
                dp[j] = dp[j-cc] + vv;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int n, i, j;
    int v, c;
    while (scanf("%d %d", &n, &cost) != EOF) {
        memset(dp, 0, (cost + 1) * 4);
        memset(re, 0, sizeof(re));
        for (i = 0; i < n; i++) {
            scanf("%*c%*s %d %d", &v, &c);
            re[v][c]++;
        }
        for (i = 1; i <= 10; i++)
            for (j = 0; j <= 10; j++) {
                if (re[i][j] > 0) {
                    Pack(i, j, re[i][j]);
                }
            }
        printf("%d\n", dp[cost]);
    }
    return 0;
}
