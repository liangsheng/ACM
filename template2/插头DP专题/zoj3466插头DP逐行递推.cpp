#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 10;
const int M = 8;
const int MAXN = 16;
const int MAXM = 1 << 16;
const int popcount[8] = {0, 1, 1, 2, 1, 2, 2, 3};
const int offset[8] = {13, 12, 9, 8, 5, 4, 1, 0};

LL dp[MAXM], tmp[MAXM];

void gao(int off, bool flag) {
    fill(tmp, tmp + MAXM, 0);
    for (int i = 0; i < MAXM; ++i) {
        if (dp[i] == 0){
            continue;
        }
        int k = (i >> off) & 7;
        if (! flag){
            if (k == 0) {
                tmp[i] += dp[i];
            }
        } else {
            for (int j = 0; j < M; ++j) {
                if (popcount[j] + popcount[k] == 2) {
                    tmp[i ^ ((k ^ j) << off)] += dp[i];
                }
            }
        }
    }
    copy(tmp, tmp + MAXM, dp);
}

int main() {
    int n, m;
    bool g[N][N];
    char s[3];

    while (scanf("%d%d", &n, &m) != EOF) {
        fill(g[0], g[n], 1);
        for (int i = 0; i < m; ++i) {
            scanf("%s", s);
            g[s[0] - 'A'][s[1] - 'A'] = 0;
        }
        fill(tmp, tmp + MAXM, 0);
        fill(dp, dp + MAXM, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < M; j += 2) {
                gao(offset[j], g[i][j]);
            }
            fill(tmp, tmp + MAXM, 0);
            for (int j = 0; j < MAXM; j += 2) { //j += 2, 边界上最后一位一定是0
                tmp[j >> 1] = dp[j];
            }
            copy(tmp, tmp + MAXM, dp);
            for (int j = 0; j < M; j += 2) {
                gao(offset[j], g[i][j]);
            }
            fill(tmp, tmp + MAXM, 0);
            for (int j = 0; j < MAXM / 2; ++j) { //首位没用
                tmp[j << 1] = dp[j];
            }
            copy(tmp, tmp + MAXM, dp);
        }
        printf("%lld\n", dp[0]);
    }
    system("pause");
    return 0;
}
