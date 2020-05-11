#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define sqr(x) ((x)*(x))

using namespace std;
int chh;

const int N = 155;

int T, n, m, q, s;
int g[N][N], gs[N][N], L[N][N], R[N][N];

//int a[N << 2][N << 2];
//
//void inity(int kx, int sx, int ky, int sy, int ty) {
//    int mid = (sy + ty) >> 1;
//    if (sy == ty) {
//        a[kx][ky] = g[sx][sy];
//        return;
//    }
//    inity(kx, sx, ky << 1, sy, mid);
//    inity(kx, sx, ky << 1 | 1, mid + 1, ty);
//    a[kx][ky] = max(a[kx][ky << 1], a[kx][ky << 1 | 1]);
//}
//
//void update(int kx, int ky, int sy, int ty) {
//    int mid = (sy + ty) >> 1;
//    a[kx][ky] = max(a[kx << 1][ky], a[kx << 1 | 1][ky]);
//    if (sy == ty) return;
//    update(kx, ky << 1, sy, mid);
//    update(kx, ky << 1 | 1, mid + 1, ty);
//}
//
//void initx(int k, int s, int t) {
//    int mid = (s + t) >> 1;
//    if (s == t) {
//        inity(k, s, 1, 1, m);
//        return;
//    }
//    initx(k << 1, s, mid);
//    initx(k << 1 | 1, mid + 1, t);
//    update(k, 1, 1, m);
//}
//
//int findy(int kx, int ky, int sy, int ty, int y1, int y2) {
//    int mid = (sy + ty) >> 1, t1, t2;
//    if (sy > y2 || ty < y1) return -1;
//    if (sy >= y1 && ty <= y2) return a[kx][ky];
//    t1 = findy(kx, ky << 1, sy, mid, y1, y2);
//    t2 = findy(kx, ky << 1 | 1, mid + 1, ty, y1, y2);
//    return max(t1, t2);
//}
//
//int findx(int kx, int sx, int tx, int x1, int x2, int y1, int y2) {
//    int mid = (sx + tx) >> 1, t1, t2;
//    if (sx > x2 || tx < x1) return -1;
//    if (sx >= x1 && tx <= x2) return findy(kx, 1, 1, m, y1, y2);
//    t1 = findx(kx << 1, sx, mid, x1, x2, y1, y2);
//    t2 = findx(kx << 1 | 1, mid + 1, tx, x1, x2, y1, y2);
//    return max(t1, t2);
//}

int ln[N];
int a[151][8][151][8];

void get_log() {
    int i, j = 2, p = 0;
    for (i = 1; i <= 150; i++) {
        if (i == j) j *= 2, p++;
        ln[i] = p;
    }
}

void rmq_init_y(int p1, int p2) {
    int i, j, t, dep = ln[m];
    for (j = t = 1; j <= dep; j++, t <<= 1) {
        for (i = 1; i <= m - t; i++) a[p1][p2][i][j] = max(a[p1][p2][i][j - 1], a[p1][p2][i + t][j - 1]);
        for (i = m - t + 1; i <= m; i++) a[p1][p2][i][j] = a[p1][p2][i][j - 1];
    }
}

void rmq_init() {
    int i, j, k, t, dep = ln[n];
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) a[i][0][j][0] = g[i][j];
        rmq_init_y(i, 0);
    }
    for (j = t = 1; j <= dep; j++, t <<= 1) {
        for (i = 1; i <= n - t; i++) {
            for (k = 1; k <= m; k++) a[i][j][k][0] = max(a[i][j - 1][k][0], a[i + t][j - 1][k][0]);
            rmq_init_y(i, j);
        }
        for (i = n - t + 1; i <= n; i++) {
            for (k = 1; k <= m; k++) a[i][j][k][0] = a[i][j - 1][k][0];
            rmq_init_y(i, j);
        }
    }
}

int find(int r0, int r1, int c0, int c1) {
    if (r0 == r1) {
        if (c0 == c1) return a[r0][0][c0][0];
        int dep = ln[c1 - c0];
        return max(a[r0][0][c0][dep], a[r0][0][c1 - (1 << dep) + 1][dep]);
    } else {
        int dep1 = ln[r1 - r0];
        if (c0 == c1) return max(a[r0][dep1][c0][0], a[r1 - (1 << dep1) + 1][dep1][c0][0]);
        int dep2 = ln[c1 - c0], t1, t2;
        t1 = max(a[r0][dep1][c0][dep2], a[r0][dep1][c1 - (1 << dep2) + 1][dep2]);
        t2 = max(a[r1 - (1 << dep1) + 1][dep1][c0][dep2], a[r1 - (1 << dep1) + 1][dep1][c1 - (1 << dep2) + 1][dep2]);
        return max(t1, t2);
    }
}

int sum(int r0, int c0, int r1, int c1) {
    return gs[r1][c1] - gs[r1][c0 - 1] - gs[r0 - 1][c1] + gs[r0 - 1][c0 - 1];
}

int main() {
    int i, j, k, t, c0, c1, r0, r1, r, c, cas = 0;
    get_log();
    scanf("%d", &T);
    while (T--) {
        if (cas++) puts("");
        printf("Case %d:\n", cas);
        scanf("%d %d %d %d", &n, &m, &q, &s);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) scanf("%d", &g[i][j]);
        }
        gs[1][0] = gs[0][1] = gs[0][0] = 0;
        for (i = 1; i <= n; i++) {
            gs[i][1] = g[i][1] + gs[i - 1][1];
            L[i][1] = 1, R[i][m] = m;
        }
        for (i = 1; i <= m; i++) gs[1][i] = g[1][i] + gs[1][i - 1];
        for (i = 2; i <= n; i++) {
            for (j = 2; j <= m; j++)
                gs[i][j] = gs[i - 1][j] + gs[i][j - 1] - gs[i - 1][j - 1] + g[i][j];
        }
        for (i = 1; i <= n; i++) {
            for (j = 2; j <= m; j++) {
                if (g[i][j - 1] != -1) L[i][j] = L[i][j - 1];
                else L[i][j] = j;
            }
            for (j = m - 1; j >= 1; j--) {
                if (g[i][j + 1] != -1) R[i][j] = R[i][j + 1];
                else R[i][j] = j;
            }
        }
//        initx(1, 1, n);
        rmq_init();
        //cout << find(1, 3, 1, 4), pause;
        for (k = 1; k <= q; k++) {
            scanf("%d %d %d %d", &r0, &c0, &r1, &c1);
            int ans = 0;
            for (c = c0; c <= c1; c++) {
                r = r0;
                while (r <= r1) {
                    while (g[r][c] == -1 && r <= r1) r++;
                    int br = r;
                    int ml = c0, mr = c1;
                    while (g[r][c] != -1 && r <= r1) {
                        ml = max(ml, L[r][c]);
                        mr = min(mr, R[r][c]);
//                        int tmp = findx(1, 1, n, br, r, ml, mr);
                        int tmp = find(br, r, ml, mr);
                        tmp = tmp * s + sum(br, ml, r, mr) - tmp;
                        ans = max(ans, tmp);
                        r++;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
