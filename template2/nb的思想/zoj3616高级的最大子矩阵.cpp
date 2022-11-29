#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define sqr(x) ((x)*(x))

using namespace std;
int chh;

const int N = 105, M = 2005;

int n, m, b, g;
int v[N][M], s[N][M], gv[N][M], gs[N][M], L[N][M], R[N][M];

int sum(int h[N][M], int r0, int c0, int r1, int c1) {
    return h[r1][c1] - h[r1][c0 - 1] - h[r0 - 1][c1] + h[r0 - 1][c0 - 1];
}

int main() {
    int i, j;
    while (~scanf("%d %d %d %d", &n, &m, &b, &g)) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                scanf("%d %d", &v[i][j], &s[i][j]);
                if (s[i][j] == 2) s[i][j] = -1;
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                gv[i][j] = gv[i - 1][j] + gv[i][j - 1] - gv[i - 1][j - 1] + v[i][j];
                gs[i][j] = gs[i - 1][j] + gs[i][j - 1] - gs[i - 1][j - 1] + s[i][j];
            }
        }
        for (i = 1; i <= n; i++) {
            L[i][1] = 1, R[i][m] = m;
            for (j = 2; j <= m; j++) {
                if (v[i][j - 1] < 0) L[i][j] = j;
                else L[i][j] = L[i][j - 1];
            }
            for (j = m - 1; j >= 1; j--) {
                if (v[i][j + 1] < 0) R[i][j] = j;
                else R[i][j] = R[i][j + 1];
            }
        }
        int c, ans = -1;
        for (c = 1; c <= m; c++) {
            int r = 1;
            while (r <= n) {
                while (v[r][c] < 0 && r <= n) r++;
                int br = r;
                int ml = 1, mr = m;
                while (v[r][c] >= 0 && r <= n) {
                    ml = max(ml, L[r][c]);
                    mr = min(mr, R[r][c]);
                    int cnt_m = sum(gs, br, ml, r, mr), cnt_s = (r - br + 1) * (mr - ml + 1);
                    int bb = (cnt_m + cnt_s) / 2, gg = (cnt_s - cnt_m) / 2;
                    if (bb >= b && gg >= g) ans = max(ans, sum(gv, br, ml, r, mr));
                    r++;
                }
            }
        }
        if (ans == -1) puts("No solution!");
        else printf("%d\n", ans);
    }
    return 0;
}
